#include "core.hh"

#include "hash.hh"

#include <filesystem>
#include <fstream>
#include <string>

namespace algorithm {
bool StringComparator::operator()(const std::string &a,
                                  const std::string &b) const {
  return a == b;
}

int HashFunction::operator()(const std::string &str) const {
  return utilities::hash(str);
}

void create_index(const std::string &path, index &index) {
  for (auto &file : std::filesystem::recursive_directory_iterator(path)) {
    if (file.is_regular_file() && file.path().extension() == ".txt") {
      std::ifstream text_stream(file.path());
      std::string path_string(file.path());
      while (!text_stream.eof()) {
        std::string word;
        text_stream >> word;
        if (!index.contains(word))
          index.insert(word, utilities::list<std::string>(1, path_string));
        else {
          auto &files = index[word];
          if (files.find(path_string, StringComparator()) == nullptr)
            files.add(path_string);
        }
      }
    }
  }
}

utilities::list<std::string> find_references(const std::string &word,
                                             const index &index) {
  if (index.contains(word))
    return index[word];
  return utilities::list<std::string>();
}
} // namespace algorithm
