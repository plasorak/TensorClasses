#include "NuGamma/TensorDim4.h"

ClassImp(TensorDim4)

bool TensorDim4::CheckIndex(const unsigned int i, const unsigned int j, const unsigned int k, const unsigned int l) const{
  if(i < DimSizes[0] && j < DimSizes[1] && k < DimSizes[2] && l < DimSizes[3])
    return true;
  return false;
};

unsigned int TensorDim4::GetGlobalIndex(const unsigned int i1, const unsigned int i2, const unsigned int i3, const unsigned int i4) const{
  return (DimSizes[0] * DimSizes[1] * DimSizes[2] * i1 +
	  DimSizes[1] * DimSizes[2] * i2 +
	  DimSizes[2] * i3 +
	  i4);
};

TensorDim4::TensorDim4(const TensorDim4& t1){
  this->Name = t1.Name;
  this->Dim  = t1.Dim;
  for(unsigned int i = 0; i < t1.Elements.size(); i++)
    this->Elements.push_back(t1.Elements[i]);
  for(unsigned int i = 0; i < t1.DimSizes.size(); i++)
    this->DimSizes.push_back(t1.DimSizes[i]);
};


TensorDim4::TensorDim4(){
  TensorDim4(4,4,4,4);
};
    
TensorDim4::TensorDim4(int SizeDim1, int SizeDim2, int SizeDim3, int SizeDim4, std::string Name = "none"){
  this->Name = Name;
  DimSizes.clear();
  DimSizes.push_back(SizeDim1);
  DimSizes.push_back(SizeDim2);
  DimSizes.push_back(SizeDim3);
  DimSizes.push_back(SizeDim4);
  Elements.clear();
  TComplex Zero(0.,0.);
  for(int i1 = 0; i1 < SizeDim1; i1++){
    std::vector< std::vector< std::vector< TComplex > > > e1;
    for(int i2 = 0; i2 < SizeDim2; i2++){
      std::vector< std::vector< TComplex > > e2;
      for(int i3 = 0; i3 < SizeDim3; i3++){
	std::vector< TComplex > e3;
	for(int i4 = 0; i4 < SizeDim4; i4++)
	  Elements.push_back(Zero);
      }
    }
  }
};

TensorDim4::TensorDim4(int SizeDim, std::string Name = "none"){
  TensorDim4(SizeDim, SizeDim, SizeDim, SizeDim, Name);
};

TComplex TensorDim4::At(const unsigned int i,
			const unsigned int j,
			const unsigned int k,
			const unsigned int l) const{
  if(!CheckIndex(i, j, k, l))
    exit(1);
	
  return Elements[GetGlobalIndex(i, j, k, l)];
};
  
void TensorDim4::Set(int i, int j, int k, int l, TComplex c){
  if(CheckIndex(i, j, k, l))
    Elements[GetGlobalIndex(i, j, k, l)] = c;
  else{
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
  }
};
  
TComplex& TensorDim4::operator()(const unsigned int i1,
				 const unsigned int i2,
				 const unsigned int i3,
				 const unsigned int i4){
  if(!CheckIndex(i1, i2, i3, i4))
    exit(1);
  //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
      
  return Elements[GetGlobalIndex(i1, i2, i3, i4)];
};
  
TComplex TensorDim4::operator()(const unsigned int i1,
				const unsigned int i2,
				const unsigned int i3,
				const unsigned int i4) const{
  if(!CheckIndex(i1, i2, i3, i4))
    exit(1);
  //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
      
  return Elements[GetGlobalIndex(i1, i2, i3, i4)];
};
