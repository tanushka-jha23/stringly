#include "orange_juice.h"
#include "../include/stringly.h"

oj_test(takes_hello_and_returns_5) {
    String* s = string_from("hello");
    int v = string_length(s);
    string_destroy(s);

    oj_assert_eq_int(5, v);
    oj_fresh;
} 

oj_test(returns_length_of_string) {
    String* s = string_from("monods are monoids in the category of endofunctors");
    int v = string_length(s);
    string_destroy(s);

    oj_assert_eq_int(50, v);
    oj_fresh;
} 

oj_test(returns_zero_when_string_is_null) {
    String* s = string_from(NULL);
    int v = string_length(s);
    string_destroy(s);

    oj_assert_eq_int(0, v);
    oj_fresh;
}

oj_test(returns_hello) {
    String* s = string_from("hello");

    oj_assert_eq_bytes(5, "hello", string_value(s), "");
    string_destroy(s);
    oj_fresh;
}

oj_test(returns_data_of_string) {
    String* s = string_from("hello123 56");

    oj_assert_eq_bytes(11, "hello123 56", s->data, "");
    string_destroy(s);
    oj_fresh;
}

oj_prepare(string_length_tests) {
    oj_run(takes_hello_and_returns_5);
    oj_run(returns_length_of_string);
    oj_run(returns_zero_when_string_is_null);
    oj_report;
    oj_fresh;
}

oj_prepare(string_value_tests) {
    oj_run(returns_hello);
    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(string_length_tests, 0);
    oj_blend(string_value_tests, 0);

    return 0;
}

