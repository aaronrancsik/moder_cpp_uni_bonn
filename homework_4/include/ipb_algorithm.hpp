#pragma once
#include "named_vector.hpp"
namespace ipb {
int accumulate(ipb::named_vector<int>& vec);
int count(ipb::named_vector<int>& vec, int count_for);
bool all_even(ipb::named_vector<int>& vec);
void clamp(ipb::named_vector<int>& vec, int min, int max);
void fill(ipb::named_vector<int>& vec, int fill_with);
bool find(ipb::named_vector<int>& vec, int find);
void print(ipb::named_vector<int>& vec);
void toupper(ipb::named_vector<int>& vec);
void sort(ipb::named_vector<int>& vec);
void rotate(ipb::named_vector<int>& vec, int rotate_by);
void reverse(ipb::named_vector<int>& vec);

}  // namespace ipb