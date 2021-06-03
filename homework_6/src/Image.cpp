#include "Image.hpp"

#include <algorithm>
#include <iostream>

#include "io_tools.hpp"
namespace igg {

Image::Image() = default;
Image::Image(int rows, int cols) : rows_{rows}, cols_{cols} {}
int Image::cols() const { return cols_; }
int Image::rows() const { return rows_; }
uint8_t Image::at(int row, int col) const {
  return this->data_[this->rows_ * row + col];
}
uint8_t& Image::at(int row, int col) {
  return this->data_[this->rows_ * row + col];
}

bool Image::FillFromPgm(const std::string& file_name) {
  auto res = igg::io_tools::ReadFromPgm(file_name);
  if (res.cols == 0 || res.rows == 0 || res.data.empty()) {
    return false;
  }
  cols_ = res.cols;
  rows_ = res.cols;
  max_val_ = res.max_val;
  data_ = res.data;
  return true;
}

void Image::WriteToPgm(const std::string& file_name) {
  igg::io_tools::WriteToPgm({rows_,cols_,max_val_,data_}, file_name);
}
}  // namespace igg
