#include<iostream>
using namespace std;

class complex {
private:
    double real;
    double imag;

public:
    complex() : real(0.0), imag(0.0) {}
    complex(double r, double i) : real(r), imag(i) {}
    complex(const complex &c) : real(c.real), imag(c.imag) {}
    ~complex() {
        cout << "Destructor initialized\n";
    }
    friend ostream& operator<<(ostream&, const complex&);
    friend istream& operator>>(istream&, complex&);
	bool operator==(const complex& equal) const;
	complex operator-(complex& minus) const;
	complex operator+(complex& plus) const;
	complex operator*(complex& product) const;
};

ostream& operator<<(ostream& output, const complex& c) {
    output << c.real << " + " << c.imag << "i";
    return output;
}

istream& operator>>(istream& input, complex& c) {
    input >> c.real >> c.imag;
    return input;
}
bool complex::operator==(const complex& equal) const
{
	return (real==equal.real) && (imag==equal.imag);
}
complex complex::operator-(complex& minus) const
{
	return complex(real-minus.real, imag-minus.imag);
}
complex complex::operator+(complex& plus) const
{
	return complex(real+plus.real,imag+plus.imag);
}
complex complex::operator*(complex& product) const
{
	return complex(real*product.real,imag*product.imag);
}

int main() {
    complex n1, n2;
    complex n3(3.5, 7.6);
    cout<<n3<<endl;
	
	cout<<"type a complex number: \n";
	cout<<"type the real part and imaginary part: \n";
	cin>>n1;
	cout<<"type another number: \n";
	cin>>n2;
	
	cout<<"the numbers are: \n";
	cout<<n1<<endl;
	cout<<n2<<endl;
	
	if(n1==n2) cout<<"the numbers are equal\n";
	else cout<<"the numbers are not equal\n";
	
	cout<<"the difference is: "<<n1-n2<<endl;
	cout<<"the sum is: "<<n1+n2<<endl;
	cout<<"the product is: "<<n1*n2<<endl;

    return 0;
}

