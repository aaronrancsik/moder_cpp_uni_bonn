#include "Image.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

#include "io_tools.hpp"
namespace igg {

Image::Image() = default;
Image::Image(int rows, int cols) : rows_{rows}, cols_{cols} {
  data_ = std::vector<int>(rows * cols, 0);
}
int Image::cols() const { return cols_; }
int Image::rows() const { return rows_; }
int Image::at(int row, int col) const { return data_.at(cols_ * row + col); }
int& Image::at(int row, int col) {
  return this->data_.at(this->rows_ * row + col);
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
  const std::vector<size_t> full_histogram = createCompleteHistogram();
  size_t bin_size = full_histogram.size() / bins;
  auto reduced_histogram =
      createReducedHistogram(bins, bin_size, full_histogram);
  auto fsize = data_.size();
  auto normalized_histogram =
      createNormalizedHistogram(fsize, reduced_histogram);
  return normalized_histogram;
}

std::vector<size_t> Image::createCompleteHistogram() const {
  std::vector<size_t> complete_histogram(max_val_ + 1, 0);
  for (auto pixel : data_) {
    ++complete_histogram.at(pixel);
  }
  return complete_histogram;
}

std::vector<int> Image::createReducedHistogram(
    int bins, size_t bin_size, const std::vector<size_t>& full_histogram) {
  std::vector<int> reduced_histogram(bins, 0);
  for (size_t i = 0; i < reduced_histogram.size(); ++i) {
    for (size_t j = 0; j < static_cast<size_t>(bin_size); ++j) {
      reduced_histogram.at(i) += full_histogram.at((i * bin_size) + j);
    }
  }
  for (size_t i = 0; i < full_histogram.size() % bins; ++i) {
    reduced_histogram.back() +=
        full_histogram.at(full_histogram.size() - 1 - i);
  }
  return reduced_histogram;
}

std::vector<float> Image::createNormalizedHistogram(
    size_t fsize, const std::vector<int>& reduced_histogram) {
  std::vector<float> normalized_histogram;
  auto populate_normal = [&normalized_histogram, fsize](const int& n) {
    normalized_histogram.push_back(mapping(n, fsize));
  };
  std::for_each(reduced_histogram.cbegin(), reduced_histogram.cend(),
                populate_normal);
  return normalized_histogram;
}

float Image::mapping(size_t numb, size_t max) {
  float scale = 1.0F / static_cast<float>(max);
  return numb * scale;
}

void Image::UpScale(int scale) {
  std::vector<int> new_data(data_.size() * scale * scale, 0);
  for (size_t s = 0; s < data_.size(); ++s) {
    size_t col_current = (s % rows_);
    size_t row_current = (s / cols_);

    size_t col_scaled = (col_current * scale);
    size_t row_scaled = (row_current * cols_ * scale * scale);

    auto current_pixel = data_.at(s);
    createBigPixel(scale, new_data, col_scaled, row_scaled, current_pixel);
  }
  rows_ *= scale;
  cols_ *= scale;
  data_ = new_data;
}

void Image::createBigPixel(size_t scale, std::vector<int>& new_data, size_t col,
                           size_t row, int pixel_value) const {
  for (size_t c = 0; c < scale; ++c) {
    for (size_t r = 0; r < scale; ++r) {
      size_t r_plus = r * cols_ * scale;
      size_t c_plus = c;
      new_data.at(col + row + c_plus + r_plus) = pixel_value;
    }
  }
}

void Image::DownScale(int scale) {
  std::vector<int> new_date;
  new_date.reserve( data_.size() / (scale*scale) );
  for (size_t s = 0; s < data_.size(); ++s) {
    size_t col = (s % rows_);
    size_t row = (s / cols_);
    if (col % scale == 0) {
      if (row % scale == 0) {
        new_date.push_back(at(row,col));
      }
    }
  }
  rows_ /= scale;
  cols_ /= scale;
  data_ = new_date;
}

}  // namespace igg
