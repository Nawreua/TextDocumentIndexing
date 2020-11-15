#include "core.hh"

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  // We verify if the user has given the directory path
  if (argc == 1)
    return 1;
  algorithm::index index;
  algorithm::create_index(argv[1], index);
  std::cout << "Enter word to search:\n";
  std::string word;
  std::cin >> word;
  auto list = algorithm::find_references(word, index);
  if (list.size() == 0)
    std::cout << "No files contains this word\n";
  else {
    std::cout << "The word was found in:\n";
    for (size_t i = 0; i < list.size(); ++i)
      std::cout << list[i].c_str() << std::endl;
  }
  return 0;
}
