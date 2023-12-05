#include <simpler_graph/simpler_graph.hpp>

// Ihre Implementierung
#include <simpler_graph/simpler_graph.hpp>
#include <iostream>
#include <queue>


namespace SimplerGraph {
  // Create a directed graph of {0->1->2->3->4->...->n}
  SimplerGraph::SimplerGraph(size_t knoten_anzahl) :
    knoten_anz(knoten_anzahl)
  {
    v = std::vector<size_t>(knoten_anz);
    e = std::vector<std::vector<bool>>(knoten_anz, std::vector<bool>(knoten_anz, false));
    size_t i = 0;
    for (auto& x : v) {
      x = i;
      i++;
    }
    for (size_t j = 0 ; j < knoten_anz - 1 ; j++) {
      e[v[j]][v[j+1]] = true;
    }
  }

  // Printing nodes using a range based for loop
  void SimplerGraph::print_knots() {
    std::cout << "The nodes are: { ";
    for (const size_t& x: v) {
      std::cout << x << " ";
    }
    std::cout << "}" << std::endl;
  }

  // Printing edges using two range based for loops
  void SimplerGraph::print_edges() {
    std::cout << "The edges are: { ";
    for (size_t l = 0 ; l < knoten_anz ; l++) {
      for (size_t r = 0; r < knoten_anz ; r++) {
        if (e[l][r] == true) {
          std::cout << "(" << l << "," << r << ") ";
        }
      }
    }
    std::cout << "}" << std::endl;
  }

  // Adding edges by changing the edge status from false to true in the e matrix
  void SimplerGraph::add_edges(size_t a, size_t b) {
    if ( a < knoten_anz && b < knoten_anz ) {
      e[a][b] = true;
    }
    else {
      std::cout << "Nodes don't exist" << std::endl;
    }
  }

  // Deleting edge by changing the edge status from true to false in the e matrix
  void SimplerGraph::kill_edges(size_t a, size_t b) {
    if ( a < knoten_anz && b < knoten_anz ) {
      e[a][b] = false;
    }
    else {
      std::cout << "Knots don't exist" << std::endl;
    }
  }

  // Deleting node by changing the status of edges that contain the node to false and using erase function to delete from v vector
  void SimplerGraph::kill_knots(size_t a) {
    if ( a < knoten_anz ) {
      for (size_t y = 0 ; y < knoten_anz ; y++) {
        if ( v[y] == a ) {
          for (auto x : v) {
            kill_edges(a,x);
            kill_edges(x,a);
          }
          v.erase(v.begin()+y);
        }
      }
    }
    else {
      std::cout << "Knots don't exist" << std::endl;
    }
  }

  // BFS Algorithm using queue
  std::vector<int> SimplerGraph::breadth_search(int target) {
    // Declared path for BFS
    std::vector<int> path;
    // Declared queue
    std::queue<int> queue;
    // Declared used as a function to know if the nodes are checked and all are initialized as false
    std::vector<bool> used (v.size(), false);
    // The chosen node is set as true because it is checked
    used[target] = true;
    // The chosen node is pushed into the queue
    queue.push(target);
    // The chosen node is pushed into the path vector
    path.push_back(target);
    // Check if the queue is all cleared
    while (queue.empty() == false) {
      // Declared the first element of the queue as top
      int top = queue.front();
      // Delete the first element of queue
      queue.pop();
      // Range based for loop to find the adjacent node of top
      for (auto& x : v) {
        if (e[top][x] == true) {
          // Check if the adjacent node is checked
          if (used[x] == false) {
            // Set the adjacent node as checked because it is checked
            used[x] = true;
            // The adjacent node is pushed into the queue
            queue.push(x);
            // The adjacent node is pushed into the path vector
            path.push_back(x);
          }
        }
      }
    }
    // Return path vector
    return path;
  }

  // DFS Algorithm using recursion
  std::vector<int> SimplerGraph::depth_search(int target) {
    // Set the chosen node as true
    depth_used[target] = true;
    // The chosen node is pushed into the path vector
    path.push_back(target);
    // Range based for loop to find the first adjacent node of target
    for (auto& x : v) {
      if (e[target][x] == true) {
        // Use recursion to maintain the priority of finding the first adjacent node of previous adjacent node
        if (depth_used[x] == false) {
          depth_search(x);
        }
      }
    }
    // Return path vector
    return path;
  }
}
