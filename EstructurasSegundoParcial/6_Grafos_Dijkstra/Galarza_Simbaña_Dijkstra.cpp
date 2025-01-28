#include <iostream>
#include <climits>
using namespace std;

// this method returns a minimum distance for the
// vertex which is not included in Tset.
int minimumDist(int dist[], bool Tset[])
{
    int min = INT_MAX, index;
    for (int i = 0; i < 6; i++) {
        if (Tset[i] == false && dist[i] <= min) {
            min = dist[i];
			index = i;
        }
    }
    return index;
}

void Dijkstra(int graph[6][6], int src) // adjacency matrix used is 6x6
{
    int dist[6]; // integer array to calculate minimum distance for each node
    bool Tset[6]; // boolean array to mark visited/unvisited for each node

	// set the nodes with infinity distance
	// except for the initial node and mark
	// them unvisited
    for (int i = 0; i < 6; i++) {
        dist[i] = INT_MAX;
        Tset[i] = false;
    }

    dist[src] = 0; // Source vertex distance is set to zero

    for (int i = 0; i < 6 - 1; i++) {
        int m = minimumDist(dist, Tset); // vertex not yet included
        Tset[m] = true; //m with minimum distance included in Tset

        for (int i = 0; i < 6; i++) {
        	//Updating the minimum distance for the particular node
            if (!Tset[i] && graph[m][i] && dist[m] != INT_MAX && dist[m] + graph[m][i] < dist[i]) {
                dist[i] = dist[m] + graph[m][i];
            }
        }
    }

    cout << "Vertex\t\tDistance from source" << endl;
    char node[6] = {'S','B','C','D','E','T'};
    for (int i = 0; i < 6; i++) {
    	// Printing
        cout << node[i] << "\t\t " << dist[i] << endl;
    }
}

int main()
{
    int graph[6][6] = {
        {0, 5, 4, 0, 0, 0},
        {5, 0, 3, 6, 0, 0},
        {4, 3, 0, 9, 7, 0},
        {0, 6, 9, 0, 4, 5},
        {0, 0, 7, 4, 0, 3},
        {0, 0, 0, 5, 3, 0}
    };
    
    Dijkstra(graph, 0);
	return 0;
}
