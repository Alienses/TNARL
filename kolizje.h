void kolizja_gracza(int &x,int &y,int sx, int sy,int k,int predkosc)
{
    int a=sx,b=sy;
            switch (k)
            {
                case 1:
                    sx+=(8+predkosc);
                    sy-=(8+predkosc);
                break;

                case 2:
                    sx-=(8+predkosc);
                    sy-=(8+predkosc);
                break;

                case 3:
                    sx+=(8+predkosc);
                    sy+=(8+predkosc);
                break;

                case 4:
                    sx-=(8+predkosc);
                    sy+=(8+predkosc);
                break;

                case 5:
                    sy-=(8+predkosc);
                break;

                case 6:
                    sy+=(8+predkosc);
                break;

                case 7:
                    sx+=(8+predkosc);
                break;

                case 8:
                    sx-=(8+predkosc);
                break;
            }
            if(getpixel(sx,sy)!=BLACK)
        {
          x=a;
          y=b;
        }
}
void kolizja_pocisku(float &x,float &y,float sx,float sy,int& wsk,int &atak)
{
    if(getpixel(x,y)==MAGENTA)
    {
    atak=1;
    }
    if(getpixel(x,y)!=BLACK)
       {
        x=sx;
        y=sy;
        wsk=1;
        }
}
