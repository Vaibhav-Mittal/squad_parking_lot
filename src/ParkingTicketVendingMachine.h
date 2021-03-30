#ifndef __PARKING_TICKET_VENDING_MACHINE__
#define __PARKING_TICKET_VENDING_MACHINE__
#include "ParkingTicket.h"
#include <memory>

class ParkingTicketVendingMachine
{
public:
	std::shared_ptr<ParkingTicket> createParkingTicket(const std::string& vehicle_registration_number_, int age_of_driver_, int parking_slot_number_) const;
};

#endif //__PARKING_TICKET_VENDING_MACHINE__
