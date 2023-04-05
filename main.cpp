#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <utility>

class Graph
{
  public:
    int numVertices;
    int infinity = 1000000;
    std::list<std::pair<int,int>> *adjacent;

    Graph(int _numVertices) {
      numVertices = _numVertices;
      adjacent = new std::list<std::pair<int, int>>[numVertices];
    }

  // Function to add an edge to graph
    void addEdge(int u, int v, int w){
      //first = vertex, second = weight
      adjacent[u].push_back(std::make_pair(v,w));
      adjacent[v].push_back(std::make_pair(u,w));
    }

  // Print MST using Prim's algorithm
    void primMST(){
      std::vector<int> cost(numVertices, infinity);
      std::vector<int> prev(numVertices, NULL);
      std::vector<bool> known(numVertices, false);

      int start = 0;
      cost[start] = 0;

      std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> priorityQueue;

      //first = weight, second = vertex
      priorityQueue.push(std::make_pair(0, start));

      while (!priorityQueue.empty()) {
        int v = priorityQueue.top().second;
        priorityQueue.pop();

        if (!known[v]) {
          known[v] = true;
          int n = adjacent[v].size();
          for (int i = 0; i < n; i++) {
            int z = adjacent[v].front().first;
            int zNewCost = adjacent[v].front().second;
            if (cost[z] > zNewCost && !known[z]) {
              cost[z] = zNewCost;
              prev[z] = v;
              priorityQueue.push(std::make_pair(cost[z], z));
            }
            adjacent[v].pop_front();
          }
        }
      }
      
      for (int i = 1; i < numVertices; i++) {
        std::cout << prev[i] << " - " << i << " | " << cost[i] << std::endl;
      }
    }
};

int main() {
  int numVertices = 9;
  Graph g(numVertices);
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
