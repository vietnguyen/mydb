#include "query.h"

Query::Query(std::string &query) {
	queryString = query;
	parseQuery(&vQuery, queryString);
}

//void Query::setQueryString(std::string& query){
//
//	parseQuery(&vQuery, query);
//
//	for( int i=0; i<vQuery.size(); i++){
//		std::cout  << vQuery[i] << "\n";
//	}
//
//}


void Query::parseQuery(std::vector<std::string> *vQuery, std::string &query) {
	std::string buf; // Have a buffer string
	std::stringstream ss(query); // Insert the string into a stream

	while (ss >> buf)
		vQuery->push_back(buf);
}

void Query::executeQuery() {


	if (vQuery[0] == "create") {
		executeCreateQuery();
	}
	if (vQuery[0] == "select") {
		executeSelectQuery();
	}
	if (vQuery[0] == "drop") {
		executeDropQuery();
	}
	if (vQuery[0] == "insert") {
		executeInsertQuery();
	}
	if (vQuery[0] == "update") {
		executeUpdateQuery();
	}
}


/** CREATE TABLE games
		(yr   INT NOT NULL PRIMARY KEY
		,city VARCHAR(20)
		);
 * */
void Query::executeCreateQuery() {
	std::cout << "create " << std::endl  << std::endl;
	Table *table = new Table(vQuery[2]);

	std::string paramString = subStrByDelim(queryString,'(',')');
	std::cout << "\n paramString : "<<  paramString << std::endl;

	std::vector<std::string> vParam = split(paramString,',');

	std::string query = "";
	std::string colName = "";
	std::string dataType = "";
	int dataLength = 0;
	std::string tmpDataType = "";
	int hasNotNull = 0;
	int hasPK = 0;
	bool isNull = false;
	bool isPK = false;

	for( int i=0; i < (int)vParam.size(); i++ ){

		query = "";
		colName = "";
		dataType = "";
		dataLength = 0;
		tmpDataType = "";
		hasNotNull = 0;
		hasPK = 0;
		isNull = false;
		isPK = false;

		std::cout << "\n param here" << vParam[i] << std::endl  << std::endl;
		query = vParam[i];
		std::vector<std::string> vp ;
		parseQuery(&vp, query);
		colName = vp[0];
		dataType = vp[1];

		if( dataType.find("(") > 0 ){
			tmpDataType = subStrByDelim(dataType, '(',')');
			std::istringstream stream (tmpDataType);
			stream >> dataLength;
			dataType = dataType.substr(0,dataType.find('('));
		}

		isNull = ((int ) query.find("not null")) > 0 ? true : false ;
		isPK = ((int)query.find("primary key")) > 0 ? true: false ;

		Column *col = new Column(colName,  dataType, dataLength, isNull,  isPK);
//		col->printObject();
		table->addColumn(col);
//		table->printCols();
	}

	tables->push_back(table);
	for (std::list<Table*>::iterator it = tables->begin(); it != tables->end(); it++){
		Table *p = *it;
		    std::cout << "\n table: " << p->getName() << std::endl;
		    p->printCols();
		}
}


//INSERT INTO games(yr,city) VALUES (2008,'Paris');
void Query::executeInsertQuery() {


	// games(yr,city) part
	std::string tableName = vQuery[2].substr(0, vQuery[2].find('(') );
	std::cout << "\n table name: " << tableName << std::endl;
	tableName = trim(tableName);
	Table *table = getTableByName(tableName);

	// Check if table exist
	if( !table )
	{
		std::cout << (" \n Table does not exist !");
		return;
	}

	// Get columns name
	std::string sName = queryString.substr(queryString.find_first_of('(') + 1,  queryString.find_first_of(')')  -  queryString.find_first_of('(') - 1);
	std::vector<std::string> colNames = split(sName,',');
	for(int i=0; i<(int)colNames.size(); i++){
		std::cout << "\n col name : " << colNames[i] << std::endl;
	}

	//  check if NOT NULL column is entered.
	std::list<Column*> cols = table->getAllCols();
	bool colexist = false;
	for(std::list<Column*>::iterator it = cols.begin(); it != cols.end(); it++){
		colexist = false;
		Column *col = *it;
		for(int i=0; i<(int)colNames.size(); i++){
			if( colNames[i] == col->getName()) {
				colexist = true;
			}
		}
		if( colexist == false && col->getIsNull() == true ){
			std::cout << "\n Column " << col->getName() << "must not be null !" << std::endl;
			return;
		}
	}

	// check if all colums entered  exist
	for(int i=0; i<(int)colNames.size(); i++){
		colexist = false;
		for(std::list<Column*>::iterator it = cols.begin(); it != cols.end(); it++){
			Column *col = *it;
			if( colNames[i] == col->getName()) {
				colexist = true;
			}
		}
		if( colexist == false ){
			std::cout << "\n Column " << colNames[i] << " does not exist !" << std::endl;
			return;
		}
	}



	int posValue = queryString.find("values");
//	std::cout << "\n queryString.length() - (posValue + 7) : " << queryString.length() - (posValue + 7);
	std::string svalue = queryString.substr(posValue+7,queryString.length() - (posValue + 7));
//	std::cout << "\n value : " << svalue;
	std::string valuesString =  subStrByDelim(svalue,'(',')');
	std::vector<std::string> values = split(valuesString,',');

	Row *row = new Row();
	std::cout << "\nbegin add data : -------------------------\n";
	for(int i=0; i<(int)colNames.size(); i++){
		std::cout << "\nadd data col : " << colNames[i] << " value : " << values[i] << std::endl;
		row->addData(colNames[i], values[i] );
	}
	table->addRow(row);
}

void Query::executeSelectQuery() {

}

void Query::executeDropQuery() {

}

void Query::executeUpdateQuery() {

}

void Query::printResult() {

}

void Query::setTables(std::list<Table*> *tables){
	this->tables = tables;
}

Table* Query::getTableByName(const std::string &name){
	for (std::list<Table*>::iterator it = tables->begin(); it != tables->end(); it++){
		Table *p = *it;
		if( p->getName() == name ){
			std::cout << "\n found table: " << p->getName() << std::endl;
			return p;
		}
	}
	return NULL;
}
