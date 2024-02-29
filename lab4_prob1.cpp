#include<iostream>
#include<string>
using namespace std;

class rezistor {
private:
    string nume;
    double valoare;

public:
    rezistor() : nume("unknown"), valoare(0.0) {}
    rezistor(string n, double v) : nume(n), valoare(v) {}
    rezistor(const rezistor& c) : nume(c.nume), valoare(c.valoare) {}
    ~rezistor() { cout << "destructor\n"; }

    friend istream& operator>>(istream&, rezistor&);
    friend ostream& operator<<(ostream&, const rezistor&);

    bool operator<(const rezistor& c);
    rezistor operator+(const rezistor& d);
    rezistor operator=(const rezistor& f);
};

istream& operator>>(istream& input, rezistor& p) {
    input >> p.nume >> p.valoare;
    return input;
}

ostream& operator<<(ostream& output, const rezistor& f) {
    output << "numele: " << f.nume << " " << "valoarea: " << f.valoare;
    return output;
}

bool rezistor::operator<(const rezistor& c) {
    return valoare < c.valoare;
}

rezistor rezistor::operator+(const rezistor& d) {
    return rezistor(nume + d.nume, valoare + d.valoare);
}

rezistor rezistor::operator=(const rezistor& f) {
    nume = f.nume;
    valoare = f.valoare;
    return *this;
}

int main() {
    rezistor r1("rezistor_mare", 2000);
    rezistor r2("rezistor_mic", 100);
    rezistor r3;
    r3 = r2;
    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;
    if (r2 < r3) cout << "is smaller\n";
    else cout << "is bigger\n";

    return 0;
}

