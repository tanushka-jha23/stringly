#include "../include/stringly.h"
#include "orange_juice.h"

oj_test(string_join_concatenates_strings_with_characters) {
    char* list[3] = {"Hello", "World", "Guys"};
    String* s = string_new();
    string_join(s, list, 3, "#?");

    oj_assert_eq_bytes(18, "Hello#?World#?Guys", s->data, "");
    string_destroy(s);
    oj_fresh;
}

oj_test(joins_two_strings) {
    char* list[2] = {"hello", "world"};
    String* s = string_new();
    string_join(s, list, 2, "123");

    oj_assert_eq_bytes(13, "hello123world", string_value(s), "");
    string_destroy(s);
    oj_fresh;
}

oj_prepare(tests_for_string_join) {
    oj_run(string_join_concatenates_strings_with_characters);
    oj_run(joins_two_strings);
    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(tests_for_string_join, 0);
    return 0;
}
