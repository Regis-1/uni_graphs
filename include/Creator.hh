#ifndef CREATOR_HH
#define CREATOR_HH

#include <string>
#include <algorithm>
#include <fstream>

class Creator{
	private:
		int nV;
		int **adj_matrix;
	public:
		Creator();
		Creator(int nV);
		void generate_rand_graph(int nE, int max_weight, std::string if_name);
		void init_adj_matrix();
		void save_matrix_to_file(int nE, std::string if_name);
		bool is_connected(int i, int j);
};

#endif
