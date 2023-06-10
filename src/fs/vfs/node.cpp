/*
저장된 빨간네모가지고 export
*/
#include <string>
#include <fstream>
#include "../fat/directory_entry.cpp"

using namespace std;

class Node{
    public:
        Node(DirectoryEntry* de, ifstream* ifs);

    bool ExportTo(string path);
};
