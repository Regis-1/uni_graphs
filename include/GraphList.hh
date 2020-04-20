#ifndef GRAPHLIST_HH
#define GRAPHLIST_HH

#include <string>
#include <fstream>

#include "../include/ListElement.hh"

class GraphList{
	private:
		ListElement **adj_list;

		void init_adj_list(int nV);
	public:
		GraphList(){};
		GraphList(std::string if_name);
		ListElement* operator[](int i){return adj_list[i];}
};

#endif
