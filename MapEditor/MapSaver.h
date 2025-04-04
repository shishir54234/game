#pragma once
#include <string>
#include "../MapData.h"

class MapSaver
{
public:
	void Save(const std::string& filename, const MapData& mapData);
};