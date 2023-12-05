#include <meine_funktionen.hpp>
#include <iostream>

int main() {
  // Hier Sinus, Kosius, usw für einige Werte ausrechnen
  // und Ergebnisse ausdrucken
  char a;                                                                               // declaration of a(user's respond), k(tolerance value) and z(input number)
  double k;
  double z;
  std::cout << "Insert a number: ";
  std::cin >> z;                                                                        // read the input number
  std::cout << "Do you want to define your own tolerance value[Y/n]?: ";                // asking if tolerance value should be defined by user or goes by default
  std::cin >> a;                                                                        // read yes or no

  if ( a == 'n' ) {                                                                     // if no, all answers are shown with tolerance value of 1e-8
      std::cout << "The sine of " << z << " is " << sinus(z) << std::endl;              // sine of z is shown
      std::cout << "The cosine of " << z << " is " << kosinus(z) << std::endl;          // cosine of z is shown
      std::cout << "The tangent of " << z << " is " << tangens(z) << std::endl;         // tangent of z is shown
      std::cout << "The cotangent of " << z << " is " << kotangens(z) << std::endl;     // cotangent of z is shown
      
      return 0;
  }

  else {                                                                                // if yes, all answers are shown with tolerance value that is defined by user
      std::cout << "Insert the tolerance value: ";
      std::cin >> k;                                                                    // read the user-define tolerance value
      std::cout << "The sine of " << z << " is " << sinus(z, k) << std::endl;           // sine of z is shown
      std::cout << "The cosine of " << z << " is " << kosinus(z, k) << std::endl;       // cosine of z is shown
      std::cout << "The tangent of " << z << " is " << tangens(z, k) << std::endl;      // tangent of z is shown
      std::cout << "The cotangent of " << z << " is " << kotangens(z, k) << std::endl;  // cotangent of z is shown

      return 0;
  }


  return 0;
}
