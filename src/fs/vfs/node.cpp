/*
저장된 빨간네모가지고 export
*/
#include <string>
#include <fstream>
#include <chrono>
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
            //size = stream.Size();
            //sizebuf = stream.read(0, size);

            // 파일에 쓰기
            return true;
        }

    private:
        string name;
        vector<Node> childern; // linked list로 자식 node 연결
        chrono::time_point<chrono::system_clock> mtime; // modified time
        chrono::time_point<chrono::system_clock> atime; // access time
        chrono::time_point<chrono::system_clock> ctime; // created time
        //NodeStreaam stream;
};