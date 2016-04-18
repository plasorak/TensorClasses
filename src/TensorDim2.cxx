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

  TensorDim2::TensorDim2(const char * Name, unsigned int SizeDim1, unsigned int SizeDim2){
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
    if(t1.Dim != 2){
      std::cerr << "The tensor is not of dimension 2!" << std::endl;
      exit(1);	
    }
    this->Dim = t1.Dim;
    for(unsigned int i = 0; i < t1.Element.size(); i++)
      this->Element.push_back(t1.Element[i]);
    for(unsigned int i = 0; i < t1.DimSize.size(); i++)
      this->DimSize.push_back(t1.DimSize[i]);
  };

  TensorDim2::TensorDim2(const char * Name, unsigned int SizeDim){
    this->Name = Name;
    //this->DimSize.clear();
    this->DimSize.reserve(2);
    this->DimSize.push_back(SizeDim);
    this->DimSize.push_back(SizeDim);
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
    std::cout << "TensorDim" << this->DimSize.size() << " with name '" << this->Name << "'" << std::endl;
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


  TensorDim2 Real(const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.Real();
    return t;
  };

  TensorDim2 Imaginary(const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.Imaginary();
    return t;
  };

  TensorDim2 Abs(const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.Abs();
    return t;
  };
  
  TensorDim2 operator+(const int c, const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim2 operator-(const int c, const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.Minus();
    t.Add(c);
    return t;
  };
  TensorDim2 operator*(const int c, const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim2 operator/(const int c, const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.OneOverElementWise();
    t.Multiply(c);
    return t;
  };

  TensorDim2 operator+(const TensorDim2 &t1, const int c){
    TensorDim2 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim2 operator-(const TensorDim2 &t1, const int c){
    TensorDim2 t(t1);
    t.Subtract(c);
    return t;
  };
  TensorDim2 operator*(const TensorDim2 &t1, const int c){
    TensorDim2 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim2 operator/(const TensorDim2 &t1, const int c){
    TensorDim2 t(t1);
    t.Divide(c);
    return t;
  };

  TensorDim2 operator+(TComplex c, const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim2 operator-(TComplex c, const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.Minus();
    t.Add(c);
    return t;
  };
  TensorDim2 operator*(TComplex c, const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim2 operator/(TComplex c, const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.OneOverElementWise();
    t.Multiply(c);
    return t;
  };

  TensorDim2 operator+(const TensorDim2 &t1, TComplex c){
    TensorDim2 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim2 operator-(const TensorDim2 &t1, TComplex c){
    TensorDim2 t(t1);
    t.Subtract(c);
    return t;
  };
  TensorDim2 operator*(const TensorDim2 &t1, TComplex c){
    TensorDim2 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim2 operator/(const TensorDim2 &t1, TComplex c){
    TensorDim2 t(t1);
    t.Divide(c);
    return t;
  };

  TensorDim2 operator+(double c, const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim2 operator-(double c, const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.Minus();
    t.Add(c);
    return t;
  };
  TensorDim2 operator*(double c, const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim2 operator/(double c, const TensorDim2 &t1){
    TensorDim2 t(t1);
    t.OneOverElementWise();
    t.Multiply(c);
    return t;
  };

  TensorDim2 operator+(const TensorDim2 &t1, double c){
    TensorDim2 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim2 operator-(const TensorDim2 &t1, double c){
    TensorDim2 t(t1);
    t.Subtract(c);
    return t;
  };
  TensorDim2 operator*(const TensorDim2 &t1, double c){
    TensorDim2 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim2 operator/(const TensorDim2 &t1, double c){
    TensorDim2 t(t1);
    t.Divide(c);
    return t;
  };

  TensorDim2 operator+(const TensorDim2 &t1, const TensorDim2 &t2){
    TensorDim2 t(t1);
    t.Add(t2);
    return t;
  };

  TensorDim2 operator-(const TensorDim2 &t1, const TensorDim2 &t2){
    TensorDim2 t(t1);
    t.Subtract(t2);
    return t;
  };

  TensorDim2 operator*(const TensorDim2 &t1, const TensorDim2 &t2){

    // First check the dimension of the matrix
    if(t1.GetDim() != 2 || t2.GetDim() != 2){
      std::cerr << "Can't do the matrix product, one of the tensor is not a matrix or vector" << std::endl;
      exit(1);
    }

    // Then check that size are good for multiplication
    // (i * j) (j * k) = (i * k)
    if(t1.GetDimSize(1) !=  t2.GetDimSize(0)){
      std::cerr << "Can't do the matrix product, the matrix sizes are not right" << std::endl;
      exit(1);
    }
    char* resultName;
    strcpy(resultName, t1.GetName());
    strcat(resultName, t2.GetName());

    TensorDim2 result(resultName, t1.GetDimSize(0), t2.GetDimSize(1));

    for(int i = 0; i < t1.GetDimSize(0); i++)
      for(int j = 0; j < t2.GetDimSize(1); j++)
	for(int k = 0; k < t1.GetDimSize(1); k++)
	  result(i,j) += t1(i,k)*t2(k,j);
    
    return result;
  };

  bool operator==(const TensorDim2 &t1, const TensorDim2 &t2){ return t1.IsEqual(t2);          };
  bool operator!=(const TensorDim2 &t1, const TensorDim2 &t2){ return t1.IsDifferent(t2);      };
  bool operator>=(const TensorDim2 &t1, const TensorDim2 &t2){ return t1.IsBiggerOrEqual(t2);  };
  bool operator<=(const TensorDim2 &t1, const TensorDim2 &t2){ return t1.IsSmallerOrEqual(t2); };
  bool operator> (const TensorDim2 &t1, const TensorDim2 &t2){ return t1.IsBigger(t2);         };
  bool operator< (const TensorDim2 &t1, const TensorDim2 &t2){ return t1.IsSmaller(t2);        };

  bool operator==(double d, const TensorDim2 &t1){ return t1.IsEqual(d);          };
  bool operator!=(double d, const TensorDim2 &t1){ return t1.IsDifferent(d);      };
  bool operator>=(double d, const TensorDim2 &t1){ return t1.IsSmallerOrEqual(d); };
  bool operator<=(double d, const TensorDim2 &t1){ return t1.IsBiggerOrEqual(d);  };
  bool operator> (double d, const TensorDim2 &t1){ return t1.IsSmaller(d);        };
  bool operator< (double d, const TensorDim2 &t1){ return t1.IsBigger(d);         };

  bool operator==(const TensorDim2 &t1, double d){ return t1.IsEqual(d);          };
  bool operator!=(const TensorDim2 &t1, double d){ return t1.IsDifferent(d);      };
  bool operator>=(const TensorDim2 &t1, double d){ return t1.IsBiggerOrEqual(d);  };
  bool operator<=(const TensorDim2 &t1, double d){ return t1.IsSmallerOrEqual(d); };
  bool operator> (const TensorDim2 &t1, double d){ return t1.IsBigger(d);         };
  bool operator< (const TensorDim2 &t1, double d){ return t1.IsSmaller(d);        };

  bool operator==(TComplex d, const TensorDim2 &t1){ return t1.IsEqual(d);          };
  bool operator!=(TComplex d, const TensorDim2 &t1){ return t1.IsDifferent(d);      };
  bool operator>=(TComplex d, const TensorDim2 &t1){ return t1.IsSmallerOrEqual(d); };
  bool operator<=(TComplex d, const TensorDim2 &t1){ return t1.IsBiggerOrEqual(d);  };
  bool operator> (TComplex d, const TensorDim2 &t1){ return t1.IsSmaller(d);        };
  bool operator< (TComplex d, const TensorDim2 &t1){ return t1.IsBigger(d);         };

  bool operator==(const TensorDim2 &t1, TComplex d){ return t1.IsEqual(d);          };
  bool operator!=(const TensorDim2 &t1, TComplex d){ return t1.IsDifferent(d);      };
  bool operator>=(const TensorDim2 &t1, TComplex d){ return t1.IsBiggerOrEqual(d);  };
  bool operator<=(const TensorDim2 &t1, TComplex d){ return t1.IsSmallerOrEqual(d); };
  bool operator> (const TensorDim2 &t1, TComplex d){ return t1.IsBigger(d);         };
  bool operator< (const TensorDim2 &t1, TComplex d){ return t1.IsSmaller(d);        };


}
