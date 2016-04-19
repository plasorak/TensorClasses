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

  TensorDim2 Metric();

  TensorDim2 UnityDim2(int i = 4);
  TensorDim3 UnityDim3(int i = 4);
  TensorDim4 UnityDim4(int i = 4);

  TensorDim2 DiracMatrix(int i);
  TensorDim3 DiracTensor(int a, int b);
  TComplex   DotProd(const TensorDim1 &t1, const TensorDim1 &t2);
  TComplex   DotProdMetric(const TensorDim1 &t1, const TensorDim1 &t2);

  TensorDim1 CrossProd(const TensorDim1 &t1, const TensorDim1 &t2);
  TensorDim2 SlashDirac(const TensorDim1 &t1);
}

#endif
