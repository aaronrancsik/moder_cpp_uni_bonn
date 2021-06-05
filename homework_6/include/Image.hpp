#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace igg {

class Image {
 public:
  Image();
  Image(int rows, int cols);

  [[nodiscard]] int rows() const;
  [[nodiscard]] int cols() const;

  [[nodiscard]] uint8_t at(int row, int col) const;
  [[nodiscard]] uint8_t& at(int row, int col);

  bool FillFromPgm(const std::string& file_name);
  void WriteToPgm(const std::string& file_name);

  [[nodiscard]] std::vector<float> ComputeHistogram(int bins) const;

 private:
  int rows_ = 0;
  int cols_ = 0;
  uint8_t max_val_ = 0;
  std::vector<uint8_t> data_;
  [[nodiscard]] static float mapping(size_t numb, size_t max);
};

}  // namespace igg
