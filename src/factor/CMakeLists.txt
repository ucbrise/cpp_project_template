CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_LIBRARY(factor factor.cc)

ADD_EXECUTABLE(factor_test factor_test.cc factor.cc)
ADD_TEST(factor_test factor_test)
TARGET_LINK_LIBRARIES(factor_test
    ${GTEST_LIBS_DIR}/libgtest.a
    ${GTEST_LIBS_DIR}/libgtest_main.a
    pthread
)

ADD_EXECUTABLE(factor_bench factor_bench.cc factor.cc)
TARGET_LINK_LIBRARIES(factor_bench
    ${GBENCH_LIBS_DIR}/libbenchmark.a
    pthread
)
