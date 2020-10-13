//Практическая работа 1 + доп.задание (Добавить возможность изменить произвольные биты на 1 или 0 по указанию пользователя)

#include <iostream> 
#include <iomanip> //Прдключение библиотеки для работы setw()
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
	unsigned intMask = 1 << 31;
	int arr[32];

	cout << "Введите число типа int:  ";
	cin >> intNum;

	for (int i = 0; i < 32; i++) {
		if (i == 0) {
			putchar(intNum & intMask ? '1' : '0');
			cout << "  ";								//отделяем знаковый бит
		}
		else {
			putchar(intNum & intMask ? '1' : '0');
		}

		intNum <<= 1;
		if (intNum & intMask) { // Записываем двоичное представление числа в массив для дополнительного задания
			arr[i] = 1;
		}
		else { arr[i] = 0; }
	}

	cout << endl;

	//Измениение произвольного бита

	int numBit, znachBit;
	cout << "Введите номер бита:";
	cin >> numBit;
	cout << "Введите значение бита 1/0:";
	cin >> znachBit;

	for (int i = 0; i < 31; i++) {
		if (i == 0) {
			if (i == (numBit - 1)) cout << znachBit << "  ";
			else cout << arr[i] << "  ";
		}
		else {
			if (i == (numBit - 1)) cout << znachBit;
			cout << arr[i];
		}
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

	for (int i = 0; i < 32; i++) {
		if (i == 0 || i == 8) {
			putchar(floatTool & floatMask ? '1' : '0');
			cout << "  ";								//отделяем знаковый бит, экспоненту и мантиссу
		}
		else {
			putchar(floatTool & floatMask ? '1' : '0');
		}

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


	for (int i = 0; i < 32; i++) {
		putchar(doubleTool[1] & doubleMask ? '1' : '0');
		if (i == 0 || i == 11) cout << "  ";
		doubleTool[1] <<= 1;
	}

	for (int i = 32; i < 65; i++) {
		putchar(doubleTool[0] & doubleMask ? '1' : '0');
		doubleTool[0] <<= 1;
	}


	return 0;
}