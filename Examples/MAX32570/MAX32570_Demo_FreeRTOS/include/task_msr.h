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

#ifndef _TASK_MSR_H_
#define _TASK_MSR_H_

/********************************* 		DEFINES		 *************************/
/* Number of tracks on magstripe */
#define MCR_NUM_TRACKS 3

/* Maximum number of bits on a 3.375 inch, 210 bpi magstripe */
#define MCR_MAX_RAW_LEN_BITS (3375 * 210 / 1000)
/* Maximum number of characters decoded from any track */
#define MCR_MAX_DEC_LEN (MCR_MAX_RAW_LEN_BITS / 5)

/* Swipe direction: Forward */
#define MCR_FORWARD 0
/* Swipe direction: Reverse */
#define MCR_REVERSE 1

/* Errors generated by decoding functions */
#define MCR_ERR_OK        0x00 /// No error
#define MCR_ERR_BAD_LEN   0x01 /// invalid length parameter
#define MCR_ERR_START_SEN 0x02 /// start sentinel was not found
#define MCR_ERR_END_SEN   0x04 /// end sentinel was not found
#define MCR_ERR_OUTLIER   0x08 /// invalid sample value
#define MCR_ERR_PARAM     0x10 /// invalid parameter
#define MCR_ERR_LRC       0x40 /// invalid LRC (LRC != 0)
#define MCR_ERR_PARITY    0x80 /// parity error

/* ADC errors */
#define ADCERR_OVERRUN    (1 << 0)
#define ADCERR_SHIFT      (1 << 1)
#define ADCERR_INCOMPLETE (1 << 2)

/* swipe termination exit code */
#define GETSWIPE_BUSY   (0x00)
#define GETSWIPE_OK     (0x01)
#define GETSWIPE_ADCERR (0x02)
#define GETSWIPE_TIMO   (0x03)

/*****************************    TYPE DEF    *********************************/
/* Structure to contain result of a track decode */
typedef struct {
    uint8_t error_code;            /**< Error code value */
    uint8_t parity_errs;           /**< Number of characters with parity errors */
    uint8_t lrc;                   /**< LRC check value. A value of '0' indicates a
                             successful LRC check. Any other value should be
                             considered a failure. */
    uint8_t direction;             /**< Swipe direction determined from decode */
    uint16_t len;                  /**< Number or decoded characters. This does not include
                             the sentinels or the LRC. */
    uint16_t speed;                /**< Approximate swipe rate, LSB = 0.1 in/sec */
    uint8_t data[MCR_MAX_DEC_LEN]; /**< The decoded data */
} mcr_decoded_track_t;

/*****************************     FUNCTIONS *********************************/
void msr_start(void);
void msr_stop(void);

#endif /* _TASK_MSR_H_ */
