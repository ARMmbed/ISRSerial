# ISRSerial

ISRSerial is a helper class to allow printing from interrupt context. It does this by buffering from an ISR and printing it from a thread.

## Example application

Application using ISRSerial to safely print from a ticker:

```c++
#include "mbed.h"
#include "ISRSerial.h"

ISRSerial serial(USBTX, 0x1000);

uint32_t count = 0;

void ticker_handler()
{
    serial.printf("Count: %i\r\n", count++);
}

int main()
{
    Ticker t;
    t.attach(ticker_handler, 1.0);
    
    while (true) {
        wait(1);
    }
}
```
