#include "Transport.h"
#include <iostream> 

using namespace std;

double Transport::totalAmount=0; //инициализация статических полей
int Transport::constructorCounter=0;
int Transport::destructorCounter=0;


const double & Transport::addTotalAmount(double const & USDprice)

	{
			return totalAmount+=USDprice;
	}


Transport::Transport(const string & manufacturer):manufacturer(manufacturer)
	{
		hasManufacturer=true;
		cout<<endl<<"constructor running for \t"<<manufacturer;
		constructorCounter++;
	}
Transport::Transport(const string & manufacturer, const int & speed, const double & price):manufacturer(manufacturer), speed(speed),price(price)
	{
		hasManufacturer=true;
		cout<<endl<<"constructor running for \t"<<manufacturer;
		constructorCounter++;
	}
Transport::~Transport()
	{
		cout<<endl<<"destructor running for \t"<<manufacturer;
		destructorCounter++;
	}	
	
double & Transport::makeDiscount(const double & getDiscount)
	{
		return discount=0.01*getDiscount*price;
		
	}
void Transport::printData()
	{
		cout<<endl<<"manufacturer is "<<manufacturer;
		cout<<endl<<"maximum speed is "<<speed;
		cout<<endl<<"price is "<<price<<endl;
	}
void ownerPrice(Transport &t, double superPrice)
{
	t.price=superPrice;
}