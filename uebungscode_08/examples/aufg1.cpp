#include <datenstrukturen/list.hpp>

int main() {
  // To save my time
  using node = Datenstrukturen::ListNodeptr;

  // Declared list
  Datenstrukturen::List list;
  // Insert {0,1,2,3,42,99}
  node p1 =  list.insert_front(1);
  node p2 = list.insert_after(p1,2);
  list.print();
  list.next(p1);
  node p3 = list.insert_after(p2,3);
  node p4 = list.insert_after(p3,42);
  node p5 = list.insert_after(p4,99);
  list.print();
  list.next(p4);
  list.next(p5);
  node p6 = list.insert_front(0);
  list.print();
  list.next(p6);
  list.next(p1);
  // Remove 0 to see if it crashes even if the head is added later
  list.remove_front();
  list.print();
  // Remove 3 that is after 2
  list.remove_after(p2);
  list.print();
  // Remove whatever that is after 2 after 3 is removed
  list.remove_after(p2);
  list.print();
  // Remove the head again which is 1 to see if it crashes
  list.remove_front();
  list.print();

}
