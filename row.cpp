#include "row.h"

void Row::addData(const std::string &colName, const std::string &data){
	mapData.insert(std::pair<std::string,std::string>(colName, data));
}
void Row::printMapData(){
	 // showing contents:

	  std::cout << "--------------------------------" <<"\n map data contains:\n" << std::endl;
	  for ( std::map<std::string,std::string>::iterator it=mapData.begin() ; it != mapData.end(); it++ ){
		  std::cout << (*it).first << " => " << (*it).second << " ; " <<std::endl;
	  }
}
