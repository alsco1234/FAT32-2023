#include "boot_record.hpp"
#include "util.hpp"

BootRecord::BootRecord(char* buffer)
{
    int bytes_per_sector = io::to_le2(buffer + 0x0b);
    int sector_per_cluster = io::to_le1(buffer + 0x0d);
    int cluster_size = bytes_per_sector * sector_per_cluster;
    int fat_count = io::to_le1(buffer + 0x10);  // 0-offset F다음에 1 byte만큼 읽어야 함으로 16 = 0x10
    int reserved_area = io::to_le2(buffer + 0x0e) * bytes_per_sector;    
    int fat1_offset  = reserved_area;            
    int sector_per_fat = io::to_le4(buffer + 0x24); // 36번째부터 4 byte를 읽어야 함으로        
    int data_block_area = reserved_area + fat_count * sector_per_fat * bytes_per_sector;    
}