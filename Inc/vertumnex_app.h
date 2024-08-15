/**
 * @file    vertumnex_app.h
 * @author  The Worshipers of Vertumnus, SPQR, Inc.
 * @brief   Declares the functions needed to initialize a Vertumnex Application
 * 
 *  A Vertumnex application requires many a sensor to operate. It also needs a way to
 * act and one to report. Above all, it needs a servive to configure and start that all.
 * 
 *  The functions declared here serve that purpose.
 *
 * @copyright (c) Copyright 2024 The Worshipers of Vertumnus, SPQR, Inc.
 */

#ifndef __VERTUMNEX_APP
#define __VERTUMNEX_APP


extern void VTX_Init( void );
extern void VTX_Exec( void );

#endif /* __VERTUMNEX_APP */