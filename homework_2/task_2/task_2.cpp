#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Input shoud be 2 filename.." << std::endl;
    return EXIT_FAILURE;
  }
  std::stringstream arg1{argv[1]};
  std::stringstream arg2{argv[2]};

  int arg1_file_name = 0;
  int arg2_file_name = 0;
  std::string arg1_file_extension;
  std::string arg2_file_extension;

  arg1 >> arg1_file_name >> arg1_file_extension;
  arg2 >> arg2_file_name >> arg2_file_extension;

  if (arg1.fail() || arg2.fail()) {
    std::cerr << "Cant parse filename params." << std::endl;
    return EXIT_FAILURE;
  }

  std::string result;
  if (arg1_file_extension == arg2_file_extension) {
    if (arg1_file_extension == ".txt") {
      result = "txts mean value: " +
               std::to_string((arg1_file_name + arg2_file_name) / 2);
    } else if (arg1_file_extension == ".png") {
      result =
          "pngs sun value: " + std::to_string(arg1_file_name + arg2_file_name);
    } else {
      std::cerr << "Not know extension.";
      return EXIT_FAILURE;
    }
  } else if (arg1_file_extension == ".txt" && arg2_file_extension == ".png") {
    result = "txt and png modulo: " +
             std::to_string(arg1_file_name % arg2_file_name);
  } else {
    std::cerr << "Not know extension combination.";
    return EXIT_FAILURE;
  }

  std::cout << result << std::endl;

  return EXIT_SUCCESS;
}
