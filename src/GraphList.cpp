#include "../include/GraphList.hh"
#include <iostream>

GraphList::GraphList(std::string if_name){
	std::fstream fs;
	fs.open(if_name, std::fstream::in);
	
	int x, y, w;
	ListElement* p;
	fs >> x >> y >> w;
	int nE = x;
	init_adj_list(y);
	for(int i=0; i<nE; i++){
		fs >> x >> y >> w;
		p = new ListElement;
		p->v_dest = y;
		p->weight = w;
		p->next = adj_list[x];
		adj_list[x] = p;
		p = new ListElement;
		p->v_dest = x;
		p->weight = w;
		p->next = adj_list[y];
		adj_list[y] = p;
	}
	fs.close();
}

/* PRIVATE METHODS */
void GraphList::init_adj_list(int nV){
	adj_list = new ListElement *[nV];
	for(int i=0; i<nV; i++){
		adj_list[i] = NULL;
	}
}
