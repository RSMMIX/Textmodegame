#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y); printf(" <-0-> ");
}
void draw_bullet(int x, int y)
{
	gotoxy(x, y); printf("^");
}
void clear_bullet(int x, int y)
{
	gotoxy(x, y); printf(" ");
}
int randrange(int start, int stop)
{
	return (rand() % (stop - start + 1)) + start;
}
char cursor(int x, int y) 
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];

}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
int main()
{
	srand(time(NULL));
	char ch = '.';
	int x = 38, y = 20;
	int bx, by, i;
	int bullet = 0;
	int score = 0;
	setcursor(0);
	draw_ship(x, y);
	for (int i = 0; i < 20; i++)
	{
		gotoxy(randrange(10, 70), randrange(2,5));
		printf("*");
	}
	do {
		gotoxy(70, 0);
		printf("score : %d", score);
		if (_kbhit()) 
		{
			ch = _getch();
			if (ch == 'a') { draw_ship(--x, y); }
			if (ch == 's') { draw_ship(++x, y); }
			if (bullet != 1 && ch == ' ') { bullet = 1; bx = x + 3; by = y - 1; }
			fflush(stdin);
		}
		if (bullet == 1) {
			Beep(700, 100);
			clear_bullet(bx, by);
			if (cursor(bx, by - 1) == '*') 
			{ 
				bullet = 0; 
				gotoxy(bx, by - 1);
				printf(" ");
				gotoxy(randrange(10, 70), randrange(2, 5));
				printf("*");
				Beep(300, 100);
				score++;
			}
			else if (by == 2)
			{
				bullet = 0;
			}
			else 
			{ 
				draw_bullet(bx, --by); 
			}

		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}