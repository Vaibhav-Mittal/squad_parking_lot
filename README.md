# squad_parking_lot
code repository for parking lot assignment for SquadStack

How to run:

Windows:

1. Open command prompt on the bin/Windows folder
2. Run the executable with the file path as the command line argument. For example
	.\ParkingLot.exe C:\Users\Vaibhav\input.txt
	
The program considers ..\..\resource\input.txt as the default input file path, so if this is the file path, then the command line argument can be skipped. For example below
	.\ParkingLot.exe
	
Linux:

1. Open terminal on the bin/Linux folder
2. Run the executable with the file path as the command line argument. For example
	./ParkingLot.lx /home/vaibhav/input.txt
	
The program considers ../../resource/input.txt as the default input file path, so if this is the file path, then the command line argument can be skipped. For example below
	./ParkingLot.lx
	
Mac:

1. Open terminal on the bin/Mac folder
2. Run the executable with the file path as the command line argument. For example
	./ParkingLot.out /home/vaibhav/input.txt
	
The program considers ../../resource/input.txt as the default input file path, so if this is the file path, then the command line argument can be skipped. For example below
	./ParkingLot.out

How to build:

The code can be built with g++ compiler (minimum version 4.8.1) in any OS (Windows, Linux or Mac), for example with the below command in the directory with the source code:
g++ -std=c++0x -o <executable_name_path> *.cpp
For example:
g++ -std=c++0x -o a.out *.cpp

Requirements:
- There is only 1 parking lot with n slots numbered 1 to n based on distance from entry point.
- Customer/Vehicle can take parking ticket issued by system and park the car in the issued slot.
- The parking ticket should only contain the age of the driver and the Vehicle Registration number.
- The slot issued by the system should be the nearest vacant slot from the entry point.
- There is no payment for parking.
- Customer can leave the parking slot, which vacates the parking slot for new car entries.
- If the parking is full and customer tries to enter the parking, some error should be displayed.
- If some slot number is requested to be vacated and that slot is already vacant, some error should be displayed.
- System should be able to provide Vehicle Registration numbers of cars with drivers of given age
- System should be able to provide the parking slot of a given Vehicle Registration number
- System should be able to provide the parking slots of all cars with drivers of a given age
- All output should be shown in terminal

Added Requirements:
- Age of driver should be >= 18
- In case of unsuccessful creation/search, an exception is thrown with an appropriate message which has to be caught by the caller (instead of blank or null as in row 13 of the FAQ doc as it mentions "Anything will work")

Classes:
- ParkingLot: The class for the whole system, responsible for the parking functionalities like adding car to parking slot and vacating the parking slot.
- ParkingLotManager: The class for managing the ParkingLot, executing the commands on the ParkingLot.
- Customer: The class for the customer/driver, having details like age.
- ParkingTicket: The class for the parking ticket, having details like parking slot number, Vehicle Registration number of car and age of driver.
- Vehicle: The class for the car, having details like Vehicle Registration number, driver and parking ticket (if any).
- ParkingSlot: The class for the parking slot having details like slot number and the vehicle parked in the slot (if any).
- ParkingTicketVendingMachine: The class for the machine issuing the parking ticket.

