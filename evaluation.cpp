#include<bits/stdc++.h>
using namespace std;

double avg[100],ar[100][100],err[100];

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

	for(i=0;i<n;++i)
		cout << avg[i] << " " << sqrt(err[i]/n) << "\n";

	return 0;
}