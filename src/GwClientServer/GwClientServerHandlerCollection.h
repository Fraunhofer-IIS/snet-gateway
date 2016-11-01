/**
 * \file      GwClientServerHandlerCollection.h
 * \brief     
 * \author    Florian Evers, florian-evers@gmx.de
 * \copyright GNU Public License version 3.
 *
 * The HDLC Deamon implements the HDLC protocol to easily talk to devices connected via serial communications.
 * Copyright (C) 2016  Florian Evers, florian-evers@gmx.de
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GWCLIENT_SERVER_HANDLER_COLLECTION_H
#define GWCLIENT_SERVER_HANDLER_COLLECTION_H

#include <memory>
#include <list>
#include <boost/asio.hpp>
#include "SnetServiceMessage.h"
class GwClientServerHandler;
class Routing;
class AddressPool;

class GwClientServerHandlerCollection: public std::enable_shared_from_this<GwClientServerHandlerCollection> {
public:
    // CTOR, initializer, and resetter
    GwClientServerHandlerCollection(boost::asio::io_service& a_IOService, uint16_t a_TcpPortNbr);
    void Initialize(std::shared_ptr<Routing> a_RoutingEntity);
    void SystemShutdown();
    
    // Self-registering and -deregistering of gateway client handler objects
    void RegisterGwClientServerHandler  (std::shared_ptr<GwClientServerHandler> a_GwClientServerHandler);
    void DeregisterGwClientServerHandler(std::shared_ptr<GwClientServerHandler> a_GwClientServerHandler);

    void Send(const SnetServiceMessage& a_SnetServiceMessage);
    
private:
    // Internal helpers
    void DoAccept();

    // Members
    boost::asio::io_service& m_IOService;
    std::shared_ptr<AddressPool> m_AddressPool;
    std::list<std::shared_ptr<GwClientServerHandler>> m_GwClientServerHandlerList;
    std::shared_ptr<Routing> m_RoutingEntity;
    
    // Accept incoming TCP connections
    boost::asio::ip::tcp::tcp::acceptor m_TcpAcceptor; //!< The TCP listener
    boost::asio::ip::tcp::tcp::socket   m_TcpSocket; //!< One incoming TCP socket
};

#endif // GWCLIENT_SERVER_HANDLER_COLLECTION_H
