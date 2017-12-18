#ifndef	GRAPHWEIGHT_HEADERFILES_SPARESEGRAPH
#define GRAPHWEIGHT_HEADERFILES_SPARESEGRAPH
#include <iostream>
#include <vector>
using namespace std;
template<typename Weight>
class SparseGraph{
private:
	int n;			//图中点数
	int	m;			//图中边数	
	vector< vector< Edge<Weight>* >> g;
	bool directed;
public:
	SparseGraph(int n, bool directed){
		this->n = n;
		this->directed = directed;
		this->m = 0;
		g= vector< vector<Edge<Weight> * >>(n, vector<Edge<Weight>*>());
	}
	~SparseGraph(){}

	bool hasEdge(int v, int w){
		assert( v >= 0 && v < n );
		assert( w >= 0 && w < n );
		
			for( int i = 0; i < g[v].size(); i ++){
				if(g[v][i]->other(v) == w)
					return true;
				return false;
			}
	}
	//返回结点数
	int V(){
		return n;
	}
	//返回边数
	int W(){
		return m;
	}
	
	//稀疏图不考虑平行边。
	void addEdge( int v, int w, Weight weight){
		assert( v >= 0 && v < n );
		assert( w >= 0 && w < n );
		
		g[v].push_back( new Edge<Weight>(v, w, weight));
		if(!directed && v != w)
			g[w].push_back( new Edge<Weight>(w, v, weight));
		m ++;

	}

	void show(){
		for( int i = 0; i < n; i ++){
			cout<<i<<"\t";
			for( int j = 0; j < g[i].size(); j++){
                cout<<"( to:"<<g[i][j]->w()<<",wt:"<<g[i][j]->GetWeight()<<")\t";
			}
			cout<<endl;
		}
	}




};



#endif