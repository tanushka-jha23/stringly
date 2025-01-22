#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include "miniutils.h"

typedef struct string {
    char* data;
    int len;
} String;

typedef struct stringslice {
    const char* ptr;
    int len;
}StringSlice;

int str_len(char* c);
String* string_from(char* c);
String* string_new();
String* string_with_capacity(int capacity);
void string_destroy(String* s);
int string_length(String* s);
char* string_value(String* str);

String* string_concat(String* s1, String* s2);
void string_concat_from_parts(String* s, String* s1, String* s2);


int string_trim(String* s);
int string_trim_left(String* s);
int string_trim_right(String* s);

int string_is_whitespace(String* s);
void string_empty(String* s);
int string_whitespace_from_left(String* s);
int string_whitespace_from_right(String* s);
void string_substring(String* s, int a, int b);


int string_format(String* s, char* format, ...);
void string_push_cstr(String* s, char* str, int strlen);
void string_print(char* c, int n);
StringSlice string_slice(String* s, int start, int stop);
int string_split_count(String* s, char* c);
void string_split(String* s, char* delimiter, StringSlice* out);
void string_join(String* s, char** c, int len, char* v);
void string_swapcase(String* s);
int string_is_numeric(String* s);


int char_is_uppercase(char c);
char char_lowercase(char c);
int char_is_lowercase(char c);
char char_uppercase(char c);

/// macro for string_format
/// example: sprintf(string->data, "%s is %d years old", name, age)
