#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Vertex {
  public:
    int cost = std::numeric_limits<int>::max();
    Vertex * prev;
    
    Vertex() {

    }
};

class Edge {
  public:
    int weight;
};

class Graph
{
  public:
    vector<Vertex*> verticies;
    Graph(int V) {
      for (int i = 0; i <= V; i++) {
        verticies.push_back(new Vertex());
      }
      
    }
  // Function to add an edge to graph
    void addEdge(int u, int v, int weight){
      
    }

  // Print MST using Prim's algorithm
    void primMST(){
      
    }
};

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