#ifndef MANAGER_HH
#define MANAGER_HH

#include <time.h>

#include "../include/TextFile.hh"
#include "../include/Maker.hh"

class Manager{
	private:
		int nV = 0;
		float density = 0;
		TextFile init_data;
		TextFile result_data;
		Maker maker;
	public:
		Manager(int nV, float density, std::string if_name, std::string of_name);
		void initialize();
};

#endif
