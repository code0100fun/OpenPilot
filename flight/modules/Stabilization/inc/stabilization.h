/**
 ******************************************************************************
 * @addtogroup OpenPilotModules OpenPilot Modules
 * @{
 * @addtogroup StabilizationModule Stabilization Module
 * @brief Stabilization PID loops in an airframe type independent manner
 * @note This object updates the @ref ActuatorDesired "Actuator Desired" based on the
 * PID loops on the @ref AttitudeDesired "Attitude Desired" and @ref AttitudeState "Attitude State"
 * @{
 *
 * @file       stabilization.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @brief      Attitude stabilization module.
 *
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef STABILIZATION_H
#define STABILIZATION_H

enum { ROLL, PITCH, YAW, MAX_AXES };

int32_t StabilizationInitialize();

typedef struct stab_rate_pid{
    float Kp;
    float Ki;
    float Kd;
    float ILimit;
};

typedef struct stab_att_pid{
    float Kp;
    float Ki;
    float ILimit;
};

typedef struct stab_rpy{
    float Roll;
    float Pitch;
    float Yaw;
};

typedef struct stab_bank {
    float RollMax;
    float PitchMax;
    float YawMax;
    struct{
        float Roll;
        float Pitch;
        float Yaw;
    };
    float ManualRate;
    float iAccumulator;
    float lastErr;
    float lastDer;
};



#endif // STABILIZATION_H

/**
 * @}
 * @}
 */
