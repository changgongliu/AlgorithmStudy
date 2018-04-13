#include <iostream>
#include <iomanip>
#include "DenseGraph.h"
#include "Edge.h"
#include "ReadGraph.h"
#include "SparseGraph.h"

int main(){

	string filename = "test.txt";
	int V = 8;
	cout<<fixed<<setprecision(2);
	
	DenseGraph<double> g1 = DenseGraph<double>(V, false);
	ReadGraph<DenseGraph<double>, double> readGraph(g1, filename);

	g1.show();
	cout<<endl;


	SparseGraph<double> g2 = SparseGraph<double>(V, false);
	ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename);
	g2.show();
	cout<<endl;
	system("pause");
	return 0;
}