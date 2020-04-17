#ifndef GRAPHMATRIX_HH
#define GRAPHMATRIX_HH

#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>

#define MAX_WEIGHT 199

class GraphMatrix{
	private:
		int nV;
		int nE;
		int starting_vertex;
		int **adj_matrix;
	public:
		GraphMatrix();
		GraphMatrix(std::string name);
		GraphMatrix(int nV, int nE, std::string if_name);
		void init_adj_matrix();
		void generate_rand_matrix();
		void save_matrix_to_file(std::string if_name);
		bool is_connected(int i, int j);
};

#endif
