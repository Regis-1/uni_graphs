#include "../include/Manager.hh"

int calculate_nE(int nV, float density){
	float nE = std::floor((density*nV*(nV-1))/2);
	return (int)nE;
}

Manager::Manager(int nV, float density, int max_weight, std::string if_name, std::string of_name){
	this->nV = nV;
	this->density = density;
	this->max_weight = max_weight;
	this->if_name = if_name;
	this->of_name = of_name;
}

void Manager::initialize(){
	int nE = calculate_nE(nV, density);
	Creator *creator = new Creator(nV);
	creator->generate_rand_graph(nE, max_weight, if_name);
	delete creator;
	pathfinder = Pathfinder(if_name);
}

void Manager::find_path(){
	pathfinder.find_path_to_all();
	pathfinder.save_paths_to_file(of_name);
}

void Manager::finish(){
	pathfinder.clean();
	printf("Finished!\n");
}
