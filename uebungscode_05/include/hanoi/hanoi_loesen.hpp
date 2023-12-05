#pragma once

#include <hanoi/hanoi.hpp>

namespace hanoi{
  // Hier soll(en) die Funktion(en) für die Lösungsstrategie deklariert werden.
  void Hanoi_solution(size_t anz, Hanoi& h, int a, int c, int b);   //an algorithm to solve the hanoi tower game
}
