#include "TensorUtils/TensorDim1.h"

//ClassImp(TensorUtils::TensorDim1)

namespace TensorUtils {
  bool TensorDim1::CheckIndex(const unsigned int i) const{
    return (i < DimSizes[0]);
  };

  unsigned int TensorDim1::GetGlobalIndex(const unsigned int i) const{
    return i;
  };

  TensorDim1::TensorDim1(){
    TensorDim1(4);
  };

  TensorDim1::TensorDim1(int SizeDim, std::string Name){
    this->Name = Name;
    DimSizes.clear();
    DimSizes.push_back(SizeDim);

    TComplex Zero(0.,0.);
    for(int i = 0; i< SizeDim; i++)
      Elements.push_back(Zero);
  };

  TComplex TensorDim1::At(const unsigned int i) const{
    if(!CheckIndex(i))
      exit(1);
    return Elements[GetGlobalIndex(i)];

  };

  void TensorDim1::Set(const unsigned int i, TComplex c){
    if(CheckIndex(i))
      Elements[GetGlobalIndex(i)] = c;

    else{
      exit(1);
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    }
  };

  TComplex& TensorDim1::operator()(const unsigned int i){
    if(!CheckIndex(i))
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
      exit(1);
    return Elements[GetGlobalIndex(i)];
  };

  TComplex  TensorDim1::operator()(const unsigned int i) const{
    if(!CheckIndex(i))
      exit(1);
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";

    return Elements[GetGlobalIndex(i)];
  };

  TensorDim1::TensorDim1(const TensorDim1& t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(unsigned int i = 0; i < t1.Elements.size(); i++)
      this->Elements.push_back(t1.Elements[i]);
    for(unsigned int i = 0; i < t1.DimSizes.size(); i++)
      this->DimSizes.push_back(t1.DimSizes[i]);
  }
}
