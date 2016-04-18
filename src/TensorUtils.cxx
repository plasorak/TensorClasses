#include "TensorUtils/Tensor.h"
#include "TensorUtils/TensorDim.h"
#include "TensorUtils/TensorUtils.h"
#include "TString.h"

namespace TensorUtils {


  // -----------------------------------------------------
  // Common tensors
  // -----------------------------------------------------

  TensorDim2 LeviCivitaDim2(){
    TensorDim2 t("LeviCivitaDim2", 4);
    return t;
  };

  TensorDim3 LeviCivitaDim3(){
    TensorDim3 t("LeviCivitaDim3", 4);
    return t;
  };

  TensorDim4 LeviCivitaDim4(){
    TensorDim4 t("LeviCivitaDim4", 4);
    return t;
  };

  TensorDim2 Metric(){
    TensorDim2 t("Metric", 4);
    return t;
  };

  TensorDim2 UnityDim2(){
    TensorDim2 t("UnityDim2", 4);
    return t;
  };

  TensorDim3 UnityDim3(){
    TensorDim3 t("UnityDim2", 4);
    return t;
  };

  TensorDim4 UnityDim4(){
    TensorDim4 t("UnityDim4", 4);
    return t;
  };

  TensorDim2 DiracMatrix(unsigned int i){
    TensorDim2 t(Form("DiracMatrix%i", i), 4);
    return t;
  };

  // TensorDim2 MatMult(const TensorDim2 &t1,  const TensorDim2 &t2){

  //   // First check the dimension of the matrix
  //   if(t1.GetDim() != 2 || t2.GetDim() != 2){
  //     std::cerr << "Can't do the matrix product, one of the tensor is not a matrix or vector" << std::endl;
  //     exit(1);
  //   }

  //   // Then check that size are good for multiplication
  //   // (i * j) (j * k) = (i * k)
  //   if(t1.GetDimSize(1) !=  t2.GetDimSize(0)){
  //     std::cerr << "Can't do the matrix product, the matrix sizes are not right" << std::endl;
  //     exit(1);
  //   }
  //   char* resultName;
  //   strcpy(resultName, t1.GetName());
  //   strcat(resultName, t2.GetName());

  //   TensorDim2 result(resultName, t1.GetDimSize(0), t2.GetDimSize(1));

  //   for(int i = 0; i < t1.GetDimSize(0); i++)
  //     for(int j = 0; j < t2.GetDimSize(1); j++)
  // 	for(int k = 0; k < t1.GetDimSize(1); k++)
  // 	  result(i,j) += t1(i,k)*t2(k,j);
    
  //   return result;
  // }

  // TensorDim1 MatMult(const TensorDim2 &t1, const TensorDim1 &t2){

  //   // First check the dimension of the matrix
  //   if(t1.GetDim() != 2 || t2.GetDim() != 1){
  //     std::cerr << "Can't do the matrix product, one of the tensor is not a matrix or vector" << std::endl;
  //     exit(1);
  //   }

  //   // Then check that size are good for multiplication
  //   // (i * j) (j) = (i)
  //   if(t1.GetDimSize(1) !=  t2.GetDimSize(0)){
  //     std::cerr << "Can't do the matrix product, the matrix and vector sizes are not right" << std::endl;
  //     exit(1);
  //   }
  //   char* resultName;
  //   strcpy(resultName, t1.GetName());
  //   strcat(resultName, t2.GetName());
  //   TensorDim1 result(resultName, t1.GetDimSize(0));

  //   for(int i = 0; i < t1.GetDimSize(0); i++)
  //     for(int j = 0; j < t2.GetDimSize(1); j++)
  // 	result(i) += t1(i,j)*t2(j);
    
  //   return result;
  // }
  
  TensorDim2 CrossProd(const TensorDim1 &t1, const TensorDim1 &t2){
    
    // First check the dimension of the matrix
    if(t1.GetDim() != 2 || t2.GetDim() != 1){
      std::cerr << "Can't do the matrix product, one of the tensor is not a matrix or vector" << std::endl;
      exit(1);
    }

    // Then check that size are good for multiplication
    // (i * j) (j) = (i)
    if(t1.GetDimSize(0) !=  t2.GetDimSize(0)){
      std::cerr << "Can't do the matrix product, the matrix and vector sizes are not right" << std::endl;
      exit(1);
    }
    char* resultName;
    strcpy(resultName, t1.GetName());
    strcat(resultName, t2.GetName());
    TensorDim2 result(resultName, t1.GetDimSize(0));
    
    for(int i = 0; i < t1.GetDimSize(0); i++){
      for(int j = 0; j < t1.GetDimSize(0); j++){
	
      }
    }

    return result;
  }

  TensorDim1 ElementWiseMult(const TensorDim1 &t1, const TensorDim1 &t2){
 
    if(t1.GetDim() != 1 || t2.GetDim() != 1){
      std::cerr << "Can't do the element wise multiplication, sure it is a tensor of same dimensions?" << std::endl;
      exit(1);
    }

    char* resultName;
    strcpy(resultName, t1.GetName());
    strcat(resultName, t2.GetName());
    TensorDim1 nTensor(resultName, t1.GetDimSize(0));

    unsigned int ndim = t1.GetDim();

    for(unsigned int i = 0; i < ndim; i++){
      if(t1.GetDimSize(i) != t2.GetDimSize(i)){
	std::cerr << "Can't do the dot element wise multiplication, sure it is a tensor of same dimensions?" << std::endl;
	exit(1);
      }
      for(unsigned int i = 0; i < t1.GetDimSize(i); i++){
	nTensor(i) = t1(i) * t2(i);
      }
    }
    return nTensor;
  }


  TensorDim2 ElementWiseMult(const TensorDim2 &t1, const TensorDim2 &t2){
 
    if(t1.GetDim() != 2 || t2.GetDim() != 2){
      std::cerr << "Can't do the element wise multiplication, sure it is a tensor of same dimensions?" << std::endl;
      exit(1);
    }
    
    char* resultName;
    strcpy(resultName, t1.GetName());
    strcat(resultName, t2.GetName());
    TensorDim2 nTensor(resultName, t1.GetDimSize(0), t1.GetDimSize(1));

    unsigned int ndim = t1.GetDim();
    unsigned int dims[2] = {0, 0};
    for(unsigned int i = 0; i < ndim; i++){
      if(t1.GetDimSize(i) != t2.GetDimSize(i)){
	std::cerr << "Can't do the dot element wise multiplication, sure it is a tensor of same dimensions?" << std::endl;
	exit(1);
      }
      dims[i] = t1.GetDimSize(i);
    }
    for(unsigned int i = 0; i < dims[0]; i++){
      for(unsigned int j = 0; j < dims[1]; j++){
	nTensor(i,j) = t2(i,j) * t2(i,j);
      }
    }
    return nTensor;
  }


  TensorDim3 ElementWiseMult(const TensorDim3 &t1, const TensorDim3 &t2){
  
    if(t1.GetDim() != 3 || t2.GetDim() != 3){
      std::cerr << "Can't do the element wise multiplication, sure it is a tensor of same dimensions?" << std::endl;
      exit(1);
    }

    char* resultName;
    strcpy(resultName, t1.GetName());
    strcat(resultName, t2.GetName());
    TensorDim3 nTensor(resultName, t1.GetDimSize(0), t1.GetDimSize(1), t1.GetDimSize(2));

    unsigned int ndim = t1.GetDim();
    unsigned int dims[3] = {0, 0, 0};
    for(unsigned int i = 0; i < ndim; i++){
      if(t1.GetDimSize(i) != t2.GetDimSize(i)){
	std::cerr << "Can't do the dot element wise multiplication, sure it is a tensor of same dimensions?" << std::endl;
	exit(1);
      }
      dims[i] = t1.GetDimSize(i);
    }
    for(unsigned int i = 0; i < dims[0]; i++){
      for(unsigned int j = 0; j < dims[1]; j++){
	for(unsigned int k = 0; k < dims[2]; k++){
	  nTensor(i,j,k) = nTensor(i,j,k) * t2(i,j,k);
	}
      }
    }
    return nTensor;
  }


  TensorDim4 ElementWiseMult(const TensorDim4 &t1, const TensorDim4 &t2){

    if(t1.GetDim() != 4 || t2.GetDim() != 4){
      std::cerr << "Can't do the element wise multiplication, sure it is a tensor of same dimensions?" << std::endl;
      exit(1);
    }
    
    char* resultName;
    strcpy(resultName, t1.GetName());
    strcat(resultName, t2.GetName());
    TensorDim4 nTensor(resultName, t1.GetDimSize(0), t1.GetDimSize(1), t1.GetDimSize(2), t1.GetDimSize(3));

    unsigned int ndim = t1.GetDim();
    unsigned int dims[4] = {0, 0, 0, 0};
    for(unsigned int i = 0; i < ndim; i++){
      if(t1.GetDimSize(i) != t2.GetDimSize(i)){
	std::cerr << "Can't do the dot element wise multiplication, sure it is a tensor of same dimensions?" << std::endl;
	exit(1);
      }
      dims[i] = t1.GetDimSize(i);
    }
    for(unsigned int i = 0; i < dims[0]; i++){
      for(unsigned int j = 0; j < dims[1]; j++){
	for(unsigned int k = 0; k < dims[2]; k++){
	  for(unsigned int l = 0; l < dims[3]; l++){
	    nTensor(i,j,k,l) = t1(i,j,k,l) * t2(i,j,k,l);
	  }
	}
      }
    }
    return nTensor;
  }

  TComplex DotProd(const TensorDim1 &t1, const TensorDim1 &t2){
    if(t1.GetDim() != 1 || t2.GetDim() != 1 || t1.GetDimSize(0) != t2.GetDimSize(0)){
      std::cerr << "Can't do the dot product, sure it is a vector of same dimensions?" << std::endl;
      exit(1);
    }
    TensorDim1 result = ElementWiseMult(t1, t2); 
    return result.SumOver();
  }
  
  TensorDim2 SlashDirac(TensorDim1 t){
    if(t.GetDim() != 1 || t.GetDimSize(0) != 4){
      std::cerr << "Can't do dirac slash, vector isn't of dimension 4" << std::endl;
      exit(1);
    }
    
    TensorDim2 result(Form("%sSlashDirac",t.GetName()),4);
    for(int i = 0; i < 4; i++){
      result = result + t(i) * DiracMatrix(i);
    }
    return result;
  }

 
}
