unsigned char	swap_bits(unsigned char octet)
{
    unsigned char res;
    
    res = 0;
    if (octet & 0b00000001)
        res = res | 0b00010000;
    if (octet & 0b00000010)
        res = res | 0b00100000;
    if (octet & 0b00000100)
        res = res | 0b01000000;
    if (octet & 0b00001000)
        res = res | 0b10000000;
    if (octet & 0b00010000)
        res = res | 0b00000001;
    if (octet & 0b00100000)
        res = res | 0b00000010;
    if (octet & 0b01000000)
        res = res | 0b00000100;
    if (octet & 0b10000000)
        res = res | 0b00001000;
    return (res);
}

//unsigned char	swap_bits(unsigned char octet)
//{
//	return ((octet >> 4) | (octet << 4));
//}
