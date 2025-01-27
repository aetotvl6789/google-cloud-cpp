// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/storage/benchmarks/benchmark_utils.h"
#include "google/cloud/storage/benchmarks/bounded_queue.h"
#include "google/cloud/internal/throw_delegate.h"
#include "absl/types/optional.h"
#include <cctype>
#include <future>
#include <limits>
#include <sstream>
#include <stdexcept>

namespace google {
namespace cloud {
namespace storage_benchmarks {

void DeleteAllObjects(google::cloud::storage::Client client,
                      std::string const& bucket_name, int thread_count) {
  return DeleteAllObjects(std::move(client), bucket_name,
                          google::cloud::storage::Prefix(), thread_count);
}

void DeleteAllObjects(google::cloud::storage::Client client,
                      std::string const& bucket_name,
                      google::cloud::storage::Prefix prefix, int thread_count) {
  using WorkQueue = BoundedQueue<google::cloud::storage::ObjectMetadata>;
  using std::chrono::duration_cast;
  using std::chrono::milliseconds;
  namespace gcs = ::google::cloud::storage;

  std::cout << "# Deleting test objects [" << thread_count << "]\n";
  auto start = std::chrono::steady_clock::now();
  WorkQueue work_queue;
  std::vector<std::future<google::cloud::Status>> workers;
  std::generate_n(
      std::back_inserter(workers), thread_count, [&client, &work_queue] {
        auto worker_task = [](gcs::Client client, WorkQueue& wq) {
          google::cloud::Status status{};
          for (auto object = wq.Pop(); object.has_value(); object = wq.Pop()) {
            auto s = client.DeleteObject(object->bucket(), object->name(),
                                         gcs::Generation(object->generation()));
            if (!s.ok()) status = s;
          }
          return status;
        };
        return std::async(std::launch::async, worker_task, client,
                          std::ref(work_queue));
      });

  for (auto& o : client.ListObjects(bucket_name, gcs::Versions(true),
                                    std::move(prefix))) {
    if (!o) break;
    work_queue.Push(*std::move(o));
  }
  work_queue.Shutdown();
  int count = 0;
  for (auto& t : workers) {
    auto status = t.get();
    if (!status.ok()) {
      std::cerr << "Error return task[" << count << "]: " << status << "\n";
    }
    ++count;
  }
  auto elapsed = std::chrono::steady_clock::now() - start;
  std::cout << "# Deleted in " << duration_cast<milliseconds>(elapsed).count()
            << "ms\n";
}

char const* ToString(ApiName api) {
  switch (api) {
    case ApiName::kApiJson:
      return "JSON";
    case ApiName::kApiXml:
      return "XML";
    case ApiName::kApiGrpc:
      return "GRPC";
  }
  return "";
}

StatusOr<ApiName> ParseApiName(std::string const& val) {
  for (auto a : {ApiName::kApiJson, ApiName::kApiXml, ApiName::kApiGrpc}) {
    if (val == ToString(a)) return a;
  }
  return Status{StatusCode::kInvalidArgument, "unknown ApiName " + val};
}

StatusOr<ExperimentLibrary> ParseExperimentLibrary(std::string const& val) {
  for (auto v : {ExperimentLibrary::kRaw, ExperimentLibrary::kCppClient}) {
    if (val == ToString(v)) return v;
  }
  return Status{StatusCode::kInvalidArgument,
                "unknown ExperimentLibrary " + val};
}

StatusOr<ExperimentTransport> ParseExperimentTransport(std::string const& val) {
  for (auto v : {ExperimentTransport::kDirectPath, ExperimentTransport::kGrpc,
                 ExperimentTransport::kJson, ExperimentTransport::kXml,
                 ExperimentTransport::kJsonV2, ExperimentTransport::kXmlV2}) {
    if (val == ToString(v)) return v;
  }
  return Status{StatusCode::kInvalidArgument,
                "unknown ExperimentTransport " + val};
}

std::string ToString(ExperimentLibrary v) {
  switch (v) {
    case ExperimentLibrary::kCppClient:
      return "CppClient";
    case ExperimentLibrary::kRaw:
      return "Raw";
  }
  return "";
}

std::string ToString(ExperimentTransport v) {
  switch (v) {
    case ExperimentTransport::kDirectPath:
      return "DirectPath";
    case ExperimentTransport::kGrpc:
      return "Grpc";
    case ExperimentTransport::kJson:
      return "Json";
    case ExperimentTransport::kXml:
      return "Xml";
    case ExperimentTransport::kJsonV2:
      return "JsonV2";
    case ExperimentTransport::kXmlV2:
      return "XmlV2";
  }
  return "";
}

std::string RandomBucketPrefix() { return "cloud-cpp-testing-bm"; }

std::string MakeRandomBucketName(google::cloud::internal::DefaultPRNG& gen) {
  return storage::testing::MakeRandomBucketName(gen, RandomBucketPrefix());
}

}  // namespace storage_benchmarks
}  // namespace cloud
}  // namespace google
