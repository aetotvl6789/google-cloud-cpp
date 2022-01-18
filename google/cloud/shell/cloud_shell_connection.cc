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
// source: google/cloud/shell/v1/cloudshell.proto

#include "google/cloud/shell/cloud_shell_connection.h"
#include "google/cloud/shell/cloud_shell_options.h"
#include "google/cloud/shell/internal/cloud_shell_option_defaults.h"
#include "google/cloud/shell/internal/cloud_shell_stub_factory.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace shell {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudShellServiceConnection::~CloudShellServiceConnection() = default;

StatusOr<google::cloud::shell::v1::Environment>
CloudShellServiceConnection::GetEnvironment(
    google::cloud::shell::v1::GetEnvironmentRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::cloud::shell::v1::StartEnvironmentResponse>>
CloudShellServiceConnection::StartEnvironment(
    google::cloud::shell::v1::StartEnvironmentRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::shell::v1::StartEnvironmentResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::shell::v1::AuthorizeEnvironmentResponse>>
CloudShellServiceConnection::AuthorizeEnvironment(
    google::cloud::shell::v1::AuthorizeEnvironmentRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::shell::v1::AuthorizeEnvironmentResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::shell::v1::AddPublicKeyResponse>>
CloudShellServiceConnection::AddPublicKey(
    google::cloud::shell::v1::AddPublicKeyRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::shell::v1::AddPublicKeyResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::shell::v1::RemovePublicKeyResponse>>
CloudShellServiceConnection::RemovePublicKey(
    google::cloud::shell::v1::RemovePublicKeyRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::shell::v1::RemovePublicKeyResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

namespace {
class CloudShellServiceConnectionImpl : public CloudShellServiceConnection {
 public:
  CloudShellServiceConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<shell_internal::CloudShellServiceStub> stub,
      Options const& options)
      : background_(std::move(background)),
        stub_(std::move(stub)),
        retry_policy_prototype_(
            options.get<CloudShellServiceRetryPolicyOption>()->clone()),
        backoff_policy_prototype_(
            options.get<CloudShellServiceBackoffPolicyOption>()->clone()),
        polling_policy_prototype_(
            options.get<CloudShellServicePollingPolicyOption>()->clone()),
        idempotency_policy_(
            options.get<CloudShellServiceConnectionIdempotencyPolicyOption>()
                ->clone()) {}

  ~CloudShellServiceConnectionImpl() override = default;

  StatusOr<google::cloud::shell::v1::Environment> GetEnvironment(
      google::cloud::shell::v1::GetEnvironmentRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->GetEnvironment(request),
        [this](grpc::ClientContext& context,
               google::cloud::shell::v1::GetEnvironmentRequest const& request) {
          return stub_->GetEnvironment(context, request);
        },
        request, __func__);
  }

  future<StatusOr<google::cloud::shell::v1::StartEnvironmentResponse>>
  StartEnvironment(google::cloud::shell::v1::StartEnvironmentRequest const&
                       request) override {
    auto stub = stub_;
    return google::cloud::internal::AsyncLongRunningOperation<
        google::cloud::shell::v1::StartEnvironmentResponse>(
        background_->cq(), request,
        [stub](
            google::cloud::CompletionQueue& cq,
            std::unique_ptr<grpc::ClientContext> context,
            google::cloud::shell::v1::StartEnvironmentRequest const& request) {
          return stub->AsyncStartEnvironment(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::GetOperationRequest const& request) {
          return stub->AsyncGetOperation(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::CancelOperationRequest const& request) {
          return stub->AsyncCancelOperation(cq, std::move(context), request);
        },
        &google::cloud::internal::ExtractLongRunningResultResponse<
            google::cloud::shell::v1::StartEnvironmentResponse>,
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->StartEnvironment(request),
        polling_policy_prototype_->clone(), __func__);
  }

  future<StatusOr<google::cloud::shell::v1::AuthorizeEnvironmentResponse>>
  AuthorizeEnvironment(
      google::cloud::shell::v1::AuthorizeEnvironmentRequest const& request)
      override {
    auto stub = stub_;
    return google::cloud::internal::AsyncLongRunningOperation<
        google::cloud::shell::v1::AuthorizeEnvironmentResponse>(
        background_->cq(), request,
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::cloud::shell::v1::AuthorizeEnvironmentRequest const&
                   request) {
          return stub->AsyncAuthorizeEnvironment(cq, std::move(context),
                                                 request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::GetOperationRequest const& request) {
          return stub->AsyncGetOperation(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::CancelOperationRequest const& request) {
          return stub->AsyncCancelOperation(cq, std::move(context), request);
        },
        &google::cloud::internal::ExtractLongRunningResultResponse<
            google::cloud::shell::v1::AuthorizeEnvironmentResponse>,
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->AuthorizeEnvironment(request),
        polling_policy_prototype_->clone(), __func__);
  }

  future<StatusOr<google::cloud::shell::v1::AddPublicKeyResponse>> AddPublicKey(
      google::cloud::shell::v1::AddPublicKeyRequest const& request) override {
    auto stub = stub_;
    return google::cloud::internal::AsyncLongRunningOperation<
        google::cloud::shell::v1::AddPublicKeyResponse>(
        background_->cq(), request,
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::cloud::shell::v1::AddPublicKeyRequest const& request) {
          return stub->AsyncAddPublicKey(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::GetOperationRequest const& request) {
          return stub->AsyncGetOperation(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::CancelOperationRequest const& request) {
          return stub->AsyncCancelOperation(cq, std::move(context), request);
        },
        &google::cloud::internal::ExtractLongRunningResultResponse<
            google::cloud::shell::v1::AddPublicKeyResponse>,
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->AddPublicKey(request),
        polling_policy_prototype_->clone(), __func__);
  }

  future<StatusOr<google::cloud::shell::v1::RemovePublicKeyResponse>>
  RemovePublicKey(google::cloud::shell::v1::RemovePublicKeyRequest const&
                      request) override {
    auto stub = stub_;
    return google::cloud::internal::AsyncLongRunningOperation<
        google::cloud::shell::v1::RemovePublicKeyResponse>(
        background_->cq(), request,
        [stub](
            google::cloud::CompletionQueue& cq,
            std::unique_ptr<grpc::ClientContext> context,
            google::cloud::shell::v1::RemovePublicKeyRequest const& request) {
          return stub->AsyncRemovePublicKey(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::GetOperationRequest const& request) {
          return stub->AsyncGetOperation(cq, std::move(context), request);
        },
        [stub](google::cloud::CompletionQueue& cq,
               std::unique_ptr<grpc::ClientContext> context,
               google::longrunning::CancelOperationRequest const& request) {
          return stub->AsyncCancelOperation(cq, std::move(context), request);
        },
        &google::cloud::internal::ExtractLongRunningResultResponse<
            google::cloud::shell::v1::RemovePublicKeyResponse>,
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->RemovePublicKey(request),
        polling_policy_prototype_->clone(), __func__);
  }

 private:
  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<shell_internal::CloudShellServiceStub> stub_;
  std::unique_ptr<CloudShellServiceRetryPolicy const> retry_policy_prototype_;
  std::unique_ptr<BackoffPolicy const> backoff_policy_prototype_;
  std::unique_ptr<PollingPolicy const> polling_policy_prototype_;
  std::unique_ptr<CloudShellServiceConnectionIdempotencyPolicy>
      idempotency_policy_;
};
}  // namespace

std::shared_ptr<CloudShellServiceConnection> MakeCloudShellServiceConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 CloudShellServicePolicyOptionList>(options,
                                                                    __func__);
  options = shell_internal::CloudShellServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = shell_internal::CreateDefaultCloudShellServiceStub(
      background->cq(), options);
  return std::make_shared<CloudShellServiceConnectionImpl>(
      std::move(background), std::move(stub), options);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace shell
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace shell_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<shell::CloudShellServiceConnection>
MakeCloudShellServiceConnection(std::shared_ptr<CloudShellServiceStub> stub,
                                Options options) {
  options = CloudShellServiceDefaultOptions(std::move(options));
  return std::make_shared<shell::CloudShellServiceConnectionImpl>(
      internal::MakeBackgroundThreadsFactory(options)(), std::move(stub),
      std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace shell_internal
}  // namespace cloud
}  // namespace google