#include<bits/stdc++.h>
using namespace std;

double avg[100],ar[100][100],err[100];

double f(double u,double s,int n,double T,double M) {
	//Here, u is the work done by the player, and s is the deviation in his reported values and n is the number of people
	double a = (M - T/n)/(1 - 1/n);
	double b = -100;
	return a*(u - (1/(double)n)) + b*(s);
}

int main()
{
	int n,i,j;

	cin >> n;

	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			cin >> ar[i][j];
		}
	}

	for(j=0;j<n;++j)
		for(i=0;i<n;++i)
			avg[j] += ar[i][j]/(double)n;

	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			err[i] += (ar[i][j]-avg[j])*(ar[i][j]-avg[j]);
		}
	}

	//Allocating  marks to the members.
	double T = 320;
	double M = 100;
	cout << "Work" << "\t" << "Error" << "\t" << "Marks" << "\n";

	for(i=0;i<n;++i)
		cout << avg[i] << "\t" << sqrt(err[i]/n) << "\t" << T/n + f(avg[i],sqrt(err[i]/n),n,T,M) << "\n";
	


	return 0;
}
