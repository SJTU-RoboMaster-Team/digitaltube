/**
  ******************************************************************************
  * @FileName			    DigitalTubeTask.cpp
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

#include "includes.h"
#include "DigitalTubeTask.h"

void DigitalTube::ShowNumber(uint8_t num) {
    numDec=num;
    serialData=0;
    serialData&=digitalTubeChar[num/100];serialData<<uint8_t (8);num-=100*(num/100);
    serialData&=digitalTubeChar[num/10];serialData<<uint8_t (8);num-=10*(num/10);
    serialData&=digitalTubeChar[num];
    StartTransmitData();
}
void DigitalTube::ResetScore() {
    numDec=0;
    serialData=0;
    StartTransmitData();
}

void DigitalTube::AddScore(uint8_t score) {
    numDec+=score;
    ShowNumber(numDec);
}

void DigitalTube::ToggleAll() {
    HAL_GPIO_TogglePin(OE.pinGroup,OE.pin);
}

void DigitalTube::StartTransmitData() {
    flagForTransmitData=1;
}

void DigitalTube::TransmitData() {//only works for 3 less tube
    if (flagForTransmitData == 0)return;


    dataBackUp=serialData;

    switch (oneBitCounter) {
        case 0:
            ChangeSI(LastBitOf());
            MoveBit();
            oneBitCounter=1;
            break;
        case 1:
            SetSCK();//rising edge move
            oneBitCounter=2;
            break;
        case 2:
            ResetSCK();
            SetRCK();
            oneBitCounter=3;
            break;
        case 3:
            ResetRCK();
            oneBitCounter=0;
            transmitCounter--;
            break;
        default:
            break;
    }

    if(transmitCounter == 0){
        flagForTransmitData=0;
        transmitCounter=24;
        //transmission finished
    }
}

uint8_t DigitalTube::LastBitOf() {

    return dataBackUp&uint8_t(1) ;
}
void DigitalTube::MoveBit() {
    dataBackUp>>uint8_t (1);
}



void DigitalTube::ChangeSI(uint8_t dataBit) {
    if (dataBit == 0){
        HAL_GPIO_WritePin(SI.pinGroup,SI.pin,GPIO_PIN_RESET);
    }
    else if(dataBit == 1){
        HAL_GPIO_WritePin(SI.pinGroup,SI.pin,GPIO_PIN_SET);
    }
}



void DigitalTube::SetRCK() {
    HAL_GPIO_WritePin(RCK.pinGroup,RCK.pin,GPIO_PIN_SET);
}

void DigitalTube::ResetRCK() {
    HAL_GPIO_WritePin(RCK.pinGroup,RCK.pin,GPIO_PIN_RESET);
}

void DigitalTube::SetSCK() {
    HAL_GPIO_WritePin(SCK.pinGroup,SCK.pin,GPIO_PIN_SET);
}

void DigitalTube::ResetSCK() {
    HAL_GPIO_WritePin(SCK.pinGroup,SCK.pin,GPIO_PIN_RESET);
}

DigitalTube DigitalTube::tube;