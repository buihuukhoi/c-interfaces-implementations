#include "assert.h"

const Except_T Assert_Failed = { "Assertion failed" };

void (assert)(int e) {  // (assert) --> function
    assert(e);  // assert --> macro
}