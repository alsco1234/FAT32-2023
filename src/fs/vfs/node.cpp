/*
저장된 빨간네모가지고 export
*/
#include <string>
#include <fstream>
#include <timestamp>
#include "../fat/directory_entry.cpp"

using namespace std;

class Node{
    public:
        Node(DirectoryEntry* de, ifstream* ifs);

        auto ExportTo(string path) -> bool
        {
            /*
                STREAM으로 read 연속적 읽기 구현
                fat는 단순하게 연속적인 cluster 번호로 ㅇ릭기 때문에
                buf로 시작점과 size 받아 연속으로 읽기
            */
            size = stream.Size();
            buf = stream.read(0, sz);
            return true;
        }

    private:
        string name;
        vector<Node> childern; //linked list로 자식 node 연결
        timestamp mtime;
        NodeStreaam stream;
};
