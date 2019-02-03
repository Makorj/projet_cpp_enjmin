#include "Data.h"
#include <fstream>
#include <iostream>



Data::Data()
{
}


Data::~Data()
{
}

void Data::LoadMap(std::string mapFilePath){

	std::fstream mapFile(mapFilePath.c_str(), std::ios::in);
	std::string map = "";

	if (!mapFile.is_open())
	{
		std::cerr << "Unable to open mapfile " + mapFilePath << std::endl;
		return;
	}

	/*while (!mapFile.eof())
	{
		map += map
	}*/

}