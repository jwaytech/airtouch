#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "threads_platform.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize the provided mutex
 *
 * Call this function to initialize the mutex
 *
 * @param Airtouch_Mutex_t - pointer to the mutex to be initialized
 * @return Airtouch_Error_t - error code indicating result of operation
 */
Airtouch_Error_t aws_iot_thread_mutex_init(Airtouch_Mutex_t *pMutex) {

    pMutex->mutex = xSemaphoreCreateRecursiveMutex();
    return pMutex->mutex ? SUCCESS : MUTEX_INIT_ERROR;
}

/**
 * @brief Lock the provided mutex
 *
 * Call this function to lock the mutex before performing a state change
 * Blocking, thread will block until lock request fails
 *
 * @param Airtouch_Mutex_t - pointer to the mutex to be locked
 * @return Airtouch_Error_t - error code indicating result of operation
 */
Airtouch_Error_t aws_iot_thread_mutex_lock(Airtouch_Mutex_t *pMutex) {
    xSemaphoreTakeRecursive(pMutex->mutex, portMAX_DELAY);
    return SUCCESS;
}

/**
 * @brief Try to lock the provided mutex
 *
 * Call this function to attempt to lock the mutex before performing a state change
 * Non-Blocking, immediately returns with failure if lock attempt fails
 *
 * @param Airtouch_Mutex_t - pointer to the mutex to be locked
 * @return Airtouch_Error_t - error code indicating result of operation
 */
Airtouch_Error_t aws_iot_thread_mutex_trylock(Airtouch_Mutex_t *pMutex) {
    if (xSemaphoreTakeRecursive(pMutex->mutex, 0)) {
        return SUCCESS;
    } else {
        return MUTEX_LOCK_ERROR;
    }
}

/**
 * @brief Unlock the provided mutex
 *
 * Call this function to unlock the mutex before performing a state change
 *
 * @param Airtouch_Mutex_t - pointer to the mutex to be unlocked
 * @return Airtouch_Error_t - error code indicating result of operation
 */
Airtouch_Error_t aws_iot_thread_mutex_unlock(Airtouch_Mutex_t *pMutex) {
    if (xSemaphoreGiveRecursive(pMutex->mutex)) {
        return SUCCESS;
    } else {
        return MUTEX_UNLOCK_ERROR;
    }
}

/**
 * @brief Destroy the provided mutex
 *
 * Call this function to destroy the mutex
 *
 * @param Airtouch_Mutex_t - pointer to the mutex to be destroyed
 * @return Airtouch_Error_t - error code indicating result of operation
 */
Airtouch_Error_t aws_iot_thread_mutex_destroy(Airtouch_Mutex_t *pMutex) {
    vSemaphoreDelete(pMutex->mutex);
    return SUCCESS;
}

#ifdef __cplusplus
}
#endif