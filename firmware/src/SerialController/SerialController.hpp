#ifndef SERIALCONTROLLER_HPP
#define SERIALCONTROLLER_HPP

#include <IrReader/IrReader.hpp>

class SerialController
{
    private:
        unsigned long lastSerialEmission;
        IrReader * irReaderRef;
    public:
        SerialController();
        void begin(IrReader * irReader);
        void update();
        void logInfo();
};

#include <SerialController/SerialController.ipp>

#endif