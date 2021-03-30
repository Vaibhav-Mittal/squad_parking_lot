#include "Customer.h"
#include "ApplicationExceptions.h"

Customer::Customer(int age_)
{
	if (age_ < minimum_age()) // Added requirement: if the age provided is less than minimum age, then Customer object cannoe be created and the command would fail.
	{
		throw CustomerException("Age of driver should be more than or equal to " + std::to_string(minimum_age()));
	}
	_age = age_;
}

int Customer::get_age() const
{
	return _age;
}

int Customer::minimum_age()
{
	return 18;
}

