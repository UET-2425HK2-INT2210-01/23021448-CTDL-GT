#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	int n = s.size();
	int j = 0;
	for(int i = 0; i <= n; i++){
		if((s[i] == ' ')||(i == n)){
			for(int p = i - 1; p >= j; p--)
			   cout << s[p];
			   j = 1 + i;
			   cout << " ";
		}
	}
	return 0;
}

