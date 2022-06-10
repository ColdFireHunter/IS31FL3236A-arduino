#ifndef _IS32FL3236A_h
#define _IS32FL3236A_h

#include <Arduino.h>
#include <Wire.h>

#define IS32FL3236A_OK    0x00
#define IS32FL3236A_ERROR 0xFF
#define IS32FL3236A_IMAX    0
#define IS32FL3236A_IMAX2   1
#define IS32FL3236A_IMAX3   2
#define IS32FL3236A_IMAX4   3

class IS32FL3236A{
    public:
        explicit  IS32FL3236A(uint8_t deviceAdress, uint8_t sdb_pin, TwoWire *wire = &Wire);
        bool begin();
        void blank(bool on = 0);
        void sleep(bool on);
        bool isConnected();
        void setLedPwm(uint8_t lednum, byte brightness);
        void setLedParam(uint8_t lednum, uint8_t current, bool enabled);
        void clear();
        void update();
        void setFrequency(bool high);
        void reset();


    private:
        uint8_t _adress;
        uint8_t _sdbpin;
        uint8_t _data;
        int      _error;
        TwoWire* _wire;
        uint8_t writeReg(uint8_t reg, uint8_t value);
};

#endif
