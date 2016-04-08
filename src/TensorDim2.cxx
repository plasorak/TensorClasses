#include "TensorDim2.h"


ClassImp(TensorDim2)

namespace TensorUtils {

  Tensor::TensorDim2(const TensorDim2& t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(unsigned int i = 0; i < t1.Elements.size(); i++)
      this->Elements.push_back(t1.Elements[i]);
    for(unsigned int i = 0; i < t1.DimSizes.size(); i++)
      this->DimSizes.push_back(t1.DimSizes[i]);
  };

  Tensor::TensorDim2(){
    TensorDim2(4,4);
  };
    
  bool Tensor::CheckIndex(const unsigned int i, const unsigned int j) const{
    return (i < DimSizes[0] && j < DimSizes[1]);
  };

  unsigned int Tensor::GetGlobalIndex(const unsigned int i,
				      const unsigned int j) const{
    return i * DimSizes[0] + j;
  };

  Tensor::TensorDim2(int SizeDim1, int SizeDim2, std::string Name = "none"){
    this->Name = Name;
    DimSizes.clear();
    DimSizes.push_back(SizeDim1);
    DimSizes.push_back(SizeDim2);
    Elements.clear();
    TComplex Zero(0.,0.);
    
    for(int i1 = 0; i1 < SizeDim1; i1++)
      for(int i2 = 0; i2 < SizeDim2; i2++)
	Elements.push_back(Zero);
  
  };

  Tensor::TensorDim2(int SizeDim, std::string Name = "none"){
    TensorDim2(SizeDim, SizeDim, Name);
  };
  
  TComplex Tensor::At(const unsigned int i, const unsigned int j)const{
    if(!CheckIndex(i, j))
      exit(1);
    return Elements[GetGlobalIndex(i, j)];
      
  };
  
  void Tensor::Set(const unsigned int i, const unsigned int j, TComplex c){
    if(CheckIndex(i, j))
      Elements[GetGlobalIndex(i, j)] = c;
    else{
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    }
  };


  TComplex& Tensor::operator()(const int i1, const int i2){
    if(!CheckIndex(i1, i2))
      exit(1);
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    return Elements[GetGlobalIndex(i1, i2)];
  };
    
  TComplex  Tensor::operator()(const int i1, const int i2) const{
    if(!CheckIndex(i1, i2))
      exit(1);
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    return Elements[GetGlobalIndex(i1, i2)];
  };
}
