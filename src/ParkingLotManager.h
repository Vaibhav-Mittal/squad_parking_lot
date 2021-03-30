#ifndef __PARKING_LOT_MANAGER__
#define __PARKING_LOT_MANAGER__
#include <string>
#include "ParkingLot.h"

enum Command
{
	UNDEF,
	CREATE_PARKING_LOT,
	PARK_VEHICLE,
	RETURN_SLOTS_FOR_DRIVER_AGE,
	RETURN_SLOT_FOR_REG_NO,
	REMOVE_VEHICLE,
	RETURN_REG_NO_FOR_DRIVER_AGE
};

class ParkingLotManager
{
public:
	Command getCommand(const std::string& command);
	void executeCommand(ParkingLot& parking_lot, const std::vector<std::string>& input_tokens);
};

#endif //__PARKING_LOT_MANAGER__
