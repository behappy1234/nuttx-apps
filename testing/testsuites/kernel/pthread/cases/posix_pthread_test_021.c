/****************************************************************************
 * Included Files
 ****************************************************************************/
#include <nuttx/config.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdint.h>

#include "PthreadTest.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: TestNuttxPthreadTest21
 ****************************************************************************/

void TestNuttxPthreadTest21(FAR void **state)
{
    UINT32 ret;
    int oldstate;
    int oldstype;

    ret = pthread_setcancelstate(2, &oldstate); // 2, test for invalid param.
    syslog(LOG_INFO,"ret: %d \n", ret);
    assert_int_equal(ret, EINVAL);

    ret = pthread_setcancelstate(3, &oldstate); // 3, test for invalid param.
    syslog(LOG_INFO,"ret: %d \n", ret);
    assert_int_equal(ret, EINVAL);

    ret = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    syslog(LOG_INFO,"ret: %d \n", ret);
    assert_int_equal(ret, 0);

    ret = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &oldstate);
    syslog(LOG_INFO,"ret: %d \n", ret);
    assert_int_equal(ret, 0);
    syslog(LOG_INFO,"oldstate: %d \n", oldstate);
    assert_int_equal(oldstate, PTHREAD_CANCEL_ENABLE);

    ret = pthread_setcanceltype(2, &oldstype); // 2, test for invalid param.
    syslog(LOG_INFO,"ret: %d \n", ret);
    assert_int_equal(ret, EINVAL);

    ret = pthread_setcanceltype(3, &oldstype); // 3, test for invalid param.
    syslog(LOG_INFO,"ret: %d \n", ret);
    assert_int_equal(ret, EINVAL);

    ret = pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    syslog(LOG_INFO,"ret: %d \n", ret);
    assert_int_equal(ret, 0);

    #ifdef CONFIG_CANCELLATION_POINTS
        ret = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &oldstate);
        syslog(LOG_INFO,"ret: %d \n", ret);
        syslog(LOG_INFO,"oldstate: %d \n", oldstate);
        assert_int_equal(ret, 0);
        assert_int_equal(oldstate, PTHREAD_CANCEL_ASYNCHRONOUS);
    #endif
}
