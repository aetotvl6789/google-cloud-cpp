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
// source: google/cloud/dataplex/v1/metadata.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPLEX_METADATA_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPLEX_METADATA_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/version.h"
#include <google/cloud/dataplex/v1/metadata.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dataplex {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class MetadataServiceConnectionIdempotencyPolicy {
 public:
  virtual ~MetadataServiceConnectionIdempotencyPolicy() = 0;

  /// Create a new copy of this object.
  virtual std::unique_ptr<MetadataServiceConnectionIdempotencyPolicy> clone()
      const = 0;

  virtual google::cloud::Idempotency CreateEntity(
      google::cloud::dataplex::v1::CreateEntityRequest const& request) = 0;

  virtual google::cloud::Idempotency UpdateEntity(
      google::cloud::dataplex::v1::UpdateEntityRequest const& request) = 0;

  virtual google::cloud::Idempotency DeleteEntity(
      google::cloud::dataplex::v1::DeleteEntityRequest const& request) = 0;

  virtual google::cloud::Idempotency GetEntity(
      google::cloud::dataplex::v1::GetEntityRequest const& request) = 0;

  virtual google::cloud::Idempotency ListEntities(
      google::cloud::dataplex::v1::ListEntitiesRequest request) = 0;

  virtual google::cloud::Idempotency CreatePartition(
      google::cloud::dataplex::v1::CreatePartitionRequest const& request) = 0;

  virtual google::cloud::Idempotency DeletePartition(
      google::cloud::dataplex::v1::DeletePartitionRequest const& request) = 0;

  virtual google::cloud::Idempotency GetPartition(
      google::cloud::dataplex::v1::GetPartitionRequest const& request) = 0;

  virtual google::cloud::Idempotency ListPartitions(
      google::cloud::dataplex::v1::ListPartitionsRequest request) = 0;
};

std::unique_ptr<MetadataServiceConnectionIdempotencyPolicy>
MakeDefaultMetadataServiceConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataplex
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPLEX_METADATA_CONNECTION_IDEMPOTENCY_POLICY_H