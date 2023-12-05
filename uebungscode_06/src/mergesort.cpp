#include <mergesort.hpp>

#include <vector>

// Hier wird mergesort implementiert
std::vector<int> merge(std::vector<int> l, std::vector<int> r) {
    
    std::vector<int> merged;
    int i = 0;
    int j = 0;
    while (i < l.size() && j < r.size()) {
        if ( l[i] < r[j] ) {
            merged.push_back(l[i]);
            i++;
        }
        else {
            merged.push_back(r[j]);
            j++;
        }
    }
    while (i < l.size()) {
        merged.push_back(l[i]);
        i++;
    }
    while (j < r.size()) {
        merged.push_back(r[j]);
        j++;
    }
    return merged;
}

std::vector<int> mergesort(std::vector<int> v) {
    
    const size_t& n = v.size();
    if ( n > 1 ){
       std::vector<int> left;
       std::vector<int> right;
       for(int i = 0; i < n; i++) {
        if ( i < n / 2 ) {
            left.push_back(v[i]);
        }
        else {
            right.push_back(v[i]);
        }
       }
       return merge(mergesort(left), mergesort(right));
    }
    else {
        return v;
    }
    
}
