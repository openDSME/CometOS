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

#include "gtest/gtest.h"
#include "6lowpan/gmockTest_unittest.h"
#include "6lowpan/LowpanBuffer_unittest.h"
#include "6lowpan/IPHCCompressor_unittest.h"
#include "6lowpan/IPHCDecompressor_unittest.h"
#include "6lowpan/CompressingAndDecompressing_unittest.h"
#include "6lowpan/AssemblyBuffer_unittest.h"
#include "6lowpan/QueueFrame_unittest.h"
#include "6lowpan/FifoLowpanQueue_unittest.h"
#include "6lowpan/DatagramOrderedLowpanQueue_unittest.h"
//#include "6lowpan/RetransmissionList_unittest.h"
//#include "6lowpan/LFFRPacket_unittest.h"
//#include "6lowpan/LFFRSpecification_unittest.h"
//#include "6lowpan/LFFRFrame_unittest.h"
//#include "6lowpan/DirectBuffer_unittest.h"

#include "addressing/Addressing_unittest.h"
#include "ipHeaders/IPv6Datagram_unittest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
