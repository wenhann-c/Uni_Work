#include <hanoi/hanoi.hpp>
#include <hanoi/hanoi_loesen.hpp>
#include <iostream>

namespace hanoi{
  void Hanoi_solution(size_t anz, Hanoi& h, int a, int c, int b){ //an algorithm to solve the hanoi tower game
    
    if( anz == 1 ){
      h.bewege(a,c);
      h.drucke();
      return;
    }
    Hanoi_solution(anz-1, h, a, b, c);
    h.bewege(a,c);
    h.drucke();
    Hanoi_solution(anz-1, h, b, c, a);
  }
}
