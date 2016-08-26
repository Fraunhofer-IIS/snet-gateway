/**
 * \file      PublishSubscribeService.h
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

#ifndef PUBLISH_SUBSCRIBE_SERVICE_H
#define PUBLISH_SUBSCRIBE_SERVICE_H

#include "SnetServiceMessage.h"
#include <memory>
class AddressLease;

class PublishSubscribeService {
public:
    // CTOR
    PublishSubscribeService();
    
    SnetServiceMessage ProcessRequest(const SnetServiceMessage& a_ServiceMessage, std::shared_ptr<AddressLease> a_AddressLease);
    bool IsServiceIdForMe(uint8_t a_SubscribedServiceId) const;
    
private:
    // Members
    uint8_t m_SubscribedServiceId;
};

#endif // PUBLISH_SUBSCRIBE_SERVICE_H
