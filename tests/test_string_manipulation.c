#include "../include/stringly.h"
#include "orange_juice.h"

///tests for string_concat
oj_test(takes_hello_and_world_and_returns_helloworld) {
    String* s1 = string_from("hello");
    String* s2 = string_from("world");
    String* s = string_concat(s1, s2);
    String* v = string_from("helloworld");

    oj_assert_eq_bytes(10, string_value(v), string_value(s), "");
    oj_fresh;
}

oj_test(takes_starbucks_and_empty_string_and_returns_starbucks) {
    String* s1 = string_from("starbucks");
    String* s2 = string_from("");
    String* s = string_concat(s1, s2);
        
    oj_assert_eq_bytes(9, string_value(s1), string_value(s), "");
    oj_fresh;
}

oj_test(takes_an_empty_string_and_world_and_returns_world) {
    String* s1 = string_from("");
    String* s2 = string_from("world");
    String* s = string_concat(s1, s2);

    oj_assert_eq_bytes(5, string_value(s2), string_value(s), "");
    oj_fresh;
}

oj_test(takes_hello_and_world_with_space_and_returns_hello_world_with_space) {
    String* s1 = string_from("hello ");
    String* s2 = string_from("world");
    String* s = string_concat(s1, s2);

    oj_assert_eq_bytes(11, "hello world", string_value(s), "");
    oj_fresh;
}
    
oj_prepare(tests_for_string_concatenation) {
    oj_run(takes_hello_and_world_and_returns_helloworld);
    oj_run(takes_an_empty_string_and_world_and_returns_world);
    oj_run(takes_an_empty_string_and_world_and_returns_world);
    oj_run(takes_hello_and_world_with_space_and_returns_hello_world_with_space);
    oj_report;
    oj_fresh;
}

/// tests for string_trim
oj_test(takes_helloworld_with_spaces_and_returns_helloworld_without_spaces) {
    String* s = string_from("   HelloWorld   ");
    int v = string_trim(s);

    oj_assert_eq_bytes(10, "HelloWorld", string_value(s), "");
    oj_fresh;
}

oj_test(takes_hello_world_and_returns_hello_world_without_trailing_spaces) {
    String* s = string_from("        hello   world   ");
    int v = string_trim(s);

    oj_assert_eq_bytes(13, "hello   world", string_value(s), "");
    oj_fresh;
}

oj_prepare(tests_for_string_trimming) {
    oj_run(takes_helloworld_with_spaces_and_returns_helloworld_without_spaces);
    oj_run(takes_hello_world_and_returns_hello_world_without_trailing_spaces);
    
    oj_report;
    oj_fresh;
}

oj_test(takes_helloworld_with_trailing_spaces_and_removes_spaces_from_beginning) {
    String* s = string_from("   HelloWorld  ");
    int v = string_trim_left(s);

    oj_assert_eq_bytes(12, "HelloWorld  ", string_value(s), "");
    oj_fresh;
}

oj_test(takes_hello_coffee_with_trailing_spaces_and_removes_spaces_from_beginning) {
    String* s = string_from("   hello coffee");
    int v = string_trim_left(s);

    oj_assert_eq_bytes(10, "hello coffee", string_value(s), "");
    oj_fresh;
}

oj_prepare(tests_for_string_left_trimming) {
    oj_run(takes_hello_world_and_returns_hello_world_without_trailing_spaces);
    oj_run(takes_hello_coffee_with_trailing_spaces_and_removes_spaces_from_beginning);

    oj_report;
    oj_fresh;
}

oj_test(takes_helloworld_with_trailing_spaces_and_removes_all_spaces_from_end) {
    String* s = string_from("   HelloWorld    ");
    int v = string_trim_right(s);
    
    oj_assert_eq_bytes(13, "   HelloWorld", string_value(s), "");
    oj_fresh;
}

oj_test(takes_hello_coffee_and_removes_all_the_spaces_from_end) {
    String* s = string_from("hello coffee   ");
    int v = string_trim_right(s);

    oj_assert_eq_bytes(15, "hello coffee", string_value(s), "");
    oj_fresh;
}

oj_prepare(tests_for_string_right_trimming) {
    oj_run(takes_helloworld_with_trailing_spaces_and_removes_all_spaces_from_end);
    oj_run(takes_hello_coffee_and_removes_all_the_spaces_from_end);

    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(tests_for_string_concatenation, 0);
    oj_blend(tests_for_string_trimming, 0);
    oj_blend(tests_for_string_left_trimming, 0);
    oj_blend(tests_for_string_right_trimming, 0);

    return 0;
}
