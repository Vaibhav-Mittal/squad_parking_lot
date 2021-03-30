#ifndef __VEHICLE__
#define __VEHICLE__
#include "Customer.h"
#include <memory>
#include <string>
#include "ParkingTicket.h"

class Vehicle
{
	std::shared_ptr<Customer> _driver;
	std::string _vehicle_registration_number;
	std::shared_ptr<ParkingTicket> _parking_ticket;
public:
	Vehicle(const std::shared_ptr<Customer> &driver_, const std::string& vehicle_registration_number_);
	void assignParkingTicket(const std::shared_ptr<ParkingTicket> &ticket_);
	void removeParkingTicket();
	const std::shared_ptr<Customer>& get_driver() const;
	const std::string& get_vehicle_registration_number() const;
	const std::shared_ptr<ParkingTicket>& get_parking_ticket() const;
};

#endif //__VEHICLE__
