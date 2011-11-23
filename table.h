#ifndef TABLE_INCLUDED
#define TABLE_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

#include "column.h"
#include "row.h"

class Column;
class Row;

class Table {
public:

	Table(std::string&);
	std::string getName();
	void addColumn(Column*);
	void addRow(Row*);
	std::list<Column*>& getAllCols();
//	void getAllRows();
	void printCols();
private:
	std::string name;
	std::string pKName;
	int pkColIndex;
	std::list<Column*> cols;
	std::list<Row*> rows;

};

#endif
