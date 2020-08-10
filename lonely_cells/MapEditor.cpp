#include <stdio.h>
#include <graphics.h>
#include<math.h>
void map_printer(int n);

int main (){
    int n;
    printf("Enter the size of map (n)\n");
    scanf("%d",&n);
    map_printer(n);
    FILE * fp;
    char bin_map[n*n+1];
    fp = fopen("map.bin","wb");
    fwrite(&n,sizeof(int),1,fp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getchar();
            printf("Enter type of cell [%d,%d]\n[1]Energy cell\n[2]Mitosis cell\n[3]Forbidden cell\n[4]Normal cell\n",j,i);
            scanf("%c",&bin_map[i*n+j]);
            fwrite(&bin_map[i*n+j], sizeof(char), 1, fp);
        }
    }
    fclose(fp);
    printf("Map has successfully maked\n");
    return 0;
}





void map_printer(int n){
    int a = 40;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    initwindow(n*125,n*125);
    cleardevice();
    int coordinate_for_text[n*n][2];
    for (int j = 0;j  <n; j++)
    {
        for (int  i = 0; i < n; i++)
        {
            coordinate_for_text[i +j*n][0] = (2*i+1)*a+20;
            coordinate_for_text[i +j*n][1] = (2*j+1)*sqrt(3)*(a)/2 + (i%2+1)* sqrt(3)*(a)/2+10;
            int coordinates[14];
            coordinates[0]=(2*i+1)*a-a +20;
            coordinates[1] = (2*j+1)*sqrt(3)*(a)/2 + (i%2+1)* sqrt(3)*(a)/2+10;
            coordinates[2] = (2*i+1)*(a)-a/2+20;
            coordinates[3] = (2*j+1)*sqrt(3)*(a)/2+sqrt(3)*a/2 + (i%2+1)* sqrt(3)*(a)/2+10;
            coordinates[4] = (2*i+1)*(a)+a/2+20;
            coordinates[5] = (2*j+1)*sqrt(3)*(a)/2+sqrt(3)*a/2+ (i%2+1)* sqrt(3)*(a)/2+10;
            coordinates[6] = (2*i+1)*(a)+a+20;
            coordinates[7] = (2*j+1)*sqrt(3)*(a)/2 + (i%2+1)* sqrt(3)*(a)/2+10;
            coordinates[8] = (2*i+1)*(a)+a/2+20;
            coordinates[9] = (2*j+1)*sqrt(3)*(a)/2-sqrt(3)*a/2+ (i%2+1)* sqrt(3)*(a)/2+10;
            coordinates[10] = (2*i+1)*(a)-a/2+20;
            coordinates[11] = (2*j+1)*sqrt(3)*(a)/2-sqrt(3)*a/2+ (i%2+1)* sqrt(3)*(a)/2+10;
            coordinates[12] = (2*i+1)*(a)-a+20;
            coordinates[13] = (2*j+1)*sqrt(3)*(a)/2+ (i%2+1)* sqrt(3)*(a)/2+10;
            setcolor(BROWN);
            setfillstyle(8, DARKGRAY);
            fillpoly(7,coordinates);
        }
    }

    for(int i =0 ; i < n ; i++){
        for(int j =0 ; j < n ; j++){
            char coordinate[10];
            sprintf(coordinate, "[%d,%d]", i,j);
            setcolor(BROWN);
            outtextxy(coordinate_for_text[n*j+i][0] -13,coordinate_for_text[n* j +i][1]-20,coordinate);
        }
    }
}
