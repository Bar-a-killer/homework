#include<bits/stdc++.h>
using namespace std;
string data;
int main()
{
	int k,i=0;
	cin >> k;
	cin >> data;
	// for(int i=0;i<data.length();i++)
	// {
		// if(data[i]>=97)
		// {
			// data[i]==
		// }
	// }
	int output=0;
	int nota=0;
	int tmplen=0,det=0;
	nota=(data[i]>=97);
	while(i<data.length()-k+1)
	{
		for(int j=0;j<k;j++)
		{
			if((data[j+i]>=97)!=nota)
			{
				det+=1;
				break;
			}
			else if(j==k-1)
			{
				nota = !nota;
				tmplen+=k;
				i+=k;
				//cout << tmplen <<endl;
			}
		}
		if(det)
		{
			output = max(tmplen,output);
			
			if(tmplen>0)
				i -=k ;
			tmplen=0;
			det=0;
			i++;
			nota=(data[i]>=97);
			//cout << 'b' << endl;
		}
		
	}
	output = max(tmplen,output);
	cout << output << endl;
}