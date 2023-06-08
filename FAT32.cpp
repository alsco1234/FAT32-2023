/*
FAT32 class
각 클래스들 적절한 이니셜로 생성
*/
#include <fstream>
#include "node.cpp"
#include "boot_record.cpp"
#include "FatTable.cpp"

using namespace std;

class Fat32
{
    public:
        Fat32(ifstream* ifs)
        {
            this->ifs = ifs;
            // bootrecord에서 읽어야 하는 정보는 0x0 ~ 0x20까지
            char buffer[0x20] = { 0 };
            ifs->read(buffer, 0x20);
            br = new BootRecord(buffer);
        }

        /* 하나의 노드 받아오기
        Node* GetNode(char const* name)
        {
            
        }
        */

        auto get_br() -> BootRecord*
        {
            return br;
        }

    private:
        ifstream* ifs;
        BootRecord* br;
        FatTable* fat;
        Node* root;
};
