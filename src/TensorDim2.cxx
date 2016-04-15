#include "TensorUtils/TensorDim.h"
#define DEBUG
namespace TensorUtils{

  bool TensorDim2::CheckIndex(const unsigned int i, const unsigned int j) const{
    return (i < DimSize[0] && j < DimSize[1]);
  };

  unsigned int TensorDim2::GetGlobalIndex(const unsigned int i,
					  const unsigned int j) const{
    return i * DimSize[0] + j;
  };

  TensorDim2::TensorDim2(int SizeDim1, int SizeDim2, std::string Name){
    this->Name = Name;
    //this->DimSize.clear();
    this->DimSize.reserve(2);
    this->DimSize.push_back(SizeDim1);
    this->DimSize.push_back(SizeDim2);
    this->Dim = DimSize.size();
    std::cout << "Dim1212 " << this->Dim << std::endl;
    //this->Element.clear();
    this->Element.reserve(DimSize[0]*DimSize[1]);

    TComplex Zero(0.,0.);
#ifdef DEBUG
    for(int i = 0; i < Dim; i++)
      std::cout << "Dim[" << i << "] = " << this->DimSize[i] << std::endl;
#endif

    for(int i1 = 0; i1 < this->DimSize[0]; i1++){
      for(int i2 = 0; i2 < this->DimSize[1]; i2++){
	this->Element.push_back(Zero);

#ifdef DEBUG
	std::cout << "setting (" << i1  << ", " << i2 << " = " << this->GetGlobalIndex(i1, i2) << ") to " << this->Element[this->GetGlobalIndex(i1, i2)] << std::endl;
#endif
      }
    }
  };
  
  TensorDim2::TensorDim2(const TensorDim2& t1){
    this->Name = t1.Name;
    this->Dim  = t1.Dim;
    for(unsigned int i = 0; i < t1.Element.size(); i++)
      this->Element.push_back(t1.Element[i]);
    for(unsigned int i = 0; i < t1.DimSize.size(); i++)
      this->DimSize.push_back(t1.DimSize[i]);
  };

  TensorDim2::TensorDim2(int SizeDim, std::string Name){
    std::cout << "blabla"  <<std::endl;
    *this = TensorDim2(SizeDim, SizeDim, Name);
  };

  TComplex TensorDim2::At(const unsigned int i, const unsigned int j) const{
    if(!CheckIndex(i, j))
      exit(1);
    return Element[GetGlobalIndex(i, j)];

  };

  void TensorDim2::Set(const unsigned int i, const unsigned int j, TComplex c){
    if(CheckIndex(i, j))
      Element[GetGlobalIndex(i, j)] = c;
   
    else{
      exit(1);
      //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    }
  };

  void TensorDim2::Print() const{
    std::cout << "" << std::endl;
    std::cout << "TensorDim" << this->DimSize.size() << " with name '" << this->Name.c_str() << "'" << std::endl;
    for(unsigned int i = 0; i < Dim; i++){
      std::cout << "Dimension(" << i << ") size: " << this->DimSize[i] << std::endl;
    }
    std::cout << "Element(<position0>, <position1> = <globalposition>)" << std::endl;
    for(unsigned int i = 0; i < this->DimSize[0]; i++){
      for(unsigned int j = 0; j < this->DimSize[1]; j++){
	std::cout << "Element(" << i << ", " << j << " = " << this->GetGlobalIndex(i, j) << ") = " << this->At(i, j) << std::endl;
      }
    }
  };
  
  TComplex& TensorDim2::operator()(const int i1, const int i2){
    if(!CheckIndex(i1, i2))
      exit(1);
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    return Element[GetGlobalIndex(i1, i2)];
  };

  TComplex  TensorDim2::operator()(const int i1, const int i2) const{
    if(!CheckIndex(i1, i2))
      exit(1);
    //LOG("TensorDim", pFATAL) << "The tensor dimensions don't match!";
    return Element[GetGlobalIndex(i1, i2)];
  };

}
