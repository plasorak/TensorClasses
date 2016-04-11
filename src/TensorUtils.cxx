

#include "TensorUtils/Tensor.h"
#include "TensorUtils/TensorDim1.h"
#include "TensorUtils/TensorDim2.h"
#include "TensorUtils/TensorDim3.h"
#include "TensorUtils/TensorDim4.h"
#include "TensorUtils/TensorUtils.h"

using namespace TensorUtils;

// -----------------------------------------------------
// Common tensors
// -----------------------------------------------------

TensorDim2 LeviCivitaDim2(){
  TensorDim2 t(4);
  return t;
};

TensorDim3 LeviCivitaDim3(){
  TensorDim3 t(4);
  return t;
};

TensorDim4 LeviCivitaDim4(){
  TensorDim4 t(4);
  return t;
};

TensorDim2 MetricDim2(){
  TensorDim2 t(4);
  return t;
};

TensorDim3 MetricDim3(){
  TensorDim3 t(4);
  return t;
};

TensorDim4 MetricDim4(){
  TensorDim4 t(4);
  return t;
};

TensorDim2 UnityDim2(){
  TensorDim2 t(4);
  return t;
};

TensorDim3 UnityDim3(){
  TensorDim3 t(4);
  return t;
};

TensorDim4 UnityDim4(){
  TensorDim4 t(4);
  return t;
};

TensorDim2 DiracMatrix(unsigned int i){
  TensorDim2 t(4);
  return t;
};
  
TensorDim3 DiracTensor(unsigned int a, unsigned int b){
  TensorDim3 t(4);
  return t;
};

TensorDim2 MatMult(const TensorDim2 &t1,  const TensorDim2 &t2){
  TensorDim2 t(4);
  return t;
};
    
TensorDim1 MatMult(const TensorDim2 &td2, const TensorDim1 &td1){
  TensorDim1 t(4);
  return t;
};
    
TensorDim2 VecProd(const TensorDim1 &t1, const TensorDim1 &t2){
  TensorDim2 t(4);
  return t;
};
    
TComplex DotProd(const TensorDim1 &t1, const TensorDim1 &t2){
  return t1*t2;
};

TensorDim2 SlashDirac(){
  TensorDim2 t(4);
  return t;
};
