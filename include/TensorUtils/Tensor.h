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
    int GetDim() const;
    int GetDimSize(const int i = 0) const;
    TComplex SumOver() const;

    const char* GetName() const{ return Name; };

    Tensor& operator=(const Tensor &t1);

    virtual bool AssertGoodDim(int Dim) const;
    virtual bool AssertGoodDim(int Dim, int DimSize) const;
    virtual bool AssertGoodDim(const Tensor &t1) const;
    virtual bool GoodDim(int Dim) const;
    virtual bool GoodDim(int Dim, int DimSize) const;
    virtual bool GoodDim(const Tensor &t1) const;

    virtual void Real();
    virtual void Imaginary();
    virtual void Abs();
    virtual void Minus();
    virtual void OneOverElementWise();

    virtual void Add      (const int c);
    virtual void Subtract (const int c);
    virtual void Multiply (const int c);
    virtual void Divide   (const int c);
 
    virtual void Add      (const TComplex c);
    virtual void Subtract (const TComplex c);
    virtual void Multiply (const TComplex c);
    virtual void Divide   (const TComplex c);

    virtual void Add      (const double xd);
    virtual void Subtract (const double d);
    virtual void Multiply (const double d);
    virtual void Divide   (const double d);

    virtual void Add                 (const Tensor &t);
    virtual void Subtract            (const Tensor &t);
    virtual void MultiplyElementWise (const Tensor &t);
    virtual void DivideElementWise   (const Tensor &t);

    virtual bool IsEqual          (const Tensor &t) const;
    virtual bool IsDifferent      (const Tensor &t) const;
    virtual bool IsBiggerOrEqual  (const Tensor &t) const;
    virtual bool IsSmallerOrEqual (const Tensor &t) const;
    virtual bool IsBigger         (const Tensor &t) const;
    virtual bool IsSmaller        (const Tensor &t) const;

    virtual bool IsEqual          (const double d) const;
    virtual bool IsDifferent      (const double d) const;
    virtual bool IsBiggerOrEqual  (const double d) const;
    virtual bool IsSmallerOrEqual (const double d) const;
    virtual bool IsBigger         (const double d) const;
    virtual bool IsSmaller        (const double d) const;

    virtual bool IsEqual          (const TComplex d) const;
    virtual bool IsDifferent      (const TComplex d) const;
    virtual bool IsBiggerOrEqual  (const TComplex d) const;
    virtual bool IsSmallerOrEqual (const TComplex d) const;
    virtual bool IsBigger         (const TComplex d) const;
    virtual bool IsSmaller        (const TComplex d) const;

  protected:

    Tensor(const Tensor& t1);

    std::vector< TComplex > Element;
    std::vector< int >  DimSize;
    const char * Name;
    int Dim;

    virtual bool CheckIndex() const {return false;};
    virtual int GetGlobalIndex() const {return 0;};
    virtual void Print() const {};

    Tensor(){};

    TComplex& operator()(const int GlobalIndex);
    TComplex  operator()(const int GlobalIndex) const;

  };
} 

#endif
