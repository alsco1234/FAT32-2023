#include <cstdint>
#include "util.hpp"

namespace io
{
    int to_le1(char * bytes)
    {
        return *bytes;
    }

    int to_le2(char* bytes)
    {
        return *(int16_t *) bytes;  //  bytes ptr를 int32_t로 casting후 역참조하여 값을 가져온다.
    }

    int to_le4(char* bytes)
    {
        return *(int32_t *) bytes;
    }
}