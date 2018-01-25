void bullet(int n){
    int i;

    for(i=0;i<n;i++){
            if(kula[i].strona==1 && kula[i].y>lewy_rogy){
                putpixel(kula[i].x,kula[i].y,BLACK);
                kula[i].x=kula[i].x;
                kula[i].y=kula[i].y-1;
        };

    if(kula[i].strona==2 && kula[i].x<prawy_rogx){
                putpixel(kula[i].x,kula[i].y,BLACK);
                kula[i].x=kula[i].x+1;
                kula[i].y=kula[i].y;
        };

        if(kula[i].strona==3 && kula[i].y<prawy_rogy){
                putpixel(kula[i].x,kula[i].y,BLACK);
                kula[i].x=kula[i].x;
                kula[i].y=kula[i].y+1;
        };

         if(kula[i].strona==4 && kula[i].x>lewy_rogx){
                putpixel(kula[i].x,kula[i].y,BLACK);
                kula[i].x=kula[i].x-1;
                kula[i].y=kula[i].y;
        };

    };
    for(i=0;i<n;i++){
            if(kula[i].strona==1 && kula[i].y>lewy_rogy){
                putpixel(kula[i].x,kula[i].y,RED);

        };


    if(kula[i].strona==2 && kula[i].x<prawy_rogx){
                putpixel(kula[i].x,kula[i].y,RED);

        };

        if(kula[i].strona==3 && kula[i].y<prawy_rogy){
                putpixel(kula[i].x,kula[i].y,RED);

        };

         if(kula[i].strona==4 && kula[i].x>lewy_rogx){
                putpixel(kula[i].x,kula[i].y,RED);


        };

    };


}
