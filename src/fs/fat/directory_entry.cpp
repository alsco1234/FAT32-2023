/*
빨간네모 분석하는 구조체
*/
#include "directory_entry.hpp"
#include "../../../util/util.hpp"
#include <vector>
#include <fstream>
#include <chrono>
#include <iostream>

using namespace std;

// 하나의 node를 만들기 위한 정보 가지고있음
// TODO
    // Node하나를 만들때 마다, Directory Entry객체가 하나씩 생성된다.
    // Directory Entry는 32 byte씩 읽는다.
    // 그러기 위해서는 buffer를 0x20만큼 읽어서 DirectoryEntry생성자에게 넘겨주는데
    // buffer에 읽어들이기 전에 파일 ptr를 이동시켜줘야 한다. -> FAT 영역 시작주소 + FAT영역 총 크기만큼 ptr를 이동

// 생성자
DirectoryEntry::DirectoryEntry(char* buffer, vector<uint32_t> fat)
{   
    this->name = string(buffer, 0, 8);

    this->extension = string(buffer + 0x08, 8, 3);

    int attr = io::to_le1(buffer + 0x0b);
    if ((attr & 0x10) == 0x10) this->is_dir = true;
    else this->is_dir = false;

    this->cluster_no = io::to_le2(buffer+0x14)<<2 | io::to_le2(buffer+0x1a);

    this->file_size = io::to_le4(buffer+0x1c);
            
    this->whole_cluster.push_back(this->cluster_no);
    uint32_t current_no = fat[this->cluster_no];
    while (current_no != 0xfffffff)
    {
        this->whole_cluster.push_back(current_no);
        current_no = fat[current_no];
    }

    this->mtime = std::chrono::system_clock::from_time_t(io::to_le2(buffer+0x10));
    this->atime = std::chrono::system_clock::from_time_t(io::to_le2(buffer+0x12));
    this->ctime = std::chrono::system_clock::from_time_t(io::to_le4(buffer+0x16));

    //Node node = new node(DirectoryEntry* de, ifstream* ifs);
}

// private name 테스트용 함수
auto DirectoryEntry::get_name() -> string
{
    return name;
}