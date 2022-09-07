#include <core/logger.h>
#include <math/smath.h>

#define expect_should_be(expected, actual)                                                              \
    if(actual != expected) {                                                                            \
        SERROR("--> Expected %lld, but got: %lld. File: %s.%d.", expected, actual, __FILE__, __LINE__); \
        return false;                                                                                   \
    }

#define expect_should_not_be(expected, actual)                                                                   \
    if(actual == expected) {                                                                                     \
        SERROR("--> Expected %d != %d, but they are equal. File: %s.%d.", expected, actual, __FILE__, __LINE__); \
        return false;                                                                                            \
    }

#define expect_float_to_be(expected, actual)                                                            \
    if(sabs(expected - actual) > 0.001f) {                                                              \
        SERROR("--> Expected %f, but got: %f. File: %s.%d.", expected, actual, __FILE__, __LINE__);     \
        return false;                                                                                   \
    }

#define expect_to_be_true(actual)                                                                           \
    if(actual != true) {                                                                                    \
        SERROR("--> Expected true, but got: false. File: %s.%d.", expected, actual, __FILE__, __LINE__);    \
        return false;                                                                                       \
    }

#define expect_to_be_false(actual)                                                                           \
    if(actual != false) {                                                                                    \
        SERROR("--> Expected false, but got: true. File: %s.%d.", expected, actual, __FILE__, __LINE__);    \
        return false;                                                                                       \
    }