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

const uint8_t numbers[][9]={
        {1,1,1,0,1,1,1,0,1},//0
        {0,0,1,0,1,0,0,0,0},//1
        {1,1,0,0,1,1,0,1,1},//2
        {0,1,1,0,1,1,0,1,0},//3
        {0,0,1,0,1,0,1,1,0},//4
        {0,1,1,0,0,1,1,1,0},//5
        {1,1,1,0,0,1,1,1,1},//6
        {0,0,1,0,1,1,0,0,0},//7
        {1,1,1,0,1,1,1,1,1},//8
        {0,1,1,0,1,1,1,1,0},//9
        {0,0,0,0,0,0,0,0,0}
};

/*const uint8_t numbers[11][8]={
        {0,0,0,0,0,0,0,0},//0
        {0,0,0,0,0,0,0,0},//1
        {0,0,0,0,0,0,0,1},//2
        {0,0,0,0,0,0,1,1},//3
        {0,0,0,0,0,1,1,1},//4
        {0,0,0,0,1,1,1,1},//5
        {0,0,0,1,1,1,1,1},//6
        {0,0,1,1,1,1,1,1},//7
        {0,1,1,1,1,1,1,1},//8
        {1,1,1,1,1,1,1,1},//9
        {1,1,1,1,1,1,1,1}
};*/
/*const uint8_t
     Char_0=0b10001000,
     Char_1=0b11101011,
     Char_2=0b01001100,
     Char_3=0b01001001,
     Char_4=0b00101011,
     Char_5=0b00011011,
     Char_6=0b00011000,
     Char_7=0b11001011,
     Char_8=0b00001000,
     Char_9=0b00001001;*/

struct PinForGPIO{

    GPIO_TypeDef* pinGroup;
    uint32_t pin;
    GPIO_PinState val;
};

class DigitalTube{
public:

    static DigitalTube tube;

    void ShowNumber(uint32_t num);
    void AddScore(uint8_t score=1);
    void ToggleAll();
    void TransmitData();//fsm in timer
    void TransmitDataUsingDelay();//fsm in timer
    void TestPin();
    void TestSI();

private:
    PinForGPIO SI={GPIOB,GPIO_PIN_10,GPIO_PIN_RESET};//receive serial data
    PinForGPIO OE={GPIOB,GPIO_PIN_9,GPIO_PIN_RESET};//enable
    PinForGPIO RCK={GPIOB,GPIO_PIN_3,GPIO_PIN_RESET};//refresh
    PinForGPIO SCK={GPIOA,GPIO_PIN_7,GPIO_PIN_RESET};//store and move

/*    PinForGPIO SI={GPIOC,0,GPIO_PIN_RESET};//receive serial data
    PinForGPIO OE={GPIOC,1,GPIO_PIN_RESET};//enable
    PinForGPIO RCK={GPIOC,4,GPIO_PIN_RESET};//refresh
    PinForGPIO SCK={GPIOC,5,GPIO_PIN_RESET};//store and move*/

/*    PinForGPIO SI={LED5_GPIO_Port,LED5_Pin,GPIO_PIN_RESET};//receive serial data
    PinForGPIO OE={LED2_GPIO_Port,LED2_Pin,GPIO_PIN_RESET};//enable
    PinForGPIO RCK={LED3_GPIO_Port,LED3_Pin,GPIO_PIN_RESET};//refresh
    PinForGPIO SCK={LED4_GPIO_Port,LED4_Pin,GPIO_PIN_RESET};//store and move/**/

/*    PinForGPIO SI={GPIOD,12,GPIO_PIN_RESET};//receive serial data
    PinForGPIO OE={GPIOD,13,GPIO_PIN_RESET};//enable
    PinForGPIO RCK={GPIOD,14,GPIO_PIN_RESET};//refresh
    PinForGPIO SCK={GPIOD,15,GPIO_PIN_RESET};//store and move*/

    //uint8_t digitalTubeChar[10]={Char_0,Char_1,Char_2,Char_3,Char_4,Char_5,Char_6,Char_7,Char_8,Char_9};


    uint8_t flagForTransmitData=0;

    uint8_t transmitCounter=0;
    uint8_t oneBitCounter=0;

    uint32_t currentDigits=0;
    uint32_t numDec=0;

    uint8_t numFirstDigit=0,numSecondDigit=0,numThirdDigit=0;

    uint8_t serialData[24]={};
    uint32_t dataBackUp=0;

    void StartTransmitData();

    void ChangeSI(uint8_t dataBit);

/*    uint8_t LastBitOf();
    void MoveBit();*/
    void SetRCK();
    void ResetRCK();
    void SetSCK();
    void ResetSCK();



};




#endif //RM_FRAME2_DIGITALTUBETASK_H
