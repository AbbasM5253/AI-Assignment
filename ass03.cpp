#include <stdio.h>
#include <vector>
#include <algorithm>

// Initialize vectors and variables
std::vector<int> opened;                            // List of vertices that are currently open for exploration
std::vector<int> path;                              // The path being constructed
int vertex = 0;                                     // Starting vertex
int minVertex;                                      // Vertex with minimum cost
int heuristic[] = {10, 8, 5, 7, 3, 6, 5, 3, 1, 0};  // Heuristic values for each vertex
int visited[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};     // Array to mark visited vertices
int lookUpTable[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Lookup table for parent vertices
int graph[][10] = {{0, 6, 0, 0, 0, 3, 0, 0, 0, 0},
                   {0, 0, 3, 2, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 1, 5, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 8, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 5, 5},
                   {0, 0, 0, 0, 0, 0, 1, 7, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 3, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int vertexCost(int vert)
{
    int initVertex = vert;
    int vCost = 0;

    while (vert != 0)
    {
        int parentVertex = lookUpTable[vert];
        vCost += graph[parentVertex][vert];
        vert = parentVertex;
    }

    return vCost + heuristic[initVertex];
}

int findMinVertex(std::vector<int> vec)
{
    int minVertex = vec[0];
    int minVertexCost = vertexCost(vec[0]);

    for (int i = 1; i < vec.size(); i++)
    {
        int Vert = vertexCost(vec[i]);
        if (Vert < minVertexCost)
        {
            minVertexCost = Vert;
            minVertex = vec[i];
        }
    }

    return minVertex;
}

void aStar(int vertex)
{
    if (vertex == 9)
        return;

    auto it = std::find(opened.begin(), opened.end(), vertex);
    opened.erase(it);

    for (int i = 0; i < 10; i++)
    {
        if (graph[vertex][i] && !visited[i])
        {
            opened.push_back(i);
            lookUpTable[i] = vertex;
        }
    }

    printf("For expansion of vertex %d, the opened list is: ", vertex);
    for (int i = 0; i < opened.size(); i++)
    {
        printf("%d-%d\t", opened[i], vertexCost(opened[i]));
    }

    minVertex = findMinVertex(opened);
    printf("Min vertex is %d\n", minVertex);
    visited[vertex] = 1;

    aStar(minVertex);
}

int main()
{
    opened.push_back(vertex);
    aStar(vertex);
    return 0;
}