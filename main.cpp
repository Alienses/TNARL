#include <graphics.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include "pola.h"
#include "poziom.h"
#include "kolizje.h"

using namespace std;


void postac(int x, int y, int kolor)
{
    setcolor(kolor);
    setfillstyle(SOLID_FILL,kolor);
    circle(x,y,8);
    floodfill(x+1,y+1,kolor);


}
void wrog(int x, int y, int kolor)
{
    setcolor(kolor);
    setfillstyle(SOLID_FILL,kolor);
    circle(x,y,16);
    floodfill(x+1,y+1,kolor);


}

void pociskr(int x, int y, int kolor)
{
        setcolor(kolor);
        circle(x,y,3);
        setfillstyle(SOLID_FILL,kolor);
        floodfill(x,y,kolor);


}
void punkty(int x){
    setcolor(WHITE);
    char punkty[50] = "Punkty: ";
    char p[20];
    itoa(x, p, 10 );
    strcat(punkty, p);
    settextstyle (DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy( 31 , 31, punkty);
}
struct przeciwnik
{
    int kolor=MAGENTA;
    int lp;
    int x;
    int y;
    int sx;
    int sy;
    int zycie=10;
};

struct pocisk
{
    int atak;
    int j=0;
    int wsk;
    float sx;
    float sy;
    int y;
    int x;
    int predkosc=15;
    float cel_y;
    float cel_x;
    float xp;
    float yp;
    float kierunek;
}pocisk[10000000];



void bullet(int &z,int &atak){

    int i;


    for(i=0;i<z;i+=1)
        {
            if(pocisk[i].wsk!=1)
                {
                    pociskr(pocisk[i].xp,pocisk[i].yp,BLACK);
                    pocisk[i].sx=pocisk[i].xp;
                    pocisk[i].sy=pocisk[i].yp;

                    if(pocisk[i].y-pocisk[i].cel_y>0)
                        {
                            if((pocisk[i].x-pocisk[i].cel_x)>pocisk[i].y-pocisk[i].cel_y)
                            {
                                pocisk[i].xp-=pocisk[i].predkosc;
                                pocisk[i].yp-=pocisk[i].predkosc/pocisk[i].kierunek;

                            }
                            else if(-(pocisk[i].x-pocisk[i].cel_x)>pocisk[i].y-pocisk[i].cel_y)
                            {
                                pocisk[i].xp+=pocisk[i].predkosc;
                                pocisk[i].yp+=pocisk[i].predkosc/pocisk[i].kierunek;

                            }
                            else
                            {
                                pocisk[i].xp-=pocisk[i].predkosc*pocisk[i].kierunek;
                                pocisk[i].yp-=pocisk[i].predkosc;

                            }
                       }
                    else
                        {
                            if(pocisk[i].x-pocisk[i].cel_x<pocisk[i].y-pocisk[i].cel_y)
                            {
                                pocisk[i].xp+=pocisk[i].predkosc;
                                pocisk[i].yp+=pocisk[i].predkosc/pocisk[i].kierunek;

                            }
                            else if(-(pocisk[i].x-pocisk[i].cel_x)<pocisk[i].y-pocisk[i].cel_y)
                            {
                                pocisk[i].xp-=pocisk[i].predkosc;
                                pocisk[i].yp-=pocisk[i].predkosc/pocisk[i].kierunek;

                            }
                            else
                           {
                               pocisk[i].xp+=pocisk[i].predkosc*pocisk[i].kierunek;
                                pocisk[i].yp+=pocisk[i].predkosc;

                            }
                        }

                    kolizja_pocisku(pocisk[i].xp,pocisk[i].yp,pocisk[i].sx,pocisk[i].sy,pocisk[i].wsk,atak);
                    pocisk[i].atak=atak;
                    pociskr(pocisk[i].xp,pocisk[i].yp,RED);

                }
                else if(pocisk[i].j!=1)
                {
                    pociskr(pocisk[i].xp,pocisk[i].yp,BLACK);
                    pocisk[i].j++;
                }

        }
}






int main()
{
    initwindow(1024,768,"INIT",0,0,false,true); // otwarcie okna graficznego 64x48 kwadratow o boku 16

    int z=0,x=1024/2,y=758/2,sx,sy,xstrzal,ystrzal,predkosc=3,kol,ilosc_przeciwnikow=0,zycie,pkt=0,ilp,atak=0;
    int krok[16][16];
    int mapa[48][64];

    readimagefile("poziomy.bmp",0,0,1024,768);

    ilp=getch();

    if(ilp=='1')
        {
            ilosc_przeciwnikow=1;
        }
        else if(ilp=='2')
        {
            ilosc_przeciwnikow=2;
        }

    cleardevice();
    poziom1(mapa,zycie);
    ppola(krok,x,y);
    postac(x,y,GREEN);

	przeciwnik** ww = new przeciwnik*[ilosc_przeciwnikow];
	for (int k = 0; k<ilosc_przeciwnikow; k++) {
		ww[k] = new przeciwnik;
		ww[k]->lp = k;
		ww[k]->x=8*(k+1)*16;
		ww[k]->y=8*16;

	}




    while(1)
        {
            for(int jkl=0;jkl<ilosc_przeciwnikow;jkl++)
            {


            wrog(ww[jkl]->x,ww[jkl]->y,ww[jkl]->kolor);
            ww[jkl]->sx=ww[jkl]->x;
            ww[jkl]->sy=ww[jkl]->y;
            //delay(0);

            if((x-ww[jkl]->x)>0)
            ww[jkl]->x+=3;
            else if((x-ww[jkl]->x)<0)
            ww[jkl]->x-=3;

            if((y-ww[jkl]->y)>0)
            ww[jkl]->y+=3;
            else if((y-ww[jkl]->y)<0)
            ww[jkl]->y-=3;



                        wrog(ww[jkl]->sx,ww[jkl]->sy,BLACK);
            sx=x;
            sy=y;

            postac(x,y,GREEN);

            if(ismouseclick(WM_LBUTTONDOWN))
                {
                    getmouseclick(WM_LBUTTONDOWN,xstrzal,ystrzal);
                    pocisk[z].kierunek=(float(xstrzal-x))/(float(ystrzal-y));
                    pocisk[z].cel_y=ystrzal;
                    pocisk[z].cel_x=xstrzal;
                    pocisk[z].xp=x;
                    pocisk[z].yp=y;
                    pocisk[z].y=y;
                    pocisk[z].x=x;
                    z++;
                }

            bullet(z,atak);
            punkty(pkt);
            delay(50);


            if (kbhit())
                {



                    wspola(krok,x,y);

/*prawo gora*/      if(GetAsyncKeyState(87)&&GetAsyncKeyState(68))
                        {
                            y-=predkosc;
                            x+=predkosc;
                            kol=1;
                            kolizja_gracza(x,y,sx,sy,kol,predkosc);
                        }
/*lewo gora*/       else if(GetAsyncKeyState(87)&&GetAsyncKeyState(65))
                    {
                        y-=predkosc;
                        x-=predkosc;
                        kol=2;
                        kolizja_gracza(x,y,sx,sy,kol,predkosc);
                    }
/*prawo dol*/       else  if(GetAsyncKeyState(83)&&GetAsyncKeyState(68))
                    {
                        y+=predkosc;
                        x+=predkosc;
                        kol=3;
                        kolizja_gracza(x,y,sx,sy,kol,predkosc);
                    }
/*lewo dol*/        else if(GetAsyncKeyState(83)&&GetAsyncKeyState(65))
                    {
                        y+=predkosc;
                        x-=predkosc;
                        kol=4;
                        kolizja_gracza(x,y,sx,sy,kol,predkosc);
                    }
/*gora*/            else if(GetAsyncKeyState(87))
                    {
                        y-=predkosc;
                        kol=5;
                        kolizja_gracza(x,y,sx,sy,kol,predkosc);
                    }
  /*dol*/             else  if(GetAsyncKeyState(83))
                    {
                        y+=predkosc;
                        kol=6;
                        kolizja_gracza(x,y,sx,sy,kol,predkosc);
                    }
    /*prawo*/           else  if(GetAsyncKeyState(68))
                    {
                        x+=predkosc;
                        kol=7;
                        kolizja_gracza(x,y,sx,sy,kol,predkosc);
                    }
   /*lewo*/            else  if(GetAsyncKeyState(65))
                    {
                        x-=predkosc;
                        kol=8;
                        kolizja_gracza(x,y,sx,sy,kol,predkosc);
                    }

                    else if(GetAsyncKeyState(VK_F1))
                    {
                        writeimagefile("pobor.bmp",0,0,1024,768);
                        readimagefile("zasady.bmp",0,0,1024,768);
                        delay(3000);



                       readimagefile("pobor.bmp",0,0,1024,768);
                    }
                    if(GetAsyncKeyState(VK_ESCAPE))
                    {
                        exit(0);
                    }



                ppola(krok,x,y);


                }

                        for(int kpoc=0;kpoc<z;kpoc++)
                            {

                        if(pocisk[kpoc].atak==1)
                                {
                                ww[jkl]->zycie--;
                                circle(100,100,9);
                            }
                            }


                        if(ww[jkl]->zycie==0)
                            {
                                ww[jkl]->kolor=BLACK;
                            }





}
                    }



}


