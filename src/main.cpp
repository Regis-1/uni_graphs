/* Projekt nr 2
 * Programowanie Algorytmow i Metody Sztucznej Inteligencji
 * Jakub Dudzinski 248928
 */

#include <iostream>

#include "../include/Manager.hh"

#define MAX_WEIGHT 9

int main(int argc, char **argv){
	std::srand(time(NULL));

	int max_weight = MAX_WEIGHT;
	std::string if_name = "input.txt";

	Manager manager;

	switch(argc){
		case 2:
			{
				if_name = argv[1];
				//initializing manager object
				manager = Manager(if_name);
				manager.initialize();
				manager.find_path();
				manager.finish();
				break;
			}
		case 3:
			{
				int nV = atoi(argv[1]);
				float density = std::stof(argv[2]);
				
				//checking arguments
				if(nV == 0){std::cout<<"Wrong vertices number!\n"; return -1;}
				if(density == 0 or density > 1.0){std::cout<<"Wrong density percentage!\n"; return -1;}

				//initializing manager object
				manager = Manager(nV, density, max_weight, if_name);
				manager.initialize();
				manager.find_path();
				manager.finish();
				break;
			}
		default:
			{
				std::cout<< std::endl <<
					"Usage: ./3D5G3R [number of vertices] [percentage of graph density (0 - 1]]\n"<<
					"Or:    ./3D5G3R [input data filename]\n"
					"--------------------------------------------------------------------------\n"<<std::endl;
			}
	}
	return 0;
}
