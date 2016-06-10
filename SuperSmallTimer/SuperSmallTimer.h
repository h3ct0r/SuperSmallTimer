#ifndef SSTIMER_H
#define SSTIMER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

typedef void (*timer_callback)(void);

class SSTimer {

public:

    // constructor
    SSTimer();

    // this function must be called inside loop()
    void run();

    // call function f every d milliseconds
    void setInterval(long d, timer_callback f);

    void setTimer(long d, timer_callback f);

private:
    // deferred call constants
    const static int DEFCALL_DONTRUN = 0;       // don't call the callback function
    const static int DEFCALL_RUNONLY = 1;       // call the callback function but don't delete the timer

    // value returned by the millis() function
    // in the previous run() call
    unsigned long prev_millis;

    // pointers to the callback functions
    timer_callback callback;

    // which timers are enabled
    boolean enabled;

    // delay values
    long delay;

    // deferred function call (sort of) - N.B.: this array is only used in run()
    int toBeCalled;
};

#endif