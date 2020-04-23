#ifndef MANAGER_HH
#define MANAGER_HH

#include <cmath>
#include <iostream>

#include "../include/Creator.hh"
#include "../include/Pathfinder.hh"

class Manager{
	private:
		int nV = 0;
		float density = 0;
		int max_weight = 0;
		bool will_generate = false;
		std::string if_name;
		Pathfinder pathfinder;
	public:
		Manager(){}
		Manager(std::string if_name);
		Manager(int nV, float density, int max_weight, std::string if_name);
		void initialize();
		void find_path();
		void finish();
};

#endif
