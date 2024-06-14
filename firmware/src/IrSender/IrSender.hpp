#ifndef IRSENDER_HPP
#define IRSENDER_HPP

#include <DataVec.hpp>
#include <Snapshot.hpp>

class IrSender
{
    public:
        IrSender();
        void begin(int irPin);
        void sendIrCode(DataVec<Snapshot> * data);
};

#include <IrReader/IrReader.ipp>

#endif