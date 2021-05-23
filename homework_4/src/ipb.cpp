#include "../include/ipb.hpp"

#include <iostream>
template <>
std::string& ipb::named_vector<int>::name() {
  return m_name;
}

template <>
std::vector<int>& ipb::named_vector<int>::vector() {
  return m_t;
}

template <>
size_t ipb::named_vector<int>::size() {
  return m_t.size() + m_name.size();
}

template <>
bool ipb::named_vector<int>::empty() {
  return m_t.empty() || m_name.empty();
}

template <>
void ipb::named_vector<int>::reserve(size_t n) {
  m_t.reserve(n);
}

template <>
void ipb::named_vector<int>::resize(size_t new_size) {
  m_t.resize(new_size);
}

template <>
size_t ipb::named_vector<int>::capacity() {
  return m_t.capacity();
}