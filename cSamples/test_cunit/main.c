#include <stdio.h>
#include <assert.h>
#include <Basic.h>

static int my_max(int a, int b)
{
    return (a > b) ? a : b;
}

static int my_min(int a, int b)
{
    return (a < b) ? a : b;
}

static int test_tearup(void)
{
    return 0;
}

static int test_teardown(void)
{
    return 0;
}

static void test_my_max(void)
{
    int r = my_max(10, 6);

    CU_ASSERT_EQUAL(r, 10);
}

static void test_my_min(void)
{
    int r = my_min(10, 6);

    CU_ASSERT_EQUAL(r, 6);
}

static CU_TestInfo tests_success[] = {
  { "test_my_max", test_my_max},
  { "test_my_min", test_my_min},
  CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
  { "suite_success_both",  test_tearup, test_teardown, tests_success},
	CU_SUITE_INFO_NULL,
};

#define E_REGFAIL 2

int do_tests()
{
    CU_BasicRunMode mode = CU_BRM_VERBOSE;
    CU_ErrorAction error_action = CUEA_IGNORE;
    int ret  = 0;
    
    assert(NULL != CU_get_registry());
    assert(!CU_is_test_running());

    if (CU_register_suites(suites) != CUE_SUCCESS) {
        fprintf(stderr, "suite registration failed - %s\n", CU_get_error_msg());

        return E_REGFAIL;
    }

    CU_basic_set_mode(mode);
    CU_set_error_action(error_action);
    ret = CU_basic_run_tests();
    return ret;
}

int main(int argc, char **argv)
{
    int ret = 0;
    if (CU_initialize_registry()) {
        fprintf(stderr, "Initial CUint registry failure\n");
        return 1;
    }

    ret = do_tests();
    if (ret != 0) {
        printf("basic run with CUint: result: %d\n", ret);
    }
    CU_cleanup_registry();
    return ret;    
}
