#include "SuperSmallTimer.h"


// Select time function:
//static inline unsigned long elapsed() { return micros(); }
static inline unsigned long elapsed() { return millis(); }


SSTimer::SSTimer() {
    unsigned long current_millis = elapsed();
    
    enabled = false;
    callback = 0; // if the callback pointer is zero, the slot is free, i.e. doesn't "contain" any timer
    prev_millis = current_millis;
}


void SSTimer::run() {
    int i;
    unsigned long current_millis;

    // get current time
    current_millis = elapsed();
    toBeCalled = DEFCALL_DONTRUN;

    // no callback == no timer, i.e. jump over empty slots
    if (callback) {
        // is it time to process this timer ?
        // see http://arduino.cc/forum/index.php/topic,124048.msg932592.html#msg932592
        if (current_millis - prev_millis >= delay) {
            // update time
            //prev_millis[i] = current_millis;
            prev_millis += delay;

            // check if the timer callback has to be executed
            if (enabled) {
                // "run forever" timers must always be executed
                toBeCalled = DEFCALL_RUNONLY;
            }
        }
    }

    if(toBeCalled == DEFCALL_RUNONLY){
        (*callback)();
    }
}

void SSTimer::setTimer(long d, timer_callback f) {
    delay = d;
    callback = f;
    enabled = true;
    prev_millis = elapsed();
}


void SSTimer::setInterval(long d, timer_callback f) {
    setTimer(d, f);
}