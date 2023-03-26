#include "InterfaceMenu_1.h"

void HideScrollBar() 
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    GetConsoleScreenBufferInfo(console, &screenBufferInfo);

    COORD new_screen_buffer_size;

    new_screen_buffer_size.X = screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1;
    new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1;

    SetConsoleScreenBufferSize(console, new_screen_buffer_size);
}

// Set color 
// Ref:  https://www.phanxuanchanh.com/2021/01/08/lap-trinh-c-c-doi-mau-console/
void SetColor(int color)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}
// Ref: https://tuicocach.com/viet-ham-thay-doi-mau-chu-trong-man-hinh-console-c-c/
void TextColor(int x)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

// Control the Cursor
// Ref:  https://tuicocach.com/tao-chuyen-dong-co-ban-trong-console-c-c-dieu-khien-chuyen-dong/
void GoToXY(int x, int y)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD a = { x, y };
    // Set Position of Cursor
    SetConsoleCursorPosition(h, a);
}


void setWindowSizeAndPos()
{
    HWND console1 = GetForegroundWindow();
    MoveWindow(console1, 200, 50, WINDOWSWIDTH, WINDOWSHEIGHT, TRUE);
}

void HideCursor(bool visible) 
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}

// Ref: https://codelearn.io/sharing/windowsh-va-ham-dinh-dang-console-p1
void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}

void CreateWindows()
{
    setWindowSizeAndPos();
    SetConsoleTitle(L"Pikachu");
    HideCursor(0);
    DisableCtrButton(1, 1, 1);
    HideScrollBar();
    
}
void HighLightMenuBar(int x, int y)
{
    SetColor(10);
    if (y == 16)
    {
        GoToXY(x, y);
        cout << "        PLAY GAME      ";
    }

    else if (y == 18)
    {
        GoToXY(x, y);
        cout << "       LEADERBOARD      ";
    }

    else if (y == 20)
    {
        GoToXY(x, y);
        cout << "         CREDITS        ";
    }
    else if (y == 22)
    {
        GoToXY(x, y);
        cout << "        EXIT GAME     ";
    }
    SetColor(9);
}
void NoHighlightMenuBar(int x, int y)
{
    SetColor(11);
    if (y == 16)
    {
        GoToXY(x, y);
        cout << "        PLAY GAME      ";
    }
    
    else if (y == 18)
    {
        GoToXY(x, y);
        cout << "       LEADERBOARD      ";
    }
    
    else if (y == 20)
    {
        GoToXY(x, y);
        cout << "         CREDITS        ";
    }
    else if (y == 22)
    {
        GoToXY(x, y);
        cout << "        EXIT GAME     ";
    }
    SetColor(9);

}

void LoadandDrawAscii(string filename, int line, int x, int y)
{
    ifstream filein;
    filein.open(filename);
    string* ptr = new string[line];
    for (int i = 0; i < line; i++)
    {
        getline(filein, ptr[i]);
    }
    filein.close();
    // Draw
    for (int i = 0; i < line; i++)
    {
        GoToXY(x, y);
        cout << ptr[i] << endl;
        y++;
    }
    delete[] ptr;
}
int CreateMenuGame()
{
        NoHighlightMenuBar(40, 16);
        NoHighlightMenuBar(40, 18);
        NoHighlightMenuBar(40, 20);
        NoHighlightMenuBar(40, 22);
        LoadandDrawAscii("Logo.txt", 15, 30, 5);
        LoadandDrawAscii("Onix.txt", 15, 1, 11);
        LoadandDrawAscii("Pikachu.txt", 15, 75, 13);
        bool check = true;
        int Key_y = 16, Key_x = 40;
        int Pre_y = 16;
        // Choose option
        // Ref: https://www.youtube.com/watch?v=UjQIwlr_DqI
        while (true)
        {
           // GoToXY(Key_x, Pre_y);
            // Check pressed button
            if (check == true)
            {
                GoToXY(Key_x, Pre_y);
                NoHighlightMenuBar(40, Pre_y); 
                Pre_y = Key_y;
                HighLightMenuBar(40, Key_y); 
                check = false; 
            }
            
            if (_kbhit())
            {
                char key = _getch();
                if (key == -32)
                {
                    check = true;
                    key = _getch();
                    if (key == UP && Key_y != 16)
                    {
                        Key_y -= 2;
                    }
                    else if (key == DOWN && Key_y != 22)
                    {
                        Key_y += 2;
                    }
                }
                    else if (key == 13)
                    {
 
                        if (Key_y == 16)
                            return 1;
                        if (Key_y == 18)
                            return 2;
                        if (Key_y == 20)
                            return 3;
                        if (Key_y == 22)
                            return 0;  
                    }
            }
        }
}
