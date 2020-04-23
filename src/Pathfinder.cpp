#include "../include/Pathfinder.hh"

Pathfinder::Pathfinder(std::string if_name){
	std::fstream fs;
	fs.open(if_name, std::fstream::in);
	fs >> nE >> nV >> starting_vertex;
	fs.close();

	g_list = GraphList(if_name);
	//g_matrix = GraphMatrix(if_name);
	heap = MinHeap(nV);

}

void Pathfinder::find_path_to_all(){
	init_beginning_values();
	heap.decrease_key(starting_vertex, 0);
	d[starting_vertex] = 0;

	int u_pos;
	ListElement *pw;
	for(int i=0; i<nV; i++){
		u_pos = heap.extract_min();
		pw = new ListElement;
		for(pw = g_list[u_pos]; pw; pw = pw->next)
			if(!QS[pw->v_dest] && (d[pw->v_dest] > d[u_pos] + pw->weight)){
				heap.decrease_key(heap.get_i_of_node(pw->v_dest), d[u_pos]+pw->weight);
				d[pw->v_dest] = d[u_pos] + pw->weight; 
				p[pw->v_dest] = u_pos;
			}
		
		QS[u_pos] = true;
	}
}

void Pathfinder::save_paths_to_file(std::string of_name){
	std::fstream fs;
	int ptr;
	fs.open(of_name, std::fstream::out | std::fstream::trunc);
	
	fs << "Starting vertex: "<<starting_vertex<<std::endl;
	for(int i=0; i<nV; i++){
		fs <<"v"<<i<<": ";
		ptr = i;
		while(ptr != -1){
			fs<< ptr << " ";
			ptr = p[ptr];
		}
		fs<<"$"<<d[i];
		fs << std::endl;
	}
}

void Pathfinder::clean(){
	delete [] d;
	delete [] p;
	delete [] QS;
}

/* PRIVATE METHODS */
void Pathfinder::init_beginning_values(){
	p = new int [nV];
	d = new int [nV];
	QS = new bool [nV];

	for(int i=0; i<nV; i++){
		d[i] = INT_MAX;
		p[i] = -1;
		QS[i] = false;
		heap.insert_key(INT_MAX);
	}
}	
