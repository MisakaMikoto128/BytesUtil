#include <iostream>
#include "BytesUtil.hpp"
using namespace std;

int main()
{
    Endian endian;
     // show system endian
    endian = BytesUtil::getSelfEndian();
    printf("%s\n", endian == LBIG_ENDIAN ? "BIG_ENDIAN" : "LITTLE_ENDIAN");

    // show peer endian
    bu_uint32 peerEndianJudgeData = ENDIA_JUDGE_DATA;
    endian = BytesUtil::getEndian((const bu_byte*)&peerEndianJudgeData);
    printf("%s\n", endian == LBIG_ENDIAN ? "BIG_ENDIAN" : "LITTLE_ENDIAN");


    // test data parse
    bu_byte bytes[4] = {0x12, 0x34, 0x56, 0x78};
    bu_uint32 data1 = BytesUtil::getObj<bu_uint32>(bytes,false);
    bu_uint32 data2 = BytesUtil::getObj<bu_uint32>(bytes,true);
    printf("data1:%x,data2:%x\n",data1,data2);

    return 0;
}