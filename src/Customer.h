#ifndef __CUSTOMER__
#define __CUSTOMER__

class Customer
{
	int _age;
public:
	Customer(int age_);
	int get_age() const;
	static int minimum_age();
};

#endif //__CUSTOMER__
