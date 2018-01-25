void ppola(int (&pole)[16][16],int x, int y)
{
    x-=8;
    y-=8;
    for(int i=0;i<16;i++)
            {
                for(int j=0;j<16;j++)
                {
                    pole[i][j]=getpixel(x+i,y+j);
                }
            }
}
void wspola(int pole[16][16],int x, int y)
{
    x-=8;
    y-=8;
    for(int i=0;i<16;i++)
            {
                for(int j=0;j<16;j++)
                {
                    putpixel(x+i,y+j,pole[i][j]);
                }
            }
}
