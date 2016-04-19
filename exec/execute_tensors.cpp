#include "TensorUtils/TensorOrder.h"
#include "TensorUtils/TensorUtils.h"

using namespace TensorUtils;

int main(int argc, char **argv) {
  
  std::cout << "Basic operation with tensors" << std::endl;

  TensorOrder1 TD1_0("4x1_0", 4);
  TD1_0.Print();
  TensorOrder1 TD1_1("4x1_1", 4);
  TD1_1.Print();
  TComplex cu(0.,1.);

  for(int i = 0; i < 4; i++){
    std::cout << "Setting  TD1_0(" << i << ") = " <<  (double)i*2. + ((double)i+4.)*cu << std::endl;
    TD1_0(i) = (double)i*2. + ((double)i+4.)*cu;
    std::cout << "Checking TD1_0(" << i << ") = " << TD1_0(i) << std::endl;
    std::cout << "Setting  TD1_0.Set(" << i << ") = " << (double)i - 4. << std::endl;
    TD1_1.Set(i, (double)i - 4. + (double)(2.*i+1.)*cu);
    std::cout << "Checking TD1_0.At(" << i << ")  = " << TD1_0.At(i) << std::endl;
  }
  
  TD1_0.Print();
  TD1_1.Print();

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Examples of usage of TensorOrder1" << std::endl;
  std::cout << "--- Element wise multiplication" << std::endl;
  TensorOrder1 TD1_EWM(TD1_0);
  TD1_EWM.MultiplyElementWise(TD1_1);
  TD1_EWM.Print();
  std::cout << "--- Dot product" << std::endl;
  TComplex TD1_DP = DotProd(TD1_0, TD1_1);
  std::cout << "result: " << TD1_DP << std::endl;
  std::cout << "--- Dot product 'with metric'" << std::endl;
  TComplex TD1_DPM = DotProdMetric(TD1_0, TD1_1);
  std::cout << "result: " << TD1_DPM << std::endl;
  std::cout << "--- Cross product" << std::endl;

  TensorOrder1 TD1_2("3x1_0", 3);
  TD1_2.Print();
  TensorOrder1 TD1_3("3x1_1", 3);
  TD1_3.Print();

  if(TD1_2 == TD1_3)
    std::cout<< "------ true" << std::endl;

  for(int i = 0; i < 3; i++){
    std::cout << "Setting  TD1_2(" << i << ") = " <<  (double)i*2. << std::endl;
    TD1_2(i) = i*2;
    std::cout << "Checking TD1_2(" << i << ") = " << TD1_2(i) << std::endl;
    std::cout << "Setting  TD1_3.Set(" << i << ") = " << (double)i - 4. << std::endl;
    TD1_3.Set(i, (double)i - 4.);
    std::cout << "Checking TD1_3.At(" << i << ")  = " << TD1_3.At(i) << std::endl;
  }
  TensorOrder1 TD2_CP = CrossProd(TD1_2, TD1_3);
  TD2_CP.Print();
  std::cout << "--- Substraction" << std::endl;
  TensorOrder1 TD1_sub = TD1_0 - TD1_1;
  TD1_sub.Print();
  std::cout << "--- Addition" << std::endl;
  TensorOrder1 TD1_add = TD1_0 + TD1_1;
  TD1_add.Print();
  TensorOrder2 TD2_D0 = DiracMatrix(0);
  TensorOrder2 TD2_D1 = DiracMatrix(1);
  TensorOrder2 TD2_D2 = DiracMatrix(2);
  TensorOrder2 TD2_D3 = DiracMatrix(3);
  TensorOrder2 TD2_D5 = DiracMatrix(5);
  TD2_D0.Print();
  TD2_D1.Print();
  TD2_D2.Print();
  TD2_D3.Print();
  TD2_D5.Print();

  std::cout << "--- Slash Dirac" << std::endl;
  TensorOrder2 TD2_DM0 = SlashDirac(TD1_0);
  TD2_DM0.Print();
  TensorOrder2 TD2_DM1 = SlashDirac(TD1_1);
  TD2_DM1.Print();
  
  std::cout << "--- Substraction" << std::endl;
  TensorOrder2 TD2_sub = TD2_DM0 - TD2_DM1;
  TD2_sub.Print();
  std::cout << "--- Addition" << std::endl;
  TensorOrder2 TD2_add = TD2_DM0 + TD2_DM1;
  TD2_add.Print();
  
  std::cout << "--- Matrix Multiplication" << std::endl;
  TensorOrder2 TD2_mult = TD2_DM0 * TD2_DM1;
  TD2_mult.Print();
  std::cout << "--- Vector Multiplication" << std::endl;
  TensorOrder1 TD1_mult_1 = TD2_DM1 * TD1_add;
  TD1_mult_1.Print();
  

  TensorOrder3 TD3_0("4x3_0", 4);
  TD3_0.Print();
  TensorOrder3 TD3_1("4x3_1", 4);
  TD3_1.Print();
  
  for(int i1 = 0; i1 < 4; i1++){
    for(int i2 = 0; i2 < 4; i2++){
      for(int i3 = 0; i3 < 4; i3++){
	TD3_0(i1,i2,i3) =  cu*1. + 1.;
	TD3_1(i1,i2,i3) = -cu*1. + 1.;
      }
    }
  }
  TD3_0.Print();
  TD3_1.Print();
  


  TensorOrder3 TD3_add = TD3_0 + TD3_1;
  TD3_add.Print();
  TensorOrder3 TD3_sub = TD3_0 - TD3_1;
  TD3_sub.Print();

  TensorOrder3 TD3_mult = cu * TD3_0;
  TD3_mult.Print();


  TensorOrder4 TD4_0("4x4_0",4);
  TD4_0.Print();

  TensorOrder4 TD4_1("4x4_1",4);
  TD4_1.Print();

  for(int i1 = 0; i1 < 4; i1++){
    for(int i2 = 0; i2 < 4; i2++){
      for(int i3 = 0; i3 < 4; i3++){
	for(int i4 = 0; i4 < 4; i4++){
	  TD4_0(i1,i2,i3,i4) =  cu*1. + 1.;
	  TD4_1(i1,i2,i3,i4) = -cu*1. + 1.;
	}
      }
    }
  }

  TensorOrder4 TD4_add = TD4_0 + TD4_1;
  TD4_add.Print();
  TensorOrder4 TD4_sub = TD4_0 - TD4_1;
  TD4_sub.Print();
  TensorOrder4 TD4_mult = cu * TD4_0;
  TD4_mult.Print();
  return 1;


}
