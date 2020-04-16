#include "../include/Manager.hh"

Manager::Manager(int nV, float density, std::string if_name, std::string of_name){
	this->nV = nV;
	this->density = density;
	init_data = TextFile(if_name);
	result_data = TextFile(of_name);
	maker = Maker(if_name);
}

void Manager::initialize(){
	maker.make_graph(this->nV, this->density);
}
