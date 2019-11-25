#include "gtest/gtest.h"

#include "unitTest.hpp"
#include "../src/Execute.cpp"
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
