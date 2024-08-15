/**
  ******************************************************************************
  * @file    scheduler.h
  * @author  The Worshipers of Vertumnus, SPQR, Inc.
  * @brief   This file contains all definitions and functions prototypes for the
  *          Scheduler component of the Vertumnex Demo project.
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
#ifndef SCHEDULER_H
#define SCHEDULER_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <stdbool.h>


/**
 * @brief Scheduler Manager
 */
typedef struct VTX_SchedulerManager_s {
    uint32_t Now;               /**< */
    uint32_t ManagerPeriod;     /**< */
} VTX_SchedulerManager_t;

// 
void VTXSCHMG_Update( VTX_SchedulerManager_t * handle );

#ifdef __cplusplus
}
#endif

#endif /* SCHEDULER_H */