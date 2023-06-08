#include "boot_record.hpp"
#include "FatTable.cpp" // 보통 hpp파일을 불러온다(hpp로 수정필요)
#include "node.cpp"

#include <fstream>

using namespace std;

class Fat32
{
    public:
        Fat32(ifstream* ifs)
        {
            this->ifs = ifs;
            
            char buffer[0x200] = { 0 }; // 처음 한 sector를 전부 읽기 위해 0x200만큼 읽도록 수정
            ifs->read(buffer, 0x200);   //  mdf파일을 열어보면 Byte Per Sector = 0x200인것을 알 수 있다.
            br = new BootRecord(buffer);
        }

        /* 하나의 노드 받아오기
        Node* GetNode(char const* name)
        {
            
        }
        */

        // test case를 위해 private 변수 리턴
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
