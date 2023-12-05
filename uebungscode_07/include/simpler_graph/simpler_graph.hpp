#pragma once

// Ihre Implementierung
#include <vector>
#include <cstddef>

namespace SimplerGraph{
  
  class SimplerGraph{
  public:
    // Erstellt einen Graph mit einer festen Knotenanzahl
    SimplerGraph(size_t knoten_anzahl);
    // Print knots
    void print_knots();
    // Print edges
    void print_edges();
    // Add new edge
    void add_edges(size_t a, size_t b);
    // Delete chosed edge
    void kill_edges(size_t a, size_t b);
    // Delete chosed knot
    void kill_knots(size_t a);
    // Declared knots as variable
    std::vector<size_t> v;
    // Declared edges as variable
    std::vector<std::vector<bool>> e;
    // Declared depth first search function
    std::vector<int> depth_search(int target);
    // Declared breadth first search function
    std::vector<int> breadth_search(int target);
    // Declared path of DFS
    std::vector<int> path;
    // Declared used function of DFS
    std::vector<bool> depth_used{false};

  private:
    // Declared number of knots as variable
    const size_t knoten_anz;
  };
}
