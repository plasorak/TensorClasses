#ifndef _TENSOR_H_
#define _TENSOR_H_
#include "TComplex.h"
#include "TObject.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <complex>

namespace TensorUtils{ 

  class Tensor: public TObject{

  public:

    ~Tensor();
    TComplex At();
    void Set();
    unsigned int GetDim() const;
    unsigned int GetDimSize(const unsigned int i = 0) const;
    TComplex SumOver() const;

    friend Tensor Real(const Tensor& t1);
    friend Tensor Imaginary(const Tensor& t1);
    friend Tensor Abs(const Tensor& t1);

    const char* GetName() const{
      return Name.c_str();
    };

    friend Tensor operator-(const Tensor &t1);

    Tensor& operator=(const Tensor &t1);

    friend Tensor operator+(const int c, const Tensor &t1);
    friend Tensor operator-(const int c, const Tensor &t1);
    friend Tensor operator*(const int c, const Tensor &t1);
    friend Tensor operator/(const int c, const Tensor &t1);

    friend Tensor operator+(const Tensor &t1, const int c);
    friend Tensor operator-(const Tensor &t1, const int c);
    friend Tensor operator*(const Tensor &t1, const int c);
    friend Tensor operator/(const Tensor &t1, const int c);

    friend Tensor operator+(const TComplex c, const Tensor &t1);
    friend Tensor operator-(const TComplex c, const Tensor &t1);
    friend Tensor operator*(const TComplex c, const Tensor &t1);
    friend Tensor operator/(const TComplex c, const Tensor &t1);

    friend Tensor operator+(const Tensor &t1, const TComplex c);
    friend Tensor operator-(const Tensor &t1, const TComplex c);
    friend Tensor operator*(const Tensor &t1, const TComplex c);
    friend Tensor operator/(const Tensor &t1, const TComplex c);

    friend Tensor operator+(const double d, const Tensor &t1);
    friend Tensor operator-(const double d, const Tensor &t1);
    friend Tensor operator*(const double d, const Tensor &t1);
    friend Tensor operator/(const double d, const Tensor &t1);

    friend Tensor operator+(const Tensor &t1, const double d);
    friend Tensor operator-(const Tensor &t1, const double d);
    friend Tensor operator*(const Tensor &t1, const double d);
    friend Tensor operator/(const Tensor &t1, const double d);

    friend Tensor operator+(const Tensor &t1, const Tensor &t2);
    friend Tensor operator-(const Tensor &t1, const Tensor &t2);
    
    friend Tensor ElementWiseMult(const Tensor &t1, const Tensor &t2); // to go in tensorutils
    
    friend bool operator==(const Tensor &t1, const Tensor &t2);
    friend bool operator!=(const Tensor &t1, const Tensor &t2);
    friend bool operator>=(const Tensor &t1, const Tensor &t2);
    friend bool operator<=(const Tensor &t1, const Tensor &t2);
    friend bool operator> (const Tensor &t1, const Tensor &t2);
    friend bool operator< (const Tensor &t1, const Tensor &t2);

    friend bool operator==(const double d, const Tensor &t1);
    friend bool operator!=(const double d, const Tensor &t1);
    friend bool operator>=(const double d, const Tensor &t1);
    friend bool operator<=(const double d, const Tensor &t1);
    friend bool operator> (const double d, const Tensor &t1);
    friend bool operator< (const double d, const Tensor &t1);

    friend bool operator==(const Tensor &t1, const double d);
    friend bool operator!=(const Tensor &t1, const double d);
    friend bool operator>=(const Tensor &t1, const double d);
    friend bool operator<=(const Tensor &t1, const double d);
    friend bool operator> (const Tensor &t1, const double d);
    friend bool operator< (const Tensor &t1, const double d);

    friend bool operator==(const TComplex d, const Tensor &t1);
    friend bool operator!=(const TComplex d, const Tensor &t1);
    friend bool operator>=(const TComplex d, const Tensor &t1);
    friend bool operator<=(const TComplex d, const Tensor &t1);
    friend bool operator> (const TComplex d, const Tensor &t1);
    friend bool operator< (const TComplex d, const Tensor &t1);

    friend bool operator==(const Tensor &t1, const TComplex d);
    friend bool operator!=(const Tensor &t1, const TComplex d);
    friend bool operator>=(const Tensor &t1, const TComplex d);
    friend bool operator<=(const Tensor &t1, const TComplex d);
    friend bool operator> (const Tensor &t1, const TComplex d);
    friend bool operator< (const Tensor &t1, const TComplex d);


  protected:

    Tensor(const Tensor& t1);

    std::vector< TComplex > Element;
    std::vector< unsigned int >  DimSize;
    std::string Name;
    unsigned int Dim;

    virtual bool CheckIndex() const {return false;};
    virtual unsigned int GetGlobalIndex() const {return 0;};
    virtual void Print() const {};

    Tensor(){};

    TComplex& operator()(const unsigned int GlobalIndex);
    TComplex  operator()(const unsigned int GlobalIndex) const;

  };
} 

#endif
