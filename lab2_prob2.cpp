#include<iostream>
using namespace std;
class complex{
	private:
		double real;
		double imag;
	public:
		complex():real(0.0),imag(0.0){}
		complex(double r, double i):real(r), imag(i){}
		complex(const complex &c):real(c.real),imag(c.imag){}
		~complex(){ cout<<"destructor";}
		double getReal(){ cout<<"partea reala este: "; return real;}
		double getImag(){ cout<<"partea imaginara este: "; return imag;}
		void setComplex(double r, double i)
		{
			real=r;
			imag=i;
		}
		void print()
		{
			cout<<"Numarul este: "<<real<<" + "<<imag<<"i"<<endl;
		}
		bool eReal()
		{
			if(imag==0) return true;
			else return false;
		}
		bool eImag()
		{
			if(real==0) return true;
			else return false;
		}
		complex& suma(complex& c1)
		{
			real+=c1.real;
			imag+=c1.imag;
			return *this;
		}
};
int main()
{
	complex n1;
	//cout<<n1.getReal()<<endl;
	//cout<<n1.getImag()<<endl;
	//n1.print();
	n1.setComplex(3.2,7.5);
	//cout<<n1.getReal()<<endl;
	n1.print();
	complex n2(2,4);
	n2.print();
	n1.suma(n2);
	n1.print();
	return 0;
}
