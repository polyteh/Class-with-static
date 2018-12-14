#pragma once
#include <string> 
using std::string;


	class Transport
	{
						
		public:
		
		static int constructorCounter; //статические переменные и методы для подсчета вызовов конструктора/деструктора
		static int destructorCounter;
		static int getconstructorCounter () {return constructorCounter;};
		static int getdestructorCounter () {return destructorCounter;};
		
		static double totalAmount; //переменная и функций для накопления общей стоимости всей известной техники в одной переменной
		static const double & addTotalAmount(double const & USDprice); //добавление выбранного элемента в суммарную стоимость
		static const double & getTotalAmount () {return totalAmount;};//геттер для переменной накопления

		friend void ownerPrice(Transport &t, double superDiscount);//френд функция
		
		Transport(); //конструкторы
		Transport(const string & manufacturer);
		Transport(const string & manufacturer, const int & speed, const double & price);
		
		~Transport();//деструктор
		
		//геттеры и сеттеры на поля
		void setManufacturer (const string & setManufacturer) {manufacturer=setManufacturer;};
		const string & getManufacturer() const{return manufacturer;};
		void setSpeed (const int & setSpeed) {speed=setSpeed;};
		const int & getSpeed() const{return speed;};
		void setPrice (const double & setPrice) {price=setPrice;};
		const double & getPrice() const{return price;};	

		double & makeDiscount(const double & discount); //методы класса
		void printData();
		
		
		private:
		string manufacturer="unknown_manufacturer";//значения для полей по умолчанию
		int speed=0;
		double price=0;
		bool hasManufacturer=false;
		
		double discount;

		
	};
	

