#include "../include/stringly.h"
#include "orange_juice.h"


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
}
    
oj_prepare(tests_for_string_concatenation) {
    oj_run(takes_hello_and_world_and_returns_helloworld);
    oj_run(takes_an_empty_string_and_world_and_returns_world);
    oj_run(takes_an_empty_string_and_world_and_returns_world);
    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(tests_for_string_concatenation, 0);
    return 0;
}
