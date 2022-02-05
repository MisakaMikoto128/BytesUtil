#include <stdio.h>
#include "BytesUtil.h"
int main()
{

    // show system endian
    Endian endian = getSelfEndian();
    printf("%s\n", endian == BIG_ENDIAN ? "BIG_ENDIAN" : "LITTLE_ENDIAN");

    // test endian
    int i = 0;
    // bu_uint32 data= 0x12345678;
    // bu_byte *bytes = (bu_byte *)&data;
    bu_byte bytes[4] = {0x12, 0x34, 0x56, 0x78};
    union
    {
        bu_int32 i;
        bu_byte b[4];
    } u;

     *((bu_int32 *)&u) = *((bu_int32 *)bytes);

    // u.b[0] = bytes[0];
    // u.b[1] = bytes[1];
    // u.b[2] = bytes[2];
    // u.b[3] = bytes[3];

    // u.b[0] = bytes[3];
    // u.b[1] = bytes[2];
    // u.b[2] = bytes[1];
    // u.b[3] = bytes[0];
    bu_int32 a = u.i;
    for(i = 0; i < 4; i++)
    {
        printf("%#x\n", u.b[i]);
    }
    printf("%#x\n", a);

    return 0;
}