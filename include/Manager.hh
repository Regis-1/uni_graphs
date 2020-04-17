#ifndef MANAGER_HH
#define MANAGER_HH

#include <cmath>

#include "../include/TextFile.hh"
#include "../include/GraphMatrix.hh"

class Manager{
	private:
		int nV = 0;
		float density = 0;
		std::string if_name;
		std::string of_name;
		GraphMatrix graph_matrix;
	public:
		Manager(int nV, float density, std::string if_name, std::string of_name);
		void initialize();
		void find_path();
		void finish();
};

#endif
