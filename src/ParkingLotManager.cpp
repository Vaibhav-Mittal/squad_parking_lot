#include "ParkingLotManager.h"
#include "ApplicationExceptions.h"
#include <iostream>
#include "Util.h"

#define CATCH_PARKING_LOT_EXCEPTION catch (const ParkingLotException& e)\
				{\
			std::cout << e.what() << std::endl;\
				}\

#define CATCH_CUSTOMER_EXCEPTION catch (const CustomerException& e)\
								{\
			std::cout << "Error in parking car: " << e.what() << std::endl;\
								}\

Command ParkingLotManager::getCommand(const std::string& command)
{
	if (command == "Create_parking_lot")
	{
		return CREATE_PARKING_LOT;
	}
	if (command == "Park")
	{
		return PARK_VEHICLE;
	}
	if (command == "Slot_numbers_for_driver_of_age")
	{
		return RETURN_SLOTS_FOR_DRIVER_AGE;
	}
	if (command == "Slot_number_for_car_with_number")
	{
		return RETURN_SLOT_FOR_REG_NO;
	}
	if (command == "Leave")
	{
		return REMOVE_VEHICLE;
	}
	if (command == "Vehicle_registration_number_for_driver_of_age")
	{
		return RETURN_REG_NO_FOR_DRIVER_AGE;
	}
	return UNDEF;
}

void ParkingLotManager::executeCommand(ParkingLot& parking_lot, const std::vector<std::string>& input_tokens)
{
	const Command input_command = getCommand(input_tokens[0]); // get the command to be executed

	if (input_command == CREATE_PARKING_LOT) // Initialize the parking lot with the given number of slots
	{
		try
		{
			const int no_of_slots = Util::strToInt(input_tokens[1]); // number of slots
			parking_lot.initParkingLot(no_of_slots);
			std::cout << "Created parking of " << no_of_slots << " slots" << std::endl;
		} CATCH_PARKING_LOT_EXCEPTION;
	}
	else if (input_command == PARK_VEHICLE) // Add the vehicle to the parking
	{
		try
		{
			const std::string vehicle_registration_number = input_tokens[1]; // vehicle registration number
			const int driver_age = Util::strToInt(input_tokens[3]); // age of driver
			std::shared_ptr<Customer> driver = std::make_shared<Customer>(driver_age);
			const std::shared_ptr<Vehicle> vehicle = std::make_shared<Vehicle>(driver, vehicle_registration_number);
			const int slot_number = parking_lot.addVehicle(vehicle);
			std::cout << "Car with vehicle registration number \"" << vehicle_registration_number << "\" has been parked at slot number " << slot_number << std::endl;
		}
		CATCH_PARKING_LOT_EXCEPTION
		CATCH_CUSTOMER_EXCEPTION;
	}
	else if (input_command == RETURN_SLOTS_FOR_DRIVER_AGE || input_command == RETURN_REG_NO_FOR_DRIVER_AGE)
	{
		try
		{
			const int driver_age = Util::strToInt(input_tokens[1]); // age of driver
			std::list<std::shared_ptr<Vehicle>>& vehicles = parking_lot.getVehiclesFromDriverAge(driver_age);
			std::string delim;
			if (input_command == RETURN_SLOTS_FOR_DRIVER_AGE) // Print all the parking slot numbers with vehicles with driver of given age
			{
				for (const auto &vehicle : vehicles)
				{
					std::cout << delim << vehicle->get_parking_ticket()->get_parking_slot_number();
					delim = ",";
				}
			}
			else if (input_command == RETURN_REG_NO_FOR_DRIVER_AGE) // Print all the registraton numbers of vehicles with driver of given age
			{
				for (const auto &vehicle : vehicles)
				{
					std::cout << delim << vehicle->get_vehicle_registration_number();
					delim = ",";
				}
			}
			std::cout << std::endl;
		} CATCH_PARKING_LOT_EXCEPTION;
	}
	else if (input_command == RETURN_SLOT_FOR_REG_NO) // Print parking slot number with vehicle of given registraton number
	{
		try
		{
			const std::string vehicle_registration_number = input_tokens[1]; // vehicle registration number
			const int slot_number = parking_lot.getSlotFromVehicleRegistrationNumber(vehicle_registration_number);
			std::cout << slot_number << std::endl;
		} CATCH_PARKING_LOT_EXCEPTION;
	}
	else if (input_command == REMOVE_VEHICLE) // Remove the vehicle from parking
	{
		try
		{
			const int slot_number = Util::strToInt(input_tokens[1]); // parking slot number
			const std::shared_ptr<Vehicle> vehicle = parking_lot.removeVehicleFromSlot(slot_number);
			std::cout << "Slot number " << slot_number << " vacated, the car with vehicle registration number \"" << vehicle->get_vehicle_registration_number() << "\" left the space, the driver of the car was of age " << vehicle->get_driver()->get_age() << std::endl;
		} CATCH_PARKING_LOT_EXCEPTION;

	}
	else // The command is not known to the system
	{
		std::cout << "Unknown Command" << std::endl;
	}
}
