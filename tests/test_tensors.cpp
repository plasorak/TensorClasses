// gtest
#include "gtest/gtest.h"

// project specific include
#include "TensorUtils/Tensor.h"
#include "TensorUtils/TensorOrder.h"
#include "TensorUtils/TensorUtils.h"

#include "TComplex.h"

using namespace TensorUtils;

TEST(TensorOrder1, DoesThings) {

  // Test that the order and the dimension are OK when initialising without any parameter
  TensorOrder1 td1 = TensorOrder1();
  EXPECT_EQ(1, td1.GetOrder());
  EXPECT_EQ(4, td1.GetOrderDim());
  
  // Test that the order and the dimension are OK at initialisation
  TensorOrder1 td2 = TensorOrder1("101",10);
  EXPECT_EQ(1,  td2.GetOrder());
  EXPECT_EQ(10, td2.GetOrderDim());

  // Instanciate multiple tensors to play with
  TensorOrder1 td3 = TensorOrder1("102",10);
  TensorOrder1 td4 = TensorOrder1("103",10);
  TensorOrder1 td5 = TensorOrder1("104",10);
  TensorOrder1 td9 = TensorOrder1("109",10);
  TensorOrder1 td10 = TensorOrder1("1010",10);
  TensorOrder1 td11 = TensorOrder1("1011",10);
  TensorOrder1 td12 = TensorOrder1("1012",10);

  // The result of the dot product
  TComplex result1(0,0);
  // Handy to instanciate the complex unity
  TComplex cu(0.,1.);

  // Instanciate the tensor in 2 different ways
  // one by using Tensor::operator()
  // one by using Tensor::Set()
  // Instanciate the results of the tests as well (DotProd, Real, Imaginary and Absolute parts)
  for(int i = 0; i < 10; i++){
    td3(i) = 1. - cu;
    td4.Set(i, 1. + cu);
    td5(i) = (1. - cu) - (1. + cu);
    td9(i) = TComplex::Abs((1. - cu) * (1. + cu)); // Abs result
    td10(i) = ((1. - cu) * (1. + cu)).Im();        // Imaginary part
    td11(i) = ((1. - cu) * (1. + cu)).Re();        // Real
    td12(i) = ((1. - cu) * (1. + cu));
    result1 = result1 + (1. - cu) * (1. + cu);     // Dot product
  }
  
  // Check that one can do double == tensor
  // Also check that the addition works
  EXPECT_EQ(2., td3+td4);
  
  // Check the substraction works
  // and that one can do tensor == tensor
  EXPECT_EQ(td5, td3-td4);
  
  // Not sure why this isn't working??
  //EXPECT_EQ(td5, td3.MultiplyElementWise(td4)); 
  
  // Check the TensorOrder1::DotProd (dot product) works
  // This would be much more elegant is one could do TComplex == TComplex...
  EXPECT_EQ(result1.Im(), DotProd(td3,td4).Im());
  EXPECT_EQ(result1.Re(), DotProd(td3,td4).Re());
  
  // Check the Tensor::Abs function works
  EXPECT_EQ(td9, Abs(td12));
  
  // Check the Tensor::Imaginary function works
  EXPECT_EQ(td10, Imaginary(td12));
  
  // Check the Tensor::Real function works
  EXPECT_EQ(td11, Real(td12));

  // Some more tensor to play with!
  // This time use dimension 4 and 3 to be able to make CrossProducts and constraction with the MetricTensor
  TensorOrder1 td6 = TensorOrder1("30",3);
  TensorOrder1 td7 = TensorOrder1("31",3);
  TensorOrder1 td8 = TensorOrder1("32",3);
  TensorOrder1 td71 = TensorOrder1("41",4);
  TensorOrder1 td81 = TensorOrder1("42",4);
  
  // The results...
  TComplex result2(0,0); // DotProduct
  TComplex result3(0,0); // Dot product after contraction with metric tensor
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
  // Check the cross production function of TensorUtils
  EXPECT_EQ(0, CrossProd(td6,td7));

  // Check (again) the Dot product
  EXPECT_EQ(result3.Im(), DotProd(td71,td81).Im());
  EXPECT_EQ(result3.Re(), DotProd(td71,td81).Re());

  // Check the Dot product after contraction with the metric Matrix.
  EXPECT_EQ(result2.Im(), DotProdMetric(td71,td81).Im());
  EXPECT_EQ(result2.Re(), DotProdMetric(td71,td81).Re());
  
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
