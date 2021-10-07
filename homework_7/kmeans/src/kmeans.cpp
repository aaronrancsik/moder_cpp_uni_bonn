#include "kmeans/kmeans.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"

cv::Mat ipb::kMeans(const std::vector<cv::Mat> &descriptors, int k, int max_iter){
  cv::Mat labels;
  cv::Mat centers;
  cv::kmeans(descriptors.at(0), k, labels,  cv::TermCriteria(), max_iter, cv::KMEANS_PP_CENTERS, centers);
  return centers;
}
