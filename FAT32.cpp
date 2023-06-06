/* 
각 클래스들 적절한 이니셜로 생성
*/

class Fat32
{
    public:
        Fat32(ifstream* ifs)
        
        Node* GetNode(char const* name)

    private:
        ifstream* ifs;
        BootRecord* br;
        FatTable* fat;
        Node* root;
}
