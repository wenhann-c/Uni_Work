#include <misc/zeitmesser.hpp>
#include <vector>
#include <iostream>

void print_vector(const std::vector<int>& a) {

    for (const int& zahl : a) {

        std::cout << zahl << " ";
    }

    std::cout << '\n';
}

// Min Sort out of place
std::vector<int> int_array_min_sort_out_of_place(const std::vector<int>& input) {
    
    const int laenge = input.size();

    // Array der als Lösung erzeugt wird
    std::vector<int> loesung (laenge);

    // Bereits verwendete Elemente werden markiert
    std::vector<bool> verwendet (laenge, false); // Alle Einträge sind mit false initalisiert

    // Iteriert durch das Array
    for (int i = 0; i < laenge; i++) {

        // Finde den Index des ersten, noch nicht verwendeten Element
        int min_idx;
        for (min_idx = 0; verwendet[min_idx] == true; min_idx++) {

        }
        // Finde ab dort den Index des kleinsten, unverwendeten Element
        for (int j = min_idx + 1; j < laenge; j++) {
            if ( (verwendet[j] == false) && (input[min_idx] > input[j]) ) {
                min_idx = j; // Element bei j ist unverwendet und kleiner
            }
        }
        // Schreibe das kleinste, unverwendete Element in die Lösung
        loesung[i] = input[min_idx];
        // Markiere das kleinste, unverwendete Element als verwendet
        verwendet[min_idx] = true;
    }
    return loesung;
}

int main() {
    // Declared Zeitmesser function
    misc::Zeitmesser Zeitmesser;
    // Zeitmesser starts here
    Zeitmesser.start();
    // Declaring and giving vector input
    std::vector<int> input = {2, 1, 3, 6, 25, 15, 2, 0, 9};
    // Declaring x and calling min sort out of place function
    std::vector<int> x = int_array_min_sort_out_of_place(input);
    // Print vector
    print_vector(x);
    // Stop Zeitmesser
    Zeitmesser.stop();
    // Print the recorded time in minutes, seconds, milliseconds and microseconds
    std::cout << Zeitmesser.get_minutes() << std::endl;
    std::cout << Zeitmesser.get_seconds() << std::endl;
    std::cout << Zeitmesser.get_milliseconds() << std::endl;
    std::cout << Zeitmesser.get_microseconds() << std::endl;
    return 0;
}
