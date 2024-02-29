#include<iostream>
using namespace std;
double* produs(double v1[],double v2[],int n)
{
	double *pr= new double[n];
	for(int i=0;i<n;i++)
		pr[i]=v1[i]*v2[i];
	return pr;
}
int main()
{
	int n;
	double v1[100],v2[100];
	cout<<"dati n= "; cin>>n;
	cout<<"primul vector= \n";
	for(int i=0;i<n;i++)
	cin>>v1[i];
	cout<<"al doilea vector= \n";
	for(int i=0;i<n;i++)
	cin>>v2[i];
	double *rez=produs(v1,v2,n);
	cout<<"rezultatul produsului= \n";
	for(int i=0;i<n;i++)
	cout<<rez[i]<<" ";
	delete[] rez;
	
	return 0;
}
