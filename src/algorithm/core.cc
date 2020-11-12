#include "core.hh"

#include "hash.hh"

#include <filesystem>
#include <fstream>
#include <string>

namespace algorithm {
bool StringComparator::operator()(const utilities::string &a,
                                  const utilities::string &b) const {
  return a == b;
}

int HashFunction::operator()(const utilities::string &str) const {
  return utilities::hash(str);
}

void create_index(const utilities::string &path, index &index) {
  for (auto &file :
       std::filesystem::recursive_directory_iterator(path.c_str())) {
    if (file.is_regular_file() && file.path().extension() == ".txt") {
      std::ifstream text_stream(file.path());
      utilities::string path_string(file.path().c_str());
      while (!text_stream.eof()) {
        std::string word;
        text_stream >> word;
        utilities::string str(word.c_str());
        if (!index.contains(str))
          index.insert(str, utilities::list<utilities::string>(1, path_string));
        else {
          auto &files = index[str];
          if (files.find(path_string, StringComparator()) == nullptr)
            files.add(path_string);
        }
      }
    }
  }
}

utilities::list<utilities::string>
find_references(const utilities::string &word, const index &index) {
  if (index.contains(word))
    return index[word];
  return utilities::list<utilities::string>();
}
} // namespace algorithm
