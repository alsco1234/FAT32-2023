#include "fs/fat32.hpp"

#include <cstdlib>
#include <string>
#include <iostream>

namespace fs = script::engine::fs;

using namespace std;

int main()
{
    //auto home = string(getenv("HOME"));
    auto fat32_data = "../data/fat32.mdf";
    auto export_path = "../test";

    fs::Fat32 a(fat32_data);

    cout << "Read file success: " << boolalpha <<  a.good() << endl;

    cout << "Bytes per sector: " << a.get_br()->bytes_per_sector << endl;

    return 0;
}