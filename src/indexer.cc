#include "core.hh"

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  // We check if the user has given the directory path
  if (argc == 1) {
    std::cerr << "Usage: index [PATH]\n\tPATH: path to the directory"
              << std::endl;
    return 1;
  }

  // We create the index, using the directory path given by the user
  algorithm::index index;
  algorithm::create_index(argv[1], index);

  // After asking the user for the word, we search its references in the index
  std::cout << "Enter the word to search:\n";
  std::string word;
  std::cin >> word;
  auto list = algorithm::find_references(word, index);

  if (list.size() == 0)
    std::cout << "No files contains this word\n";
  else {
    std::cout << "The word " << word << " was found in:\n";
    for (size_t i = 0; i < list.size(); ++i)
      std::cout << list[i] << std::endl;
  }
  return 0;
}
