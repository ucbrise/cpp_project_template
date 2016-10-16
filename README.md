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

## Dependencies
Before you build and run the code, there are a couple of dependencies you'll
have to take care of first.

- *clang.* First, install a recent version of
  [`clang`](http://clang.llvm.org/), [`libc++`](http://libcxx.llvm.org/),
  [`clang-format`](http://bit.ly/2dttR1C), and
  [`clang-tidy`](http://bit.ly/2dttR1C). If you're running Ubuntu 14.04 or
  later, you can run the following command to get things installed:

        sudo apt-get install clang-3.8 clang-format-3.8 clang-tidy-3.8
        sudo apt-get install libc++-dev libc++abi-dev
        sudo ln -s "$(which clang-3.8)" /usr/bin/clang
        sudo ln -s "$(which clang++-3.8)" /usr/bin/clang++
        sudo ln -s "$(which clang-format-3.8)" /usr/bin/clang-format
        sudo ln -s "$(which clang-tidy-3.8)" /usr/bin/clang-tidy
- *cmake.* Next, install a recent version of
  [CMake](https://cmake.org/download/). For example,

        wget 'https://cmake.org/files/v3.6/cmake-3.6.2-Linux-x86_64.sh'
        yes | sh cmake-3.6.2-Linux-x86_64.sh
        echo 'export PATH="$PATH:$HOME/cmake-3.6.2-Linux-x86_64/bin"' >> ~/.bashrc
- *protobuf.* Finally, install the [Protocol
  Buffer](https://cmake.org/download/) compiler and libraries. For example,

        local readonly url='https://github.com/google/protobuf/releases/download/v2.6.1/protobuf-2.6.1.zip'
        local readonly name='protobuf-2.6.1'

        sudo apt-get install -y autoconf automake libtool curl make g++ unzip
        wget "$url"
        unzip "$name.zip"
        cd "$name"
        CXX="clang++ -stdlib=libc++" ./configure
        make # this takes a while
        make check
        sudo make install
        sudo ldconfig

- TODO(mwhittaker): Explain how to install clang, CMake, and protobuf.
- TODO(mwhittaker): Given a more in-depth description of how the code works and
  is organized.
