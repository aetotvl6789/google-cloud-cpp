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
// source: google/cloud/retail/v2/completion_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RETAIL_COMPLETION_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RETAIL_COMPLETION_CLIENT_H

#include "google/cloud/retail/completion_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace retail {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Auto-completion service for retail.
///
/// This feature is only available for users who have Retail Search enabled.
/// Please enable Retail Search on Cloud Console before using this feature.
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class CompletionServiceClient {
 public:
  explicit CompletionServiceClient(
      std::shared_ptr<CompletionServiceConnection> connection,
      Options opts = {});
  ~CompletionServiceClient();

  //@{
  // @name Copy and move support
  CompletionServiceClient(CompletionServiceClient const&) = default;
  CompletionServiceClient& operator=(CompletionServiceClient const&) = default;
  CompletionServiceClient(CompletionServiceClient&&) = default;
  CompletionServiceClient& operator=(CompletionServiceClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(CompletionServiceClient const& a,
                         CompletionServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(CompletionServiceClient const& a,
                         CompletionServiceClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Completes the specified prefix with keyword suggestions.
  ///
  /// This feature is only available for users who have Retail Search enabled.
  /// Please enable Retail Search on Cloud Console before using this feature.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::retail::v2::CompleteQueryRequest,google/cloud/retail/v2/completion_service.proto#L78}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::retail::v2::CompleteQueryResponse,google/cloud/retail/v2/completion_service.proto#L150}
  ///
  /// [google.cloud.retail.v2.CompleteQueryRequest]:
  /// @googleapis_reference_link{google/cloud/retail/v2/completion_service.proto#L78}
  /// [google.cloud.retail.v2.CompleteQueryResponse]:
  /// @googleapis_reference_link{google/cloud/retail/v2/completion_service.proto#L150}
  ///
  StatusOr<google::cloud::retail::v2::CompleteQueryResponse> CompleteQuery(
      google::cloud::retail::v2::CompleteQueryRequest const& request,
      Options opts = {});

  ///
  /// Bulk import of processed completion dataset.
  ///
  /// Request processing is asynchronous. Partial updating is not supported.
  ///
  /// The operation is successfully finished only after the imported suggestions
  /// are indexed successfully and ready for serving. The process takes hours.
  ///
  /// This feature is only available for users who have Retail Search enabled.
  /// Please enable Retail Search on Cloud Console before using this feature.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::retail::v2::ImportCompletionDataRequest,google/cloud/retail/v2/import_config.proto#L254}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::retail::v2::ImportCompletionDataResponse,google/cloud/retail/v2/import_config.proto#L398}
  ///
  /// [google.cloud.retail.v2.ImportCompletionDataRequest]:
  /// @googleapis_reference_link{google/cloud/retail/v2/import_config.proto#L254}
  /// [google.cloud.retail.v2.ImportCompletionDataResponse]:
  /// @googleapis_reference_link{google/cloud/retail/v2/import_config.proto#L398}
  ///
  future<StatusOr<google::cloud::retail::v2::ImportCompletionDataResponse>>
  ImportCompletionData(
      google::cloud::retail::v2::ImportCompletionDataRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<CompletionServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace retail
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_RETAIL_COMPLETION_CLIENT_H
