/**
  ******************************************************************************
  * @FileName			    DigitalTubeTask.h
  * @Description            Digital tube driver
  * @author                 Jiayue Ma
  * @note
  ******************************************************************************
  *
  * Copyright (c) 2021 Team JiaoLong-ShanghaiJiaoTong University
  * All rights reserved.
  *
  ******************************************************************************
**/

#ifndef RM_FRAME2_DIGITALTUBETASK_H
#define RM_FRAME2_DIGITALTUBETASK_H


#include "includes.h"
#include "stm32f4xx_hal_gpio.h"


const uint8_t
     Char_0=0b10001000,
     Char_1=0b11101011,
     Char_2=0b01001100,
     Char_3=0b01001001,
     Char_4=0b00101011,
     Char_5=0b00011011,
     Char_6=0b00011000,
     Char_7=0b11001011,
     Char_8=0b00001000,
     Char_9=0b00001001;

struct PinForGPIO{

    GPIO_TypeDef* pinGroup;
    uint32_t pin;
    GPIO_PinState val;
};

class DigitalTube{
public:

    static DigitalTube tube;

    void ShowNumber(uint8_t num);
    void ResetScore();
    void AddScore(uint8_t score=1);
    void ToggleAll();
    void TransmitData();//fsm in timer

private:
    PinForGPIO SI={GPIOB,10,GPIO_PIN_RESET};//receive serial data
    PinForGPIO OE={GPIOB,9,GPIO_PIN_RESET};//enable
    PinForGPIO RCK={GPIOB,3,GPIO_PIN_RESET};//refresh
    PinForGPIO SCK={GPIOA,7,GPIO_PIN_RESET};//store and move

    uint8_t digitalTubeChar[10]={Char_0,Char_1,Char_2,Char_3,Char_4,Char_5,Char_6,Char_7,Char_8,Char_9};

    uint8_t numDec=0;
    uint8_t flagForTransmitData=0;

    uint8_t transmitCounter=24;
    uint8_t oneBitCounter=0;

    uint32_t serialData=0;
    uint32_t dataBackUp=0;

    void StartTransmitData();

    void ChangeSI(uint8_t dataBit);

    uint8_t LastBitOf();
    void MoveBit();
    void SetRCK();
    void ResetRCK();
    void SetSCK();
    void ResetSCK();



};




#endif //RM_FRAME2_DIGITALTUBETASK_H
