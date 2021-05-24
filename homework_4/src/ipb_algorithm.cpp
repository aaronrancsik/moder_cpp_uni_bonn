#include "ipb_algorithm.hpp"

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <numeric>

int ipb::accumulate(ipb::named_vector<int>& vec) {
  auto& v = vec.vector();
  return std::accumulate(v.begin(), v.end(), 0);
}
int ipb::count(ipb::named_vector<int>& vec, int count_for) {
  auto& v = vec.vector();
  return std::count(v.begin(), v.end(), count_for);
}
bool ipb::all_even(ipb::named_vector<int>& vec) {
  auto& v = vec.vector();
  return std::count_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; }) !=
         0;
}
void ipb::clamp(ipb::named_vector<int>& vec, int min, int max) {
  auto& v = vec.vector();
  std::transform(v.begin(), v.end(), v.begin(),
                 [&](int i) { return std::clamp(i, min, max); });
}
void ipb::fill(ipb::named_vector<int>& vec, int fill_with) {
  auto& v = vec.vector();
  std::fill(v.begin(), v.end(), fill_with);
}
bool ipb::find(ipb::named_vector<int>& vec, int _find) {
  auto& v = vec.vector();
  return std::find(v.begin(), v.end(), _find) != v.end();
}
void ipb::print(ipb::named_vector<int>& vec) {
  std::cout << vec.name() << " ";
  auto& v = vec.vector();
  for (auto e : v) {
    std::cout << e << ", ";
  }
  std::cout << std::endl;
}
void ipb::toupper(ipb::named_vector<int>& vec) {
  auto& n = vec.name();
  std::transform(n.begin(), n.end(), n.begin(),
                 [](unsigned char c) { return std::toupper(c); });
}
void ipb::sort(ipb::named_vector<int>& vec) {
  auto& v = vec.vector();
  std::sort(v.begin(), v.end());
}
void ipb::rotate(ipb::named_vector<int>& vec, int rotate_by) {
  auto& v = vec.vector();
  std::rotate(v.begin(), v.begin() + rotate_by, v.end());
}
void ipb::reverse(ipb::named_vector<int>& vec) {
  auto& v = vec.vector();
  std::reverse(v.begin(), v.end());
}
