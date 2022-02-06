if(BytesUtil.getSelfEndian() == 0)
    disp('Little-Endian');
end

data = BytesUtil.Convert2bytes(1.1)
BytesUtil.bytes2class(data,'double')
BytesUtil.bytes2class(data,'double',true)
data = BytesUtil.Convert2bytes(single(1.1))
BytesUtil.bytes2class(data,'single')
data = BytesUtil.Convert2bytes(int32([200,1]))
BytesUtil.bytes2class(data,'int32')
data = BytesUtil.Convert2bytes(uint8([1,2,3]))
BytesUtil.bytes2class(data,'uint8')
data = BytesUtil.Convert2bytes("Hello  ¿ΩÁ£°")
BytesUtil.bytes2class(data,'string','UTF-8')