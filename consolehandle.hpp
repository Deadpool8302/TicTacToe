#pragma once

/*
    gotoxy(short, short) and clrscr() were predefined functions in conio.h header file in older versions of c++.
    Since they are no longer available in modern versions of c++.
    I have used raw code of those functions (not coded by me)

    conio.h is included for _getch() function.
    _getch() takes a character as an input as soon as user presses a keyboard key.
    Depending on the OS and the version of C++ name of this function may vary like getch(), _getch()
*/

void gotoxy(short x, short y);

void clrscr();