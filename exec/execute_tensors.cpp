#include "TensorUtils/TensorDim.h"
#include "TensorUtils/TensorUtils.h"

using namespace TensorUtils;

int main(int argc, char **argv) {
  
  std::cout << "Basic operation with tensors" << std::endl;

  TensorDim1 TD1_0("4x1_0", 4);
  TD1_0.Print();
  TensorDim1 TD1_1("4x1_1", 4);
  TD1_1.Print();
  
  for(int i =0; i < 4; i++){
    TD1_0(i) = i*2;
    std::cout << "Checking TD1_0(" << i << ") = " << TD1_0(i) << std::endl;
    TD1_1.Set(i, i - 4);
    std::cout << "Checking TD1_0.At(" << i << ") = " << TD1_0.At(i) << std::endl;
  }
  
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Examples of usage of TensorDim1" << std::endl;
  std::cout << "--- Element wise multiplication" << std::endl;
  TensorDim1 TD1_EWM = ElementWiseMult(TD1_0, TD1_1);
  TD1_EWM.Print();
  std::cout << "--- Dot product" << std::endl;
  TComplex TD1_DP = DotProd(TD1_0, TD1_1);
  std::cout << "result: " <<TD1_DP << std::endl;
  std::cout << "--- Cross product" << std::endl;
  TensorDim2 TD2_CP = CrossProd(TD1_0, TD1_1);
  TD2_CP.Print();
  std::cout << "--- Substraction" << std::endl;
  TensorDim1 TD1_sub = (TensorDim1)(TD1_0 - TD1_1);
  TD1_sub.Print();
  std::cout << "--- Addition" << std::endl;
  TensorDim1 TD1_add = (TensorDim1)(TD1_0 + TD1_1);
  TD1_add.Print();
  return 1;

  // TensorDim2 td2("4x2", 4);
  // td2.Print();
  // TensorDim2 td21("4x21", 4);
  // td21.Print();

  // TensorDim1 tmult1x2 = MatMult(t2, t1);
  // tmul.Print();
  // TensorDim1 tmult2x2 = MatMult(t2, t1);
  // tmul.Print();

  // TensorDim3 t3("4x3",4);
  // t3.Print();
  // TensorDim4 t4("4x4",4);
  // t4.Print();
  
  // return 1;

}
