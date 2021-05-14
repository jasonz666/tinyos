// Jason 2021-05-12
void _strcolor(char* p_strdst, char* string, char color){
    // a byte ascii + a byte color in VESA display mode
    *p_strdst++ = *string;
    *p_strdst = color;
}

void _strwrite(char* string){
    char* p_strdst = (char*)(0xb8000);
    while (*string){
        if (*string == 'H'){
            _strcolor(p_strdst, string, (char)0x92);
        }else if (*string == 'l'){
            _strcolor(p_strdst, string, (char)0x8c);
        }else if (*string == 'O'){
            _strcolor(p_strdst, string, (char)0x85);
        }else if (*string == 'S'){
            _strcolor(p_strdst, string, (char)0x8d);
        }else{
            *p_strdst = *string;
        }
        string++;
        p_strdst += 2;
    }
    return;
}

void printf(char* fmt, ...){
    _strwrite(fmt);
    return;
}
