#include <iostream>
#include <string.h>
using namespace std;


static int x; /* 0 по умолчанию, существует всё время выполнения */
static int x2 = 45; /* 45, существует всё время выполнения */
int x3;

static int y;
static int y2 = 46; /* 45, существует всё время выполнения */
int y3;

int cnt(void)
{
	static int i;/*статический тип, инициализируется нулём только при запуске
		программы, а не каждый вызов функции */
	cout << "Address i = " << &i << "	Value i = " << i << endl;

	int j;/*автоматический тип, инициализируется каждый раз
				при вызове функции -1*/
	cout << "Address j = " << &j << "	Value i = " << j << endl;
	i++;/* увеличивается на 1 в статической области памяти каждый запуск функции*/
	j++;/* увеличивается на 1 локальная переменная */
	return (i + j);/*при первом вызове с запуска программы функция вернёт 1,
		при втором вызове 2, ... */
}

int main(void) {

	setlocale(LC_ALL, "rus");

	char arr[50] = "This is object of automatic storage duration";
	/* имеет автоматический тип,существует до выхода из main,
	начальные 45 элементов массива инициализированы элементами
	строки с закрывающим нулём, остальные не определены */
	char line[] = "Simple line"; /*автоматический тип, существует до выхода
	из main, line инициализирован указателем на константу */

	int z; /* значение не определено, существует до выхода из main*/
	int z2 = 10; /* значение определено, существует до выхода из main*/
	char* ptr; /* значение указателя не определено */
	ptr = new char[50]; /* значение по указателю не определено,
					объект по указателю существует до вызова free */
	strcpy(ptr, arr);

	cout << "Address x1 = " << &x << "	Value x1 = " << x << endl;
	cout << "Address x2 = " << &x2 << "	Value x2 = " << x2 << endl;
	cout << "Address x3 = " << &x3 << "	Value x3 = " << x3 << endl;
	cout << "Address y1 = " << &y << "	Value y1 = " << y << endl;
	cout << "Address y2 = " << &y2 << "	Value y2 = " << y2 << endl;
	cout << "Address y3 = " << &y3 << "	Value y3 = " << y3 << endl;

	cnt();

	delete [] ptr;

	getchar();

	return 0;

}
