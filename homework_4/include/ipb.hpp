#pragma once
#include <string>
#include <vector>
namespace ipb {

template <typename T>
struct named_vector {
 public:
  std::string m_name;
  std::vector<T> m_t;
  std::string& name();
  std::vector<T>& vector();
  size_t size();
  bool empty();
  void reserve(size_t n);
  void resize(size_t new_size);
  size_t capacity();
};

}  // namespace ipb
