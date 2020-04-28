#include<bits/stdc++.h>
using namespace std;

double avg[100],ar[100][100],err[100];

double f(double u,double s,int n,double T,double M,double ad) {
	//Here, u is the work done by the player, and s is the deviation in his reported values and n is the number of people
	double a = 100;
	double b = 200;
	return T/(double)n + max(-T/(double)n, min(M-T/(double)n, (a*(u - (1/(double)n)) + b*(ad-s))));
}

int main()
{
	int n,i,j;

	cout << "Enter the no. of players : " << endl;
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
	cout << "Enter the marks obtained by entire team : " << endl;
	cin >> T;
	cout << "Enter the maximum individual marks each student can get : " << endl;
	cin >> M;
	cout << "Work" << "\t" << "Error" << "\t" << "Marks" << "\n";

	double avg_dev = 0;
	for(i=0;i<n;++i)
	{
		err[i] = sqrt(err[i]/n);
		avg_dev += err[i]/(double)n;
	}

	cout << std::fixed;
	for(i=0;i<n;++i)
		cout << setprecision(2) << avg[i] << "\t" << err[i] << "\t" << f(avg[i],err[i],n,T,M,avg_dev) << "\n";
	


	return 0;
}