#include<iostream>
using namespace std;
int main()
{
    double arr[5];
    for(int i = 0; i < 5; ++i){
    	cin >> arr[i];
	}
	double max = arr[0];
	double min = arr[0];
	for(int i = 1; i < 5; ++i){
		if(arr[i] < min){
			min = arr[i];
		}
		if(arr[i] > max){
			max = arr[i];
		}
	}
	cout << max + min << endl;
	return 0;
}
