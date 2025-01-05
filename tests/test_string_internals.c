#include "orange_juice.h"
#include "../include/stringly.h"

oj_test(takes_hello_and_returns_5) {
    String* s = string_from("hello");
    int v = string_length(s);
    string_destroy(s);

    oj_assert_eq_int(5, v);
    oj_fresh;
} 

oj_test(takes_starbucks_and_returns_9) {
    String* s = string_from("starbucks");
    int v = string_length(s);
    string_destroy(s);

    oj_assert_eq_int(9, v);
    oj_fresh;
} 

oj_prepare(string_length_tests) {
    oj_run(takes_hello_and_returns_5);
    oj_run(takes_starbucks_and_returns_9);
    oj_report;
    oj_fresh;
}



oj_test(returns_hello) {
    String* s = string_from("hello");

    oj_assert_eq_bytes(5, "hello", string_value(s), "");
    oj_fresh;
}

oj_test(returns_coffee) {
    String* v = string_from("coffee");

    oj_assert_eq_bytes(6, "coffee", string_value(v), "");
    oj_fresh;
}

oj_prepare(string_value_tests) {
    oj_run(returns_hello);
    oj_run(returns_coffee);
    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(string_length_tests, 0);
    oj_blend(string_value_tests, 0);


    return 0;
}

