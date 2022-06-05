/* After end term examination, Akshay wants to party with his friends.
 All his friends are living as paying guest and it has been decided to first gather at Akshay’s house and
 then move towards party location. The problem is that no one knows the exact address of his house in the city.
  Akshay as a computer science wizard knows how to apply his theory subjects in his real life and came
   up with an amazing idea to help his friends. He draws a graph by looking in to location of his house and his friends’
    location (as a node in the graph) on a map. He wishes to find out shortest distance and path covering that distance
    from each of his friend’s location to his house and then whatsapp them this path so that they can reach his house in minimum time.
 Akshay has developed the program that implements Dijkstra’s algorithm but not sure about correctness of results.
  Can you also implement the same algorithm and verify the correctness of Akshay’s results? (Hint: Print shortest path and distance from friends’ location to Akshay’s house)*/
#include <iostream>
#include <climits>
    using namespace std;

    // this method returns a minimum distance for the
    // vertex which is not included in Tset.
    int minimumDist(int dist[], bool Tset[])
    {
        int min = INT_MAX, index;

        for (int i = 0; i < 6; i++)
        {
            if (Tset[i] == false && dist[i] <= min)
            {
                min = dist[i];
                index = i;
            }
        }
        return index;
    }

    void Dijkstra(int graph[6][6], int src) // adjacency matrix used is 6x6
    {
        int dist[6];  // integer array to calculate minimum distance for each node.
        bool Tset[6]; // boolean array to mark visted/unvisted for each node.

        // set the nodes with infinity distance
        // except for the initial node and mark
        // them unvisited.
        for (int i = 0; i < 6; i++)
        {
            dist[i] = INT_MAX;
            Tset[i] = false;
        }

        dist[src] = 0; // Source vertex distance is set to zero.

        for (int i = 0; i < 6; i++)
        {
            int m = minimumDist(dist, Tset); // vertex not yet included.
            Tset[m] = true;                  // m with minimum distance included in Tset.
            for (int i = 0; i < 6; i++)
            {
                // Updating the minimum distance for the particular node.
                if (!Tset[i] && graph[m][i] && dist[m] != INT_MAX && dist[m] + graph[m][i] < dist[i])
                    dist[i] = dist[m] + graph[m][i];
            }
        }
        cout << "Vertex\t\tDistance from source" << endl;
        for (int i = 0; i < 6; i++)
        {                      // Printing
            char str = 65 + i; // Ascii values for pritning A,B,C..
            cout << str << "\t\t\t" << dist[i] << endl;
        }
    }

    int main()
    {
        int graph[6][6] = {
            {0, 2, 10, 1, 0, 0},
            {10, 0, 0, 50, 10, 0},
            {20, 0, 0, 20, 33, 3},
            {1, 50, 20, 0, 20, 2},
            {10, 10, 20, 20, 0, 1},
            {0, 0, 2, 2, 1, 0}};
        Dijkstra(graph, 0);
        return 0;
    }

