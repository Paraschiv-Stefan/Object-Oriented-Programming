#include<iostream>
#include<string>
using namespace std;
class student{
	private:
		string nume;
		string adresa;
		int nrCursuri;
		string cursuri[20];
		int note[20];
	public:
		student(string n, string adr, int nr):nume(n),adresa(adr),nrCursuri(nr){}
		string getNume(){ return nume;}
		string getAdresa() {return adresa;}
		void setAdresa(string nouaAdresa)
		{
			adresa= nouaAdresa;
		}
		void print()
		{
			cout<<"numele studentului: "<<nume<<", adresa: "<<adresa; 
			cout<<"si numarul de cursuri: "<<nrCursuri<<endl;
		}
		void adaugaCurs(string curs, int nota) 
		{
		
        	if (nrCursuri < 20) {
            	cursuri[nrCursuri] = curs;
            	note[nrCursuri] = nota;
            	nrCursuri++;
        	} else {
            	cout << "Numarul maxim de cursuri a fost atins!" << endl;
        		}
    	}	
		void printNote()
		{
			for(int i=0;i<nrCursuri;i++)
			cout<<"Cursul:" <<cursuri[i] <<" si nota cursului: "<<note[i]<<endl;
		}
		float getMediaGenerala()
		{
			float s=0,cnt=0,media=0;
			for(int i=0;i<nrCursuri;i++)
			{
				s=s+note[i];
				cnt++;
			}
			media=s/cnt;
			return media;	
		}
		
		
};
int main()
{
	student s1("Mircea","Str Pacurari nr 44",0);
	cout<<"numele studentului "<<s1.getNume()<<endl;
	cout<<"adresa studentului "<<s1.getAdresa()<<endl;
	s1.setAdresa("Moara de foc nr105");
	cout<<"adresa schimbata "<<s1.getAdresa()<<endl;
	s1.adaugaCurs("matematica", 10);
	s1.adaugaCurs("bazele electrotehnicii", 8);
	s1.adaugaCurs("Fizica", 7);
	s1.adaugaCurs("OOP", 6);
	s1.printNote();
	cout<<"Media generala este: "<<s1.getMediaGenerala();
	return 0;
}
