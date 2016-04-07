#include "TensorDim3.h"

ClassImp(TensorDim3)

namespace TensorUtils{

  bool TensorDim3::CheckIndex(const unsigned int i, const unsigned int j, const unsigned int k)const{
    return (i < DimSizes[0] && j < DimSizes[1] && k < DimSizes[2]);
  };

  unsigned intTensorDim3:: GetGlobalIndex(const unsigned int i1,
					  const unsigned int i2,
					  const unsigned int i3)const{
    return DimSizes[0] * DimSizes[1] * i1 + DimSizes[1] * i2 + i3;
  };
  
  TensorDim3::TensorDim3(const TensorDim3& t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(unsigned int i = 0; i < t1.Elements.size(); i++)
      this->Elements.push_back(t1.Elements[i]);
    for(unsigned int i = 0; i < t1.DimSizes.size(); i++)
      this->DimSizes.push_back(t1.DimSizes[i]);
  };

  TensorDim3::TensorDim3(){
    TensorDim3(4,4,4);
  };

  TensorDim3::TensorDim3(int SizeDim1, int SizeDim2, int SizeDim3, std::string Name = "none"){
    this->Name = Name;
    DimSizes.clear();
    DimSizes.push_back(SizeDim1);
    DimSizes.push_back(SizeDim2);
    DimSizes.push_back(SizeDim3);
    Elements.clear();
    TComplex Zero(0.,0.);
    for(int i1 = 0; i1 < SizeDim1; i1++){
      std::vector< std::vector< TComplex > > e1;
      for(int i2 = 0; i2 < SizeDim2; i2++){
	std::vector< TComplex > e2;
	for(int i3 = 0; i3 < SizeDim3; i3++)
	  Elements.push_back(Zero);
      }
    }
  };

  TensorDim3::TensorDim3(int SizeDim, std::string Name = "none"){
    TensorDim3(SizeDim, SizeDim, SizeDim, Name);
  };
    
  TComplex TensorDim3::At(const unsigned int i, const unsigned int j, const unsigned int k)const{
    if(CheckIndex(i, j, k))
      exit(1);
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
      
    return Elements[GetGlobalIndex(i, j, k)];
      
  };

  void TensorDim3::Set(const unsigned int i, const unsigned int j, const unsigned int k, TComplex c){
    if(CheckIndex(i, j, k))
      Elements[GetGlobalIndex(i, j, k)] = c;
    else{
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    }
  };
  
  TComplex& TensorDim3::operator()(const unsigned int i1,
				   const unsigned int i2,
				   const unsigned int i3){
    if(!CheckIndex(i1, i2, i3))
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
      exit(1);
    return Elements[GetGlobalIndex(i1, i2, i3)];
  };

  TComplex TensorDim3::operator()(const unsigned int i1,
				  const unsigned int i2,
				  const unsigned int i3) const{
    if(!CheckIndex(i1, i2, i3))
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
      exit(1);
    return Elements[GetGlobalIndex(i1, i2, i3)];
  };
}
