#include "TensorUtils/TensorDim1.h"
#include "TensorUtils/TensorDim2.h"
#include "TensorUtils/TensorDim3.h"
#include "TensorUtils/TensorDim4.h"
#include "TensorUtils/TensorUtils.h"

using namespace TensorUtils;

int main(int argc, char **argv) {
  
  std::cout << "Basic operation with tensors" << std::endl;

  // TensorDim1 t1(4);
  // t1.Print();
  TensorDim2 t2(4);
  t2.Print();
  // TensorDim3 t3(4);
  // t3.Print();
  // TensorDim4 t4(4);
  // t4.Print();
  
  return 1;

}
