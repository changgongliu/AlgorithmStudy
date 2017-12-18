#ifndef GRAPHWEIGHT_HEADERFILES_DENSEGRAPH
#define GRAPHWEIGHT_HEADERFILES_DENSEGRAPH
#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;
template<typename Weight>
class DenseGraph{
private:
	int n, m ;//节点数和边数
	bool directed;//是否有向图
	vector< vector<Edge<Weight> *>> g;//图的具体数据
public:
	DenseGraph(int n,  bool directed){
		this->n = n;
		this->directed = directed;
		g = vector< vector<Edge< Weight>* >> (n, vector<Edge<Weight>*>(n, NULL));

	}
	~DenseGraph(){
		for(int i = 0;  i < n ; i ++){
			for( int j = 0; j < n ; j ++){
				//if( g[i][j] != NULL)
					delete g[i][j];
			}
		}
	}

	int V(){return n;}
	int W(){return m;}

	bool hasEdge(int v, int w){
		assert( v>=0 && v<n);
		assert( w>=0 && w<n);

		return g[v][w] != NULL ;
	}

	void addEdge(int v, int w, Weight weight){
		assert( v>=0 && v<n);
		assert( w>=0 && w<n);		
		//如果已经有变，就删除这条边
		if( hasEdge( v, w)){
			delete g[v][w];
			if(v != w && !directed )
				delete g[w][v];
			m--;
		}
		
		//添加边
		g[v][w] = new Edge<Weight>(v, w, weight);
		if( !directed && v != w )
			g[w][v] = new Edge<Weight>(w, v, weight);
		m ++;
	} 

	void show(){
		for( int i = 0; i < n; i++){
			for( int j = 0; j <n; j++){
				if( g[i][j])
					cout<<g[i][j]->GetWeight() <<"\t";
				else
					cout<<"NULL\t";
			}
			cout<<endl;
		}
	}
    // 邻边迭代器, 传入一个图和一个顶点,
    // 迭代在这个图中和这个顶点相连的所有边
	class adjIterator{
	private:
		DenseGraph &G;//图G的引用
		int v;//顶点
		int index;
	public:
		adjIterator(DenseGraph &g, int v){
			this->G = g;
			this->v = v;
			intdex = -1;//index从-1开始，
		}
	
		Edge<Weight>* begin(){
			next();
			return index;
		}

		int next(){
			for( index += 1; index < G.V(); index ++){
				if( G.g[v][index])
					return G.g[v][index];

			}
			//若没有顶点相连，则返回NUL
			return NULL;
		}

		bool end(){
			return index >= G.V();
		}
	};
};

#endif