#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Students {
	string name;
	string gender;
	int numGroup;
	int numStud;
	int ratings[8];
	double average;
	string form;
	string time;
};

void menu() {
	cout << "1.   Создание новой записи о студенте." << endl;
	cout << "2.   Внесение изменений в уже имеющуюся запись." << endl;
	cout << "3.   Вывод всех данных о студентах." << endl;
	cout << "4.   Вывод информации обо всех студентах группы N. N – инициализируется пользователем." << endl;
	cout << "5.   Вывод топа самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию." << endl;
	cout << "6.   Вывод количества студентов мужского и женского пола." << endl;
	cout << "7.   Определение количества студентов, которые будут получать стипендию." << endl;
	cout << "8.   Вывод данных о студентах, которые не получают стипендию." << endl;
	cout << "9.   Вывод данных о студентах, имеющих номер в списке – k." << endl;
	cout << "10.  Вывод всех записей, сделанных в день, который введет пользователь." << endl;
	cout << "11.  Вывод всех записей, сделанных после полудня." << endl;
	cout << "12.  Вывод всех записей, сделанных до полудня." << endl;
	cout << "0.   ВЫХОД" << endl;
}

void Info(vector<Students>&stud, int n) { //Вывод всех данных о студентах.
	
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << "Name:  " << stud[i].name << endl;
		cout << "Group:  " << stud[i].numGroup << endl;
		cout << "Student number:  " << stud[i].numStud << endl;
		cout << "Gender:  " << stud[i].gender << endl;
		cout << "Form of education:  " << stud[i].form << endl;
		cout << "Raitings:  ";
			for (int j = 0; j < 8; j++) {
				cout<< stud[i].ratings[j]<< " ";
			}
			cout << endl;
		cout << "Date:  " << stud[i].time << endl << endl;
	}
}

void AddStudent(vector<Students>&stud, int n) {
 
	ofstream students;
	students.open("students.txt", ios_base::app);
	stud.resize(n);
	string name;
	string gender;
	int numGroup;
	int numStud;
	int ratings[8];
	string form;
	string time;
	cout << "Введите имя:  ";
	cin >> name;
	students << "\n" << name; //запись в файл
	stud[n-1].name = name; //добавление в структуру
	cout << "Введите пол:  ";
	cin >> gender;
	students << "\n" << gender; //запись в файл
	stud[n - 1].gender = gender; //добавление в структуру
	cout << "Введите номер группы:  ";
	cin >> numGroup;
	students << "\n" << numGroup; //запись в файл
	stud[n - 1].numGroup = numGroup; //добавление в структуру
	cout << "Введите номер студента в списке:  ";
	cin >> numStud;
	students << "\n" << numStud << "\n"; //запись в файл
	stud[n - 1].numStud = numStud; //добавление в структуру
	cout << "Введите оценки за прошедшую сессию:  ";
	for (int i = 0; i < 8; i++) {
		cin >> ratings[i];
		//cout << ratings[i];
		students << ratings[i] << " "; //запись в файл
		stud[n - 1].ratings[i] = ratings[i]; //добавление в структуру
	}
	cout << "Введите форму обучения:  ";
	cin >> form;
	students << "\n" << form; //запись в файл
	stud[n - 1].form = form; //добавление в структуру
	cout << "Введите время:  ";
	cin >> time;
	students << "\n" << time; //запись в файл
	stud[n - 1].time = time; //добавление в структуру
	students.close();
}

void EditStudent(vector<Students>&stud, int n) {

	ifstream edit("students.txt");

	string name;
	string gender;
	int numGroup;
	int numStud;
	int ratings[8];
	string form;
	string time;

	cout << "1  Name:  " << stud[n-1].name << endl;
	cout << "2  Group:  " << stud[n-1].numGroup << endl;
	cout << "3  Student number:  " << stud[n-1].numStud << endl;
	cout << "4  Gender:  " << stud[n-1].gender << endl;
	cout << "5  Form of education:  " << stud[n-1].form << endl;
	cout << "6  Raitings:  ";
	for (int j = 0; j < 8; j++) {
		cout << stud[n-1].ratings[j] << " ";
	}
	cout << endl;
	cout << "7  Date:  " << stud[n-1].time << endl << endl;

	
	cout << "Введите новые значения:  " << endl;
	
	cout << "Введите имя:  ";
	cin >> name;
	stud[n - 1].name = name; //добавление в структуру
	cout << "Введите пол:  ";
	cin >> gender;
	stud[n - 1].gender = gender; //добавление в структуру
	cout << "Введите номер группы:  ";
	cin >> numGroup;
	stud[n - 1].numGroup = numGroup; //добавление в структуру
	cout << "Введите номер студента в списке:  ";
	cin >> numStud;
	stud[n - 1].numStud = numStud; //добавление в структуру
	cout << "Введите оценки за прошедшую сессию:  ";
	for (int i = 0; i < 8; i++) {
		cin >> ratings[i];
		stud[n - 1].ratings[i] = ratings[i]; //добавление в структуру
	}
	cout << "Введите форму обучения:  ";
	cin >> form;
	stud[n - 1].form = form; //добавление в структуру
	cout << "Введите время:  ";
	cin >> time;
	stud[n - 1].time = time; //добавление в структуру

	int i = 0; //счётчик строк
	string line; //для хранения строки
	string line_file_text; //для хранения текста файла

	while (getline(edit, line)){

		i++;
		if ((n == 1 && n == i) || (i == (n-1)*7+1)){
			i = i + 7;
			string SnG = to_string(numGroup);
			string SnS = to_string(numStud);
			string Sratings;
			for (int i = 0; i < 8; i++) {
				Sratings += to_string(ratings[i]);
			}
			line_file_text.insert(line_file_text.size(), name + "\n");
			line_file_text.insert(line_file_text.size(), SnG + "\n");
			line_file_text.insert(line_file_text.size(), SnS + "\n");
			line_file_text.insert(line_file_text.size(), gender + "\n");
			line_file_text.insert(line_file_text.size(), form + "\n");
			line_file_text.insert(line_file_text.size(), Sratings + "\n");
			line_file_text.insert(line_file_text.size(), time + "\n");
		}

		line_file_text.insert(line_file_text.size(), line + "\n");
		
	}

	edit.close();

	//теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл

	ofstream file_out;

	file_out.open("students.txt", ios::trunc | ios::binary); //открыть и обрезать

	//записать

	file_out.write(line_file_text.c_str(), line_file_text.size());
	file_out.clear();

	edit.close();
}

void func_4(vector<Students>&stud, int n, int N) {

	for (int i = 0; i < n; i++) {
		if (stud[i].numGroup == N) {
			cout << "Name:  " << stud[i].name << endl;
			cout << "Group:  " << stud[i].numGroup << endl;
			cout << "Student number:  " << stud[i].numStud << endl;
			cout << "Gender:  " << stud[i].gender << endl;
			cout << "Form of education:  " << stud[i].form << endl;
			cout << "Raitings:  ";
			for (int j = 0; j < 8; j++) {
				cout << stud[i].ratings[j] << " ";
			}
			cout << endl;
			cout << "Date:  " << stud[i].time << endl << endl;
		}
	}
} 

void top(vector<Students>&stud, int n) {
	double average;
	for (int i = 0; i < n; i++) { //средний былл каждого студента
		average = 0;
		for (int j = 0; j < 8; j++) {
			average = average + stud[i].ratings[j];
		}
		//average = (stud[i].ratings[0]+ stud[i].ratings[1] + stud[i].ratings[2] + stud[i].ratings[3] + stud[i].ratings[4] + stud[i].ratings[5] + stud[i].ratings[6] + stud[i].ratings[7])/8;
		stud[i].average = average/8;
		//cout << stud[i].average << endl;
	}
	for (int b = 0; b < n; b++) {
		for (int e = 0; e < n-1; e++) {
			if (stud[e].average < stud[e+1].average) {
				swap(stud[e], stud[e + 1]);
			}
		}
	}
	for (int g = 0; g < n; g++) { //средний былл каждого студента
		cout << stud[g].average << endl;
		cout << "Name:  " << stud[g].name << endl;
		cout << "Group:  " << stud[g].numGroup << endl << endl;
	}
}

void gender(vector<Students>&stud, int n) {

	int M = 0, F = 0;

	for (int i = 0; i < n; i++) {

		if (stud[i].gender == "F") F++;
		if (stud[i].gender == "M") M++;

	}
	cout << "количества студентов женского пола:  " << F << endl;
	cout << "количества студентов мужского пола:  " << M << endl;

}

void stipend(vector<Students>&stud, int n) {

	int sum = 0;
	bool task = 1;

	for (int i = 0; i < n; i++) {
		task = 1;
		for (int j = 0; j < 8; j++) {
			if (stud[i].ratings[j] < 4) task = 0;
			//cout << stud[i].ratings[j];
		}
		if (task && stud[i].form == "day") sum++;

	}
	cout << "Количество студентов, которые будут получать стипендию:  " << sum << endl << endl;
}

void funk_8(vector<Students>&stud, int n) {
	cout << "1.  Студенты, которые не получают стипендию" << endl;
	cout << "2.  Студенты, которые учатся только на «хорошо» и «отлично»" << endl;
	cout << "3.  Студенты, которые учатся только на «отлично»" << endl;
	cout << "0.  Выход в главное меню" << endl;
	int N;
	cin >> N;
	bool task = 1;
	while (N!=0)
	{
		switch (N)
		{
		case 1:
			system("cls");
			cout << "Студенты, которые не получают стипендию:" << endl;
			for (int i = 0; i < n; i++) {
				task = 0;
				for (int j = 0; j < 8; j++) {
					if (stud[i].ratings[j] < 4) task = 1;
				}
				if (task || stud[i].form != "day") {
					cout << "Name:  " << stud[i].name << endl;
					cout << "Group:  " << stud[i].numGroup << endl;
					cout << "Student number:  " << stud[i].numStud << endl;
					cout << "Gender:  " << stud[i].gender << endl;
					cout << "Form of education:  " << stud[i].form << endl;
					cout << "Raitings:  ";
					for (int j = 0; j < 8; j++) {
						cout << stud[i].ratings[j] << " ";
					}
					cout << endl;
					cout << "Date:  " << stud[i].time << endl << endl;
				}
			}
			break;
		case 2:
			system("cls");
			cout << "Студенты, которые учатся только на «хорошо» и «отлично»:" << endl;
			for (int i = 0; i < n; i++) {
				task = 1;
				for (int j = 0; j < 8; j++) {
					if (stud[i].ratings[j] < 4) task = 0;
				}
				if (task) {
					cout << "Name:  " << stud[i].name << endl;
					cout << "Group:  " << stud[i].numGroup << endl;
					cout << "Student number:  " << stud[i].numStud << endl;
					cout << "Gender:  " << stud[i].gender << endl;
					cout << "Form of education:  " << stud[i].form << endl;
					cout << "Raitings:  ";
					for (int j = 0; j < 8; j++) {
						cout << stud[i].ratings[j] << " ";
					}
					cout << endl;
					cout << "Date:  " << stud[i].time << endl << endl;
				}
			}
			break;
		case 3:
			system("cls");
			cout << "Студенты, которые учатся только на «отлично»:" << endl;
			for (int i = 0; i < n; i++) {
				task = 1;
				for (int j = 0; j < 8; j++) {
					if (stud[i].ratings[j] < 5) task = 0;
				}
				if (task) {
					cout << "Name:  " << stud[i].name << endl;
					cout << "Group:  " << stud[i].numGroup << endl;
					cout << "Student number:  " << stud[i].numStud << endl;
					cout << "Gender:  " << stud[i].gender << endl;
					cout << "Form of education:  " << stud[i].form << endl;
					cout << "Raitings:  ";
					for (int j = 0; j < 8; j++) {
						cout << stud[i].ratings[j] << " ";
					}
					cout << endl;
					cout << "Date:  " << stud[i].time << endl << endl;
				}
			}
			break;
		case 0:
			break;
		default:
			break;
		}
		cout << endl << "1.  Студенты, которые не получают стипендию" << endl;
		cout << "2.  Студенты, которые учатся только на «хорошо» и «отлично»" << endl;
		cout << "3.  Студенты, которые учатся только на «отлично»" << endl;
		cout << "0.  Выход в главное меню" << endl;
		cin >> N;
	}
	
}

void studNum(vector<Students>&stud, int n, int N) {

	for (int i = 0; i < n; i++) {
		if (stud[i].numStud == N) {
			cout << "Name:  " << stud[i].name << endl;
			cout << "Group:  " << stud[i].numGroup << endl;
			cout << "Student number:  " << stud[i].numStud << endl;
			cout << "Gender:  " << stud[i].gender << endl;
			cout << "Form of education:  " << stud[i].form << endl;
			cout << "Raitings:  ";
			for (int j = 0; j < 8; j++) {
				cout << stud[i].ratings[j] << " ";
			}
			cout << endl;
			cout << "Date:  " << stud[i].time << endl << endl;
		}
	}

}

void time_day(vector<Students>&stud, int n) {
	string month, day, date, studTime;
	cout << "Введите месяц:  ";
	cin >> month;
	cout << endl << "Введите день:  ";
	cin >> day;
	date = month + " " + day;

	for (int i = 0; i < n; i++) {
		studTime = stud[i].time;
		studTime.erase(10);
		studTime.erase(0, 4);
		
		if (studTime == date) {
			cout << "Name:  " << stud[i].name << endl;
			cout << "Group:  " << stud[i].numGroup << endl;
			cout << "Student number:  " << stud[i].numStud << endl;
			cout << "Gender:  " << stud[i].gender << endl;
			cout << "Form of education:  " << stud[i].form << endl;
			cout << "Raitings:  ";
			for (int j = 0; j < 8; j++) {
				cout << stud[i].ratings[j] << " ";
			}
			cout << endl;
			cout << "Date:  " << stud[i].time << endl << endl;
		}

	}
}

void time_afternoon(vector<Students>&stud, int n) {
	string studTime, hour, min;


	for (int i = 0; i < n; i++) {
		studTime = stud[i].time;
		int pos = studTime.find(" ", 8);
		if (pos != 9) {
			studTime.erase(19);
			studTime.erase(0, 11);
		}
		else {
			studTime.erase(18);
			studTime.erase(0, 10);
		}

		hour = studTime; hour.erase(2);
		min = studTime; min.erase(5); min.erase(0, 3);

		if (stoi(hour) >= 12 || (stoi(hour) == 12 && stoi(min) >= 0)) {
			cout << "Name:  " << stud[i].name << endl;
			cout << "Group:  " << stud[i].numGroup << endl;
			cout << "Student number:  " << stud[i].numStud << endl;
			cout << "Gender:  " << stud[i].gender << endl;
			cout << "Form of education:  " << stud[i].form << endl;
			cout << "Raitings:  ";
			for (int j = 0; j < 8; j++) {
				cout << stud[i].ratings[j] << " ";
			}
			cout << endl;
			cout << "Date:  " << stud[i].time << endl << endl;
		}

	}
}

void time_untilnoon(vector<Students>&stud, int n) {
	string studTime, hour;


	for (int i = 0; i < n; i++) {
		studTime = stud[i].time;
		int pos = studTime.find(" ", 8);
		if (pos != 9) {
			studTime.erase(19);
			studTime.erase(0, 11);
		}
		else {
			studTime.erase(18);
			studTime.erase(0, 10);
		}
		
		hour = studTime; hour.erase(2);

		if (stoi(hour) < 12) {
			cout << "Name:  " << stud[i].name << endl;
			cout << "Group:  " << stud[i].numGroup << endl;
			cout << "Student number:  " << stud[i].numStud << endl;
			cout << "Gender:  " << stud[i].gender << endl;
			cout << "Form of education:  " << stud[i].form << endl;
			cout << "Raitings:  ";
			for (int j = 0; j < 8; j++) {
				cout << stud[i].ratings[j] << " ";
			}
			cout << endl;
			cout << "Date:  " << stud[i].time << endl << endl;
		}

	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
    
	ifstream file("students.txt");   //открываем файл

	int N = 0;
	while (!file.eof()) {
		if (file.get() == '\n')
			N++;
	}
	N = N++ / 7; //количество студентов
	//cout << N;
	file.close();

	vector<Students>stud(N);

	ifstream f("students.txt");

	for (int i = 0; i < N; i++) {
		getline(f, stud[i].name);
		f >> stud[i].numGroup; f.ignore();
		f >> stud[i].numStud; f.ignore();
		getline(f, stud[i].gender);
		getline(f, stud[i].form);

		for (int j = 0; j < 8; j++) {
			f >> stud[i].ratings[j];
		}

		f.ignore(2);
		getline(f, stud[i].time);
	}

	f.close();

	int Choice = -1;
	while (Choice != 0) {
		menu();
		cout << endl;
		cout << "Введите номер задания:  " << endl;
		cin >> Choice;
		switch (Choice)
		{
		case 1:
			system("cls");
			cout << "Добавьте нового студента:" << endl << endl;
			N++;
			AddStudent(stud, N);
			break;
		case 2:
			system("cls");
			cout << "Выберите студента:" << endl << endl;
			int NStud;
			cin >> NStud;
			EditStudent(stud, NStud);
			break;
		case 3:
			system("cls");
			cout << "Данные о всех студентах:" << endl << endl;
			Info(stud, N);
			break;
		case 4:
			system("cls");
			cout << "Введите номер группы:  ";
			int numG;
			cin >> numG;
			func_4(stud, N, numG);
			break;
		case 5:
			system("cls");
			cout << "топа самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию:  " << endl;
			top(stud, N);
			break;
		case 6:
			system("cls");
			gender(stud, N);
			break;
		case 7:
			system("cls");
			stipend(stud, N);
			break;
		case 8:
			system("cls");
			funk_8(stud, N);
			break;
		case 9:
			system("cls");
			cout << "Введите номер студента в списке:  ";
			int numS;
			cin >> numS;
			studNum(stud, N, numS);
			break;
		case 10:
			system("cls");
			cout << "10.  Вывод всех записей, сделанных в день, который введет пользователь." << endl;
			time_day(stud, N);
			break;
		case 11:
			system("cls");
			cout << "11.  Вывод всех записей, сделанных после полудня." << endl;
			time_afternoon(stud, N);
			break;
		case 12:
			system("cls");
			cout << "12.  Вывод всех записей, сделанных до полудня." << endl;
			time_untilnoon(stud, N);
			break;
		case 0:
			break;
		}

	}
	
}

