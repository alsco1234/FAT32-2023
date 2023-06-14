// directory_entry_table을 벡터로 저장 (directory_entry_table들)
#include "fat_table.hpp"
#include "../../../util/util.hpp"

#include <vector>

FatTable::FatTable(char* fat_bytes, int fat_size)
{   
    //char 바이트 4니까
    for (auto i=0; i<fat_size; i+=4)
    { 
        auto entry = io::to_le4((char*)&fat_bytes[i]);
        fat.push_back(entry);
    }
}