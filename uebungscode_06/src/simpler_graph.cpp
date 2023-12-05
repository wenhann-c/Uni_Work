#include <simpler_graph/simpler_graph.hpp>
#include <iostream>


namespace SimplerGraph {
  SimplerGraph::SimplerGraph(size_t knoten_anzahl) :
    knoten_anz(knoten_anzahl)
  {
    v = std::vector<int>(knoten_anz);
    e = std::vector<std::vector<bool>>(knoten_anz, std::vector<bool>(knoten_anz, false));
    int i = 0;
    for (auto& x : v) {
      x = i;
      i++;
    }
    for (int j = 0 ; j < knoten_anz - 1 ; j++) {
      e[j][j+1] = true;
    }
  }

  void SimplerGraph::print_knots() {
    std::cout << "The knots are: { ";
    for (const int& x: v) {
      std::cout << x << " ";
    }
    std::cout << "}" << std::endl;
  }

  void SimplerGraph::print_edges() {
    std::cout << "The edges are: { ";
    for (int l = 0 ; l < knoten_anz ; l++) {
      for (int r = 0; r < knoten_anz ; r++) {
        if (e[l][r] == true) {
          std::cout << "(" << l << "," << r << ") ";
        }
      }
    }
    std::cout << "}" << std::endl;
  }

  void SimplerGraph::add_edges(int a, int b) {
    if ( a < knoten_anz && b < knoten_anz ) {
      e[a][b] = true;
    }
    else {
      std::cout << "Knots don't exist" << std::endl;
    }
  }

  void SimplerGraph::kill_edges(int a, int b) {
    if ( a < knoten_anz && b < knoten_anz ) {
      e[a][b] = false;
    }
    else {
      std::cout << "Knots don't exist" << std::endl;
    }
  }

  void SimplerGraph::kill_knots(int a) {
    std::vector<int> v2;
    if ( a < knoten_anz) {
      for (int y = 0 ; y < knoten_anz ; y++) {
        if ( v[y] == a ) {
          for (auto x : v) {
            kill_edges(a,x);
            kill_edges(x,a);
            if (x != a) {
              v2.push_back(x);
            }
          }
          v.clear();
          v = v2;
          v2.clear();
        }
      }
    }
    else {
      std::cout << "Knots don't exist" << std::endl;
    }
  }
}
