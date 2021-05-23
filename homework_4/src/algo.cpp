#include "../include/algo.hpp"

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <numeric>

int algo::accumulate(ipb::named_vector<int>& vec) {
  auto& v = vec.vector();
  return std::accumulate(v.begin(), v.end(), 0);
}
int algo::count(ipb::named_vector<int>& vec, int count_for) {
  auto& v = vec.vector();
  return std::count(v.begin(), v.end(), count_for);
}
bool algo::all_even(ipb::named_vector<int>& vec) {
  auto& v = vec.vector();
  return std::count_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; }) !=
         0;
}
void algo::clamp(ipb::named_vector<int>& vec, int min, int max) {
  auto& v = vec.vector();
  std::transform(v.begin(), v.end(), v.begin(),
                 [&](int i) { return std::clamp(i, min, max); });
}
void algo::fill(ipb::named_vector<int>& vec, int fill_with) {
  auto& v = vec.vector();
  std::fill(v.begin(), v.end(), fill_with);
}
bool algo::find(ipb::named_vector<int>& vec, int _find) {
  auto& v = vec.vector();
  return std::find(v.begin(), v.end(), _find) != v.end();
}
void algo::print(ipb::named_vector<int>& vec) {
  std::cout << vec.name() << " ";
  auto& v = vec.vector();
  for (auto e : v) {
    std::cout << e << ", ";
  }
  std::cout << std::endl;
}
void algo::toupper(ipb::named_vector<int>& vec) {
  auto& n = vec.name();
  std::transform(n.begin(), n.end(), n.begin(),
                 [](unsigned char c) { return std::toupper(c); });
}
void algo::sort(ipb::named_vector<int>& vec) {
  auto& v = vec.vector();
  std::sort(v.begin(), v.end());
}
void algo::rotate(ipb::named_vector<int>& vec) {
  auto& v = vec.vector();
  std::rotate(v.begin(), v.begin() + 1, v.end());
}
void algo::reverse(ipb::named_vector<int>& vec) {
  auto& v = vec.vector();
  std::reverse(v.begin(), v.end());
}
