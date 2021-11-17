// Copyright 2021 Google LLC
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
// source: google/bigtable/admin/v2/bigtable_instance_admin.proto

#include "google/cloud/bigtable/admin/internal/bigtable_instance_admin_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/bigtable/admin/v2/bigtable_instance_admin.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace bigtable_admin_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

BigtableInstanceAdminStub::~BigtableInstanceAdminStub() = default;

future<StatusOr<google::longrunning::Operation>>
DefaultBigtableInstanceAdminStub::AsyncCreateInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::admin::v2::CreateInstanceRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::bigtable::admin::v2::CreateInstanceRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCreateInstance(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::bigtable::admin::v2::Instance>
DefaultBigtableInstanceAdminStub::GetInstance(
    grpc::ClientContext& client_context,
    google::bigtable::admin::v2::GetInstanceRequest const& request) {
  google::bigtable::admin::v2::Instance response;
  auto status = grpc_stub_->GetInstance(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::bigtable::admin::v2::ListInstancesResponse>
DefaultBigtableInstanceAdminStub::ListInstances(
    grpc::ClientContext& client_context,
    google::bigtable::admin::v2::ListInstancesRequest const& request) {
  google::bigtable::admin::v2::ListInstancesResponse response;
  auto status = grpc_stub_->ListInstances(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::bigtable::admin::v2::Instance>
DefaultBigtableInstanceAdminStub::UpdateInstance(
    grpc::ClientContext& client_context,
    google::bigtable::admin::v2::Instance const& request) {
  google::bigtable::admin::v2::Instance response;
  auto status = grpc_stub_->UpdateInstance(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultBigtableInstanceAdminStub::AsyncPartialUpdateInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::admin::v2::PartialUpdateInstanceRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::bigtable::admin::v2::PartialUpdateInstanceRequest const&
                 request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncPartialUpdateInstance(context, request, cq);
      },
      request, std::move(context));
}

Status DefaultBigtableInstanceAdminStub::DeleteInstance(
    grpc::ClientContext& client_context,
    google::bigtable::admin::v2::DeleteInstanceRequest const& request) {
  google::protobuf::Empty response;
  auto status = grpc_stub_->DeleteInstance(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

future<StatusOr<google::longrunning::Operation>>
DefaultBigtableInstanceAdminStub::AsyncCreateCluster(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::admin::v2::CreateClusterRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::bigtable::admin::v2::CreateClusterRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCreateCluster(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::bigtable::admin::v2::Cluster>
DefaultBigtableInstanceAdminStub::GetCluster(
    grpc::ClientContext& client_context,
    google::bigtable::admin::v2::GetClusterRequest const& request) {
  google::bigtable::admin::v2::Cluster response;
  auto status = grpc_stub_->GetCluster(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::bigtable::admin::v2::ListClustersResponse>
DefaultBigtableInstanceAdminStub::ListClusters(
    grpc::ClientContext& client_context,
    google::bigtable::admin::v2::ListClustersRequest const& request) {
  google::bigtable::admin::v2::ListClustersResponse response;
  auto status = grpc_stub_->ListClusters(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultBigtableInstanceAdminStub::AsyncUpdateCluster(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::admin::v2::Cluster const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::bigtable::admin::v2::Cluster const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncUpdateCluster(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultBigtableInstanceAdminStub::AsyncPartialUpdateCluster(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::admin::v2::PartialUpdateClusterRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::bigtable::admin::v2::PartialUpdateClusterRequest const&
                 request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncPartialUpdateCluster(context, request, cq);
      },
      request, std::move(context));
}

Status DefaultBigtableInstanceAdminStub::DeleteCluster(
    grpc::ClientContext& client_context,
    google::bigtable::admin::v2::DeleteClusterRequest const& request) {
  google::protobuf::Empty response;
  auto status = grpc_stub_->DeleteCluster(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

StatusOr<google::bigtable::admin::v2::AppProfile>
DefaultBigtableInstanceAdminStub::CreateAppProfile(
    grpc::ClientContext& client_context,
    google::bigtable::admin::v2::CreateAppProfileRequest const& request) {
  google::bigtable::admin::v2::AppProfile response;
  auto status =
      grpc_stub_->CreateAppProfile(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::bigtable::admin::v2::AppProfile>
DefaultBigtableInstanceAdminStub::GetAppProfile(
    grpc::ClientContext& client_context,
    google::bigtable::admin::v2::GetAppProfileRequest const& request) {
  google::bigtable::admin::v2::AppProfile response;
  auto status = grpc_stub_->GetAppProfile(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::bigtable::admin::v2::ListAppProfilesResponse>
DefaultBigtableInstanceAdminStub::ListAppProfiles(
    grpc::ClientContext& client_context,
    google::bigtable::admin::v2::ListAppProfilesRequest const& request) {
  google::bigtable::admin::v2::ListAppProfilesResponse response;
  auto status =
      grpc_stub_->ListAppProfiles(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultBigtableInstanceAdminStub::AsyncUpdateAppProfile(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::admin::v2::UpdateAppProfileRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](
          grpc::ClientContext* context,
          google::bigtable::admin::v2::UpdateAppProfileRequest const& request,
          grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncUpdateAppProfile(context, request, cq);
      },
      request, std::move(context));
}

Status DefaultBigtableInstanceAdminStub::DeleteAppProfile(
    grpc::ClientContext& client_context,
    google::bigtable::admin::v2::DeleteAppProfileRequest const& request) {
  google::protobuf::Empty response;
  auto status =
      grpc_stub_->DeleteAppProfile(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

StatusOr<google::iam::v1::Policy>
DefaultBigtableInstanceAdminStub::GetIamPolicy(
    grpc::ClientContext& client_context,
    google::iam::v1::GetIamPolicyRequest const& request) {
  google::iam::v1::Policy response;
  auto status = grpc_stub_->GetIamPolicy(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::iam::v1::Policy>
DefaultBigtableInstanceAdminStub::SetIamPolicy(
    grpc::ClientContext& client_context,
    google::iam::v1::SetIamPolicyRequest const& request) {
  google::iam::v1::Policy response;
  auto status = grpc_stub_->SetIamPolicy(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
DefaultBigtableInstanceAdminStub::TestIamPermissions(
    grpc::ClientContext& client_context,
    google::iam::v1::TestIamPermissionsRequest const& request) {
  google::iam::v1::TestIamPermissionsResponse response;
  auto status =
      grpc_stub_->TestIamPermissions(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultBigtableInstanceAdminStub::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::longrunning::GetOperationRequest const& request,
             grpc::CompletionQueue* cq) {
        return operations_->AsyncGetOperation(context, request, cq);
      },
      request, std::move(context));
}

future<Status> DefaultBigtableInstanceAdminStub::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return cq
      .MakeUnaryRpc(
          [this](grpc::ClientContext* context,
                 google::longrunning::CancelOperationRequest const& request,
                 grpc::CompletionQueue* cq) {
            return operations_->AsyncCancelOperation(context, request, cq);
          },
          request, std::move(context))
      .then([](future<StatusOr<google::protobuf::Empty>> f) {
        return f.get().status();
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigtable_admin_internal
}  // namespace cloud
}  // namespace google