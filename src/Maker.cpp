#include "../include/Maker.hh"

Maker::Maker(){
}

Maker::Maker(std::string if_name){
	init_data = TextFile(if_name);
}

int calculate_nE(int nV, float density){
	float nE = std::floor((density*nV*(nV-1))/2);
	return (int)nE;
}

void connect_vertices(int nV, int nE, TextFile *if_file){
	int *vertex_order = new int[nV];
	for(int i=0; i<nV; i++)
		vertex_order[i]=i;
	std::random_shuffle(&vertex_order[0], &vertex_order[nV-1]);
	for(int i=0; i<nV; i++){std::cout<<vertex_order[i]<<' ';}
	for(int i=0; i<nE; i++){
		int weight = (std::rand() % 999)+1;
		if(i<nV-1){
			if_file->write_line(std::to_string(vertex_order[i])+' '+std::to_string(vertex_order[i+1])+' '+std::to_string(weight));
		}
		else{
			int beg_vertex=std::rand()%nV;
			int end_vertex=0;

			do{
				end_vertex=std::rand()%nV;
			}while(end_vertex == beg_vertex);

			if_file->write_line(std::to_string(beg_vertex)+' '+std::to_string(end_vertex)+' '+std::to_string(weight));
		}
	}
}

void Maker::make_graph(int nV, float density){
	std::srand(time(NULL));
	init_data.open(FILE_MODE::app);
	int nE = calculate_nE(nV, density);
	int random_vertex = std::rand() % nV;
	init_data.write_line(std::to_string(nE)+' '+std::to_string(nV)+' '+std::to_string(random_vertex));
	connect_vertices(nV, nE, &init_data);

	init_data.close();
}

