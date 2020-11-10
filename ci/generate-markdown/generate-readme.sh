#!/usr/bin/env bash
#
# Copyright 2019 Google LLC
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

readonly BINDIR=$(dirname "$0")

# The initial portion of the preamble needs variable expansion:
cat <<EOF
# Google Cloud Platform C++ Client Libraries

<!-- This file is automatically generated by ci/test-markdown/$(basename "$0") -->

EOF

cat <<"EOF"
[![Kokoro CI status][kokoro-clang-tidy-shield]][kokoro-clang-tidy-link]
[![Kokoro CI status][kokoro-windows-cmake-shield]][kokoro-windows-cmake-link]
[![Kokoro CI status][kokoro-macos-cmake-shield]][kokoro-macos-cmake-link]
[![Codecov Coverage status][codecov-shield]][codecov-link]<br>
[![Kokoro CI status][kokoro-integration-shield]][kokoro-integration-link]
[![Kokoro CI status][kokoro-windows-bazel-shield]][kokoro-windows-bazel-link]
[![Kokoro CI status][kokoro-macos-bazel-shield]][kokoro-macos-bazel-link]

[kokoro-clang-tidy-shield]: https://storage.googleapis.com/cloud-cpp-kokoro-status/kokoro-clang-tidy.svg
[kokoro-clang-tidy-link]: https://storage.googleapis.com/cloud-cpp-kokoro-status/kokoro-clang-tidy-link.html
[kokoro-integration-shield]: https://storage.googleapis.com/cloud-cpp-kokoro-status/kokoro-integration.svg
[kokoro-integration-link]: https://storage.googleapis.com/cloud-cpp-kokoro-status/kokoro-integration-link.html
[kokoro-windows-cmake-shield]: https://storage.googleapis.com/cloud-cpp-kokoro-status/kokoro-windows-cmake.svg
[kokoro-windows-cmake-link]: https://storage.googleapis.com/cloud-cpp-kokoro-status/kokoro-windows-cmake-link.html
[kokoro-windows-bazel-shield]: https://storage.googleapis.com/cloud-cpp-kokoro-status/kokoro-windows-bazel.svg
[kokoro-windows-bazel-link]: https://storage.googleapis.com/cloud-cpp-kokoro-status/kokoro-windows-bazel-link.html
[kokoro-macos-cmake-shield]: https://storage.googleapis.com/cloud-cpp-kokoro-status/macos/kokoro-cmake-super.svg
[kokoro-macos-cmake-link]: https://storage.googleapis.com/cloud-cpp-kokoro-status/macos/kokoro-cmake-super-link.html
[kokoro-macos-bazel-shield]: https://storage.googleapis.com/cloud-cpp-kokoro-status/macos/kokoro-bazel.svg
[kokoro-macos-bazel-link]: https://storage.googleapis.com/cloud-cpp-kokoro-status/macos/kokoro-bazel-link.html
[codecov-shield]: https://codecov.io/gh/googleapis/google-cloud-cpp/branch/master/graph/badge.svg
[codecov-link]: https://codecov.io/gh/googleapis/google-cloud-cpp

This repository contains idiomatic C++ client libraries for the following
[Google Cloud Platform](https://cloud.google.com/) services.

* [Google Cloud BigQuery](google/cloud/bigquery/README.md) (experimental)
* [Google Cloud Bigtable](google/cloud/bigtable/README.md) [[quickstart]](google/cloud/bigtable/quickstart/README.md)
* [Google Cloud Spanner](google/cloud/spanner/README.md) [[quickstart]](google/cloud/spanner/quickstart/README.md)
* [Google Cloud Pub/Sub](google/cloud/pubsub/README.md) [[quickstart]](google/cloud/pubsub/quickstart/README.md) (experimental)
* [Google Cloud Storage](google/cloud/storage/README.md) [[quickstart]](google/cloud/storage/quickstart/README.md)

See each library's `README.md` file for more information about:

* Where to find the documentation for the library and the service.
* How to get started using the library.
* How to incorporate the library into your build system.
* The library's support status if not Generally Available (GA); unless noted in
  a library's `README.md`, these libraries are all GA and supported by Google.

## Install

On most platforms, with all dependencies installed, the following commands will
compile and install all the libraries:

```sh
cmake -H. -Bcmake-out
cmake --build cmake-out
sudo cmake --build cmake-out --target install
```

You can find detailed instructions on how to install and/or compile all the
dependencies for several platforms in the [packaging guide](doc/packaging.md).

For application developers who prefer to build from source, the quickstart
guides for each library (see above) include instructions on how to incorporate
the library into their CMake-based or Bazel-based builds.

## Quickstart

Each library (linked above) contains a directory named `quickstart/` that's
intended to help you get up and running in a matter of minutes. This
`quickstart/` directory contains a minimal "Hello World" program demonstrating
how to use the library, along with minimal build files for common build
systems, such as CMake and Bazel.

* [Google Cloud Bigtable Quickstart](google/cloud/bigtable/quickstart/README.md)
* [Google Cloud Spanner Quickstart](google/cloud/spanner/quickstart/README.md)
* [Google Cloud Pub/Sub Quickstart](google/cloud/pubsub/quickstart/README.md)
* [Google Cloud Storage Quickstart](google/cloud/storage/quickstart/README.md)

As an example, the following code snippet, taken from [Google Cloud
Storage](google/cloud/storage/README.md), should give you a taste of what it's
like to use one of these C++ libraries.

```cc
EOF

# Dumps the contents of GCS's quickstart.cc starting at the first #include, so
# we skip the license header comment.
sed -n '/^#/,$p' "${BINDIR}/../../google/cloud/storage/quickstart/quickstart.cc"

cat <<"EOF"
```

## Support

* This project supports Windows, macOS, Linux
* This project supports C++11 (and higher) compilers (we test with GCC \>= 5.4, Clang >= 3.8, and MSVC \>= 2019)
* This project supports Bazel and CMake builds. See the [Quickstart examples](https://github.com/googleapis/google-cloud-cpp#quickstart)
* This project uses dependencies described in [doc/packaging.md](https://github.com/googleapis/google-cloud-cpp/blob/master/doc/packaging.md)
* This project works with or without exceptions enabled
* This project cuts [monthly releases](https://github.com/googleapis/google-cloud-cpp/releases) with detailed release notes

## Contact us

If you have questions or comments, or want to file bugs or request feature,
please do so using GitHub's normal Issues mechanism: [Contact Us](https://github.com/googleapis/google-cloud-cpp/issues/new/choose)

## Contributing changes

See [`CONTRIBUTING.md`](CONTRIBUTING.md) for details on how to contribute to
this project, including how to build and test your changes as well as how to
properly format your code.

## Licensing

Apache 2.0; see [`LICENSE`](LICENSE) for details.
EOF