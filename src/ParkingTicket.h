#ifndef __PARKING_TICKET__
#define __PARKING_TICKET__
#include <string>

class ParkingTicket
{
	std::string _vehicle_registration_number;
	int _age_of_driver;
	int _parking_slot_number;
public:
	ParkingTicket(const std::string& vehicle_registration_number_, int age_of_driver_, int parking_slot_number_);
	int get_parking_slot_number() const;
};

#endif //__PARKING_TICKET__
