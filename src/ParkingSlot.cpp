#include "ParkingSlot.h"

ParkingSlot::ParkingSlot(int slot_number_): _slot_number(slot_number_)
{
}

void ParkingSlot::assignVehicle(const std::shared_ptr<Vehicle> &vehicle_)
{
	_vehicle = vehicle_;
}

void ParkingSlot::removeVehicle()
{
	_vehicle = nullptr;
}
