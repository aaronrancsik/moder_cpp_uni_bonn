#pragma once
#include <string>
#include <vector>
namespace ipb {

template <typename T>
struct named_vector {
  std::string m_name;
  std::vector<T> m_t;
  std::string& name() { return m_name; }
  std::vector<T>& vector() { return m_t; }
  size_t size() { return m_t.size() + m_name.size(); }
  bool empty() { return m_t.empty() || m_name.empty(); }
  void reserve(size_t n) { m_t.reserve(n); }
  void resize(size_t new_size) { m_t.resize(new_size); }
  size_t capacity() { return m_t.capacity(); }
};

}  // namespace ipb
