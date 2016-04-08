#ifndef _TENSORDIM1_H_
#define _TENSORDIM1_H_

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <complex>

#include "Tensor.h"


class TensorDim1: public Tensor{

private:

  bool CheckIndex(const unsigned int i) const;
  unsigned int GetGlobalIndex(const unsigned int i) const;

public:
  using Tensor::operator=;
  TensorDim1(const TensorDim1& t1);
  TensorDim1();
  TensorDim1(int SizeDim, std::string Name = "none");

  TComplex At(const unsigned int i) const;
  void Set(const unsigned int i, TComplex c);
  TComplex& operator()(const unsigned int i);
  TComplex  operator()(const unsigned int i) const;

  friend Tensor Real(const Tensor &t1);
  friend Tensor Imaginary(const Tensor &t1);
  friend Tensor Abs(const Tensor &t1);

  friend Tensor operator+(const int c, const Tensor &t1);
  friend Tensor operator-(const int c, const Tensor &t1);
  friend Tensor operator*(const int c, const Tensor &t1);
  friend Tensor operator/(const int c, const Tensor &t1);

  friend Tensor operator+(const Tensor &t1, const int c);
  friend Tensor operator-(const Tensor &t1, const int c);
  friend Tensor operator*(const Tensor &t1, const int c);
  friend Tensor operator/(const Tensor &t1, const int c);

  friend Tensor operator+(TComplex c, const Tensor &t1);
  friend Tensor operator-(TComplex c, const Tensor &t1);
  friend Tensor operator*(TComplex c, const Tensor &t1);
  friend Tensor operator/(TComplex c, const Tensor &t1);

  friend Tensor operator+(const Tensor &t1, TComplex c);
  friend Tensor operator-(const Tensor &t1, TComplex c);
  friend Tensor operator*(const Tensor &t1, TComplex c);
  friend Tensor operator/(const Tensor &t1, TComplex c);

  friend Tensor operator+(double d, const Tensor &t1);
  friend Tensor operator-(double d, const Tensor &t1);
  friend Tensor operator*(double d, const Tensor &t1);
  friend Tensor operator/(double d, const Tensor &t1);

  friend Tensor operator+(const Tensor &t1, double d);
  friend Tensor operator-(const Tensor &t1, double d);
  friend Tensor operator*(const Tensor &t1, double d);
  friend Tensor operator/(const Tensor &t1, double d);

  friend Tensor operator+(const Tensor &t1, const Tensor &t2);
  friend Tensor operator-(const Tensor &t1, const Tensor &t2);
  friend TComplex operator*(const TensorDim1 &t1, const TensorDim1 &t2);
  friend TComplex DotProd(const TensorDim1 &t1, const TensorDim1 &t2);
  friend Tensor operator/(const Tensor &t1, const Tensor &t2);

  friend bool operator==(const Tensor &t1, const Tensor &t2);
  friend bool operator!=(const Tensor &t1, const Tensor &t2);
  friend bool operator>=(const Tensor &t1, const Tensor &t2); // NEXT are yet to do
  friend bool operator<=(const Tensor &t1, const Tensor &t2); //
  friend bool operator> (const Tensor &t1, const Tensor &t2); //
  friend bool operator< (const Tensor &t1, const Tensor &t2); //

  friend bool operator==(double d, const Tensor &t1); //
  friend bool operator!=(double d, const Tensor &t1); //
  friend bool operator>=(double d, const Tensor &t1); //
  friend bool operator<=(double d, const Tensor &t1); //
  friend bool operator> (double d, const Tensor &t1); //
  friend bool operator< (double d, const Tensor &t1); //

  friend bool operator==(const Tensor &t1, double d); //
  friend bool operator!=(const Tensor &t1, double d); //
  friend bool operator>=(const Tensor &t1, double d); //
  friend bool operator<=(const Tensor &t1, double d); //
  friend bool operator> (const Tensor &t1, double d); //
  friend bool operator< (const Tensor &t1, double d); //

  friend bool operator==(TComplex d, const Tensor &t1); //
  friend bool operator!=(TComplex d, const Tensor &t1); //
  friend bool operator>=(TComplex d, const Tensor &t1); //
  friend bool operator<=(TComplex d, const Tensor &t1); //
  friend bool operator> (TComplex d, const Tensor &t1); //
  friend bool operator< (TComplex d, const Tensor &t1); //

  friend bool operator==(const Tensor &t1, TComplex d); //
  friend bool operator!=(const Tensor &t1, TComplex d); //
  friend bool operator>=(const Tensor &t1, TComplex d); //
  friend bool operator<=(const Tensor &t1, TComplex d); //
  friend bool operator> (const Tensor &t1, TComplex d); //
  friend bool operator< (const Tensor &t1, TComplex d); //

  ClassDef(TensorDim1, 1)
};
 


#endif
