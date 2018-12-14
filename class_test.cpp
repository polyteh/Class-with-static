#include <iostream>  
#include <vector>   
#include <memory>   

#include "Transport.h"


using namespace std;


int main()
	{
		
	//высветил счетчики конструкторов-деструкторов, статик методы	
	cout<<"Constructor run "<<Transport::getconstructorCounter()<<" times"<<endl; 
	cout<<"Destructor run "<<Transport::getdestructorCounter()<<" times"<<endl;
		
	vector<string> manufacturerVector{"Audi","BMW","","Daewoo"};//вектора для инициализации объектов
	vector<int> speedVector{150,200,300,50};
	vector<double> priceVector{150,200,300,50};
	
	//указатель на вектор объектов
	vector<Transport*> obj (manufacturerVector.size()); 


	for(int i=0;i<manufacturerVector.size();i++) //заполнение вектора объектами
	{
		
		obj[i]=new Transport(manufacturerVector[i],speedVector[i],priceVector[i]);
		//unique_ptr<Transport> t{new Transport(manufacturerVector[i],speedVector[i],priceVector[i])}; //в данном случае нет преимущества, так как все равно надо чистить вектор
		//obj[i]=t.release();
		(*obj[i]).printData();//метод класса для печати всего
		
		
	};
	
	//накопление суммы выбранных объектов через статик методы
	Transport::addTotalAmount((*obj[1]).getPrice()); 
	Transport::addTotalAmount((*obj[3]).getPrice());
	cout<<endl<<"Total price of selected items is "<<Transport::getTotalAmount()<<endl;

	//метод для вычисления скидки
	cout<<endl<<"Possible discount for "<<(*obj[0]).getManufacturer()<<" is "<<(*obj[0]).makeDiscount(10)<<endl;
	
	//чистка вектора объектов
	for(auto it=obj.begin();it!=obj.end();++it) 
	{
		delete(*it);
	};
	
	//высветил счетчики конструкторов-деструкторов, статик методы, для понимания, что все удалил
	cout<<endl<<endl;
	cout<<"Constructor run "<<Transport::getconstructorCounter()<<" times"<<endl;
	cout<<"Destructor run "<<Transport::getdestructorCounter()<<" times"<<endl;
	
	//создал объект через умный указатель - деструктор после заверщения программы (оно же выход из зоны видимости) вызывается, перегрузка конструктора
	unique_ptr<Transport> testUniq{new Transport("Chevrolet")};
	(*testUniq).printData();
	
		
	//высветил счетчики конструкторов-деструкторов, статик методы, для понимания, что все удалил
	cout<<"Constructor run "<<Transport::getconstructorCounter()<<" times"<<endl;
	cout<<"Destructor run "<<Transport::getdestructorCounter()<<" times"<<endl;
	
	//создал объект через обьычный указатель - деструктор после заверщения программы (оно же выход из зоны видимости) НЕ вызывается
	Transport *testNew=new Transport("Volvo");
	testNew->printData();
	
	//с помощью френд-функции установил новую цену
	cout<<endl<<"Set Owner price " <<endl;
	ownerPrice(*testNew,100); 
	testNew->printData();
	
	//еще раз посмотрел, что все удалил
	cout<<"Constructor run "<<Transport::getconstructorCounter()<<" times"<<endl;
	cout<<"Destructor run "<<Transport::getdestructorCounter()<<" times"<<endl;		
		
		std::cin.get();
		return 0;
	}