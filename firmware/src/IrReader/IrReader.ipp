#include <IrReader/IrReader.hpp>
#include <Arduino.h>
#include <utils/utils.hpp>

#define MAX_DURATION_PULSE 5000
#define MIN_DURATION_PULSE 200

IrReader* IrReader::instance = nullptr;

IrReader::IrReader()
{
    instance = this;
    this->codeReaded = false;
};

void IrReader::begin(int pin, int intNumOfPin)
{
    pinMode(pin, INPUT);
    attachInterrupt(intNumOfPin, this->handlePinChange, CHANGE);
}

void IrReader::handlePinChange()
{
    unsigned long now = micros();
    if( instance && !instance->isDecoded() )
    {
        if(instance->recordedCode.lastItem() == nullptr)
        {
            instance->recordedCode.add(Snapshot(0, now));
        }
        else
        {
            unsigned long last_read = instance->recordedCode.lastItem()->atTime;
            unsigned long durationPulse = now - last_read;
            if( ( durationPulse >= MIN_DURATION_PULSE && durationPulse <= MAX_DURATION_PULSE ) )
            {
                instance->recordedCode.add(Snapshot(durationPulse, now));
            }
        }
    }
}

void IrReader::update()
{
    if( TUtils::elapsed(this->recordedCode.lastItem()->atTime) > MAX_DURATION_PULSE && this->recordedCode.length > 1 && !this->codeReaded)
    {
        this->codeReaded = true;
    }
}

void IrReader::resume()
{
    this->recordedCode.clean();
    this->codeReaded = false;
}

DataVec<Snapshot> * IrReader::getRecordedCode()
{
    return &this->recordedCode;
}

bool IrReader::isDecoded()
{
    return this->codeReaded;
}