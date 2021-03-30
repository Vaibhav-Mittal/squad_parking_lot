#ifndef __PARKING_SLOT__
#define __PARKING_SLOT__
#include "Vehicle.h"

class ParkingSlot
{
	std::shared_ptr<Vehicle> _vehicle;
	int _slot_number;
public:
	ParkingSlot(int slot_number_);
	void assignVehicle(const std::shared_ptr<Vehicle> &vehicle_);
	void removeVehicle();
};

#endif //__PARKING_SLOT__
