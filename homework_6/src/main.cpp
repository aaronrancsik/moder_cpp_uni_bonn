#include <cstddef>
#include <iostream>

#include "Image.hpp"

using std::cout;
using std::endl;

int main() {
  igg::Image i = igg::Image();
  i.FillFromPgm("../data/lena.ascii.pgm");

  cout << "cols: " << i.cols() << " rows: " << i.rows() << endl;
  cout << "at 500: " << std::to_string(i.at(500, 500)) << endl;
  cout <<"at 499: " <<  std::to_string(i.at(499, 499)) << endl;

  i.at(500,500) = 5;
  i.WriteToPgm("./test.pgm");

  i.FillFromPgm("./test.pgm");

  cout << "at 500: " << std::to_string(i.at(500, 500)) << endl;
  cout <<"at 499: " <<  std::to_string(i.at(499, 499)) << endl;

  return EXIT_SUCCESS;
}
