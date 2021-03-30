#include "Vehicle.h"

Vehicle::Vehicle(const std::shared_ptr<Customer> &driver_, const std::string& vehicle_registration_number_) : _driver(driver_), _vehicle_registration_number(vehicle_registration_number_), _parking_ticket(nullptr)
{
}

void Vehicle::assignParkingTicket(const std::shared_ptr<ParkingTicket> &ticket_)
{
	_parking_ticket = ticket_;
}

void Vehicle::removeParkingTicket()
{
	_parking_ticket = nullptr;
}

const std::shared_ptr<Customer>& Vehicle::get_driver() const
{
	return _driver;
}

const std::string& Vehicle::get_vehicle_registration_number() const
{
	return _vehicle_registration_number;
}

const std::shared_ptr<ParkingTicket>& Vehicle::get_parking_ticket() const
{
	return _parking_ticket;
}
