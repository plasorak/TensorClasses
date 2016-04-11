#ifndef _TENSORDIM4_H_
#define _TENSORDIM4_H_

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <complex>

#include "TensorUtils/Tensor.h"
namespace TensorUtils{
class TensorDim4: public Tensor{
    
private:

  bool CheckIndex(const unsigned int i, const unsigned int j, const unsigned int k, const unsigned int l) const;
  unsigned int GetGlobalIndex(const unsigned int i1, const unsigned int i2, const unsigned int i3, const unsigned int i4) const;

public:

  TensorDim4(int SizeDim1, int SizeDim2, int SizeDim3, int SizeDim4, std::string Name = "none");
  TensorDim4(int SizeDim = 4, std::string Name = "none");
  TComplex At(const unsigned int i, const unsigned int j, const unsigned int k, const unsigned int l) const;
  void Set(int i, int j, int k, int l, TComplex c);
  TComplex& operator()(const unsigned int i1, const unsigned int i2, const unsigned int i3, const unsigned int i4);
  TComplex operator()(const unsigned int i1, const unsigned int i2, const unsigned int i3, const unsigned int i4) const;
  TensorDim4(const TensorDim4& t1);

  using Tensor::operator=;

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
  friend Tensor operator*(const Tensor &t1, const Tensor &t2);
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

};
}
#endif
