#include <misc/zeitmesser.hpp>
#include <mergesort.hpp>
#include <misc/hilfsfunktionen.hpp>
#include <vector>
#include <iostream>

int main() {
  // Declared Zeitmesser function
  misc::Zeitmesser Zeitmesser;
  // Zeitmesser starts here
  Zeitmesser.start();
  // Declaring and giving number of elements in vector as input
  std::vector<int> bsp_zahlen(4000);
  misc::fuelle_zufaellig(bsp_zahlen);
  misc::drucke_array(bsp_zahlen);
  // Declared merged as the final returned value of the mergesort function
  std::vector<int> merged = mergesort(bsp_zahlen);
  misc::drucke_array(merged);
  // Stop Zeitmesser
  Zeitmesser.stop();
  // Print the recorded time in minutes, seconds, milliseconds and microseconds
  std::cout << Zeitmesser.get_minutes() << std::endl;
  std::cout << Zeitmesser.get_seconds() << std::endl;
  std::cout << Zeitmesser.get_milliseconds() << std::endl;
  std::cout << Zeitmesser.get_microseconds() << std::endl;

}
