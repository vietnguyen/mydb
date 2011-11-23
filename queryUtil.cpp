#include "queryUtil.h"

std::string getQueryFromUser(){
	std::string query ="";
	std::cout << "\nPlease enter SQL query: " ;
	std::getline(std::cin,query);
	std::cout << "\n query : " << query <<std::endl;
	return query;
}

void stop(){

}

bool run(std::list<Table*> *tables){

	std::string string = getQueryFromUser();
	std::transform(string.begin(), string.end(), string.begin(),
				::tolower);
	if (string == "exit") {
			std::cout << "\nBye\n";
			return false;
	}
	Query query(string);
	query.setTables(tables);
	query.executeQuery();
	query.printResult();
	return true;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;

    while(std::getline(ss, item, delim)) {
    	item = trim(item);
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    if( (int)s.find(delim) == -1 ) {
    	// no delim exist, put s into the vector
    	elems.push_back(s);
    	return elems;
    }else {
    	return split(s, delim, elems);
    }
}

std::string subStrByDelim(const std::string &str, char begin, char end){
	int sb,eb;
	sb = str.find(begin);
	eb = str.find(end);
	return str.substr(sb+1,eb - sb -1 );
}

std::string trim(std::string& str)
{
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ')+1);
	return str;
}
