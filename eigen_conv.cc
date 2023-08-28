#include <iostream>
#include <eigen/unsupported/Eigen/CXX11/Tensor>
int main()
{
  using namespace Eigen;
  Eigen::Tensor<float, 2> tensor(5,5);
  for(size_t i=0; i<5; i++)
    for(size_t j=0; j<5; j++)
      tensor(i,j) = i+0.1*j;
  Eigen::Tensor<float, 2> kernel(3,3);
  kernel.setConstant(1.0/9.0);
  //tensor.setRandom();

  Eigen::DSizes<ptrdiff_t, 2> indices(1,1);
  Eigen::DSizes<ptrdiff_t, 2> sizes(3,3);
  Eigen::TensorRef<Eigen::Tensor<float, 2>> slice = tensor.slice(indices, sizes);
  tensor(2,2) = 10;
  slice.coeffRef(0,0) = 20;
  std::cout << slice(1,1) << std::endl;
  std::cout << tensor(1,1) << std::endl;
  Eigen::array<ptrdiff_t, 2> dims; dims[0]=0;dims[1]=1;
  Eigen::Tensor<float, 2> result = slice.convolve(kernel, dims);
  std::cout  << "tensor: " << std::endl;
  std::cout << tensor << std::endl;
  std::cout << "result: " << std::endl; 
  std::cout << result << std::endl;

  /*
  Tensor<float, 3> single_pixel_patch;
  single_pixel_patch = tensor.extract_image_patches(1);
  single_pixel_patch(3,3,3) = 500000;
  std::cout << single_pixel_patch.dimensions() << std::endl;
  std::cout << single_pixel_patch << std::endl;
  std::cout << "tensor:" << std::endl << tensor << std::endl;
  */
  return 0;
}
