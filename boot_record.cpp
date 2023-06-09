#include "boot_record.hpp"
#include "util.hpp"
#include <iostream>

BootRecord::BootRecord(char* buffer)
{
    bytes_per_sector = io::to_le2(buffer + 0x0b);
    sector_per_cluster = io::to_le1(buffer + 0x0d);
    cluster_size = bytes_per_sector * sector_per_cluster;
    fat_count = io::to_le1(buffer + 0x10);  // 0-offset F다음에 1 byte만큼 읽어야 함으로 16 = 0x10
    reserved_area = io::to_le2(buffer + 0x0e);    
    fat1_offset  = reserved_area * bytes_per_sector;        
    sector_per_fat = io::to_le4(buffer + 0x24); // 36번째부터 4 byte를 읽어야 함으로        
    data_block_area = reserved_area + fat_count * sector_per_fat * bytes_per_sector;    
}