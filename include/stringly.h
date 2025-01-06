#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct string {
    char* data;
    int len;
} String;


String* string_from(char* c);
String* string_new();
String* string_with_capacity(int capacity);
void string_destroy(String* s);
int string_length(String* s);
char* string_value(String* str);
String* string_clone(String* str);
String* string_concat(String* s1, String* s2);
int string_trim(String* s);
int string_trim_left(String* s);
int string_trim_right(String* s);


/// macro for string_format
/// example: sprintf(string->data, "%s is %d years old", name, age)
