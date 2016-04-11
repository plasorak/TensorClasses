#include "TensorUtils/Tensor.h"

#include "TComplex.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>

namespace TensorUtils{

  Tensor::~Tensor(){
    Elements.clear();
    DimSizes.clear();
  };

  unsigned int Tensor::GetDim() const{

    if(Dim != DimSizes.size()){
      std::cerr << "Dimension of the tensor as changed!" << std::endl;
      std::cerr << "Program will exit" << std::endl;
      exit(1);
    }
    return Dim;
  };

  unsigned int Tensor::GetDimSize(const unsigned int i) const{

    if(Dim != DimSizes.size()){
      std::cerr << "Dimension of the tensor as changed!" << std::endl;
      std::cerr << "Program will exit" << std::endl;
      exit(1);
    }

    if(i > 0 && i < Dim)
      return DimSizes[i];
    else{
      std::cerr << "Trying to access the size of dimension which doesn't exist in the tensor"<<  std::endl;
      return -9999999;
    }
  };

  Tensor& Tensor::operator=(const Tensor &t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(unsigned int i = 0; i < t1.Elements.size(); i++)
      this->Elements.push_back(t1.Elements[i]);
    for(unsigned int i = 0; i < t1.DimSizes.size(); i++)
      this->DimSizes.push_back(t1.DimSizes[i]);
    return *this;
  };

  Tensor::Tensor(const Tensor& t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(unsigned int i = 0; i < t1.Elements.size(); i++)
      this->Elements.push_back(t1.Elements[i]);
    for(unsigned int i = 0; i < t1.DimSizes.size(); i++)
      this->DimSizes.push_back(t1.DimSizes[i]);
  };

  TComplex& Tensor::operator()(const unsigned int GlobalIndex){
    return Elements[GlobalIndex];
  };

  TComplex  Tensor::operator()(const unsigned int GlobalIndex) const{
    return Elements[GlobalIndex];
  };

  // -----------------------------------------------------
  // Tensor friend functions
  // -----------------------------------------------------

  // Returning negative value
  Tensor operator-(const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = -nTensor.Elements[i];
    return nTensor;
  }

  // Scalar operations
  Tensor operator+(const TComplex c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] + c;
    return nTensor;
  }

  Tensor operator-(const TComplex c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = c - nTensor.Elements[i];
    return nTensor;
  }

  Tensor operator*(const TComplex c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] * c;
    return nTensor;
  }

  Tensor operator/(const TComplex c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = c / nTensor.Elements[i];
    return nTensor;
  }

  Tensor operator+(const Tensor &t1, const TComplex c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] + c;
    return nTensor;
  }

  Tensor operator-(const Tensor &t1, const TComplex c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] - c;
    return nTensor;
  }

  Tensor operator*(const Tensor &t1, const TComplex c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] * c;
    return nTensor;
  }

  Tensor operator/(const Tensor &t1, const TComplex c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] / c;
    return nTensor;
  }




  Tensor operator+(const double d, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] + d;
    return nTensor;
  }

  Tensor operator-(const double d, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = d - nTensor.Elements[i];
    return nTensor;
  }

  Tensor operator*(const double d, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] * d;
    return nTensor;
  }

  Tensor operator/(const double d, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = d / nTensor.Elements[i];
    return nTensor;
  }

  Tensor operator+(const Tensor &t1, const double d){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] + d;
    return nTensor;
  }

  Tensor operator-(const Tensor &t1, const double d){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] - d;
    return nTensor;
  }

  Tensor operator*(const Tensor &t1, const double d){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] * d;
    return nTensor;
  }

  Tensor operator/(const Tensor &t1, const double d){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] / d;
    return nTensor;
  }

  // Entry by entry operations
  Tensor operator+(const Tensor &t1, const Tensor &t2){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] + t1.Elements[i];
    return nTensor;
  }

  Tensor operator-(const Tensor &t1, const Tensor &t2){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] - t1.Elements[i];
    return nTensor;
  }

  Tensor operator*(const Tensor &t1, const Tensor &t2){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] * t1.Elements[i];
    return nTensor;
  }

  Tensor operator/(const Tensor &t1, const Tensor &t2){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] / t1.Elements[i];
    return nTensor;
  }


  // Boolean operations
  bool operator==(const Tensor &t1, const Tensor &t2){

    // First chekc the rank of the tensor
    if(t2.Dim != t1.Dim)
      return false;

    bool flag = true;
    unsigned int i = 0;

    // Then check the number of element for each dim
    while(flag && i < t1.DimSizes.size()){
      if(!t2.DimSizes[i] == t1.DimSizes[i])
	flag = false;
    }
    if(!flag)
      return flag;

    flag = true;
    i = 0;
    // Then check the element by element
    while(flag && i < t1.Elements.size()){
      if(!t2.Elements[i].Im() == t1.Elements[i].Im() || !t2.Elements[i].Re() == t1.Elements[i].Re())
	flag = false;
    }
    return flag;
  };

  bool operator!=(const Tensor &t1, const Tensor &t2){
    return !(t1 == t2);
  };

  Tensor Real(const Tensor& t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = t1.Elements[i].Re();
    return nTensor;
  };

  Tensor Imaginary(const Tensor& t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = t1.Elements[i].Im();
    return nTensor;
  };

  Tensor Abs(const Tensor& t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = TComplex::Abs(t1.Elements[i]);
    return nTensor;
  };

  Tensor operator+(const int c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] + (double)c;
    return nTensor;
  }

  Tensor operator-(const int c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = (double)c - nTensor.Elements[i];
    return nTensor;
  }

  Tensor operator*(const int c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] * (double)c;
    return nTensor;
  }

  Tensor operator/(const int c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = (double)c / nTensor.Elements[i];
    return nTensor;
  }

  Tensor operator+(const Tensor &t1, const int c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] + (double)c;
    return nTensor;
  }

  Tensor operator-(const Tensor &t1, const int c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] - (double)c; 
    return nTensor;
  }

  Tensor operator*(const Tensor &t1, const int c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] * (double)c; 
    return nTensor;
  }

  Tensor operator/(const Tensor &t1, const int c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Elements.size(); i++)
      nTensor.Elements[i] = nTensor.Elements[i] / (double)c; 
    return nTensor;
  }
  

  bool operator==(double d, const Tensor &T){
    for(unsigned int i = 0; i < T.Elements.size(); i++)
      if(TComplex::Abs(T.Elements[i]) != d)
	return false;
    return true;
  }

  bool operator!=(double d, const Tensor &T){
    return !(d == T);
  }

  bool operator>=(double d, const Tensor &T){
    for(unsigned int i = 0; i < T.Elements.size(); i++)
      if(abs(d) < TComplex::Abs(T.Elements[i]))
	return false;
    return true;
  }


  bool operator<=(double d, const Tensor &T){
    for(unsigned int i = 0; i < T.Elements.size(); i++)
      if(abs(d) > TComplex::Abs(T.Elements[i]))
	return false;
    return true;
  }

  bool operator> (double d, const Tensor &T){
    for(unsigned int i = 0; i < T.Elements.size(); i++)
      if(abs(d) <= TComplex::Abs(T.Elements[i]))
	return false;
    return true;
  }


  bool operator< (double d, const Tensor &T){
    for(unsigned int i = 0; i < T.Elements.size(); i++)
      if(abs(d) >= TComplex::Abs(T.Elements[i]))
	return false;
    return true;
  }

  bool operator==(const Tensor &T, double d){
    return (d == T);
  }

  bool operator!=(const Tensor &T, double d){
    return (d != T);
  }

  bool operator>=(const Tensor &T, double d){
    for(unsigned int i = 0; i < T.Elements.size(); i++)
      if(TComplex::Abs(T.Elements[i]) < abs(d))
	return false;
    return true;
  }

  bool operator<=(const Tensor &T, double d){
    for(unsigned int i = 0; i < T.Elements.size(); i++)
      if(TComplex::Abs(T.Elements[i]) > abs(d))
	return false;
    return true;
  }

  bool operator> (const Tensor &T, double d){
    for(unsigned int i = 0; i < T.Elements.size(); i++)
      if(TComplex::Abs(T.Elements[i]) <= abs(d))
	return false;
    return true;
  }

  bool operator< (const Tensor &T, double d){
    for(unsigned int i = 0; i < T.Elements.size(); i++)
      if(TComplex::Abs(T.Elements[i]) >= abs(d))
	return false;
    return true;
  }

  bool operator==(TComplex d, const Tensor &T){
    return (TComplex::Abs(d) == T);
  }

  bool operator!=(TComplex d, const Tensor &T){
    return !(d == T);
  }

  bool operator>=(TComplex d, const Tensor &T){
    return (TComplex::Abs(d) >= T);
  }

  bool operator<=(TComplex d, const Tensor &T){
    return (TComplex::Abs(d) <= T);
  }

  bool operator> (TComplex d, const Tensor &T){
    return (TComplex::Abs(d) > T);
  }

  bool operator< (TComplex d, const Tensor &T){
    return (TComplex::Abs(d) < T);
  }

  bool operator==(const Tensor &T, TComplex d){
    return (TComplex::Abs(d) == T);
  }

  bool operator!=(const Tensor &T, TComplex d){
    return (TComplex::Abs(d) != T);
  }

  bool operator>=(const Tensor &T, TComplex d){
    return (TComplex::Abs(d) <= T);
  }

  bool operator<=(const Tensor &T, TComplex d){
    return (TComplex::Abs(d) >= T);
  }


  bool operator> (const Tensor &T, TComplex d){
    return (TComplex::Abs(d) < T);
  }

  bool operator< (const Tensor &T, TComplex d){
    return (TComplex::Abs(d) > T);
  }

  /*
    TensorDim2 MatMult(const TensorDim2 &t1,  const TensorDim2 &t2){

    }

    TensorDim1 MatMult(const TensorDim2 &td2, const TensorDim1 &td1){

    }

    TensorDim2 VecProd(const TensorDim1 &t1, const TensorDim1 &t2){

    }

    TComplex DotProd(const Tensor &t1, const Tensor &t2){
    return t1*t2;
    }

    TensorDim3 SlashDirac(){
    }
  */

}
