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
  * @ingroup Scheduler
  */
#ifndef SCHEDULER_H
#define SCHEDULER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Period parameter value of a non periodic scheduled event
 */
#define VTXSCHED_APERIODIC (0)

/**
 * @brief Event scheduler structure
 * 
 * TBD
 */
typedef struct VTX_Scheduler_s {
    uint32_t Period;    /**< Event period */
    uint32_t Next;      /**< Next event date */
    uint32_t Start;     /**< First event date from startup */
    bool Trigered;      /**< Set to true if the event triggered. false otherwise */
} VTX_Scheduler_t;

// Initializes a scheduler component
void VTXSCHED_Init( VTX_Scheduler_t * handle );

// Updates a scheduler component with the current date 
// and returns true if its event triggered since the last update
bool VTXSCHED_Update( VTX_Scheduler_t * handle, uint32_t now );

// Sets the next date when the event of a scheduler component will trigger 
void VTXSCHED_SetNextTiggerDate( VTX_Scheduler_t * handle, uint32_t date );

/**
 * @brief Acknowledges that event triggered, resets the **triggered** indicator
 * 
 * This function essentially resets the VTX_Scheduler_t::Triggered field of the 
 * @p handle Scheduler component instance to false.
 */ 
static inline void VTXSCHED_AckTriggered( VTX_Scheduler_t * handle )
{
    handle->Trigered = false;
}

/**
 * @brief Returns true if the event triggered, false otherwise
 * 
 * This function retruns the current **triggered** indicator of the @p handle  
 * Scheduler component instance.
 */

static inline bool VTXSCHED_Triggered( VTX_Scheduler_t * handle ) 
{
    return handle->Trigered;
}

#ifdef __cplusplus
}
#endif

#endif /* SCHEDULER_H */