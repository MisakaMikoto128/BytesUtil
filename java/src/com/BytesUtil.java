package com;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

public class BytesUtil {
    //    static public <T> T bytes2Obj(byte[] bytes,int offset,) throws Exception
//    {
//        switch ()
//    }
    public static final int ENDIA_JUDGE_DATA = 0x20220204;
    private static Charset default_charset = StandardCharsets.UTF_8;
    public static final ByteOrder default_order = ByteOrder.nativeOrder();

    public static Charset getDefault_charset() {
        return default_charset;
    }

    public static void setDefault_charset(Charset default_charset) {
        BytesUtil.default_charset = default_charset;
    }

    /**
     * @param judge_bytes : the data to be judged.It must be ENDIA_JUDGE_DATA bytes come from other system.
     * @return Endian
     * @brief get the endian of the system using the data ENDIA_JUDGE_DATA.
     */
    public static ByteOrder getEndian(byte[] judge_bytes) {
        if (judge_bytes[0] == 0x04) {
            return ByteOrder.LITTLE_ENDIAN;
        } else {
            return ByteOrder.BIG_ENDIAN;
        }
    }

    /**
     * @return Endian
     * @brief get self endian.
     */
    public static ByteOrder getSelfEndian() {
        return ByteOrder.nativeOrder();
    }

    /**
     * @param data  short data.
     * @param order the byte order will be converted.
     * @return byte[] data of input short.
     * @brief get bytes of short data.
     */
    public static byte[] getBytes(short data, ByteOrder order) {
        return getBytes(data, order);
    }

    public static byte[] getBytes(char data, ByteOrder order) {
        return getBytes(data, order);
    }

    public static byte[] getBytes(int data, ByteOrder order) {
        return getBytes(data, order);
    }

    public static byte[] getBytes(long data, ByteOrder order) {
        return getBytes(data, order);
    }

    public static byte[] getBytes(float data, ByteOrder order) {
        return getBytes(data, order);
    }

    public static byte[] getBytes(double data, ByteOrder order) {
        return getBytes(data, order);
    }

    public static byte[] getBytes(String data, Charset charset) {
        //TODO : BOM
        return data.getBytes(charset);
    }

    public static byte[] getBytes(String data) {
        //TODO : BOM
        return getBytes(data, default_charset);
    }

    /**
     * @param bytes short data bytes.
     * @param order the byte order will be converted.
     * @return short data of input bytes.
     * @brief get short from bytes data.
     */
    public static short getShort(byte[] bytes, ByteOrder order) {
        return getShort(bytes, order);
    }

    public static char getChar(byte[] bytes, ByteOrder order) {
        return getChar(bytes, order);
    }

    public static int getInt(byte[] bytes, ByteOrder order) {
        return getInt(bytes, order);
    }

    public static long getLong(byte[] bytes, ByteOrder order) {
        return getLong(bytes, order);
    }

    public static float getFloat(byte[] bytes, ByteOrder order) {
        return getFloat(bytes, order);
    }

    public static double getDouble(byte[] bytes, ByteOrder order) {
        return getDouble(bytes, order);
    }

    public static String getString(byte[] bytes, Charset charset) {
        //TODO : BOM
        return new String(bytes, charset);
    }

    public static String getString(byte[] bytes) {
        //TODO : BOM
        return getString(bytes, default_charset);
    }

    /**
     * @param data short data.
     * @return byte[] data of input short.
     * @brief get bytes of short data.using default byte order.
     */
    public static byte[] getBytes(short data) {
        return getBytes(data, default_order);
    }

    /**
     * @param bytes  short data bytes.
     * @param offset The offset within the array of the first byte to be read; must be non-negative and no larger than src.length.
     * @param order  the byte order will be converted.
     * @return short data of input bytes.
     * @brief get short from bytes data.
     */
    public static short getShort(byte[] bytes, int offset, ByteOrder order) {
        ByteBuffer buf = ByteBuffer.allocate(Short.BYTES);
        buf.put(bytes, offset, Short.BYTES);
        buf.order(order);
        return buf.getShort(0);
    }

    /**
     * @param bytes  char data bytes.
     * @param offset The offset within the array of the first byte to be read; must be non-negative and no larger than src.length.
     * @param order  the byte order will be converted.
     * @return char data of input bytes.
     */
    public static char getChar(byte[] bytes, int offset, ByteOrder order) {
        ByteBuffer buf = ByteBuffer.allocate(Character.BYTES);
        buf.put(bytes, offset, Character.BYTES);
        buf.order(order);
        return buf.getChar(0);
    }


    /**
     * @param bytes  int data bytes.
     * @param offset The offset within the array of the first byte to be read; must be non-negative and no larger than src.length.
     * @param order  the byte order will be converted.
     * @return int data of input bytes.
     * @brief get int from bytes data.
     */
    public static int getInt(byte[] bytes, int offset, ByteOrder order) {
        ByteBuffer buf = ByteBuffer.allocate(Integer.BYTES);
        buf.put(bytes, offset, Integer.BYTES);
        buf.order(order);
        return buf.getInt(0);
    }



    /**
     * @param bytes  short data bytes.
     * @param offset The offset within the array of the first byte to be read; must be non-negative and no larger than src.length.
     * @return short data of input bytes.
     * @brief get short from bytes data.
     */
    public static short getShort(byte[] bytes, int offset) {
        return getShort(bytes, offset, default_order);
    }

}
