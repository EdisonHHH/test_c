#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> array;
	array.push_back(2);
	array.push_back(2);
	array.push_back(2);
	array.push_back(3);
	for(vector<int>::iterator iter=array.begin();iter!=array.end();++iter)
	{
		if(*iter==2)
		{
			iter=array.erase(iter)-1;
		}
	}
	for(vector<int>::iterator iter=array.begin();iter!=array.end();++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}
