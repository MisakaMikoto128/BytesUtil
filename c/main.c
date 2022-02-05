#include <stdio.h>
#include "BytesUtil.h"
int main()
{

    // show system endian
    Endian endian = getSelfEndian();
    printf("%s\n", endian == BIG_ENDIAN ? "BIG_ENDIAN" : "LITTLE_ENDIAN");

    // show peer endian
    bu_uint32 peerEndianJudgeData = ENDIA_JUDGE_DATA;
    Endian endian = getEndian(peerEndianJudgeData);
    printf("%s\n", endian == BIG_ENDIAN ? "BIG_ENDIAN" : "LITTLE_ENDIAN");


    // test data parse
    bu_byte bytes[4] = {0x12, 0x34, 0x56, 0x78};
    bu_uint32 data1 = bytes2int32r(bytes,false);
    bu_uint32 data2 = bytes2int32r(bytes,true);
    printf("data1:%d,data2:%d\n",data1,data2);
    // test pointer parse
    bu_uint32 data3 = 0;
    bytes2int32p(bytes,&data3,false);
    printf("data3:%d\n",data3);

    return 0;
}