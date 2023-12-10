#include "graphics.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>                     // Provides exit
#include <ctype.h>  
#include "Board.h"
#include <cstdio>
#include "Position.h"
#include "Board4.h"
#include "Board2.h"
#include "Board6.h"
// Provides toupper
using namespace std;


void flood_fill(int x, int y, int newColor, int oldColor)
{
	int c;
	c = getpixel(x, y);
	if (c == oldColor)
	{
		setcolor(newColor);
		putpixel(x, y, newColor);
		flood_fill(x + 1, y, newColor, oldColor);
		flood_fill(x, y + 1, newColor, oldColor);
		flood_fill(x - 1, y, newColor, oldColor);
		flood_fill(x, y - 1, newColor, oldColor);
	}
}
void screen()
{
	setcolor(15);
	int i = 0, x, y, j;
	rectangle(20, 20, 660, 680);
	rectangle(10, 10, 670, 690);
	line(30, 30, 60, 30);//L//
	line(30, 30, 30, 160);
	line(60, 30, 60, 160);
	line(30, 160, 60, 160);
	flood_fill(45, 85, 1, 0);
	setcolor(15);
	line(30, 160, 160, 160);
	line(30, 190, 160, 190);
	line(30, 160, 30, 190);
	line(160, 160, 160, 190);
	flood_fill(95, 175, 1, 0);//L//
	setcolor(15);
	rectangle(200, 30, 230, 160);//u//
	rectangle(200, 160, 330, 190);
	rectangle(300, 30, 330, 160);
	flood_fill(201, 31, 2, 0);
	flood_fill(201, 161, 2, 0);
	flood_fill(301, 31, 2, 0);//u//
	setcolor(15);
	rectangle(370, 30, 400, 190);
	ellipse(400, 110, -90, -270, 80, 80);
	flood_fill(371, 110, 14, 0);
	setfillstyle(3, 14);
	floodfill(401, 31, 15);
	setfillstyle(1, 4);
	setcolor(15);
	ellipse(580, 110, 0, 360, 60, 80);
	ellipse(580, 110, 0, 360, 30, 50);
	floodfill(545, 111, 15);
	setfillstyle(3, 3);
	floodfill(505, 111, 15);
	floodfill(580, 110, 15);
	setcolor(15);
	settextstyle(0, HORIZ_DIR, 1000);
	outtextxy(240, 340, "Wellcome to Ludo!");
	setcolor(15);
	rectangle(275, 370, 390, 410);
	outtextxy(280, 380, "  Rules  ");//coordinates will be( x>=275&&x<=410 )&& (y>=370 && y<=390)
	rectangle(275, 420, 390, 460);
	outtextxy(280, 430, "2-Players");//coordinates will be( x>=275&&x<=410 )&& (y>=420 && y<=460)
	rectangle(275, 470, 390, 510);
	outtextxy(280, 480, "4-Players");//coordinates will be( x>=275&&x<=410 )&& (y>=470 && y<=510)
	rectangle(275, 520, 390, 560);
	outtextxy(280, 530, "6-Players");//coordinates will be( x>=275&&x<=410 )&& (y>=520 && y<=560)
	setcolor(5);
	setfillstyle(1, 5);
	floodfill(11, 11, 15);
	setcolor(15);
}
void Rulesscreen()
{
	setcolor(15);
	settextstyle(0, HORIZ_DIR, 1000);
	setfillstyle(2, 5);
	rectangle(20, 20, 660, 680);
	rectangle(10, 10, 670, 690);
	floodfill(505, 111, 15);
	setfillstyle(3, 3);
	floodfill(505, 111, 15);
	outtextxy(318, 40, "Rules");
	outtextxy(30, 80, "1.Donot try to cheat because you cant (HEHE):p");
	outtextxy(30, 120, "2.If all your pieces have completed the board tour,");
	outtextxy(30, 160, "You win!!:)");
	outtextxy(30, 200, "3.If another piece lands on your piece, Your piece");
	outtextxy(30, 240, "is killed!:(");
	outtextxy(30, 280, "4.Kill your opponents to win easy!! XD");
	outtextxy(30, 320, "Good Luck");
	rectangle(275, 370, 390, 410);
	outtextxy(280, 380, " Return ");//coordinates will be( x>=275&&x<=410 )&& (y>=370 && y<=390)
	setfillstyle(1, 5);
	floodfill(11, 11, 15);
	
	/*readimagefile("Desktop:\ye.png", 10, 100, 325, 325);
	printimage("Desktop:\ye.png", 10, 100, 325, 325);*/
}


Position selectPosition()
{
	int x, y;

	Position p;

	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, x, y);

	p.r = y;
	p.c = x;
	return p;
	
}

#include<iostream>
#include<cstdio>
int main()
{
	
	initwindow(1000,1000, "Ludo");
	int nop=4;
	screen();
	Position p = selectPosition(); int x = p.c, y = p.r;
	if ((x >= 275 && x <= 410) && (y >= 370 && y <= 410))
	{
		cleardevice();
		Rulesscreen();
		Position P = selectPosition();
		if ((P.c >= 275 && P.c <= 410) && (P.r >= 370 && P.r <= 410))
		{
			cleardevice();
			screen();
		}
		P = selectPosition();  x = P.c, y = P.r;
	}

	if ((x >= 275 && x <= 410) && (y >= 420 && y <= 460))
		nop = 2;
	if ((x >= 275 && x <= 410) && (y >= 470 && y <= 510))
		nop = 4;
	if ((x >= 275 && x <= 410) && (y >= 520 && y <= 560))
		nop = 6;
	//cin >> nop;
	cleardevice();
	Board* B;

	switch (nop)
	{
	case 2:
		B = new Board2;
		B->PrintBoard();
		break;
	case 4:
		B = new Board4;
		B->PrintBoard();
		break;
	case 6:
		B = new Board6;
		B->PrintBoard();
		break;
	}
	/*while (true)
	{
		Position pos = selectPosition();
		cout << "";
	}*/
	/*Dice D;
	D.ShowScore();*/
	



	B->Play();


	/*while (!kbhit());*/

	return 0;
	
	
}

void main1()
{
	initwindow(500, 500, "First Sample");
	int i = 0;
	int c = 4;
	
	//while (i<=12)
	{
		system("cls");
		cout << i;
		setcolor(c);
		circle(50,50,50);
		setfillstyle(13, c);
		floodfill(50,50, c);
		
		while (!kbhit())
		{
		}
		/*getch();
		i++;*/
	}
}





