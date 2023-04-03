#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;
#define inf 10000
class Graph
{
  //number of vertices
  int V;
  // Adjacency list representation
  // Pair of a neighbor vertex and a weight for every edge
  list<pair<int, int>> *adj;
  vector<int> visited;
  vector<int> notVisited;
  public:
    Graph(int V);
  // Function to add an edge to graph
    void addEdge(int u, int v, int w){
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
    }
  // Print MST using Prim's algorithm
    void primMST(){



    }
};
// Allocates memory for adjacency list
Graph::Graph(int V)
{
  this->V = V;
  adj = new list<pair<int, int>> [V];
}

int main() {
  int V = 8;
  Graph g(V);
  g.addEdge(0, 1, 5);
  g.addEdge(0, 2, 9);
  g.addEdge(1, 4, 9);
  g.addEdge(1, 2, 12);
  g.addEdge(4, 7, 8);
  g.addEdge(2, 3, 8);
  g.addEdge(2, 5, 2);
  g.addEdge(3, 4, 3);
  g.addEdge(3, 5, 7);
  g.addEdge(4, 7, 8);
  g.addEdge(4, 6, 5);
  g.addEdge(5, 6, 3);
  g.addEdge(6, 7, 15);
  g.addEdge(6, 8, 11);
  g.addEdge(7, 8, 10);
  g.primMST();
return 0;
}