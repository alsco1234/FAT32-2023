/*
빨간네모 분석하는 구조체
*/
#include "directory_entry.hpp"
#include <vector>
#include <fstream>
#include <chrono>

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
    /* buffer 읽어서 분석
    32 바이트 읽어서
    name이랑
    childeren이랑 
    mac time 분석
    */
    // 분석한거 가지고 new node 만들기
    //Node node = new node(DirectoryEntry* de, ifstream* ifs);
}