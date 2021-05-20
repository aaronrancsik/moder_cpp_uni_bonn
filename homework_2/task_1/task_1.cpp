#include <cstdlib>
#include <iostream>
#include <random>

int main() {
  std::random_device rd;
  const int max = 99;
  std::uniform_int_distribution<int> dist(0, max);
  int random = dist(rd);
  int guess = -1;

  std::cerr << "I think for some number...\n";
  while (guess != random) {
    std::cerr << "Make a guess!: ";

    std::cin >> guess;
    if (std::cin.fail()) {
      std::cerr << "Error can't handle the input it is a not number.\n";
      return EXIT_FAILURE;
    }

    if (guess < random) {
      std::cerr << "The number is bigger..\n";
    } else if (guess > random) {
      std::cerr << "The number is smaller.\n";
    }
  }

  std::cerr << "Yes!! " << random << " is the correct number!\n";

  return EXIT_SUCCESS;
}
