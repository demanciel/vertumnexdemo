/**
  ******************************************************************************
  * @file           main.c
  * @brief          Main program body of a Vertumnex Demo
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 The Worshipers of Vertumnus, SPQR, Inc.
  * All rights reserved.
  *
  * This software component is licensed under the  Apache License version 2.0.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

int main ( void ) 
{
    /* *************** */
    /* * System Init * */
    /* *************** */

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* Configure the system clock */
    SystemClock_Config();

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_DMA_Init();
    MX_RTC_Init();
    MX_ADC1_Init();
    MX_HRTIM1_Init();
    MX_FMAC_Init();

    /* ******************** */
    /* * Application Init * */
    /* ******************** */

    VTX_Init();

    while ( 1 )
    {
        /* ************************* */
        /* * Application main loop * */
        /* ************************* */

        VTX_Exec();
    }
}



