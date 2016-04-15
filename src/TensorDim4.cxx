#include "TensorUtils/TensorDim.h"

namespace TensorUtils{

  bool TensorDim4::CheckIndex(const unsigned int i, const unsigned int j, const unsigned int k, const unsigned int l) const{
    if(i < DimSize[0] && j < DimSize[1] && k < DimSize[2] && l < DimSize[3])
      return true;
    return false;
  };

  unsigned int TensorDim4::GetGlobalIndex(const unsigned int i1, const unsigned int i2, const unsigned int i3, const unsigned int i4) const{
    return (DimSize[0] * DimSize[1] * DimSize[2] * i1 +
	    DimSize[1] * DimSize[2] * i2 +
	    DimSize[2] * i3 +
	    i4);
  };

  TensorDim4::TensorDim4(const TensorDim4& t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(unsigned int i = 0; i < t1.Element.size(); i++)
      this->Element.push_back(t1.Element[i]);
    for(unsigned int i = 0; i < t1.DimSize.size(); i++)
      this->DimSize.push_back(t1.DimSize[i]);
  };


  TensorDim4::TensorDim4(int SizeDim1, int SizeDim2, int SizeDim3, int SizeDim4, std::string Name){
    this->Name = Name;
    DimSize.clear();
    DimSize.reserve(4);
    DimSize.push_back(SizeDim1);
    DimSize.push_back(SizeDim2);
    DimSize.push_back(SizeDim3);
    DimSize.push_back(SizeDim4);
    Element.clear();
    Element.reserve(DimSize[0]*DimSize[1]*DimSize[2]*DimSize[3]);
    TComplex Zero(0.,0.);
    for(int i1 = 0; i1 < SizeDim1; i1++){
      for(int i2 = 0; i2 < SizeDim2; i2++){
	for(int i3 = 0; i3 < SizeDim3; i3++){
	  for(int i4 = 0; i4 < SizeDim4; i4++)
	    Element.push_back(Zero);
	}
      }
    }
  };
  


  TensorDim4::TensorDim4(int SizeDim, std::string Name){
    *this = TensorDim4(SizeDim, SizeDim, SizeDim, SizeDim, Name);
  };

  TComplex TensorDim4::At(const unsigned int i,
			  const unsigned int j,
			  const unsigned int k,
			  const unsigned int l) const{
    if(!CheckIndex(i, j, k, l))
      exit(1);

    return Element[GetGlobalIndex(i, j, k, l)];
  };

  void TensorDim4::Set(int i, int j, int k, int l, TComplex c){
    if(CheckIndex(i, j, k, l))
      Element[GetGlobalIndex(i, j, k, l)] = c;
    else{
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    }
  };

  void TensorDim4::Print() const{
    std::cout << "Tensor Dim4 with name '" << Name.c_str() << "'" << std::endl;
    for(unsigned int i = 0; i < Dim; i++){
      std::cout << "Dimension[" << i << "] size: " << DimSize[i] << std::endl;
      std::cout << "Element[<dimension>, <position>]" << std::endl;
      for(unsigned int j = 0; j < DimSize[i]; j++){
	std::cout << "Element[" << i << ", " << j << "] = " << this->At(i, j, 0, 0) << std::endl;
      }
    }
  };


  TComplex& TensorDim4::operator()(const unsigned int i1,
				   const unsigned int i2,
				   const unsigned int i3,
				   const unsigned int i4){
    if(!CheckIndex(i1, i2, i3, i4))
      exit(1);
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";

    return Element[GetGlobalIndex(i1, i2, i3, i4)];
  };

  TComplex TensorDim4::operator()(const unsigned int i1,
				  const unsigned int i2,
				  const unsigned int i3,
				  const unsigned int i4) const{
    if(!CheckIndex(i1, i2, i3, i4))
      exit(1);
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";

    return Element[GetGlobalIndex(i1, i2, i3, i4)];
  };

}
