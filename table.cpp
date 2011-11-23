#include "table.h"

Table::Table(std::string &newName){
	name = newName;
}
std::string Table::getName(){
	return name;
}
void Table::addColumn(Column *col){
	cols.push_back(col);
	 std::cout << "\n added col: " << col->getName() << std::endl;
}

void Table::addRow(Row *row){
	rows.push_back(row);
	row->printMapData();
}

void Table::printCols(){
	for (std::list<Column*>::iterator it = cols.begin(); it != cols.end(); it++){
		Column *p = *it;
	    std::cout << "\n col: " << p->getName() << std::endl;
	}
}

std::list<Column*>& Table::getAllCols(){
	return cols;
}
