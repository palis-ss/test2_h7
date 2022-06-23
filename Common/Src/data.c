#include <stdint.h>
#include "main.h"


#define HSEM_MUTEX	1



// this part must be included in the scatter file
uint32_t counter __attribute__((section("SHARED")));
double mydouble __attribute__((section("SHARED")));


void EnterCriticalSection()
{
	while(HAL_HSEM_IsSemTaken(HSEM_MUTEX))  // wait for lock
			;
	while(HAL_HSEM_FastTake(HSEM_MUTEX) != HAL_OK)  // acquire lock
			;
}

void LeaveCriticalSection()
{
	HAL_HSEM_Release(HSEM_MUTEX, 0);  // release lock
}

