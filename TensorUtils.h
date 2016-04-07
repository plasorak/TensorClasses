//____________________________________________________________________________
/*

\namespace TensorUtils

\brief     Valencia group's utilities

\author    Pierre Lasorak <p.j.j.lasorak \at qmul.ac.uk>
           Queen Mary University, London

\created   November 25, 2015

\cpright   Copyright (c) 2003-2015, GENIE Neutrino MC Generator Collaboration
           For the full text of the license visit http://copyright.genie-mc.org
           or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _TENSORUTILS_H_
#define _TENSORUTILS_H_


#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <complex>
#include <vector>
#include "NuGamma/TensorDim1.h"
#include "NuGamma/TensorDim2.h"
#include "NuGamma/TensorDim3.h"
#include "NuGamma/TensorDim4.h"

#include <TVector3.h>
#include <TMath.h>
#include <TComplex.h>
#include <Math/SMatrix.h>
#include <Math/SVector.h>
#include "TLorentzVector.h"

#include "BaryonResonance/BaryonResonance.h"

namespace genie {
  namespace utils {
    namespace TensorUtils{
    
      TensorDim2* GetIdentityMatrix(void);
      TensorDim2* GetZeroMatrix    (void);
      TensorDim2* GetDiracMatrix   (int i);
      TensorDim2* GetMetric        (void);
      TensorDim2* GetDiracTensor   (int a, int b);
      TensorDim2* SlashDirac       (const TensorDim1* p);
      TensorDim4* GetZeroTensorDim4(void);
    
      extern TensorDim2 *IdentityMatrix;
      extern TensorDim2 *ZeroMatrix;
      extern TensorDim2 *DiracMatrix0;
      extern TensorDim2 *DiracMatrix1;
      extern TensorDim2 *DiracMatrix2;
      extern TensorDim2 *DiracMatrix3;
      extern TensorDim2 *DiracMatrix5;
      extern TensorDim2 *Metric;
      extern TensorDim4 *ZeroTensorDim4;

      int LvTen(const int n0, const int n1, const int n2, const int n3);
      double Flam(const double sx, const double sy, const double sz);
      double SMomentum(const TensorDim1 * sp);
      // void FillWithMinus(const TensorDim4* in, const TensorDim4* out);
      TensorDim2* Dim4to2(const TensorDim4* cmatrix4, const int n1, const int n2);
      TensorDim2* Dim3to2(const TensorDim3* cmatrix3, const int n);
      TensorDim2* Mult3Matrices(const TensorDim2* Mat1, const TensorDim2* Mat2, const TensorDim2* Mat3);
      double Mult2(const TensorDim2* Mat1, const TensorDim4* Mat2, const TensorDim2* Mat3, const TensorDim4* Mat4, const int nAlpha, const int nBeta);
      double FMV(const TensorDim1* xp1, const TensorDim1* xp2);
      TensorDim4* Conj(TensorDim4* cAC_em);
    }
  }


};
  

#endif

