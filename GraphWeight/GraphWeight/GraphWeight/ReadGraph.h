#ifndef GRAPHWEIGHT_HEADERFILES_READGRAPH
#define GRAPHWEIGHT_HEADERFILES_READGRAPH
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
using namespace std;
template<typename Graph, typename Weight>
class ReadGraph{
private:
public:
	ReadGraph(Graph &graph, const string &FileName){
		string line;
		int n, m;
		Weight weight;
		ifstream file(FileName);
		
		assert(file.is_open());
		
		assert(getline(file, line) != NULL);

		stringstream ss(line);
		ss>>n>>m;

		graph = Graph(n, false);
		//getline( file, line);
		//while(line != NULL){
		//	stringstream ss(line);
		//	int a, b;
		//	ss>>a >>b >>weight;
		//	
		//	assert( a >= 0 && a < n);
		//	assert( b >= 0 && b < n);

		//	graph.addEdge(n, m, weight);
		//	getline(file, line);
		//}
		for( int i = 0; i < m; i ++ ){
			assert( getline(file ,line));
			int a, b;
			stringstream ss(line);

			ss>>a>>b>>weight;
			assert( a >= 0 && a < n);
			assert( b >= 0 && b < n);
			graph.addEdge(a, b, weight);
 		}
	}
	~ReadGraph(){}


};



#endif