#! /bin/bash

set -euo pipefail

main() {
    export CC="clang"
    export CXX="clang++"
    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -Hsrc -Bbuild
    cmake --build build
}

main
