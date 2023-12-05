#include <iostream>
#include <string_view>

void print(const std::string_view& a)  // print function
{
    std::cout << a << std::endl;
}

int main()
{
    while (true)            //Iteration statement
    {
        int x;              // Declaration statement
        x = 1815;           // Expression statement: Ada's birthyear
        
        int y{};

        std::cout << "Guess Ada's Birthyear : ";
        std::cin >> y;

        if ( x > y )        // Selection statement
            print("Ada is younger");

        else if ( x < y )
            print("Ada is older");
        
        else if ( x == y )
            {
            print("That is correct!");
            return 0;
            }

        std::cout << "Guess again[Y/n]?: ";
        char z{};
        std::cin >> z;

        if ( z == 'n' )
            return 0;
    }

    return 0;
}
