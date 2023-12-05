#include <iostream>

#include <hanoi/hanoi.hpp>
#include <hanoi/hanoi_loesen.hpp>

int main(int, char**) {
  size_t anz = 5;
  hanoi::Hanoi h(anz);
  h.drucke();
  Hanoi_solution(anz, h, 0, 2, 1);
  return 0;
}
