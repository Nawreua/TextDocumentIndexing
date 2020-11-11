#include "list.hh"

#include <cassert>

namespace test {

class IntComparator {
public:
  bool operator()(int a, int b);
};

bool IntComparator::operator()(int a, int b) { return a == b; }

void list_initialization() {
  utilities::list<int> l;
  assert(l.size() == 0);
  utilities::list<int> l_long(7, 10);
  assert(l.size() == 7);
  assert(l[0] == 10);
  assert(l[6] == 10);
}

void list_manipulation() {
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
}

} // namespace test

int main() {
  test::list_initialization();
  test::list_manipulation();
  return 0;
}
