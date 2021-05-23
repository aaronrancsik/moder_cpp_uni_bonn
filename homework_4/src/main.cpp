#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "../include/algo.hpp"
#include "../include/ipb.hpp"

int main() {
  using std::cout;
  using std::endl;

  const int n1 = 6;
  const int n2 = 5;
  const int n3 = 15;
  const int n4 = 1;
  const int n5 = 4;
  const int n6 = 7;
  const int n7 = -1;

  ipb::named_vector<int> vec{"this is my super container",
                             {n1, n2, n3, n4, n5, n6, n7}};

  cout << "Name: " << vec.name() << endl;
  cout << "Size: " << vec.size() << endl;

  auto ret = algo::accumulate(vec);
  cout << "Sum: " << ret << endl;

  cout << "Original: " << endl;
  algo::print(vec);

  cout << "clamp 2-6: " << endl;
  const int min = 2;
  const int max = 6;
  algo::clamp(vec, min, max);
  algo::print(vec);

  cout << std::boolalpha;
  cout << "All even? " << algo::all_even(vec) << endl;

  const int num = 6;
  cout << "Count 6: " << algo::count(vec, num) << endl;

  cout << "Find 4? " << algo::find(vec, 4) << endl;

  cout << "To upper" << endl;
  algo::toupper(vec);
  algo::print(vec);

  cout << "Sort" << endl;
  algo::sort(vec);
  algo::print(vec);

  cout << "Rotate" << endl;
  algo::rotate(vec);
  algo::print(vec);

  cout << "Fill with -99" << endl;
  const int num2 = -99;
  algo::fill(vec, num2);
  algo::print(vec);

  cout << "YAY!! This was a really hard homework... I've learnd a lots of "
          "things.."
       << endl;

  return EXIT_SUCCESS;
}