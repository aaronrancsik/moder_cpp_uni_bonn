#include "convert_dataset.hpp"

#include <filesystem>
#include <iostream>

#include "opencv2/opencv.hpp"
#include "serialize.hpp"
void ipb::serialization::sifts::ConvertDataset(
    const std::filesystem::path &img_path) {
  auto it = std::filesystem::directory_iterator(img_path);
  auto out_dir =
      std::filesystem::path(img_path).parent_path().parent_path() / "bin";
  std::filesystem::create_directories(out_dir);

  if (!std::filesystem::exists(img_path)) {
    return;
  }
  for (const auto &current_file : it) {
    if (current_file.path().extension().string() == ".png") {
      cv::Mat image_matrix =
          cv::imread(current_file.path(), cv::IMREAD_UNCHANGED);

      std::vector<cv::KeyPoint> keypoints;
      auto detector = cv::SiftFeatureDetector::create();
      detector->detect(image_matrix, keypoints);

      cv::Mat descriptors;
      auto extractor = cv::SiftDescriptorExtractor::create();
      extractor->compute(image_matrix, keypoints, descriptors);

      auto out_path = out_dir / current_file.path().filename();
      ipb::serialization::Serialize(descriptors, out_path.string());
    }
  }
}

std::vector<cv::Mat> ipb::serialization::sifts::LoadDataset(
    const std::filesystem::path &bin_path) {
  std::vector<cv::Mat> ret;

  auto it = std::filesystem::directory_iterator(bin_path);

  for (const auto &current_file : it) {
    if (current_file.path().extension() == "bin") {
      ret.emplace_back(ipb::serialization::Deserialize(current_file.path()));
    }
  }
  return ret;
}