#include <iostream>
using namespace std;

void p(int n)
{
	if(n>0)
	{
		p(n-2);
		cout<<n<<",";
		p(n-1);	
	}
}

int main()
{
	p(4);
	cin.get();
}

