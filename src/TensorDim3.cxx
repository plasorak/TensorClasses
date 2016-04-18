#include "TensorUtils/TensorDim.h"
#define DEBUG
namespace TensorUtils{

  bool TensorDim3::CheckIndex(const unsigned int i, const unsigned int j, const unsigned int k) const{
    return (i < DimSize[0] && j < DimSize[1] && k < DimSize[2]);
  };

  unsigned int TensorDim3:: GetGlobalIndex(const unsigned int i1,
					   const unsigned int i2,
					   const unsigned int i3) const{
    return DimSize[0] * DimSize[1] * i1 + DimSize[1] * i2 + i3;
  };

  TensorDim3::TensorDim3(const TensorDim3& t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(unsigned int i = 0; i < t1.Element.size(); i++)
      this->Element.push_back(t1.Element[i]);
    for(unsigned int i = 0; i < t1.DimSize.size(); i++)
      this->DimSize.push_back(t1.DimSize[i]);
  };

  TensorDim3::TensorDim3(unsigned int SizeDim1, unsigned int SizeDim2, unsigned int SizeDim3, const char * Name){
    this->Name = Name;
    DimSize.clear();
    DimSize.reserve(3);
    DimSize.push_back(SizeDim1);
    DimSize.push_back(SizeDim2);
    DimSize.push_back(SizeDim3);
    Dim = DimSize.size();
    Element.clear();
    Element.reserve(DimSize[0]*DimSize[1]*DimSize[2]);
#ifdef DEBUG
    for(int i = 0; i < Dim; i++)
      std::cout << "Dim[" << i << "] = " << DimSize[i] << std::endl;
#endif
    TComplex Zero(0.,0.);
    for(int i1 = 0; i1 < DimSize[0]; i1++){
      for(int i2 = 0; i2 < DimSize[1]; i2++){
	for(int i3 = 0; i3 < DimSize[2]; i3++){
#ifdef DEBUG
	  std::cout << "setting (" << i1  << ", " << i2 << ", " << i3 << " = " << GetGlobalIndex(i1, i2, i3) << ") to " << Zero << std::endl;
#endif
	  Element.push_back(Zero);
	}
      }
    }
  };

  TensorDim3::TensorDim3(unsigned int SizeDim, const char * Name){ 
    *this = TensorDim3(SizeDim, SizeDim, SizeDim, Name);
  };

  TComplex TensorDim3::At(const unsigned int i, const unsigned int j, const unsigned int k)const{
    if(CheckIndex(i, j, k))
      exit(1);
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";

    return Element[GetGlobalIndex(i, j, k)];

  };

  void TensorDim3::Set(const unsigned int i, const unsigned int j, const unsigned int k, TComplex c){
    if(CheckIndex(i, j, k))
      Element[GetGlobalIndex(i, j, k)] = c;
    else{
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    }
  };

  void TensorDim3::Print() const{
    std::cout << "Tensor Dim3 with name '" << Name.c_str() << "'" << std::endl;
    for(unsigned int i = 0; i < Dim; i++){
      std::cout << "Dimension[" << i << "] size: " << DimSize[i] << std::endl;
    }
    std::cout << "Element[<position0>, <position1>, <position2>]" << std::endl;
    for(unsigned int i = 0; i < DimSize[0]; i++){
      for(unsigned int j = 0; j < DimSize[1]; j++){
	for(unsigned int k = 0; k < DimSize[2]; k++){
	  std::cout << "Element[" << i << ", " << j << ", " << k << "] = " << this->At(i, j, k) << std::endl;
	}
      }
    }
  };

  TComplex& TensorDim3::operator()(const unsigned int i1,
				   const unsigned int i2,
				   const unsigned int i3){
    if(!CheckIndex(i1, i2, i3))
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
      exit(1);
    return Element[GetGlobalIndex(i1, i2, i3)];
  };

}
