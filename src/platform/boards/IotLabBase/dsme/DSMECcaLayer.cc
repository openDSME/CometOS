/*
 * CometOS --- a component-based, extensible, tiny operating system
 *             for wireless networks
 *
 * Copyright (c) 2015, Institute of Telematics, Hamburg University of Technology
 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "DSMECcaLayer.h"
#include "cometos.h"
#include "tosUtil.h"
#include "RFA1DriverLayer.h"

//tasklet_norace
static message_t *txMsg;

//tasklet_norace
static uint8_t ccaState;
enum {
    STATE_READY = 0, STATE_CCA_WAIT = 1, STATE_SEND = 2,
};

//tasklet_async event
void radioSend_ready() {
    if (ccaState == STATE_READY)
        ccaSend_ready(MAC_SUCCESS);
}

//tasklet_async command
mac_result_t cca_request() {
    mac_result_t error;

    if (ccaState == STATE_READY) {
        if ((error = radioCCA_request()) == MAC_SUCCESS) {
            ccaState = STATE_CCA_WAIT;
        }
    } else
        error = MAC_ERROR_BUSY;

    return error;
}

//tasklet_async command
mac_result_t ccaSend_send(message_t* msg) {
    mac_result_t error;

    if (ccaState == STATE_READY) {
        if (tosUtil_requiresCca(msg)) {
            txMsg = msg;
            if ((error = radioCCA_request()) == MAC_SUCCESS)
                ccaState = STATE_CCA_WAIT;
        } else if ((error = radioSend_send(msg)) == MAC_SUCCESS) {
            ccaState = STATE_SEND;
        }
    } else
        error = MAC_ERROR_BUSY;

    return error;
}

//tasklet_async event
void radioCCA_done(mac_result_t error) {
    ASSERT(ccaState == STATE_CCA_WAIT);

    ccaState = STATE_READY;
    ccaResult_ready(error);
    return;
}

//tasklet_async event
void radioSend_sendDone(message_t* msg, mac_result_t error) {
    ASSERT(ccaState == STATE_SEND);

    ccaState = STATE_READY;
    ccaSend_sendDone(msg, error);
}