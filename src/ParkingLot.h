#ifndef __PARKING_LOT__
#define __PARKING_LOT__
#include <queue>
#include <unordered_map>
#include <functional>
#include <vector>
#include <list>
#include "Vehicle.h"
#include "ParkingTicketVendingMachine.h"

class ParkingLot
{
	// Number of slots in the Parking Lot
	int _no_of_slots;

	// Machine which issues the parking ticket
	std::shared_ptr<ParkingTicketVendingMachine> _machine;

	// The collection of vacant parking slots available for parking, kept as a min priority queue
	// so that the minimum number slot available (mandatory to be considered for parking) can be obtained in O(log n) time.
	std::priority_queue<int, std::vector<int>, std::greater<int>> _vacant_parking_slots;

	// The collection of the occupied slots, kept as hash map, where key is the driver age and
	// value is a doubly linked list of the vehicles with that driver age.
	// This is to optimize the below requirements of the system to return result in O(1) time:
	// - System should be able to provide Vehicle Registration numbers of cars with drivers of given age
	// - System should be able to provide the parking slots of all cars with drivers of a given age
	std::unordered_map<int, std::list<std::shared_ptr<Vehicle>>> _vehicles_for_given_age;

	// The collection of the occupied slots, kept as hash map, where key is the slot number and
	// value is the iterator/pointer to the vehicle in the above collection.
	// This is the primary collection taking care of the occupied slots.
	// Removing a vehicle would resut in removing the entry from this hash map, so this would happen in O(1) time.
	// Also, the vehicle has to be removed from the above collection too and we have the iterator/pointer for the doubly linked list,
	// so it can be removed from the doubly linked list in the above collection in O(1) time too.
	std::unordered_map<int, std::list<std::shared_ptr<Vehicle>>::iterator> _occupied_slots;

public:
	ParkingLot();
	void initParkingLot(int no_of_slots_);
	int addVehicle(const std::shared_ptr<Vehicle>& vehicle_);
	std::shared_ptr<Vehicle> removeVehicleFromSlot(int slot_number_);
	std::list<std::shared_ptr<Vehicle>>& getVehiclesFromDriverAge(int age_);
	int getSlotFromVehicleRegistrationNumber(const std::string &vehicle_registration_number_);
	std::shared_ptr<ParkingTicket> createParkingTicket(const std::string& vehicle_registration_number_, int age_of_driver_, int parking_slot_number_) const;
	bool isFull() const;
	bool isEmpty() const;
};

#endif //__PARKING_LOT__
