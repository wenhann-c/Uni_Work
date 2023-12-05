#include <iostream>

#include <hanoi/hanoi.hpp>

int main(int, char**) {
  hanoi::Hanoi h(5);
  h.drucke();
  
  h.bewege(0,1);
  h.drucke();
  h.bewege(0,1); // Illegale Bewegung
  h.drucke();
  h.bewege(0,2);
  h.drucke();
  
  h.bewege(1,2);
  h.drucke();
  
  h.bewege(0,1);
  h.drucke();
  h.bewege(2,0);
  h.drucke();
  h.bewege(2,1);
  h.drucke();
  h.bewege(0,1);
  h.drucke();
}
