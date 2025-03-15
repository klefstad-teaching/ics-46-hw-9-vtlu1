#include "dijkstras.h"
using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    vector<int> distance(G.numVertices, INF);
    vector<bool> visited(G.numVertices, false);
    previous.assign(G.numVertices, -1);
    
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    distance[source] = 0;
    pq.push(Node(source, 0));
    
    while(!pq.empty()){
        Node cur_node = pq.top();
        pq.pop();
        int u = cur_node.vertex;
        
        if (visited[u]){
            continue;
        }
        visited[u] = true;

        for (const Edge neighbor: G[u]){
            int v = neighbor.dst;
            int weight = neighbor.weight;

            if (!visited[v] && distance[u] + weight < distance[v]){
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push(Node(v, distance[v]));
            }
        }
    }

    return distance;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){
    vector<int> path_taken;
    for (int position = destination; position != -1; position = previous[position]){
        path_taken.push_back(position);
    }
    reverse(path_taken.begin(), path_taken.end());
    return path_taken;
}

void print_path(const vector<int>& v, int total){
    for (size_t i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
    
    cout << "Total cost is " << total << endl;

}