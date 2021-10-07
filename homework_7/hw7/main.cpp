#include <iostream>
#include "serialization/sift_serialize.hpp"
int main(){
  ipb::serialization::sifts::ConvertDataset("image.png");
  std::cerr << "Hello, World!" << std::endl;
}
