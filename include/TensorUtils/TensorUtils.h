#ifndef _TENSORUTILS_H_
#define _TENSORUTILS_H_
#include "TensorUtils/TensorDim1.h"
// #include "TensorUtils/TensorDim2.h"
// #include "TensorUtils/TensorDim3.h"
// #include "TensorUtils/TensorDim4.h"


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
  TensorDim2 SlashDirac();

}

#endif
