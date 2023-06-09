#pragma once

#include "../br/boot_record.hpp"

#include <fstream>
#include <string>

namespace script::engine::fs
{
    using namespace std;

    class Fat32
    {
    public:
        explicit Fat32(string_view _fname);  //  명시적인 형 변환을 통해 객체를 생성하여 전달하도록 함
                                             //  string_view: 별도의 메모리 할당 없이 기존 문자열 데이터를 참조하여 사용함
        ~Fat32();
    
        auto good() const -> bool;

        auto get_br() -> BootRecord*;   //  테스트 목적 함수

    private:
    BootRecord* br;

    private:
        string fname;
        ifstream in;
        char* buffer;
    };
}