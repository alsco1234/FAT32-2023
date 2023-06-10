#include "fat32.hpp"
#include "../src/fs/fat/boot_record.hpp"

#include <fstream>

namespace script::engine::fs
{
    Fat32::Fat32(string_view _fname) : fname(_fname), in(_fname.data()), buffer(new char[0x200]) //  data(): string_view 객체에 대해 문자열 데이터의 시작 포인터를 반환
    {   
        in.read(buffer, 0x200);
        br = new BootRecord(buffer);
    }

    Fat32::~Fat32()
    {
        delete[] buffer;
    }

    auto Fat32::good() const -> bool
    {
        return in.is_open();
    }

    auto Fat32::get_br() -> BootRecord*
    {
        return this->br;
    }
}
