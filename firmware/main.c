#include "wire-protocol.h"
#include "keyscanner.h"
#include "led-spiout.h"
#include "main.h"


static inline void setup(void) {
    keyscanner_init();
    led_init();
    twi_init();
  
}

int main(void) {
    setup();
    while(1) {
        if(keyscanner_main())
            led_update();
    }
    __builtin_unreachable();
}
