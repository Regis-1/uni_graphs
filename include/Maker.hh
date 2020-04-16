#ifndef MAKER_HH
#define MAKER_HH

#include <cmath>
#include <algorithm>
#include <ctime>

#include "../include/TextFile.hh"

class Maker{
	private:
		TextFile init_data;
	public:
		Maker();
		Maker(std::string if_name);
		void make_graph(int nV, float density);
};

#endif
