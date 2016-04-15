#include "TensorUtils/Tensor.h"

#include "TComplex.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>

namespace TensorUtils{

  Tensor::~Tensor(){
    Element.clear();
    DimSize.clear();
  };


  unsigned int Tensor::GetDim() const{

    if(Dim != DimSize.size()){
      std::cerr << "Dimension of the tensor as changed!" << std::endl;
      std::cerr << "Program will exit" << std::endl;
      exit(1);
    }
    return Dim;
  };

  unsigned int Tensor::GetDimSize(const unsigned int i) const{

    if(Dim != DimSize.size()){
      std::cerr << "Dimension of the tensor as changed!" << std::endl;
      std::cerr << "Program will exit" << std::endl;
      exit(1);
    }

    if(i > 0 && i < Dim)
      return DimSize[i];
    else{
      std::cerr << "Trying to access the size of dimension which doesn't exist in the tensor"<<  std::endl;
      return -9999999;
    }
  };

  TComplex Tensor::SumOver() const{
    TComplex Zero(0,0);
    for(unsigned int i = 0; i < Element.size(); i++)
      Zero = Zero + Element[i];
    return Zero;
  }
  

  Tensor& Tensor::operator=(const Tensor &t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(unsigned int i = 0; i < t1.Element.size(); i++)
      this->Element.push_back(t1.Element[i]);
    for(unsigned int i = 0; i < t1.DimSize.size(); i++)
      this->DimSize.push_back(t1.DimSize[i]);
    return *this;
  };

  Tensor::Tensor(const Tensor& t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(unsigned int i = 0; i < t1.Element.size(); i++)
      this->Element.push_back(t1.Element[i]);
    for(unsigned int i = 0; i < t1.DimSize.size(); i++)
      this->DimSize.push_back(t1.DimSize[i]);
  };

  TComplex& Tensor::operator()(const unsigned int GlobalIndex){
    return Element[GlobalIndex];
  };

  TComplex  Tensor::operator()(const unsigned int GlobalIndex) const{
    return Element[GlobalIndex];
  };

  // -----------------------------------------------------
  // Tensor friend functions
  // -----------------------------------------------------

  // Returning negative value
  Tensor operator-(const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = -nTensor.Element[i];
    return nTensor;
  }

  // Scalar operations
  Tensor operator+(const TComplex c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] + c;
    return nTensor;
  }

  Tensor operator-(const TComplex c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = c - nTensor.Element[i];
    return nTensor;
  }

  Tensor operator*(const TComplex c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] * c;
    return nTensor;
  }

  Tensor operator/(const TComplex c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = c / nTensor.Element[i];
    return nTensor;
  }

  Tensor operator+(const Tensor &t1, const TComplex c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] + c;
    return nTensor;
  }

  Tensor operator-(const Tensor &t1, const TComplex c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] - c;
    return nTensor;
  }

  Tensor operator*(const Tensor &t1, const TComplex c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] * c;
    return nTensor;
  }

  Tensor operator/(const Tensor &t1, const TComplex c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] / c;
    return nTensor;
  }




  Tensor operator+(const double d, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] + d;
    return nTensor;
  }

  Tensor operator-(const double d, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = d - nTensor.Element[i];
    return nTensor;
  }

  Tensor operator*(const double d, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] * d;
    return nTensor;
  }

  Tensor operator/(const double d, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = d / nTensor.Element[i];
    return nTensor;
  }

  Tensor operator+(const Tensor &t1, const double d){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] + d;
    return nTensor;
  }

  Tensor operator-(const Tensor &t1, const double d){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] - d;
    return nTensor;
  }

  Tensor operator*(const Tensor &t1, const double d){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] * d;
    return nTensor;
  }

  Tensor operator/(const Tensor &t1, const double d){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] / d;
    return nTensor;
  }

  // Entry by entry operations
  Tensor operator+(const Tensor &t1, const Tensor &t2){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] + t1.Element[i];
    return nTensor;
  }

  Tensor operator-(const Tensor &t1, const Tensor &t2){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] - t1.Element[i];
    return nTensor;
  }

  Tensor ElementWiseMult(const Tensor &t1, const Tensor &t2){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] * t1.Element[i];
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
    while(flag && i < t1.DimSize.size()){
      if(!t2.DimSize[i] == t1.DimSize[i])
	flag = false;
    }
    if(!flag)
      return flag;

    flag = true;
    i = 0;
    // Then check the element by element
    while(flag && i < t1.Element.size()){
      if(!t2.Element[i].Im() == t1.Element[i].Im() || !t2.Element[i].Re() == t1.Element[i].Re())
	flag = false;
    }
    return flag;
  };

  bool operator!=(const Tensor &t1, const Tensor &t2){
    return !(t1 == t2);
  };

  Tensor Real(const Tensor& t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = t1.Element[i].Re();
    return nTensor;
  };

  Tensor Imaginary(const Tensor& t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = t1.Element[i].Im();
    return nTensor;
  };

  Tensor Abs(const Tensor& t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = TComplex::Abs(t1.Element[i]);
    return nTensor;
  };

  Tensor operator+(const int c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] + (double)c;
    return nTensor;
  }

  Tensor operator-(const int c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = (double)c - nTensor.Element[i];
    return nTensor;
  }

  Tensor operator*(const int c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] * (double)c;
    return nTensor;
  }

  Tensor operator/(const int c, const Tensor &t1){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = (double)c / nTensor.Element[i];
    return nTensor;
  }

  Tensor operator+(const Tensor &t1, const int c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] + (double)c;
    return nTensor;
  }

  Tensor operator-(const Tensor &t1, const int c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] - (double)c; 
    return nTensor;
  }

  Tensor operator*(const Tensor &t1, const int c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] * (double)c; 
    return nTensor;
  }

  Tensor operator/(const Tensor &t1, const int c){
    Tensor nTensor(t1);
    for(unsigned int i = 0; i < nTensor.Element.size(); i++)
      nTensor.Element[i] = nTensor.Element[i] / (double)c; 
    return nTensor;
  }
  

  bool operator==(double d, const Tensor &T){
    for(unsigned int i = 0; i < T.Element.size(); i++)
      if(TComplex::Abs(T.Element[i]) != d)
	return false;
    return true;
  }

  bool operator!=(double d, const Tensor &T){
    return !(d == T);
  }

  bool operator>=(double d, const Tensor &T){
    for(unsigned int i = 0; i < T.Element.size(); i++)
      if(abs(d) < TComplex::Abs(T.Element[i]))
	return false;
    return true;
  }


  bool operator<=(double d, const Tensor &T){
    for(unsigned int i = 0; i < T.Element.size(); i++)
      if(abs(d) > TComplex::Abs(T.Element[i]))
	return false;
    return true;
  }

  bool operator> (double d, const Tensor &T){
    for(unsigned int i = 0; i < T.Element.size(); i++)
      if(abs(d) <= TComplex::Abs(T.Element[i]))
	return false;
    return true;
  }


  bool operator< (double d, const Tensor &T){
    for(unsigned int i = 0; i < T.Element.size(); i++)
      if(abs(d) >= TComplex::Abs(T.Element[i]))
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
    for(unsigned int i = 0; i < T.Element.size(); i++)
      if(TComplex::Abs(T.Element[i]) < abs(d))
	return false;
    return true;
  }

  bool operator<=(const Tensor &T, double d){
    for(unsigned int i = 0; i < T.Element.size(); i++)
      if(TComplex::Abs(T.Element[i]) > abs(d))
	return false;
    return true;
  }

  bool operator> (const Tensor &T, double d){
    for(unsigned int i = 0; i < T.Element.size(); i++)
      if(TComplex::Abs(T.Element[i]) <= abs(d))
	return false;
    return true;
  }

  bool operator< (const Tensor &T, double d){
    for(unsigned int i = 0; i < T.Element.size(); i++)
      if(TComplex::Abs(T.Element[i]) >= abs(d))
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

  TensorDim2 MatMult(const TensorDim2 &t1,  const TensorDim2 &t2){

    // First check the dimension of the matrix
    if(t1->GetDim() != 2 || t2->GetDim() != 2){
      std::cerr << "Can't do the matrix product, one of the tensor is not a matrix or vector" << std::endl;
      exit(1);
    }

    // Then check that size are good for multiplication
    // (i * j) (j * k) = (i * k)
    if(t1->GetDimSize(1) !=  t2->GetDimSize(0)){
      std::cerr << "Can't do the matrix product, the matrix sizes are not right" << std::endl;
      exit(1);
    }

    TensorDim2 result(t1->GetDimSize(0), t2->GetDimSize(1));

    for(int i = 0; i < t1->GetDimSize(0); i++)
      for(int j = 0; j < t2->GetDimSize(1); j++)
	for(int k = 0; k < t1->GetDimSize(1); k++)
	  result(i,j) += t1(i,k)*t2(k,j);
    
    return result;
  }

  TensorDim1 MatMult(const TensorDim2 &td1, const TensorDim1 &td2){

    // First check the dimension of the matrix
    if(t1->GetDim() != 2 || t2->GetDim() != 1){
      std::cerr << "Can't do the matrix product, one of the tensor is not a matrix or vector" << std::endl;
      exit(1);
    }

    // Then check that size are good for multiplication
    // (i * j) (j) = (i)
    if(t1->GetDimSize(1) !=  t2->GetDimSize(0)){
      std::cerr << "Can't do the matrix product, the matrix and vector sizes are not right" << std::endl;
      exit(1);
    }

    TensorDim1 result(t1->GetDimSize(0));

    for(int i = 0; i < t1->GetDimSize(0); i++)
      for(int j = 0; j < t2->GetDimSize(1); j++)
	result(i) += t1(i,j)*t2(j);
    
    return result;
  }
  
  TensorDim2 CrossProd(const TensorDim1 &t1, const TensorDim1 &t2){
    
    // First check the dimension of the matrix
    if(t1->GetDim() != 2 || t2->GetDim() != 1){
      std::cerr << "Can't do the matrix product, one of the tensor is not a matrix or vector" << std::endl;
      exit(1);
    }

    // Then check that size are good for multiplication
    // (i * j) (j) = (i)
    if(t1->GetDimSize(0) !=  t2->GetDimSize(0)){
      std::cerr << "Can't do the matrix product, the matrix and vector sizes are not right" << std::endl;
      exit(1);
    }
    
    TensorDim2 result(t1->GetDimSize(0));
    
    for(int i = 0; i < t1->GetDimSize(0); i++){
      for(int j = 0; j < t1->GetDimSize(0); j++){
	
      }
    }

    return result;
  }
  
  TComplex DotProd(const TensorDim1 &t1, const TensorDim1 &t2){
    if(t1.Dim != 1 || t2.Dim != 1 || t1.DimSize[0] != t2.DimSize[0]){
      std::cerr << "Can't do the dot product, sure it is a vector of same dimensions?" << std::endl;
      exit(1);
    }
    TensorDim1 result = t1 * t2; 
    return result.SumOver();l
  }
  
  TensorDim3 SlashDirac(){
  }
  
}
