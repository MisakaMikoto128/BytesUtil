#include "BytesUtil.h"

/**
 * @brief  get the endian of the system using the data ENDIA_JUDGE_DATA.
 *
 * @param data : the data to be judged.It must be ENDIA_JUDGE_DATA come from other system.
 * @return Endian
 *
 * @attention the input data must be ENDIA_JUDGE_DATA come from other system.
 */
Endian getEndian(bu_uint32 data)
{
    bu_byte *p = (bu_byte *)&data;
    if (p[0] == 0x04)
    {
        return LITTLE_ENDIAN;
    }
    else
    {
        return BIG_ENDIAN;
    }
}

/**
 * @brief get self endian.
 *
 * @return Endian
 */
Endian getSelfEndian()
{
    bu_uint32 data = ENDIA_JUDGE_DATA;
    bu_byte *p = (bu_byte *)&data;
    if (p[0] == 0x04)
    {
        return LITTLE_ENDIAN;
    }
    else
    {
        return BIG_ENDIAN;
    }
}

/* @section 1: rvalue method */
/**
 * @brief convert bytes[0-3] to a float.
 *
 * @param bytes byes data
 * @param endian
 * @return bu_float
 *
 * @note the bytes data must be at least  4 bytes.
 */
bu_float bytes2floatr(const bu_byte *bytes, Endian endian)
{
    union
    {
        bu_float f;
        bu_byte b[4];
    } u;
    if (endian == LITTLE_ENDIAN)
    {
        u.b[0] = bytes[3];
        u.b[1] = bytes[2];
        u.b[2] = bytes[1];
        u.b[3] = bytes[0];
    }
    else
    {
        u.b[0] = bytes[0];
        u.b[1] = bytes[1];
        u.b[2] = bytes[2];
        u.b[3] = bytes[3];
    }
    return u.f;
}

/**
 * @brief convert bytes[0-8] to a double.
 *
 * @param bytes byes data
 * @param endian
 * @return bu_float
 *
 * @note the bytes data must be at least  8 bytes.
 */
bu_double bytes2doubler(const bu_byte *bytes, Endian endian)
{
    union
    {
        bu_double d;
        bu_byte b[8];
    } u;
    if (endian == LITTLE_ENDIAN)
    {
        u.b[0] = bytes[7];
        u.b[1] = bytes[6];
        u.b[2] = bytes[5];
        u.b[3] = bytes[4];
        u.b[4] = bytes[3];
        u.b[5] = bytes[2];
        u.b[6] = bytes[1];
        u.b[7] = bytes[0];
    }
    else
    {
        u.b[0] = bytes[0];
        u.b[1] = bytes[1];
        u.b[2] = bytes[2];
        u.b[3] = bytes[3];
        u.b[4] = bytes[4];
        u.b[5] = bytes[5];
        u.b[6] = bytes[6];
        u.b[7] = bytes[7];
    }
}

/**
 * @brief convert bytes[0-2] to a int16.
 *
 * @param bytes byes data
 * @param endian
 * @return bu_double
 *
 * @note the bytes data must be at least  2 bytes.
 */
bu_int16 bytes2int16r(const bu_byte *bytes, Endian endian)
{
    union
    {
        bu_int16 i;
        bu_byte b[2];
    } u;
    if (endian == LITTLE_ENDIAN)
    {
        u.b[0] = bytes[1];
        u.b[1] = bytes[0];
    }
    else
    {
        u.b[0] = bytes[0];
        u.b[1] = bytes[1];
    }
    return u.i;
}

/**
 * @brief convert bytes[0-4] to a int32.
 *
 * @param bytes byes data
 * @param endian
 * @return bu_int16
 *
 * @note the bytes data must be at least  be 4 bytes.
 */
bu_int32 bytes2int32r(const bu_byte *bytes, Endian endian)
{
    union
    {
        bu_int32 i;
        bu_byte b[4];
    } u;
    if (endian == LITTLE_ENDIAN)
    {
        u.b[0] = bytes[3];
        u.b[1] = bytes[2];
        u.b[2] = bytes[1];
        u.b[3] = bytes[0];
    }
    else
    {
        u.b[0] = bytes[0];
        u.b[1] = bytes[1];
        u.b[2] = bytes[2];
        u.b[3] = bytes[3];
    }
    return u.i;
}

/**
 * @brief convert bytes[0-8] to a int64.
 *
 * @param bytes byes data
 * @param endian
 * @return bu_int64
 *
 * @note the bytes data must be at least  be 8 bytes.
 */
bu_int64 bytes2int64r(const bu_byte *bytes, Endian endian)
{
    union
    {
        bu_int64 i;
        bu_byte b[8];
    } u;
    if (endian == LITTLE_ENDIAN)
    {
        u.b[0] = bytes[7];
        u.b[1] = bytes[6];
        u.b[2] = bytes[5];
        u.b[3] = bytes[4];
        u.b[4] = bytes[3];
        u.b[5] = bytes[2];
        u.b[6] = bytes[1];
        u.b[7] = bytes[0];
    }
    else
    {
        u.b[0] = bytes[0];
        u.b[1] = bytes[1];
        u.b[2] = bytes[2];
        u.b[3] = bytes[3];
        u.b[4] = bytes[4];
        u.b[5] = bytes[5];
        u.b[6] = bytes[6];
        u.b[7] = bytes[7];
    }
}

/* @section 2: pointer method */
/**
 * @brief convert bytes[0-3] to a float.
 *
 * @param bytes byes data
 * @param dst : the pointer to the variable to be assigned.
 * @param endian
 * @return void
 *
 * @note the bytes data must be at least  4 bytes.
 */
void bytes2floatp(const bu_byte *bytes, bu_float *dst, Endian endian)
{
    if (endian == LITTLE_ENDIAN)
    {
        dst[0] = bytes[3];
        dst[1] = bytes[2];
        dst[2] = bytes[1];
        dst[3] = bytes[0];
    }
    else
    {
        dst[0] = bytes[0];
        dst[1] = bytes[1];
        dst[2] = bytes[2];
        dst[3] = bytes[3];
    }
}

/**
 * @brief convert bytes[0-8] to a double.
 *
 * @param bytes byes data
 * @param dst : the pointer to the variable to be assigned.
 * @param endian
 * @return void
 *
 * @note the bytes data must be at least  8 bytes.
 */
void bytes2doublep(const bu_byte *bytes, bu_double *dst, Endian endian)
{
    if (endian == LITTLE_ENDIAN)
    {
        dst[0] = bytes[7];
        dst[1] = bytes[6];
        dst[2] = bytes[5];
        dst[3] = bytes[4];
        dst[4] = bytes[3];
        dst[5] = bytes[2];
        dst[6] = bytes[1];
        dst[7] = bytes[0];
    }
    else
    {
        dst[0] = bytes[0];
        dst[1] = bytes[1];
        dst[2] = bytes[2];
        dst[3] = bytes[3];
        dst[4] = bytes[4];
        dst[5] = bytes[5];
        dst[6] = bytes[6];
        dst[7] = bytes[7];
    }
}

/**
 * @brief convert bytes[0-2] to a int16.
 *
 * @param bytes byes data
 * @param dst : the pointer to the variable to be assigned.
 * @param endian
 * @return void
 *
 * @note the bytes data must be at least  2 bytes.
 */
void bytes2int16p(const bu_byte *bytes, bu_int16 *dst, Endian endian)
{
    if (endian == LITTLE_ENDIAN)
    {
        dst[0] = bytes[1];
        dst[1] = bytes[0];
    }
    else
    {
        dst[0] = bytes[0];
        dst[1] = bytes[1];
    }
}

/**
 * @brief convert bytes[0-4] to a int32.
 *
 * @param bytes byes data
 * @param dst : the pointer to the variable to be assigned.
 * @param endian
 * @return void
 *
 * @note the bytes data must be at least  be 4 bytes.
 */
void bytes2int32p(const bu_byte *bytes, bu_int32 *dst, Endian endian)
{
    if (endian == LITTLE_ENDIAN)
    {
        dst[0] = bytes[3];
        dst[1] = bytes[2];
        dst[2] = bytes[1];
        dst[3] = bytes[0];
    }
    else
    {
        dst[0] = bytes[0];
        dst[1] = bytes[1];
        dst[2] = bytes[2];
        dst[3] = bytes[3];
    }
}

/**
 * @brief convert bytes[0-8] to a int64.
 *
 * @param bytes byes data
 * @param dst : the pointer to the variable to be assigned.
 * @param endian
 * @return void
 *
 * @note the bytes data must be at least  be 8 bytes.
 */
void bytes2int64p(const bu_byte *bytes, bu_int64 *dst, Endian endian)
{
    if (endian == LITTLE_ENDIAN)
    {
        dst[0] = bytes[7];
        dst[1] = bytes[6];
        dst[2] = bytes[5];
        dst[3] = bytes[4];
        dst[4] = bytes[3];
        dst[5] = bytes[2];
        dst[6] = bytes[1];
        dst[7] = bytes[0];
    }
    else
    {
        dst[0] = bytes[0];
        dst[1] = bytes[1];
        dst[2] = bytes[2];
        dst[3] = bytes[3];
        dst[4] = bytes[4];
        dst[5] = bytes[5];
        dst[6] = bytes[6];
        dst[7] = bytes[7];
    }
}

/* @section 3: bytes reverse */
/**
 * @brief 2 bytes reverse.
 *
 * @param bytes byes data
 * @param det : the pointer to a byte * which will be assigned the reversed bytes.
 * @return void
 *
 * @note the bytes data must be at least  2 bytes.
 */
void reverse2bytes(const bu_byte *bytes, bu_byte *det)
{
    det[0] = bytes[1];
    det[1] = bytes[0];
}

/**
 * @brief 4 bytes reverse.
 *
 * @param bytes byes data
 * @param det : the pointer to a byte * which will be assigned the reversed bytes.
 * @return void
 *
 * @note the bytes data must be at least  4 bytes.
 */
void reverse4bytes(const bu_byte *bytes, bu_byte *det)
{
    det[0] = bytes[3];
    det[1] = bytes[2];
    det[2] = bytes[1];
    det[3] = bytes[0];
}

/**
 * @brief 8 bytes reverse.
 *
 * @param bytes byes data
 * @param det : the pointer to a byte * which will be assigned the reversed bytes.
 * @return void
 *
 * @note the bytes data must be at least 8 bytes.
 */
void reverse8bytes(const bu_byte *bytes, bu_byte *det)
{
    det[0] = bytes[7];
    det[1] = bytes[6];
    det[2] = bytes[5];
    det[3] = bytes[4];
    det[4] = bytes[3];
    det[5] = bytes[2];
    det[6] = bytes[1];
    det[7] = bytes[0];
}

/**
 * @brief n bytes reverse.
 *
 * @param bytes byes data
 * @param det : the pointer to a byte * which will be assigned the reversed bytes.
 * @param n : the number of bytes to be reversed.
 * @return void
 *
 * @note the bytes data must be at least  n bytes.
 */
void reverseNbytes(const bu_byte *bytes, bu_byte *det, bu_size_t n)
{
    bu_size_t i = 0;
    for (i = 0; i < n; i++)
    {
        det[i] = bytes[n - i - 1];
    }
}

/* section 4: convert data to bytes */
/**
 * @brief convert a float to bytes.
 *
 * @param f : the float to be converted.
 * @param det : the pointer to a byte * which will be assigned the converted bytes.
 * @param endian
 * @return void
 *
 * @note the bytes data will be at least 4 bytes space.
 */
void float2bytes(bu_float f, bu_byte *det, Endian endian)
{
    bu_byte *p = (bu_byte *)&f;
    if (endian == LITTLE_ENDIAN)
    {
        det[0] = p[3];
        det[1] = p[2];
        det[2] = p[1];
        det[3] = p[0];
    }
    else
    {
        det[0] = p[0];
        det[1] = p[1];
        det[2] = p[2];
        det[3] = p[3];
    }
}

/**
 * @brief convert a double to bytes.
 *
 * @param d : the double to be converted.
 * @param det : the pointer to a byte * which will be assigned the converted bytes.
 * @param endian
 * @return void
 *
 * @note the bytes data will be at least 8 bytes space.
 */
void double2bytes(bu_double d, bu_byte *det, Endian endian)
{
    bu_byte *p = (bu_byte *)&d;
    if (endian == LITTLE_ENDIAN)
    {
        det[0] = p[7];
        det[1] = p[6];
        det[2] = p[5];
        det[3] = p[4];
        det[4] = p[3];
        det[5] = p[2];
        det[6] = p[1];
        det[7] = p[0];
    }
    else
    {
        det[0] = p[0];
        det[1] = p[1];
        det[2] = p[2];
        det[3] = p[3];
        det[4] = p[4];
        det[5] = p[5];
        det[6] = p[6];
        det[7] = p[7];
    }
}

/**
 * @brief convert a int16 to bytes.
 *
 * @param i : the int16 to be converted.
 * @param det : the pointer to a byte * which will be assigned the converted bytes.
 * @param endian
 * @return void
 *
 * @note the bytes data will be at least 2 bytes space.
 */
void int162bytes(bu_int16 i, bu_byte *det, Endian endian)
{
    bu_byte *p = (bu_byte *)&i;
    if (endian == LITTLE_ENDIAN)
    {
        det[0] = p[1];
        det[1] = p[0];
    }
    else
    {
        det[0] = p[0];
        det[1] = p[1];
    }
}

/**
 * @brief convert a int32 to bytes.
 *
 * @param i : the int32 to be converted.
 * @param det : the pointer to a byte * which will be assigned the converted bytes.
 * @param endian
 * @return void
 *
 * @note the bytes data will be at least 4 bytes space.
 */
void int322bytes(bu_int32 i, bu_byte *det, Endian endian)
{
    bu_byte *p = (bu_byte *)&i;
    if (endian == LITTLE_ENDIAN)
    {
        det[0] = p[3];
        det[1] = p[2];
        det[2] = p[1];
        det[3] = p[0];
    }
    else
    {
        det[0] = p[0];
        det[1] = p[1];
        det[2] = p[2];
        det[3] = p[3];
    }
}

/**
 * @brief convert a int64 to bytes.
 *
 * @param i : the int64 to be converted.
 * @param det : the pointer to a byte * which will be assigned the converted bytes.
 * @param endian
 * @return void
 *
 * @note the bytes data will be at least 8 bytes space.
 */
void int642bytes(bu_int64 i, bu_byte *det, Endian endian)
{
    bu_byte *p = (bu_byte *)&i;
    if (endian == LITTLE_ENDIAN)
    {
        det[0] = p[7];
        det[1] = p[6];
        det[2] = p[5];
        det[3] = p[4];
        det[4] = p[3];
        det[5] = p[2];
        det[6] = p[1];
        det[7] = p[0];
    }
    else
    {
        det[0] = p[0];
        det[1] = p[1];
        det[2] = p[2];
        det[3] = p[3];
        det[4] = p[4];
        det[5] = p[5];
        det[6] = p[6];
        det[7] = p[7];
    }
}

/* @section 5: bit reverse */

/**
 * @brief reverse the bits of a byte.
 *
 * @param data original byte
 * @return bit reversed byte
 */
bu_byte bit_reverse8(bu_byte data)
{
    data = (((data & 0xaa) >> 1) | ((data & 0x55) << 1));
    data = (((data & 0xcc) >> 2) | ((data & 0x33) << 2));
    data = (((data & 0xf0) >> 4) | ((data & 0x0f) << 4));
    return ((data >> 8) | (data << 8));
}

/**
 * @brief reverse the bits of a uint16.
 *
 * @param data original uint16 data
 * @return bit reversed uint16
 */
bu_uint16 bit_reverse16(bu_uint16 data)
{
    data = (((data & 0xaaaa) >> 1) | ((data & 0x5555) << 1));
    data = (((data & 0xcccc) >> 2) | ((data & 0x3333) << 2));
}

/**
 * @brief reverse the bits of a uint32.
 *
 * @param data original uint32 data
 * @return bit reversed uint32
 */
bu_uint32 bit_reverse32(bu_uint32 data)
{
    data = (((data & 0xaaaaaaaa) >> 1) | ((data & 0x55555555) << 1));
    data = (((data & 0xcccccccc) >> 2) | ((data & 0x33333333) << 2));
    data = (((data & 0xf0f0f0f0) >> 4) | ((data & 0x0f0f0f0f) << 4));
    data = (((data & 0xff00ff00) >> 8) | ((data & 0x00ff00ff) << 8));
    return ((data >> 16) | (data << 16));
}

/**
 * @brief reverse the bits of a uint64.
 *
 * @param data original uint64 data
 * @return bit reversed uint64
 */
bu_uint64 bit_reverse64(bu_uint64 data)
{
    data = (((data & 0xaaaaaaaaaaaaaaaa) >> 1) | ((data & 0x5555555555555555) << 1));
    data = (((data & 0xcccccccccccccccc) >> 2) | ((data & 0x3333333333333333) << 2));
    data = (((data & 0xf0f0f0f0f0f0f0f0) >> 4) | ((data & 0x0f0f0f0f0f0f0f0f) << 4));
    data = (((data & 0xff00ff00ff00ff00) >> 8) | ((data & 0x00ff00ff00ff00ff) << 8));
    data = (((data & 0xffff0000ffff0000) >> 16) | ((data & 0x0000ffff0000ffff) << 16));
    return ((data >> 32) | (data << 32));
}
