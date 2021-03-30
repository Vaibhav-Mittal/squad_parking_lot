#include "ParkingTicketVendingMachine.h"

std::shared_ptr<ParkingTicket> ParkingTicketVendingMachine::createParkingTicket(const std::string& vehicle_registration_number_, int age_of_driver_, int parking_slot_number_) const
{
	return std::make_shared<ParkingTicket>(vehicle_registration_number_, age_of_driver_, parking_slot_number_);
}
