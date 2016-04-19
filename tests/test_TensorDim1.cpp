// gtest
#include "gtest/gtest.h"

// project specific include
#include "TensorUtils/Tensor.h"
#include "TensorUtils/TensorOrder.h"
#include "TensorUtils/TensorUtils.h"

#include "TComplex.h"

using namespace TensorUtils;

TEST(TensorOrder1, DoesThings) {
  TensorOrder1 td1 = TensorOrder1();
  EXPECT_EQ(1, td1.GetOrder());
  EXPECT_EQ(4, td1.GetOrderDim());
  
  TensorOrder1 td2 = TensorOrder1("101",10);
  EXPECT_EQ(1,  td2.GetOrder());
  EXPECT_EQ(10, td2.GetOrderDim());

  TensorOrder1 td3 = TensorOrder1("102",10);
  TensorOrder1 td4 = TensorOrder1("103",10);
  TensorOrder1 td5 = TensorOrder1("104",10);
  TensorOrder1 td9 = TensorOrder1("109",10);
  TensorOrder1 td10 = TensorOrder1("1010",10);
  TensorOrder1 td11 = TensorOrder1("1011",10);
  TComplex result1(0,0);

  TComplex cu(0.,1.);

  for(int i = 0; i < 10; i++){
    td3(i) = 1. - cu;
    td4.Set(i, 1. + cu);
    td5(i) = (1. - cu) - (1. + cu);
    td9(i) = TComplex::Abs((1. - cu) * (1. + cu));
    td10(i) = ((1. - cu) * (1. + cu)).Im();
    td11(i) = ((1. - cu) * (1. + cu)).Re();
    result1 = result1 + (1. - cu) * (1. + cu);
  }

  EXPECT_EQ(2., td3+td4);
  EXPECT_EQ(td5, td3-td4);
  // EXPECT_EQ(td5, td3.MultiplyElementWise(td4));
  EXPECT_EQ(result1.Im(), DotProd(td3,td4).Im());
  EXPECT_EQ(result1.Re(), DotProd(td3,td4).Re());
  EXPECT_EQ(td9, Abs(td5));
  EXPECT_EQ(td10, Imaginary(td5));
  EXPECT_EQ(td11, Real(td5));

  TensorOrder1 td6 = TensorOrder1("30",3);
  TensorOrder1 td7 = TensorOrder1("31",3);
  TensorOrder1 td8 = TensorOrder1("32",3);
  TensorOrder1 td71 = TensorOrder1("41",4);
  TensorOrder1 td81 = TensorOrder1("42",4);
  
  TComplex result2(0,0);
  TComplex result3(0,0);
  for(int i = 0; i < 3; i++){
    td6(i) = 1. - cu;
    td7(i) = 3. * (1. - cu);
  }
  for(int i = 0; i < 4; i++){
    td71(i) = 1. - cu;
    td81(i) = 3. * (1. - cu);
    if(i == 0)
      result2 = -(1. - cu) * 3. * (1. - cu);
    else
      result2 = result2 + (1. - cu) * 3. * (1. - cu);
    result3 = result3 + (1. - cu) * 3. * (1. - cu);   
  }
  
  EXPECT_EQ(0, CrossProd(td6,td7));
  EXPECT_EQ(result3.Im(), DotProd(td71,td81).Im());
  EXPECT_EQ(result3.Re(), DotProd(td71,td81).Re());
  EXPECT_EQ(result2.Im(), DotProdMetric(td71,td81).Im());
  EXPECT_EQ(result2.Re(), DotProdMetric(td71,td81).Re());

}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
