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

    bool CheckIndex(const int i) const;
    int  GetGlobalIndex(const int i) const;

  public:

    //TensorDim1(const Tensor& t1);
    TensorDim1(const TensorDim1& t1);
    TensorDim1(const char * Name = "none", int SizeDim = 4);

    void Print() const;
    
    TComplex At(const int i) const;
    void Set(const int i, TComplex c);
    TComplex& operator()(const int i);
    TComplex  operator()(const int i) const;

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
    using Tensor::MultiplyElementWise;
    using Tensor::DivideElementWise;
 
    using Tensor::AssertGoodDim;
    using Tensor::GoodDim;

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

    bool         CheckIndex(const int i, const int j) const;
    int GetGlobalIndex(const int i, const int j) const;

  public:

    TensorDim2(const TensorDim2& t1);
    TensorDim2(const char * Name, int SizeDim1, int SizeDim2);
    TensorDim2(const char * Name = "none", int SizeDim = 4);

    void Print() const;
    
    TComplex At(const int i, const int j) const;
    void Set(const int i, const int j, TComplex c);
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
    using Tensor::MultiplyElementWise;
    using Tensor::DivideElementWise;

    using Tensor::AssertGoodDim;
    using Tensor::GoodDim;

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
    
    bool CheckIndex(const int i, const int j, const int k)const;
    int GetGlobalIndex(const int i1, const int i2, const int i3)const;
  
  public:

    TensorDim3(const TensorDim3& t1);
    TensorDim3(const char * Name, int SizeDim1, int SizeDim2, int SizeDim3);
    TensorDim3(const char * Name = "none", int SizeDim = 4);
    
    TComplex At(const int i, const int j, const int k)const;
    void Set(const int i, const int j, const int k, TComplex c);
    TComplex& operator()(const int i1, const int i2, const int i3);
    TComplex operator()(const int i1, const int i2, const int i3) const;
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
    using Tensor::MultiplyElementWise;
    using Tensor::DivideElementWise;

    using Tensor::AssertGoodDim;
    using Tensor::GoodDim;

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

    bool CheckIndex(const int i, const int j, const int k, const int l) const;
    int GetGlobalIndex(const int i1, const int i2, const int i3, const int i4) const;

  public:
    TensorDim4(const TensorDim4& t1);
    TensorDim4(const char * Name, int SizeDim1, int SizeDim2, int SizeDim3, int SizeDim4);
    TensorDim4(const char * Name = "none", int SizeDim = 4);
    TComplex At(const int i, const int j, const int k, const int l) const;
    void Set(int i, int j, int k, int l, TComplex c);
    TComplex& operator()(const int i1, const int i2, const int i3, const int i4);
    TComplex  operator()(const int i1, const int i2, const int i3, const int i4) const;
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
    using Tensor::MultiplyElementWise;
    using Tensor::DivideElementWise;

    using Tensor::AssertGoodDim;
    using Tensor::GoodDim;

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
