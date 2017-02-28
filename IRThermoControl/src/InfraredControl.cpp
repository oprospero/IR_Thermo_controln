

#include "InfraredControl.h"



InfraredControl::InfraredControl(void) :
  irOut(IR_LED_PIN)
{

}

InfraredControl::~InfraredControl()
{

}

void InfraredControl::send_Power()
{

}

void InfraredControl::send_TempUp()
{

}

void InfraredControl::send_TempDown()
{

}

void InfraredControl::send_Oscilate()
{

}

void InfraredControl::send_Timer()
{

}

void InfraredControl::sendCommand(cmdType cmd)
{
  switch(cmd)
  {
    case cmdPower:
    irOut.sendRaw(POWER_SIGNAL, SIGNAL_LENGTH, SIGNAL_FREQ);
    break;

    case cmdTempUp:
    break;

    case cmdTempDown:
    break;

    case cmdTempMode:
    break;

    case cmdOscilate:
    break;

    case cmdTimer:
    break;

    default:
    break;
  }
}
