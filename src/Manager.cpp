#include "../include/Manager.hh"

int calculate_nE(int nV, float density){
	float nE = std::floor((density*nV*(nV-1))/2);
	return (int)nE;
}

Manager::Manager(int nV, float density, std::string if_name, std::string of_name){
	this->nV = nV;
	this->density = density;
	this->if_name = if_name;
	this->of_name = of_name;

	int nE = calculate_nE(nV, density);
	graph_matrix = GraphMatrix(nV, nE, if_name);
}

void Manager::initialize(){
}

void Manager::find_path(){
}

void Manager::finish(){
}
