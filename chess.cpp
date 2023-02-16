#include <iostream.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <fstream.h>

class chess {
	public:
		char board[8][8];
};

void init(){
	textbackground(BLACK);
	clrscr();
	textcolor(WHITE);
	cout<<"\n\n\t\t\t";
	cprintf("Welcome to Normal Chess");
	cout<<"\n\t\t\t\t";
	cprintf(":Rules:");
	cout<<"\n\t";
	cprintf("1. You can play this like normal chess tbh");
	cout<<"\n\t";
	cprintf("2. If you don't want to, you can chose to move your pieces");
	cout<<"\n\t";
	cprintf(" wherever you want :)");
	cout<<"\n\t";
	cprintf("3. Cut the king to exit this pointless game");
	cout<<"\n\t\t\t";
	cprintf("Press enter to continue...");
	cin.get();
	clrscr();
}

int exit(char cb[8][8]) {
	int bk=0,wk=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(cb[i][j]=='K')
			{
				bk=1;
			}
			else if(cb[i][j]=='k')
			{
				wk=1;
			}
		}
	}
	if(bk!=1||wk!=1)
		return 1;
	else
		return 0;
}

void makeBoard(char cb[8][8])
{
	textbackground(0);
	clrscr();
	textcolor(BLACK);
	for(int i=0;i<8;i++)
	{     if (i%2==0)
		 {
		for(int j=0;j<8;j++)
		{
			if(j%2==0)
			{
				textbackground(10);
				cprintf(" ");
				if(cb[i][j]!='0'){
					cprintf("%c",cb[i][j]);
				} else {
					cprintf(" ");
				}
			}
			else
			{
				textbackground(15);
				cprintf(" ");
				if(cb[i][j]!='0'){
					cprintf("%c",cb[i][j]);
				} else {
					cprintf(" ");
				}
			}
		}
		cout<<" "<<i+1<<endl;
		 }
		 else
		 {
		 for(int j=0;j<8;j++)
		{
			if(j%2!=0)
			{
				textbackground(10);
				cprintf(" ");
				if(cb[i][j]!='0'){
					cprintf("%c",cb[i][j]);
				} else {
					cprintf(" ");
				}
			}
			else

			{
				textbackground(15);
				cprintf(" ");
				if(cb[i][j]!='0'){
					cprintf("%c",cb[i][j]);
				} else {
					cprintf(" ");
				}
			}
		}
		cout<<" "<<i+1<<endl;
		 }
	}
	char a = 'A';
	char x;
	for(i=0;i<8;i++){
		x = a + i;
		cout<<" "<<x;
	}
}

void move(char cb[8][8]) {
	cout<<"\nEnter move\n";
	textcolor(WHITE);
	char a,b;
	int c,d;
	cin>>a>>c;
	cin>>b>>d;
	int posi[2], posf[2];
	a-=96;
	b-=96;
	posi[0]=c;
	posi[1]=int(a);
	posf[0]=d;
	posf[1]=int(b);
	if(posi[0]>8||posi[1]>8||posf[0]>8||posf[1]>8) {
		cout<<"\nBetween one and eight please\n";
		move(cb);
	}
	cb[posf[0]-1][posf[1]-1]=cb[posi[0]-1][posi[1]-1];
	cb[posi[0]-1][posi[1]-1]='0';

	//save in file

	fstream f1("chess.dat", ios::binary|ios::app);
	chess ab;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			ab.board[i][j]=cb[i][j];
		}
	}
	f1.write((char*)&ab, sizeof(ab));
	f1.close();

	if(exit(cb)==1) {
	textbackground(BLACK);
		clrscr();
		cout<<"bye";
	} else {
		makeBoard(cb);
		move(cb);
	}
}

void arf(char cb[8][8]) {
	//human
	cout<<"\nEnter move \n";
	textcolor(15);
	char a,b;
	int c,d;
	cin>>a>>c;
	cin>>b>>d;
	int posi[2], posf[2];
	a-=96;
	b-=96;
	posi[0]=c;
	posi[1]=int(a);
	posf[0]=d;
	posf[1]=int(b);
	if(posi[0]>8||posi[1]>8||posf[0]>8||posf[1]>8) {
		cout<<"\nBetween one and eight bro pls\n";
		arf(cb);

	}
	cb[posf[0]-1][posf[1]-1]=cb[posi[0]-1][posi[1]-1];
	cb[posi[0]-1][posi[1]-1]='0';
	//ai   :)
	posi[0]=random(8)+1;
	posi[1]=random(8)+1;
	posf[0]=random(8)+1;
	posf[1]=random(8)+1;
	cb[posf[0]-1][posf[1]-1]=cb[posi[0]-1][posi[1]-1];
	cb[posi[0]-1][posi[1]-1]='0';
	char u = cb[posf[0]-1][posf[1]-1];
	char f = posi[1]+96;
	char g = posf[1]+96;
	//check if king dead
	if(exit(cb)==1) {
		textbackground(0);
		clrscr();
		cout<<"bye";
	} else {
		makeBoard(cb);
		cout<<"\nAI has moved "<<u<<f<<posi[0]<<" to "<<u<<g<<posf[0]<<endl;
		delay(1500);
		arf(cb);
	}

}

void aivai(char cb[8][8]) {
	int posi[2], posf[2];
	posi[0]=random(8)+1;
	posi[1]=random(8)+1;
	posf[0]=random(8)+1;
	posf[1]=random(8)+1;
	cb[posf[0]-1][posf[1]-1]=cb[posi[0]-1][posi[1]-1];
	cb[posi[0]-1][posi[1]-1]='0';
	char u = cb[posf[0]-1][posf[1]-1];
	char f = posi[1]+96;
	char g = posf[1]+96;
	//check if king dead
	if(exit(cb)==1) {
		textbackground(0);
		clrscr();
		cout<<"bye";
	} else {
		makeBoard(cb);
		cout<<"\nAI has moved "<<u<<f<<posi[0]<<" to "<<u<<g<<posf[0]<<endl;
		delay(1500);
		aivai(cb);
	}

}

void repgame(char cb[8][8])
{
	chess a;
	fstream f1("chess.dat", ios::binary|ios::in);
	while(!f1.eof())
	{
		f1.read((char*)&a, sizeof(a));
		cb = a.board;
		makeBoard(cb);
		delay(1000);
	}
	f1.close();
	cout<<"\nReplay Over!";
	getch();
}

void main()
{
	 clrscr();
	 //lowercase is White
	//uppercase is Black
	//K is king
	//Q is queen
	//N is knight
	//R is rook
	//P is Pawn
	//B is Bishop
	//0 is nothing
	char cb[8][8]={
	{'r','n','b','q','k','b','n','r'},
	{'p','p','p','p','p','p','p','p'},
	{'0','0','0','0','0','0','0','0'},
	{'0','0','0','0','0','0','0','0'},
	{'0','0','0','0','0','0','0','0'},
	{'0','0','0','0','0','0','0','0'},
	{'P','P','P','P','P','P','P','P'},
	{'R','N','B','Q','K','B','N','R'}
	};
	init();
	makeBoard(cb);
	cout<<"\nDo you want to play with an ai/human/replay/aivai ? (y/n/r/x)\n";
	char ai;
	cin>>ai;
	if(ai=='y')
	{
		arf(cb);
	} else if(ai=='x') { //aivai
		aivai(cb);
	} else if(ai=='r') { //replay last game hvh
		repgame(cb);
	}
	else{
		fstream f1("chess.dat", ios::binary|ios::app);
		f1.close();
		remove("chess.dat");
		move(cb);
	}
	getch();
}
