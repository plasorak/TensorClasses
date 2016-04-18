#include "TensorUtils/TensorDim.h"

namespace TensorUtils{

  bool TensorDim1::CheckIndex(const unsigned int i) const{
    return (i < DimSize[0]);
  };

  unsigned int TensorDim1::GetGlobalIndex(const unsigned int i) const{
    return i;
  };
  
  TensorDim1::TensorDim1(const char *Name, unsigned int SizeDim){
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
    std::cout << "TensorDim"<< this->DimSize.size() << " with name '" << Name << "'" << std::endl;
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

  TensorDim1 Real(const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.Real();
    return t;
  };

  TensorDim1 Imaginary(const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.Imaginary();
    return t;
  };

  TensorDim1 Abs(const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.Abs();
    return t;
  };
  
  TensorDim1 operator+(const int c, const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim1 operator-(const int c, const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.Minus();
    t.Add(c);
    return t;
  };
  TensorDim1 operator*(const int c, const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim1 operator/(const int c, const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.OneOverElementWise();
    t.Multiply(c);
    return t;
  };

  TensorDim1 operator+(const TensorDim1 &t1, const int c){
    TensorDim1 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim1 operator-(const TensorDim1 &t1, const int c){
    TensorDim1 t(t1);
    t.Subtract(c);
    return t;
  };
  TensorDim1 operator*(const TensorDim1 &t1, const int c){
    TensorDim1 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim1 operator/(const TensorDim1 &t1, const int c){
    TensorDim1 t(t1);
    t.Divide(c);
    return t;
  };

  TensorDim1 operator+(TComplex c, const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim1 operator-(TComplex c, const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.Minus();
    t.Add(c);
    return t;
  };
  TensorDim1 operator*(TComplex c, const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim1 operator/(TComplex c, const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.OneOverElementWise();
    t.Multiply(c);
    return t;
  };

  TensorDim1 operator+(const TensorDim1 &t1, TComplex c){
    TensorDim1 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim1 operator-(const TensorDim1 &t1, TComplex c){
    TensorDim1 t(t1);
    t.Subtract(c);
    return t;
  };
  TensorDim1 operator*(const TensorDim1 &t1, TComplex c){
    TensorDim1 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim1 operator/(const TensorDim1 &t1, TComplex c){
    TensorDim1 t(t1);
    t.Divide(c);
    return t;
  };

  TensorDim1 operator+(double c, const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim1 operator-(double c, const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.Minus();
    t.Add(c);
    return t;
  };
  TensorDim1 operator*(double c, const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim1 operator/(double c, const TensorDim1 &t1){
    TensorDim1 t(t1);
    t.OneOverElementWise();
    t.Multiply(c);
    return t;
  };

  TensorDim1 operator+(const TensorDim1 &t1, double c){
    TensorDim1 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim1 operator-(const TensorDim1 &t1, double c){
    TensorDim1 t(t1);
    t.Subtract(c);
    return t;
  };
  TensorDim1 operator*(const TensorDim1 &t1, double c){
    TensorDim1 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim1 operator/(const TensorDim1 &t1, double c){
    TensorDim1 t(t1);
    t.Divide(c);
    return t;
  };

  TensorDim1 operator+(const TensorDim1 &t1, const TensorDim1 &t2){
    TensorDim1 t(t1);
    t.Add(t2);
    return t;
  };

  TensorDim1 operator-(const TensorDim1 &t1, const TensorDim1 &t2){
    TensorDim1 t(t1);
    t.Subtract(t2);
    return t;
  };

  TensorDim1 operator*(const TensorDim2 &t1, const TensorDim1 &t2){

    // First check the dimension of the matrix
    if(t1.GetDim() != 2 || t2.GetDim() != 1){
      std::cerr << "Can't do the matrix product, one of the tensor is not a matrix or vector" << std::endl;
      exit(1);
    }

    // Then check that size are good for multiplication
    // (i * j) (j) = (i)
    if(t1.GetDimSize(1) !=  t2.GetDimSize(0)){
      std::cerr << "Can't do the matrix product, the matrix and vector sizes are not right" << std::endl;
      exit(1);
    }
    char* resultName;
    strcpy(resultName, t1.GetName());
    strcat(resultName, t2.GetName());
    TensorDim1 result(resultName, t1.GetDimSize(0));

    for(int i = 0; i < t1.GetDimSize(0); i++)
      for(int j = 0; j < t2.GetDimSize(1); j++)
	result(i) += t1(i,j)*t2(j);
    
    return result;
  };

  bool operator==(const TensorDim1 &t1, const TensorDim1 &t2){ return t1.IsEqual(t2);          };
  bool operator!=(const TensorDim1 &t1, const TensorDim1 &t2){ return t1.IsDifferent(t2);      };
  bool operator>=(const TensorDim1 &t1, const TensorDim1 &t2){ return t1.IsBiggerOrEqual(t2);  };
  bool operator<=(const TensorDim1 &t1, const TensorDim1 &t2){ return t1.IsSmallerOrEqual(t2); };
  bool operator> (const TensorDim1 &t1, const TensorDim1 &t2){ return t1.IsBigger(t2);         };
  bool operator< (const TensorDim1 &t1, const TensorDim1 &t2){ return t1.IsSmaller(t2);        };

  bool operator==(double d, const TensorDim1 &t1){ return t1.IsEqual(d);          };
  bool operator!=(double d, const TensorDim1 &t1){ return t1.IsDifferent(d);      };
  bool operator>=(double d, const TensorDim1 &t1){ return t1.IsSmallerOrEqual(d); };
  bool operator<=(double d, const TensorDim1 &t1){ return t1.IsBiggerOrEqual(d);  };
  bool operator> (double d, const TensorDim1 &t1){ return t1.IsSmaller(d);        };
  bool operator< (double d, const TensorDim1 &t1){ return t1.IsBigger(d);         };

  bool operator==(const TensorDim1 &t1, double d){ return t1.IsEqual(d);          };
  bool operator!=(const TensorDim1 &t1, double d){ return t1.IsDifferent(d);      };
  bool operator>=(const TensorDim1 &t1, double d){ return t1.IsBiggerOrEqual(d);  };
  bool operator<=(const TensorDim1 &t1, double d){ return t1.IsSmallerOrEqual(d); };
  bool operator> (const TensorDim1 &t1, double d){ return t1.IsBigger(d);         };
  bool operator< (const TensorDim1 &t1, double d){ return t1.IsSmaller(d);        };

  bool operator==(TComplex d, const TensorDim1 &t1){ return t1.IsEqual(d);          };
  bool operator!=(TComplex d, const TensorDim1 &t1){ return t1.IsDifferent(d);      };
  bool operator>=(TComplex d, const TensorDim1 &t1){ return t1.IsSmallerOrEqual(d); };
  bool operator<=(TComplex d, const TensorDim1 &t1){ return t1.IsBiggerOrEqual(d);  };
  bool operator> (TComplex d, const TensorDim1 &t1){ return t1.IsSmaller(d);        };
  bool operator< (TComplex d, const TensorDim1 &t1){ return t1.IsBigger(d);         };

  bool operator==(const TensorDim1 &t1, TComplex d){ return t1.IsEqual(d);          };
  bool operator!=(const TensorDim1 &t1, TComplex d){ return t1.IsDifferent(d);      };
  bool operator>=(const TensorDim1 &t1, TComplex d){ return t1.IsBiggerOrEqual(d);  };
  bool operator<=(const TensorDim1 &t1, TComplex d){ return t1.IsSmallerOrEqual(d); };
  bool operator> (const TensorDim1 &t1, TComplex d){ return t1.IsBigger(d);         };
  bool operator< (const TensorDim1 &t1, TComplex d){ return t1.IsSmaller(d);        };



}
