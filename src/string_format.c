#include "../headers/stringly.h"

void format_int(String* s, va_list args) {
    int x = va_arg(args, int);
    int xlen = digits(x);
    char xstr[xlen];
    for(int i = 0; i < xlen; i++) {
        xstr[xlen-i-1] = (x%10)+48;
        x /= 10;
    }
    string_push_cstr(s, xstr, xlen);
}

void format_float(String* s, va_list args, int precision) {
    float x = va_arg(args, double);
    int y = (int)(x * precision);
    int ylen = digits(y)+1;
    char ystr[ylen];
    precision = digits(precision)-1;
    int i;
    for(i=0; i < ylen; i++) {
        if(i == precision) {
            ystr[ylen-i-1] = '.';
        } else{
            ystr[ylen-i-1] = (y%10)+48;
            y /= 10;
        }
    }
    string_push_cstr(s, ystr, ylen);
}

void format_char(String* s, va_list args) {
    char x = va_arg(args, int);
    char xstr[1];
    xstr[0] = x;
    string_push_cstr(s, xstr, 1);
}

void format_string(String* s, va_list args) {
    String* c = string_from(va_arg(args, char*));
    string_push_cstr(s, c->data, c->len);
    string_destroy(c);
}

int string_format(String* s, char* format, ...) {
    va_list args;
    va_start(args, format);
    
    int k = 0;
    while(k < strlen(format)) {
        int j = k;
        while(format[j] != '%' && j < strlen(format)) { j++; }
        string_push_cstr(s, format+k, j-k);

        ++j;
        if(format[j] == 'd') {
            format_int(s, args);
        }
        if(format[j] == 'f') {
            format_float(s, args, 100);
        }
        if(format[j] == 'c') {
            format_char(s, args);
        }
        if(format[j] == 's') {
            format_string(s, args);
        }

        k = j+1;
    }

    va_end(args);
    return 0;
}
