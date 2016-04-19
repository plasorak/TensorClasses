#ifndef _TENSORORDER_H_
#define _TENSORORDER_H_

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <complex>

#include "TensorUtils/Tensor.h"

namespace TensorUtils{

  // Some forward declarations
  class TensorOrder1;
  class TensorOrder2;
  class TensorOrder3;
  class TensorOrder4;
  
  class TensorOrder1: public Tensor{

  private:

    bool CheckIndex(const int i) const;
    int  GetGlobalIndex(const int i) const;

  public:

    //TensorOrder1(const Tensor& t1);
    TensorOrder1(const TensorOrder1& t1);
    TensorOrder1(const char * Name = "none", int Dim = 4);

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
 
    using Tensor::AssertGoodSize;
    using Tensor::GoodSize;

    friend TensorOrder1 Real(const TensorOrder1 &t1);
    friend TensorOrder1 Imaginary(const TensorOrder1 &t1);
    friend TensorOrder1 Abs(const TensorOrder1 &t1);

    friend TensorOrder1 operator+(const int c, const TensorOrder1 &t1);
    friend TensorOrder1 operator-(const int c, const TensorOrder1 &t1);
    friend TensorOrder1 operator*(const int c, const TensorOrder1 &t1);
    friend TensorOrder1 operator/(const int c, const TensorOrder1 &t1);

    friend TensorOrder1 operator+(const TensorOrder1 &t1, const int c);
    friend TensorOrder1 operator-(const TensorOrder1 &t1, const int c);
    friend TensorOrder1 operator*(const TensorOrder1 &t1, const int c);
    friend TensorOrder1 operator/(const TensorOrder1 &t1, const int c);

    friend TensorOrder1 operator+(TComplex c, const TensorOrder1 &t1);
    friend TensorOrder1 operator-(TComplex c, const TensorOrder1 &t1);
    friend TensorOrder1 operator*(TComplex c, const TensorOrder1 &t1);
    friend TensorOrder1 operator/(TComplex c, const TensorOrder1 &t1);

    friend TensorOrder1 operator+(const TensorOrder1 &t1, TComplex c);
    friend TensorOrder1 operator-(const TensorOrder1 &t1, TComplex c);
    friend TensorOrder1 operator*(const TensorOrder1 &t1, TComplex c);
    friend TensorOrder1 operator/(const TensorOrder1 &t1, TComplex c);

    friend TensorOrder1 operator+(double d, const TensorOrder1 &t1);
    friend TensorOrder1 operator-(double d, const TensorOrder1 &t1);
    friend TensorOrder1 operator*(double d, const TensorOrder1 &t1);
    friend TensorOrder1 operator/(double d, const TensorOrder1 &t1);

    friend TensorOrder1 operator+(const TensorOrder1 &t1, double d);
    friend TensorOrder1 operator-(const TensorOrder1 &t1, double d);
    friend TensorOrder1 operator*(const TensorOrder1 &t1, double d);
    friend TensorOrder1 operator/(const TensorOrder1 &t1, double d);

    friend TensorOrder1 operator+(const TensorOrder1 &t1, const TensorOrder1 &t2);
    friend TensorOrder1 operator-(const TensorOrder1 &t1, const TensorOrder1 &t2);
    friend TensorOrder1 operator*(const TensorOrder2 &td2, const TensorOrder1 &td1);

    friend bool operator==(const TensorOrder1 &t1, const TensorOrder1 &t2);
    friend bool operator!=(const TensorOrder1 &t1, const TensorOrder1 &t2);
    friend bool operator>=(const TensorOrder1 &t1, const TensorOrder1 &t2);
    friend bool operator<=(const TensorOrder1 &t1, const TensorOrder1 &t2);
    friend bool operator> (const TensorOrder1 &t1, const TensorOrder1 &t2);
    friend bool operator< (const TensorOrder1 &t1, const TensorOrder1 &t2);

    friend bool operator==(double d, const TensorOrder1 &t1);
    friend bool operator!=(double d, const TensorOrder1 &t1);
    friend bool operator>=(double d, const TensorOrder1 &t1);
    friend bool operator<=(double d, const TensorOrder1 &t1);
    friend bool operator> (double d, const TensorOrder1 &t1);
    friend bool operator< (double d, const TensorOrder1 &t1);

    friend bool operator==(const TensorOrder1 &t1, double d);
    friend bool operator!=(const TensorOrder1 &t1, double d);
    friend bool operator>=(const TensorOrder1 &t1, double d);
    friend bool operator<=(const TensorOrder1 &t1, double d);
    friend bool operator> (const TensorOrder1 &t1, double d);
    friend bool operator< (const TensorOrder1 &t1, double d);

    friend bool operator==(TComplex d, const TensorOrder1 &t1);
    friend bool operator!=(TComplex d, const TensorOrder1 &t1);
    friend bool operator>=(TComplex d, const TensorOrder1 &t1);
    friend bool operator<=(TComplex d, const TensorOrder1 &t1);
    friend bool operator> (TComplex d, const TensorOrder1 &t1);
    friend bool operator< (TComplex d, const TensorOrder1 &t1);

    friend bool operator==(const TensorOrder1 &t1, TComplex d);
    friend bool operator!=(const TensorOrder1 &t1, TComplex d);
    friend bool operator>=(const TensorOrder1 &t1, TComplex d);
    friend bool operator<=(const TensorOrder1 &t1, TComplex d);
    friend bool operator> (const TensorOrder1 &t1, TComplex d);
    friend bool operator< (const TensorOrder1 &t1, TComplex d);

  };

  class TensorOrder2: public Tensor{
    
  private:

    bool         CheckIndex(const int i, const int j) const;
    int GetGlobalIndex(const int i, const int j) const;

  public:

    TensorOrder2(const TensorOrder2& t1);
    TensorOrder2(const char * Name, int Dim1, int Dim2);
    TensorOrder2(const char * Name = "none", int Dim = 4);

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

    using Tensor::AssertGoodSize;
    using Tensor::GoodSize;

    friend TensorOrder2 Real(const TensorOrder2 &t1);
    friend TensorOrder2 Imaginary(const TensorOrder2 &t1);
    friend TensorOrder2 Abs(const TensorOrder2 &t1);
      
    friend TensorOrder2 operator+(const int c, const TensorOrder2 &t1);
    friend TensorOrder2 operator-(const int c, const TensorOrder2 &t1);
    friend TensorOrder2 operator*(const int c, const TensorOrder2 &t1);
    friend TensorOrder2 operator/(const int c, const TensorOrder2 &t1);

    friend TensorOrder2 operator+(const TensorOrder2 &t1, const int c);
    friend TensorOrder2 operator-(const TensorOrder2 &t1, const int c);
    friend TensorOrder2 operator*(const TensorOrder2 &t1, const int c);
    friend TensorOrder2 operator/(const TensorOrder2 &t1, const int c);

    friend TensorOrder2 operator+(TComplex c, const TensorOrder2 &t1);
    friend TensorOrder2 operator-(TComplex c, const TensorOrder2 &t1);
    friend TensorOrder2 operator*(TComplex c, const TensorOrder2 &t1);
    friend TensorOrder2 operator/(TComplex c, const TensorOrder2 &t1);

    friend TensorOrder2 operator+(const TensorOrder2 &t1, TComplex c);
    friend TensorOrder2 operator-(const TensorOrder2 &t1, TComplex c);
    friend TensorOrder2 operator*(const TensorOrder2 &t1, TComplex c);
    friend TensorOrder2 operator/(const TensorOrder2 &t1, TComplex c);

    friend TensorOrder2 operator+(double d, const TensorOrder2 &t1);
    friend TensorOrder2 operator-(double d, const TensorOrder2 &t1);
    friend TensorOrder2 operator*(double d, const TensorOrder2 &t1);
    friend TensorOrder2 operator/(double d, const TensorOrder2 &t1);

    friend TensorOrder2 operator+(const TensorOrder2 &t1, double d);
    friend TensorOrder2 operator-(const TensorOrder2 &t1, double d);
    friend TensorOrder2 operator*(const TensorOrder2 &t1, double d);
    friend TensorOrder2 operator/(const TensorOrder2 &t1, double d);

    friend TensorOrder2 operator+(const TensorOrder2 &t1, const TensorOrder2 &t2);
    friend TensorOrder2 operator-(const TensorOrder2 &t1, const TensorOrder2 &t2);
    friend TensorOrder2 operator*(const TensorOrder2 &t1, const TensorOrder2 &t2);
    friend TensorOrder1 operator*(const TensorOrder2 &t1, const TensorOrder1 &t2);

    friend bool operator==(const TensorOrder2 &t1, const TensorOrder2 &t2);
    friend bool operator!=(const TensorOrder2 &t1, const TensorOrder2 &t2);
    friend bool operator>=(const TensorOrder2 &t1, const TensorOrder2 &t2);
    friend bool operator<=(const TensorOrder2 &t1, const TensorOrder2 &t2);
    friend bool operator> (const TensorOrder2 &t1, const TensorOrder2 &t2);
    friend bool operator< (const TensorOrder2 &t1, const TensorOrder2 &t2);

    friend bool operator==(double d, const TensorOrder2 &t1);
    friend bool operator!=(double d, const TensorOrder2 &t1);
    friend bool operator>=(double d, const TensorOrder2 &t1);
    friend bool operator<=(double d, const TensorOrder2 &t1);
    friend bool operator> (double d, const TensorOrder2 &t1);
    friend bool operator< (double d, const TensorOrder2 &t1);

    friend bool operator==(const TensorOrder2 &t1, double d);
    friend bool operator!=(const TensorOrder2 &t1, double d);
    friend bool operator>=(const TensorOrder2 &t1, double d);
    friend bool operator<=(const TensorOrder2 &t1, double d);
    friend bool operator> (const TensorOrder2 &t1, double d);
    friend bool operator< (const TensorOrder2 &t1, double d);

    friend bool operator==(TComplex d, const TensorOrder2 &t1);
    friend bool operator!=(TComplex d, const TensorOrder2 &t1);
    friend bool operator>=(TComplex d, const TensorOrder2 &t1);
    friend bool operator<=(TComplex d, const TensorOrder2 &t1);
    friend bool operator> (TComplex d, const TensorOrder2 &t1);
    friend bool operator< (TComplex d, const TensorOrder2 &t1);

    friend bool operator==(const TensorOrder2 &t1, TComplex d);
    friend bool operator!=(const TensorOrder2 &t1, TComplex d);
    friend bool operator>=(const TensorOrder2 &t1, TComplex d);
    friend bool operator<=(const TensorOrder2 &t1, TComplex d);
    friend bool operator> (const TensorOrder2 &t1, TComplex d);
    friend bool operator< (const TensorOrder2 &t1, TComplex d);
  };



  class TensorOrder3: public Tensor{
    
  private:
    
    bool CheckIndex(const int i, const int j, const int k)const;
    int GetGlobalIndex(const int i1, const int i2, const int i3)const;
  
  public:

    TensorOrder3(const TensorOrder3& t1);
    TensorOrder3(const char * Name, int Dim1, int Dim2, int Dim3);
    TensorOrder3(const char * Name = "none", int Dim = 4);
    
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

    using Tensor::AssertGoodSize;
    using Tensor::GoodSize;

    friend TensorOrder3 Real(const TensorOrder3 &t1);
    friend TensorOrder3 Imaginary(const TensorOrder3 &t1);
    friend TensorOrder3 Abs(const TensorOrder3 &t1);

    friend TensorOrder3 operator+(const int c, const TensorOrder3 &t1);
    friend TensorOrder3 operator-(const int c, const TensorOrder3 &t1);
    friend TensorOrder3 operator*(const int c, const TensorOrder3 &t1);
    friend TensorOrder3 operator/(const int c, const TensorOrder3 &t1);

    friend TensorOrder3 operator+(const TensorOrder3 &t1, const int c);
    friend TensorOrder3 operator-(const TensorOrder3 &t1, const int c);
    friend TensorOrder3 operator*(const TensorOrder3 &t1, const int c);
    friend TensorOrder3 operator/(const TensorOrder3 &t1, const int c);

    friend TensorOrder3 operator+(TComplex c, const TensorOrder3 &t1);
    friend TensorOrder3 operator-(TComplex c, const TensorOrder3 &t1);
    friend TensorOrder3 operator*(TComplex c, const TensorOrder3 &t1);
    friend TensorOrder3 operator/(TComplex c, const TensorOrder3 &t1);

    friend TensorOrder3 operator+(const TensorOrder3 &t1, TComplex c);
    friend TensorOrder3 operator-(const TensorOrder3 &t1, TComplex c);
    friend TensorOrder3 operator*(const TensorOrder3 &t1, TComplex c);
    friend TensorOrder3 operator/(const TensorOrder3 &t1, TComplex c);

    friend TensorOrder3 operator+(double d, const TensorOrder3 &t1);
    friend TensorOrder3 operator-(double d, const TensorOrder3 &t1);
    friend TensorOrder3 operator*(double d, const TensorOrder3 &t1);
    friend TensorOrder3 operator/(double d, const TensorOrder3 &t1);

    friend TensorOrder3 operator+(const TensorOrder3 &t1, double d);
    friend TensorOrder3 operator-(const TensorOrder3 &t1, double d);
    friend TensorOrder3 operator*(const TensorOrder3 &t1, double d);
    friend TensorOrder3 operator/(const TensorOrder3 &t1, double d);

    friend TensorOrder3 operator+(const TensorOrder3 &t1, const TensorOrder3 &t2);
    friend TensorOrder3 operator-(const TensorOrder3 &t1, const TensorOrder3 &t2);

    friend bool operator==(const TensorOrder3 &t1, const TensorOrder3 &t2);
    friend bool operator!=(const TensorOrder3 &t1, const TensorOrder3 &t2);
    friend bool operator>=(const TensorOrder3 &t1, const TensorOrder3 &t2);
    friend bool operator<=(const TensorOrder3 &t1, const TensorOrder3 &t2);
    friend bool operator> (const TensorOrder3 &t1, const TensorOrder3 &t2);
    friend bool operator< (const TensorOrder3 &t1, const TensorOrder3 &t2);

    friend bool operator==(double d, const TensorOrder3 &t1);
    friend bool operator!=(double d, const TensorOrder3 &t1);
    friend bool operator>=(double d, const TensorOrder3 &t1);
    friend bool operator<=(double d, const TensorOrder3 &t1);
    friend bool operator> (double d, const TensorOrder3 &t1);
    friend bool operator< (double d, const TensorOrder3 &t1);

    friend bool operator==(const TensorOrder3 &t1, double d);
    friend bool operator!=(const TensorOrder3 &t1, double d);
    friend bool operator>=(const TensorOrder3 &t1, double d);
    friend bool operator<=(const TensorOrder3 &t1, double d);
    friend bool operator> (const TensorOrder3 &t1, double d);
    friend bool operator< (const TensorOrder3 &t1, double d);

    friend bool operator==(TComplex d, const TensorOrder3 &t1);
    friend bool operator!=(TComplex d, const TensorOrder3 &t1);
    friend bool operator>=(TComplex d, const TensorOrder3 &t1);
    friend bool operator<=(TComplex d, const TensorOrder3 &t1);
    friend bool operator> (TComplex d, const TensorOrder3 &t1);
    friend bool operator< (TComplex d, const TensorOrder3 &t1);

    friend bool operator==(const TensorOrder3 &t1, TComplex d);
    friend bool operator!=(const TensorOrder3 &t1, TComplex d);
    friend bool operator>=(const TensorOrder3 &t1, TComplex d);
    friend bool operator<=(const TensorOrder3 &t1, TComplex d);
    friend bool operator> (const TensorOrder3 &t1, TComplex d);
    friend bool operator< (const TensorOrder3 &t1, TComplex d);
 
  };


  class TensorOrder4: public Tensor{
    
  private:

    bool CheckIndex(const int i, const int j, const int k, const int l) const;
    int GetGlobalIndex(const int i1, const int i2, const int i3, const int i4) const;

  public:
    TensorOrder4(const TensorOrder4& t1);
    TensorOrder4(const char * Name, int Dim1, int Dim2, int Dim3, int Dim4);
    TensorOrder4(const char * Name = "none", int Dim = 4);
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

    using Tensor::AssertGoodSize;
    using Tensor::GoodSize;

    friend TensorOrder4 Real(const TensorOrder4 &t1);
    friend TensorOrder4 Imaginary(const TensorOrder4 &t1);
    friend TensorOrder4 Abs(const TensorOrder4 &t1);

    friend TensorOrder4 operator+(const int c, const TensorOrder4 &t1);
    friend TensorOrder4 operator-(const int c, const TensorOrder4 &t1);
    friend TensorOrder4 operator*(const int c, const TensorOrder4 &t1);
    friend TensorOrder4 operator/(const int c, const TensorOrder4 &t1);

    friend TensorOrder4 operator+(const TensorOrder4 &t1, const int c);
    friend TensorOrder4 operator-(const TensorOrder4 &t1, const int c);
    friend TensorOrder4 operator*(const TensorOrder4 &t1, const int c);
    friend TensorOrder4 operator/(const TensorOrder4 &t1, const int c);

    friend TensorOrder4 operator+(TComplex c, const TensorOrder4 &t1);
    friend TensorOrder4 operator-(TComplex c, const TensorOrder4 &t1);
    friend TensorOrder4 operator*(TComplex c, const TensorOrder4 &t1);
    friend TensorOrder4 operator/(TComplex c, const TensorOrder4 &t1);

    friend TensorOrder4 operator+(const TensorOrder4 &t1, TComplex c);
    friend TensorOrder4 operator-(const TensorOrder4 &t1, TComplex c);
    friend TensorOrder4 operator*(const TensorOrder4 &t1, TComplex c);
    friend TensorOrder4 operator/(const TensorOrder4 &t1, TComplex c);

    friend TensorOrder4 operator+(double d, const TensorOrder4 &t1);
    friend TensorOrder4 operator-(double d, const TensorOrder4 &t1);
    friend TensorOrder4 operator*(double d, const TensorOrder4 &t1);
    friend TensorOrder4 operator/(double d, const TensorOrder4 &t1);

    friend TensorOrder4 operator+(const TensorOrder4 &t1, double d);
    friend TensorOrder4 operator-(const TensorOrder4 &t1, double d);
    friend TensorOrder4 operator*(const TensorOrder4 &t1, double d);
    friend TensorOrder4 operator/(const TensorOrder4 &t1, double d);

    friend TensorOrder4 operator+(const TensorOrder4 &t1, const TensorOrder4 &t2);
    friend TensorOrder4 operator-(const TensorOrder4 &t1, const TensorOrder4 &t2);

    friend bool operator==(const TensorOrder4 &t1, const TensorOrder4 &t2);
    friend bool operator!=(const TensorOrder4 &t1, const TensorOrder4 &t2);
    friend bool operator>=(const TensorOrder4 &t1, const TensorOrder4 &t2);
    friend bool operator<=(const TensorOrder4 &t1, const TensorOrder4 &t2);
    friend bool operator> (const TensorOrder4 &t1, const TensorOrder4 &t2);
    friend bool operator< (const TensorOrder4 &t1, const TensorOrder4 &t2);

    friend bool operator==(double d, const TensorOrder4 &t1);
    friend bool operator!=(double d, const TensorOrder4 &t1);
    friend bool operator>=(double d, const TensorOrder4 &t1);
    friend bool operator<=(double d, const TensorOrder4 &t1);
    friend bool operator> (double d, const TensorOrder4 &t1);
    friend bool operator< (double d, const TensorOrder4 &t1);

    friend bool operator==(const TensorOrder4 &t1, double d);
    friend bool operator!=(const TensorOrder4 &t1, double d);
    friend bool operator>=(const TensorOrder4 &t1, double d);
    friend bool operator<=(const TensorOrder4 &t1, double d);
    friend bool operator> (const TensorOrder4 &t1, double d);
    friend bool operator< (const TensorOrder4 &t1, double d);

    friend bool operator==(TComplex d, const TensorOrder4 &t1);
    friend bool operator!=(TComplex d, const TensorOrder4 &t1);
    friend bool operator>=(TComplex d, const TensorOrder4 &t1);
    friend bool operator<=(TComplex d, const TensorOrder4 &t1);
    friend bool operator> (TComplex d, const TensorOrder4 &t1);
    friend bool operator< (TComplex d, const TensorOrder4 &t1);

    friend bool operator==(const TensorOrder4 &t1, TComplex d);
    friend bool operator!=(const TensorOrder4 &t1, TComplex d);
    friend bool operator>=(const TensorOrder4 &t1, TComplex d);
    friend bool operator<=(const TensorOrder4 &t1, TComplex d);
    friend bool operator> (const TensorOrder4 &t1, TComplex d);
    friend bool operator< (const TensorOrder4 &t1, TComplex d);

  };

} 


#endif 
