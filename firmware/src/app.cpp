#include <Arduino.h>
#include <IRremote.hpp>
#include <StatusLed/StatusLed.hpp>

#define IR_SENSOR 8
#define IR_LED 13
#define STATUS_LED 4

IRrecv irRecv(IR_SENSOR);
IRsend irSend(IR_LED);
StatusLed statusLed(STATUS_LED);

void setup()
{
    Serial.begin(9600);
    irRecv.enableIRIn();
    IrSender.begin(IR_LED);
}

void loop()
{
    if (irRecv.decode()) {
        uint_fast16_t  rawLength = irRecv.decodedIRData.rawDataPtr->rawlen - 1;
        uint16_t rawCodes[RAW_BUFFER_LENGTH];
        
        for (int i = 0; i < rawLength; i++)
        {
            rawCodes[i] = irRecv.decodedIRData.rawDataPtr->rawbuf[i + 1] * USECPERTICK;
        }

        uint_fast8_t recordedFrequency;

        if (rawLength > 1)
        {
            long totalTime = 0;
            int validPulses = 0;

            for (int i = 1; i < rawLength; i++)
            {
                if (rawCodes[i] > 100 && rawCodes[i] < 10000)
                {
                    totalTime += rawCodes[i];
                    validPulses++;
                }
            }

            if (validPulses > 0) {
                long averageTime = totalTime / validPulses;
                recordedFrequency = 1000000 / (averageTime * 2);
                // // Limitar la frecuencia a un rango razonable (30-60 kHz)
                // if (recordedFrequency < 30 || recordedFrequency > 60) {
                // recordedFrequency = 38; // Usar frecuencia por defecto si está fuera del rango
                // }
            }

        }

        Serial.print("Recorded IR signal: ");
        for (int i = 0; i < rawLength; i++) {
        Serial.print(rawCodes[i]);
        Serial.print(" ");
        }
        Serial.println();
        Serial.print("Estimated frequency: ");
        Serial.print(recordedFrequency);
        Serial.println(" kHz");

        IrSender.sendRaw(rawCodes, rawLength, recordedFrequency);

        irRecv.resume(); // Continuar recibiendo señales
    }
    // if (irRecv.decode())
    // {
    //     float periodo = 0;
    //     u8 rawBufLen = irRecv.decodedIRData.rawDataPtr->rawlen;
    //     for(int i = 0; i < rawBufLen; i++)
    //     {
    //         periodo += irRecv.decodedIRData.rawDataPtr->rawbuf[i];
    //     }
    //     periodo = periodo / 1000000; // to us
    //     Serial.println("");
    //     Serial.print("periodo: ");
    //     Serial.print(periodo);
    //     Serial.print(" freq: ");
    //     u16 freq = 1.0/periodo;
    //     Serial.println(freq);
    //     irRecv.printIRResultRawFormatted(&Serial);
        
    //     irRecv.resume();
    //     statusLed.setFor(StatusLedMode::OK, 1000);
    // }
    statusLed.update();
}
