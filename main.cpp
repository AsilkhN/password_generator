//
//
// PASSWORD GENERATOR
//
//
#ifdef _WIN32
#include <windows.h>
void clear_c(char fill = ' ') {
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}
void sleep_3() {
	Sleep(3000);
}
#else
#include <unistd.h>
void clear_c()
{
	write(1, "\E[H\E[2J", 7);
}
void sleep_3() {
	sleep(3);
}
#endif
#include <vector>
#include <iostream>
#include <time.h>

int main()
{
	int passwLength = 0;
	char randomPassw;
	char* exit = new char;

	do {
		std::cout << "input password length( >=10 ):";
		srand(time(0));
		std::cin >> passwLength; std::cout << std::endl;
		if (passwLength < 10) {
			std::cout << "\nThe length of your password must be at least 10\n\n";
			sleep_3();
		}
		else {
			for (int i = 0; i < passwLength; i++) {
				randomPassw = 48 + rand() % (122 - 48);
				std::cout << randomPassw;
			}
			std::cout << std::endl;
			std::cout << "\nIf you plan to use this password, please save it somewhere.\n";

			//EXIT FORM THE PROGRAM
			std::cout << "Do you want to continue? (y/n):";
			std::cin >> *exit; std::cout << std::endl;
		}

		clear_c();

	} while (*exit != 'n');
	delete exit;
}

