#include <stdio.h>
#include <stdlib.h>

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

int visited[70]={0,0,0,0,0,0,0};

// DFS Function
void DFS(int i){
    // We're using the stack which is automatically created by the
    // recursive function
    printf("%d\n",i);
    visited[i]=1;
    for (int j = 0; j < 7; j++) {
        if (Graph[i][j]==1 && visited[j]!=1) {
            DFS(j);
        }
    }
}

int main ()
{

    DFS(0); // From which Vertex we want to start DFS

    return 0;
}
