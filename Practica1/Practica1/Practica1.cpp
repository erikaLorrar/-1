#include <iostream> 
#include <iomanip>
using namespace std;



int main()
{
	setlocale(0, "");
	//1) Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без: int, short int, long int, float, double, long double, char и bool. 

	cout << setw(12) << "int " << sizeof(int) << " байта" << endl;
	cout << setw(12) << "short int " << sizeof(short int) << " байта" << endl;
	cout << setw(12) << "long int " << sizeof(long int) << " байта" << endl;
	cout << setw(12) << "float " << sizeof(float) << " байта" << endl;
	cout << setw(12) << "double " << sizeof(double) << " байт" << endl;
	cout << setw(12) << "long double " << sizeof(long double) << " байт" << endl;
	cout << setw(12) << "char " << sizeof(char) << " байт" << endl;
	cout << setw(12) << "bool " << sizeof(bool) << " байт" << endl;

	//2) Вывести на экран двоичное представление в памяти (все разряды) целого числа. При выводе необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом. 

	int intNum;
	unsigned intMask = 1 << 15;

	cout << "Введите число типа int:  ";
	cin >> intNum;

	if (intNum < 0) {

		cout << "1  ";
		intNum *= -1;

	}
	else cout << "0  ";

	intNum <<= 1;

	for (int i = 0; i < 15; i++) {

		putchar(intNum & intMask ? '1' : '0');
		intNum <<= 1;

	}

	cout << endl;

	//3) Вывести на экран двоичное представление в памяти (все разряды) типа float. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок. 

	union {
		float floatNum;
		int floatTool;
	};
	unsigned floatMask = 1 << 31;

	cout << "Введите число типа float:  ";
	cin >> floatNum;

	if (floatNum < 0) {

		cout << "1  ";
		floatNum *= -1;

	}
	else cout << "0  ";

	floatTool <<= 1;

	for (int i = 0; i < 31; i++) {

		if (i == 8) cout << "  ";
		putchar(floatTool & floatMask ? '1' : '0');
		floatTool <<= 1;

	}

	cout << endl;

	//4) Вывести на экран двоичное представление в памяти(все разряды) типа double.При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка(если есть), мантиссу и порядок.

	union {
		double doubleNum;
		int doubleTool[2];
	};

	unsigned doubleMask = 1 << 31;

	cout << "Введите число типа double:  ";
	cin >> doubleNum;

	if (doubleNum < 0) {

		cout << "1  ";
		doubleNum *= -1;

	}
	else cout << "0  ";

	doubleTool[1] <<= 1;

	for (int i = 0; i < 31; i++) {
		if (i == 11) cout << "  ";
		putchar(doubleTool[1] & doubleMask ? '1' : '0');
		doubleTool[1] <<= 1;
	}

	for (int i = 0; i < 32; i++) {
		putchar(doubleTool[0] & doubleMask ? '1' : '0');
		doubleTool[0] <<= 1;
	}

	return 0;
}

