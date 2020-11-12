#include "list.hh"

#include <cassert>

namespace tests {

class IntComparator {
public:
  bool operator()(int a, int b) const;
};

bool IntComparator::operator()(int a, int b) const { return a == b; }

void list_initialization() {
  utilities::list<int> l;
  assert(l.size() == 0);
  utilities::list<int> l_long(7, 10);
  assert(l_long.size() == 7);
  assert(l_long[0] == 10);
  assert(l_long[6] == 10);
  utilities::list<int> l_cpy(l_long);
  assert(l_cpy.size() == 7);
  assert(l_cpy[1] == 10);
  l_cpy = utilities::list<int>(8, 4);
  assert(l_cpy.size() == 8);
  assert(l_cpy[0] == 4);
}

void list_basic_manipulation() {
  utilities::list<int> l;
  l.add(6);
  l.add(8);
  l.add(14);
  assert(l.size() == 3);
  assert(l[1] == 8);
  l.remove(8, IntComparator());
  assert(l.size() == 2);
  assert(l[1] == 14);
  assert(l.find(8, IntComparator()) == nullptr);
  assert(l.index(8, IntComparator()) == -1);
  l.replace(7, 1);
  assert(*(l.find(7, IntComparator())) == 7);
  assert(l.index(7, IntComparator()) == 1);
  assert(l.size() == 2);
  l.remove(7, IntComparator());
  assert(l.size() == 1);
  l.add(17);
  assert(l.size() == 2);
  assert(l[1] == 17);
}

void list_extensive_manipulation() {
  utilities::list<int> l;
  for (int i = 0; i < 1000; ++i) {
    l.add(0);
  }
  assert(l.size() == 1000);
  assert(l[999] == 0);
  assert(l[0] == 0);
  for (int i = 0; i < 1000; ++i) {
    l.remove(0, IntComparator());
  }
  assert(l.size() == 0);
  assert(l.find(0, IntComparator()) == nullptr);
}

} // namespace tests

int main() {
  tests::list_initialization();
  tests::list_basic_manipulation();
  tests::list_extensive_manipulation();
  return 0;
}
