**字节序分为哪几类？**

- 大端字节序：

   高位字节数据存放在低地址处，低位数据存放在高地址处；

- 小段字节序：

   高位字节数据存放在高地址处，低位数据存放在低地址处；

 常见

**常见网络字节序:**

**大端序：**PowerPC、IBM、Sun、KEIL C51， TCP/IP协议传输数据

**小端序：**STM32（ARM既可以工作在大端模式，也可以工作在小端模式），x86系列CPU，DEC，DSP，一般操作系统都是小端
