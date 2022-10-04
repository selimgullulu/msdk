/******************************************************************************
 * Copyright (C) 2022 Maxim Integrated Products, Inc., All rights Reserved.
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
 *
 ******************************************************************************/

/**
 * @file    mscmem.h
 * @brief   Memory routines used by the USB Mass Storage Class example.
 *          See the msc_mem_t structure in msc.h for function details.
 */

#ifndef EXAMPLES_MAX32570_USB_COMPOSITEDEVICE_MSC_HID_MSCMEM_H_
#define EXAMPLES_MAX32570_USB_COMPOSITEDEVICE_MSC_HID_MSCMEM_H_

#include <stdint.h>

#define ERASE_MEMORY_ON_INIT \
    1 /* Configuration option to clear the memory (to 0s) on initialization. */
/* Use 1 to clear or 0 to leave untouched. */

int mscmem_Init(void);
int mscmem_Start(void);
int mscmem_Stop(void);
int mscmem_Ready();
uint32_t mscmem_Size(void);
int mscmem_Read(uint32_t lba, uint8_t *buffer);
int mscmem_Write(uint32_t lba, uint8_t *buffer);

#endif // EXAMPLES_MAX32570_USB_COMPOSITEDEVICE_MSC_HID_MSCMEM_H_
