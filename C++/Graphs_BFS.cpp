#include "iostream"
#include "ADT/queue.h" // Queue ADT for queue operations
using namespace std;

int main ()
{
    Queue exploration_q; // Exploration queue
    int visited[7]={0,0,0,0,0,0,0}; // The 0th index represent the 0th node
    // 0 => the node is unvisited
    
    // -- Creating the Graph --- ADJACENCY MATRIX
    int Graph [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };

    //  ----   BFS Implementation -------
    int node;
    int i=0; // Starting the BFS with Vertex: 0
    visited[i]=1; // Marking the Vertex: 0 has been visited
    exploration_q.enqueue(i); // Marking Vertex : 0 for exploration
    cout << i << endl; // Printing the first Vertex

    while (exploration_q.isEmpty()!=1)
    {
        node=exploration_q.dequeue();
        for (int j = 0; j < 7; j++) {
            if (Graph[node][j]==1 && visited[j]==0)
            {
                cout << j << endl;
                visited[j]=1; // Marking we've visited the vertex j
                exploration_q.enqueue(j); // Put the visited vertex for Exploration
            }
            
        }
    }

    return 0;
}
