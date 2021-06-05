#include <cstddef>
#include <iostream>

#include "Image.hpp"

using std::cout;
using std::endl;

int main() {
  igg::Image i = igg::Image();
  i.FillFromPgm("../data/lena.ascii.pgm");
  const int resolution = 10;
  auto res =i.ComputeHistogram(resolution);
  for(auto r : res){
    cout << r << ", ";
  }
  cout << endl;

  return EXIT_SUCCESS;
}
