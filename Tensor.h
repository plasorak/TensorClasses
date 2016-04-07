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



namespace TensorUtils {

  class Tensor: public TObject{
    
  public:
    
    ~Tensor();
    TComplex At();
    void Set();
    unsigned int GetDim();
    unsigned int GetDimSize(const unsigned int i);

    friend Tensor Real(const Tensor& t1);
    friend Tensor Imaginary(const Tensor& t1);
    friend Tensor Abs(const Tensor& t1);

    std::string GetName(){
      return Name;
    };
  
    friend Tensor operator-(const Tensor &t1);
    //Tensor OperatorMinus(const Tensor &t1);

    Tensor& operator=(const Tensor &t1){
      this->Name = t1.Name;
      this->Dim  = t1.Dim;
      for(unsigned int i = 0; i < t1.Elements.size(); i++)
	this->Elements.push_back(t1.Elements[i]);
      for(unsigned int i = 0; i < t1.DimSizes.size(); i++)
	this->DimSizes.push_back(t1.DimSizes[i]);
      return *this;
    };

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
    friend Tensor operator*(const Tensor &t1, const Tensor &t2);
    friend Tensor operator/(const Tensor &t1, const Tensor &t2);

    friend bool operator==(const Tensor &t1, const Tensor &t2);
    friend bool operator!=(const Tensor &t1, const Tensor &t2);
    friend bool operator>=(const Tensor &t1, const Tensor &t2); // NEXT are yet to do
    friend bool operator<=(const Tensor &t1, const Tensor &t2); //
    friend bool operator> (const Tensor &t1, const Tensor &t2); //
    friend bool operator< (const Tensor &t1, const Tensor &t2); //

    friend bool operator==(const double d, const Tensor &t1); //
    friend bool operator!=(const double d, const Tensor &t1); //
    friend bool operator>=(const double d, const Tensor &t1); //
    friend bool operator<=(const double d, const Tensor &t1); //
    friend bool operator> (const double d, const Tensor &t1); //
    friend bool operator< (const double d, const Tensor &t1); //
    
    friend bool operator==(const Tensor &t1, const double d); //
    friend bool operator!=(const Tensor &t1, const double d); //
    friend bool operator>=(const Tensor &t1, const double d); //
    friend bool operator<=(const Tensor &t1, const double d); //
    friend bool operator> (const Tensor &t1, const double d); //
    friend bool operator< (const Tensor &t1, const double d); //

    friend bool operator==(const TComplex d, const Tensor &t1); //
    friend bool operator!=(const TComplex d, const Tensor &t1); //
    friend bool operator>=(const TComplex d, const Tensor &t1); //
    friend bool operator<=(const TComplex d, const Tensor &t1); //
    friend bool operator> (const TComplex d, const Tensor &t1); //
    friend bool operator< (const TComplex d, const Tensor &t1); //

    friend bool operator==(const Tensor &t1, const TComplex d); //
    friend bool operator!=(const Tensor &t1, const TComplex d); //
    friend bool operator>=(const Tensor &t1, const TComplex d); //
    friend bool operator<=(const Tensor &t1, const TComplex d); //
    friend bool operator> (const Tensor &t1, const TComplex d); //
    friend bool operator< (const Tensor &t1, const TComplex d); //


  protected:
    Tensor(const Tensor& t1);

    std::vector< TComplex > Elements;
    std::vector< unsigned int >  DimSizes;
    std::string Name;
    unsigned int Dim;

    virtual bool CheckIndex()const;
    virtual unsigned int GetGlobalIndex()const;

    Tensor(){};

    TComplex& operator()(const unsigned int GlobalIndex);
    TComplex  operator()(const unsigned int GlobalIndex) const;
 
    ClassDef(Tensor, 1)
  };

}



#endif
