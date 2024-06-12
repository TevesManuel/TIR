#include <StatusLed.hpp>
#include <Arduino.h>

#define STATUSLED_PULSETIME_PERCENT 0.50

#define STATUSLED_READING 2000
#define STATUSLED_OK 100
#define STATUSLED_WARNING 5000

StatusLed::StatusLed(u8 ledPin)
{
    this->periodWidth      = STATUSLED_READING;
    this->lastModification = 0;
    this->pin              = ledPin;
    this->update();
    pinMode(this->pin, OUTPUT);
}

void StatusLed::toogle()
{
    digitalWrite(this->pin, !digitalRead(this->pin));
    this->lastModification = millis();
}

void StatusLed::update()
{
    this->pulseWidth = this->periodWidth * STATUSLED_PULSETIME_PERCENT;
    if ( this->isForTime )
    {
        if ( this->forTimeRef + this->forTime < millis() )
        {
            this->periodWidth = STATUSLED_READING;
            this->isForTime = false;
        }
    }
    if ( digitalRead(this->pin) )
    {

        if ( this->lastModification + this->pulseWidth < millis())
        {
            this->toogle();
        }
    }
    else
    {
        if ( this->lastModification + this->periodWidth - this->pulseWidth < millis() )
        {
            this->toogle();
        }
    }
}

void StatusLed::set(StatusLedMode mode)
{
    if ( mode == StatusLedMode::READING )
    {
        this->periodWidth = STATUSLED_READING;
    }
    else if ( mode == StatusLedMode::OK )
    {
        this->periodWidth = STATUSLED_OK;
    }
    else if ( mode == StatusLedMode::WARNING )
    {
        this->periodWidth = STATUSLED_WARNING;
    }
}

void StatusLed::setFor(StatusLedMode mode, u16 time)
{
    this->set(mode);
    this->isForTime = true;
    this->forTime = time;
    this->forTimeRef = millis();
}