#include<vector>
using namespace std;

int main() {
  // Matrix 
  int grid[4][4] = {
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 1},
    {0, 1, 0, 0},
  };

  // Adjacency matrix
  int adjMatrix[4][4] = {
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 1},
    {0, 1, 0, 0},
  };

  return 0;
}

class GraphNode {
public:
    int val_;
    vector<GraphNode*> neighbors_;

    GraphNode(int val) {
        val_ = val;
    }
};
