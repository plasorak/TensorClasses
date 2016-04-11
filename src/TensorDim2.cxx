#include "TensorUtils/TensorDim2.h"
#include "TensorUtils/TensorDim1.h"

namespace TensorUtils{

  TensorDim2::TensorDim2(const TensorDim2& t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(unsigned int i = 0; i < t1.Elements.size(); i++)
      this->Elements.push_back(t1.Elements[i]);
    for(unsigned int i = 0; i < t1.DimSizes.size(); i++)
      this->DimSizes.push_back(t1.DimSizes[i]);
  };


  bool TensorDim2::CheckIndex(const unsigned int i, const unsigned int j) const{
    return (i < DimSizes[0] && j < DimSizes[1]);
  };

  unsigned int TensorDim2::GetGlobalIndex(const unsigned int i,
					  const unsigned int j) const{
    return i * DimSizes[0] + j;
  };

  TensorDim2::TensorDim2(int SizeDim1, int SizeDim2, std::string Name){
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

  TensorDim2::TensorDim2(int SizeDim, std::string Name){
    TensorDim2(SizeDim, SizeDim, Name);
  };

  TComplex TensorDim2::At(const unsigned int i, const unsigned int j)const{
    if(!CheckIndex(i, j))
      exit(1);
    return Elements[GetGlobalIndex(i, j)];

  };

  void TensorDim2::Set(const unsigned int i, const unsigned int j, TComplex c){
    if(CheckIndex(i, j))
      Elements[GetGlobalIndex(i, j)] = c;
    else{
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    }
  };


  TComplex& TensorDim2::operator()(const int i1, const int i2){
    if(!CheckIndex(i1, i2))
      exit(1);
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    return Elements[GetGlobalIndex(i1, i2)];
  };

  TComplex  TensorDim2::operator()(const int i1, const int i2) const{
    if(!CheckIndex(i1, i2))
      exit(1);
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    return Elements[GetGlobalIndex(i1, i2)];
  };

}
