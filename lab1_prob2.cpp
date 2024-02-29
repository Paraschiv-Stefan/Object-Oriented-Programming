#include <iostream>
#include <cstring>
using namespace std;
class Sir {
private:
    char *nume;
    int lungime;
public:
	Sir():nume(nullptr), lungime(0){}
    Sir(char *n, int lung):lungime(lung)
    {
    	this->nume = new char[lung+1];
    	strcpy(this->nume, n);
	}
	Sir(const Sir &altsir):lungime(altsir.lungime)
	{
		this->nume= new char[lungime+1];
		strcpy(this->nume, altsir.nume);
	}
   	~Sir()
   	{
   		delete[] nume;
   		cout<<"destructor"<<endl;
	}
   	void print()
   	{
   		cout<<"Nume: "<<nume<<", Lungime: "<<lungime<< endl;
	}
};

int main() {
    Sir s1("cirese",6);
    s1.print();
    
	Sir s2("castraveti",10);
	Sir s3;
	s3=s2;
	s2.print();
	s3.print();


    return 0;
}

