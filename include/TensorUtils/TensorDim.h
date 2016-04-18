#ifndef _TENSORDIM_H_
#define _TENSORDIM_H_

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <complex>

#include "TensorUtils/Tensor.h"

namespace TensorUtils{

  // Some forward declarations
  class TensorDim1;
  class TensorDim2;
  class TensorDim3;
  class TensorDim4;
  
  class TensorDim1: public Tensor{

  private:

    bool         CheckIndex(const unsigned int i) const;
    unsigned int GetGlobalIndex(const unsigned int i) const;

  public:

    //TensorDim1(const Tensor& t1);
    TensorDim1(const TensorDim1& t1);
    TensorDim1(const char * Name = "none", unsigned int SizeDim = 4);

    void Print() const;
    
    TComplex At(const unsigned int i) const;
    void Set(const unsigned int i, TComplex c);
    TComplex& operator()(const unsigned int i);
    TComplex  operator()(const unsigned int i) const;

    using Tensor::operator=;
    using Tensor::SumOver;

    using Tensor::Add;
    using Tensor::Subtract;
    using Tensor::Multiply;
    using Tensor::Divide;

    using Tensor::IsEqual;
    using Tensor::IsDifferent;
    using Tensor::IsBiggerOrEqual;
    using Tensor::IsSmallerOrEqual;
    using Tensor::IsBigger;
    using Tensor::IsSmaller;

    using Tensor::Real;
    using Tensor::Imaginary;
    using Tensor::Abs;
    using Tensor::Minus;
    using Tensor::OneOverElementWise;

    friend TensorDim1 Real(const TensorDim1 &t1);
    friend TensorDim1 Imaginary(const TensorDim1 &t1);
    friend TensorDim1 Abs(const TensorDim1 &t1);

    friend TensorDim1 operator+(const int c, const TensorDim1 &t1);
    friend TensorDim1 operator-(const int c, const TensorDim1 &t1);
    friend TensorDim1 operator*(const int c, const TensorDim1 &t1);
    friend TensorDim1 operator/(const int c, const TensorDim1 &t1);

    friend TensorDim1 operator+(const TensorDim1 &t1, const int c);
    friend TensorDim1 operator-(const TensorDim1 &t1, const int c);
    friend TensorDim1 operator*(const TensorDim1 &t1, const int c);
    friend TensorDim1 operator/(const TensorDim1 &t1, const int c);

    friend TensorDim1 operator+(TComplex c, const TensorDim1 &t1);
    friend TensorDim1 operator-(TComplex c, const TensorDim1 &t1);
    friend TensorDim1 operator*(TComplex c, const TensorDim1 &t1);
    friend TensorDim1 operator/(TComplex c, const TensorDim1 &t1);

    friend TensorDim1 operator+(const TensorDim1 &t1, TComplex c);
    friend TensorDim1 operator-(const TensorDim1 &t1, TComplex c);
    friend TensorDim1 operator*(const TensorDim1 &t1, TComplex c);
    friend TensorDim1 operator/(const TensorDim1 &t1, TComplex c);

    friend TensorDim1 operator+(double d, const TensorDim1 &t1);
    friend TensorDim1 operator-(double d, const TensorDim1 &t1);
    friend TensorDim1 operator*(double d, const TensorDim1 &t1);
    friend TensorDim1 operator/(double d, const TensorDim1 &t1);

    friend TensorDim1 operator+(const TensorDim1 &t1, double d);
    friend TensorDim1 operator-(const TensorDim1 &t1, double d);
    friend TensorDim1 operator*(const TensorDim1 &t1, double d);
    friend TensorDim1 operator/(const TensorDim1 &t1, double d);

    friend TensorDim1 operator+(const TensorDim1 &t1, const TensorDim1 &t2);
    friend TensorDim1 operator-(const TensorDim1 &t1, const TensorDim1 &t2);
    friend TensorDim1 operator*(const TensorDim2 &td2, const TensorDim1 &td1);

    friend bool operator==(const TensorDim1 &t1, const TensorDim1 &t2);
    friend bool operator!=(const TensorDim1 &t1, const TensorDim1 &t2);
    friend bool operator>=(const TensorDim1 &t1, const TensorDim1 &t2);
    friend bool operator<=(const TensorDim1 &t1, const TensorDim1 &t2);
    friend bool operator> (const TensorDim1 &t1, const TensorDim1 &t2);
    friend bool operator< (const TensorDim1 &t1, const TensorDim1 &t2);

    friend bool operator==(double d, const TensorDim1 &t1);
    friend bool operator!=(double d, const TensorDim1 &t1);
    friend bool operator>=(double d, const TensorDim1 &t1);
    friend bool operator<=(double d, const TensorDim1 &t1);
    friend bool operator> (double d, const TensorDim1 &t1);
    friend bool operator< (double d, const TensorDim1 &t1);

    friend bool operator==(const TensorDim1 &t1, double d);
    friend bool operator!=(const TensorDim1 &t1, double d);
    friend bool operator>=(const TensorDim1 &t1, double d);
    friend bool operator<=(const TensorDim1 &t1, double d);
    friend bool operator> (const TensorDim1 &t1, double d);
    friend bool operator< (const TensorDim1 &t1, double d);

    friend bool operator==(TComplex d, const TensorDim1 &t1);
    friend bool operator!=(TComplex d, const TensorDim1 &t1);
    friend bool operator>=(TComplex d, const TensorDim1 &t1);
    friend bool operator<=(TComplex d, const TensorDim1 &t1);
    friend bool operator> (TComplex d, const TensorDim1 &t1);
    friend bool operator< (TComplex d, const TensorDim1 &t1);

    friend bool operator==(const TensorDim1 &t1, TComplex d);
    friend bool operator!=(const TensorDim1 &t1, TComplex d);
    friend bool operator>=(const TensorDim1 &t1, TComplex d);
    friend bool operator<=(const TensorDim1 &t1, TComplex d);
    friend bool operator> (const TensorDim1 &t1, TComplex d);
    friend bool operator< (const TensorDim1 &t1, TComplex d);

  };

  class TensorDim2: public Tensor{
    
  private:

    bool         CheckIndex(const unsigned int i, const unsigned int j) const;
    unsigned int GetGlobalIndex(const unsigned int i, const unsigned int j) const;

  public:

    TensorDim2(const TensorDim2& t1);
    TensorDim2(const char * Name, unsigned int SizeDim1, unsigned int SizeDim2);
    TensorDim2(const char * Name = "none", unsigned int SizeDim = 4);

    void Print() const;
    
    TComplex At(const unsigned int i, const unsigned int j) const;
    void Set(const unsigned int i, const unsigned int j, TComplex c);
    TComplex& operator()(const int i1, const int i2);
    TComplex  operator()(const int i1, const int i2) const;
  
    using Tensor::operator=;
    using Tensor::SumOver;
    using Tensor::Add;
    using Tensor::Subtract;
    using Tensor::Multiply;
    using Tensor::Divide;

    using Tensor::IsEqual;
    using Tensor::IsDifferent;
    using Tensor::IsBiggerOrEqual;
    using Tensor::IsSmallerOrEqual;
    using Tensor::IsBigger;
    using Tensor::IsSmaller;

    using Tensor::Real;
    using Tensor::Imaginary;
    using Tensor::Abs;
    using Tensor::Minus;
    using Tensor::OneOverElementWise;

    friend TensorDim2 Real(const TensorDim2 &t1);
    friend TensorDim2 Imaginary(const TensorDim2 &t1);
    friend TensorDim2 Abs(const TensorDim2 &t1);
      
    friend TensorDim2 operator+(const int c, const TensorDim2 &t1);
    friend TensorDim2 operator-(const int c, const TensorDim2 &t1);
    friend TensorDim2 operator*(const int c, const TensorDim2 &t1);
    friend TensorDim2 operator/(const int c, const TensorDim2 &t1);

    friend TensorDim2 operator+(const TensorDim2 &t1, const int c);
    friend TensorDim2 operator-(const TensorDim2 &t1, const int c);
    friend TensorDim2 operator*(const TensorDim2 &t1, const int c);
    friend TensorDim2 operator/(const TensorDim2 &t1, const int c);

    friend TensorDim2 operator+(TComplex c, const TensorDim2 &t1);
    friend TensorDim2 operator-(TComplex c, const TensorDim2 &t1);
    friend TensorDim2 operator*(TComplex c, const TensorDim2 &t1);
    friend TensorDim2 operator/(TComplex c, const TensorDim2 &t1);

    friend TensorDim2 operator+(const TensorDim2 &t1, TComplex c);
    friend TensorDim2 operator-(const TensorDim2 &t1, TComplex c);
    friend TensorDim2 operator*(const TensorDim2 &t1, TComplex c);
    friend TensorDim2 operator/(const TensorDim2 &t1, TComplex c);

    friend TensorDim2 operator+(double d, const TensorDim2 &t1);
    friend TensorDim2 operator-(double d, const TensorDim2 &t1);
    friend TensorDim2 operator*(double d, const TensorDim2 &t1);
    friend TensorDim2 operator/(double d, const TensorDim2 &t1);

    friend TensorDim2 operator+(const TensorDim2 &t1, double d);
    friend TensorDim2 operator-(const TensorDim2 &t1, double d);
    friend TensorDim2 operator*(const TensorDim2 &t1, double d);
    friend TensorDim2 operator/(const TensorDim2 &t1, double d);

    friend TensorDim2 operator+(const TensorDim2 &t1, const TensorDim2 &t2);
    friend TensorDim2 operator-(const TensorDim2 &t1, const TensorDim2 &t2);
    friend TensorDim2 operator*(const TensorDim2 &t1, const TensorDim2 &t2);
    friend TensorDim1 operator*(const TensorDim2 &t1, const TensorDim1 &t2);

    friend bool operator==(const TensorDim2 &t1, const TensorDim2 &t2);
    friend bool operator!=(const TensorDim2 &t1, const TensorDim2 &t2);
    friend bool operator>=(const TensorDim2 &t1, const TensorDim2 &t2);
    friend bool operator<=(const TensorDim2 &t1, const TensorDim2 &t2);
    friend bool operator> (const TensorDim2 &t1, const TensorDim2 &t2);
    friend bool operator< (const TensorDim2 &t1, const TensorDim2 &t2);

    friend bool operator==(double d, const TensorDim2 &t1);
    friend bool operator!=(double d, const TensorDim2 &t1);
    friend bool operator>=(double d, const TensorDim2 &t1);
    friend bool operator<=(double d, const TensorDim2 &t1);
    friend bool operator> (double d, const TensorDim2 &t1);
    friend bool operator< (double d, const TensorDim2 &t1);

    friend bool operator==(const TensorDim2 &t1, double d);
    friend bool operator!=(const TensorDim2 &t1, double d);
    friend bool operator>=(const TensorDim2 &t1, double d);
    friend bool operator<=(const TensorDim2 &t1, double d);
    friend bool operator> (const TensorDim2 &t1, double d);
    friend bool operator< (const TensorDim2 &t1, double d);

    friend bool operator==(TComplex d, const TensorDim2 &t1);
    friend bool operator!=(TComplex d, const TensorDim2 &t1);
    friend bool operator>=(TComplex d, const TensorDim2 &t1);
    friend bool operator<=(TComplex d, const TensorDim2 &t1);
    friend bool operator> (TComplex d, const TensorDim2 &t1);
    friend bool operator< (TComplex d, const TensorDim2 &t1);

    friend bool operator==(const TensorDim2 &t1, TComplex d);
    friend bool operator!=(const TensorDim2 &t1, TComplex d);
    friend bool operator>=(const TensorDim2 &t1, TComplex d);
    friend bool operator<=(const TensorDim2 &t1, TComplex d);
    friend bool operator> (const TensorDim2 &t1, TComplex d);
    friend bool operator< (const TensorDim2 &t1, TComplex d);
  };



  class TensorDim3: public Tensor{
    
  private:
    
    bool CheckIndex(const unsigned int i, const unsigned int j, const unsigned int k)const;
    unsigned int GetGlobalIndex(const unsigned int i1, const unsigned int i2, const unsigned int i3)const;
  
  public:

    TensorDim3(const TensorDim3& t1);
    TensorDim3(const char * Name, unsigned int SizeDim1, unsigned int SizeDim2, unsigned int SizeDim3);
    TensorDim3(const char * Name = "none", unsigned int SizeDim = 4);
    
    TComplex At(const unsigned int i, const unsigned int j, const unsigned int k)const;
    void Set(const unsigned int i, const unsigned int j, const unsigned int k, TComplex c);
    TComplex& operator()(const unsigned int i1, const unsigned int i2, const unsigned int i3);
    TComplex operator()(const unsigned int i1, const unsigned int i2, const unsigned int i3) const;
    void Print() const;

    using Tensor::operator=;
    using Tensor::SumOver;
    using Tensor::Add;
    using Tensor::Subtract;
    using Tensor::Multiply;
    using Tensor::Divide;

    using Tensor::IsEqual;
    using Tensor::IsDifferent;
    using Tensor::IsBiggerOrEqual;
    using Tensor::IsSmallerOrEqual;
    using Tensor::IsBigger;
    using Tensor::IsSmaller;

    using Tensor::Real;
    using Tensor::Imaginary;
    using Tensor::Abs;
    using Tensor::Minus;
    using Tensor::OneOverElementWise;
    
    friend TensorDim3 Real(const TensorDim3 &t1);
    friend TensorDim3 Imaginary(const TensorDim3 &t1);
    friend TensorDim3 Abs(const TensorDim3 &t1);

    friend TensorDim3 operator+(const int c, const TensorDim3 &t1);
    friend TensorDim3 operator-(const int c, const TensorDim3 &t1);
    friend TensorDim3 operator*(const int c, const TensorDim3 &t1);
    friend TensorDim3 operator/(const int c, const TensorDim3 &t1);

    friend TensorDim3 operator+(const TensorDim3 &t1, const int c);
    friend TensorDim3 operator-(const TensorDim3 &t1, const int c);
    friend TensorDim3 operator*(const TensorDim3 &t1, const int c);
    friend TensorDim3 operator/(const TensorDim3 &t1, const int c);

    friend TensorDim3 operator+(TComplex c, const TensorDim3 &t1);
    friend TensorDim3 operator-(TComplex c, const TensorDim3 &t1);
    friend TensorDim3 operator*(TComplex c, const TensorDim3 &t1);
    friend TensorDim3 operator/(TComplex c, const TensorDim3 &t1);

    friend TensorDim3 operator+(const TensorDim3 &t1, TComplex c);
    friend TensorDim3 operator-(const TensorDim3 &t1, TComplex c);
    friend TensorDim3 operator*(const TensorDim3 &t1, TComplex c);
    friend TensorDim3 operator/(const TensorDim3 &t1, TComplex c);

    friend TensorDim3 operator+(double d, const TensorDim3 &t1);
    friend TensorDim3 operator-(double d, const TensorDim3 &t1);
    friend TensorDim3 operator*(double d, const TensorDim3 &t1);
    friend TensorDim3 operator/(double d, const TensorDim3 &t1);

    friend TensorDim3 operator+(const TensorDim3 &t1, double d);
    friend TensorDim3 operator-(const TensorDim3 &t1, double d);
    friend TensorDim3 operator*(const TensorDim3 &t1, double d);
    friend TensorDim3 operator/(const TensorDim3 &t1, double d);

    friend TensorDim3 operator+(const TensorDim3 &t1, const TensorDim3 &t2);
    friend TensorDim3 operator-(const TensorDim3 &t1, const TensorDim3 &t2);

    friend bool operator==(const TensorDim3 &t1, const TensorDim3 &t2);
    friend bool operator!=(const TensorDim3 &t1, const TensorDim3 &t2);
    friend bool operator>=(const TensorDim3 &t1, const TensorDim3 &t2);
    friend bool operator<=(const TensorDim3 &t1, const TensorDim3 &t2);
    friend bool operator> (const TensorDim3 &t1, const TensorDim3 &t2);
    friend bool operator< (const TensorDim3 &t1, const TensorDim3 &t2);

    friend bool operator==(double d, const TensorDim3 &t1);
    friend bool operator!=(double d, const TensorDim3 &t1);
    friend bool operator>=(double d, const TensorDim3 &t1);
    friend bool operator<=(double d, const TensorDim3 &t1);
    friend bool operator> (double d, const TensorDim3 &t1);
    friend bool operator< (double d, const TensorDim3 &t1);

    friend bool operator==(const TensorDim3 &t1, double d);
    friend bool operator!=(const TensorDim3 &t1, double d);
    friend bool operator>=(const TensorDim3 &t1, double d);
    friend bool operator<=(const TensorDim3 &t1, double d);
    friend bool operator> (const TensorDim3 &t1, double d);
    friend bool operator< (const TensorDim3 &t1, double d);

    friend bool operator==(TComplex d, const TensorDim3 &t1);
    friend bool operator!=(TComplex d, const TensorDim3 &t1);
    friend bool operator>=(TComplex d, const TensorDim3 &t1);
    friend bool operator<=(TComplex d, const TensorDim3 &t1);
    friend bool operator> (TComplex d, const TensorDim3 &t1);
    friend bool operator< (TComplex d, const TensorDim3 &t1);

    friend bool operator==(const TensorDim3 &t1, TComplex d);
    friend bool operator!=(const TensorDim3 &t1, TComplex d);
    friend bool operator>=(const TensorDim3 &t1, TComplex d);
    friend bool operator<=(const TensorDim3 &t1, TComplex d);
    friend bool operator> (const TensorDim3 &t1, TComplex d);
    friend bool operator< (const TensorDim3 &t1, TComplex d);
 
  };


  class TensorDim4: public Tensor{
    
  private:

    bool CheckIndex(const unsigned int i, const unsigned int j, const unsigned int k, const unsigned int l) const;
    unsigned int GetGlobalIndex(const unsigned int i1, const unsigned int i2, const unsigned int i3, const unsigned int i4) const;

  public:
    TensorDim4(const TensorDim4& t1);
    TensorDim4(const char * Name, unsigned int SizeDim1, unsigned int SizeDim2, unsigned int SizeDim3, unsigned int SizeDim4);
    TensorDim4(const char * Name = "none", unsigned int SizeDim = 4);
    TComplex At(const unsigned int i, const unsigned int j, const unsigned int k, const unsigned int l) const;
    void Set(int i, int j, int k, int l, TComplex c);
    TComplex& operator()(const unsigned int i1, const unsigned int i2, const unsigned int i3, const unsigned int i4);
    TComplex operator()(const unsigned int i1, const unsigned int i2, const unsigned int i3, const unsigned int i4) const;
    void Print() const;
  
    using Tensor::operator=;
    using Tensor::SumOver;
    using Tensor::Add;
    using Tensor::Subtract;
    using Tensor::Multiply;
    using Tensor::Divide;

    using Tensor::IsEqual;
    using Tensor::IsDifferent;
    using Tensor::IsBiggerOrEqual;
    using Tensor::IsSmallerOrEqual;
    using Tensor::IsBigger;
    using Tensor::IsSmaller;

    using Tensor::Real;
    using Tensor::Imaginary;
    using Tensor::Abs;
    using Tensor::Minus;
    using Tensor::OneOverElementWise;

    friend TensorDim4 Real(const TensorDim4 &t1);
    friend TensorDim4 Imaginary(const TensorDim4 &t1);
    friend TensorDim4 Abs(const TensorDim4 &t1);

    friend TensorDim4 operator+(const int c, const TensorDim4 &t1);
    friend TensorDim4 operator-(const int c, const TensorDim4 &t1);
    friend TensorDim4 operator*(const int c, const TensorDim4 &t1);
    friend TensorDim4 operator/(const int c, const TensorDim4 &t1);

    friend TensorDim4 operator+(const TensorDim4 &t1, const int c);
    friend TensorDim4 operator-(const TensorDim4 &t1, const int c);
    friend TensorDim4 operator*(const TensorDim4 &t1, const int c);
    friend TensorDim4 operator/(const TensorDim4 &t1, const int c);

    friend TensorDim4 operator+(TComplex c, const TensorDim4 &t1);
    friend TensorDim4 operator-(TComplex c, const TensorDim4 &t1);
    friend TensorDim4 operator*(TComplex c, const TensorDim4 &t1);
    friend TensorDim4 operator/(TComplex c, const TensorDim4 &t1);

    friend TensorDim4 operator+(const TensorDim4 &t1, TComplex c);
    friend TensorDim4 operator-(const TensorDim4 &t1, TComplex c);
    friend TensorDim4 operator*(const TensorDim4 &t1, TComplex c);
    friend TensorDim4 operator/(const TensorDim4 &t1, TComplex c);

    friend TensorDim4 operator+(double d, const TensorDim4 &t1);
    friend TensorDim4 operator-(double d, const TensorDim4 &t1);
    friend TensorDim4 operator*(double d, const TensorDim4 &t1);
    friend TensorDim4 operator/(double d, const TensorDim4 &t1);

    friend TensorDim4 operator+(const TensorDim4 &t1, double d);
    friend TensorDim4 operator-(const TensorDim4 &t1, double d);
    friend TensorDim4 operator*(const TensorDim4 &t1, double d);
    friend TensorDim4 operator/(const TensorDim4 &t1, double d);

    friend TensorDim4 operator+(const TensorDim4 &t1, const TensorDim4 &t2);
    friend TensorDim4 operator-(const TensorDim4 &t1, const TensorDim4 &t2);

    friend bool operator==(const TensorDim4 &t1, const TensorDim4 &t2);
    friend bool operator!=(const TensorDim4 &t1, const TensorDim4 &t2);
    friend bool operator>=(const TensorDim4 &t1, const TensorDim4 &t2);
    friend bool operator<=(const TensorDim4 &t1, const TensorDim4 &t2);
    friend bool operator> (const TensorDim4 &t1, const TensorDim4 &t2);
    friend bool operator< (const TensorDim4 &t1, const TensorDim4 &t2);

    friend bool operator==(double d, const TensorDim4 &t1);
    friend bool operator!=(double d, const TensorDim4 &t1);
    friend bool operator>=(double d, const TensorDim4 &t1);
    friend bool operator<=(double d, const TensorDim4 &t1);
    friend bool operator> (double d, const TensorDim4 &t1);
    friend bool operator< (double d, const TensorDim4 &t1);

    friend bool operator==(const TensorDim4 &t1, double d);
    friend bool operator!=(const TensorDim4 &t1, double d);
    friend bool operator>=(const TensorDim4 &t1, double d);
    friend bool operator<=(const TensorDim4 &t1, double d);
    friend bool operator> (const TensorDim4 &t1, double d);
    friend bool operator< (const TensorDim4 &t1, double d);

    friend bool operator==(TComplex d, const TensorDim4 &t1);
    friend bool operator!=(TComplex d, const TensorDim4 &t1);
    friend bool operator>=(TComplex d, const TensorDim4 &t1);
    friend bool operator<=(TComplex d, const TensorDim4 &t1);
    friend bool operator> (TComplex d, const TensorDim4 &t1);
    friend bool operator< (TComplex d, const TensorDim4 &t1);

    friend bool operator==(const TensorDim4 &t1, TComplex d);
    friend bool operator!=(const TensorDim4 &t1, TComplex d);
    friend bool operator>=(const TensorDim4 &t1, TComplex d);
    friend bool operator<=(const TensorDim4 &t1, TComplex d);
    friend bool operator> (const TensorDim4 &t1, TComplex d);
    friend bool operator< (const TensorDim4 &t1, TComplex d);

  };

} 


#endif 
