#include <misc/zeitmesser.hpp>
#include <misc/schnellsort.hpp>
#include <misc/hilfsfunktionen.hpp>
#include <iostream>
#include <algorithm>


int main() {
  // Declared Zeitmesser function
  misc::Zeitmesser Zeitmesser;
  // Zeitmesser starts here
  Zeitmesser.start();
  std::vector<int> bsp_zahlen(4000);
  misc::fuelle_zufaellig(bsp_zahlen);
  misc::drucke_array(bsp_zahlen);
  misc::schnellsort(bsp_zahlen);
  misc::drucke_array(bsp_zahlen);
  // Stop Zeitmesser
  Zeitmesser.stop();
  // Print the recorded time in minutes, seconds, milliseconds and microseconds
  std::cout << Zeitmesser.get_minutes() << std::endl;
  std::cout << Zeitmesser.get_seconds() << std::endl;
  std::cout << Zeitmesser.get_milliseconds() << std::endl;
  std::cout << Zeitmesser.get_microseconds() << std::endl;
}
