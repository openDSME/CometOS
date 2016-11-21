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


/**
 * @author Andreas Weigel
 */

#ifndef __TOS_UTIL_H__
#define __TOS_UTIL_H__

#include "tosMsgReplace.h"
#include "mac_interface.h"
#include "pinEventOutput.h"


enum MacType : uint8_t {
    MT_802154_TOS = 0, //~blub
    MT_ORIGINAL_TOS = 1
};


MacType tosUtil_getMacType();

bool tosUtil_cometosToMsg(const uint8_t* data, uint8_t len, node_t dst, message_t* msg);

bool tosUtil_rxMsgToCometos( uint8_t* data,
                             uint8_t & len,
                             node_t & dst,
                             node_t & src,
                             mac_networkId_t & srcNwk,
                             mac_networkId_t & dstNwk,
                             mac_phyPacketInfo_t* & rxInfo,
                             message_t* msg);

bool tosUtil_txMsgToCometos(mac_txInfo_t* & txInfo,
                            message_t* msg);

bool tosUtil_isAckFrame(message_t* msg);

bool tosUtil_isDataFrame(message_t* msg);

mac_nodeId_t tosUtil_getDestAddr(message_t* msg);

mac_nodeId_t tosUtil_getSrcAddr(message_t* msg);

mac_networkId_t tosUtil_getDstPan(message_t* msg);

bool tosUtil_isForMe(message_t* msg);

void tosUtil_createAckFrame(message_t* msg, message_t* ack);

bool tosUtil_ackRequested(message_t* msg);

bool tosUtil_requiresAckReply(message_t* msg);

bool tosUtil_wasMsgAcked(message_t* msg);

void tosUtil_setAckReceivedFlag(message_t* msg);

void tosUtil_clearAckReceivedFlag(message_t* msg);

uint16_t tosUtil_getRetryDelay(message_t* msg);

bool tosUtil_verifyAck(message_t* originalMsg, message_t* ack);

bool tosUtil_requiresCca(message_t* msg);

uint16_t tosUtil_getMinBackoff();

uint16_t tosUtil_getInitialBackoff();

uint16_t tosUtil_getCongestionBackoff();

uint16_t tosUtil_getTransmitBarrier(message_t* msg);

uint8_t uniqueConfig_getSequenceNumber(message_t* msg);

void uniqueConfig_setSequenceNumber(message_t* msg, uint8_t seq);

#endif