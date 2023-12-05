#include <datenstrukturen/binarytree.hpp>
#include <iostream>

int main() {
  // To save my time
  using node = Datenstrukturen::TreeNodeptr;

  // Declared root and initialize the data to 42
  Datenstrukturen::BinaryTree root(42);
  // Set up the whole Binary tree according to what Felix wants
  node p1 = root.get_root();
  p1->set_left_child(11);
  p1->set_right_child(22);
  node p2 = p1->get_left_child();
  node p3 = p1->get_right_child();
  p2->set_left_child(9);
  p2->set_right_child(0);
  node p4 = p2->get_left_child();
  node p5 = p2->get_right_child();
  p4->set_left_child(-6);
  p4->set_right_child(22);
  p3->set_left_child(544);
  node p6 = p3->get_left_child();
  p6->set_left_child(11);
  // Print the entire Binary Tree structure starting with it's root
  root.print();


}
