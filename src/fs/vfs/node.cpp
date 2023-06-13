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

        bool ExportTo(string path){
            size = stream.Size();
            buf = stream.read(0, sz);
        }

    private:
        string name;
        vector<Node> childern; //linked list로 자식 node 연결
        timestamp mtime;
        NodeStreaam stream;
};
