#include <minsort_in_place.hpp>
#include <vector>

// Hier wird minsort in place implementiert
std::vector<int> int_array_min_sort_in_place(std::vector<int> &input)
{
    // The size of array
    const int laenge = input.size();
    // Declaring a temporary storage to store number
    std::vector<int> temp(1);
    // Iteriert durch das Array
    for (int i = 0; i < laenge; i++)
    {
        // Declaring min_idx
        int min_idx = i;
        // Finde ab dort den Index des kleinsten nummer
        for (int j = min_idx + 1; j < laenge; j++)
        {
            if (input[min_idx] > input[j])
            {
                min_idx = j;
            }
        }
        // Create a temporary storage to store the number that is going to replaced by the minimum number
        temp[0] = input[i];
        // Take the minimum number and move it to the index based on the current time of iteration
        input[i] = input[min_idx];
        // Take the number in temporary storage and put it in the index of the minimum number
        input[min_idx] = temp[0];
    }
    return input;
}
