//������������ ������ 1 + ���.������� (�������� ����������� �������� ������������ ���� �� 1 ��� 0 �� �������� ������������)

#include <iostream> 
#include <iomanip> //����������� ���������� ��� ������ setw()
using namespace std;



int main()
{
	setlocale(0, "");
	//1) �������, ������� ������ (� ������) �� ����� ���������� ��������� ��� ��������� ���� ������ �� ��������������� � ���: int, short int, long int, float, double, long double, char � bool. 

	cout << setw(12) << "int " << sizeof(int) << " �����" << endl;
	cout << setw(12) << "short int " << sizeof(short int) << " �����" << endl;
	cout << setw(12) << "long int " << sizeof(long int) << " �����" << endl;
	cout << setw(12) << "float " << sizeof(float) << " �����" << endl;
	cout << setw(12) << "double " << sizeof(double) << " ����" << endl;
	cout << setw(12) << "long double " << sizeof(long double) << " ����" << endl;
	cout << setw(12) << "char " << sizeof(char) << " ����" << endl;
	cout << setw(12) << "bool " << sizeof(bool) << " ����" << endl;

	//2) ������� �� ����� �������� ������������� � ������ (��� �������) ������ �����. ��� ������ ���������� ��������� ���������� �������� ������ � �������� ������� ��������� ��� ������. 

	int intNum;
	unsigned intMask = 1 << 31;
	int arr[32];

	cout << "������� ����� ���� int:  ";
	cin >> intNum;

	for (int i = 0; i < 32; i++) {
		if (i == 0) {
			putchar(intNum & intMask ? '1' : '0');
			cout << "  ";								//�������� �������� ���
		}
		else {
			putchar(intNum & intMask ? '1' : '0');
		}

		intNum <<= 1;
		if (intNum & intMask) { // ���������� �������� ������������� ����� � ������ ��� ��������������� �������
			arr[i] = 1;
		}
		else { arr[i] = 0; }
	}

	cout << endl;

	//���������� ������������� ����

	int numBit, znachBit;
	cout << "������� ����� ����:";
	cin >> numBit;
	cout << "������� �������� ���� 1/0:";
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

	//3) ������� �� ����� �������� ������������� � ������ (��� �������) ���� float. ��� ������ ���������� ��������� ���������� �������� ������ ��������, �������� ������ ������� (���� ����), �������� � �������. 

	union {
		float floatNum;
		int floatTool;
	};
	unsigned floatMask = 1 << 31;

	cout << "������� ����� ���� float:  ";
	cin >> floatNum;

	for (int i = 0; i < 32; i++) {
		if (i == 0 || i == 8) {
			putchar(floatTool & floatMask ? '1' : '0');
			cout << "  ";								//�������� �������� ���, ���������� � ��������
		}
		else {
			putchar(floatTool & floatMask ? '1' : '0');
		}

		floatTool <<= 1;
	}

	cout << endl;

	//4) ������� �� ����� �������� ������������� � ������(��� �������) ���� double.��� ������ ���������� ��������� ���������� �������� ������ ��������, �������� ������ �������(���� ����), �������� � �������.

	union {
		double doubleNum;
		int doubleTool[2];
	};

	unsigned doubleMask = 1 << 31;

	cout << "������� ����� ���� double:  ";
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