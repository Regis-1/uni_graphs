#ifndef PATHFINDER_HH
#define PATHFINDER_HH

#include <string>

#include "../include/ListElement.hh"
#include "../include/MinHeap.hh"
#include "../include/GraphList.hh"
#include "../include/GraphMatrix.hh"

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
	public:
		Pathfinder(){}
		Pathfinder(std::string if_name);
		void find_path_to_all();
		void save_paths_to_file(std::string of_name);
		void clean();
};

#endif
