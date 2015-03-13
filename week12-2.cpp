#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#define SIZE 4 // Чтобы сайз всегда был 4
using namespace std;
enum moveKey{ KeyUp = 'w', KeyLeft = 'a', KeyRight = 'd', KeyDown = 's' };//создали свой тип данных moveKey
void printTable(char arr[SIZE][SIZE]); //ф. печати таблицы с параметром, принимающим 2-мерный массив 4х4
void initTable(char arr[SIZE][SIZE]);//ф. инициализации таблицы с параматером, принимающим 2-мерн. массив 4х4
void randTable(char arr[SIZE][SIZE], int numStep);// перемешивает таблицу, с параметрами (2-мерн.м., интовая переменная)
void makeMove(char arr[SIZE][SIZE], moveKey key); // ф. (2-мерн.м., тип moveKey переменная)
void locateSpace(int &row, int &col, char arr[SIZE][SIZE]); //ф. (интовый адрес строки, интовый адрес столбца, чароый 2-м. м. 4х4)
bool userWin(char arr[SIZE][SIZE]);//бул.(чаровый м. 4х4)
void main()
{
	char table[SIZE][SIZE];//создаем 2мерн. м. 4х4
	initTable(table);//вызов ф. с аргументом table, т.е. таблица на строчку выше
	randTable(table, 40);//перемешивать(таблица, 40 - шоб лучше мешалось)
	while (true)//бесконечный цикл
	{
		printTable(table);//ф. печати табл. с аргументом созданной таблицы
		int move = getch();//ожидает нажатия клавиши, после которого она немедленно возвращает значение. Причем, символ, 
							//введенный с клавиатуры, на экране не отображается.
		makeMove(table, (moveKey)move);//вызываем ф. (2х2 табл., приведенная к типу moveKey переменная move)
		move = 0; //move обнуляю
		if (userWin(table)) //если пользователь выиграл(аргумент - таблица)
		{
			break;//выход
		}
	}
	cout << "WIN!!!" << endl; //вывести надпись о победе

}
bool userWin(char arr[SIZE][SIZE])//бул. ф. с арг. таблица 2х2
{
	int inc = 0;//создали перем. int и инициализировали 0
	char temp[SIZE][SIZE] = {//чаровая ф. с табл. 2х2
		{ '1', '2', '3', '4' },
		{ '5', '6', '7', '8' },
		{ '9', 'A', 'B', 'C' },
		{ 'D', 'E', 'F', ' ' },
	};
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] == temp[i][j])//если элемент в таблице равен элементу во временной таблице
			{
				inc++;//в сумму записываем ходы.
			}
		}
	}
	if (inc == SIZE*SIZE)//если inc равно количеству элементов во всей табл. 16
	{
		return true;//1
	}
	else{
		return false;
	}
}
void initTable(char arr[SIZE][SIZE])
{
	const char temp[SIZE][SIZE] = {
		{ '1', '2', '3', '4' },
		{ '5', '6', '7', '8' },
		{ '9', 'A', 'B', 'C' },
		{ 'D', 'E', 'F', ' ' },
	};
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = temp[i][j];
		}
	}
}
void printTable(char arr[SIZE][SIZE])
{
	system("cls");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}
void randTable(char arr[SIZE][SIZE], int numStep)
{
	srand(time(NULL));
	for (int i = 0; i < numStep; i++)
	{
		int move = rand() % 4;
		switch (move)
		{
		case 0:
			makeMove(arr, KeyUp);
			break;
		case 1:
			makeMove(arr, KeyDown);
			break;
		case 2:
			makeMove(arr, KeyLeft);
			break;
		case 3:
			makeMove(arr, KeyRight);
			break;
		default:
			break;
		}
	}
}
void locateSpace(int &row, int &col, char arr[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] == ' ')
			{
				row = i;
				col = j;
				return;
			}
		}
	}
}
void makeMove(char arr[SIZE][SIZE], moveKey key)
{
	int rowsSpace;
	int colSpace;
	locateSpace(rowsSpace, colSpace, arr);
	int rowCurrent = rowsSpace;//начальные данные пробела
	int colCurrent = colSpace;
	switch (key)
	{
	case KeyUp:
	{
				  rowCurrent -= 1;
	}
		break;
	case KeyLeft:
	{
					colCurrent -= 1;
	}
		break;
	case KeyRight:
	{
					 colCurrent += 1;
	}
		break;
	case KeyDown:
	{
					rowCurrent += 1;
	}
		break;
	}
	if (rowCurrent >= 0 && rowCurrent<SIZE && colCurrent >= 0 && colCurrent<SIZE)//меняем местами пробел и выбраный элемент
	{
		char temp = arr[rowCurrent][colCurrent];
		arr[rowCurrent][colCurrent] = arr[rowsSpace][colSpace];
		arr[rowsSpace][colSpace] = temp;
	}
}
