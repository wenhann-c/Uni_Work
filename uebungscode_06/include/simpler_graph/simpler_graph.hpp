#pragma once

#include <vector>
#include <cstddef>

namespace SimplerGraph{
  
  class SimplerGraph{
  public:
    // Erstellt einen Graph mit einer festen Knotenanzahl
    SimplerGraph(size_t knoten_anzahl);
    // Print knots
    void print_knots();
    // Print Edges
    void print_edges();
    // Add new edge
    void add_edges(int a, int b);
    // Delete chosed edge
    void kill_edges(int a, int b);
    // Delete chosed knot
    void kill_knots(int a);

  private:
    // Declared number of knots as variable
    const size_t knoten_anz;
    // Declared knots as variable
    std::vector<int> v;
    // Declared edges as variables
    std::vector<std::vector<bool>> e;
  };
}
