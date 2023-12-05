#include <hanoi/hanoi.hpp>
#include <iostream>
#include <string>
#include <unistd.h>

namespace hanoi{

Hanoi::Hanoi(size_t anz) {      // the function to declare Hanoi class

    stapel = std::vector<std::vector<size_t>>(3);       //generating 3 poles(3 arrays with arrays within them)
    stapel[0] = std::vector<size_t>(anz);               //declaring an empty array in the first pole
    stapel[1] = std::vector<size_t>(anz);               //declaring an empty array in the second pole
    stapel[2] = std::vector<size_t>(anz);               //declaring an empty array in the third pole
    size_t i = anz;                                     //declaring i as the number of discs wished to be played

    for(auto& x : stapel[0]) {                          //insert an array of {5,4,3,2,1}

        x = i;
        i--;
    }

}

bool Hanoi::bewege(size_t von, size_t nach) {           //move one disc from a chosen pole(von) to another chosen pole(nach)

    size_t top_plate_von = 0;
    size_t top_plate_nach = 0;
    int b = 0;
    int c = 0;
    size_t n = stapel[0].size();
    
    for (int i = 0;i < n; i++) {                        //getting the top first disc on the von pole
        if (stapel[von][i] != 0) {                      //as long as no zero(empty spaces), the first number is the top first disc
        b = i;
        }
    }
    top_plate_von = stapel[von][b];                     //found the top disc of von pole

    for (int i = 0;i < n; i++) {                        //getting the top first disc on the nach pole
        if (stapel[nach][i] != 0) {                     //as long as no zero(empty spaces), the first number is the top first disc
            c = i;
        }
    }
    top_plate_nach = stapel[nach][c];                   //found the top disc of nach pole

    if (stapel[von].front() == 0) {                     //check if the lowest disk of von pole is empty
        std::cout << "This pole is empty" << std::endl;
    }
    else if (stapel[nach].back() == 1) {                //check if the nach pole is full with discs(which technically wouldn't be used, since the von pole would already be found to be empty)
        std::cout << "This pole is full" << std::endl;
    }
    else if (stapel[nach].front() == 0) {               //check if the nach pole is empty
        std::cout << "Allowed" << std::endl;
        stapel[nach].front() = stapel[von][b];          //replace the lowest empty space with the top first disc of von pole
        stapel[von][b] = 0;                             //replace the top first disc of von with empty space
    }
    else if (top_plate_von < top_plate_nach) {          //check if the top first disc of von is smaller than top first disc of nach
        std::cout << "Allowed" << std::endl;
        stapel[nach][c + 1] = stapel[von][b];           //replace the empty spaces above the top first disc of nach with the top first disc of von
        stapel[von][b] = 0;                             //replace the top first disc of von with empty space
    }
    else if (top_plate_von > top_plate_nach) {          //check if the top first disc of von is larger than top first disc of nach
        std::cout << "Not Allowed" << std::endl;
    }
    
    return true;
}
    
    
void Hanoi::drucke() const {                            //print the image of the hanoi tower
    
    size_t n = stapel[0].size();                        //getting the size of the discs that is wished to be played
    for (int i = n - 1; i >= 0; i--) {                  //range based - loop
        std::cout << stapel[0][i] << " " <<stapel[1][i] << " " <<stapel[2][i] << std::endl; //printing three poles
        usleep(200000);
    }
}

}
