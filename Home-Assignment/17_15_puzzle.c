#include<stdio.h>
#include<string.h>

int n=4, m[10][10], s[10][10], temp[10][10], moves=0;
char sol[100][10];

int check(){
    int i, j, w=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(temp[i][j] != s[i][j]){
                w++;
            }
        }
    }
    return w;
}

void down(){
    int i, j, t, pos1, pos2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            temp[i][j]=m[i][j];
            if(m[i][j]==0){
                pos1=i;
                pos2=j;
            }
        }
    }
    t=temp[pos1][pos2];
    temp[pos1][pos2]=temp[pos1+1][pos2];
    temp[pos1+1][pos2]=t;
    strcpy(sol[moves], "down");
}

void up(){
    int i, j, t, pos1, pos2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            temp[i][j]=m[i][j];
            if(m[i][j]==0){
                pos1=i;
                pos2=j;
            }
        }
    }
    t=temp[pos1][pos2];
    temp[pos1][pos2]=temp[pos1 - 1][pos2];
    temp[pos1 - 1][pos2]=t;
    strcpy(sol[moves], "up");
}

void left(){
    int i, j, t, pos1, pos2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            temp[i][j]=m[i][j];
            if(m[i][j]==0){
                pos1=i;
                pos2=j;
            }
        }
    }
    t=temp[pos1][pos2];
    temp[pos1][pos2]=temp[pos1][pos2 - 1];
    temp[pos1][pos2 - 1]=t;
    strcpy(sol[moves], "left");
}

void right(){
    int i, j, t, pos1, pos2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            temp[i][j]=m[i][j];
            if(m[i][j]==0){
                pos1=i;
                pos2=j;
            }
        }
    }
    t=temp[pos1][pos2];
    temp[pos1][pos2]=temp[pos1][pos2+1];
    temp[pos1][pos2+1]=t;
    strcpy(sol[moves], "right");
}

void move(){
    int i, j, k, c[10], w, min;

    while(1){
        moves++;

        down();
        w=check();
        if(w==0)
            c[0]=-1;
        else
            c[0]=w+moves;

        up();
        w=check();
        if(w==0)
            c[1]=-1;
        else
            c[1]=w+moves;

        left();
        w=check();
        if(w==0)
            c[2]=-1;
        else
            c[2]=w+moves;

        right();
        w=check();
        if(w==0)
            c[3]=-1;
        else
            c[3]=w+moves;

        min=999;
        for(i=0;i<4;i++){
            if(min>c[i]){
                min=c[i];
                j=i;
            }
        }
        if(j==0)
            down();
        if(j==1)
            up();
        if(j==2)
            left();
        if(j==3)
            right();
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                m[i][j]=temp[i][j];
            }
        }
        if(min==-1){
            printf("\nTotal no of moves to solve : %d\n", moves);
            for(i=1;i<=moves;i++){
                printf("Move-%d = %s\n",i,sol[i]);
            }
            break;
        }
    }
}

int main(){
    int i, j;
    printf("\nEnter the puzzle:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &m[i][j]);
        }
    }
    printf("\nEnter the Solution:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &s[i][j]);
        }
    }
    move();
    return 0;
}


/*
1 2 3 4
5 6 0 8
9 10 7 11
13 14 15 12

1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 0
*/
