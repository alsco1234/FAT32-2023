#pragma once

class BootRecord
{
public:
    BootRecord(char* buffer);

    int bytes_per_sector;       // 1섹터당 바이트 수
    int sector_per_cluster;     //  1클러스터당 섹터 수
    int cluster_size;           //  클러스터 크기
    int fat_count;              //  FAT영역 수
    int reserved_area;          //  예약된 영역의 섹터 수
    int fat1_offset;            //  FAT1 영역 시작 지점
    int sector_per_fat;         //  FAT영역의 섹터 수
    int data_block_area;        //  Data영역 시작 지점  
};