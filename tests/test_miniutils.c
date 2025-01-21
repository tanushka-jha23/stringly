#include "orange_juice.h"
#include "../include/miniutils.h"

oj_test(miniutils_returns_5_for_42069) {
    oj_assert_eq_int(5, digits(42069));
    oj_fresh;
}

oj_prepare(miniutils_tests) {
    oj_run(miniutils_returns_5_for_42069);
    oj_report;
    oj_fresh;
}

int main() {
    oj_blend(miniutils_tests, 0);
    return 0;
}
