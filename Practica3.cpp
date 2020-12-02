#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <Windows.h>

using namespace std;

int* Start; int* End;

int** sozdanie(int size)
{
	int** A;// Создаем матрицу введенной размерности
	A = new int* [size]; // через массив указателей
	for (int i = 0; i < size; i++) {
		A[i] = new int[size];
	}
	return A;
}

void initialize(int** A, int size)// Функция заполнения
{

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			A[i][j] = 0;
		}

	}
}

void returnMas(int** A, int size)
{

	for (int i = 0, f = 0; i < size; i++, f++)
	{

		for (int j = 0; j < size; j++)
		{
			cout << setw(4) << A[i][j];
		}
		cout << endl << endl;
	}
}

void spiral(int** a, int size, int num, int strStart, int strEnd, int colStart, int colEnd, int x, int y, int n) {

	Start = (int*)a[strStart];

	for (int i = colStart; i <= colEnd; i++, x += 4) {
		*(Start + i) = rand() % size * size + 1;

		COORD position;										// Объявление необходимой структуры
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода
		position.X = x;									// Установка координаты X
		position.Y = y;									// Установка координаты Y
		SetConsoleCursorPosition(hConsole, position);		// Перемещение каретки по заданным координатам
		cout << *(Start + i);
		Sleep(250);

		n++;
	}

	strStart++;
	y += 2;
	x -= 4;

	for (int i = strStart; i <= strEnd; i++, y += 2) {
		Start = (int*)a[i];
		*(Start + colEnd) = rand() % size * size + 1;

		COORD position;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hConsole, position);
		cout << *(Start + colEnd);
		Sleep(250);

		n++;
	}

	colEnd--;
	y -= 2;
	x -= 4;

	for (int i = colEnd; i >= colStart; i--, x -= 4) {
		*(Start + i) = rand() % size * size + 1;

		COORD position;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hConsole, position);
		cout << *(Start + i);
		Sleep(250);

		n++;
	}

	strEnd--;
	y -= 2;
	x += 4;

	for (int i = strEnd; i >= strStart; i--, y -= 2) {
		Start = (int*)a[i];
		*(Start + colStart) = rand() % size * size + 1;

		COORD position;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hConsole, position);
		cout << *(Start + colStart);
		Sleep(250);

		n++;
	}

	colStart++;
	x += 4;
	y += 2;

	if (n < num * num) spiral(a, size - 2, num, strStart, strEnd, colStart, colEnd, x, y, n);
}

void snake(int** a, int size, int str, int col, int x, int y, int n) {

	for (int i = str; i < size; i++, y += 2) {
		Start = (int*)a[str];
		*(Start + col) = rand() % size * size + 1;

		Sleep(250);
		COORD position;										// Объявление необходимой структуры
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода
		position.X = x;									// Установка координаты X
		position.Y = y;									// Установка координаты Y
		SetConsoleCursorPosition(hConsole, position);		// Перемещение каретки по заданным координатам
		cout << *(Start + col);


		n++;
	}

	str = size - 1;
	col++;
	y -= 2;
	x += 4;

	if (n < size * size) {

		for (int i = str; i >= 0; i--, y -= 2) {
			Start = (int*)a[i];
			*(Start + col) = rand() % size * size + 1;

			Sleep(250);
			COORD position;										// Объявление необходимой структуры
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода
			position.X = x;									// Установка координаты X
			position.Y = y;									// Установка координаты Y
			SetConsoleCursorPosition(hConsole, position);		// Перемещение каретки по заданным координатам
			cout << *(Start + col);

			n++;
		}

		col++;
		str = 0;

		if (n < size * size) snake(a, size, str, col, x += 4, y += 2, n);

	}

}

void copy(int** A, int** C, int size)
{

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			C[i][j] = A[i][j];

}

void zadanie_2(int** a, int** C, int size, int X, int Y) {
	
	int n = size / 2;
	int str = 0;
	int col = 0;
	int znah = 0;
	End = (int*)C[0];

	//a
	Sleep(250);
	cout << 'a' <<endl;
	copy(a, C, size);
	for (int i = str; i < n; i++) {
		Start = (int*)C[i];
		for (int j = col, y = n; j < n; j++, y++) {
			znah = *(Start + y);
			*(Start + y) = *(Start + j);
			*(Start + j) = znah;
		}
	}
	for (int i = col; i < n; i++) {
		for (int j = str, y = n; j < n; j++, y++) {
			Start = (int*)C[j];
			End = (int*)C[y];
			znah = *(Start + i);
			*(Start + i) = *(End + i);
			*(End + i) = znah;
		}
	}
	for (int i = n; i < size; i++) {
		Start = (int*)C[i];
		for (int j = col, y = n; j < n; j++, y++) {
			znah = *(Start + y);
			*(Start + y) = *(Start + j);
			*(Start + j) = znah;
		}
	}
	returnMas(C, size);
	cout << endl;

	//b
	Sleep(250);
	cout << 'b' << endl;
	copy(a, C, size);
	for (int i = col, x = n; i < n; i++, x++) {
		for (int j = str, y = n; j < n; j++, y++) {
			Start = (int*)C[j];
			End = (int*)C[y];
			znah = *(Start + x);
			*(Start + x) = *(End + i);
			*(End + i) = znah;
		}
	}
	for (int i = col, x = n; i < n; i++, x++) {
		for (int j = str, y = n; j < n; j++, y++) {
			Start = (int*)C[j];
			End = (int*)C[y];
			znah = *(Start + i);
			*(Start + i) = *(End + x);
			*(End + x) = znah;
		}
	}
	returnMas(C, size);
	cout << endl;



	//c
	Sleep(250);
	cout << 'c' << endl;
	copy(a, C, size);
	for (int i = col; i < size; i++) {
		for (int j = str, y = n; j < n; j++, y++) {
			Start = (int*)C[j];
			End = (int*)C[y];
			znah = *(Start + i);
			*(Start + i) = *(End + i);
			*(End + i) = znah;
		}
	}
	returnMas(C, size);
	cout << endl;

	//d
	Sleep(250);
	cout << 'd' << endl;
	copy(a, C, size);
	for (int i = str; i < size; i++) {
		Start = (int*)C[i];
		for (int j = col, y = n; j < n; j++, y++) {
			znah = *(Start + y);
			*(Start + y) = *(Start + j);
			*(Start + j) = znah;
		}
	}
	returnMas(C, size);
	cout << endl;
}

void sort(int** a, int size) {

	for (int f = 0; f < size * size; f++) {
		for (int row = 0; row < size; row++) {
			Start = (int*)a[row];
			for (int col = 0; col < size-1; col++) {
				for (int i = 0; i < size-1; i++) {
					if (*(Start + i) > *(Start + i + 1)) {
						swap(*(Start + i), *(Start + i + 1));
					}
				}
			}
		}

		for (int i = 0; i < size-1; i++) {
			for (int row = 0; row < size - 1; row++) {
				for (int col = 0; col < size; col++) {
					Start = (int*)a[row];
					End = (int*)a[row + 1];
					if (*(Start + i) > *(End + i)) {
						swap(*(Start + i), *(End + i));
					}
				}
			}
		}
		for (int i = 0; i < size - 1; i++) {
			Start = (int*)a[i];
			End = (int*)a[i + 1];
			if (*(Start + size - 1) > *(End + 0)) {
				swap(*(Start + size - 1), *(End + 0));
			}
		}
	}


}

int actions(int** a, int** C, int size) {

	int N = 1;
	while (N != 0) {

		cout << "  Выберите действие:" << endl << " 1)Уменьшить" << endl << " 2)Увеличить" << endl << " 3)Умножить" << endl << " 4)Разделить" << endl << " 0) Выход" << endl;
		cin >> N;
		int znach;

		switch (N) {

		case 1:

			cout << "Введите число:";
			cin >> znach;
			copy(a, C, size);
			for (int i = 0; i < size; i++) {
				Start = (int*)C[i];
				for (int j = 0; j < size; j++) {
					*(Start + j) = *(Start + j) - znach;
				}
			}
			returnMas(C, size);

			break;
		case 2:

			cout << "Введите число:";
			cin >> znach;
			copy(a, C, size);
			for (int i = 0; i < size; i++) {
				Start = (int*)C[i];
				for (int j = 0; j < size; j++) {
					*(Start + j) = *(Start + j) + znach;
				}
			}
			returnMas(C, size);

			break;
		case 3:

			cout << "Введите число:";
			cin >> znach;
			copy(a, C, size);
			for (int i = 0; i < size; i++) {
				Start = (int*)C[i];
				for (int j = 0; j < size; j++) {
					*(Start + j) = *(Start + j) * znach;
				}
			}
			returnMas(C, size);

			break;
		case 4:

			cout << "Введите число:";
			cin >> znach;
			copy(a, C, size);
			for (int i = 0; i < size; i++) {
				Start = (int*)C[i];
				for (int j = 0; j < size; j++) {
					*(Start + j) = *(Start + j) / znach;
				}
			}
			returnMas(C, size);

			break;

		case 0: return 0;
			break;
		}
	}
}

int main()
{
	setlocale(0, "");

	int size; //размер массива

	cout << "  Введите размерность матрицы 6/8/10:  ";
	cin >> size;

	int** A;
	A = sozdanie(size);
	initialize(A, size);
	int** C;
	C = sozdanie(size);
	initialize(C, size);
	int** B;
	B = sozdanie(size);
	initialize(B, size);

	int num = size; //для сравнения при выводе 

	cout << "  1) Используя арифметику указателей, заполняет матрицу случайными числами. Пользователь должен видеть процесс заполнения квадратичной матрицы." << endl;

		CONSOLE_SCREEN_BUFFER_INFO csbi;   //Получаем положение каретки (X, Y)
		COORD coord;

		if (GetConsoleScreenBufferInfo(
			GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		{
			coord.X = csbi.dwCursorPosition.X;
			coord.Y = csbi.dwCursorPosition.Y;
		}

	cout <<endl<<endl<< "a)";
	spiral(A, size, num, 0, size - 1, 0, size - 1, coord.X + 2, coord.Y + 2, 1);
		
		COORD position;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		position.X = coord.X + size * 4 + 6;
		position.Y = coord.Y + 2;
		SetConsoleCursorPosition(hConsole, position);

		coord.X = position.X;
		coord.Y = position.Y;

	
	cout << "b)";
	snake(C, size, 0, 0, coord.X + 2, coord.Y, 1);

		coord.X = csbi.dwCursorPosition.X;
		coord.Y = csbi.dwCursorPosition.Y;

		position.X = 0;
		position.Y = coord.Y + size*2 + 2;
		SetConsoleCursorPosition(hConsole, position);

	cout << "  2) Получает новую матрицу, из матрицы п. 1, переставляя ее блоки в соответствии со схемами" << endl;
	cout << endl;

	zadanie_2(A, B, size, coord.X + 3, coord.Y + 3);

	cout << endl << "  3) Используя арифметику указателей, сортирует элементы любой сортировкой." << endl;
	Sleep(700);
	cout << "  До сортировки:" << endl;
	Sleep(500);
	returnMas(A, size);
	sort(A, size);
	Sleep(500);
	cout << "  После сортировки:" << endl;
	Sleep(500);
	returnMas(A, size);

	cout << endl << "  4) Уменьшает, увеличивает, умножает или делит все элементы матрицы на введенное пользователем число." << endl;
	
	returnMas(A, size);
	cout << endl;
	actions(A, B, size);

	for (int i = 0; i < size; i++) {

		delete[] A[i];

	}
	for (int i = 0; i < size; i++) {

		delete[] B[i];

	}
	for (int i = 0; i < size; i++) {

		delete[] C[i];

	}
}
