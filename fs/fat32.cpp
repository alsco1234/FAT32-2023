#include "fat32.hpp"
#include "../br/boot_record.hpp"

#include <fstream>

namespace script::engine::fs
{
    Fat32::Fat32(string_view _fname) : fname(_fname), in(_fname.data()) {}  //  data(): string_view 객체에 대해 문자열 데이터의 시작 포인터를 반환

    Fat32::~Fat32() {}

    auto Fat32::good() const -> bool
    {
        return in.is_open();
    }
}
