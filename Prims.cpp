#include <iostream>
using namespace std;

struct Edge
{
    int source;
    int destination;
    int cost;
};

int main()
{
    int cities, edges;

    cout << "Enter number of cities: ";
    cin >> cities;

    cout << "Enter number of connections: ";
    cin >> edges;

    Edge graph[20];

    cout << "Enter source city, destination city and cost:\n";

    for(int i = 0; i < edges; i++)
    {
        cin >> graph[i].source
            >> graph[i].destination
            >> graph[i].cost;
    }

    bool visited[10] = {0};

    // Start from city 0
    visited[0] = true;

    int selectedEdges = 0;
    int totalCost = 0;

    cout << "\nSelected Connections:\n";

    while(selectedEdges < cities - 1)
    {
        int minCost = 999;
        int cityA, cityB;

        for(int i = 0; i < edges; i++)
        {
            int u = graph[i].source;
            int v = graph[i].destination;
            int w = graph[i].cost;

            // One city visited and other not visited
            if((visited[u] && !visited[v]) ||
               (visited[v] && !visited[u]))
            {
                if(w < minCost)
                {
                    minCost = w;
                    cityA = u;
                    cityB = v;
                }
            }
        }

        cout << "City "
             << cityA
             << " -> City "
             << cityB
             << " = "
             << minCost << endl;

        totalCost += minCost;

        visited[cityA] = true;
        visited[cityB] = true;

        selectedEdges++;
    }

    cout << "\nMinimum Network Cost = "
         << totalCost;

    return 0;
}
