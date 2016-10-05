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
 * @author Stefan Unterschütz
 */

#ifndef ENDPOINT_H_
#define ENDPOINT_H_

/*INCLUDES-------------------------------------------------------------------*/

#include <cometos.h>
#include "RemoteModule.h"
#include "DataRequest.h"
#include "DataResponse.h"
#include "DataIndication.h"


/*PROTOTYPES-----------------------------------------------------------------*/

namespace cometos {

/**
 * Base class for communication endpoints (e.g., applications). DataRequest
 * and DataIndication are used as exchange format.
 */
class Endpoint: public RemoteModule {
public:
	Endpoint(const char *name=NULL);

	/**Handler for DataIndication messages. This method should
	 * be overridden.
	 *
	 * @param msg 	valid pointer to DataIndication message (ownership is received)
	 * @param gate	pointer to input gate (= gateIndIn)
	 */
	virtual void handleIndication(DataIndication* msg);

	/**
	 * Sends DataRequest message to connected module.
	 *
	 * @param request	valid pointer to DataRequest object (ownership is passed)
	 * @param ms		sending offset in milliseconds
	 */
	void sendRequest(DataRequest* request, timeOffset_t offset = 0);

	InputGate<DataIndication> gateIndIn;

	OutputGate<DataRequest> gateReqOut;

};

} /* namespace cometos */

#endif /* ENDPOINT_H_ */
