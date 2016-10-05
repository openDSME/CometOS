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
 * Maximum Independent Set
 * @author Bastian Weigelt
 */

#ifndef SPTALGO_H_
#define SPTALGO_H_

#include "SPTData.h"
#include "TZTCAElement.h"
#include "SPTHeader.h"
#include "DistAlgorithm.h"

#define SPT_STATE_UNKNOWN 0
#define SPT_STATE_ADDED 1
#define SPT_STATE_REMOVED 2
#define SPT_STATE_OK 3
#define SPT_STATE_CIRCLE 4

#define SPT_GUARD_NONE DIST_ALGO_GUARD_NONE
#define SPT_GUARD_ADD 1
#define SPT_GUARD_REMOVE 2
#define SPT_GUARD_ALONE 3

#define SPT_MAX_DISTANCE 60

namespace cometos {

class SPTAlgo : public DistAlgorithm {
public:
    SPTAlgo()
        {

        };

    virtual void initialize(TZTCAElement *neighborhoodList);
    virtual uint8_t evaluateGuards();
    virtual bool execute(uint8_t activeGuard);
    virtual void finally();
    virtual void setCache(DataIndication& msg);
    virtual void saveLocalState();
    virtual void revertLocalState();

    virtual void outReportString();
    virtual void outAlgoAbbrev();

    virtual void addHeader(Airframe& frame);
    virtual uint8_t getAlgoType();

    void resetTreeId();
    void resetTreeList();

    virtual SPTData* getDataPtr();
    node_t getTreeID();
    uint16_t getTreeDist();

protected:
    virtual uint8_t getIndexOf(node_t inID);

    SPTData mSPTNeighborStates[NEIGHBORLISTSIZE + STANDBYLISTSIZE];
    node_t mTreeID;
    uint16_t mTreeDist;
    uint8_t mTargetIndex;
    uint8_t mLastAction;

private:
    uint8_t mBackupTargetIndex;
    uint8_t mBackupTreeEdge;
};
}

#endif /* SPTALGO_H_ */
