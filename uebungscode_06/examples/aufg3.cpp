#include <simpler_graph/simpler_graph.hpp>

#include <iostream>


int main() {
  // Call simplergraph function and giving 5 as input of number of knots in a graph
  SimplerGraph::SimplerGraph g(5);
  g.print_knots();
  g.print_edges();
  g.add_edges(0,2);
  g.print_edges();
  g.add_edges(1,3);
  g.print_edges();
  g.add_edges(5,1);
  g.print_edges();
  g.add_edges(4,0);
  g.print_edges();
  g.kill_edges(1,2);
  g.print_edges();
  g.kill_edges(0,1);
  g.print_edges();
  g.print_knots();
  g.kill_knots(0);
  g.print_knots();
  g.print_edges();
  g.kill_knots(2);
  g.print_knots();
  g.print_edges();
  g.kill_knots(4);
  g.print_knots();
  g.print_edges();
  g.kill_knots(1);
  g.print_knots();
  g.print_edges();
}
