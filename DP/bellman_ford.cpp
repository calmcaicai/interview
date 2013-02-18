#include <iostream>
using namespace std;
//Input: Graph and a source vertex src
//Output: Shortest distance to all vertices from src. If there is a negative weight cycle, 
         //then shortest distances are not calculated, negative weight cycle is reported.
class Edge{
public:
	int src;
	int dest;
	int weight;
	Edge(){};
	Edge(int s, int d, int w): src(s), dest(d), weight(w){}
};
class Graph{
public:
	int V, E;
	Edge * edges;
	Graph(int v, int e){
		V = v;
		E = e;
		edges = new Edge[E];
	}
};

void bellman_ford(Graph *graph, int src){
	int *dist = new int[graph->V];
	for(int i = 0 ; i < graph->V; i++){
		if(i == src)
			dist[i] = 0;
		else dist[i] = INT_MAX;
	}
	//relax V -1 times
	for(int i = 1; i < graph->V;i++){
		for(int j = 0 ; j < graph->E; j++){
			int s = graph->edges[j].src;
			int d = graph->edges[j].dest;
			int w = graph->edges[j].weight;
			if(dist[s] + w < dist[d])
				dist[d] = dist[s] + w;
		}
	}
	//check negative cycle
	bool negCycle = false;
	for(int i = 0 ; i < graph->E; i++){
		int s = graph->edges[i].src;
		int d = graph->edges[i].dest;
		int w = graph->edges[i].weight;
		if(dist[s] + w < dist[d]){
			cout<<"there is a negative cycle"<<endl;
			break;
		}
	}
	for(int i =0; i < graph->V; i++)
		cout<<i<<" : "<<dist[i]<<endl;
}
int bfmain()
{
    /* Let us create the graph given in above example */
    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    Graph* graph = new Graph(V, E);
 
    // add edge 0-1 (or A-B in above figure)
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = -1;
 
    // add edge 0-2 (or A-C in above figure)
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 4;
 
    // add edge 1-2 (or B-C in above figure)
    graph->edges[2].src = 1;
    graph->edges[2].dest = 2;
    graph->edges[2].weight = 3;
 
    // add edge 1-3 (or B-D in above figure)
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 2;
 
    // add edge 1-4 (or A-E in above figure)
    graph->edges[4].src = 1;
    graph->edges[4].dest = 4;
    graph->edges[4].weight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    graph->edges[5].src = 3;
    graph->edges[5].dest = 2;
    graph->edges[5].weight = 5;
 
    // add edge 3-1 (or D-B in above figure)
    graph->edges[6].src = 3;
    graph->edges[6].dest = 1;
    graph->edges[6].weight = 1;
 
    // add edge 4-3 (or E-D in above figure)
    graph->edges[7].src = 4;
    graph->edges[7].dest = 3;
    graph->edges[7].weight = -3;
 
    bellman_ford(graph, 0);
 
    return 0;
}