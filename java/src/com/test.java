package com;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class test {

    public static byte[] getBytes(short data)
    {
        byte[] bytes = new byte[2];
        bytes[0] = (byte) (data);
        bytes[1] = (byte) (data >> 8);
        return bytes;
    }

    public static void main(String[] args) {

        System.out.println("ss".getClass().getClass());
        Class a;
        a = "s".getClass();
        System.out.println(a);
        System.out.println(a == "s".getClass());
        System.out.println("ss" == "ss");
        String cc = "ss";
        System.out.println(cc == "ss");
        String dd = new String("ss");
        System.out.println(dd == "ss");

        byte [] bytes = getBytes((short)0x1234);
        for (byte b :
                bytes) {
            System.out.printf("%#x ",b);
        }


        bytes = new byte[]{1,2,3,4,5};
        ByteBuffer buf = ByteBuffer.allocate(Short.BYTES);
        buf.put(bytes,0,4);


        System.out.printf("%#x",buf.getShort(0));

    }
}
