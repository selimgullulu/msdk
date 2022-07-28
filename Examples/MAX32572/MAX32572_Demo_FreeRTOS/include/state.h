/*
*******************************************************************************
* Copyright (C) Maxim Integrated Products, Inc., All rights Reserved.
*
* This software is protected by copyright laws of the United States and
* of foreign countries. This material may also be protected by patent laws
* and technology transfer regulations of the United States and of foreign
* countries. This software is furnished under a license agreement and/or a
* nondisclosure agreement and may only be used or reproduced in accordance
* with the terms of those agreements. Dissemination of this information to
* any party or parties not specified in the license agreement and/or
* nondisclosure agreement is expressly prohibited.
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of Maxim Integrated
* Products, Inc. shall not be used except as stated in the Maxim Integrated
* Products, Inc. Branding Policy.
*
* The mere transfer of this software does not imply any licenses
* of trade secrets, proprietary technology, copyrights, patents,
* trademarks, maskwork rights, or any other form of intellectual
* property whatsoever. Maxim Integrated Products, Inc. retains all
* ownership rights.
*******************************************************************************
*/

#ifndef _STATE_H_
#define _STATE_H_

/********************************* 		INCLUDES	 *************************/
#include "MAX32xxx.h"

#include "bitmap.h"
#include "keypad.h"
#include "wrapper_tft.h"

#include <FreeRTOS.h>
#include <FreeRTOSConfig.h>
#include <task.h>
#include <queue.h>
#include <semphr.h>

/********************************* 		DEFINES		 *************************/

/********************************* 		TYPE DEF	 ************************/
typedef int (*Init_func)(void);
typedef int (*Keypad_process)(unsigned int key);
typedef int (*MSR_process)(unsigned char* msg, unsigned int msg_len);
typedef int (*NFC_process)(unsigned char* msg, unsigned int msg_len);
typedef int (*Time_Tick)(void);

typedef struct _State {
    char* name;
    Init_func init;
    Keypad_process prcss_key;
    Time_Tick tick;
    unsigned int timeout;
    MSR_process prcss_msr;
    NFC_process prcss_nfc;
} State;

/******************************   PUBLIC FUNCTIONS  **************************/
void state_init(void);
State* state_get_current(void);
int state_set_current(State* state);

// states
State* get_home_state(void);
State* get_smartcard_state(void);
State* get_msr_state(void);
State* get_keypad_state(void);
State* get_nfc_state(void);
State* get_slide_state(void);
State* get_info_state(void);
State* get_idle_state(void);

#endif // _STATE_H_
