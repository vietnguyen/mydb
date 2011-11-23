#ifndef QUERY_INCLUDED
#define QUERY_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "queryUtil.h"
#include "table.h"
#include "column.h"

class QueryUtil;
class Table;
class Column;

class Query {

public:

	Query(std::string&);

	void parseQuery(std::vector<std::string>*, std::string&);

	void executeQuery();

	void printResult();

	void validateQuery();

	std::string getQueryString();

	//	void setQueryString(std::string&);

	void setTables(std::list<Table*>*);

	Table* getTableByName(const std::string&);

private:

	std::string command;

	std::string queryString;

	int queryType;

	std::list<Table*> *tables;

	std::vector<std::string> vQuery;

	void executeCreateQuery();

	void executeSelectQuery();

	void executeInsertQuery();

	void executeUpdateQuery();

	void executeDropQuery();
};

#endif
