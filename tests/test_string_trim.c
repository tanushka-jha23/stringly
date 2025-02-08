#include "../headers/stringly.h"
#include "orange_juice.h"

oj_test(takes_string_with_spaces_and_returns_true) {
    String* s = string_from("   ");
    oj_assert_eq_int(1, string_is_whitespace(s));
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_string_with_no_spaces_and_returns_false) {
    String* s = string_from(" hello  ");
    oj_assert_eq_int(0, string_is_whitespace(s));
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_a_string_and_make_it_empty) {
    String* s = string_from("hello");
    string_empty(s);
    oj_assert_eq_bytes(0, "", string_value(s), "");
    string_destroy(s);
    oj_fresh;
}

oj_test(returns_the_number_of_whitespaces_from_left) {
    String* s = string_from("  hello   ");
    oj_assert_eq_int(2, string_whitespace_from_left(s));
    string_destroy(s);
    oj_fresh;
}

oj_test(returns_the_number_of_whitespaces_from_right) {
    String* s = string_from("  hello   ");
    oj_assert_eq_int(3, string_whitespace_from_right(s));
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_a_string_and_make_its_substring) {
    String* s = string_from("hello world");
    string_substring(s, 1, 5);
    oj_assert_eq_bytes(4, "ello", string_value(s), "");
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_helloworld_with_spaces_and_returns_helloworld_without_spaces) {
    String* s = string_from("   HelloWorld   ");
    int v = string_trim(s);

    oj_assert_eq_bytes(10, "HelloWorld", string_value(s), "");
    oj_assert_eq_int(10, v);
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_hello_world_and_returns_hello_world_without_trailing_spaces) {
    String* s = string_from("   ");
    int v = string_trim(s);

    oj_assert_eq_bytes(0, "", string_value(s), "");
    oj_assert_eq_int(0, v);
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_an_empty_string_and_returns_zero) {
    String* s = string_from("");
    int v = string_trim(s);

    oj_assert_eq_bytes(0, "", string_value(s), "");
    oj_assert_eq_int(0, v);
    string_destroy(s);
    oj_fresh;
}

oj_test(remove_spaces) {
    String* s = string_from("   j");
    int v = string_trim(s);

    oj_assert_eq_bytes(1, "j", string_value(s), "");
    oj_assert_eq_int(1, v);
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_helloworld_with_trailing_spaces_and_removes_spaces_from_beginning) {
    String* s = string_from("   HelloWorld  ");
    int v = string_trim_left(s);

    oj_assert_eq_bytes(12, "HelloWorld  ", string_value(s), "");
    oj_assert_eq_int(12, v);
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_hello_coffee_with_trailing_spaces_and_removes_spaces_from_beginning) {
    String* s = string_from("   hello coffee");
    int v = string_trim_left(s);

    oj_assert_eq_bytes(12, "hello coffee", string_value(s), "");
    oj_assert_eq_int(12, v);
    string_destroy(s);
    oj_fresh;
}


oj_test(takes_helloworld_with_trailing_spaces_and_removes_all_spaces_from_end) {
    String* s = string_from("  HelloWorld   ");
    int v = string_trim_right(s);
    
    oj_assert_eq_bytes(12, "  HelloWorld", string_value(s), "");
    oj_assert_eq_int(12, v);
    string_destroy(s);
    oj_fresh;
}

oj_test(takes_hello_coffee_and_removes_all_the_spaces_from_end) {
    String* s = string_from("hello coffee   ");
    int v = string_trim_right(s);

    oj_assert_eq_bytes(12, "hello coffee", string_value(s), "");
    oj_assert_eq_int(12, v);
    string_destroy(s);
    oj_fresh;
}

oj_prepare(tests_for_prerequisites_of_string_trim) {
    oj_run(takes_string_with_no_spaces_and_returns_false);
    oj_run(takes_string_with_spaces_and_returns_true);
    oj_run(takes_a_string_and_make_it_empty);
    oj_run(returns_the_number_of_whitespaces_from_left);
    oj_run(returns_the_number_of_whitespaces_from_right);
    oj_run(takes_a_string_and_make_its_substring);

    oj_report;
    oj_fresh;
}

oj_prepare(tests_for_string_trimming) {
    oj_run(takes_helloworld_with_spaces_and_returns_helloworld_without_spaces);
    oj_run(takes_hello_world_and_returns_hello_world_without_trailing_spaces);
    oj_run(takes_an_empty_string_and_returns_zero);
    oj_run(remove_spaces);
    
    oj_report;
    oj_fresh;
}

oj_prepare(tests_for_string_left_trimming) {
    oj_run(takes_helloworld_with_trailing_spaces_and_removes_spaces_from_beginning);
    oj_run(takes_hello_coffee_with_trailing_spaces_and_removes_spaces_from_beginning);

    oj_report;
    oj_fresh;
}

oj_prepare(tests_for_string_right_trimming) {
    oj_run(takes_helloworld_with_trailing_spaces_and_removes_all_spaces_from_end);
    oj_run(takes_hello_coffee_and_removes_all_the_spaces_from_end);

    oj_report;
    oj_fresh;
}


int main() {
    oj_blend(tests_for_prerequisites_of_string_trim, 0);
    oj_blend(tests_for_string_trimming, 0);
    oj_blend(tests_for_string_left_trimming, 0);
    oj_blend(tests_for_string_right_trimming, 0);

    return 0;
}
