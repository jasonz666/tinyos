// Jason 2021-05-12

// 简单粗暴填充颜色
void _strcolor(char* p_strdst, char* string, char color){
    // a byte ascii + a byte color in VESA display mode
    *p_strdst++ = *string;
    *p_strdst = color;
}

// 定位屏幕坐标 xy为横坐标纵坐标 x<80 y<24 范围x=0-79, y=0-23
char* _gotoxy(int x, int y){
    int maxw = 80 * 2;
    return (char*)(y * maxw + x * 2 + 0xb8000);
}    

int _getlineno(char* p_strdst){
    return ((int)p_strdst - 0xb8000) / 160;
}

void _strwrite(char* string){
    char* p_strdst = (char*)(0xb8000);
    while (*string){
        if (*string == '\n'){
             p_strdst = _gotoxy(0, _getlineno(p_strdst) + 1);
             *p_strdst = *++string;
        }else if (*string == 'H'){
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

void _strwritepos(int x, int y, char* string){
    char* p_strdst = _gotoxy(x, y);
    while (*string){
        *p_strdst = *string++;
        p_strdst += 2;
    }
    return;
}

void printf(char* fmt, ...){
    _strwrite(fmt);
    return;
}
