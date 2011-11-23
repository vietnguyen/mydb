#ifndef ROW_INCLUDED
#define ROW_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
class Row{

public:

//	Row(std::string, int, std::string);
//	std::string getData();
	void addData(const std::string &, const std::string &);
	void printMapData();
private:
	int rowIndex;
	std::map<std::string,std::string> mapData;
};
#endif
