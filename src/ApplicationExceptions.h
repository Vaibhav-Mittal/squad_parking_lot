#ifndef __APPLICATION_EXCEPTIONS__
#define __APPLICATION_EXCEPTIONS__
#include <exception>
#include <string>

class ParkingLotException : public std::exception
{
	std::string _msg;
public:
	ParkingLotException(const std::string& msg_) : _msg(msg_){}

	const char* what() const noexcept override { return _msg.c_str(); }

};

class CustomerException : public std::exception
{
	std::string _msg;
public:
	CustomerException(const std::string& msg_) : _msg(msg_){}

	const char* what() const noexcept override{ return _msg.c_str(); }
};

#endif //__APPLICATION_EXCEPTIONS__
