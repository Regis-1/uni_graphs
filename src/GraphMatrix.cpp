#include "../include/GraphMatrix.hh"

GraphMatrix::GraphMatrix(){}

GraphMatrix::GraphMatrix(std::string name){
	std::fstream fs;
	fs.open(name, std::fstream::in);

	fs >> this->nE;
	fs >> this->nV;
	fs >> this->starting_vertex;
	init_adj_matrix();

	for(int i=0; i<this->nE; i++){
		int x, y, w;
		fs >> x; fs >> y; fs >> w;
		adj_matrix[x][y] = w;
	}
	fs.close();
}

GraphMatrix::GraphMatrix(int nV, int nE, std::string if_name){
	this->nV = nV;
	this->nE = nE;
	this->starting_vertex = std::rand() % nV;
	init_adj_matrix();
	
	generate_rand_matrix();

	save_matrix_to_file(if_name);
}

void GraphMatrix::init_adj_matrix(){
	adj_matrix = new int *[nV];
	for(int i=0; i<nV; i++)
		adj_matrix[i] = new int [nV];
	
	for(int i=0; i<nV; i++)
		for(int j=0; j<nV; j++)
			adj_matrix[i][j]=0;
}

void GraphMatrix::generate_rand_matrix(){
	int *order_vertex = new int[nV];
	for(int i=0; i<nV; i++){order_vertex[i] = i;}
	
	std::random_shuffle(&order_vertex[0], &order_vertex[nV-1]);
	for(int i=0; i<nV-1; i++){
		int weight = (std::rand() % MAX_WEIGHT)+1;
		adj_matrix[order_vertex[i]][order_vertex[i+1]] = weight;
		adj_matrix[order_vertex[i+1]][order_vertex[i]] = weight;
	}
	int *tmp_vertices = new int[nV];
	for(int i=0; i<nV; i++)
		tmp_vertices[i] = order_vertex[i];
	int other_edges = nE-nV+1;
	while(other_edges>0){
		std::random_shuffle(&tmp_vertices[0], &tmp_vertices[nV-1]);
		for(int j=0; j<nV; j++){
			int weight = (std::rand() % MAX_WEIGHT)+1;
			for(int k=0; k<nV; k++){
				if(!is_connected(tmp_vertices[j], order_vertex[k]) &&
						tmp_vertices[j] != order_vertex[k]){
					adj_matrix[tmp_vertices[j]][order_vertex[k]] = weight;
					adj_matrix[order_vertex[k]][tmp_vertices[j]] = weight;
					other_edges--;
					break;
				}
			}
			if(other_edges<=0){ break; }
		}
	}
	delete [] order_vertex;
	delete [] tmp_vertices;
}

void GraphMatrix::save_matrix_to_file(std::string if_name){
	std::fstream fs;
	fs.open(if_name, std::fstream::out | std::fstream::trunc);

	fs <<nE<<" "<<nV<<" "<<starting_vertex<<"\n";
	for(int i=0; i<nV; i++)
		for(int j=0; j<i+1; j++)
			if(is_connected(i, j)){
				fs<<i<<" "<<j<<" "<<adj_matrix[i][j]<<"\n";
			}
	fs.close();
}

bool GraphMatrix::is_connected(int i, int j){
	if(adj_matrix[i][j] != 0 || adj_matrix[j][i] != 0)
		return true;
	else
		return false;
}
