#ifndef STATUSLED_HPP
#define STATUSLED_HPP

#include <USBAPI.h>

enum StatusLedMode
{
    READING,
    OK,
    WARNING,
};

class StatusLed {
    private:
        u16 pulseWidth;
        u16 periodWidth;
        bool isForTime;
        u16 forTime;
        unsigned long forTimeRef;
        unsigned long lastModification;
        u8 pin;
    public:
        StatusLed(u8 ledPin);
        void reset();
        void set(StatusLedMode mode);
        void setFor(StatusLedMode mode, u16 time);
        void update();
    private:
        void toogle();
};

#include <StatusLed.ipp>

#endif