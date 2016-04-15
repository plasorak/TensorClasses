#ifndef _TENSORDIM3_H_
#define _TENSORDIM3_H_

// #include <iostream>
// #include <iomanip>
// #include <sstream>
// #include <string>
// #include <cstdlib>
// #include <complex>

// #include "TensorUtils/Tensor.h"

// namespace TensorUtils{

//   class TensorDim3: public Tensor{
    
//   private:
    
//     bool CheckIndex(const unsigned int i, const unsigned int j, const unsigned int k)const;
//     unsigned int GetGlobalIndex(const unsigned int i1, const unsigned int i2, const unsigned int i3)const;
  
//   public:

//     TensorDim3(const TensorDim3& t1);
//     TensorDim3(int SizeDim1, int SizeDim2, int SizeDim3, std::string Name = "none");
//     TensorDim3(int SizeDim = 4, std::string Name = "none");
    
//     TComplex At(const unsigned int i, const unsigned int j, const unsigned int k)const;
//     void Set(const unsigned int i, const unsigned int j, const unsigned int k, TComplex c);
//     TComplex& operator()(const unsigned int i1, const unsigned int i2, const unsigned int i3);
//     TComplex operator()(const unsigned int i1, const unsigned int i2, const unsigned int i3) const;
//     void Print() const;

//     using Tensor::operator=;
//     using Tensor::SumOver()const;

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
//     friend Tensor operator*(const Tensor &t1, const Tensor &t2);
//     friend Tensor operator/(const Tensor &t1, const Tensor &t2);

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
