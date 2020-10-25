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

void DigitalTube::ShowNumber(uint32_t num) {
    numDec=num;
    numThirdDigit=num%10;
    numSecondDigit=(num%100)/10;
    numFirstDigit=num/100;
    for (int i = 0; i <8 ; ++i) {
        serialData[i]=numbers[numFirstDigit][i];
    }
    for (int j = 0; j <8 ; ++j) {
        serialData[8+j]=numbers[numSecondDigit][j];
    }
    for (int k = 0; k <9 ; ++k) {
        serialData[16+k]=numbers[numThirdDigit][k];
    }



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

    if(transmitCounter == 25){
        HAL_Delay(10);
        SetRCK();
        SetSCK();
        transmitCounter++;
        return;
        //transmission finished
    }
    if(transmitCounter == 26){
        flagForTransmitData=0;
        transmitCounter=0;
        HAL_Delay(10);
        ResetRCK();
        ResetSCK();
        return;
    }
    switch (oneBitCounter) {
        case 0:
            ChangeSI(serialData[transmitCounter]);

            oneBitCounter=1;
            break;
        case 1:
            SetSCK();//rising edge move
            oneBitCounter=2;
            break;
        case 2:
            ResetSCK();
            oneBitCounter=3;
            break;
        case 3:

            oneBitCounter=0;
            transmitCounter++;
            break;
        default:
            break;
    }

    if(transmitCounter == 24){
        ChangeSI(serialData[23]);

        transmitCounter++;

        //transmission finished
    }

}

void DigitalTube::TransmitDataUsingDelay() {//only works for 3 less tube

    for (int i = 0; i <23 ; ++i) {
        ChangeSI(serialData[i]);
        HAL_Delay(1);
        ResetSCK();
        HAL_Delay(1);
        SetSCK();
    }
    HAL_Delay(1);
    ChangeSI(serialData[23]);
    HAL_Delay(1);
    ResetRCK();
    HAL_Delay(1);
    SetRCK();



}
/*
uint8_t DigitalTube::LastBitOf() {

    return dataBackUp&0b1 ;
}
void DigitalTube::MoveBit() {
    dataBackUp>>uint8_t (1);
}
*/



void DigitalTube::ChangeSI(uint8_t dataBit) {
    if (dataBit == 0){
        HAL_GPIO_WritePin(SI.pinGroup,SI.pin,GPIO_PIN_RESET);
//        SI.pinGroup->ODR&=(~SI.pin);
    }
    else if(dataBit == 1){
        HAL_GPIO_WritePin(SI.pinGroup,SI.pin,GPIO_PIN_SET);
/*        SI.pinGroup->ODR|=SI.pin;*/
    }
}



void DigitalTube::SetRCK() {
    HAL_GPIO_WritePin(RCK.pinGroup,RCK.pin,GPIO_PIN_SET);
//    RCK.pinGroup->ODR|=RCK.pin;
}

void DigitalTube::ResetRCK() {
    HAL_GPIO_WritePin(RCK.pinGroup,RCK.pin,GPIO_PIN_RESET);
/*    RCK.pinGroup->ODR&=(~RCK.pin);*/
}

void DigitalTube::SetSCK() {
    HAL_GPIO_WritePin(SCK.pinGroup,SCK.pin,GPIO_PIN_SET);
/*    SCK.pinGroup->ODR|=SCK.pin;*/
}

void DigitalTube::ResetSCK() {
    HAL_GPIO_WritePin(SCK.pinGroup,SCK.pin,GPIO_PIN_RESET);
/*    SCK.pinGroup->ODR&=(~SCK.pin);*/
}

void DigitalTube::TestPin() {
    HAL_GPIO_TogglePin(SI.pinGroup,SI.pin);
    HAL_GPIO_TogglePin(OE.pinGroup,OE.pin);
    HAL_GPIO_TogglePin(SCK.pinGroup,SCK.pin);
    HAL_GPIO_TogglePin(RCK.pinGroup,RCK.pin);
}

void DigitalTube::TestSI() {
    static uint32_t counterForSI = 0;
    if (counterForSI == 0){
        counterForSI=1;
        ChangeSI(0);
    }
    else if(counterForSI == 1){
        counterForSI=0;
        ChangeSI(1);
    }
}

DigitalTube DigitalTube::tube;