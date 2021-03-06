/* Copyright (c) 2017 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ISR_SERIAL_H
#define ISR_SERIAL_H

#include "mbed.h"

#include "QueueAllocator.h"

class ISRSerial : public SerialBase {
public:
    ISRSerial(PinName tx, size_t size);
    ~ISRSerial();

    int printf(const char *format, ...);

protected:
    QueueAllocator _alloc;
    Thread _thread;
    EventFlags _flags;
    bool _error;

    void _main();
};

#endif
