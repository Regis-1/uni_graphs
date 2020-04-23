#include "../include/GraphMatrix.hh"

GraphMatrix::GraphMatrix(std::string if_name){
	std::fstream fs;
	fs.open(if_name, std::fstream::in);

	int x, y, w;
	fs >> x >> y >> w;
	int nE = x;
	init_adj_matrix(y);
	for(int i=0; i<nE; i++){
		fs >> x >> y >> w;
		adj_matrix[x][y] = w;
		adj_matrix[y][x] = w;
	}
	fs.close();
}

/* PRIVATE METHODS */
void GraphMatrix::init_adj_matrix(int nV){
	adj_matrix = new int *[nV];
	for(int i=0; i<nV; i++)
		adj_matrix[i] = new int [nV];

	for(int i=0; i<nV; i++)
		for(int j=0; j<nV; j++)
			adj_matrix[i][j] = 0;
}
