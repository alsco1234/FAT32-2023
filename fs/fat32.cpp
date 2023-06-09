#include "../br/boot_record.hpp"

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
            this->br = new BootRecord(buffer);
        }

        // test case를 위해 private 변수 리턴
        auto get_br() -> BootRecord*
        {
            return this->br;
        }

    private:
        ifstream* ifs;
        BootRecord* br;
        //FatTable* fat;
        //Node* root;
};
