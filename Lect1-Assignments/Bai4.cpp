#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[1000];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n -1; i++){
		for(int j = 0; j < n - 1; j++){
			if(a[j] > a[j + 1]){
				int b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
    }
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	return 0;
}
	
