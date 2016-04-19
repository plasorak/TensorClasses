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


  int Tensor::GetDim() const{

    this->AssertGoodDim(this->Dim);
    return Dim;
  };

  int Tensor::GetDimSize(const int i) const{
    
    this->AssertGoodDim(this->Dim);

    if(i >= 0 && i < Dim)
      return DimSize[i];
    else{
      std::cout << "Trying to access the size of dimension which doesn't exist in the tensor."<<  std::endl;
      std::cout << "Index = " << i << std::endl;
      std::cout << "DimSize.size() = " << DimSize.size() << std::endl;
      std::cout << "DimSize[" << i << "] = " << DimSize[i] << std::endl;
      std::cout << "Program will exit" << std::endl;
      exit(1);
    }
  };

  TComplex Tensor::SumOver() const{
    TComplex Zero(0,0);
    for(int i = 0; i < Element.size(); i++)
      Zero = Zero + Element[i];
    return Zero;
  }
  

  Tensor& Tensor::operator=(const Tensor &t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(int i = 0; i < t1.Element.size(); i++)
      this->Element[i] = t1.Element[i];
    for(int i = 0; i < t1.DimSize.size(); i++)
      this->DimSize[i] = t1.DimSize[i];
    return *this;
  };

  Tensor::Tensor(const Tensor& t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(int i = 0; i < t1.Element.size(); i++)
      this->Element.push_back(t1.Element[i]);
    for(int i = 0; i < t1.DimSize.size(); i++)
      this->DimSize.push_back(t1.DimSize[i]);
  };

  TComplex& Tensor::operator()(const int GlobalIndex){
    return Element[GlobalIndex];
  };

  TComplex  Tensor::operator()(const int GlobalIndex) const{
    return Element[GlobalIndex];
  };

  bool Tensor::GoodDim(int iDim) const{
    if(this->Dim != DimSize.size()) { return false; }
    if(this->Dim != iDim) { return false; }
    return true;
  };

  // Check that the tensor (this) has the dimension size DimSize in the dimension Dim (eugh)
  bool Tensor::GoodDim(int iDim, int DimSize) const{
    if(this->Dim != this->DimSize.size()) { return false; }
    if(this->Dim <= iDim) { return false; }
    if(this->DimSize[iDim] != DimSize) { return false; }
    return true;
  };

  // Check that both tensor (this and t1) have same dimension sizes
  bool Tensor::GoodDim(const Tensor &t1) const{
    this->GoodDim(t1.GetDim());
    t1.GoodDim(this->GetDim());
    for(int i = 0; i < this->GetDim(); i++){
      this->GoodDim(i, t1.GetDimSize(i));
    }
    return true;
  };

  // Check that the tensor (this) has the dimension Dim
  bool Tensor::AssertGoodDim(int iDim) const{
    if(this->Dim != DimSize.size()){
      std::cout << "bool Tensor::AssertGoodDim(int iDim) const" << std::endl;
      std::cout << "Dimension of the tensor has changed!" << std::endl;
      std::cout << "Dim            = " << Dim << std::endl;
      std::cout << "DimSize.size() = " << DimSize.size() << std::endl;
      std::cout << "Program will exit" << std::endl;
      exit(1);
    }
    if(this->Dim != iDim){
      std::cout << "bool Tensor::AssertGoodDim(int iDim) const" << std::endl;
      std::cout << "The number of dimensions don't match!" << std::endl;
      std::cout << "Dim       = " << iDim << std::endl;
      std::cout << "this->Dim = " << this->Dim << std::endl;
      std::cout << "Program will exit" << std::endl;
      exit(1);
    }
    return true;
    
  };

  // Check that the tensor (this) has the dimension size DimSize in the dimension Dim (eugh)
  bool Tensor::AssertGoodDim(int iDim, int DimSize) const{

    if(this->Dim != this->DimSize.size()){
      std::cout << "bool Tensor::AssertGoodDim(int iDim, int DimSize) const" << std::endl;
      std::cout << "Dimension of the tensor has changed!" << std::endl;
      std::cout << "this->Dim            = " << this->Dim << std::endl;
      std::cout << "this->DimSize.size() = " << this->DimSize.size() << std::endl;
      std::cout << "Program will exit" << std::endl;
      exit(1);
    }
    if(this->Dim <= iDim){
      std::cout << "bool Tensor::AssertGoodDim(int iDim, int DimSize) const" << std::endl;
      std::cout << "The number of dimensions don't match!" << std::endl;
      std::cout << "Dim       = " << iDim << std::endl;
      std::cout << "this->Dim = " << this->Dim << std::endl;
      std::cout << "Program will exit" << std::endl;
      exit(1);
    }
    if(this->DimSize[iDim] != DimSize){
      std::cout << "bool Tensor::AssertGoodDim(int iDim, int DimSize) const" << std::endl;
      std::cout << "The dimension size of dimension " << iDim  << " don't match!" << std::endl;
      std::cout << "DimSize   = " << iDim << std::endl;
      std::cout << "this->DimSize[" << iDim << "] = " << this->DimSize[iDim] << std::endl;
      std::cout << "Program will exit" << std::endl;
      exit(1);
    }
      
    return true;

  };

  // Check that both tensor (this and t1) have same dimension sizes
  bool Tensor::AssertGoodDim(const Tensor &t1) const{
    this->AssertGoodDim(t1.GetDim());
    t1.AssertGoodDim(this->GetDim());

    for(int i = 0; i < this->GetDim(); i++){
      this->AssertGoodDim(i, t1.GetDimSize(i));
    }
    return true;
  };

  void Tensor::Minus(){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = - this->Element[i];
  };

  void Tensor::OneOverElementWise(){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = 1. / this->Element[i];
  };

  void Tensor::Real(){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i].Re();
  };

  void Tensor::Imaginary(){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i].Im();
  };

  void Tensor::Abs(){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = TComplex::Abs(this->Element[i]);
  };


  // Scalar operations
  void Tensor::Add(const TComplex c){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] + c;
  };
  
  void Tensor::Subtract(const TComplex c){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] - c;
  };

  void Tensor::Multiply(const TComplex c){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] * c;
  };

  void Tensor::Divide(const TComplex c){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] / c;
  };


  void Tensor::Add(const double d){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] + d;
  };

  void Tensor::Subtract(const double d){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] - d;
  };

  void Tensor::Multiply(const double d){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] * d;
  };

  void Tensor::Divide(const double d){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] / d;
  };

  // Entry by entry operations
  void Tensor::Add(const Tensor &t1){

    // First check the dimension/sizes of the tensor
    this->AssertGoodDim(t1);

    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] + t1.Element[i];

  };

  void Tensor::Subtract(const Tensor &t1){

    // First check the dimension/sizes of the tensor
    this->AssertGoodDim(t1);

    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] - t1.Element[i];
  };

  void Tensor::MultiplyElementWise(const Tensor &t1){

    // First check the dimension/sizes of the tensor
    this->AssertGoodDim(t1);
  
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] * t1.Element[i];
  };

  void Tensor::DivideElementWise(const Tensor &t1){

    // First check the dimension/sizes of the tensor
    this->AssertGoodDim(t1);

    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] / t1.Element[i];
  };

  void Tensor::Add(const int c){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] + (double)c;
  };

  void Tensor::Subtract(const int c){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] - (double)c;
  };

  void Tensor::Multiply(const int c){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] * (double)c;
  };

  void Tensor::Divide(const int c){
    for(int i = 0; i < this->Element.size(); i++)
      this->Element[i] = this->Element[i] / (double)c;
  };

  bool Tensor::IsEqual(double d) const{
    for(int i = 0; i < this->Element.size(); i++)
      if(TComplex::Abs(this->Element[i]) != d)
	return false;
    return true;
  };

  // Boolean operations
  bool Tensor::IsEqual(const Tensor &t1) const{

    // First check the dimension/sizes of the tensor
    this->GoodDim(t1);

    bool flag = true;
    int i = 0;
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

    // First dimensions the dimension/sizes of the tensor
    this->GoodDim(t1);

    bool flag = true;
    int i = 0;

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
    for(int i = 0; i < this->Element.size(); i++)
      if(TMath::Abs(d) <= TComplex::Abs(this->Element[i]))
	return false;
    return true;
  };

  bool Tensor::IsSmallerOrEqual(double d) const{
    for(int i = 0; i < this->Element.size(); i++)
      if(TMath::Abs(d) >= TComplex::Abs(this->Element[i]))
	return false;
    return true;
  };

  bool Tensor::IsBigger (double d) const{
    for(int i = 0; i < this->Element.size(); i++)
      if(TMath::Abs(d) < TComplex::Abs(this->Element[i]))
	return false;
    return true;
  };

  bool Tensor::IsSmaller (double d) const{
    for(int i = 0; i < this->Element.size(); i++)
      if(TMath::Abs(d) > TComplex::Abs(this->Element[i]))
	return false;
    return true;
  };

  bool Tensor::IsEqual(TComplex d) const{
    for(int i = 0; i < this->Element.size(); i++)
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
