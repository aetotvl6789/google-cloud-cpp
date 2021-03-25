#!/bin/bash
#
# Copyright 2021 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set -eu

source "$(dirname "$0")/../../lib/init.sh"
source module ci/cloudbuild/builds/lib/bazel.sh
source module ci/etc/integration-tests-config.sh
source module ci/lib/io.sh

export CC=clang
export CXX=clang++
export CLOUD_SDK_LOCATION=/usr/local/google-cloud-sdk
readonly EMULATOR_SCRIPT="run_integration_tests_emulator_bazel.sh"

mapfile -t args < <(bazel::common_args)
bazel test "${args[@]}" --test_tag_filters=-integration-test ...

# Common configuration for all integration tests that follow.
args+=(
  "--test_timeout=600"
  "--test_env=GOOGLE_CLOUD_PROJECT=${GOOGLE_CLOUD_PROJECT}"
  "--test_env=GOOGLE_CLOUD_CPP_AUTO_RUN_EXAMPLES=yes"
  "--test_env=GOOGLE_CLOUD_CPP_EXPERIMENTAL_LOG_CONFIG=lastN,100,WARNING"
  "--test_env=GOOGLE_CLOUD_CPP_ENABLE_TRACING=rpc"
  "--test_env=CLOUD_STORAGE_ENABLE_TRACING=rpc"
)

# TODO(#6083): Enable storage integration tests. The difficulty with these is
# providing the GOOGLE_CLOUD_CPP_TEST_KEY_FILE_{JSON,P12} files, which we may
# need to provide via Secret Manager.

io::log_h2 "Runnning Generator integration tests (with emulator)"
env \
  GOOGLE_CLOUD_CPP_GENERATOR_RUN_INTEGRATION_TESTS=yes \
  GOOGLE_CLOUD_CPP_GENERATOR_CODE_PATH=/workspace \
  "./generator/ci/${EMULATOR_SCRIPT}" \
  bazel test "${args[@]}"

io::log_h2 "Runnning Pub/Sub integration tests (with emulator)"
"./google/cloud/pubsub/ci/${EMULATOR_SCRIPT}" \
  bazel test "${args[@]}"

# TODO(#441) - remove the `retry-command.sh` below.
# Sometimes the integration tests manage to crash the Bigtable emulator. Use a
# (short) timeout to run the test and try 3 times.
io::log_h2 "Runnning Bigtable integration tests (with emulator)"
bigtable_args=(
  "--test_timeout=100"
  "--test_env=GOOGLE_CLOUD_CPP_BIGTABLE_TEST_INSTANCE_ID=${GOOGLE_CLOUD_CPP_BIGTABLE_TEST_INSTANCE_ID}"
  "--test_env=GOOGLE_CLOUD_CPP_BIGTABLE_TEST_CLUSTER_ID=${GOOGLE_CLOUD_CPP_BIGTABLE_TEST_CLUSTER_ID}"
  "--test_env=GOOGLE_CLOUD_CPP_BIGTABLE_TEST_ZONE_A=${GOOGLE_CLOUD_CPP_BIGTABLE_TEST_ZONE_A}"
  "--test_env=GOOGLE_CLOUD_CPP_BIGTABLE_TEST_ZONE_B=${GOOGLE_CLOUD_CPP_BIGTABLE_TEST_ZONE_B}"
  "--test_env=GOOGLE_CLOUD_CPP_BIGTABLE_TEST_SERVICE_ACCOUNT=${GOOGLE_CLOUD_CPP_BIGTABLE_TEST_SERVICE_ACCOUNT}"
  "--test_env=ENABLE_BIGTABLE_ADMIN_INTEGRATION_TESTS=${ENABLE_BIGTABLE_ADMIN_INTEGRATION_TESTS:-no}"
)
env \
  CBT=/usr/local/google-cloud-sdk/bin/cbt \
  CBT_EMULATOR=/usr/local/google-cloud-sdk/platform/bigtable-emulator/cbtemulator \
  GOPATH="${GOPATH:-}" \
  ./ci/retry-command.sh 3 0 \
  "./google/cloud/bigtable/ci/${EMULATOR_SCRIPT}" \
  bazel test "${args[@]}" "${bigtable_args[@]}"

# TODO(#6083): Run //google/cloud/bigtable/examples:bigtable_grpc_credentials
# separately w/ an access token.

io::log_h2 "Runnning Spanner integration tests"
# TODO(#6083): Add support for:
# - GOOGLE_CLOUD_CPP_SPANNER_SLOW_INTEGRATION_TESTS
# - GOOGLE_CLOUD_CPP_SPANNER_DEFAULT_ENDPOINT
spanner_args=(
  "--test_tag_filters=integration-test"
  "--test_env=GOOGLE_CLOUD_CPP_SPANNER_TEST_INSTANCE_ID=${GOOGLE_CLOUD_CPP_SPANNER_TEST_INSTANCE_ID}"
  "--test_env=GOOGLE_CLOUD_CPP_SPANNER_TEST_SERVICE_ACCOUNT=${GOOGLE_CLOUD_CPP_SPANNER_TEST_SERVICE_ACCOUNT}"
)
bazel test "${args[@]}" "${spanner_args[@]}" google/cloud/spanner/...