#include <iostream>
#include <vector>
#include <string>

void print_vector(const std::vector<int>& a) {

    for (const int& zahl : a) {

        std::cout << zahl << " ";
    }

    std::cout << '\n';
}

void change_vector(std::vector<int>& a) {

    for (int& zahl : a) {

        zahl += 40;
    }

}

void print_vector(const std::vector<std::string>& a) {

    for (const std::string& farbe : a) {

        std::cout << farbe << " ";
    }

    std::cout << '\n';
}

void until_42(std::vector<int>& a) {

    int i = 0;
    int b = i;
    int n = a.size();

    while(a[i] != 42) {
         
         b = i + 1;
         i++;
    }

    for(i = 1; i < n - b; i++) {

        a.pop_back();
    }
    
}

int main() {

    std::vector<int> x = {1, 3, 4, 5, 6, 2, 7, 2, 8};
    std::vector<std::string> y = {"Red", "Blue", "Green"};
    print_vector(x);
    change_vector(x);
    print_vector(x);
    print_vector(y);
    until_42(x);
    print_vector(x);

    return 0;
}
