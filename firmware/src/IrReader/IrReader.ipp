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
    if( instance && !instance->isDecoded() )
    {
        unsigned long last_read = instance->recordedCode.lastItem()->atTime;
        if(instance->recordedCode.lastItem() == nullptr)
        {
            last_read = 0;
        }
        unsigned long durationPulse = now - last_read;
        Serial.println(instance->recordedCode.lastItem() == nullptr);
        Serial.println(now);
        Serial.println(last_read);
        Serial.println(durationPulse);
        // Serial.println(now - instance->recordedCode.lastItem()->atTime);
        // Serial.println(durationPulse);
        if( durationPulse >= 200 && durationPulse <= 3000 )
        {
            instance->recordedCode.add(Snapshot(durationPulse, now));
        }
    }
}

void IrReader::update()
{
    // if( (micros() - this->recordedCode.lastItem()->atTime) > 100000 && this->recordedCode.length > 1 && !this->codeReaded)
    // {
    //     Serial.print("Last lecture: ");
    //     Serial.println(micros() - this->recordedCode.lastItem()->atTime);
    //     Serial.println( (micros() - this->recordedCode.lastItem()->atTime) > 3000 );
    //     Serial.println(micros());
    //     Serial.println(this->recordedCode.lastItem()->atTime);
    //     this->codeReaded = true;
    // }
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