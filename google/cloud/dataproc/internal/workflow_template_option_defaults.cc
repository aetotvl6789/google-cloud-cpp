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
// source: google/cloud/dataproc/v1/workflow_templates.proto

#include "google/cloud/dataproc/internal/workflow_template_option_defaults.h"
#include "google/cloud/dataproc/workflow_template_connection.h"
#include "google/cloud/dataproc/workflow_template_options.h"
#include "google/cloud/common_options.h"
#include "google/cloud/connection_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/getenv.h"
#include "google/cloud/internal/user_agent_prefix.h"
#include "google/cloud/options.h"
#include <memory>

namespace google {
namespace cloud {
namespace dataproc_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options WorkflowTemplateServiceDefaultOptions(Options options) {
  if (!options.has<EndpointOption>()) {
    auto env =
        internal::GetEnv("GOOGLE_CLOUD_CPP_WORKFLOW_TEMPLATE_SERVICE_ENDPOINT");
    options.set<EndpointOption>(
        env && !env->empty() ? *env : "dataproc.googleapis.com");
  }
  if (!options.has<GrpcCredentialOption>()) {
    options.set<GrpcCredentialOption>(grpc::GoogleDefaultCredentials());
  }
  if (!options.has<TracingComponentsOption>()) {
    options.set<TracingComponentsOption>(internal::DefaultTracingComponents());
  }
  if (!options.has<GrpcTracingOptionsOption>()) {
    options.set<GrpcTracingOptionsOption>(internal::DefaultTracingOptions());
  }
  auto& products = options.lookup<UserAgentProductsOption>();
  products.insert(products.begin(), google::cloud::internal::UserAgentPrefix());

  if (!options.has<dataproc::WorkflowTemplateServiceRetryPolicyOption>()) {
    options.set<dataproc::WorkflowTemplateServiceRetryPolicyOption>(
        dataproc::WorkflowTemplateServiceLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<dataproc::WorkflowTemplateServiceBackoffPolicyOption>()) {
    options.set<dataproc::WorkflowTemplateServiceBackoffPolicyOption>(
        ExponentialBackoffPolicy(std::chrono::seconds(1),
                                 std::chrono::minutes(5), kBackoffScaling)
            .clone());
  }
  if (!options.has<dataproc::WorkflowTemplateServicePollingPolicyOption>()) {
    options.set<dataproc::WorkflowTemplateServicePollingPolicyOption>(
        GenericPollingPolicy<
            dataproc::WorkflowTemplateServiceRetryPolicyOption::Type,
            dataproc::WorkflowTemplateServiceBackoffPolicyOption::Type>(
            options.get<dataproc::WorkflowTemplateServiceRetryPolicyOption>()
                ->clone(),
            options.get<dataproc::WorkflowTemplateServiceBackoffPolicyOption>()
                ->clone())
            .clone());
  }
  if (!options.has<
          dataproc::
              WorkflowTemplateServiceConnectionIdempotencyPolicyOption>()) {
    options.set<
        dataproc::WorkflowTemplateServiceConnectionIdempotencyPolicyOption>(
        dataproc::
            MakeDefaultWorkflowTemplateServiceConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataproc_internal
}  // namespace cloud
}  // namespace google