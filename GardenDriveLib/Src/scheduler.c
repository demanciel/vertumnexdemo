/**
  ******************************************************************************
  * @file    pid_regulator.c
  * @author  The Worshipers of Vertumnus, SPQR, Inc.
  * @brief   This file provides firmware functions that implement the features
  *          of the Scheduler component of the Vertumnex Demo project.
  *
  *  The Scheduler component provides ... TBD. 
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

#include "scheduler.h"

/**
 * @addtogroup Vertumnex
 * @{
 */

/** 
 * @defgroup Scheduler "Scheduler"
 * @brief Scheduler components handle the occurence of programmed events 
 * 
 * A Scheduler component acts as a timer: it allows for programming the date of occurence 
 * of an event and provides the functions needed to update its state and determine whether
 * the event occured. 
 * 
 * An instance of a Scheduler component manages one event. The event can be periodic or not. 
 * From the Scheduler component point of view, an event is defined by a date of first occurence
 * and a period. 
 * 
 * Periodic events...
 * 
 * Non periodic event have a period set to 0. Their first occurence date is their only occurence 
 * date. This date can be changed ...
 * 
 * TBC...
 */

/**
 * @brief Initializes the Scheduler component pointed to by @p handle
 * 
 * This function needs to be called when the system starts or when it is reset (that is, when the 
 * current time is set to 0). It prepares the @p handle scheduler to work from the origin of time.
 */
void VTXSCHED_Init( VTX_Scheduler_t * handle ) 
{
    handle->Next = handle->Start;
    handle->Trigered = false;
}

/**
 * @brief Updates the Scheduler component pointed to by @p handle with the date @p now
 * 
 * The next event occurence time of the @p handle scheduler is checked against the time @p now 
 * to determine whether the event deadline occured. If it is the case, the function returns true
 * and the Triggered field is set true. Otherwise, it returns false. 
 * 
 * The condition for ... event triggers if the date @p now is past the VTX_Scheduler_t::Next occurence date 
 * 
 * @param handle pointer on the scheduler component to update
 * @param now current value of the time
 * 
 * @return true if the 
 */
bool VTXSCHED_Update( VTX_Scheduler_t * handle, uint32_t now )
{
    bool retVal = false;

    /* check if the event occured, taking a possible overflow into account and also */
    if ( ( now >= handle->Next ) || 
         (
           ( handle->Next + handle->Period < handle->Next ) && 
           ( handle->Next + handle->Period > now ) 
         ) 
       ) {
        if ( handle->Period != 0 || ! handle->Trigered ) {
            /* indicate the event occured */
            handle->Trigered = true;
            handle->Next += handle->Period;

            retVal = true;
        }
    }

    return retVal;
}

/**
 * 
 */
void VTXSCHED_SetNextTiggerDate( VTX_Scheduler_t * handle, uint32_t date )
{
    handle->Next = date;

    if ( handle->Period == 0 ) handle->Trigered = false;
}

/**
  * @}
  */

/**
  * @}
  */
