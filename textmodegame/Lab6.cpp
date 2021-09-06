#include<stdio.h>
/*#include<windows.h>
#include<conio.h>
struct Bullet
{
	int x = 0, y = 0;
	bool isOn = false;
};
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y); printf(" <-0-> ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void draw_bullet(int x , int y)
{
	gotoxy(x, y); printf("   *   ");
}
void erase_bullet(int x, int y)
{
	gotoxy(x, y);
	printf("       ");
}
int main()
{
	setcursor(false);
	setcolor(7, 0);
	char ch = '.';
	int x = 38, y = 20;
	draw_ship(x, y);
	int direction = 0;
	const int bc = 5;
	Bullet bs[bc];
	do {
		if (_kbhit()) //ตรวจสอบการกดปุ่ม
		{
			ch = _getch();
			if (ch == 'a') { direction = 1; }
			if (ch == 'd') { direction = 2; }
			if (ch == 's') { direction = 0; }
			if (ch == ' ') 
			{
				for (size_t i = 0; i < bc; i++)
				{
					if (!bs[i].isOn) 
					{
						bs[i].isOn = true;
						bs[i].x = x;
						bs[i].y = y;
						break;
					}
				}
			}
			fflush(stdin);
		}
		for (size_t i = 0; i < bc; i++)
		{
			erase_bullet(bs[i].x , bs[i].y);
			if (bs[i].isOn && bs[i].y > 0)
			{
				draw_bullet(bs[i].x, --bs[i].y);
			}
			else
			{
				bs[i].isOn = false;
			}
		}
		if (direction == 1 && x > 0)
		{
			draw_ship(--x, y);
		}
		else if (direction == 2 && x < 80)
		{
			draw_ship(++x, y);
		}
		else
		{
			draw_ship(x, y);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}*/