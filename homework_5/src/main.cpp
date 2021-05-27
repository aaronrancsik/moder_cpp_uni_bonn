#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

#include "convert_dataset.hpp"
#include "serialize.hpp"

int main() {
  ipb::serialization::sifts::ConvertDataset("../data/freiburg/images");

  auto image_descriptors =
      ipb::serialization::sifts::LoadDataset("../data/freiburg/bin");

  //   std::string file_name = "../data/lenna.png";
  //   cv::Mat image_matrix = cv::imread(file_name, cv::IMREAD_UNCHANGED);

  //   std::vector<cv::KeyPoint> keypoints;

  //   auto detector = cv::SiftFeatureDetector::create();
  //   detector->detect(image_matrix, keypoints);

  //   //   cv::Mat image_wiht_keypoints;
  //   //   cv::drawKeypoints(image_matrix, keypoints, image_wiht_keypoints);

  //   cv::Mat descriptors;
  //   auto extractor = cv::SiftDescriptorExtractor::create();
  //   extractor->compute(image_matrix, keypoints, descriptors);

  //   ipb::serialization::Serialize(descriptors, file_name);
  //   const std::string win2{"win2"};
  //   cv::namedWindow(win2, cv::WINDOW_AUTOSIZE);
  //   cv::imshow(win2, descriptors);

  //   const std::string win1{"win1"};
  //   cv::namedWindow(win1, cv::WINDOW_AUTOSIZE);
  //   auto loaded_descriptor =
  //   ipb::serialization::Deserialize("../data/lenna.bin"); cv::imshow(win1,
  //   loaded_descriptor);

  //   cv::waitKey(0);
  return EXIT_SUCCESS;
}