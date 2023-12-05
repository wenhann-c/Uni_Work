#include <meine_funktionen.hpp>
#include <iostream>

double sinus(double x, double small){                           // Declaration of sine function

    double sine = 0;                                            // Declaration of sine, helper and summand
    double helper = 1;
    double summand = x;

    while ( summand > small || -summand > small ) {             // Expressing the condition in order to continue the loop
        
        sine += summand;                                        // The taylor series algorithm of sine function
        summand = -(summand*x*x) / ((helper+1) * (helper+2));
        helper += 2;
    }

    return sine;                                                // Return the nearest answer to sine after the loop broke
}

double kosinus(double x, double small){                         // Declaration of cosine function
    
    double cosine = 0;                                          // Declaration of cosine, helper and summand
    double helper = 0;
    double summand = 1;

    while ( summand > small || -summand > small ) {             // Expressing the condition in order to continue the loop
        
        cosine += summand;                                      // The taylor series algorithm of sine function
        summand = -(summand*x*x) / ((helper+1) * (helper+2));
        helper += 2;
    }

    return cosine;                                              // Return the nearest answer to cosine after the loop broke
}

double tangens(double x, double small){                         // Declaration of tangent function

    return sinus(x, small) / kosinus(x, small);                 // Sine of a value divide by cosine of the same value equals tangent of that value
}

double kotangens(double x, double small){                       // Declaration of cotangent function

    return kosinus(x, small) / sinus(x, small);                 // Cotangent is the reciprocal of tangent
}

double sinus(double x){                                         // Declaration of sine function with different parameters(overloading)

    return sinus(x, 1e-8);                                      // return function with a default tolerance value 1e-8
}
double kosinus(double x){                                       // Declaration of cosine function with different parameters(overloading)
    
    return kosinus(x, 1e-8);                                    // return function with a default tolerance value 1e-8
}

double tangens(double x){                                       // Declaration of tangent function with different parameters(overloading)

    return sinus(x) / kosinus(x);                               // return function with a default tolerance value 1e-8
}

double kotangens(double x){                                     // Declaration of cotangent function with different parameters(overloading)

    return kosinus(x) / sinus(x);                               // return function with a default tolerance value 1e-8
}
