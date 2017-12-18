#ifndef GRAPHWEIGHT_HEADERFILES_EDGE
#define GRAPHWEIGHT_HEADERFILES_EDGE
#include <iostream>
#include <vector>

using namespace std;
template<typename Weight>
class Edge{
private:
	int a, b;
	Weight weight;
public:
	Edge(int a, int b, Weight weight){
		this->a = a;
		this->b = b;
		this->weight = weight;
	}
	
	Edge(){}

	~Edge(){}

	int v(){return a;}
	int w(){return b;}
	Weight GetWeight(){return weight;}

	friend ostream& operator<<(ostream &os, const Edge &e){
		os<<e.v()<<"-"<<e.w()<<" : "<<e.GetWeight();
		//os<<e.a<<"-"<<e.b<<": "<<e.weight;
		return os;
	} 

	int other(int x){
		return x == a : b ? a;
	}


	bool operator<(Edge &e){
		return weight < e.weight;
	}

	bool operator>=(Edge &e){
		return weight >= e.weight;
	}

	bool operator<=(Edge &e){
		return weight <= e.weight;
	}

	bool operator==(Edge &e){
		return weight == e.weight;
	}
};

#endif