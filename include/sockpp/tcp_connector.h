/**
 * @file tcp_connector.h
 *
 * Class for creating client-side TCP connections
 *
 * @author	Frank Pagliughi
 * @author	SoRo Systems, Inc.
 * @author  www.sorosys.com
 *
 * @date	December 2014
 */

// --------------------------------------------------------------------------
// This file is part of the "sockpp" C++ socket library.
//
// Copyright (c) 2014-2017 Frank Pagliughi
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from this
// software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// --------------------------------------------------------------------------


#ifndef __sockpp_tcp_connector_h
#define __sockpp_tcp_connector_h

#include "sockpp/connector.h"
#include "sockpp/inet_address.h"

namespace sockpp {

/////////////////////////////////////////////////////////////////////////////

/**
 * Class to create a client TCP connection.
 */
class tcp_connector : public connector
{
    /** The base class */
	using base = connector;

	// Non-copyable
	tcp_connector(const tcp_connector&) =delete;
	tcp_connector& operator=(const tcp_connector&) =delete;

public:
	/**
	 * Creates an unconnected connector.
	 */
	tcp_connector() {}
	/**
	 * Creates the connector and attempts to connect to the specified
	 * address.
	 * @param addr The remote server address.
	 */
	tcp_connector(const inet_address& addr) {
        connect(addr);
    }
	/**
	 * Gets the local address to which the socket is bound.
	 * @return The local address to which the socket is bound.
	 * @throw sys_error on error
	 */
	inet_address address() const {
        return inet_address(base::address());
    }
	/**
	 * Gets the address of the remote peer, if this socket is connected.
	 * @return The address of the remote peer, if this socket is connected.
	 * @throw sys_error on error
	 */
	inet_address peer_address() const {
        return inet_address(socket::peer_address());
    }
	/**
	 * Attempts to connects to the specified server.
	 * If the socket is currently connected, this will close the current
	 * connection and open the new one.
	 * @param addr The remote server address.
	 * @return @em true on success, @em false on error
	 */
	bool connect(const inet_address& addr) {
		return base::connect(addr);
	}
};

/////////////////////////////////////////////////////////////////////////////
// end namespace sockpp
};

#endif		// __sockpp_tcp_connector_h
