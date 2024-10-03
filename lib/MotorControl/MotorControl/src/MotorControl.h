#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Arduino.h>

class MotorControl
{
private:
    uint8_t _bits;
    uint16_t _freq;
    uint8_t _pwmChannel1;
    uint8_t _pwmChannel2;
    static const uint8_t MAX_CHANNELS = 16;
    static bool _availableChannels[MAX_CHANNELS];

    uint8_t allocateChannel();

public:
    MotorControl(uint8_t in1, uint8_t in2);

    void pwmSettings(uint16_t freq, uint8_t bits);
    
    void move(int16_t pwm);
};
#endif