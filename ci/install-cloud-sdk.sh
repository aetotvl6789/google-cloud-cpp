#!/usr/bin/env bash
#
# Copyright 2019 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set -euo pipefail

readonly GOOGLE_CLOUD_CPP_CLOUD_SDK_VERSION="390.0.0"
readonly GOOGLE_CLOUD_CPP_SDK_SHA256="5ce31b85013599dd842ca8a08539aaa6047aee63bb216d5b3988fb2666b06c07"

readonly SITE="https://dl.google.com/dl/cloudsdk/channels/rapid/downloads"
readonly TARBALL="google-cloud-cli-${GOOGLE_CLOUD_CPP_CLOUD_SDK_VERSION}-linux-x86_64.tar.gz"
curl -L "${SITE}/${TARBALL}" -o "${TARBALL}"

echo "${GOOGLE_CLOUD_CPP_SDK_SHA256} ${TARBALL}" | sha256sum --check -
tar x -C /usr/local -f "${TARBALL}"
/usr/local/google-cloud-sdk/bin/gcloud --quiet components install \
  beta bigtable cbt cloud-spanner-emulator pubsub-emulator
