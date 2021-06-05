#include <cstddef>
#include <iostream>

#include "Image.hpp"

using std::cout;
using std::endl;

int main() {
  igg::Image i = igg::Image();
  i.FillFromPgm("../data/lena.ascii.pgm");
  const int resolution = 100;
  auto res =i.ComputeHistogram(resolution);

  return EXIT_SUCCESS;
}
