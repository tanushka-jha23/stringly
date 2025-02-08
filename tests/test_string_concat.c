#include "../headers/stringly.h"
#include "orange_juice.h"

oj_test(takes_2_strings_and_return_concatenated_string) {
    String* s1 = string_from("hello");
    String* s2 = string_from("world");
    String* s = string_concat(s1, s2);
    String* v = string_from("helloworld");

    oj_assert_eq_bytes(10, string_value(v), string_value(s), "");
    string_destroy(s);
    string_destroy(v);
    oj_fresh;
}

oj_test(takes_hello_and_an_empty_string_and_returns_hello) {
    String* s1 = string_from("hello");
    String* s2 = string_from("");
    String* s = string_concat(s1, s2);
        
    oj_assert_eq_bytes(5, "hello", string_value(s), "");
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_an_empty_string_and_world_and_returns_world) {
    String* s1 = string_from("");
    String* s2 = string_from("world");
    String* s = string_concat(s1, s2);

    oj_assert_eq_bytes(5, "world", string_value(s), "");
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_2_empty_strings_and_returns_an_empty_string) {
    String* s1 = string_from("");
    String* s2 = string_from("");
    String* s = string_concat(s1, s2);

    oj_assert_eq_bytes(0, "", string_value(s), "");
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_hello_and_world_with_space_and_returns_hello_world_with_space) {
    String* s1 = string_from("hello ");
    String* s2 = string_from("world");
    String* s = string_concat(s1, s2);

    oj_assert_eq_bytes(11, "hello world", string_value(s), "");
    string_destroy(s);
    oj_fresh;
    oj_fresh;
}

oj_test(takes_two_strings_and_concat_them_into_another_string) {
    String* s1 = string_from("hello");
    String* s2 = string_from("world");
    String* s = string_with_capacity(10);
    string_concat_from_parts(s, s1, s2);
    string_destroy(s1);
    string_destroy(s2);

    oj_assert_eq_bytes(10, "helloworld", string_value(s), "");
    string_destroy(s);
    oj_fresh;
}

oj_prepare(tests_for_string_concatenation) {
    oj_run(takes_2_strings_and_return_concatenated_string);
    oj_run(takes_hello_and_an_empty_string_and_returns_hello);
    oj_run(takes_an_empty_string_and_world_and_returns_world);
    oj_run(takes_2_empty_strings_and_returns_an_empty_string);
    oj_run(takes_hello_and_world_with_space_and_returns_hello_world_with_space);

    oj_run(takes_two_strings_and_concat_them_into_another_string);
    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(tests_for_string_concatenation, 0);

    return 0;
}

