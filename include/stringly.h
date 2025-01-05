#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string {
    char* data;
    int len;
} String;


String* string_from(char* c);
String* string_new();
void string_destroy(String* s);
int string_length(String* s);
char* string_value(String* str);
String* string_clone(String* str);
String* string_concat(String* s1, String* s2);
