# C++ Project Template
This repository is a minimal C++ project template. It is meant to be copied and
augmented. Though minimal, it includes a couple of useful features that can be
tricky to get working:

- All the code is built with CMake. Most of the dependencies are managed with
  CMake too!
- The code is separated into multiple directories which use code from one
  another.
- The project depends on a few third party libraries (e.g. zeromq).
- The project includes unit tests using [Google
  Test](https://github.com/google/googletest)
- The project include microbenchmarks using [Google
  Benchmark](https://github.com/google/benchmark)
- The project uses Protocol Buffers.
- TODO(mwhittaker): Add scripts to run clang-format and clang-tidy and mention
  that. Describe how to integrate the tools into vim, emacs, etc.
- TODO(someone): Add continuous integration?

## Getting Primal
This repository implements a prime factorization server and a corresponding
client. The client reads numbers from the command line and sends them to the
server, the server sends back their prime factorizations.

        +--------+    120    +--------+
        |        |---------->|        |
        | client |           | client |
        |        |<----------|        |
        +--------+  2,3,4,5  +--------+

Building and running the code, tests, and benchmarks is a breeze!

```bash
./scripts/build_debug.sh    # build the code in debug mode
./scripts/build_release.sh  # build the code in release mode
./build/factor/factor_test  # run a test
(cd build && make test)     # run all the tests
./build/factor/factor_bench # run a benchmark
./build/server/server       # start the server (in another window)
./build/client/client       # start the client
```

- TODO(mwhittaker): Explain how to install clang, CMake, and protobuf.
- TODO(mwhittaker): Given a more in-depth description of how the code works and
  is organized.
