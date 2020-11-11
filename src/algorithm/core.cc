#include "core.hh"

#include "hash.hh"

namespace algorithm {
bool StringComparator::operator()(const char *const &a, const char *const &b) {
  return !strcmp(a, b);
}

int HashFunction::operator()(const char *const &string) {
  return utilities::hash<const char *>(string);
}

void create_index(char, index) {}
utilities::list<const char *> find_references(const char *word,
                                              const index &index) {
  if (index.contains(word))
    return index[word];
  return utilities::list<const char *>();
}
} // namespace algorithm
