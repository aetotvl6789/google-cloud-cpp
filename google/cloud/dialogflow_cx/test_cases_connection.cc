// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/dialogflow/cx/v3/test_case.proto

#include "google/cloud/dialogflow_cx/test_cases_connection.h"
#include "google/cloud/dialogflow_cx/internal/test_cases_connection_impl.h"
#include "google/cloud/dialogflow_cx/internal/test_cases_option_defaults.h"
#include "google/cloud/dialogflow_cx/internal/test_cases_stub_factory.h"
#include "google/cloud/dialogflow_cx/test_cases_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

TestCasesConnection::~TestCasesConnection() = default;

StreamRange<google::cloud::dialogflow::cx::v3::TestCase>
TestCasesConnection::ListTestCases(
    google::cloud::dialogflow::cx::v3::
        ListTestCasesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::dialogflow::cx::v3::TestCase>>();
}

Status TestCasesConnection::BatchDeleteTestCases(
    google::cloud::dialogflow::cx::v3::BatchDeleteTestCasesRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::dialogflow::cx::v3::TestCase>
TestCasesConnection::GetTestCase(
    google::cloud::dialogflow::cx::v3::GetTestCaseRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::dialogflow::cx::v3::TestCase>
TestCasesConnection::CreateTestCase(
    google::cloud::dialogflow::cx::v3::CreateTestCaseRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::dialogflow::cx::v3::TestCase>
TestCasesConnection::UpdateTestCase(
    google::cloud::dialogflow::cx::v3::UpdateTestCaseRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::cloud::dialogflow::cx::v3::RunTestCaseResponse>>
TestCasesConnection::RunTestCase(
    google::cloud::dialogflow::cx::v3::RunTestCaseRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::dialogflow::cx::v3::RunTestCaseResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::dialogflow::cx::v3::BatchRunTestCasesResponse>>
TestCasesConnection::BatchRunTestCases(
    google::cloud::dialogflow::cx::v3::BatchRunTestCasesRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::dialogflow::cx::v3::BatchRunTestCasesResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::cloud::dialogflow::cx::v3::CalculateCoverageResponse>
TestCasesConnection::CalculateCoverage(
    google::cloud::dialogflow::cx::v3::CalculateCoverageRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::cloud::dialogflow::cx::v3::ImportTestCasesResponse>>
TestCasesConnection::ImportTestCases(
    google::cloud::dialogflow::cx::v3::ImportTestCasesRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::dialogflow::cx::v3::ImportTestCasesResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::dialogflow::cx::v3::ExportTestCasesResponse>>
TestCasesConnection::ExportTestCases(
    google::cloud::dialogflow::cx::v3::ExportTestCasesRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::dialogflow::cx::v3::ExportTestCasesResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StreamRange<google::cloud::dialogflow::cx::v3::TestCaseResult>
TestCasesConnection::ListTestCaseResults(
    google::cloud::dialogflow::cx::v3::
        ListTestCaseResultsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::dialogflow::cx::v3::TestCaseResult>>();
}

StatusOr<google::cloud::dialogflow::cx::v3::TestCaseResult>
TestCasesConnection::GetTestCaseResult(
    google::cloud::dialogflow::cx::v3::GetTestCaseResultRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<TestCasesConnection> MakeTestCasesConnection(Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 TestCasesPolicyOptionList>(options, __func__);
  options = dialogflow_cx_internal::TestCasesDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = dialogflow_cx_internal::CreateDefaultTestCasesStub(
      background->cq(), options);
  return std::make_shared<dialogflow_cx_internal::TestCasesConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<dialogflow_cx::TestCasesConnection> MakeTestCasesConnection(
    std::shared_ptr<TestCasesStub> stub, Options options) {
  options = TestCasesDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<dialogflow_cx_internal::TestCasesConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google
