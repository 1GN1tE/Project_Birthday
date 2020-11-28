#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <ctype.h>  
#include <time.h>

int height = 50;
int width = 200;

void print_data()
{
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	printw("\n     ");
	for(int i=0; i<width-10; i++)
	{
		printw("_");
	}
	printw("     ");
	for(int i=0; i<height-4; i++)
	{
		printw("\n     |");
		for(int i=0; i<width-12; i++)
			printw(" ");
		printw("|");
	}
	printw("\n");
	printw("     ");
	for(int i=0; i<width-10; i++)
	{
		printw("-");
	}
	printw("     ");
	attroff(COLOR_PAIR(2));
}

void start()
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	move((int)height/2,((int)width/2)-11);
	printw("Press any key to start");
	getch();
	attroff(COLOR_PAIR(1));
	clear();
	print_data();
}

void credits()
{
	char credit[] = "From Ignite and Rey";

	init_pair(10, COLOR_RED, COLOR_BLACK);
	init_pair(11, COLOR_MAGENTA, COLOR_BLACK);

	for(int _=0; _<5; _++)
	{
		for(int c=0; c<strlen(credit); c++)
		{
			move((height-4),(width-30));
			for(int first=0; first<c; first++)
			{
				attron(COLOR_PAIR(11));
				printw("%c", credit[first]);
				attroff(COLOR_PAIR(11));
			}
			
			attron(COLOR_PAIR(10));
			printw("%c", toupper(credit[c]));
			attroff(COLOR_PAIR(10));

			for(int last=c+1; last<strlen(credit); last++)
			{
				attron(COLOR_PAIR(11));
				printw("%c", credit[last]);
				attroff(COLOR_PAIR(11));
			}
			refresh();
			delay_output(150);
		}
	}
	clear();
	print_data();
}

void loading_screen(){
	move((int)height/2,((int)width/2)-5);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	printw("Loading  ");
	// attroff(COLOR_PAIR(1));

	for(int t=0; t<10; t++)
	{	
		move((int)height/2,((int)width/2)+4);
		printw("|");
		refresh();
		delay_output(100);
		move((int)height/2,((int)width/2)+4);
		printw("/");
		refresh();
		delay_output(100);
		move((int)height/2,((int)width/2)+4);
		printw("-");
		refresh();
		delay_output(100);
		move((int)height/2,((int)width/2)+4);
		printw("\\");
		refresh();
		delay_output(100);
	}
	attroff(COLOR_PAIR(1));
	clear();
	print_data();
}

void check()
{
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(3));

	move(((int)height/2-1), ((int)width/2)-17);
	char sentence1[] = "This app contains a secret message";
	for(int c=0; c<strlen(sentence1); c++)
	{
		printw("%c", sentence1[c]);
		refresh();
		delay_output(100);
	}

	move(((int)height/2+0), ((int)width/2)-22);
	char sentence2[] = "The right person will be able to decode this";
	for(int c=0; c<strlen(sentence2); c++)
	{
		printw("%c", sentence2[c]);
		refresh();
		delay_output(100);
	}
	

	move(((int)height/2+1), ((int)width/2)-21);
	char sentence3[] = "Data >>> 49742773206d79206269727468646179";
	for(int c=0; c<strlen(sentence3); c++)
	{
		printw("%c", sentence3[c]);
		refresh();
		delay_output(100);
	}
	

	move(((int)height/2+2), ((int)width/2)-17);
	printw("Ans. >>> ");
	attroff(COLOR_PAIR(3));

	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(4));

	char arr[200];
	int c = 0;
	while(true)
	{
		char ch = getch();
		if(ch==10)
		{	
			break;
		}
		arr[c] = ch;
		c++;
	}
	clear();
	print_data();
	if(strncmp(arr,"It's my birthday",16))
	{
		move(((int)height/2-1), ((int)width/2)-2);
		printw("Fail");
		refresh();
		delay_output(1000);
		endwin();
		exit(0);
	}
	else
	{
		move(((int)height/2-1), ((int)width/2)-2);
		printw("Pass");
		refresh();
		delay_output(500);

		init_pair(5, COLOR_CYAN, COLOR_BLACK);

		move(((int)height/2), ((int)width/2)-32);
		char sentence4[] = "Ok We are sure you are the person. So now sit back and enjoy....";
		for(int c=0; c<strlen(sentence4); c++)
		{
			attron(COLOR_PAIR(5));
			printw("%c", sentence4[c]);
			refresh();
			delay_output(100);
			attroff(COLOR_PAIR(5));
		}
		delay_output(1000);
	}
	attroff(COLOR_PAIR(4));
	clear();
	print_data();
}

void shot()
{
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	int h=18;
	int w=10;

	int y1 = 0;
	int x1 = 0;
	int y2 = 0;
	int x2 = 0;


    for(int i=0; i<15; i++)
    {
    	attron(COLOR_PAIR(4));
    	move(height-h,w);
    	printw("//");
    	getyx(stdscr, y1, x1);
    	move(height-h,width-w-1);
    	printw("\\\\");
    	getyx(stdscr, y2, x2);
    	attroff(COLOR_PAIR(4));
    	w+=2;
    	h++;
    	refresh();
		delay_output(200);
    }
    h=18;
	w=10;
	
    for(int i=0; i<15; i++)
    {
    	attron(COLOR_PAIR(4));
    	move(height-h,w);
    	printw("  ");
    	getyx(stdscr, y1, x1);
    	move(height-h,width-w-1);
    	printw("  ");
    	getyx(stdscr, y2, x2);
    	attroff(COLOR_PAIR(4));
    	w+=2;
    	h++;
    }

    char ch_arr[9][20] = {
		"        * ",
		"      /-|-\\",
		"     /  |  \\",
		"    -   |   -",
		"   /    |    \\",
		"  -     |     -",
		" /      |      \\",
		"|       |       |",
		"|       |       |",
	};
	h = 0;
	for(int i=0; i<9; i++)
	{
		attron(COLOR_PAIR((4+i%2)));
		move((y1+h),x1);
		printw("%s",ch_arr+i);
		refresh();
		delay_output(50);

		move((y2+h),x2-17);
		printw("%s",ch_arr+i);
		refresh();
		delay_output(50);
		attroff(COLOR_PAIR((4+i%2)));
		h++;
	}
}

void bday()
{
	srand(time(0));

    char ch_arr[6][200] = {
		"  _   _                                  	 ____    _          _     _           _                  ",
		" | | | |   __ _   _ __    _ __    _   _  	| __ )  (_)  _ __  | |_  | |__     __| |   __ _   _   _  ",
		" | |_| |  / _` | | '_ \\  | '_ \\  | | | | 	|  _ \\  | | | '__| | __| | '_ \\   / _` |  / _` | | | | | ",
		" |  _  | | (_| | | |_) | | |_) | | |_| | 	| |_) | | | | |    | |_  | | | | | (_| | | (_| | | |_| | ",
		" |_| |_|  \\__,_| | .__/  | .__/   \\__, | 	|____/  |_| |_|     \\__| |_| |_|  \\__,_|  \\__,_|  \\__, | ",
		"                  |_|     |_|      |___/ 	                                                   |___/ ",
	};

	init_pair(0, COLOR_RED, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);


	int c=0;
	for(int _=0; _<1000; _++)
	{
		for(int i=0; i<6;i++)
		{
			move(((int)height/2-3)+i,((int)width/2-50));
			for(int j=0; j<100; j++)
			{
				int tmp = (rand()%7);
				attron(COLOR_PAIR(tmp));
				printw("%c", ch_arr[i][j]);
				attroff(COLOR_PAIR(tmp));
				c++;
			}
		}
		refresh();
		delay_output(5);
	}
}

void main()
{
	initscr();
	getmaxyx(stdscr, height, width);
	height = height - 1;
	width = width - 1;
	start_color();
	print_data();

	start();
	loading_screen();
	check();
	bday();
	shot();
	credits();

	getch();
	endwin();
}