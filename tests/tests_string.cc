#include "string.hh"

#include <cassert>

namespace tests {
void string_initialization() {
  utilities::string empty;
  utilities::string foo("foo");
  assert(empty.size() == 0);
  assert(foo.size() == 3);
  assert(foo[1] == 'o');
  assert(*foo.c_str() == 'f');
  empty = foo;
  assert(empty.size() == 3);
  assert(empty[2] == 'o');
}

void string_comparison() {
  utilities::string empty;
  utilities::string foo("foo");
  assert(foo == foo);
  assert(foo == "foo");
  assert(foo != empty);
  assert("bar" != foo);
}

} // namespace tests

int main() {
  tests::string_initialization();
  tests::string_comparison();
  return 0;
}
