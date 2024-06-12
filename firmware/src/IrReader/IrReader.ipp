#include <IrReader/IrReader.hpp>

IrReader* IrReader::instance = nullptr;

IrReader::IrReader()
{
    instance = this;
    this->codeReaded = false;
};

void IrReader::begin(u8 pin, u8 intNumOfPin)
{
    pinMode(pin, INPUT);
    attachInterrupt(intNumOfPin, this->handlePinChange, CHANGE);
}

void IrReader::handlePinChange()
{
    unsigned long now = micros();
    if( instance )
    {
        u16 durationPulse = now - instance->recordedCode.lastItem()->atTime;
        if( durationPulse >= 200 && durationPulse <= 3000 )
        {
            instance->recordedCode.add(Snapshot(durationPulse, now));
        }
        else
        {
            instance->codeReaded = true;
        }
    }
}

void IrReader::update()
{
    if(micros() - this->recordedCode.lastItem()->atTime > 3000 && this->recordedCode.length > 1)
        this->codeReaded = true;
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