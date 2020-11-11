#include "hash.hh"

#include <cassert>
#include <cstring>

namespace tests {
void hash_string() {
  assert(utilities::hash<const char *>("foo") !=
         utilities::hash<const char *>("bar"));
  assert(utilities::hash<const char *>("foo") ==
         utilities::hash<const char *>("foo"));
}

void hash_int() {
  assert(utilities::hash<int>(75) != utilities::hash<int>(94));
  assert(utilities::hash<int>(48) == utilities::hash<int>(48));
}
} // namespace tests

int main() {
  tests::hash_string();
  tests::hash_int();
}
