#ifndef _TENSORUTILS_H_
#define _TENSORUTILS_H_
#include "TensorUtils/TensorDim.h"

namespace TensorUtils {

  // -----------------------------------------------------
  // Common tensors
  // -----------------------------------------------------

  TensorDim2 LeviCivitaDim2();
  TensorDim3 LeviCivitaDim3();
  TensorDim4 LeviCivitaDim4();

  TensorDim2 MetricDim2();
  TensorDim3 MetricDim3();
  TensorDim4 MetricDim4();

  TensorDim2 UnityDim2();
  TensorDim3 UnityDim3();
  TensorDim4 UnityDim4();

  TensorDim2 DiracMatrix(unsigned int i);
  TensorDim3 DiracTensor(unsigned int a, unsigned int b);
  TensorDim2 MatMult(const TensorDim2 &t1,  const TensorDim2 &t2);
  TensorDim1 MatMult(const TensorDim2 &td2, const TensorDim1 &td1);
  TensorDim2 VecProd(const TensorDim1 &t1, const TensorDim1 &t2);
  TComplex   DotProd(const TensorDim1 &t1, const TensorDim1 &t2);
  
  TensorDim1 ElementWiseMult(const TensorDim1 &t1, const TensorDim1 &t2);
  TensorDim2 ElementWiseMult(const TensorDim2 &t1, const TensorDim2 &t2);
  TensorDim3 ElementWiseMult(const TensorDim3 &t1, const TensorDim3 &t2);
  TensorDim4 ElementWiseMult(const TensorDim4 &t1, const TensorDim4 &t2);
  TComplex   DotProd(const TensorDim1 &t1, const TensorDim1 &t2);
  TensorDim2 CrossProd(const TensorDim1 &t1, const TensorDim1 &t2);
  TensorDim2 SlashDirac(const TensorDim1 t1);
}

#endif
