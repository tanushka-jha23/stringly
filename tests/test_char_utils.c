#include "../headers/stringly.h"
#include "orange_juice.h"

oj_test(char_is_uppercase_returns_false_if_character_is_not_alphabet) {
    char c = ',';
    oj_assert_eq_int(0, char_is_uppercase(c));
    oj_fresh;
}

oj_test(char_is_uppercase_returns_true_if_character_is_uppercase) {
    char c = 'P';
    oj_assert_eq_int(1, char_is_uppercase(c));
    oj_fresh;
}

oj_test(char_is_lowercase_returns_false_if_character_is_uppercase) {
    char c = 'G';
    oj_assert_eq_int(0, char_is_lowercase(c));
    oj_fresh;
}

oj_test(char_is_lowercase_returns_true_if_character_is_lowercase) {
    char c = 'd';
    oj_assert_eq_int(1, char_is_lowercase(c));
    oj_fresh;
}

oj_test(char_uppercase_returns_char_in_uppercase) {
    char c = 'h';
    c = char_uppercase(c);
    oj_assert_eq_int('H', c);
    oj_fresh;
}

oj_test(returns_same_if_char_already_in_uppercase) {
    char c = 'T';
    c = char_uppercase(c);
    oj_assert_eq_int('T', c);
    oj_fresh;
}

oj_test(returns_char_if_input_is_non_char) {
    char c = '#';
    c = char_uppercase(c);
    oj_assert_eq_int('#', c);
    oj_fresh;
}

oj_test(char_lowercase_returns_char_in_lowercase) {
    char c = 'P';
    c = char_lowercase(c);
    oj_assert_eq_int('p', c);
    oj_fresh;
}

oj_test(returns_same_if_char_already_in_lowercase) {
    char c = 'a';
    c = char_lowercase(c);
    oj_assert_eq_int('a', c);
    oj_fresh;
}

oj_test(returns_char_if_char_is_not_char) {
    char c = '@';
    c = char_lowercase(c);
    oj_assert_eq_int('@', c);
    oj_fresh;
}


oj_prepare(tests_for_char_utils) {
    oj_run(char_is_lowercase_returns_false_if_character_is_uppercase);
    oj_run(char_is_lowercase_returns_true_if_character_is_lowercase);
    oj_run(char_is_uppercase_returns_false_if_character_is_not_alphabet);
    oj_run(char_is_uppercase_returns_true_if_character_is_uppercase);
    oj_run(char_uppercase_returns_char_in_uppercase);
    oj_run(returns_same_if_char_already_in_uppercase);
    oj_run(char_lowercase_returns_char_in_lowercase);
    oj_run(returns_same_if_char_already_in_lowercase);
    oj_run(returns_char_if_input_is_non_char);
    oj_run(returns_char_if_char_is_not_char);

    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(tests_for_char_utils, 0);

    return 0;
}

