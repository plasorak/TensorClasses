#include "TensorUtils/TensorDim.h"

namespace TensorUtils{

  bool TensorDim4::CheckIndex(const int i, const int j, const int k, const int l) const{
    if(i < DimSize[0] && j < DimSize[1] && k < DimSize[2] && l < DimSize[3])
      return true;
    return false;
  };

  int TensorDim4::GetGlobalIndex(const int i1, const int i2, const int i3, const int i4) const{
    return (DimSize[0] * DimSize[1] * DimSize[2] * i1 +
	    DimSize[1] * DimSize[2] * i2 +
	    DimSize[2] * i3 +
	    i4);
  };

  TensorDim4::TensorDim4(const TensorDim4& t1){
    t1.AssertGoodDim(4);
    this->Name = t1.Name;
    this->Dim = t1.Dim;
    for(int i = 0; i < t1.Element.size(); i++)
      this->Element.push_back(t1.Element[i]);
    for(int i = 0; i < t1.DimSize.size(); i++)
      this->DimSize.push_back(t1.DimSize[i]);
  };


  TensorDim4::TensorDim4(const char * Name, int SizeDim1, int SizeDim2, int SizeDim3, int SizeDim4){
    this->Name = Name;
    DimSize.clear();
    DimSize.reserve(4);
    DimSize.push_back(SizeDim1);
    DimSize.push_back(SizeDim2);
    DimSize.push_back(SizeDim3);
    DimSize.push_back(SizeDim4);
    Dim = DimSize.size();
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
  


  TensorDim4::TensorDim4(const char * Name, int SizeDim){
    this->Name = Name;
    DimSize.clear();
    DimSize.reserve(4);
    DimSize.push_back(SizeDim);
    DimSize.push_back(SizeDim);
    DimSize.push_back(SizeDim);
    DimSize.push_back(SizeDim);
    Dim = DimSize.size();
    Element.clear();
    Element.reserve(DimSize[0]*DimSize[1]*DimSize[2]*DimSize[3]);
    TComplex Zero(0.,0.);
    for(int i1 = 0; i1 < SizeDim; i1++){
      for(int i2 = 0; i2 < SizeDim; i2++){
	for(int i3 = 0; i3 < SizeDim; i3++){
	  for(int i4 = 0; i4 < SizeDim; i4++)
	    Element.push_back(Zero);
	}
      }
    }
  };

  TComplex TensorDim4::At(const int i,
			  const int j,
			  const int k,
			  const int l) const{
    if(!CheckIndex(i, j, k, l))
      exit(1);

    return Element[GetGlobalIndex(i, j, k, l)];
  };

  void TensorDim4::Set(int i, int j, int k, int l, TComplex c){
    if(!CheckIndex(i, j, k, l))
      exit(1);
    
    Element[GetGlobalIndex(i, j, k, l)] = c;
    
  };

  void TensorDim4::Print() const{
    std::cout << "______________________________________________________________________" << std::endl;
    std::cout << "Tensor Dim" << this->DimSize.size() << " with name '" << Name << "'" << std::endl;
    for(int i = 0; i < Dim; i++){
      std::cout << "Dimension(" << i << ") size: " << DimSize[i] << std::endl;
    }

    std::cout << "Element(<position0>, <position1>, <position2> <position3> = <globalposition>)" << std::endl;
    for(int i = 0; i < DimSize[0]; i++){
      for(int j = 0; j < DimSize[1]; j++){
	for(int k = 0; k < DimSize[2]; k++){
	  for(int l = 0; l < DimSize[3]; l++){
	    std::cout << "Element(" << i << ", " << j << " = " << this->GetGlobalIndex(i,j,k,l) << ") = " << this->At(i,j,k,l) << std::endl;
	  }
	}
      }
    }
    
    std::cout << "______________________________________________________________________" << std::endl;
    
  };


  TComplex& TensorDim4::operator()(const int i1,
				   const int i2,
				   const int i3,
				   const int i4){
    if(!CheckIndex(i1, i2, i3, i4))
      exit(1);

    return Element[GetGlobalIndex(i1, i2, i3, i4)];
  };

  TComplex TensorDim4::operator()(const int i1,
				  const int i2,
				  const int i3,
				  const int i4) const{
    if(!CheckIndex(i1, i2, i3, i4))
      exit(1);

    return Element[GetGlobalIndex(i1, i2, i3, i4)];
  };


  TensorDim4 Real(const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.Real();
    return t;
  };

  TensorDim4 Imaginary(const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.Imaginary();
    return t;
  };

  TensorDim4 Abs(const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.Abs();
    return t;
  };
  
  TensorDim4 operator+(const int c, const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim4 operator-(const int c, const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.Minus();
    t.Add(c);
    return t;
  };
  TensorDim4 operator*(const int c, const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim4 operator/(const int c, const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.OneOverElementWise();
    t.Multiply(c);
    return t;
  };

  TensorDim4 operator+(const TensorDim4 &t1, const int c){
    TensorDim4 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim4 operator-(const TensorDim4 &t1, const int c){
    TensorDim4 t(t1);
    t.Subtract(c);
    return t;
  };
  TensorDim4 operator*(const TensorDim4 &t1, const int c){
    TensorDim4 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim4 operator/(const TensorDim4 &t1, const int c){
    TensorDim4 t(t1);
    t.Divide(c);
    return t;
  };

  TensorDim4 operator+(TComplex c, const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim4 operator-(TComplex c, const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.Minus();
    t.Add(c);
    return t;
  };
  TensorDim4 operator*(TComplex c, const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim4 operator/(TComplex c, const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.OneOverElementWise();
    t.Multiply(c);
    return t;
  };

  TensorDim4 operator+(const TensorDim4 &t1, TComplex c){
    TensorDim4 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim4 operator-(const TensorDim4 &t1, TComplex c){
    TensorDim4 t(t1);
    t.Subtract(c);
    return t;
  };
  TensorDim4 operator*(const TensorDim4 &t1, TComplex c){
    TensorDim4 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim4 operator/(const TensorDim4 &t1, TComplex c){
    TensorDim4 t(t1);
    t.Divide(c);
    return t;
  };

  TensorDim4 operator+(double c, const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim4 operator-(double c, const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.Minus();
    t.Add(c);
    return t;
  };
  TensorDim4 operator*(double c, const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim4 operator/(double c, const TensorDim4 &t1){
    TensorDim4 t(t1);
    t.OneOverElementWise();
    t.Multiply(c);
    return t;
  };

  TensorDim4 operator+(const TensorDim4 &t1, double c){
    TensorDim4 t(t1);
    t.Add(c);
    return t;
  };
  TensorDim4 operator-(const TensorDim4 &t1, double c){
    TensorDim4 t(t1);
    t.Subtract(c);
    return t;
  };
  TensorDim4 operator*(const TensorDim4 &t1, double c){
    TensorDim4 t(t1);
    t.Multiply(c);
    return t;
  };
  TensorDim4 operator/(const TensorDim4 &t1, double c){
    TensorDim4 t(t1);
    t.Divide(c);
    return t;
  };

  TensorDim4 operator+(const TensorDim4 &t1, const TensorDim4 &t2){
    TensorDim4 t(t1);
    t.Add(t2);
    return t;
  };

  TensorDim4 operator-(const TensorDim4 &t1, const TensorDim4 &t2){
    TensorDim4 t(t1);
    t.Subtract(t2);
    return t;
  };

  bool operator==(const TensorDim4 &t1, const TensorDim4 &t2){ return t1.IsEqual(t2);          };
  bool operator!=(const TensorDim4 &t1, const TensorDim4 &t2){ return t1.IsDifferent(t2);      };
  bool operator>=(const TensorDim4 &t1, const TensorDim4 &t2){ return t1.IsBiggerOrEqual(t2);  };
  bool operator<=(const TensorDim4 &t1, const TensorDim4 &t2){ return t1.IsSmallerOrEqual(t2); };
  bool operator> (const TensorDim4 &t1, const TensorDim4 &t2){ return t1.IsBigger(t2);         };
  bool operator< (const TensorDim4 &t1, const TensorDim4 &t2){ return t1.IsSmaller(t2);        };

  bool operator==(double d, const TensorDim4 &t1){ return t1.IsEqual(d);          };
  bool operator!=(double d, const TensorDim4 &t1){ return t1.IsDifferent(d);      };
  bool operator>=(double d, const TensorDim4 &t1){ return t1.IsSmallerOrEqual(d); };
  bool operator<=(double d, const TensorDim4 &t1){ return t1.IsBiggerOrEqual(d);  };
  bool operator> (double d, const TensorDim4 &t1){ return t1.IsSmaller(d);        };
  bool operator< (double d, const TensorDim4 &t1){ return t1.IsBigger(d);         };

  bool operator==(const TensorDim4 &t1, double d){ return t1.IsEqual(d);          };
  bool operator!=(const TensorDim4 &t1, double d){ return t1.IsDifferent(d);      };
  bool operator>=(const TensorDim4 &t1, double d){ return t1.IsBiggerOrEqual(d);  };
  bool operator<=(const TensorDim4 &t1, double d){ return t1.IsSmallerOrEqual(d); };
  bool operator> (const TensorDim4 &t1, double d){ return t1.IsBigger(d);         };
  bool operator< (const TensorDim4 &t1, double d){ return t1.IsSmaller(d);        };

  bool operator==(TComplex d, const TensorDim4 &t1){ return t1.IsEqual(d);          };
  bool operator!=(TComplex d, const TensorDim4 &t1){ return t1.IsDifferent(d);      };
  bool operator>=(TComplex d, const TensorDim4 &t1){ return t1.IsSmallerOrEqual(d); };
  bool operator<=(TComplex d, const TensorDim4 &t1){ return t1.IsBiggerOrEqual(d);  };
  bool operator> (TComplex d, const TensorDim4 &t1){ return t1.IsSmaller(d);        };
  bool operator< (TComplex d, const TensorDim4 &t1){ return t1.IsBigger(d);         };

  bool operator==(const TensorDim4 &t1, TComplex d){ return t1.IsEqual(d);          };
  bool operator!=(const TensorDim4 &t1, TComplex d){ return t1.IsDifferent(d);      };
  bool operator>=(const TensorDim4 &t1, TComplex d){ return t1.IsBiggerOrEqual(d);  };
  bool operator<=(const TensorDim4 &t1, TComplex d){ return t1.IsSmallerOrEqual(d); };
  bool operator> (const TensorDim4 &t1, TComplex d){ return t1.IsBigger(d);         };
  bool operator< (const TensorDim4 &t1, TComplex d){ return t1.IsSmaller(d);        };

  
}
