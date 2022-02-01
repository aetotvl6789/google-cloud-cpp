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
// source: google/cloud/asset/v1/asset_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_ASSET_INTERNAL_ASSET_LOGGING_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_ASSET_INTERNAL_ASSET_LOGGING_DECORATOR_H

#include "google/cloud/asset/internal/asset_stub.h"
#include "google/cloud/tracing_options.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace asset_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class AssetServiceLogging : public AssetServiceStub {
 public:
  ~AssetServiceLogging() override = default;
  AssetServiceLogging(std::shared_ptr<AssetServiceStub> child,
                      TracingOptions tracing_options,
                      std::set<std::string> components);

  future<StatusOr<google::longrunning::Operation>> AsyncExportAssets(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::asset::v1::ExportAssetsRequest const& request) override;

  StatusOr<google::cloud::asset::v1::ListAssetsResponse> ListAssets(
      grpc::ClientContext& context,
      google::cloud::asset::v1::ListAssetsRequest const& request) override;

  StatusOr<google::cloud::asset::v1::BatchGetAssetsHistoryResponse>
  BatchGetAssetsHistory(
      grpc::ClientContext& context,
      google::cloud::asset::v1::BatchGetAssetsHistoryRequest const& request)
      override;

  StatusOr<google::cloud::asset::v1::Feed> CreateFeed(
      grpc::ClientContext& context,
      google::cloud::asset::v1::CreateFeedRequest const& request) override;

  StatusOr<google::cloud::asset::v1::Feed> GetFeed(
      grpc::ClientContext& context,
      google::cloud::asset::v1::GetFeedRequest const& request) override;

  StatusOr<google::cloud::asset::v1::ListFeedsResponse> ListFeeds(
      grpc::ClientContext& context,
      google::cloud::asset::v1::ListFeedsRequest const& request) override;

  StatusOr<google::cloud::asset::v1::Feed> UpdateFeed(
      grpc::ClientContext& context,
      google::cloud::asset::v1::UpdateFeedRequest const& request) override;

  Status DeleteFeed(
      grpc::ClientContext& context,
      google::cloud::asset::v1::DeleteFeedRequest const& request) override;

  StatusOr<google::cloud::asset::v1::SearchAllResourcesResponse>
  SearchAllResources(grpc::ClientContext& context,
                     google::cloud::asset::v1::SearchAllResourcesRequest const&
                         request) override;

  StatusOr<google::cloud::asset::v1::SearchAllIamPoliciesResponse>
  SearchAllIamPolicies(
      grpc::ClientContext& context,
      google::cloud::asset::v1::SearchAllIamPoliciesRequest const& request)
      override;

  StatusOr<google::cloud::asset::v1::AnalyzeIamPolicyResponse> AnalyzeIamPolicy(
      grpc::ClientContext& context,
      google::cloud::asset::v1::AnalyzeIamPolicyRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncAnalyzeIamPolicyLongrunning(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::asset::v1::AnalyzeIamPolicyLongrunningRequest const&
          request) override;

  StatusOr<google::cloud::asset::v1::AnalyzeMoveResponse> AnalyzeMove(
      grpc::ClientContext& context,
      google::cloud::asset::v1::AnalyzeMoveRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::shared_ptr<AssetServiceStub> child_;
  TracingOptions tracing_options_;
  std::set<std::string> components_;
};  // AssetServiceLogging

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace asset_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_ASSET_INTERNAL_ASSET_LOGGING_DECORATOR_H