#include "ParkingLot.h"
#include "ApplicationExceptions.h"

ParkingLot::ParkingLot() : _no_of_slots(0), _machine(nullptr){}

void ParkingLot::initParkingLot(int no_of_slots_)
{
	if (no_of_slots_ <= 0)
	{
		throw ParkingLotException("Error in creating parking lot: Number of slots should be more than 0");
	}
	_no_of_slots = no_of_slots_;
	_machine = std::make_shared<ParkingTicketVendingMachine>();

	// Create the min priority queue for the vacant slots
	for (int i = 1; i <= no_of_slots_; ++i)
	{
		_vacant_parking_slots.emplace(i);
	}
}

int ParkingLot::addVehicle(const std::shared_ptr<Vehicle>& vehicle_)
{
	// This function takes O(log n) time

	if (_no_of_slots <= 0)
	{
		throw ParkingLotException("Error in parking car: Cannot park vehicle as there are no slots in parking lot");
	}
	if (_vacant_parking_slots.empty())
	{
		throw ParkingLotException("Error in parking car: Parking Lot full");
	}

	// Get the minimum slot number vacant/available for parking and remove from the collection of vacant slots - This takes O(log n) time
	int next_available_slot_number = _vacant_parking_slots.top();
	_vacant_parking_slots.pop();

	// Create and assign parking ticket to the vehicle - This takes O(1) time
	int age = vehicle_->get_driver()->get_age();
	std::string reg_no = vehicle_->get_vehicle_registration_number();
	vehicle_->assignParkingTicket(createParkingTicket(reg_no, age, next_available_slot_number));

	// Add vehicle in the hash map for age: list of vehicles - This takes O(1) time
	_vehicles_for_given_age[age].push_back(vehicle_);

	// Add vehicle in the hash map for slot number: vehicle iterator - This takes O(1) time
	auto vehicle_iterator = _vehicles_for_given_age[age].end();
	--vehicle_iterator;
	_occupied_slots[next_available_slot_number] = vehicle_iterator;

	// return the slot number just occuipied
	return next_available_slot_number;
}

std::shared_ptr<Vehicle> ParkingLot::removeVehicleFromSlot(int slot_number_)
{
	// This function takes O(log n) time

	if (_no_of_slots <= 0)
	{
		throw ParkingLotException("Error in removing car from parking lot: Cannot remove vehicle from slot number " + std::to_string(slot_number_) + " as there are no slots in parking lot");
	}
	if (slot_number_ <= 0)
	{
		throw ParkingLotException("Error in removing car from parking lot: Slot number has to be greater than 0");
	}
	if (slot_number_ > _no_of_slots)
	{
		throw ParkingLotException("Error in removing car from parking lot: Slot number " + std::to_string(slot_number_) + " not available, Parking Lot has only " + std::to_string(_no_of_slots) + " slot(s)");
	}

	// obtain the vehicle iterator from the hash map for slot number: vehicle iterator - This takes O(1) time
	const auto slot_to_vehicle_iterator = _occupied_slots.find(slot_number_);

	// if the slot number does not exist in the hash map, it is already vacant
	if (slot_to_vehicle_iterator == _occupied_slots.end())
	{
		throw ParkingLotException("Error in removing car from parking lot: Slot number " + std::to_string(slot_number_) + " already vacant");
	}

	// otherwise remove it from the hash map  for age: list of vehicles - This takes O(1) time
	auto vehicle_iterator = slot_to_vehicle_iterator->second;
	std::shared_ptr<Vehicle> vehicle = *vehicle_iterator;
	const int age = vehicle->get_driver()->get_age();
	_vehicles_for_given_age[age].erase(vehicle_iterator);

	// remove it from the hash map for slot number : vehicle iterator - This takes O(1) time
	_occupied_slots.erase(slot_number_);

	// add the now vacant slot number to the min priority queue of vacant slots - This takes O(log n) time
	_vacant_parking_slots.emplace(slot_number_);

	// return the vehicle just removed from parking
	return vehicle;
}

std::list<std::shared_ptr<Vehicle>>& ParkingLot::getVehiclesFromDriverAge(int age_)
{
	// This function takes O(1) time

	if (_no_of_slots <= 0)
	{
		throw ParkingLotException("Error in searching: Cannot search for vehicles with age " + std::to_string(age_) + " as there are no slots in parking lot");
	}

	// search if the list for the given age exists in the hash map for age: list of vehicles - This takes O(1) time
	const auto vehicles_list_iterator = _vehicles_for_given_age.find(age_);
	if (vehicles_list_iterator != _vehicles_for_given_age.end())
	{
		return vehicles_list_iterator->second; // if it exists, return the list
	}
	throw ParkingLotException("Error in searching: No vehicles with driver of age " + std::to_string(age_) + " found");
}

int ParkingLot::getSlotFromVehicleRegistrationNumber(const std::string& vehicle_registration_number_)
{
	// This function takes O(n) time

	if (_no_of_slots <= 0)
	{
		throw ParkingLotException("Error in searching: Cannot search for vehicle with registration number " + vehicle_registration_number_ + " as there are no slots in parking lot");
	}

	// search for this vehicle registration number in the occupied slots hash map for slot number: vehicle iterator - This takes O(1) time
	for (const auto &slot_to_vehicle_iterator : _occupied_slots)
	{
		const int slot_number = slot_to_vehicle_iterator.first;
		const std::list<std::shared_ptr<Vehicle>>::const_iterator &vehicle = slot_to_vehicle_iterator.second;
		if ((*vehicle)->get_vehicle_registration_number() == vehicle_registration_number_)
		{
			return slot_number; // if found, return
		}
	}
	throw ParkingLotException("Error in searching: Vehicle with registration number " + vehicle_registration_number_ + " not found");
}

std::shared_ptr<ParkingTicket> ParkingLot::createParkingTicket(const std::string& vehicle_registration_number_,
	int age_of_driver_, int parking_slot_number_) const
{
	if (_no_of_slots <= 0)
	{
		throw ParkingLotException("Error in issuing parking ticket: There are no slots in parking lot");
	}
	return _machine->createParkingTicket(vehicle_registration_number_, age_of_driver_, parking_slot_number_);
}

bool ParkingLot::isFull() const
{
	return _vacant_parking_slots.empty();
}

bool ParkingLot::isEmpty() const
{
	return _vacant_parking_slots.size() == _no_of_slots;
}
