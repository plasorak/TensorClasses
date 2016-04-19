#include "TensorUtils/TensorDim.h"
#include "TString.h"

namespace TensorUtils{

  bool TensorDim2::CheckIndex(const int i, const int j) const{
    return (i < DimSize[0] && j < DimSize[1]);
  };

  int TensorDim2::GetGlobalIndex(const int i,
					  const int j) const{
    return i * DimSize[0] + j;
  };

  TensorDim2::TensorDim2(const char * Name, int SizeDim1, int SizeDim2){
    this->Name = Name;
    this->DimSize.reserve(2);
    this->DimSize.push_back(SizeDim1);
    this->DimSize.push_back(SizeDim2);
    this->Dim = DimSize.size();
    this->Element.reserve(DimSize[0]*DimSize[1]);

    TComplex Zero(0.,0.);

    for(int i1 = 0; i1 < this->DimSize[0]; i1++)
      for(int i2 = 0; i2 < this->DimSize[1]; i2++)
	this->Element.push_back(Zero);
      
    
  };
  TensorDim2::TensorDim2(const TensorDim2& t1){
    t1.AssertGoodDim(2);
    this->Name = t1.Name;
    this->Dim = t1.Dim;
    this->DimSize.reserve(2);
    this->DimSize.push_back(t1.DimSize[0]);
    this->DimSize.push_back(t1.DimSize[1]);
    this->Element.reserve(DimSize[0]*DimSize[1]);

    for(int i = 0; i < t1.Element.size(); i++)
      this->Element.push_back(t1.Element[i]);
  };

  TensorDim2::TensorDim2(const char * Name, int SizeDim){
    this->Name = Name;
    this->DimSize.reserve(2);
    this->DimSize.push_back(SizeDim);
    this->DimSize.push_back(SizeDim);
    this->Dim = DimSize.size();
    this->Element.reserve(DimSize[0]*DimSize[1]);

    TComplex Zero(0.,0.);


    for(int i1 = 0; i1 < this->DimSize[0]; i1++)
      for(int i2 = 0; i2 < this->DimSize[1]; i2++)
	this->Element.push_back(Zero);
    
    
  };

  TComplex TensorDim2::At(const int i, const int j) const{
    if(!CheckIndex(i, j))
      exit(1);
    return Element[GetGlobalIndex(i, j)];

  };

  void TensorDim2::Set(const int i, const int j, TComplex c){
    if(!CheckIndex(i, j))
      exit(1);
    
    Element[GetGlobalIndex(i, j)] = c;
      
  };

  void TensorDim2::Print() const{
    std::cout << "______________________________________________________________________" << std::endl;
    std::cout << "TensorDim" << this->DimSize.size() << " with name '" << this->Name << "'" << std::endl;
    for(int i = 0; i < Dim; i++){
      std::cout << "Dimension(" << i << ") size: " << this->DimSize[i] << std::endl;
    }
    std::cout << "Element(<position0>, <position1> = <globalposition>)" << std::endl;
    for(int i = 0; i < this->DimSize[0]; i++){
      for(int j = 0; j < this->DimSize[1]; j++){
	std::cout << " Element(" << i << ", " << j << " = " << this->GetGlobalIndex(i, j) << ") = " << this->At(i, j) << std::endl;
      }
    }
    std::cout << "______________________________________________________________________" << std::endl;

  };
  
  TComplex& TensorDim2::operator()(const int i1, const int i2){
    if(!CheckIndex(i1, i2))
      exit(1);
    return Element[GetGlobalIndex(i1, i2)];
  };

  TComplex  TensorDim2::operator()(const int i1, const int i2) const{
    if(!CheckIndex(i1, i2))
      exit(1);
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

    // First check the dimension of the tensors
    t1.AssertGoodDim(2);
    t2.AssertGoodDim(2);
    // First check the dimension of the matrix
    // (i * j) (j * k) = (i * k)
    t1.AssertGoodDim(1, t2.GetDimSize(1));

    TensorDim2 result(Form("(%sX%s)",t1.GetName(), t2.GetName()), t1.GetDimSize(0), t2.GetDimSize(1));

    for(int i = 0; i < t1.GetDimSize(0); i++)
      for(int k = 0; k < t2.GetDimSize(1); k++)
	for(int j = 0; j < t1.GetDimSize(1); j++)
	  result(i,k) += t1(i,j)*t2(j,k);
    
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
