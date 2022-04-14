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
// source: google/cloud/dialogflow/cx/v3/deployment.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_INTERNAL_DEPLOYMENTS_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_INTERNAL_DEPLOYMENTS_STUB_H

#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/dialogflow/cx/v3/deployment.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class DeploymentsStub {
 public:
  virtual ~DeploymentsStub() = 0;

  virtual StatusOr<google::cloud::dialogflow::cx::v3::ListDeploymentsResponse>
  ListDeployments(
      grpc::ClientContext& context,
      google::cloud::dialogflow::cx::v3::ListDeploymentsRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::dialogflow::cx::v3::Deployment> GetDeployment(
      grpc::ClientContext& context,
      google::cloud::dialogflow::cx::v3::GetDeploymentRequest const&
          request) = 0;
};

class DefaultDeploymentsStub : public DeploymentsStub {
 public:
  explicit DefaultDeploymentsStub(
      std::unique_ptr<
          google::cloud::dialogflow::cx::v3::Deployments::StubInterface>
          grpc_stub)
      : grpc_stub_(std::move(grpc_stub)) {}

  StatusOr<google::cloud::dialogflow::cx::v3::ListDeploymentsResponse>
  ListDeployments(
      grpc::ClientContext& client_context,
      google::cloud::dialogflow::cx::v3::ListDeploymentsRequest const& request)
      override;

  StatusOr<google::cloud::dialogflow::cx::v3::Deployment> GetDeployment(
      grpc::ClientContext& client_context,
      google::cloud::dialogflow::cx::v3::GetDeploymentRequest const& request)
      override;

 private:
  std::unique_ptr<google::cloud::dialogflow::cx::v3::Deployments::StubInterface>
      grpc_stub_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_INTERNAL_DEPLOYMENTS_STUB_H