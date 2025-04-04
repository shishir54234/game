#pragma once
#include <string>

struct MapData
{
    int version;

    std::string tilesheet = "";
    std::string name = "";

    int mapWidth = 0;
    int mapHeight = 0;

    int tileWidth = 16;
    int tileHeight = 16;

    int scaleX = 5;
    int scaleY = 5;

    int dataLength = 6;
    int* data = nullptr;
};