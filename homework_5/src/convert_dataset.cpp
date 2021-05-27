#include "convert_dataset.hpp"

#include <filesystem>
#include <iostream>

#include "opencv2/opencv.hpp"
#include "serialize.hpp"
void ipb::serialization::sifts::ConvertDataset(
    const std::filesystem::path &img_path) {
  auto it = std::filesystem::directory_iterator(img_path);
  for (const auto &current_file : it) {
    cv::Mat image_matrix =
        cv::imread(current_file.path(), cv::IMREAD_UNCHANGED);

    std::vector<cv::KeyPoint> keypoints;
    auto detector = cv::SiftFeatureDetector::create();
    detector->detect(image_matrix, keypoints);

    cv::Mat descriptors;
    auto extractor = cv::SiftDescriptorExtractor::create();
    extractor->compute(image_matrix, keypoints, descriptors);

    auto out_dir = current_file.path().parent_path().parent_path() / "bin";
    auto out_path = out_dir / current_file.path().filename();
    std::filesystem::create_directories(out_dir);

    ipb::serialization::Serialize(descriptors, out_path.string());
  }
}

std::vector<cv::Mat> ipb::serialization::sifts::LoadDataset(
    const std::filesystem::path &bin_path) {
  std::vector<cv::Mat> ret;

  auto it = std::filesystem::directory_iterator(bin_path);

  for (const auto &current_file : it) {
    ret.emplace_back(ipb::serialization::Deserialize(current_file.path()));
  }
  return ret;
}