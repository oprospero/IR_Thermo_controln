#ifndef INFRAREDCONTROL_H
#define INFRAREDCONTROL_H

#include <Arduino.h>
#include "HeaterSignals.h"
#include "IRremoteESP8266.h"
#include "PinDef.h"


class InfraredControl
{

  enum cmdType
  {
    cmdPower = 0,
    cmdTempUp,
    cmdTempDown,
    cmdTempMode,
    cmdOscilate,
    cmdTimer
  };

  InfraredControl(void);
  ~InfraredControl(void);

  void send_Power();
  void send_TempUp();
  void send_TempDown();
  void send_TempMode();
  void send_Oscilate();
  void send_Timer();

private:

  IRsend irOut;
  void sendCommand(cmdType cmd);

};

#endif
