#include "Image.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

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
  igg::io_tools::WriteToPgm({rows_, cols_, max_val_, data_}, file_name);
}


std::vector<float> Image::ComputeHistogram(int bins) const {
  if (bins > max_val_ + 1) {
    return std::vector<float>();
  }

  std::vector<int> full_histogram(max_val_ + 1, 0);
  for (auto pixel : data_) {
    ++full_histogram.at(pixel);
  }

  size_t chunk_size = full_histogram.size() / bins;
  std::vector<int> histogram(bins, 0);

  for (size_t i = 0; i < histogram.size(); ++i) {
    for (size_t j = 0; j < static_cast<size_t>(chunk_size); ++j) {
      histogram.at(i) += full_histogram.at((i * chunk_size) + j);
    }
  }
  histogram.at(bins - 1) += full_histogram.back();

  std::vector<float> normalized_histogram;
  auto fsize = full_histogram.size();
  auto populate_normal = [&normalized_histogram,fsize](const int& n) {
    normalized_histogram.push_back(mapping(n,fsize));
  };
  std::for_each(histogram.cbegin(), histogram.cend(), populate_normal);
  return normalized_histogram;
}

float Image::mapping(size_t numb, size_t max) {
  float scale = 1.0F / static_cast<float>(max);
  return numb * scale;
}

}  // namespace igg
