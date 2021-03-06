#ifndef __MOCHA_H
#define __MOCHA_H
#ifdef __cplusplus
extern "C" {
#endif
/**
 * int describe(const char * description, int (* testCase)(), ...);
 *
 * @param description
 * @param testCase      function => int testCase();
 * @return 0            all pass
 *         -1           at least one failed
 */
#define describe(description, ...) __describe(description, #__VA_ARGS__, __VA_ARGS__)

/**
 * void expect(expression);
 *
 * @param expression    a true/false expression
 */
#define expect(expression)                                          \
    if (!(expression)) {                                            \
        __expect_fail(#expression, __FILE__, __LINE__, __func__);   \
        return -1;                                                  \
    }

/* internal function */
int __describe(const char * description, const char * testCaseNames, int (* testCaseList)(), ...);
void __expect_fail(const char * expression, const char * file, int line, const char * func);

#ifdef __cplusplus
}
#endif

#endif
