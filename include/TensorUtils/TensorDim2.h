#ifndef _TENSORDIM2_H_
#define _TENSORDIM2_H_

// #include <iostream>
// #include <iomanip>
// #include <sstream>
// #include <string>
// #include <cstdlib>
// #include <complex>

// #include "TensorUtils/Tensor.h"
// #include "TensorUtils/TensorDim1.h"

// namespace TensorUtils{

//   class TensorDim2: public Tensor{
    
//   private:

//     bool         CheckIndex(const unsigned int i, const unsigned int j) const;
//     unsigned int GetGlobalIndex(const unsigned int i, const unsigned int j) const;

//   public:

//     TensorDim2(const TensorDim2& t1);
//     TensorDim2(int SizeDim1, int SizeDim2, std::string Name);
//     TensorDim2(int SizeDim = 4, std::string Name = "none");

//     void Print() const;
    
//     TComplex At(const unsigned int i, const unsigned int j) const;
//     void Set(const unsigned int i, const unsigned int j, TComplex c);
//     TComplex& operator()(const int i1, const int i2);
//     TComplex  operator()(const int i1, const int i2) const;
  
//     using Tensor::operator=;
//     using Tensor::SumOver;
  
//     friend Tensor Real(const Tensor &t1);
//     friend Tensor Imaginary(const Tensor &t1);
//     friend Tensor Abs(const Tensor &t1);
      
//     friend Tensor operator+(const int c, const Tensor &t1);
//     friend Tensor operator-(const int c, const Tensor &t1);
//     friend Tensor operator*(const int c, const Tensor &t1);
//     friend Tensor operator/(const int c, const Tensor &t1);

//     friend Tensor operator+(const Tensor &t1, const int c);
//     friend Tensor operator-(const Tensor &t1, const int c);
//     friend Tensor operator*(const Tensor &t1, const int c);
//     friend Tensor operator/(const Tensor &t1, const int c);

//     friend Tensor operator+(TComplex c, const Tensor &t1);
//     friend Tensor operator-(TComplex c, const Tensor &t1);
//     friend Tensor operator*(TComplex c, const Tensor &t1);
//     friend Tensor operator/(TComplex c, const Tensor &t1);

//     friend Tensor operator+(const Tensor &t1, TComplex c);
//     friend Tensor operator-(const Tensor &t1, TComplex c);
//     friend Tensor operator*(const Tensor &t1, TComplex c);
//     friend Tensor operator/(const Tensor &t1, TComplex c);

//     friend Tensor operator+(double d, const Tensor &t1);
//     friend Tensor operator-(double d, const Tensor &t1);
//     friend Tensor operator*(double d, const Tensor &t1);
//     friend Tensor operator/(double d, const Tensor &t1);

//     friend Tensor operator+(const Tensor &t1, double d);
//     friend Tensor operator-(const Tensor &t1, double d);
//     friend Tensor operator*(const Tensor &t1, double d);
//     friend Tensor operator/(const Tensor &t1, double d);

//     friend Tensor operator+(const Tensor &t1, const Tensor &t2);
//     friend Tensor operator-(const Tensor &t1, const Tensor &t2);

//     friend Tensor ElementWiseMult(const Tensor &t1, const Tensor &t2);
//     friend TensorDim1 operator*(const TensorDim2 &td2, const TensorDim1 &td1);

//     friend bool operator==(const Tensor &t1, const Tensor &t2);
//     friend bool operator!=(const Tensor &t1, const Tensor &t2);
//     friend bool operator>=(const Tensor &t1, const Tensor &t2);
//     friend bool operator<=(const Tensor &t1, const Tensor &t2);
//     friend bool operator> (const Tensor &t1, const Tensor &t2);
//     friend bool operator< (const Tensor &t1, const Tensor &t2);

//     friend bool operator==(double d, const Tensor &t1);
//     friend bool operator!=(double d, const Tensor &t1);
//     friend bool operator>=(double d, const Tensor &t1);
//     friend bool operator<=(double d, const Tensor &t1);
//     friend bool operator> (double d, const Tensor &t1);
//     friend bool operator< (double d, const Tensor &t1);

//     friend bool operator==(const Tensor &t1, double d);
//     friend bool operator!=(const Tensor &t1, double d);
//     friend bool operator>=(const Tensor &t1, double d);
//     friend bool operator<=(const Tensor &t1, double d);
//     friend bool operator> (const Tensor &t1, double d);
//     friend bool operator< (const Tensor &t1, double d);

//     friend bool operator==(TComplex d, const Tensor &t1);
//     friend bool operator!=(TComplex d, const Tensor &t1);
//     friend bool operator>=(TComplex d, const Tensor &t1);
//     friend bool operator<=(TComplex d, const Tensor &t1);
//     friend bool operator> (TComplex d, const Tensor &t1);
//     friend bool operator< (TComplex d, const Tensor &t1);

//     friend bool operator==(const Tensor &t1, TComplex d);
//     friend bool operator!=(const Tensor &t1, TComplex d);
//     friend bool operator>=(const Tensor &t1, TComplex d);
//     friend bool operator<=(const Tensor &t1, TComplex d);
//     friend bool operator> (const Tensor &t1, TComplex d);
//     friend bool operator< (const Tensor &t1, TComplex d);

//   };
// }
#endif
