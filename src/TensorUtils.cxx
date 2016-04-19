#include "TensorUtils/Tensor.h"
#include "TensorUtils/TensorOrder.h"
#include "TensorUtils/TensorUtils.h"
#include "TString.h"

namespace TensorUtils {

 
  // -----------------------------------------------------
  // Common tensors
  // -----------------------------------------------------

  TensorOrder2 LeviCivitaOrder2(){
    TensorOrder2 t(Form("LeviCivitaOrder2_%ix%i", 2, 2), 2);
    // From Wikipedia's Levi-Civita symbol page
    t(0,0) =  0.; t(0,1) =  1.;
    t(1,0) = -1.; t(1,1) =  0.;

    return t;
  };

  TensorOrder3 LeviCivitaOrder3(){
    TensorOrder3 t(Form("LeviCivitaOrder3_%ix%ix%i", 3, 3, 3), 3);
    // From  Wikipedia
    // Some of these ones are useless since the tensor is instanciated with 0 everywheres, just to make sure...
    t(0,0,0) =  0.; t(0,0,1) =  0.; t(0,0,2) =  0.; 
    t(0,1,0) =  0.; t(0,1,1) =  0.; t(0,1,2) =  1.;
    t(0,2,0) =  0.; t(0,2,1) = -1.; t(0,2,2) =  0.;

    t(1,0,0) =  0.; t(1,0,1) =  0.; t(1,0,2) = -1.;
    t(1,1,0) =  0.; t(1,1,1) =  0.; t(1,1,2) =  0.;
    t(1,2,0) =  1.; t(1,2,1) =  0.; t(1,2,2) =  0.;

    t(2,0,0) =  0.; t(2,0,1) =  1.; t(2,0,2) =  0.;
    t(2,1,0) = -1.; t(2,1,1) =  0.; t(2,1,2) =  0.;
    t(2,2,0) =  0.; t(2,2,1) =  0.; t(2,2,2) =  0.;

    return t;
  };

  TensorOrder4 LeviCivitaOrder4(){
    TensorOrder4 t(Form("LeviCivitaOrder4_%ix%ix%ix%i",4, 4, 4, 4), 4);
    // Ugly! but I'm not good in math enough to do it properly
    t(0,0,0,0) =  0.; t(0,0,0,1) =  0.; t(0,0,0,2) =  0.; t(0,0,0,3) =  0.;
    t(0,0,1,0) =  0.; t(0,0,1,1) =  0.; t(0,0,1,2) =  0.; t(0,0,1,3) =  0.;
    t(0,0,2,0) =  0.; t(0,0,2,1) =  0.; t(0,0,2,2) =  0.; t(0,0,2,3) =  0.;
    t(0,0,3,0) =  0.; t(0,0,3,1) =  0.; t(0,0,3,2) =  0.; t(0,0,3,3) =  0.;

    t(0,1,0,0) =  0.; t(0,1,0,1) =  0.; t(0,1,0,2) =  0.; t(0,1,0,3) =  0.;
    t(0,1,1,0) =  0.; t(0,1,1,1) =  0.; t(0,1,1,2) =  0.; t(0,1,1,3) =  0.;
    t(0,1,2,0) =  0.; t(0,1,2,1) =  0.; t(0,1,2,2) =  0.; t(0,1,2,3) =  1.;
    t(0,1,3,0) =  0.; t(0,1,3,1) =  0.; t(0,1,3,2) = -1.; t(0,1,3,3) =  0.;

    t(0,2,0,0) =  0.; t(0,2,0,1) =  0.; t(0,2,0,2) =  0.; t(0,2,0,3) =  0.;
    t(0,2,1,0) =  0.; t(0,2,1,1) =  0.; t(0,2,1,2) =  0.; t(0,2,1,3) = -1.;
    t(0,2,2,0) =  0.; t(0,2,2,1) =  0.; t(0,2,2,2) =  0.; t(0,2,2,3) =  0.;
    t(0,2,3,0) =  0.; t(0,2,3,1) =  1.; t(0,2,3,2) =  0.; t(0,2,3,3) =  0.;

    t(0,3,0,0) =  0.; t(0,3,0,1) =  0.; t(0,3,0,2) =  0.; t(0,3,0,3) =  0.;
    t(0,3,1,0) =  0.; t(0,3,1,1) =  0.; t(0,3,1,2) =  1.; t(0,3,1,3) =  0.;
    t(0,3,2,0) =  0.; t(0,3,2,1) = -1.; t(0,3,2,2) =  0.; t(0,3,2,3) =  0.;
    t(0,3,3,0) =  0.; t(0,3,3,1) =  0.; t(0,3,3,2) =  0.; t(0,3,3,3) =  0.;


    t(1,0,0,0) =  0.; t(1,0,0,1) =  0.; t(1,0,0,2) =  0.; t(1,0,0,3) =  0.;
    t(1,0,1,0) =  0.; t(1,0,1,1) =  0.; t(1,0,1,2) =  0.; t(1,0,1,3) =  0.;
    t(1,0,2,0) =  0.; t(1,0,2,1) =  0.; t(1,0,2,2) =  0.; t(1,0,2,3) = -1.;
    t(1,0,3,0) =  0.; t(1,0,3,1) =  0.; t(1,0,3,2) =  1.; t(1,0,3,3) =  0.;

    t(1,1,0,0) =  0.; t(1,1,0,1) =  0.; t(1,1,0,2) =  0.; t(1,1,0,3) =  0.;
    t(1,1,1,0) =  0.; t(1,1,1,1) =  0.; t(1,1,1,2) =  0.; t(1,1,1,3) =  0.;
    t(1,1,2,0) =  0.; t(1,1,2,1) =  0.; t(1,1,2,2) =  0.; t(1,1,2,3) =  0.;
    t(1,1,3,0) =  0.; t(1,1,3,1) =  0.; t(1,1,3,2) =  0.; t(1,1,3,3) =  0.;

    t(1,2,0,0) =  0.; t(1,2,0,1) =  0.; t(1,2,0,2) =  0.; t(1,2,0,3) =  0.;
    t(1,2,1,0) =  0.; t(1,2,1,1) =  0.; t(1,2,1,2) =  0.; t(1,2,1,3) = -1.;
    t(1,2,2,0) =  0.; t(1,2,2,1) =  0.; t(1,2,2,2) =  0.; t(1,2,2,3) =  0.;
    t(1,2,3,0) =  0.; t(1,2,3,1) =  1.; t(1,2,3,2) =  0.; t(1,2,3,3) =  0.;

    t(1,3,0,0) =  0.; t(1,3,0,1) =  0.; t(1,3,0,2) = -1.; t(1,3,0,3) =  0.;
    t(1,3,1,0) =  0.; t(1,3,1,1) =  0.; t(1,3,1,2) =  0.; t(1,3,1,3) =  0.;
    t(1,3,2,0) =  1.; t(1,3,2,1) =  0.; t(1,3,2,2) =  0.; t(1,3,2,3) =  0.;
    t(1,3,3,0) =  0.; t(1,3,3,1) =  0.; t(1,3,3,2) =  0.; t(1,3,3,3) =  0.;
    

    t(2,0,0,0) =  0.; t(2,0,0,1) =  0.; t(2,0,0,2) =  0.; t(2,0,0,3) =  0.;
    t(2,0,1,0) =  0.; t(2,0,1,1) =  0.; t(2,0,1,2) =  0.; t(2,0,1,3) =  1.;
    t(2,0,2,0) =  0.; t(2,0,2,1) =  0.; t(2,0,2,2) =  0.; t(2,0,2,3) =  0.;
    t(2,0,3,0) =  0.; t(2,0,3,1) = -1.; t(2,0,3,2) =  0.; t(2,0,3,3) =  0.;
    
    t(2,1,0,0) =  0.; t(2,1,0,1) =  0.; t(2,1,0,2) =  0.; t(2,1,0,3) = -1.;
    t(2,1,1,0) =  0.; t(2,1,1,1) =  0.; t(2,1,1,2) =  0.; t(2,1,1,3) =  0.;
    t(2,1,2,0) =  0.; t(2,1,2,1) =  0.; t(2,1,2,2) =  0.; t(2,1,2,3) =  0.;
    t(2,1,3,0) = -1.; t(2,1,3,1) =  0.; t(2,1,3,2) =  0.; t(2,1,3,3) =  0.;
       			 		   		     
    t(2,2,0,0) =  0.; t(2,2,0,1) =  0.; t(2,2,0,2) =  0.; t(2,2,0,3) =  0.;
    t(2,2,1,0) =  0.; t(2,2,1,1) =  0.; t(2,2,1,2) =  0.; t(2,2,1,3) =  0.;
    t(2,2,2,0) =  0.; t(2,2,2,1) =  0.; t(2,2,2,2) =  0.; t(2,2,2,3) =  0.;
    t(2,2,3,0) =  0.; t(2,2,3,1) =  0.; t(2,2,3,2) =  0.; t(2,2,3,3) =  0.;
    
    t(2,3,0,0) =  0.; t(2,3,0,1) =  1.; t(2,3,0,2) =  0.; t(2,3,0,3) =  0.;
    t(2,3,1,0) = -1.; t(2,3,1,1) =  0.; t(2,3,1,2) =  0.; t(2,3,1,3) =  0.;
    t(2,3,2,0) =  0.; t(2,3,2,1) =  0.; t(2,3,2,2) =  0.; t(2,3,2,3) =  0.;
    t(2,3,3,0) =  0.; t(2,3,3,1) =  0.; t(2,3,3,2) =  0.; t(2,3,3,3) =  0.;
    
    
    t(3,0,0,0) =  0.; t(3,0,0,1) =  0.; t(3,0,0,2) =  0.; t(3,0,0,3) =  0.;
    t(3,0,1,0) =  0.; t(3,0,1,1) =  0.; t(3,0,1,2) = -1.; t(3,0,1,3) =  0.;
    t(3,0,2,0) =  0.; t(3,0,2,1) =  1.; t(3,0,2,2) =  0.; t(3,0,2,3) =  0.;
    t(3,0,3,0) =  0.; t(3,0,3,1) =  0.; t(3,0,3,2) =  0.; t(3,0,3,3) =  0.;
    
    t(3,1,0,0) =  0.; t(3,1,0,1) =  0.; t(3,1,0,2) =  1.; t(3,1,0,3) =  0.;
    t(3,1,1,0) =  0.; t(3,1,1,1) =  0.; t(3,1,1,2) =  0.; t(3,1,1,3) =  0.;
    t(3,1,2,0) =  0.; t(3,1,2,1) =  0.; t(3,1,2,2) =  0.; t(3,1,2,3) =  0.;
    t(3,1,3,0) = -1.; t(3,1,3,1) =  0.; t(3,1,3,2) =  0.; t(3,1,3,3) =  0.;

    t(3,2,0,0) =  0.; t(3,2,0,1) = -1.; t(3,2,0,2) =  0.; t(3,2,0,3) =  0.;
    t(3,2,1,0) =  1.; t(3,2,1,1) =  0.; t(3,2,1,2) =  0.; t(3,2,1,3) =  0.;
    t(3,2,2,0) =  0.; t(3,2,2,1) =  0.; t(3,2,2,2) =  0.; t(3,2,2,3) =  0.;
    t(3,2,3,0) =  0.; t(3,2,3,1) =  0.; t(3,2,3,2) =  0.; t(3,2,3,3) =  0.;
			 		   		     
    t(3,3,0,0) =  0.; t(3,3,0,1) =  0.; t(3,3,0,2) =  0.; t(3,3,0,3) =  0.;
    t(3,3,1,0) =  0.; t(3,3,1,1) =  0.; t(3,3,1,2) =  0.; t(3,3,1,3) =  0.;
    t(3,3,2,0) =  0.; t(3,3,2,1) =  0.; t(3,3,2,2) =  0.; t(3,3,2,3) =  0.;
    t(3,3,3,0) =  0.; t(3,3,3,1) =  0.; t(3,3,3,2) =  0.; t(3,3,3,3) =  0.;
    return t;
  };

  TensorOrder2 Metric(){
    TensorOrder2 t(Form("Metric_%ix%i", 4, 4), 4);
    for(int i = 0; i < 4; i++) { t(i,i) = 1.; }
    t(0,0) = -1.;
    return t;
  };

  TensorOrder2 UnityOrder2(int size){
    TensorOrder2 t(Form("UnityOrder2_%ix%i"), size);
    for(int i = 0; i < size; i++) { t(i,i) = 1.; }
    return t;
  };

  TensorOrder3 UnityOrder3(int size){
    TensorOrder3 t(Form("UnityOrder3_%ix%ix%i", size, size, size), size);
    for(int i = 0; i < size; i++) { t(i,i,i) = 1.; }
    return t;
  };

  TensorOrder4 UnityOrder4(int size){
    TensorOrder4 t(Form("UnitySize4_%ix%ix%ix%i", size, size, size), size);
    for(int i = 0; i < size; i++) { t(i,i,i,i) = 1; }
    return t;
  };

  TensorOrder2 DiracMatrix(int i){
    TensorOrder2 t(Form("DiracMatrix%i", i), 4);
    //Define the imaginary unity
    TComplex cu(0.,1.);
    
    switch(i){
    case 0:
      t(0,0) =  1.;
      t(1,1) =  1.;
      t(2,2) = -1.;
      t(3,3) = -1.;
      break;
    case 1:
      t(0,3) =  1.;
      t(1,2) =  1.;
      t(2,1) = -1.;
      t(3,0) = -1.;
      break;
    case 2:
      t(0,3) = -cu;
      t(1,2) =  cu;
      t(2,1) =  cu;
      t(3,0) = -cu;
      break;
    case 3:
      t(0,2) =  1.;
      t(1,3) = -1.;
      t(2,0) = -1.;
      t(3,1) =  1.;
      break;
    case 5:
      t(0,2) = 1.;
      t(1,3) = 1.;
      t(2,0) = 1.;
      t(3,1) = 1.;
      break;
    default:
      std::cout << "Dirac matrix number " << i << " not supported (only 0,1,2,3,5 exist)!" << std::endl;
      exit(1);
    }
    
    return t;
  };

  TensorOrder1 CrossProd(const TensorOrder1 &t1, const TensorOrder1 &t2){
    t1.AssertGoodSize(1);
    t1.AssertGoodSize(0,3);
    t2.AssertGoodSize(0,3);
    t1.AssertGoodSize(t2);

    TensorOrder1 result(Form("(%sX%s)",t1.GetName(),t2.GetName()), 3);

    result(0) = t1(1) * t2(2) - t1(2) * t2(1);
    result(0) = t1(2) * t2(0) - t1(0) * t2(2);
    result(0) = t1(0) * t2(1) - t1(1) * t2(0);

    return result;
  };


  TComplex DotProd(const TensorOrder1 &t1, const TensorOrder1 &t2){
    t1.AssertGoodSize(1);
    t2.AssertGoodSize(1);
    t1.AssertGoodSize(t2);

    TensorOrder1 result(t1);

    result.MultiplyElementWise(t2);
    return result.SumOver();

  };
  
  TComplex DotProdMetric(const TensorOrder1 &t1, const TensorOrder1 &t2){
    t1.AssertGoodSize(1);
    t1.AssertGoodSize(0,4);
    t2.AssertGoodSize(0,4);
    t1.AssertGoodSize(t2);

    TComplex result(0.,0.);
    TensorOrder2 m = Metric();

    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
	result += t1(i) * m(i,j) * t2(j);

    return result;

  };
  
  TensorOrder2 SlashDirac(const TensorOrder1 &t1){

    t1.AssertGoodSize(1);
    t1.AssertGoodSize(0,4);

    TensorOrder2 result(Form("SlashDirac(%s)",t1.GetName()),4);

    for(int i = 0; i < 4; i++){
      TensorOrder2 add(t1(i) * DiracMatrix(i));
      result = result + add;
    }

    return result;
  };

 
}
