#ifndef QUERY_PARSER_INCLUDED
#define QUERY_PARSER_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "query.h"
#include "table.h"

class Table;

std::string getQueryFromUser();
bool run(std::list<Table*> *);
void stop();

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);
std::string subStrByDelim(const std::string &str, char begin, char end);
std::string trim(std::string& str);
#endif
