#include <iostream>
#include <fstream>
#include "FAT32.cpp"

using namespace std;

int main(int argc, char* argv[]){
    //argv[1] = 복구할 mdf path
    ifstream ifs(argv[1]);

    //목표는 이렇게 했을 때 전부 복구되는거
    Fat32 fat32(&ifs);

    // TEST1 :byte_per_sector를 읽었을때 0x200인가?
    assert(fat32.get_br()->bytepersector == 0x200);

    // TEST2 : sector_per_cluter 를 읽었을때 0x8인가?
    assert(fat32.get_br()->sector_per_cluter == 0x8);

    // TEST3 : reserved_area를 읽었을때 0x08인가?
    assert(fat32.get_br()->reserved_area == 0x10AE);

    return 0;
}