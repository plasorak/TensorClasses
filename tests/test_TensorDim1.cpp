// gtest
#include "gtest/gtest.h"

// project specific include
// #include "TensorUtils/Example.h"
#include "TensorUtils/TensorDim1.h"
#include "TensorUtils/TensorDim2.h"

using namespace TensorUtils;

TEST(TensorDim1, DoesThings) {
  auto td = TensorDim1();
  std::cout << td.GetDim() << std::endl;
  EXPECT_EQ(1,td.GetDim());

  td = TensorDim1(10);
  EXPECT_EQ(1,td.GetDim());

  // e.set(12);
  // EXPECT_EQ(12,e.get());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
