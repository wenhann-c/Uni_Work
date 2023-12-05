#pragma once

#include <vector>

// Hier kommt die Deklaration (und Beschreibung) von mergesort hin
// Declared merge function in order to merge different vectors together
std::vector<int> merge(std::vector<int> l, std::vector<int> r);
// Declared mergesort function in order to sort and split the given vector
std::vector<int> mergesort(std::vector<int> v);

