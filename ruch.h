void ruch(int x,int y)
{

if(GetAsyncKeyState(87)&&GetAsyncKeyState(68))
    {
        y-=3;
        x+=3;
    }
    if(GetAsyncKeyState(87)&&GetAsyncKeyState(65))
    {
        y-=3;
        x-=3;
    }
    if(GetAsyncKeyState(83)&&GetAsyncKeyState(68))
    {
        y+=3;
        x+=3;
    }
    if(GetAsyncKeyState(83)&&GetAsyncKeyState(65))
    {
        y+=3;
        x-=3;
    }
    if(GetAsyncKeyState(87))
    {
        y-=8;

    }
    if(GetAsyncKeyState(83))
    {
        y+=8;

    }
    if(GetAsyncKeyState(68))
    {

        x+=8;
    }
    if(GetAsyncKeyState(65))
    {

        x-=8;
    }
    if(mapa[y/16][x/16]==2 || (y/16)<0 || (x/16)<0 || (y/16)>=48 || (x/16)>64)
    {
        x=sx;
        y=sy;
    }
}
