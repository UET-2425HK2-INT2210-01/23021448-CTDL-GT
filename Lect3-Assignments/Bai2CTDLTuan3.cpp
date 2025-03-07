#include<iostream>
using namespace std;
long long powerOfTwo_Iterative(int n){
	long long result = 1;
	for (int i = 0; i < n; i++){
		result *= 2;
	}
	return result;
}
int main(){
	int n;
	cout << "Nhap n:";
	cin >> n;
	cout << "2^" << n << " = " << powerOfTwo_Iterative(n) << endl;
	return 0;
}


//1.Ham powerOfTwo_Iterative(int n) muc dich tinh 2^n bang cach nhan 2 lien tiep trong vong lap

//long long result = 1; Khoi tao bien result voi gia tri 1.

//for (int i = 0; i < n; i++){result *= 2;}//Vong lap chay n lan, moi lan lap nhan result voi 2 de tang luy thua dan len).

//return result; //tra ve ket qua khi vong lap ket thuc

//cout << "2^" << n << " = " << powerOfTwo_Iterative(n) << endl; //goi ham powerOfTwo_Iterative(n) de tinh 2^n.

