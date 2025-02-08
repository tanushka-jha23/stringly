#include "../headers/stringly.h"
#include "orange_juice.h"

oj_test(takes_string_and_returns_true_if_string_is_all_numeric) {
    String* s = string_from("1234");
    int v = string_is_numeric(s);
    
    string_destroy(s);

    oj_assert_eq_int(1, v);
    oj_fresh;
}

oj_test(returns_false_for_non_numeric_string) {
    String* c = string_from("1234Hello");
    int r = string_is_numeric(c);

    string_destroy(c);
    oj_assert_eq_int(0, r);
    oj_fresh;
}

oj_test(returns_false_for_string_having_all_numeric_data_with_space) {
    String* p= string_from("1?");
    int z = string_is_numeric(p);

    string_destroy(p);
    oj_assert_eq_int(0, z);
    oj_fresh;
}

oj_test(push_cstr_pushes_world_into_hello) {
    String* s = string_from("hello");
    string_push_cstr(s, "world", 5);
    oj_assert_eq_bytes(10, "helloworld", string_value(s), "some error occurred while pushing ");
    string_destroy(s);
    oj_fresh;
}

oj_test(push_cstr_pushes_in_empty_string) {
    String* s = string_new();
    string_push_cstr(s, "hello", 5);
    oj_assert_eq_bytes(5, "hello", string_value(s), "");
    string_destroy(s);
    oj_fresh;
}

oj_test(pushes_empty_string_in_an_empty_string) {
    String* s = string_from("");
    string_push_cstr(s, "", 0);
    oj_assert_eq_bytes(0, "", string_value(s), "");
    string_destroy(s);
    oj_fresh;
}

oj_prepare(tests_for_string_is_numeric) {
    oj_run(takes_string_and_returns_true_if_string_is_all_numeric);
    oj_run(returns_false_for_non_numeric_string);
    oj_run(returns_false_for_string_having_all_numeric_data_with_space);
    oj_report;
    oj_fresh;
}

oj_prepare(string_push_cstr_tests) {
    oj_run(push_cstr_pushes_world_into_hello);
    oj_run(push_cstr_pushes_in_empty_string);
    oj_run(pushes_empty_string_in_an_empty_string);
    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(string_push_cstr_tests, 0);
    oj_blend(tests_for_string_is_numeric, 0);

    return 0;
}
