#include "../../script.engine/fat32.hpp"

#include <cstdlib>
#include <string>
#include <iostream>

namespace fs = script::engine::fs;

using namespace std;

int main()
{
    //auto home = string(getenv("HOME"));
    auto fat32_data = "../../data/fat32.mdf";
    auto export_path = "../../test";

    cout << "fat32_data: " << fat32_data << endl;
    cout << "export_path: " << export_path << endl;

    fs::Fat32 a(fat32_data);

    cout << "Read file success: " << boolalpha <<  a.good() << endl;

    cout << "Bytes per sector: " << a.get_br()->bytes_per_sector << endl;   // for test br

    cout << "Fat table cluster 1 name: " << hex << a.get_ft()->fat[0] << endl;   // for test br : fffff8
    cout << "Fat table cluster 8 name: " << hex << a.get_ft()->fat[7] << endl;   // for test br : 8

    // TODO
    // Directory Entry를 탐색하면서, fat_table에 vector형태로 저장한다. -> DirectoryEntry, FatTable class
    // fat_table로 부터 entry를 하나씩 꺼내 node를 만든다. ->  Node class
    // entry의 정보가 저장된 node로부터, start ~ end cluster를 참고하여 bin파일을 읽은 후, export한다.
    // 최종적으로 Fat32 객체 하나로 모두 작동한다.

    return 0;
}