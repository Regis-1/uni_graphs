/* Projekt nr 2
 * Programowanie Algorytmow i Metody Sztucznej Inteligencji
 * Jakub Dudzinski 248928
 */

#include <iostream>

#include "../include/Manager.hh"

#define MAX_WEIGHT 9

int main(int argc, char **argv){
	std::srand(time(NULL));
	switch(argc){
		case 3:
			{
				int nV = atoi(argv[1]);
				float density = std::stof(argv[2]);
				int max_weight = MAX_WEIGHT;
				std::string if_name = "input.txt";
				std::string of_name = "output.txt";
				
				//checking arguments
				if(nV == 0){std::cout<<"Wrong vertices number!\n"; return -1;}
				if(density == 0 or density > 1.0){std::cout<<"Wrong density percentage!\n"; return -1;}

				//initializing objects
				Manager manager = Manager(nV, density, max_weight, if_name, of_name);
				manager.initialize();
				manager.find_path();
				manager.finish();
				break;
			}
		default:
			{
				std::cout<< std::endl <<
					"Usage: ./3D5G3R [number of vertices] [percentage of graph density (0 - 1]]\n"<<
					"--------------------------------------------------------------------------\n"<<std::endl;
			}
	}
	return 0;
}
