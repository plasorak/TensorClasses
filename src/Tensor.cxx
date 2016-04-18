#include "TensorUtils/Tensor.h"
#include "TensorUtils/TensorDim.h"

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

  void Tensor::Minus(){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = - this->Element[i];
  };

  void Tensor::OneOverElementWise(){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = 1. / this->Element[i];
  };

  void Tensor::Real(){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i].Re();
  };

  void Tensor::Imaginary(){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i].Im();
  };

  void Tensor::Abs(){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = TComplex::Abs(this->Element[i]);
  };


  // Scalar operations
  void Tensor::Add(const TComplex c){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] + c;
  };
  
  void Tensor::Subtract(const TComplex c){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] - c;
  };

  void Tensor::Multiply(const TComplex c){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] * c;
  };

  void Tensor::Divide(const TComplex c){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] / c;
  };


  void Tensor::Add(const double d){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] + d;
  };

  void Tensor::Subtract(const double d){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] - d;
  };

  void Tensor::Multiply(const double d){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] * d;
  };

  void Tensor::Divide(const double d){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] / d;
  };

  // Entry by entry operations
  void Tensor::Add(const Tensor &t1){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] + t1.Element[i];
  };

  void Tensor::Subtract(const Tensor &t1){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] - t1.Element[i];
  };

  void Tensor::MultiplyElementWise(const Tensor &t1){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] * t1.Element[i];
  };

  void Tensor::DivideElementWise(const Tensor &t1){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] / t1.Element[i];
  };

  void Tensor::Add(const int c){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] + (double)c;
  };

  void Tensor::Subtract(const int c){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] - (double)c;
  };

  void Tensor::Multiply(const int c){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] * (double)c;
  };

  void Tensor::Divide(const int c){
    for(unsigned int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] / (double)c;
  };

  bool Tensor::IsEqual(double d) const{
    for(unsigned int i = 0; i < this->Element.size(); i++)
      if(TComplex::Abs(this->Element[i]) != d)
	return false;
    return true;
  };

  // Boolean operations
  bool Tensor::IsEqual(const Tensor &t1) const{

    // First chekc the rank of the tensor
    if(this->Dim != t1.Dim)
      return false;

    bool flag = true;
    unsigned int i = 0;

    // Then check the number of element for each dim
    while(flag && i < t1.DimSize.size()){
      if(this->DimSize[i] != t1.DimSize[i])
	flag = false;
    }
    if(!flag)
      return flag;

    flag = true;
    i = 0;
    // Then check the element by element
    while(flag && i < t1.Element.size()){
      if(this->Element[i].Re() != t1.Element[i].Re() || this->Element[i].Im() != t1.Element[i].Im())
	flag = false;
    }
    return flag;
  };

  bool Tensor::IsDifferent(const Tensor &t1) const{
    return !IsEqual(t1);
  };

  bool Tensor::IsBiggerOrEqual(const Tensor &t1) const{

    // First chekc the rank of the tensor
    if(this->Dim != t1.Dim)
      return false;

    bool flag = true;
    unsigned int i = 0;

    // Then check the number of element for each dim
    while(flag && i < t1.DimSize.size()){
      if(this->DimSize[i] != t1.DimSize[i])
	flag = false;
    }
    if(!flag)
      return flag;

    flag = true;
    i = 0;
    // Then check the element by element
    while(flag && i < t1.Element.size()){
      if(TComplex::Abs(this->Element[i]) <= TComplex::Abs(t1.Element[i]))
	flag = false;
    }
    return flag;
  };

  bool Tensor::IsSmaller(const Tensor &t1) const{
    return !IsBiggerOrEqual(t1);
  };
  
  bool Tensor::IsSmallerOrEqual(const Tensor &t1) const{
    return IsSmaller(t1) || IsEqual(t1);
  };
  
  bool Tensor::IsBigger(const Tensor &t1) const{
    return !IsSmallerOrEqual(t1);
  };
  
  bool Tensor::IsDifferent(double d) const{
    return !IsEqual(d);
  };

  bool Tensor::IsBiggerOrEqual(double d) const{
    for(unsigned int i = 0; i < this->Element.size(); i++)
      if(TMath::Abs(d) <= TComplex::Abs(this->Element[i]))
	return false;
    return true;
  };

  bool Tensor::IsSmallerOrEqual(double d) const{
    for(unsigned int i = 0; i < this->Element.size(); i++)
      if(TMath::Abs(d) >= TComplex::Abs(this->Element[i]))
	return false;
    return true;
  };

  bool Tensor::IsBigger (double d) const{
    for(unsigned int i = 0; i < this->Element.size(); i++)
      if(TMath::Abs(d) < TComplex::Abs(this->Element[i]))
	return false;
    return true;
  };

  bool Tensor::IsSmaller (double d) const{
    for(unsigned int i = 0; i < this->Element.size(); i++)
      if(TMath::Abs(d) > TComplex::Abs(this->Element[i]))
	return false;
    return true;
  };

  bool Tensor::IsEqual(TComplex d) const{
    for(unsigned int i = 0; i < this->Element.size(); i++)
      if(this->Element[i].Re() == d.Re() && this->Element[i].Im() == d.Im())
	return false;
    return true;
  };

  bool Tensor::IsDifferent(TComplex d) const{
    return !IsEqual(d);
  };

  bool Tensor::IsBiggerOrEqual(TComplex d) const{
    return IsBiggerOrEqual(TComplex::Abs(d));
  };

  bool Tensor::IsSmallerOrEqual(TComplex d) const{
    return IsSmallerOrEqual(TComplex::Abs(d));
  };

  bool Tensor::IsBigger (TComplex d) const{
    return IsBigger(TComplex::Abs(d));
  };

  bool Tensor::IsSmaller (TComplex d) const{
    return IsSmaller(TComplex::Abs(d));
  };

}
