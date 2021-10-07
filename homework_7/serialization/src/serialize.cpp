#include "serialization/serialize.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

void ipb::serialization::Serialize(const cv::Mat &m,
                                   const std::string &filename) {
  auto path = std::filesystem::path(filename);

  //  std::cout << path.extension().string() << "   ops  \n";
  //  return;
  auto out_path = path.replace_extension(".bin");

  std::ofstream file(out_path, std::ios_base::out | std::ios_base::binary);

  // header
  int type = m.type();
  int channels = m.channels();
  int rows = m.rows;
  int cols = m.cols;
  file.write(reinterpret_cast<char *>(&rows), sizeof(int));
  file.write(reinterpret_cast<char *>(&cols), sizeof(int));
  file.write(reinterpret_cast<char *>(&type), sizeof(int));
  file.write(reinterpret_cast<char *>(&channels), sizeof(int));

  // data
  if (m.isContinuous()) {
    file.write(reinterpret_cast<char *>(m.data),
               m.elemSize() * m.size().height * m.size().width);
    //  file.write(m.ptr<char>(0), (m.dataend - m.datastart));
  } else {
    int rowsz = CV_ELEM_SIZE(type) * m.cols;
    for (int r = 0; r < m.rows; r++) {
      file.write(m.ptr<char>(r), rowsz);
    }
  }
}

cv::Mat ipb::serialization::Deserialize(const std::string &filename) {
  std::ifstream in(filename, std::ios_base::in | std::ios_base::binary);
  if (!in) {
    cv::Mat m;
    return m;
  }

  // header
  int rows = 0;
  int cols = 0;
  int type = 0;
  int channels = 0;

  in.read(reinterpret_cast<char *>(&rows), sizeof(int));
  in.read(reinterpret_cast<char *>(&cols), sizeof(int));
  in.read(reinterpret_cast<char *>(&type), sizeof(int));
  in.read(reinterpret_cast<char *>(&channels), sizeof(int));
  // data
  cv::Mat mat(rows, cols, type);
  in.read(reinterpret_cast<char *>(mat.data), CV_ELEM_SIZE(type) * rows * cols);
  return mat;
}
