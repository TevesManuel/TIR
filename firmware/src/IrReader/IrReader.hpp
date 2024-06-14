#ifndef IRREADER_HPP
#define IRREADER_HPP

#include <DataVec.hpp>
#include <Snapshot.hpp>

class IrReader
{
    private:
        DataVec<Snapshot> recordedCode;
        static void handlePinChange();
        static IrReader* instance;
        bool codeReaded;
    public:
        IrReader();
        void begin(int irPin, int intNumOfPin);
        void resume();
        bool isDecoded();
        void update();
        DataVec<Snapshot> * getRecordedCode();
};

#include <IrReader/IrReader.ipp>

#endif