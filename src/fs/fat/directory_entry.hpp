#pragma once

//#include "../vfs/node.cpp"
#include <vector>
#include <chrono>
#include <string>

using namespace std;

// 하나의 node를 만들기 위한 정보 가지고있음
class DirectoryEntry
{
public:
    DirectoryEntry(char* buffer, vector<uint32_t> fat);
    // TODO
    // Node하나를 만들때 마다, Directory Entry객체가 하나씩 생성된다.
    // Directory Entry는 32 byte씩 읽는다.
    // 그러기 위해서는 buffer를 0x20만큼 읽어서 DirectoryEntry생성자에게 넘겨주는데
    // buffer에 읽어들이기 전에 파일 ptr를 이동시켜줘야 한다. -> FAT 영역 시작주소 + FAT영역 총 크기만큼 ptr를 이동

    auto get_name() -> string;

private:
    string name;
    string extension;
    bool is_dir;
    int cluster_no;
    int file_size;
    vector<uint32_t> whole_cluster;

    chrono::time_point<chrono::system_clock> mtime; // modified time
    chrono::time_point<chrono::system_clock> atime; // access time
    chrono::time_point<chrono::system_clock> ctime; // created time

    //vector<Node> childern; // linked list로 자식 node 연결
    //NodeStreaam stream;
};