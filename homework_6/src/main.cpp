#include <cstddef>
#include <iostream>

#include "Image.hpp"

using std::cout;

int main() {
  igg::Image i = igg::Image();
  i.FillFromPgm("../data/lena.ascii.pgm");
  const int resolution = 10;
  auto res =i.ComputeHistogram(resolution);
  for(auto r : res){
    cout << r << ", ";
  }
  // i.UpScale(3);
  i.DownScale(2);
  i.WriteToPgm("test.pgm");

  // i.FillFromPgm("./test.pgm");
  // res =i.ComputeHistogram(resolution);
  // for(auto r : res){
    // cout << r << ", ";
  // }
//
  
  return EXIT_SUCCESS;
}
