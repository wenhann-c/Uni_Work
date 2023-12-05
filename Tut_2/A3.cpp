// Zur Blatt 02 Aufgabe 03

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// Druckt einen Text aus
void drucke_text(const std::string& text);

// Druckt eine Ganzzahl aus
void drucke_ganzzahl(int ganzzahl);

// Druckt eine Kommazahl aus
void drucke_kommazahl(double gleitkommazahl);

// Liest ein Wort von der Konsole ein
std::string lies_wort();

// Liest eine Ganzzahl von der Konsole ein
int lies_ganzzahl();

// Liest eine Gleitkommazahl von der Konsole ein
double lies_gleitkommazahl();


void ablauf_diagram_1(){

  // Declaration statement und Expression statement
  double x;
  // Druct den Text aus
  drucke_text("Geben Sie eine Nummer ein: ");
  // Expression statement und liest die eingegebene Zahl
  x = lies_gleitkommazahl();
  // Berechnet das Quadrat der Zahl
  x = x*x;
  // Druckt die Antwort
  drucke_kommazahl(x);

}

void ablauf_diagram_2(){

  // Declaration statement und Expression statement
  double x;
  // Druct den Text aus
  drucke_text("Geben Sie eine Nummer ein: ");
  // Expression statement und liest die eingegebene Zahl
  x = lies_gleitkommazahl();
  // Algorithmen aus Tut 1, Iteration statement
  while (x > 1) {
      x = x - 2;    
  }
  // Druckt die Antwort
  drucke_kommazahl(x);
  // Selection statement
  if ( x == 0 ) {
    drucke_text( "Die Nummer ist gerade" );
  }

  else if ( x == 1 ) {
    drucke_text( "Die Nummer ist ungerade" );
  }
  
  else {
    drucke_text( "Die Nummer ist kleiner als 1" );
  }
  
}

void programm_1() {

  // Declaration statement und Expression statement
  int x;
  int y;
  // Druct den Text aus
  drucke_text("Geben Sie eine Nummer ein: ");
  // Expression statement und liest die eingegebene Zahl
  x = lies_ganzzahl();
  // Algorithmen aus Tut 1
  y = x;
  y = y + 17;
  y = y * 3;
  y = y % 2;
  // Druckt die Antwort
  drucke_ganzzahl(y);
  // Selection statement
  if ( y == 0 ) {
    drucke_text( "Die Nummer ist ungerade" );
  }

  else if ( y == 1 ) {
    drucke_text( "Die Nummer ist gerade" );
  }
  
}


void programm_2() {
  
  // Declaration statement und Expression statement
  std::string text = "Das Modul Algorithmen und Programmierung ist so konzipert, dass die Konzepte und Methodiken\
der objektorientierten Programmierung im Vordergrund stehen. Die hier vorgestellte\
Programmiersprache C++ nimmt die Rolle einer Beispielprogrammiersprache ein, in der die\
diskutierten Konzepte (meist mehr, selten weniger) nachvollziehbar und effizient umgesetzt\
sind. Das Modul soll so verstanden werden, dass es den Teilnehmer:innen im Anschluss an\
dieses Modul leicht fällt andere, objektorientierte Programmiersprachen zu erlernen. Hier soll\
man sich nur noch die Frage stellen: Wie setzten andere Programmiersprachen die wesentlichen\
Konzepte um und was gibt es bei der Sprachsyntax zu beachten?";
  unsigned long i = 0;
  int s = 0;
  // Algorithmen aus Tut 1, Iteration statement
  while ( i < text.length() ) {
    
  // Selection statement  
    if ( text[i] == '.' || text[i] == '!' || text[i] == '?' )
      s = s + 1;

    // Increment
    i++;
  }
  // Druckt die Antwort
  drucke_ganzzahl(s);
  
}


void programm_3() {
  
  // Declaration statement und Expression statement
  std::vector<int> zahlen = {42, 69, 420, 99, -444, 9014};
  unsigned long i = 0;
  double s = 0;
  // Algorithmen aus Tut 1, Iteration statement
  while ( i < zahlen.size() ) {
    
    s = s + zahlen[i];

    // Increment
    i++;
  }
  // Druckt die Antwort
  drucke_kommazahl( s / zahlen.size() );
  
}


void programm_4() {

  // Declaration statement und Expression statement
  double x;
  double t;
  // Druct den Text aus
  drucke_text("Geben Sie eine Nummer ein: ");
  // Expression statement und liest die eingegebene Zahl
  x = lies_gleitkommazahl();
  // Algorithmen aus Tut 1
  t = x;
  t = t * t;
  t = x * t;
  t = t * t;
  t = t * t;
  t = x * t;
  t = t * t;
  t = x * t;
  t = t * t;
  t = t * t;
  t = x * t;
  t = t * t;
  // Druckt die Antwort
  drucke_kommazahl(t);
  std::cout << static_cast<float>(t) << std::endl;

}


int main() {
  ablauf_diagram_1();
  ablauf_diagram_2();
  programm_1();
  programm_2();
  programm_3();
  programm_4();
}


/************************************/
/*                                  */
/*   MAGIE   MAGIE   MAGIE  MAGIE   */
/*                                  */
/************************************/

void drucke_text(const std::string& text) {
  std::cout << text << std::endl;
}

void drucke_ganzzahl(int ganzzahl) {
  std::cout << std::to_string(ganzzahl) << std::endl;
}

void drucke_kommazahl(double gleitkommazahl) {
  std::cout << std::to_string(gleitkommazahl) << std::endl;
}

std::string lies_wort() {
  std::string wort;
  std::cin >> wort;
  return wort;
}

int lies_ganzzahl() {
  std::string wort;
  std::cin >> wort;
  int ganzzahl = 0;
  try {
    ganzzahl = std::stoi(wort);
  } catch (const std::invalid_argument& e) {
    ganzzahl = -1000;
  }
  return ganzzahl;
}

double lies_gleitkommazahl() {
  std::string wort;
  std::cin >> wort;
  double lies_gleitkommazahl = 0.0;
  try {
    lies_gleitkommazahl = std::stod(wort);
  } catch (const std::invalid_argument& e) {
    lies_gleitkommazahl = NAN; // See https://en.cppreference.com/w/cpp/numeric/math/NAN
  }
  return lies_gleitkommazahl;
}
