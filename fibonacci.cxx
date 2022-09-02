#include <iostream>

using namespace std;

int main(){
	int f0=0, f1=1;
	int f2, N;

	cout << "N = ";
	cin >> N;

	for(int i=2; i<=N; i++){
		f2 = f1 + f0;
		f0 = f1; f1=f2;
	}

	cout << "f(" << N << ") = " << f2 << endl;

	return 0;
}