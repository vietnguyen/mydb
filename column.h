#ifndef COLUMN_INCLUDED
#define COLUMN_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Column{

public:

	Column(std::string, std::string, int, bool, bool);

	std::string getName();

	std::string getDataType();

	int getDataLength();

	bool getIsNull();

	bool getIsPK();

	void printObject();
private:
	std::string name;
	std::string dataType;
	int dataLength;
	bool isNull;
	bool isPK;
};
#endif
