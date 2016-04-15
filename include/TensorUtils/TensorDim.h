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

    TensorDim1(const TensorDim1& t1);
    TensorDim1(int SizeDim = 4, std::string Name = "none");


    void Print() const;
    
    TComplex At(const unsigned int i) const;
    void Set(const unsigned int i, TComplex c);
    TComplex& operator()(const unsigned int i);
    TComplex  operator()(const unsigned int i) const;

    using Tensor::operator=;
    using Tensor::SumOver;

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

    friend TComplex   ElementWiseMult(const TensorDim1 &t1, const TensorDim1 &t2);
    friend TComplex   DotProd(const TensorDim1 &t1, const TensorDim1 &t2);
    friend TensorDim2 CrossProd(const TensorDim1 &t1, const TensorDim1 &t2);
    friend TComplex   operator*(const TensorDim1 &t1, const TensorDim1 &t2);

    friend bool operator==(const Tensor &t1, const Tensor &t2);
    friend bool operator!=(const Tensor &t1, const Tensor &t2);
    friend bool operator>=(const Tensor &t1, const Tensor &t2);
    friend bool operator<=(const Tensor &t1, const Tensor &t2);
    friend bool operator> (const Tensor &t1, const Tensor &t2);
    friend bool operator< (const Tensor &t1, const Tensor &t2);

    friend bool operator==(double d, const Tensor &t1);
    friend bool operator!=(double d, const Tensor &t1);
    friend bool operator>=(double d, const Tensor &t1);
    friend bool operator<=(double d, const Tensor &t1);
    friend bool operator> (double d, const Tensor &t1);
    friend bool operator< (double d, const Tensor &t1);

    friend bool operator==(const Tensor &t1, double d);
    friend bool operator!=(const Tensor &t1, double d);
    friend bool operator>=(const Tensor &t1, double d);
    friend bool operator<=(const Tensor &t1, double d);
    friend bool operator> (const Tensor &t1, double d);
    friend bool operator< (const Tensor &t1, double d);

    friend bool operator==(TComplex d, const Tensor &t1);
    friend bool operator!=(TComplex d, const Tensor &t1);
    friend bool operator>=(TComplex d, const Tensor &t1);
    friend bool operator<=(TComplex d, const Tensor &t1);
    friend bool operator> (TComplex d, const Tensor &t1);
    friend bool operator< (TComplex d, const Tensor &t1);

    friend bool operator==(const Tensor &t1, TComplex d);
    friend bool operator!=(const Tensor &t1, TComplex d);
    friend bool operator>=(const Tensor &t1, TComplex d);
    friend bool operator<=(const Tensor &t1, TComplex d);
    friend bool operator> (const Tensor &t1, TComplex d);
    friend bool operator< (const Tensor &t1, TComplex d);

  };

 class TensorDim2: public Tensor{
    
  private:

    bool         CheckIndex(const unsigned int i, const unsigned int j) const;
    unsigned int GetGlobalIndex(const unsigned int i, const unsigned int j) const;

  public:

    TensorDim2(const TensorDim2& t1);
    TensorDim2(int SizeDim1, int SizeDim2, std::string Name);
    TensorDim2(int SizeDim = 4, std::string Name = "none");

    void Print() const;
    
    TComplex At(const unsigned int i, const unsigned int j) const;
    void Set(const unsigned int i, const unsigned int j, TComplex c);
    TComplex& operator()(const int i1, const int i2);
    TComplex  operator()(const int i1, const int i2) const;
  
    using Tensor::operator=;
    using Tensor::SumOver;
  
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

    friend Tensor ElementWiseMult(const Tensor &t1, const Tensor &t2);
    friend TensorDim1 operator*(const TensorDim2 &td2, const TensorDim1 &td1);

    friend bool operator==(const Tensor &t1, const Tensor &t2);
    friend bool operator!=(const Tensor &t1, const Tensor &t2);
    friend bool operator>=(const Tensor &t1, const Tensor &t2);
    friend bool operator<=(const Tensor &t1, const Tensor &t2);
    friend bool operator> (const Tensor &t1, const Tensor &t2);
    friend bool operator< (const Tensor &t1, const Tensor &t2);

    friend bool operator==(double d, const Tensor &t1);
    friend bool operator!=(double d, const Tensor &t1);
    friend bool operator>=(double d, const Tensor &t1);
    friend bool operator<=(double d, const Tensor &t1);
    friend bool operator> (double d, const Tensor &t1);
    friend bool operator< (double d, const Tensor &t1);

    friend bool operator==(const Tensor &t1, double d);
    friend bool operator!=(const Tensor &t1, double d);
    friend bool operator>=(const Tensor &t1, double d);
    friend bool operator<=(const Tensor &t1, double d);
    friend bool operator> (const Tensor &t1, double d);
    friend bool operator< (const Tensor &t1, double d);

    friend bool operator==(TComplex d, const Tensor &t1);
    friend bool operator!=(TComplex d, const Tensor &t1);
    friend bool operator>=(TComplex d, const Tensor &t1);
    friend bool operator<=(TComplex d, const Tensor &t1);
    friend bool operator> (TComplex d, const Tensor &t1);
    friend bool operator< (TComplex d, const Tensor &t1);

    friend bool operator==(const Tensor &t1, TComplex d);
    friend bool operator!=(const Tensor &t1, TComplex d);
    friend bool operator>=(const Tensor &t1, TComplex d);
    friend bool operator<=(const Tensor &t1, TComplex d);
    friend bool operator> (const Tensor &t1, TComplex d);
    friend bool operator< (const Tensor &t1, TComplex d);
  };



  class TensorDim3: public Tensor{
    
  private:
    
    bool CheckIndex(const unsigned int i, const unsigned int j, const unsigned int k)const;
    unsigned int GetGlobalIndex(const unsigned int i1, const unsigned int i2, const unsigned int i3)const;
  
  public:

    TensorDim3(const TensorDim3& t1);
    TensorDim3(int SizeDim1, int SizeDim2, int SizeDim3, std::string Name = "none");
    TensorDim3(int SizeDim = 4, std::string Name = "none");
    
    TComplex At(const unsigned int i, const unsigned int j, const unsigned int k)const;
    void Set(const unsigned int i, const unsigned int j, const unsigned int k, TComplex c);
    TComplex& operator()(const unsigned int i1, const unsigned int i2, const unsigned int i3);
    TComplex operator()(const unsigned int i1, const unsigned int i2, const unsigned int i3) const;
    void Print() const;

    using Tensor::operator=;
    using Tensor::SumOver;

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
    friend bool operator>=(const Tensor &t1, const Tensor &t2);
    friend bool operator<=(const Tensor &t1, const Tensor &t2);
    friend bool operator> (const Tensor &t1, const Tensor &t2);
    friend bool operator< (const Tensor &t1, const Tensor &t2);

    friend bool operator==(double d, const Tensor &t1);
    friend bool operator!=(double d, const Tensor &t1);
    friend bool operator>=(double d, const Tensor &t1);
    friend bool operator<=(double d, const Tensor &t1);
    friend bool operator> (double d, const Tensor &t1);
    friend bool operator< (double d, const Tensor &t1);

    friend bool operator==(const Tensor &t1, double d);
    friend bool operator!=(const Tensor &t1, double d);
    friend bool operator>=(const Tensor &t1, double d);
    friend bool operator<=(const Tensor &t1, double d);
    friend bool operator> (const Tensor &t1, double d);
    friend bool operator< (const Tensor &t1, double d);

    friend bool operator==(TComplex d, const Tensor &t1);
    friend bool operator!=(TComplex d, const Tensor &t1);
    friend bool operator>=(TComplex d, const Tensor &t1);
    friend bool operator<=(TComplex d, const Tensor &t1);
    friend bool operator> (TComplex d, const Tensor &t1);
    friend bool operator< (TComplex d, const Tensor &t1);

    friend bool operator==(const Tensor &t1, TComplex d);
    friend bool operator!=(const Tensor &t1, TComplex d);
    friend bool operator>=(const Tensor &t1, TComplex d);
    friend bool operator<=(const Tensor &t1, TComplex d);
    friend bool operator> (const Tensor &t1, TComplex d);
    friend bool operator< (const Tensor &t1, TComplex d);
 
  };


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
    void Print() const;
  
    using Tensor::operator=;
    using Tensor::SumOver;

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
    friend bool operator>=(const Tensor &t1, const Tensor &t2);
    friend bool operator<=(const Tensor &t1, const Tensor &t2);
    friend bool operator> (const Tensor &t1, const Tensor &t2);
    friend bool operator< (const Tensor &t1, const Tensor &t2);

    friend bool operator==(double d, const Tensor &t1);
    friend bool operator!=(double d, const Tensor &t1);
    friend bool operator>=(double d, const Tensor &t1);
    friend bool operator<=(double d, const Tensor &t1);
    friend bool operator> (double d, const Tensor &t1);
    friend bool operator< (double d, const Tensor &t1);

    friend bool operator==(const Tensor &t1, double d);
    friend bool operator!=(const Tensor &t1, double d);
    friend bool operator>=(const Tensor &t1, double d);
    friend bool operator<=(const Tensor &t1, double d);
    friend bool operator> (const Tensor &t1, double d);
    friend bool operator< (const Tensor &t1, double d);

    friend bool operator==(TComplex d, const Tensor &t1);
    friend bool operator!=(TComplex d, const Tensor &t1);
    friend bool operator>=(TComplex d, const Tensor &t1);
    friend bool operator<=(TComplex d, const Tensor &t1);
    friend bool operator> (TComplex d, const Tensor &t1);
    friend bool operator< (TComplex d, const Tensor &t1);

    friend bool operator==(const Tensor &t1, TComplex d);
    friend bool operator!=(const Tensor &t1, TComplex d);
    friend bool operator>=(const Tensor &t1, TComplex d);
    friend bool operator<=(const Tensor &t1, TComplex d);
    friend bool operator> (const Tensor &t1, TComplex d);
    friend bool operator< (const Tensor &t1, TComplex d);

  };

} 


#endif 
