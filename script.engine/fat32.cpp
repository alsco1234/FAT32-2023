#include "fat32.hpp"
#include "../src/fs/fat/boot_record.hpp"
#include "../src/fs/fat/fat_table.hpp"
#include "../src/fs/fat/directory_entry.hpp"

#include <fstream>

namespace script::engine::fs
{
    Fat32::Fat32(string_view _fname) : fname(_fname), in(_fname.data()), buffer(new char[0x200]) //  data(): string_view 객체에 대해 문자열 데이터의 시작 포인터를 반환
    {   
        in.read(buffer, 0x200);
        br = new BootRecord(buffer);

        in.seekg(br->fat1_offset, ios_base::beg);
        auto fat_size = br->reserved_area * br->bytes_per_sector; //215c00
        vector<char> fat_bytes(fat_size);
        in.read(&fat_bytes[0], fat_size);
        ft = new FatTable(&fat_bytes[0], fat_size);

        char buffer2[0x20] = { 0 };
        // in.seekg(br->data_block_area, ios_base::beg); //400000 => libc++abi: terminating with uncaught exception of type std::out_of_range: basic_string
        in.seekg(0x404040, ios_base::beg);
        in.read(buffer2, 0x20);
        de = new DirectoryEntry(buffer2, ft->fat);
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

    auto Fat32::get_ft() -> FatTable*
    {
        return this->ft;
    }

    auto Fat32::get_de() -> DirectoryEntry*
    {
        return this->de;
    }
}
