#ifndef _BYTES_UTIL_H_
#define _BYTES_UTIL_H_
#ifdef __cplusplus
extern "C" {
#endif
/*
Naming Rule:
1. Categorize by the method of getting the result.
<data type> bytes2<data type><method>(const byte* bytes,xxx);
<data type>: int32, float, double, etc.
<method>: r: rvalue, assign the result to the variable by return value.
          p: pointer, assign the result to the variable by pass variable's pointer to parameter.

You can quickly search "@section" int IDE to see the different categories of methods

2. spuuort : at least c89
*/

#include <stdbool.h>
//Select the appropriate platform nefore writing other code,the default configuration is 32-bit machines
// #define _8_BIT_SYSTEM
// #define _16_BIT_SYSTEM
// #define _32_BIT_SYSTEM
// #define _64_BIT_SYSTEM
#define _32_BIT_SYSTEM

#ifdef _8_BIT_SYSTEM //TODO : the following definitions are for 8-bit maybe wrong
#define bu_uint8 unsigned char
#define bu_int8 char
#define bu_uint16 unsigned short
#define bu_int16 short
#define bu_uint32 unsigned long
#define bu_int32 long
#define bu_uint64 unsigned long long
#define bu_int64 long long
#define bu_float float
#define bu_double double

#define bu_byte bu_uint8
#define bu_word bu_uint16
#define bu_dword bu_uint32
#define bu_qword bu_uint64

#define bu_size_t bu_uint32
#endif

#ifdef _16_BIT_SYSTEM
#define bu_uint8 unsigned char
#define bu_int8 char
#define bu_uint16 unsigned short
#define bu_int16 short
#define bu_uint32 unsigned long
#define bu_int32 long
#define bu_uint64 unsigned long long
#define bu_int64 long long
#define bu_float float
#define bu_double double
#define bu_byte bu_uint8

#define bu_byte bu_uint8
#define bu_word bu_uint16
#define bu_dword bu_uint32
#define bu_qword bu_uint64

#define bu_size_t bu_uint32
#endif

#ifdef _32_BIT_SYSTEM
#define bu_uint8 unsigned char
#define bu_int8 char
#define bu_uint16 unsigned short
#define bu_int16 short
#define bu_uint32 unsigned int
#define bu_int32 int
#define bu_uint64 unsigned long long
#define bu_int64 long long
#define bu_float float
#define bu_double double
#define bu_byte bu_uint8

#define bu_byte bu_uint8
#define bu_word bu_uint16
#define bu_dword bu_uint32
#define bu_qword bu_uint64

#define bu_size_t bu_uint32
#endif

#ifdef _64_BIT_SYSTEM
#define bu_uint8 unsigned char
#define bu_int8 char
#define bu_uint16 unsigned short
#define bu_int16 short
#define bu_uint32 unsigned int
#define bu_int32 int
#define bu_uint64 unsigned long long
#define bu_int64 long long
#define bu_float float
#define bu_double double
#define bu_byte bu_uint8

#define bu_byte bu_uint8
#define bu_word bu_uint16
#define bu_dword bu_uint32
#define bu_qword bu_uint64

#define bu_size_t bu_uint32
#endif


typedef enum {
    LITTLE_ENDIAN = 0,
    BIG_ENDIAN = 1
}Endian;
#define ENDIA_JUDGE_DATA 0x20220204

/**
 * @brief  get the endian of the system using the data ENDIA_JUDGE_DATA.
 * 
 * @param data : the data to be judged.It must be ENDIA_JUDGE_DATA come from other system.
 * @return Endian 
 */
Endian getEndian(bu_uint32 data);

/**
 * @brief get self endian.
 * 
 * @return Endian
 */
Endian getSelfEndian();

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
bu_float bytes2floatr(const bu_byte* bytes,Endian endian);

/**
 * @brief convert bytes[0-8] to a double.
 * 
 * @param bytes byes data
 * @param endian 
 * @return bu_float 
 * 
 * @note the bytes data must be at least  8 bytes.
 */
bu_double bytes2doubler(const bu_byte* bytes,Endian endian);

/**
 * @brief convert bytes[0-2] to a int16.
 * 
 * @param bytes byes data
 * @param endian 
 * @return bu_double 
 * 
 * @note the bytes data must be at least  2 bytes.
 */
bu_int16 bytes2int16r(const bu_byte* bytes,Endian endian);

/**
 * @brief convert bytes[0-4] to a int32.
 * 
 * @param bytes byes data
 * @param endian 
 * @return bu_int16 
 * 
 * @note the bytes data must be at least  be 4 bytes.
 */
bu_int32 bytes2int32r(const bu_byte* bytes,Endian endian);

/**
 * @brief convert bytes[0-8] to a int64.
 * 
 * @param bytes byes data
 * @param endian
 * @return bu_int64
 * 
 * @note the bytes data must be at least  be 8 bytes.
 */
bu_int64 bytes2int64r(const bu_byte* bytes,Endian endian);

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
void bytes2floatp(const bu_byte* bytes,bu_float *dst,Endian endian);

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
void bytes2doublep(const bu_byte* bytes,bu_double *dst,Endian endian);


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
void bytes2int16p(const bu_byte* bytes,bu_int16 *dst,Endian endian);


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
void bytes2int32p(const bu_byte* bytes,bu_int32 *dst,Endian endian);


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
void bytes2int64p(const bu_byte* bytes,bu_int64 *dst,Endian endian);


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
void reverse2bytes(const bu_byte* bytes,bu_byte* det);


/**
 * @brief 4 bytes reverse.
 * 
 * @param bytes byes data
 * @param det : the pointer to a byte * which will be assigned the reversed bytes.
 * @return void
 * 
 * @note the bytes data must be at least  4 bytes.
 */
void reverse4bytes(const bu_byte* bytes,bu_byte* det);


/**
 * @brief 8 bytes reverse.
 * 
 * @param bytes byes data
 * @param det : the pointer to a byte * which will be assigned the reversed bytes.
 * @return void
 * 
 * @note the bytes data must be at least 8 bytes.
 */
void reverse8bytes(const bu_byte* bytes,bu_byte* det);


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
void reverseNbytes(const bu_byte* bytes,bu_byte* det,bu_size_t n);


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
void float2bytes(bu_float f,bu_byte* det,Endian endian);


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
void double2bytes(bu_double d,bu_byte* det,Endian endian);


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
void int162bytes(bu_int16 i,bu_byte* det,Endian endian);


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
void int322bytes(bu_int32 i,bu_byte* det,Endian endian);


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
void int642bytes(bu_int64 i,bu_byte* det,Endian endian);

/* @section 5: bit reverse */

/* @section end: Summarize all methods into comment */
/*
Endian getEndian(bu_uint32 data);

bu_float bytes2floatr(const bu_byte* bytes,Endian endian);
bu_double bytes2doubler(const bu_byte* bytes,Endian endian);
bu_int16 bytes2int16r(const bu_byte* bytes,Endian endian);
bu_int32 bytes2int32r(const bu_byte* bytes,Endian endian);
bu_int64 bytes2int64r(const bu_byte* bytes,Endian endian);

void float2bytesr(bu_float f,bu_byte* det,Endian endian);
void double2bytesr(bu_double d,bu_byte* det,Endian endian);
void int162bytesr(bu_int16 i,bu_byte* det,Endian endian);
void int322bytesr(bu_int32 i,bu_byte* det,Endian endian);
void int642bytesr(bu_int64 i,bu_byte* det,Endian endian);

void reverse2bytes(const bu_byte* bytes,bu_byte* det);
void reverse4bytes(const bu_byte* bytes,bu_byte* det);
void reverse8bytes(const bu_byte* bytes,bu_byte* det);
void reverseNbytes(const bu_byte* bytes,bu_byte* det,bu_size_t n);

void float2bytes(bu_float f,bu_byte* det,Endian endian);
void double2bytes(bu_double d,bu_byte* det,Endian endian);
void int162bytes(bu_int16 i,bu_byte* det,Endian endian);
void int322bytes(bu_int32 i,bu_byte* det,Endian endian);
void int642bytes(bu_int64 i,bu_byte* det,Endian endian);
*/
#ifdef __cplusplus
}
#endif

#endif // _BYTES_UTIL_H_