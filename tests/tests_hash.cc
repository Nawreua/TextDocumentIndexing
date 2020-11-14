#include "hash.hh"

#include <cassert>
#include <cstring>
#include <string>

namespace tests {
void hash_char_pointer() {
  assert(utilities::hash<const char *>("foo") !=
         utilities::hash<const char *>("bar"));
  assert(utilities::hash<const char *>("foo") ==
         utilities::hash<const char *>("foo"));
}

void hash_int() {
  assert(utilities::hash<int>(75) != utilities::hash<int>(94));
  assert(utilities::hash<int>(48) == utilities::hash<int>(48));
}

void hash_string() {
  assert(utilities::hash<std::string>("foo") ==
         utilities::hash<const char *>("foo"));
  assert(utilities::hash<std::string>("foo") !=
         utilities::hash<std::string>("bar"));
}
} // namespace tests

int main() {
  tests::hash_char_pointer();
  tests::hash_string();
  tests::hash_int();
}
