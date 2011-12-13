function out = subsref(obj,index)

obj.checkDeleted();

if strcmp(index.type, '.')
    
    switch lower(index.subs)
        case {'porta', 'portb', 'portc', 'port1', 'port2', 'port3', 'port4'}
            out = get(obj, index.subs);
        otherwise
            customError('new', '''%s'' is not a valid port name', index.subs);
    end
    
else
    customError('new', 'Array indexing is not supported by LEGO-NXT object');
end

