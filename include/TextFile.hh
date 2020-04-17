#ifndef TEXTFILE_HH
#define TEXTFILE_HH

#include <fstream>
#include <iostream>
#include <string>

enum FILE_MODE{read, app};

class TextFile{
	private:
		std::fstream fs;
		std::string name;
		int mode;
	public:
		TextFile();
		TextFile(std::string name);
		void open(FILE_MODE mode);
		void close();
		void write_line(std::string s);
		std::string read_line();
		std::string read_word();
};

#endif
