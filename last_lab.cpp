/*Implement a class car with protected data: brand(string) and yearOfcar(int). As public members: constructor with params, copy constr, desctructor,
the assignement operator =, a virtual fucntion displayInfo(). Implement 2 types of cars, starting from car calss: Classic and electric. The classi 
car is just a car and the electric car is a car with an extra data member: (the no of km for a single charge). Implement a test program, to test everything */\



#include<iostream>
using namespace std;
class car{
	protected:
		string brand;
		int yearOfcar;
	public:
		car(string, int); //constructor with param
		car(const car&); // copy constructor
		~car();
		car& operator=(const car&); // car1 = car2;
		bool operator==(const car&) const; // if( car1== car2)
		virtual void displayinfo(); // 
};

class classic: public car {
	public:
		classic(string b, int y):car(b,y){cout<<" Classic constr with parasm "<<endl;}
		
};

class electric: public car{
	private:
		float range;
	public:
		virtual void displayinfo();
		electric(string, int, float);
};

//the constructor with params of Car class
car::car(string name, int year): brand(name), yearOfcar(year){cout<<"Car constructor with params"<< endl; }

//The copy constructor for car
car::car(const car& car): brand(car.brand),yearOfcar(car.yearOfcar) {cout<<"Car copy constructor"<< endl; }

//the destructor 
car::~car() {cout<< "car destructor"<< endl;}

// op =
car& car::operator=(const car& c){
	// to check if we have c1 = c1
	if(this != &c){
	brand = c.brand;
	yearOfcar= c.yearOfcar;
	}
	return *this;// this is a pointer to the current object
}
// op== 
bool car::operator==(const car& c) const{
	if(yearOfcar == c.yearOfcar)
	return true;
	else return false;
	//or return(yearOfcar == c.yearOfcar); 
}

void car::displayinfo() {
	cout<< "The brand of the car is: " <<brand<< endl;
	cout<<" the year of fabrication is: "<<yearOfcar<< endl;
}

//the elctric constr with params
//electric::electric(string brand, int year, float r){
//	this->brand= brand;
//	yearOfcar = year;
//	range = r;
//	cout<< " Electric constructor with params" <<endl;
//}
electric::electric(string brand, int year, float r): car(brand, year), range(r) {cout<< "Eletric constructor with params " <<endl;}

//displayinfo() function from electic class

void electric::displayinfo(){
	car::displayinfo();
	cout <<"The range is: "<<range<<"km."<< endl;
}

int main()
{
	car* cars[3]; //cars is an array of pointers to car
	cars[0] = new classic("Dacia", 2020);
	cars[1] = new electric("Mercedes", 2020, 451);
	cars[2] = new electric("Dacia", 2021, 320);
	for(int i=0; i< 3;i++)
	{
		cars[i]->displayinfo();
	}
	//if((*cars[0])==(*cars[1])) cout<<"equal \n"<< endl;
	//else cout<<"not equal \n";
	or cout<<" Have the 2 cars the same year of fab? " << boolalpha<<((*cars[1])==(*cars[2]));
	for(int i=0; i<3;i++)
	delete cars[i];
	
	return 0;
}

