//____________________________________________________________________________
/*

 Author: Pierre Lasorak <p.j.j.lasorak \at qmul.ac.uk>
         Queen Mary University, London

*/
//____________________________________________________________________________

#include <algorithm>
#include "Messenger/Messenger.h"
#include "Conventions/Constants.h"
#include "TMath.h"
#include "TLorentzVector.h"
#include "Tensor.h"
#include "TensorDim1.h"
#include "TensorDim2.h"
#include "TensorDim3.h"
#include "TensorDim4.h"


#include "NuGamma/TensorUtils.h"
#include "Messenger/Messenger.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <complex>

using std::endl;
using namespace genie;
using namespace utils;
using namespace constants;


TensorDim2* TensorUtils::GetIdentityMatrix(){

  if(!TensorUtils::IdentityMatrix){
    TensorDim2 *matrix0;
    matrix0 = (TensorDim2*) TensorUtils::GetZeroMatrix();
    TensorDim2 *matrix = new TensorDim2(*matrix0);
    
    TComplex one(1,0);
    
    for(int i = 0; i < 4; i++)
      (*matrix).Set(i, i, one);
    TensorUtils::IdentityMatrix = matrix;
  }
  return TensorUtils::IdentityMatrix;
}


TensorDim2* TensorUtils::GetZeroMatrix(){

  if(!TensorUtils::ZeroMatrix){
    TensorDim2 *matrix = new TensorDim2(4);
    TComplex zero(0,0);
    
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
	(*matrix)(i,j) = zero;
    TensorUtils::ZeroMatrix = matrix;
  }

  return TensorUtils::ZeroMatrix;

}

TensorDim4* TensorUtils::GetZeroTensorDim4(){

  if(!TensorUtils::ZeroTensorDim4){
    TensorDim4 *tensor = new TensorDim4(4);
    TComplex zero(0,0);
    
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
	for(int k = 0; k < 4; k++)
	  for(int l = 0; l < 4; l++)
	    (*tensor)(i,j,k,l) = zero;
    TensorUtils::ZeroTensorDim4 = tensor;
  }

  return TensorUtils::ZeroTensorDim4;

}

TensorDim2* TensorUtils::GetDiracMatrix(int number){

  if(number == 0){
    if(!TensorUtils::DiracMatrix0){
 
      TensorDim2 *matrix0;
      matrix0 = TensorUtils::GetZeroMatrix();
      TensorDim2 *matrix = new TensorDim2(*matrix0);

      TComplex one     ( 1, 0);
      TComplex minusone(-1, 0);
      TComplex i       ( 0, 1);
      TComplex minusi  ( 0,-1); 
      (*matrix)(0, 0) = one;
      (*matrix)(1, 1) = one;
      (*matrix)(2, 2) = minusone;
      (*matrix)(3, 3) = minusone;
      TensorUtils::DiracMatrix0 = matrix;
    }
    return TensorUtils::DiracMatrix0;
    
  }else if(number == 1){
    if(!TensorUtils::DiracMatrix1){

      TensorDim2 *matrix0;
      matrix0 = TensorUtils::GetZeroMatrix();
      TensorDim2 *matrix = new TensorDim2(*matrix0);

      TComplex one     ( 1, 0);
      TComplex minusone(-1, 0);
      TComplex i       ( 0, 1);
      TComplex minusi  ( 0,-1); 
      (*matrix)(0, 3) = one;
      (*matrix)(1, 2) = one;
      (*matrix)(2, 1) = one;
      (*matrix)(3, 0) = one;
      TensorUtils::DiracMatrix1 = matrix;
    }
    return TensorUtils::DiracMatrix1;

  }else if(number == 2){
    if(!TensorUtils::DiracMatrix2){
 
      TensorDim2 *matrix0;
      matrix0 = TensorUtils::GetZeroMatrix();
      TensorDim2 *matrix = new TensorDim2(*matrix0);

      TComplex one     ( 1, 0);
      TComplex minusone(-1, 0);
      TComplex i       ( 0, 1);
      TComplex minusi  ( 0,-1); 
      (*matrix)(0, 3) = minusi;
      (*matrix)(1, 2) = i;
      (*matrix)(2, 1) = i;
      (*matrix)(3, 0) = minusi;
      TensorUtils::DiracMatrix2 = matrix;
    }
    return TensorUtils::DiracMatrix2;

  }else if(number == 3){
    if(!TensorUtils::DiracMatrix3){
 
      TensorDim2 *matrix0;
      matrix0 = TensorUtils::GetZeroMatrix();
      TensorDim2 *matrix = new TensorDim2(*matrix0);

      TComplex one     ( 1, 0);
      TComplex minusone(-1, 0);
      TComplex i       ( 0, 1);
      TComplex minusi  ( 0,-1); 
      (*matrix)(0, 2) = one;
      (*matrix)(1, 3) = minusone;
      (*matrix)(2, 0) = minusone;
      (*matrix)(3, 1) = one;
      TensorUtils::DiracMatrix3 = matrix;
    }
    return TensorUtils::DiracMatrix3;

  }else if(number == 5){
    if(!TensorUtils::DiracMatrix5){

      TensorDim2 *matrix0;
      matrix0 = TensorUtils::GetZeroMatrix();
      TensorDim2 *matrix = new TensorDim2(*matrix0);
      
      TComplex one     ( 1, 0);
      TComplex minusone(-1, 0);
      TComplex i       ( 0, 1);
      TComplex minusi  ( 0,-1); 
      (*matrix)(0, 2) = one;
      (*matrix)(1, 3) = one;
      (*matrix)(2, 0) = one;
      (*matrix)(3, 1) = one;
      TensorUtils::DiracMatrix5 = matrix;
    }
    return TensorUtils::DiracMatrix5;
  }else
    LOG("TensorUtils", pFATAL) << "not the right Dirac Matrix";
  
  return TensorUtils::GetZeroMatrix();

}


 
TensorDim2* TensorUtils::GetMetric(){
  //TensorDim2* TensorUtils::GetMetric(){

  if(!TensorUtils::Metric){

    TensorDim2 *matrix0;
    matrix0 = TensorUtils::GetZeroMatrix();
    TensorDim2 *matrix = new TensorDim2(*matrix0);
      
    TComplex one     ( 1, 0);
    TComplex minusone(-1, 0);
    (*matrix)(0, 0) = one;
    (*matrix)(1, 1) = minusone;
    (*matrix)(2, 2) = minusone;
    (*matrix)(3, 3) = minusone;
    TensorUtils::Metric = matrix;
  }
  return TensorUtils::Metric;

}


TensorDim2*  TensorUtils::GetDiracTensor(int a, int b){

  TensorDim2* matrixA = new TensorDim2((*TensorUtils::GetDiracMatrix(a)));
  TensorDim2* matrixB = new TensorDim2((*TensorUtils::GetDiracMatrix(b)));
  TensorDim2* matrixAB = new TensorDim2(4);
  TensorDim2* matrixBA = new TensorDim2(4);
  TensorDim2* matrixCom = new TensorDim2(4);
  TensorDim2* matrixSigma = new TensorDim2(4);
  TComplex iOverTwo(0, 0.5);

  (*matrixAB) = (*matrixA) * (*matrixB);
  (*matrixBA) = (*matrixB) * (*matrixA);
  (*matrixCom) = (*matrixAB) - (*matrixBA);
  (*matrixSigma) = iOverTwo * (*matrixCom);
  
  return matrixSigma;

}

TensorDim2* TensorUtils::SlashDirac(const TensorDim1* p){

  TensorDim2* DiracSlached = new TensorDim2(4);

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      (*DiracSlached)(i, j) = 0.;
      for(int n = 0; n < 4; n++){
	(*DiracSlached)(i, j) =  (*p)(n) * (*GetDiracMatrix(n))(i,j)*(*GetMetric())(n,n);
      }
    }
  }
  return DiracSlached;
}




//!********Trace of four matrix multiply***************************************
TensorDim2* TensorUtils::Mult3Matrices(const TensorDim2* Mat1, const TensorDim2* Mat2, const TensorDim2* Mat3){

  TensorDim2* MatTemp  = new TensorDim2(4);
  (*MatTemp)= (*Mat1) * (*Mat2) * (*Mat3);

  return MatTemp;
}      

//!*********Change the dimension of matrix from 3 to 2****************
TensorDim2* TensorUtils::Dim3to2(const TensorDim3* matrix3, const int n){

  TensorDim2* matrix = new TensorDim2(4);

  for(int i = 1; i < 5; i++){
    for(int j = 1; j < 5; j++){
      (*matrix)(i, j) = (*matrix3)(n, i, j);
    }
  }

  return matrix;
}


//!*********Change the dimension of matrix from 4 to 2****************
TensorDim2* TensorUtils::Dim4to2(const TensorDim4* matrix4, const int n1, const int n2){

  TensorDim2*  matrix = new TensorDim2(4);
  for(int i = 1; i < 5; i++){
    for(int j = 1; j < 5; j++){
      (*matrix)(i, j) = (*matrix4)(n1, n2, i, j);
    }
  }
  return matrix;
}



int TensorUtils::LvTen(const int n0, const int n1, const int n2, const int n3){
  
  int arr[4] = {n0, n1, n2, n3};
  
  for(int i = 0; i < 2; i++){
    for(int j = i + 1; j < 4; j++){
      if(arr[i] == arr[j]){
	return 0;
      }
    }
  }

  int num = 0;
  for(int i = 0; i < 3; i++){
    for(int j = i + 1; j < 4; j++){       
      if(arr[i] > arr[j]){
	int ntem = arr[j];
	arr[j] = arr[i];
	arr[i] = ntem;
	num++;
      }
    }
  }

  if(num%2 == 0)
    return 1;
  else
    return -1;

}


//!******************************************************
double TensorUtils::Flam(const double sx, const double sy, const double sz){

  return TMath::Power(sx, 2) + TMath::Power(sy,2) + TMath::Power(sz,2) -2.*(sx*sy + sy*sz + sx*sz);

}

double TensorUtils::SMomentum(const TensorDim1 *sp){
  // use parameter
  // implicit real*8 (a,b,d-h,o-z)
  // implicit complex*16 (c)
  // real*8,dimension(0:3) :: sp

  double smomentum = 0.;
  for(int i = 0; i< 4; i++){
    smomentum = smomentum + (*sp)(i) * (*sp)(i) * (*GetMetric())(i,i);
  }
  
  return smomentum;
}

//*****************************************************
double TensorUtils::FMV(const TensorDim1* xp1, const TensorDim1* xp2){
  // use parameter
  // implicit real*8 (a,b,d-h,o-z)
  // implicit complex*16 (c)
  // real*8,dimension(0:3) :: xp1,xp2

  double FMV = 0.;
  for(int n = 0; n < 4; n++){
    FMV = FMV + (*xp1)(n) * (*xp2)(n) * (*GetMetric())(n,n);
  }
  
  return FMV;
}

// void TensorUtils::FillWithMinus(TensorDim2* in[4][4], TensorDim2* out[4][4]){
//   for(int i1 = 0; i1 < 4; i1++){
//     for(int i2 = 0; i2 < 4; i2++){
//       for(int i3 = 0; i3 < 4; i3++){
// 	for(int i4 = 0; i4 < 4; i4++){
// 	  (*out)[i1][i2][i3][i4] = -(*in)[i1][i2][i3][i4];
// 	}
//       }
//     }
//   }
// }
