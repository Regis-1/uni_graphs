#include "../include/Manager.hh"

int calculate_nE(int nV, float density){
	float nE = std::floor((density*nV*(nV-1))/2);
	return (int)nE;
}

Manager::Manager(std::string if_name){
	this->if_name = if_name;
}

Manager::Manager(int nV, float density, int max_weight, std::string if_name){
	this->nV = nV;
	this->density = density;
	this->max_weight = max_weight;
	this->will_generate = true;
	this->if_name = if_name;
}

void Manager::initialize(){
	if(will_generate){
		int nE = calculate_nE(nV, density);
		Creator *creator = new Creator(nV);
		creator->generate_rand_graph(nE, max_weight, if_name);
		delete creator;
	}
	pathfinder = Pathfinder(if_name);
}

void Manager::find_path(){
	pathfinder.find_path_to_all(Representation::list);
	pathfinder.save_paths_to_file("output_list.txt");
	pathfinder.clean();
	pathfinder.find_path_to_all(Representation::matrix);
	pathfinder.save_paths_to_file("output_matrix.txt");
	pathfinder.clean();
}

void Manager::finish(){
	printf("Finished!\n");
}
