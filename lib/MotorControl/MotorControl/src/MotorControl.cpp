#include "MotorControl.h"

bool MotorControl::_availableChannels[MAX_CHANNELS];

uint8_t MotorControl::allocateChannel(){

    for (int i = 0; i < MAX_CHANNELS; i++)
    {
        if (!_availableChannels[i])
        {
            _availableChannels[i] = true;
            return i;
        }   
    }

    return -1;
}

MotorControl::MotorControl(uint8_t in1, uint8_t in2){

    _pwmChannel1 = allocateChannel();
    _pwmChannel2 = allocateChannel();

    if ((_pwmChannel1 || _pwmChannel2) != -1) Serial.println("Sem canais disponíveis");
    
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);

    ledcAttachPin(in1, _pwmChannel1);
    ledcAttachPin(in2, _pwmChannel2);
   
}   

void MotorControl::pwmSettings(uint16_t freq, uint8_t bits)
{
    _bits = bits;
    _freq = freq;

    ledcSetup(_pwmChannel1, _freq, _bits);
    ledcSetup(_pwmChannel2, _freq, _bits);
}

void MotorControl::move(int16_t pwm)
{
    ledcWrite(_pwmChannel1, (pwm > 0)? pwm : 0); 
    ledcWrite(_pwmChannel2, (pwm > 0)? 0 : -pwm); 
}   







