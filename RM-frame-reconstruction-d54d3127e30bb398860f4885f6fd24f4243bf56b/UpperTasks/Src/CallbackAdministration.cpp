/**
  ******************************************************************************
  * @FileName			    CallbackAdministration.cpp
  * @Description            CAN & Uart & TIM callback
  * @author                 Chang Liu & Steve Young
  * @note
  ******************************************************************************
  *
  * Copyright (c) 2021 Team JiaoLong-ShanghaiJiaoTong University
  * All rights reserved.
  *
  ******************************************************************************
**/

#include "includes.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

    if (htim->Instance == htim6.Instance) {
        HAL_NVIC_DisableIRQ(TIM6_DAC_IRQn);
        static uint32_t counter1=0,counter2=0;
        counter1++;
        counter2++;
        if(1000 == counter1){
            counter1=0;


/*            DigitalTube::tube.ToggleAll();*/

            DigitalTube::tube.AddScore();
        }

        if(10 == counter2){
            counter2=0;
            HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin);
            /*static uint32_t testSerialData=0b0101010011000111;

            if ((testSerialData&uint32_t(1)) == uint32_t(0)){

                LED_RED_GPIO_Port->ODR|=LED_RED_Pin;
            }
            else if((testSerialData&uint32_t(1)) == uint32_t(1)){

                LED_RED_GPIO_Port->ODR&=(!LED_RED_Pin);

            }
            testSerialData>>uint32_t(1);*/

/*            static uint32_t testSerialData[]={1,0,1,0,1,0,1,0,1,0,1,0};
            static uint32_t sequence=0;
            sequence++;
            sequence%=12;
            if (testSerialData[sequence] == uint32_t(0)){
                //HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin,GPIO_PIN_RESET);

                LED_RED_GPIO_Port->ODR|=LED_RED_Pin;
            }
            else if(testSerialData[sequence] == uint32_t(1)){
                //HAL_GPIO_WritePin(LED_RED_GPIO_Port,LED_RED_Pin,GPIO_PIN_SET);

                (LED_RED_GPIO_Port->ODR)&=(~LED_RED_Pin);

            }*/

/*            DigitalTube::tube.TestSI();*/
/*            DigitalTube::tube.TestPin();*/
           DigitalTube::tube.TransmitData();
        }
        MainControlLoop();
        HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

    }
    if(htim->Instance == htim7.Instance) {
        Count();
        Remote::remote.Handle();


        //RemoteKeyMouseControlLoop();
    }
}

void HAL_CAN_RxCpltCallback(CAN_HandleTypeDef *hcan) {
    if (hcan == CAN::can1.GetHcan()) {
        CAN::can1.RxHandle();
	}
    else {
        CAN::can2.RxHandle();
	}
    HAL_CAN_Receive_IT(hcan, CAN_FIFO0);
}

void HAL_CAN_TxCpltCallback(CAN_HandleTypeDef *hcan) {
    if (hcan == &hcan1)
        CAN::can1.SetTxDone(1);
    if (hcan == &hcan2)
        CAN::can2.SetTxDone(1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle) {
    if (UartHandle == &RC_UART) {
        Remote::remote.UartRxCpltCallback();
    }
    if (UartHandle == &AUTOAIM_UART) {
        AutoAim::autoAim.UartRxCpltCallback();
    }
    if (UartHandle == &JUDGE_UART) {
		JudgeUartRxCpltCallback();
    }
}
