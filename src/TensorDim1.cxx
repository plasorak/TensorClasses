#include "TensorUtils/TensorDim.h"

namespace TensorUtils{

  bool TensorDim1::CheckIndex(const unsigned int i) const{
    return (i < DimSize[0]);
  };

  unsigned int TensorDim1::GetGlobalIndex(const unsigned int i) const{
    return i;
  };

  TensorDim1::TensorDim1(int SizeDim, std::string Name){
    this->Name = Name;
    DimSize.clear();
    DimSize.reserve(1);
    DimSize.push_back(SizeDim);
    Dim = DimSize.size();
    Element.clear();
    Element.reserve(DimSize[0]);

    TComplex Zero(0.,0.);
    for(int i = 0; i < DimSize[0]; i++){
      std::cout << "setting (" << i  << ") to " << Zero << std::endl;      
      Element.push_back(Zero);
    }
  };

  TensorDim1::TensorDim1(const TensorDim1& t1){
    this->Name = t1.Name;
    this->Dim = t1.Dim;
    for(unsigned int i = 0; i < t1.Element.size(); i++)
      this->Element.push_back(t1.Element[i]);
    for(unsigned int i = 0; i < t1.DimSize.size(); i++)
      this->DimSize.push_back(t1.DimSize[i]);
  };

  TComplex TensorDim1::At(const unsigned int i) const{
    if(!CheckIndex(i))
      exit(1);
    return Element[GetGlobalIndex(i)];

  };

  void TensorDim1::Set(const unsigned int i, TComplex c){
    if(CheckIndex(i))
      Element[GetGlobalIndex(i)] = c;

    else{
      exit(1);
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    }
  };

  void TensorDim1::Print() const{
    std::cout << "TensorDim"<< this->DimSize.size() << " with name '" << Name.c_str() << "'" << std::endl;
    std::cout << "Dimension(" << 0 << ") size: " << DimSize[0] << std::endl;
    std::cout << "Element(<position> = <globalposition>)" << std::endl;
    for(unsigned int j = 0; j < DimSize[0]; j++){
      std::cout << "Element(" << j << " = " << this->GetGlobalIndex(j) << ") = " << this->At(j) << std::endl;
    }
  };

  TComplex& TensorDim1::operator()(const unsigned int i){
    if(!CheckIndex(i))
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
      exit(1);
    return Element[GetGlobalIndex(i)];
  };

  TComplex TensorDim1::operator()(const unsigned int i) const{
    if(!CheckIndex(i))
      exit(1);
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    return Element[GetGlobalIndex(i)];
  };

  TComplex operator*(const TensorDim1 &t1, const TensorDim1 &t2){
    if(t1.DimSize[0] != t2.DimSize[0]){
      std::cerr << "Dot product doesn't work is the vectors don't have the same size!" << std::endl;
      exit(1);
    }
    TComplex c(0,0);
    for(unsigned int i = 0; i < t1.Element.size(); i++)
      c += t1(i) * t2(i);
    return c; 
  };

}
