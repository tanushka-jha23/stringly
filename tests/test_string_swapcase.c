#include "../headers/stringly.h"
#include "orange_juice.h"

oj_test(string_swap_converts_the_string_by_swapping_characters) {
    String* s = string_from("hello world");
    string_swapcase(s);

    oj_assert_eq_bytes(11, "HELLO WORLD", s->data, "");
    string_destroy(s);
    oj_fresh;
}

oj_test(string_swap_will_swap_the_casing) {
    String* s = string_from("hello#GUYS");
    string_swapcase(s);

    oj_assert_eq_bytes(10, "HELLO#guys", s->data, "");
    oj_fresh;
}

oj_prepare(tests_for_string_swap) {
    oj_run(string_swap_converts_the_string_by_swapping_characters);
    oj_run(string_swap_will_swap_the_casing);
    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(tests_for_string_swap, 0);

    return 0;
}
