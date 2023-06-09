#include "fat32.hpp"
#include "../br/boot_record.hpp"

#include <fstream>

namespace script::engine::fs
{
    Fat32::Fat32(string_view _fname) : fname(_fname) {}

    Fat32::~Fat32() {}

    auto Fat32::good() const -> bool
    {
        ifstream in(fname);
        return in.is_open();
    }
}
