#include "../include/TextFile.hh"

TextFile::TextFile(){
}

TextFile::TextFile(std::string name){
	this->name = name;
}

void TextFile::open(FILE_MODE mode){
	this->mode = mode;
	if(mode == FILE_MODE::read)
		(this->fs).open(this->name, std::fstream::in);
	else if(mode == FILE_MODE::app)
		(this->fs).open(this->name, std::fstream::out | std::fstream::app);
}

void TextFile::close(){
	this->fs.close();
}

void TextFile::write_line(std::string s){
	if(this->fs.is_open() && this->mode == FILE_MODE::app){
		this->fs << s + "\n";
	}
	else{
		std::cout<<"Wrong file open mode!"<<std::endl;
	}
}

