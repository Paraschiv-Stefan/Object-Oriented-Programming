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
	//Sir(const Sir &altsir):lungime(altsir.lungime)
	//{
	//	this->nume= new char[lungime+1];
	//	strcpy(this->nume, altsir.nume);
	//}
   	~Sir()
   	{
   		delete[] nume;
   		cout<<"destructor"<<endl;
	}
   	void print()
   	{
   		cout<<"Nume: "<<nume<<", Lungime: "<<lungime<< endl;
	}
	Sir operator=(const Sir& other);
	bool operator==(const Sir& egal) const;
};

Sir Sir::operator=(const Sir& other)
{
	lungime=other.lungime;
	this->nume= new char[lungime+1];
	strcpy(this->nume, other.nume);
}
bool Sir::operator==(const Sir& egal) const
{
	int ok=1;
	for(int i=0;i<strlen(this->nume);i++)
	if(this->nume[i]!=egal.nume[i]) ok=0;
	if(ok==0)  return false;
	else return true;
	//if(lungime==egal.lungime)
	//{
	//cout<<"sirurile au aceasi lungime \n";
		//return true;
 //	}
 	//else {cout<<"sirurile nu au aceasi lungime \n";
 	//	return false;
	// }
}
int main() {
    Sir s1("cirese",6);
    s1.print();
    Sir s2;
    s2=s1;
    Sir s3("castravete",10);
    s2.print();
    if(s3==s1) cout<<"sirurile nu sunt identice \n";
    else cout<<"sirurile sunt identice \n";
    return 0;
}

