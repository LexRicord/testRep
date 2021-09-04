#define _CRT_SECURE_NO_WARNINGS
#include <iostream>   
#include <windows.h>

# define date_len 11
# define str_len 50                             
# define size 30  
FILE* file1;
FILE* file;
errno_t err;
using namespace std;
struct CLIENT enter_new();
void del();
void out();
void search();
void input();
void output();

struct CLIENT
{
	char name[str_len];
	char arrDate[date_len];
	char depDate[date_len];
	char room[date_len];
	char typeOfAlloc[str_len];
};
struct CLIENT listOfCli[size];
struct CLIENT bad;
struct CLIENT change[1];
struct CLIENT* ctr = &listOfCli[0];

int currentSize = 0;
int choice;
int check = 0;
int current_check = 0, current_checkName = 0;
int buf = 0;

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	cout << "Введите:" << endl;
	cout << "1-для ввода новой записи" << endl;
	cout << "2-для удаления записи" << endl;
	cout << "3-для вывода записи(ей)" << endl;
	cout << "4-для поиска информации" << endl;
	cout << "5-запись в файл" << endl;
	cout << "6-чтение из файла" << endl;
	cout << "0-для выхода" << endl;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:  enter_new();	break;
		case 2:  del();  break;
		case 3:  out();	break;
		case 4:  search();	break;
		case 5:  input(); 	break;
		case 6:	 output();	break;
	
		case 0:  break;
		}
	} while (choice != 0);
}

struct CLIENT enter_new()
{
	cout << "Ввод информации" << endl;
	if (currentSize < size)
	{
		cout << "Строка номер ";
		cout << currentSize + 1;
		cout << endl << "ФИО Клиента: ";
		cin.ignore();
		cin.getline(listOfCli[currentSize].name, 50);
		cout << endl << "Дата прибытия: ";
		cin >> listOfCli[currentSize].arrDate;
		cout << endl << "Дата отбытия: ";
		cin >> listOfCli[currentSize].depDate;
		cout << endl << "Номер комнаты: ";
		cin >> listOfCli[currentSize].room;
		cout << endl << "Тип размещения: ";
		cin >> listOfCli[currentSize].typeOfAlloc;
		currentSize++;
	}
	else
	{
		cout << "Введено максимальное кол-во строк";
	}

	do
	{
		check = 0;
		for (int i = 0; i < currentSize - 1; i++)
		{
			if (strcmp(listOfCli[i].depDate, listOfCli[i + 1].depDate) > 0)
			{
				change[1] = listOfCli[i];
				listOfCli[i] = listOfCli[i + 1];
				listOfCli[i + 1] = change[1];
				check++;
			}
		}
	} while (check > 0);

	do
	{
		check = 0;
		for (int i = 0; i < currentSize - 1; i++)
		{
			if (strcmp(listOfCli[i].depDate, listOfCli[i + 1].depDate) == 0)
			{
				if (strcmp(listOfCli[i].name, listOfCli[i + 1].name) > 0)
				{
					change[1] = listOfCli[i];
					listOfCli[i] = listOfCli[i + 1];
					listOfCli[i + 1] = change[1];
					check++;
				}
			}
		}
	} while (check > 0);
	cout << "Что дальше?" << endl;
	cin >> choice;
	struct CLIENT* ctr = &listOfCli[0];
	return *ctr;
}

void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < currentSize; de1++)
			listOfCli[de1] = listOfCli[de1 + 1];
		currentSize = currentSize - 1;
		current_check--;
	}
	if (d == 99)
	{
		current_check--;
		for (int i = 0; i < size; i++)
			listOfCli[i] = bad;
	}

	cout << "Что дальше?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-вывод 1 стоки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;

	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << endl << "\nФИО Клиента      Дата прибытия           Дата отбытия            Номер комнаты            Тип размещения\n";
		cout << listOfCli[n - 1].name << "\t\t          " << listOfCli[n - 1].arrDate << "\t\t           " << listOfCli[n - 1].depDate << "\t\t            " << listOfCli[n - 1].room << "\t\t            " << listOfCli[n - 1].room << endl;
	}
	if (sw == 2)
	{
		cout << endl << "\nФИО Клиента      Дата прибытия           Дата отбытия            Номер комнаты            Тип размещения\n";
		for (int i = 0; i < currentSize; i++)
		{

			cout << listOfCli[i].name << "\t\t          " << listOfCli[i].arrDate << "\t\t           " << listOfCli[i].depDate << "\t\t            " << listOfCli[i].room << "\t\t            " << listOfCli[i].room << endl;
		}
	}
	cout << endl << endl;
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void search()
{
		int choose; int none = 0; struct CLIENT searching[1];
		printf("Введите ФИО клиента: ");
		cin.ignore();
		cin.getline(searching[0].name, 30);
		cout << endl << "\nФИО Клиента      Дата прибытия           Дата отбытия            Номер комнаты            Тип размещения\n";
		for (int i = 0; i < currentSize; i++)
		{
			if (strcmp(searching[0].name, listOfCli[i].name) == 0)
			{
				cout << listOfCli[i].name << "\t\t          " << listOfCli[i].arrDate << "\t\t           " << listOfCli[i].depDate << "\t\t            " << listOfCli[i].room << "\t\t            " << listOfCli[i].room << endl;
				none++;
			}
		}
		if (none == 0)
		{
			printf("Не было найдено ни одной записи\n");
		}
		cout << "Что дальше?" << endl;
}

void input()
{
	
	struct CLIENT buf = { ' ', ' ', ' ', ' ', ' '};
	if (!fopen_s(&file, "file.txt", "ab"))
	{
		fputs("\nФИО Клиента      Дата прибытия           Дата отбытия            Номер комнаты            Тип размещения\n", file);
		cout << "Текущая строка:"; cout << currentSize + 1;
		cout << "\nФИО Клиента: "; cin >> buf.name;
		cout << "\nДата прибытия: "; 	cin >> buf.arrDate;
		cout << "\nДата отбытия: "; 	cin >> buf.depDate;
		cout << "\nНомер комнаты: "; 	cin >> buf.room;
		cout << "\nТип размещения: "; 	cin >> buf.typeOfAlloc;
		listOfCli[currentSize] = buf;
		fwrite(&buf, sizeof(buf), 1, file);
		currentSize++;
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
	fclose(file);
	cout << "Что дальше?" << endl;
}
void output()
{
	struct CLIENT buf = { ' ', ' ', ' ', ' ', ' ' };
	int size_Of = 29;
	if (!fopen_s(&file1, "file1.bin", "rb"))
	{
		cout << "\nФИО Клиента      Дата прибытия           Дата отбытия            Номер комнаты            Тип размещения\n";
		//fread(&buf, sizeof(buf), 1, file1);
		while (!feof(file1))
		{
			fread(&buf, size_Of, 1, file1);
			listOfCli[currentSize] = buf;
			cout << buf.name << "\t     " << buf.arrDate << "\t    " << buf.depDate << "\t            " << buf.room << "\t        " << buf.typeOfAlloc << endl;
		}
		cout << endl;
		fclose(file1);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}

	cout << "Что дальше?" << endl;
	
}
