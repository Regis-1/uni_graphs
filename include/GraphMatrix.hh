#ifndef GRAPHMATRIX_HH
#define GRAPHMATRIX_HH

#include <fstream>
#include <string>

class GraphMatrix{
	private:
		int **adj_matrix;

		void init_adj_matrix(int nV);
	public:
		GraphMatrix(){}
		GraphMatrix(std::string if_name);
		int* operator[](int i){return adj_matrix[i];}
};

#endif
