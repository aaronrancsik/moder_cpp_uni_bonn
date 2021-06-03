#pragma once
#include <vector>
#include <string>
#include <cstdint>

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
 private:
  int rows_ = 0;
  int cols_ = 0;
  uint8_t max_val_ = 0;
  std::vector<uint8_t> data_;
};

}  // namespace igg
