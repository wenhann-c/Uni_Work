#include <simpler_graph/simpler_graph.hpp>

#define FMT_HEADER_ONLY  // Dieses Makro ist nötig, um die Bibliothek simpel einzubinden
#include <fmt/core.h>    // Muss eingebunden werden um {fmt} zu verwenden
#include <fmt/ranges.h>  // Muss zur Ausgabe von Arrays eingebunden werden
#include <vector>        // Stellt dynamische Arrays zur Verfügung
#include <iostream>

// This is used to capture the number that we want to check by choice
int input() {
    std::cout << "Type in the number: ";
    int a;
    std::cin >> a;
    return a;
}

int main() {
  // Calling this funciton to create a directed graph of 5 nodes
  SimplerGraph::SimplerGraph g(5);
  // These are called to add different edges rather than just the ones created as to add complexity
  g.add_edges(0,2);
  g.add_edges(4,2);
  g.add_edges(1,3);
  g.add_edges(3,0);
  g.add_edges(4,0);
  // Print all the nodes exists
  g.print_knots();
  // Print all the edges exists
  g.print_edges();
  // Capturing input as the chosen number(node) to carry out BFS
  int target = input();

  // Nutzen Sie die {fmt}-Library um das Array auszugeben
  fmt::print("{0}{1}{2}","The following are Breadth First Traversal starting from node ", fmt::join(g.breadth_search(target), "~>"), '\n');
}
