#ifndef PATHFINDER_HH
#define PATHFINDER_HH

#include <string>
#include <chrono>

#include "../include/ListElement.hh"
#include "../include/MinHeap.hh"
#include "../include/GraphList.hh"
#include "../include/GraphMatrix.hh"

enum Representation{
	list,
	matrix
};

class Pathfinder{
	private:
		int nV, nE;
		int starting_vertex;
		GraphList g_list;
		GraphMatrix g_matrix;
		MinHeap heap;

		int *d, *p;
		bool *QS;

		void init_beginning_values();
		float find_with_list();
		float find_with_matrix();
	public:
		Pathfinder(){}
		Pathfinder(std::string if_name);
		float find_path_to_all(Representation rep);
		void save_paths_to_file(std::string of_name);
		void clean();
};

#endif
