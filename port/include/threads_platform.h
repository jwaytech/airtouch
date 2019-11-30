/*
 * Copyright 2019 Jwaytech . or its affiliates. All Rights Reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "license").
 * You may not use this file except in compliance with the Licence.
 * A copy of the license is located at
 * 
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KINK, either
 * express or implied. see the License for the specific language governing
 * premissions and limitations under the License.
 */

#include "threads_interface.h"

#ifndef __AIRTOUCH_PORT_THREADS_PLATFORM_H__
#define __AIRTOUCH_PORT_THREADS_PLATFORM_H__

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

/**
 * @brief Mutex Type
 *
 * definition of the Mutex   struct. Platform specific
 *
 */
struct _IoT_Mutex_t {
    SemaphoreHandle_t mutex;
};


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __AIRTOUCH_PORT_THREADS_PLATFORM_H__ */