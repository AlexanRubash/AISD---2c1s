#include <iostream>
using namespace std;
void hanoi(int i, int k, int n);
int num = 1;
int main()
{
	int choosen, choosek;
	setlocale(0, "rus");
	cout << "(N)Введите количеcтво дисков: ";
	cin >> choosen;
	if (choosen <= 1 ) {
		cout << "Введены неверные значения 'k'\nВведите N повторно(N>2): ";
		cin >> choosen;
	}
	cout << "\n(k)Введите куда надо переместить(2-3): ";
	cin >> choosek;
	if (choosek <= 1 || choosek > 3) {
		cout << "Введены неверные значения 'k'\nВведите k повторно(2-3): ";
		cin >> choosek;
	}


	hanoi(1, choosek, choosen);
	return 0;
}
void hanoi(int i, int k, int n)
{
	
	if (n == 1) {
	
		cout<<num++<< ") Переместить диск 1 со стержня " << i << " на стержень " << k << ".\n";
		
	}
	else {
		
		int tmp = 6 - i - k;
		hanoi(i, tmp, n - 1);
		
		cout <<num++ <<") Переместить диск " << n << " со стержня " << i << " на стержень " << k << ".\n";
		hanoi(tmp, k, n - 1);
	
	}
}
