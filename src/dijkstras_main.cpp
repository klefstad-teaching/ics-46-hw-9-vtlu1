#include "dijkstras.h"
using namespace std;

int main() {
    Graph G;
    file_to_graph("src/small.txt", G);

    //TEST 1
    int source = 0;
    int destination = 0;

    vector<int> previous;

    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    vector<int> path = extract_shortest_path(distances, previous, destination);

    print_path(path, distances[destination]);

    //TEST 2
    int source2 = 0;
    int destination2 = 1;

    vector<int> distances2 = dijkstra_shortest_path(G, source, previous);
    vector<int> path2 = extract_shortest_path(distances2, previous, destination2);

    print_path(path2, distances2[destination2]);

    //TEST3
    int source3 = 0;
    int destination3 = 2;

    vector<int> distances3 = dijkstra_shortest_path(G, source, previous);
    vector<int> path3 = extract_shortest_path(distances3, previous, destination3);

    print_path(path3, distances3[destination3]);

    //TEST4
    int source4 = 0;
    int destination4 = 3;

    vector<int> distances4 = dijkstra_shortest_path(G, source, previous);
    vector<int> path4 = extract_shortest_path(distances4, previous, destination4);

    print_path(path4, distances4[destination4]);

    return 0;
}