#pragma once
#include"..\repository\MainRepository.h"

class DigitalPort
{
public:
    enum AlarmOn
    {
        low,
        high
    };
    enum PortDirection
    {
        input,
        output
    };
    DigitalPort(char* uid, uint8_t pin);
    bool isEnable = true;
    PortDirection direction = output;
    /// <summary>
    /// Set low for trigger alarm on low level or high.
    /// </summary>
    AlarmOn alarmTriggerOn = low;
    bool isOnPullUp = false;
    float minCustomMisureValue = 0.00f;
    float maxCustomMisureValue = 0.00f;
    /*String customMisureValueDescription = "";*/
    char* getUid();
    uint8_t getPin();
private:
    char* _uid;
    uint8_t _pin;
};

