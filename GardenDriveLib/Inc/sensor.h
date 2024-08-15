/**
  ******************************************************************************
  * @file    sensor.h
  * @author  The Worshipers of Vertumnus, SPQR, Inc.
  * @brief   This file contains all definitions and functions prototypes for the
  *          Sensor base component of the Vertumnex Demo project.
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 The Worshipers of Vertumnus, SPQR, Inc.
  * All rights reserved.
  *
  * This software component is licensed under the Apache License version 2.0.
  *
  ******************************************************************************
  *
  */

#ifndef SENSOR_H
#define SENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief 
 */
#define SENSOR_NAME_MAX_BYTES_LENGTH 25

/**
 * @brief Defines the class of a sensor.
 */
typedef struct VTX_SensorClass_s {
    uint16_t SuperClass;    ///< 
    uint16_t SubClass;      ///< 
} VTX_SensorClass_t;

/**
 * @brief Identifes an actual sensor
 * 
 * TBD
 */
typedef uint32_t VTX_SensorId_t;

/**
 * @bief Sensor management base structure
 * 
 * TBD
 */
typedef struct VTX_Sensor_s {
    VTX_SensorId_t Id;          ///< 
    VTX_SensorClass_t Class;    ///< 

    char Name[ (SENSOR_NAME_MAX_BYTES_LENGTH) + 1 ];
} VTX_Sensor_t;


#ifdef __cplusplus
}
#endif

#endif /* SENSOR_H */
