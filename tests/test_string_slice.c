#include "../headers/stringly.h"
#include "orange_juice.h"

oj_test(string_slice_takes_Hello_world_and_returns_a_sliced_string) {
    String* s = string_from("Hello world!");
    StringSlice c = string_slice(s, 1, 7);
    oj_assert_eq_bytes(5, "ello w", c.ptr, "");
    string_destroy(s);
    oj_fresh;
}

oj_test(slice_the_string) {
    String* s = string_from("Hey coffee!");
    StringSlice c = string_slice(s, 0, 1);
    oj_assert_eq_bytes(1, "H", c.ptr, "");
    string_destroy(s);
    oj_fresh;
}

oj_test(string_slice_returns_null_for_null_string) {
    String* s = string_from("NULL");
    StringSlice c = string_slice(s, 0, 0);
    oj_assert_eq_bytes(0, "NULL", c.ptr, "");
    string_destroy(s);
    oj_fresh;
}

oj_prepare(tests_for_string_slice) {
    oj_run(string_slice_takes_Hello_world_and_returns_a_sliced_string);
    oj_run(slice_the_string);
    oj_run(string_slice_returns_null_for_null_string);
    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(tests_for_string_slice, 0);
    
    return 0;
}
