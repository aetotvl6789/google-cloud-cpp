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
// source: google/appengine/v1/appengine.proto

#include "google/cloud/appengine/domain_mappings_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace appengine {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::internal::Idempotency;

DomainMappingsConnectionIdempotencyPolicy::
    ~DomainMappingsConnectionIdempotencyPolicy() = default;

namespace {
class DefaultDomainMappingsConnectionIdempotencyPolicy
    : public DomainMappingsConnectionIdempotencyPolicy {
 public:
  ~DefaultDomainMappingsConnectionIdempotencyPolicy() override = default;

  /// Create a new copy of this object.
  std::unique_ptr<DomainMappingsConnectionIdempotencyPolicy> clone()
      const override {
    return absl::make_unique<DefaultDomainMappingsConnectionIdempotencyPolicy>(
        *this);
  }

  Idempotency ListDomainMappings(
      google::appengine::v1::ListDomainMappingsRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetDomainMapping(
      google::appengine::v1::GetDomainMappingRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency CreateDomainMapping(
      google::appengine::v1::CreateDomainMappingRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency UpdateDomainMapping(
      google::appengine::v1::UpdateDomainMappingRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteDomainMapping(
      google::appengine::v1::DeleteDomainMappingRequest const&) override {
    return Idempotency::kNonIdempotent;
  }
};
}  // namespace

std::unique_ptr<DomainMappingsConnectionIdempotencyPolicy>
MakeDefaultDomainMappingsConnectionIdempotencyPolicy() {
  return absl::make_unique<DefaultDomainMappingsConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace appengine
}  // namespace cloud
}  // namespace google