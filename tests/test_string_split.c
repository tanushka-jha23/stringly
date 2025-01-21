#include "../include/stringly.h"
#include "orange_juice.h"

oj_test(string_split_count_returns_the_number_of_string) {
    String* s = string_from("HelloWorld");
    int v = string_split_count(s, "o");
    
    oj_assert_eq_int(3, v);
    string_destroy(s);
    oj_fresh;
}

oj_test(split_the_string_on_the_basis_of_delimiter) {
    String* s = string_from("HelloWorld");
    int len = string_split_count(s, "o");
    StringSlice out[len];
    string_split(s, "o", out);

    oj_assert_eq_bytes(1, "rld", (out[2]).ptr, "");
    oj_assert_eq_int(4, out[0].len);
    string_destroy(s);
    oj_fresh;
}

oj_prepare(tests_for_string_split_count) {
    oj_run(string_split_count_returns_the_number_of_string);

    oj_report;
    oj_fresh;
}

oj_prepare(tests_for_string_split) {
    oj_run(split_the_string_on_the_basis_of_delimiter);

    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(tests_for_string_split_count, 0);
    oj_blend(tests_for_string_split, 0);
    
    return 0;
}

