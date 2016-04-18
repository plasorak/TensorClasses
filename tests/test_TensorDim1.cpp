// gtest
#include "gtest/gtest.h"

// project specific include
#include "TensorUtils/Tensor.h"
#include "TensorUtils/TensorDim.h"

using namespace TensorUtils;

TEST(TensorDim1, DoesThings) {
  TensorDim1 td = TensorDim1();
  std::cout << td.GetDim() << std::endl;
  //EXPECT_EQ(1, td.GetDim());
  EXPECT_EQ(4, td.GetDimSize());
  
  td = TensorDim1("10",10);
  //EXPECT_EQ(1,td.GetDim());

  // e.set(12);
  // EXPECT_EQ(12,e.get());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
