package com;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

public class BytesUtil {

    public static final int ENDIA_JUDGE_DATA = 0x20220204;
    private static Charset default_charset = StandardCharsets.UTF_8;
    public static final ByteOrder default_order = ByteOrder.nativeOrder();

    public static Charset getDefault_charset() {
        return default_charset;
    }

    public static void setDefault_charset(Charset default_charset) {
        BytesUtil.default_charset = default_charset;
    }

    /** @section 1 String */

    public static byte[] getBytes(String data, Charset charset) {
        // TODO : BOM
        return data.getBytes(charset);
    }

    public static byte[] getBytes(String data) {
        // TODO : BOM
        return getBytes(data, default_charset);
    }

    public static String getString(byte[] bytes, Charset charset) {
        // TODO : BOM
        return new String(bytes, charset);
    }

    public static String getString(byte[] bytes) {
        // TODO : BOM
        return getString(bytes, default_charset);
    }

    /** @section 2 endian check */

    /**
     * @param judge_bytes : the data to be judged.It must be ENDIA_JUDGE_DATA bytes
     *                    come from other system.
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

    /** @section 3 get bytes */
    /** @section 3.1 */
    /**
     * @param data  short data.
     * @param order the byte order will be converted.
     * @return byte[] data of input short.
     * @brief get bytes of short data.
     */
    public static byte[] getBytes(short data, ByteOrder order) {
        ByteBuffer buffer = ByteBuffer.allocate(Short.BYTES);
        buffer.putShort(data);
        buffer.order(order);
        return buffer.array();
    }

    public static byte[] getBytes(char data, ByteOrder order) {
        ByteBuffer buffer = ByteBuffer.allocate(Character.BYTES);
        buffer.putChar(data);
        buffer.order(order);
        return buffer.array();
    }

    public static byte[] getBytes(int data, ByteOrder order) {
        ByteBuffer buffer = ByteBuffer.allocate(Integer.BYTES);
        buffer.putInt(data);
        buffer.order(order);
        return buffer.array();
    }

    public static byte[] getBytes(long data, ByteOrder order) {
        ByteBuffer buffer = ByteBuffer.allocate(Long.BYTES);
        buffer.putLong(data);
        buffer.order(order);
        return buffer.array();
    }

    public static byte[] getBytes(float data, ByteOrder order) {
        ByteBuffer buffer = ByteBuffer.allocate(Float.BYTES);
        buffer.putFloat(data);
        buffer.order(order);
        return buffer.array();
    }

    public static byte[] getBytes(double data, ByteOrder order) {
        ByteBuffer buffer = ByteBuffer.allocate(Double.BYTES);
        buffer.putDouble(data);
        buffer.order(order);
        return buffer.array();
    }

    /** @section 3.2 */
    public static byte[] getBytes(short data) {
        return getBytes(data, default_order);
    }

    public static byte[] getBytes(char data) {
        return getBytes(data, default_order);
    }

    public static byte[] getBytes(int data) {
        return getBytes(data, default_order);
    }

    public static byte[] getBytes(long data) {
        return getBytes(data, default_order);
    }

    public static byte[] getBytes(float data) {
        return getBytes(data, default_order);
    }

    public static byte[] getBytes(double data) {
        return getBytes(data, default_order);
    }

    /** @section 4 get basic type object */

    /** @section 4.1 */
    /**
     * @param bytes  short data bytes.
     * @param offset The offset within the array of the first byte to be read; must
     *               be non-negative and no larger than src.length.
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

    public static char getChar(byte[] bytes, int offset, ByteOrder order) {
        ByteBuffer buf = ByteBuffer.allocate(Character.BYTES);
        buf.put(bytes, offset, Character.BYTES);
        buf.order(order);
        return buf.getChar(0);
    }

    public static int getInt(byte[] bytes, int offset, ByteOrder order) {
        ByteBuffer buf = ByteBuffer.allocate(Integer.BYTES);
        buf.put(bytes, offset, Integer.BYTES);
        buf.order(order);
        return buf.getInt(0);
    }

    public static long getLong(byte[] bytes, int offset, ByteOrder order) {
        ByteBuffer buf = ByteBuffer.allocate(Long.BYTES);
        buf.put(bytes, offset, Long.BYTES);
        buf.order(order);
        return buf.getLong(0);
    }

    public static float getFloat(byte[] bytes, int offset, ByteOrder order) {
        ByteBuffer buf = ByteBuffer.allocate(Float.BYTES);
        buf.put(bytes, offset, Float.BYTES);
        buf.order(order);
        return buf.getFloat(0);
    }

    public static double getDouble(byte[] bytes, int offset, ByteOrder order) {
        ByteBuffer buf = ByteBuffer.allocate(Double.BYTES);
        buf.put(bytes, offset, Double.BYTES);
        buf.order(order);
        return buf.getDouble(0);
    }

    /** @section 4.2 */
    /**
     * @param bytes short data bytes.
     * @param order the byte order will be converted.
     * @return short data of input bytes.
     * @brief get short from bytes data.
     */
    public static short getShort(byte[] bytes, ByteOrder order) {
        return getShort(bytes, 0, order);
    }

    public static char getChar(byte[] bytes, ByteOrder order) {
        return getChar(bytes, 0, order);
    }

    public static int getInt(byte[] bytes, ByteOrder order) {
        return getInt(bytes, 0, order);
    }

    public static long getLong(byte[] bytes, ByteOrder order) {
        return getLong(bytes, 0, order);
    }

    public static float getFloat(byte[] bytes, ByteOrder order) {
        return getFloat(bytes, 0, order);
    }

    public static double getDouble(byte[] bytes, ByteOrder order) {
        return getDouble(bytes, 0, order);
    }

    /** @section 4.3 */
    /**
     * @param bytes  short data bytes.
     * @param offset The offset within the array of the first byte to be read; must
     *               be non-negative and no larger than src.length.
     * @return short data of input bytes.
     * @brief get short from bytes data.
     */
    public static short getShort(byte[] bytes, int offset) {
        return getShort(bytes, offset, default_order);
    }

    public static char getChar(byte[] bytes, int offset) {
        return getChar(bytes, offset, default_order);
    }

    public static int getInt(byte[] bytes, int offset) {
        return getInt(bytes, offset, default_order);
    }

    public static long getLong(byte[] bytes, int offset) {
        return getLong(bytes, offset, default_order);
    }

    public static float getFloat(byte[] bytes, int offset) {
        return getFloat(bytes, offset, default_order);
    }

    public static double getDouble(byte[] bytes, int offset) {
        return getDouble(bytes, offset, default_order);
    }

    public static void main(String[] args) {
        byte[] bytes = new byte[] { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };
        System.out.printf("%#x \n", getInt(bytes, 0));
        System.out.printf("%#x \n", getInt(bytes, 4));
        System.out.printf("%#x \n", getInt(bytes, 0, ByteOrder.LITTLE_ENDIAN));
        System.out.printf("%#x \n", getInt(bytes, 4, ByteOrder.LITTLE_ENDIAN));
        System.out.printf("%#x \n", getInt(bytes, 0, ByteOrder.BIG_ENDIAN));
        System.out.printf("%#x \n", getInt(bytes, 4, ByteOrder.BIG_ENDIAN));

        bytes = getBytes((short) 0x0102);
        System.out.printf("%#x \n", getShort(bytes, 0));
        System.out.printf("%#x \n", getShort(bytes, 0, ByteOrder.LITTLE_ENDIAN));
        System.out.printf("%#x \n", getShort(bytes, 0, ByteOrder.BIG_ENDIAN));
    }
}
