/*
void Board_1::drawBackgroundCell(char bg[][65], int easyHeight, int easyWidth)
{
	setColor(7);
	for (int h = 0; h < cellHeight + 1; h++)
	{
		if (ci == easyHeight && h == cellHeight)
			break;
		gotoxy(x, y + h);
		for (int k = 0; k < 6; k++)
		{
			if (cj == easyWidth && k == cellWidth - 1)
				break;
			cout << bg[(ci - 1) * 4 + h][(cj - 1) * 6 + k];
		}
	}
}
*/

