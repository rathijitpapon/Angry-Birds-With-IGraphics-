//#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#include<stdio.h>
#include<math.h>
#include<time.h>

double x=43,y=251,v,angle,t=0,s=0,f=0,l,pic=0;
double play,hs,help,lvl,l1,l2,l3,mnmnu=1,ext;
int snm=1,sbrds;
int nb=0,brd;

void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

void movebird()
{
    //if(pic!=0){
        if(s==1){
        x=70*cos(30*(acos(0)/90))*t+43;
        y=70*sin(40*(acos(0)/90))*t-0.5*9.81*t*t+251;
        t+=0.1;
        }

        /*x=70*cos(acos(0)/2)*t;
        y=70*sin(acos(0)/2)*t-0.5*9.81*t*t;
        t+=0.1;*/
   // }


}

void birdselection(int n , int brd)
{
	if(n==2){
		if(brd==1){
			iShowBMP2(140,00,"b1.bmp",0);
		}
		else if(brd==2){
			iShowBMP2(240,00,"b2.bmp",0);
		}
		else if(brd==3){
			iShowBMP2(350,00,"b3.bmp",0);
		}
	}

	else if(n==1){
		if(brd==1){
			iShowBMP2(240,00,"b2.bmp",0);
			iShowBMP2(350,00,"b3.bmp",0);
		}
		else if(brd==2){
			iShowBMP2(140,00,"b1.bmp",0);
			iShowBMP2(350,00,"b3.bmp",0);
		}
		else if(brd==3){
			iShowBMP2(140,00,"b1.bmp",0);
			iShowBMP2(240,00,"b2.bmp",0);
		}
	}

	else if(n==3){
		/*iShowBMP2(140,00,"b1.bmp",0);
		iShowBMP2(240,00,"b2.bmp",0);
		iShowBMP2(350,00,"b3.bmp",0);*/
	}
}


void iDraw() {

	iClear();

	if(mnmnu==1){
		iShowBMP(0,0,"menu.bmp");
		iShowBMP2(3,3,"exit.bmp",0);
	}

	if(ext==1){
		iShowBMP(0,0,"Cover.bmp"); 
		delay(3000);
		exit(0);
		
		mnmnu=0,play=0,l1=0,ext=0;

	}

	if(play==1){
		iShowBMP(0,0,"level.bmp");
	}

	if(l1==1){
		iShowBMP(0,0,"bg.bmp");
		iShowBMP2(30,50,"gulti.bmp",0);
		//iShowBMP2(630,50,"temp[103].bmp",0);
        if(pic!=-1)iShowBMP2(630,170,"Cage11.bmp",0);


		if(pic==2){
			birdselection(nb,2);
			iShowBMP2(x,y,"b2.bmp",0);
		}
		else if(pic==3){
			birdselection(nb,3);
			iShowBMP2(x,y,"b3.bmp",0);
		}
		else if(pic==1){
			birdselection(nb,1);
			iShowBMP2(x,y,"b1.bmp",0);
		}
		else{
			iShowBMP2(140,00,"b1.bmp",0);
			iShowBMP2(240,00,"b2.bmp",0);
			iShowBMP2(350,00,"b3.bmp",0);
		}

		if(x>=632-80 && x<=775 && y>=178 && y<=414){
			iShowBMP2(630,170,"cagedown.bmp",0);
			iShowBMP2(800,170,"cageup.bmp",0);
			if(pic==1){
				iShowBMP2(65,250,"b1.bmp",0);
				pic=-1;
			}
			else if(pic==2){
				iShowBMP2(65,250,"b2.bmp",0);
				pic=-1;
			}
			else if(pic==3){
				iShowBMP2(65,250,"b3.bmp",0);
				pic=-1;
			}
		}

		iSetColor(255,0,128);

		if(x>=275 && y<=320)f=1,s=1;
		
	}


}


void iMouseMove(int mx, int my)
{
        x=mx,y=my,s=1;

        if(x+y==l)s=0;
        else l=x+y;
        angle=acos(fabs(x-139)/sqrt((x-139)*(x-139)+(y-185)*(y-185)));
        v=(3/0.2)*fabs(x-139);

}


void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		if(mx>=130 && mx<=315 && my<=375 && my>=272)play=1,mnmnu=0;
		if(mx>=423 && mx<=619 && my<=371 && my>=273)hs=1,mnmnu=0;
		if(mx>=708 && mx<=896 && my<=378 && my>=276)help=1,mnmnu=0;

		if(play==1){
			if(mx>=431 && mx<=529 && my<=309 && my>=289)l1=1,play=0,mnmnu=0;			
			if(mx>=428 && mx<=525 && my<=267 && my>=251)l2=1,play=0,mnmnu=0;
			if(mx>=428 && mx<=530 && my<=224 && my>=207)l3=1,play=0,mnmnu=0;
		}

		printf("%d %d\n",mx,my);

		if(l1==1){
			if(mx>=140 && mx<=190)pic=1,nb++;
			else if(mx>=240 && mx<=290)pic=2,nb++;
			else if(mx>=350 && mx<=400)pic=3,nb++;
		}

		if(mx>=23 && mx<=82 && my>=17 && my<=78)ext=1;
    }
}

void iKeyboard(unsigned char key) {

}

void iSpecialKeyboard(unsigned char key)
{

}

int main() {
    iSetTimer(100,movebird);

	/*if(snm)
		PlaySound("angrymm.wav", NULL, SND_LOOP | SND_ASYNC);
	if(sbrds)
		PlaySound("birdshot.wav", NULL, SND_LOOP | SND_ASYNC);*/

	iInitialize(1000, 565, "Angry Birds Rio");
	return 0;
}