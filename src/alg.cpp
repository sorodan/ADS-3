// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxval = 1;
    while (num != 1) {
        if (num % 2 != 0) {
            num = (3 * num + 1);
            if (num > maxval) {
                maxval = num;
            }
        } else {
            num = num / 2;
            if (num > maxval) {
                maxval = num;
            }
        }
    }
    return maxval;
}

unsigned int collatzLen(uint64_t num) {
    uint64_t len = 1;
    while (num != 1) {
        if (num % 2 != 0) {
            num = (3 * num + 1);
            len++;
        } else {
            num = num / 2;
            len++;
        }
    }
    return len;
}

unsigned int seqCollatz(unsigned int* maxlen,
    uint64_t lbound,
    uint64_t rbound) {
    *maxlen = 1;
    unsigned int num = 1;
    for (uint64_t i = lbound; i <= rbound; i++) {
        if (*maxlen < collatzLen(i)) {
            *maxlen = collatzLen(i);
            num = i;
        }
    }
    return num;
}
