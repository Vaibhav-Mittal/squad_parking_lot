#include "ParkingTicket.h"

ParkingTicket::ParkingTicket(const std::string& vehicle_registration_number_, int age_of_driver_, int parking_slot_number_) : _vehicle_registration_number(vehicle_registration_number_), _age_of_driver(age_of_driver_), _parking_slot_number(parking_slot_number_)
{
}

int ParkingTicket::get_parking_slot_number() const
{
	return _parking_slot_number;
}
