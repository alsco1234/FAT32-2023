#pragma once

#include <vector>

using namespace std;

class FatTable{
    public:
        FatTable(char* fat_bytes, int fat_size);

    public:
        vector<uint32_t> fat;
};