#include "BinIO.h"
void SaveFile(string filename, players user)
{
	ofstream fileout;
	fileout.open(filename, ios::binary | ios::app);
	if (!fileout.good())
	{
		return;
	}
	fileout.write((char*)&user, 38);
	fileout.close();
}
void LoadFile(string filename, players user)
{
	SetColor(15);
	LoadandDrawAscii("Leaderboard_logo.txt", 20, 10, 2);
	int numlst = 1;
	ifstream filein;
	filein.open(filename, ios::binary | ios::in);
	filein.seekg(0, ios::end);
	int num = filein.tellg() / 38;
	filein.seekg(0, ios::beg);
	players* ptr = new players[num];
	for (int i = 0; i < num; i++)
	{
		filein.read((char*)&ptr[i], 38);
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (ptr[i].point <= ptr[j].point)
			{
				players temp;
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
	
	if (num > 7)
	{
		num--;
	}
	LoadandDrawAscii("Trophy_1.txt", 20, 1, 12);
	LoadandDrawAscii("Pokeball.txt", 20, 75, 12);
	GoToXY(42, 10);
	cout << "TOP 7 PLAYERS !!!" << endl;
	GoToXY(42, 12);
	cout << "NAME WITH SCORES" << endl;
	for (int i = 0; i < num; i++)
	{
		GoToXY(42, 14 + 2*i);
		cout << numlst << " ";
		numlst++;
		cout << ptr[i].name << " (";
		cout << ptr[i].point << ")";
	
	}

	delete[]ptr;
	filein.close();
	char c;
	c = _getch();
	if (c == Enter)
		return;
}