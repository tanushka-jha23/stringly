#include "orange_juice.h"
#include "../headers/stringly.h"

oj_test(formats_integer_into_string) {
    String* s = string_new();
    string_format(s, "%d hello, %d", 7, 42);
    oj_assert_eq_bytes(11, "7 hello, 42", string_value(s), "didn't format correctly");
    string_destroy(s);
    oj_fresh;
}

oj_test(formats_float_into_string) {
    String* s = string_new();
    string_format(s, "%f for Rs %f", 2.53, 50.60);
    oj_assert_eq_bytes(17, "2.53 for Rs 50.60", string_value(s), "didn't format correctly");
    string_destroy(s);
    oj_fresh;
}

oj_test(formats_float_value) {
    String* s = string_new();
    string_format(s, "%f %f", 2.075, 00057.5);
    oj_assert_eq_bytes(10, "2.07 57.50", string_value(s), "didn't format correctly");
    string_destroy(s);
    oj_fresh;
}

oj_test(formats_char_into_string) {
    String* s = string_new();
    string_format(s, "%c", 'z');
    oj_assert_eq_bytes(1, "z", string_value(s), "didn't format correctly");
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_two_char_and_formats_into_string) {
    String* s = string_new();
    string_format(s, "%c and %c are good friends", 'A', 'B'); 
    oj_assert_eq_bytes(24, "A and B are good friends", string_value(s), "didn't format correctly");
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_string_and_format_it_into_another_string) {
    String* s = string_new();
    string_format(s, "hello %s", "world");
    oj_assert_eq_bytes(11, "hello world", string_value(s), "didn't format correctly");
    string_destroy(s);
    oj_fresh;
}

oj_test(formats_string) {
    String* s = string_new();
    string_format(s, "%s, %s", "Boyd", "sheriff");
    oj_assert_eq_bytes(13, "Boyd, sheriff", string_value(s), "");
    string_destroy(s);
    oj_fresh;
}

oj_prepare(string_format_tests) {
    oj_run(formats_integer_into_string);
    oj_run(formats_float_into_string);
    oj_run(formats_float_value);
    oj_run(formats_char_into_string);
    oj_run(takes_two_char_and_formats_into_string);
    oj_run(takes_string_and_format_it_into_another_string);
    oj_run(formats_string);
    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(string_format_tests, 0);
    return 0;
}
