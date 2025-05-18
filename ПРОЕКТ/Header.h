#include <iostream> 
#include <windows.h>
#include <conio.h>
using namespace std;

enum Color : short { // ����� ������
	BLACK, DARKBLUE, DARKGREEN, TURQUOISE, DARKRED,
	PURPLE, DARKYELLOW, GREY, DARKGREY, BLUE, GREEN,
	CYAN, RED, PINK, YELLOW, WHITE
};

enum Key : short { // ���� ������
	LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80,
	ENTER = 13, SPACE = 32, ESCAPE = 27, BACKSPACE = 8
};

void APPLE_SETUP(const int* width, const int* height, int* X_apple, int* Y_apple, int* array_X, int* array_Y, int* length) {
	do // ���� ������ ���������� ������ �������� ������� - �� ����� ��� �� ��������� �� "�������"
	{
		*X_apple = rand() % (*width - 2) + 1;
		*Y_apple = rand() % (*height - 2) + 1;
	} while (*X_apple != array_X[*length - 1] && *Y_apple != array_Y[*length - 1]);
}

void DRAWING_FRAME(const int* height, const int* width, HANDLE h) {
	SetConsoleTextAttribute(h, 4); // ��������� �����, ������� �������� ����� ����
	for (int y = 0; y < *height; y++) // ����������� ������� ���� �� ��������� �����
	{
		for (int x = 0; x < *width; x++)
		{
			char s;
			if (x == 0 && y == 0) // � ������� ����� ���� ���� - ������ ���������������� ����
				s = '#'; // 218
			else if (x == 0 && y == *height - 1) // ������ ����� ����
				s = '#'; // 192
			else if (y == 0 && x == *width - 1) // ������� ������ ����
				s = '#'; // 191
			else if (y == *height - 1 && x == *width - 1) // ������ ������ ����
				s = '#'; // 217
			else if (y == 0 || y == *height - 1) // ������� � ������ ������� ����
				s = '#'; // 196
			else if (x == 0 || x == *width - 1) // ����� � ������ ������� ����
				s = '#'; // 179
			else s = ' '; // �� ���� ��������� ������� ������ ���� ������ ������ (�������� ������ ������� ����)
			cout << s; // ������� ������
		}
		cout << "\n";
	}
}

void INFO_PANEL(COORD& info_panel, HANDLE h, int max_length, int length, int width) {
	SetConsoleOutputCP(1251);
	info_panel.X = width + 5;
	info_panel.Y = 0;
	SetConsoleCursorPosition(h, info_panel);
	SetConsoleTextAttribute(h, Color::RED);
	cout << "������������ ����� ������: ";
	SetConsoleTextAttribute(h, Color::WHITE);
	cout << max_length;

	info_panel.Y = 2;
	SetConsoleCursorPosition(h, info_panel);
	SetConsoleTextAttribute(h, Color::RED);
	cout << "�������� ����� ������: ";
	SetConsoleTextAttribute(h, Color::WHITE);
	cout << length;
	SetConsoleOutputCP(866);
}

void UPDATE_LENGTH(COORD info_panel, HANDLE h, int length, int width) {
	info_panel.X = width + 5;
	info_panel.Y = 2;
	SetConsoleCursorPosition(h, info_panel);
	SetConsoleTextAttribute(h, Color::RED);
	SetConsoleOutputCP(1251);
	cout << "�������� ����� ������: ";
	SetConsoleOutputCP(866);
	SetConsoleTextAttribute(h, Color::WHITE);
	cout << length;
	SetConsoleTextAttribute(h, Color::GREEN);
}



void GAME_OVER(HANDLE h) {
	// ������� ������� � ����� �������
	SetConsoleOutputCP(1251); // ��������� ������� �������� ��� ����������� ����������� ���������
	system("cls"); // ������� ������� 

	COORD game_over; // �������� ������� ��� �������� ���������
	game_over.X = 52;
	game_over.Y = 15;

	SetConsoleCursorPosition(h, game_over); // ��������� ������� � �������� ����������
	SetConsoleTextAttribute(h, Color::RED); // ��������� ����� ������
	cout << "���� ��������!\n";
	_getch(); // �������� ������� �������
}