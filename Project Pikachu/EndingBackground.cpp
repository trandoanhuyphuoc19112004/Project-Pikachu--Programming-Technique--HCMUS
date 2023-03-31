#include "EndingBackground.h"
int LoseBackGround(players& player)
{
	system("cls");
	// Ref: https://pixabay.com/sound-effects/dead-8bit-41400/
	PlaySound(TEXT("Losemusic.wav"), NULL, SND_FILENAME | SND_ASYNC);
	SetColor(11);
	LoadandDrawAscii("LoseBG.txt", 15, 20, 3);
	GoToXY(40, 16);
	cout << "KEEP UP THE GOOD WORK!";
	GoToXY(40, 18);
	cout << "Name:" << player.name;
	GoToXY(40, 20);
	cout << "Point:" << player.point;
	GoToXY(40, 22);
	cout << "Press any key to continue";
	char c;
	c = _getch();
	return 0;
}
int WinBackGround(players& player)
{
	system("cls");
	// Ref: https://pixabay.com/sound-effects/win-sfx-38507/
	PlaySound(TEXT("Winmusic.wav"), NULL, SND_FILENAME | SND_ASYNC);
	SetColor(11);
	LoadandDrawAscii("Winbackground.txt", 15, 2, 3);
	GoToXY(35, 14);
	cout << "LORD OF THE MATCHING GAME!";
	GoToXY(35, 16);
	cout << "Name:" << player.name;
	GoToXY(35, 18);
	cout << "Point:" << player.point;
	GoToXY(35, 20);
	cout << "Press any key to continue";
	char c;
	c = _getch();
	return 1;
}