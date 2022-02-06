classdef BytesUtil < handle
    % 1. using feature('locale') to view the default coding.
    % 2. using feature('DefaultCharacterSet', 'UTF8') to set the matlab
    % support UTF-8 encoding.
    % 3. default coding is Unicode
    properties(Constant)
        LITTLE_ENDIAN = 0;
        BIG_ENDIAN = 1;
        ENDIA_JUDGE_DATA = uint32(hex2dec('20220204'));
    end
    
    properties(Constant,Hidden)
        double_len = 8;
        single_len = 4;
        int8_len = 1;
        int16_len = 2;
        int32_len = 4;
        int64_len = 8;
        uint8_len = 1;
        uint16_len = 2;
        uint32_len = 4;
        uint64_len = 8;
    end
    
    methods(Static)
        %@note : char and string is using unicode in default case.
        function data = Convert2bytes(origin,varargin)
            change_endian_flag = false;
            mencodeing = 'UTF-8';
            for i=1:nargin-2
                arg = cell2mat(varargin(i));
                if(isa(arg,'char'))
                    mencodeing = arg;
                elseif(isa(arg,'logical'))
                    change_endian_flag = arg;
                end
            end
            if(isa(origin,'uint8'))
                data = origin;
            elseif(isa(origin,'char'))
                data = unicode2native(origin,mencodeing);
            elseif(isa(origin,'string'))
                % TODO: Byte Order Mark
                data = unicode2native(char(origin),mencodeing);
            elseif(isa(origin,'single') || isa(origin,'double') ...
                    || isa(origin,'int8') || isa(origin,'int16') || isa(origin,'int32')...
                    || isa(origin,'uint16') || isa(origin,'uint16') || isa(origin,'uint32'))
                data = typecast(origin,'uint8');
            elseif(isa(origin,'logical'))
                data = uint8(origin);
            else
                error('[Error]:Not support current type:[%s]\r\n',class(origin))
            end
            
            if(change_endian_flag)
                data = swapbytes(data);
            end
        end
        
        %@note : char and string is using unicode in default case.
        function data = bytes2class(bytes,type,varargin)
            change_endian_flag = false;
            mencodeing = 'UTF-8';
            for i=1:nargin-2
                arg = cell2mat(varargin(i));
                if(isa(arg,'char'))
                    mencodeing = arg;
                elseif(isa(arg,'logical'))
                    change_endian_flag = arg;
                end
            end
            
            flag_error = false;
            if(strcmp(type,'double'))
                if(mod(length(bytes),BytesUtil.double_len) == 0)
                    data = typecast(bytes,'double');
                else
                    flag_error = true;
                end
            elseif(strcmp(type,'single'))
                if(mod(length(bytes),BytesUtil.single_len) == 0)
                    data = typecast(bytes,'single');
                else
                    flag_error = true;
                end
            elseif(strcmp(type,'uint8'))
                data = bytes;
                change_endian_flag = false;
            elseif(strcmp(type,'uint16'))
                if(mod(length(bytes),BytesUtil.uint16_len) == 0)
                    data = typecast(bytes,'uint16');
                else
                    flag_error = true;
                end
            elseif(strcmp(type,'uint32'))
                if(mod(length(bytes),BytesUtil.uint32_len) == 0)
                    data = typecast(bytes,'uint32');
                else
                    flag_error = true;
                end
            elseif(strcmp(type,'uint16'))
                if(mod(length(bytes),BytesUtil.uint16_len) == 0)
                    data = typecast(bytes,'uint16');
                else
                    flag_error = true;
                end
            elseif(strcmp(type,'int8'))
                data = typecast(bytes,'int8');
                change_endian_flag = false;
            elseif(strcmp(type,'int16'))
                if(mod(length(bytes),BytesUtil.int16_len) == 0)
                    data = typecast(bytes,'int16');
                else
                    flag_error = true;
                end
            elseif(strcmp(type,'int32'))
                if(mod(length(bytes),BytesUtil.int32_len) == 0)
                    data = typecast(bytes,'int32');
                else
                    flag_error = true;
                end
            elseif(strcmp(type,'int16'))
                if(mod(length(bytes),BytesUtil.int16_len) == 0)
                    data = typecast(bytes,'int16');
                else
                    flag_error = true;
                end
            elseif(strcmp(type,'char'))
                data = native2unicode(bytes,mencodeing);
                change_endian_flag = false;
            elseif(strcmp(type,'logical'))
                data = logical(bytes);
                change_endian_flag = false;
            elseif(strcmp(type,'string'))
                % TODO: Byte Order Mark
                data = string(native2unicode(bytes,mencodeing));
                change_endian_flag = false;
            else
                error('[Error]:Not support current type:[%s]\r\n',type);
            end
            
            if(flag_error)
                error('[Error]input bytes length must be an integer multiple of the length of a byte of %s',type);
            end
            
            if(change_endian_flag)
                data = swapbytes(data);
            end
        end
        
        %@return LITTLE_ENDIAN = 0,BIG_ENDIAN = 1
        function endian = getSelfEndian()
            ENDIA_JUDGE_BYTES = typecast(BytesUtil.ENDIA_JUDGE_DATA,'uint8');
            endian = ENDIA_JUDGE_BYTES(1) ~= uint8(04);
        end
        
        %@return LITTLE_ENDIAN = 0,BIG_ENDIAN = 1
        %the input data must be ENDIA_JUDGE_DATA come from other system.
        function endian = getEndian(data)
            if(~isa(data,'uint32'))
                error('[Error]The input type must be uint32!\n');
            end
            ENDIA_JUDGE_BYTES = typecast(data,'uint8');
            endian = ENDIA_JUDGE_BYTES(1) ~= uint8(04);
        end

        %swapbytes in cording to the input data type do byte reverse.
        end
    end
end