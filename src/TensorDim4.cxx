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
    if(t1.Dim != 4){
      std::cerr << "The tensor is not of dimension 4!" << std::endl;
      exit(1);	
    }
    this->Dim = t1.Dim;
    for(unsigned int i = 0; i < t1.Element.size(); i++)
      this->Element.push_back(t1.Element[i]);
    for(unsigned int i = 0; i < t1.DimSize.size(); i++)
      this->DimSize.push_back(t1.DimSize[i]);
  };


  TensorDim4::TensorDim4(const char * Name, unsigned int SizeDim1, unsigned int SizeDim2, unsigned int SizeDim3, unsigned int SizeDim4){
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
  


  TensorDim4::TensorDim4(const char * Name, unsigned int SizeDim){
    this->Name = Name;
    DimSize.clear();
    DimSize.reserve(4);
    DimSize.push_back(SizeDim);
    DimSize.push_back(SizeDim);
    DimSize.push_back(SizeDim);
    DimSize.push_back(SizeDim);
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
    std::cout << "Tensor Dim4 with name '" << Name << "'" << std::endl;
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
