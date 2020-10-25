//1)    Создает целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99.
//2)    Отсортировать заданный в пункте 1 элементы массива[…] сортировкой.Определить время, затраченное на сортировку, используя библиотеку chrono.
//3)    Найти максимальный и минимальный элемент массива.Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono.
//4)    Выводит среднее значение(если необходимо, число нужно округлить) максимального и минимального значения.Выводит все числа, которые равны этому значению.
//5)    Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем.
//6)    Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем.
//7)    Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве.Реализуйте алгоритм бинарного поиска.Сравните скорость его работы с обычным перебором. (*)
//8)     Меняет местами элементы массива, индексы которых вводит пользователь.Выведите скорость обмена, используя библиотеку chrono.
//Должна присутствовать возможность запуска каждого пункта многократно.
#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

int arr[100];

void returnMas() { // Вывод массива

	for (int i = 0; i < 100; i++) {
		cout << "[" << i << "]" << arr[i] << " ";
	}
	cout << endl;
}

void randomMas() { // Заполнение массива рандомными значениями

	for (int i = 0; i < 100; i++) {
		arr[i] = rand() % 199 - 99;
	}

}

void sort() { // Сортировка массива пузырьком

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 99; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}

}

void timeSort() { //Время сортировки массива

	auto start = chrono::system_clock::now();

	sort();

	auto end = chrono::system_clock::now();
	chrono::duration<double> elapsed = end - start;

	cout << "Время работы сортировки:  " << std::fixed << elapsed.count() << "s";
	cout << endl;

}

void minMaxRandom() { //Поиск максимального и минимального элемента в неотсортированном массиве
	int min = 100, max = -100;

	randomMas();

	auto start = chrono::system_clock::now();

	for (int i = 0; i < 100; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}

	auto end = chrono::system_clock::now();

	chrono::duration<double> elapsed = end - start;
	cout << "Время поиска элементов в неотсортированном массиве:  " << std::fixed << elapsed.count() << " s" << endl;

	cout << "Наибольшее:  " << max << endl;
	cout << "Наименьшее:  " << min << endl;
}

void minMaxSort() { //Поиск максимального и минимального элемента в отсортированном массиве
	int min = 100, max = -100;

	sort();

	auto start = chrono::system_clock::now();

	for (int i = 0; i < 100; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}

	auto end = chrono::system_clock::now();

	chrono::duration<double> elapsed = end - start;
	cout << "Время поиска элементов в отсортированном массиве:  " << std::fixed << elapsed.count() << " s" << endl;

	cout << "Наибольшее:  " << max << endl;
	cout << "Наименьшее:  " << min << endl;
}

void average() { //Поиск среднего значения
	int min = 100, max = -100;

	randomMas();

	for (int i = 0; i < 100; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}

	cout << "Наибольшее:  " << max << endl;
	cout << "Наименьшее:  " << min << endl;

	int average = (min + max) / 2;
	int count = 0;

	cout << "Сренее значение:  " << average << endl;

	for (int i = 0; i < 100; i++) { //Вывод элементов равных этому значению
		if (arr[i] == average) {
			cout << "[" << i << "]" << arr[i] << endl;
			count += 1;
		}
	}
	if (count == 0) cout << "В массиве нет элементов равных среднему значению" << endl;
	else if (count == 1) cout << "Найден один элемент" << endl;
	else if (count == 2 || count == 3 || count == 4) cout << "Найдено "<< count<<" элемента" << endl;
	else cout << "Найдено " << count << " элементов" << endl;
}

void numA() { //Количество чисел в массиве меньше а
	int a, quant = 0;
	cout << "Введите число:  ";
	cin >> a;

	randomMas();
	sort();
	returnMas();

	for (int i = 0; i < 100; i++) {
		if (arr[i] < a) {
			quant += 1;
		}
	}

	cout << quant << "  эелементов в массиве меньше  " << a;
}

void numB() { //Количество чисел в массиве больше б
	int b, quant = 0;
	cout << "Введите число:  ";
	cin >> b;

	randomMas();
	sort();
	returnMas();

	for (int i = 0; i < 100; i++) {
		if (arr[i] > b) {
			quant += 1;
		}
	}

	cout << quant << "  эелементов в массиве больше  " << b;
}

void binSearch() { //Баинарный поиск

	int n;
	int mid;
	int l = 0;  //Нижняя граница
	int u = 100; //Верхняя граница
	int key;

	cout << "введите число, которое необходимо найти:  ";
	cin >> n;

	randomMas();
	sort();

	auto start1 = chrono::system_clock::now();

	while (l <= u) {
		mid = (l + u) / 2;
		if (arr[mid] == n) break;
		if (arr[mid] < n) l = mid + 1;
		if (arr[mid] > n) u = mid - 1;
	}

	auto end1 = chrono::system_clock::now();

	chrono::duration<double> elapsed1 = end1 - start1;

	if (arr[mid] == n) {
		cout << "Индекс элемента " << n << " в массиве равен: " << mid << endl;
		cout << "Время бинарного поиска элемента:  " << std::fixed << elapsed1.count() << " s" << endl;


		auto start2 = chrono::system_clock::now();

		for (int i = 0; i < 100; i++) {  //Поиск перебором
			if (arr[i] == n) {
				key = i;
			}
		}

		auto end2 = chrono::system_clock::now();

		chrono::duration<double> elapsed2 = end2 - start2;

		if (arr[key] == n) {
			cout << "Время поиска элемента перебором:  " << std::fixed << elapsed2.count() << " s" << endl;
		}

		if (elapsed2.count() < elapsed1.count()) {
			cout << "Бинарный поиск быстрее" << endl;
		}
	}
	else {
		cout << "Такого элемента в массиве нет" << endl;
	}

	returnMas();

}

void change() { //Поменять местами элементы с индексами заданными пользователем
	int a, b;
	cout << "Введите индексы элементов, которые нужно поменять местами:  " << endl;
	cin >> a >> b;
	randomMas();
	returnMas();

	auto start = chrono::system_clock::now();

	swap(arr[a], arr[b]);

	auto end = chrono::system_clock::now();

	chrono::duration<double> elapsed = end - start;
	cout << "Скорость обмена:  " << std::fixed << elapsed.count() << " s" << endl;

	returnMas();
}

int main()
{
	setlocale(0, "");
	int n;
	cout << "1)    Создает целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99." << endl;
	cout << "2)    Отсортировать заданный в пункте 1 элементы массива[…] сортировкой.Определить время, затраченное на сортировку, используя библиотеку chrono." << endl;
	cout << "3)    Найти максимальный и минимальный элемент массива.Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono." << endl;
	cout << "4)    Выводит среднее значение(если необходимо, число нужно округлить) максимального и минимального значения.Выводит все числа, которые равны этому значению." << endl;
	cout << "5)    Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем." << endl;
	cout << "6)    Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем." << endl;
	cout << "7)    Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве.Реализуйте алгоритм бинарного поиска.Сравните скорость его работы с обычным перебором. (*)" << endl;
	cout << "8)    Меняет местами элементы массива, индексы которых вводит пользователь.Выведите скорость обмена, используя библиотеку chrono." << endl;
	cout << "0)    Выход" << endl;
	cout << "Введите номер задания:  ";
	cin >> n;

	while (n != 0) {

		switch (n)
		{
		case 1: randomMas(); returnMas();
			break;
		case 2: randomMas(); sort(); timeSort(); returnMas();
			break;
		case 3: minMaxRandom(); returnMas(); minMaxSort(); returnMas();
			break;
		case 4: average(); returnMas();
			break;
		case 5: numA();
			break;
		case 6: numB();
			break;
		case 7: binSearch();
			break;
		case 8: change();
			break;
		case 0: return 0;
			break;
		default: cout << "Такого номера нет!";
			break;
		}
		cout << endl;
		cout << "Введите номер задания:  ";
		cin >> n;
	}

	return 0;
}