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
  EXPECT_EQ("none", td1.GetName());
  for(int i = 0; i < td1.GetOrderDim(); i++){
    EXPECT_EQ(0, td1(i).Re()); // Check operator ()
    EXPECT_EQ(0, td1(i).Im());
    EXPECT_EQ(0, td1.At(i).Re()); // Check function At
    EXPECT_EQ(0, td1.At(i).Im());
    
  }

  // Test that the order and the dimension are OK at initialisation
  TensorOrder1 td2 = TensorOrder1("101",10);
  EXPECT_EQ(1,  td2.GetOrder());
  EXPECT_EQ(10, td2.GetOrderDim());
  // EXPECT_EQ("101", td2.GetName());
  for(int i = 0; i < td2.GetOrderDim(); i++){
    EXPECT_EQ(0, td2(i).Re());
    EXPECT_EQ(0, td2(i).Im());
  }

  // Instanciate multiple tensors to play with
  TensorOrder1 td3  = TensorOrder1("102",10);
  TensorOrder1 td4  = TensorOrder1("103",10);
  TensorOrder1 td5  = TensorOrder1("104",10);
  TensorOrder1 td6  = TensorOrder1("106",10);
  TensorOrder1 td9  = TensorOrder1("109",10);
  TensorOrder1 td10 = TensorOrder1("1010",10);
  TensorOrder1 td11 = TensorOrder1("1011",10);
  TensorOrder1 td12 = TensorOrder1("1012",10);
  TensorOrder1 td13 = TensorOrder1("1013",10);
  TensorOrder1 td15 = TensorOrder1("1015",10);
  TensorOrder1 td16 = TensorOrder1("1016",10);
  TensorOrder1 td17 = TensorOrder1("1017",10);
  TensorOrder1 td18 = TensorOrder1("1018",10);
  TensorOrder1 td19 = TensorOrder1("1019",10);
  TensorOrder1 td20 = TensorOrder1("1020",10);
  TensorOrder1 td21 = TensorOrder1("1021",10);
  TensorOrder1 td22 = TensorOrder1("1022",10);

  // The result of the dot product
  TComplex result1(0,0);
  // Handy to instanciate the complex unity
  TComplex cu(0.,1.);

  // Instanciate the tensor in 2 different ways
  // one by using Tensor::operator()
  // one by using Tensor::Set()
  // Instanciate the results of the tests
  
  for(int i = 0; i < 10; i++){
    td3(i) = 1. - cu; // Using operator()
    td4.Set(i, 1. + cu); // Using Set
    td15(i) = 2. * (1. - cu);  // Result of Multiply(2)
    td16(i) = 0.5 * (1. - cu); // Result of Divide(2)
    td18(i) = (1. - cu) + 4.; // Result of operator+
    td19(i) = (1. - cu) - 4.; // Result of operator-
    td20(i) = (1. - cu) * 4.; // Result of operator*
    td21(i) = (1. - cu) / 4.; // Result of operator/
    td22(i) = 1. / (1. - cu); // Result of OnOverElenentWise
    td5(i) = (1. - cu) - (1. + cu);  // Result of operator -
    td6(i) = (1. - cu) + (1. + cu);  // Result of operator +
    td12(i) = ((1. - cu) * (1. + cu));             // Result of ElementWiseMult
    td9(i) = TComplex::Abs((1. - cu) * (1. + cu)); // Result of Abs
    td10(i) = ((1. - cu) * (1. + cu)).Im();        // Result of Imaginary
    td11(i) = ((1. - cu) * (1. + cu)).Re();        // Result of Real
    td17(i) = 100000.*(1.+cu);                     // A big number for operators <, >, >=, <=
    result1 = result1 + (1. - cu) * (1. + cu);     // Result of DotProd
  }
  
  //Check that the operator = - and + works
  td13 = td3+td4;
  EXPECT_EQ(td6, td3+td4);
  EXPECT_EQ(td5, td3-td4);
  EXPECT_EQ(td13, td3+td4);
  
  // Check that the copy constructor works
  TensorOrder1 td14(td13);
  EXPECT_EQ(td14, td13);
  
  //Check that the functions Tensor::Add, Tensor::Substract, Tensor::Multiply, Tensor::Divide work
  td3.Add(td4);
  EXPECT_EQ(td13, td3);
  td3.Subtract(td4);
  EXPECT_EQ(td13-td4, td3);
  td3.Multiply(2);
  EXPECT_EQ(td15, td3);
  td3.Divide(4);
  EXPECT_EQ(td3, td16);
  td3.Multiply(2);

  // operator *, / + - for int, double, TComplex
  TensorOrder1 t01 = td3 + (int)4;
  TensorOrder1 t02 = td3 + (double)4;
  TensorOrder1 t03 = td3 + (TComplex)4;
  EXPECT_EQ(td18, t01);
  EXPECT_EQ(td18, t02);
  EXPECT_EQ(td18, t03);
  TensorOrder1 t04 = td3 - (int)4;     
  TensorOrder1 t05 = td3 - (double)4;  
  TensorOrder1 t06 = td3 - (TComplex)4;
  EXPECT_EQ(td19, t04);
  EXPECT_EQ(td19, t05);
  EXPECT_EQ(td19, t06);
  TensorOrder1 t07 = td3 * (int)4;     
  TensorOrder1 t08 = td3 * (double)4;  
  TensorOrder1 t09 = td3 * (TComplex)4;
  EXPECT_EQ(td20, t07);
  EXPECT_EQ(td20, t08);
  EXPECT_EQ(td20, t09);
  TensorOrder1 t010 = td3 / (int)4;     
  TensorOrder1 t011 = td3 / (double)4;
  TensorOrder1 t012 = td3 / (TComplex)4;
  EXPECT_EQ(td21, t010);
  EXPECT_EQ(td21, t011);
  EXPECT_EQ(td21, t012);

  // TensorOrder1 td16 = (double)2.
  

  //Check that one can do double == tensor
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

  // // Some more tensor to play with!
  // // This time use dimension 4 and 3 to be able to make CrossProducts and constraction with the MetricTensor
  TensorOrder1 td116 = TensorOrder1("30",3);
  TensorOrder1 td117 = TensorOrder1("31",3);
  TensorOrder1 td118 = TensorOrder1("32",3);
  TensorOrder1 td1171 = TensorOrder1("41",4);
  TensorOrder1 td1181 = TensorOrder1("42",4);
  
  // The results...
  TComplex result2(0,0); // DotProduct
  TComplex result3(0,0); // Dot product after contraction with metric tensor
  for(int i = 0; i < 3; i++){
    td116(i) = 1. - cu; 
    td117(i) = 3. * (1. - cu);
  }
  for(int i = 0; i < 4; i++){
    td1171(i) = 1. - cu;
    td1181(i) = 3. * (1. - cu);
    if(i == 0)
      result2 = -(1. - cu) * 3. * (1. - cu);
    else
      result2 = result2 + (1. - cu) * 3. * (1. - cu);
    result3 = result3 + (1. - cu) * 3. * (1. - cu);   
  }
  // Check the cross production function of TensorUtils
  EXPECT_EQ(0, CrossProd(td116,td117));

  // Check (again) the Dot product
  EXPECT_EQ(result3.Im(), DotProd(td1171,td1181).Im());
  EXPECT_EQ(result3.Re(), DotProd(td1171,td1181).Re());

  // Check the Dot product after contraction with the metric Matrix.
  EXPECT_EQ(result2.Im(), DotProdMetric(td1171,td1181).Im());
  EXPECT_EQ(result2.Re(), DotProdMetric(td1171,td1181).Re());
  
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
