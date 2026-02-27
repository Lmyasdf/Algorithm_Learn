#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
int ful(char board[ROW][COL],int row,int col);
int panduan(char board[ROW][COL],int* k ,int* l);
void menu(){
    printf("******1.开始游戏******\n******0.退出游戏******\n**********************\n请输入:");
}

void initboard(char board[ROW][COL],int row,int col){
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            board[i][j] = ' ';
        }
    }
}

void print(char board[ROW][COL],int row,int col){
    int i = 0;
    int j = 0;
    int o = 0;
   for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        printf(" %c ",board[i][j]);
        if(j==col-1){
            break;
        }
        printf("|");
    }
    printf("\n");
    if(i==col-1){
        break;
    }
    for(o=0;o<col;o++){
        printf("---");
        if(o==col-1){
            break;
        }
        printf("|");
    }
    printf("\n");
   }

    
}

void player(char board[ROW][COL],int row,int col){
    int x = 0;
    int y = 0;
    printf("输入格式：横 列\n");

    while(1){
  a:  printf("玩家下棋：>");
    scanf("%d %d",&x,&y);
    if(x>=1&&y>=1&&x<=row&&y<=col){
        if(board[x-1][y-1]==' '){
        board[x-1][y-1] = '*';
        break;
        }
        else {
        printf("输入错误，请重新输入\n");
        goto a;
        }
    }
    else{
    printf("输入错误，请重新输入\n");
    goto a;
    }
}
}

void computer(char board[ROW][COL],int row,int col){
    printf("电脑下棋：>\n");
    int x = 0;
    int y = 0;
    int i = 0;
    int j = 0;    
    int k = 0;
    int l = 0;
    while(1){        
        int pan = panduan(board,&k,&l);//&
        if(pan >= 0 && pan <= 2){
        board[k][l]='#';
        break;
        }
    
        if(board[1][1]==' '){
        board[1][1]='#';
        break;

    }
    if(board[0][0]==' '||board[0][2]==' '||board[2][0]==' '||board[2][2]==' '){
     x = rand()%(row+1);
        if(x==0&&board[0][0]==' '){
            board[0][0]='#';
            break;
        }
        else if(x==1&&board[0][2]==' '){
            board[0][2]='#';
            break;
        }
        else if(x==2&&board[2][2]==' '){
            board[2][2]='#';
            break;
        }        
        else if(x==3&&board[2][0]==' '){
            board[2][0]='#';
            break;
        }
    }
        i=rand()%3;
        j=rand()%3;
        if(board[i][j]!='*'&&board[i][j]!='#'){
            board[i][j]='#';
            break;
        } 
        }
    }          


int panduan(char board[ROW][COL],int* k ,int* l){
    int i = 0;
    int j = 0;

    for(i=0;i<3;i++){


        if(board[i][0]=='#' && board[i][1]=='#' && board[i][2]==' '){
            *k = i;
            *l = 2;
            return 0;
        }
        if(board[i][0]=='#' && board[i][2]=='#' && board[i][1]==' '){
            *k = i;
            *l = 1;
            return 0;
        }
        if(board[i][1]=='#' && board[i][2]=='#' && board[i][0]==' '){
            *k = i;
            *l = 0;
            return 0;
        }
    }
    

    for(j=0;j<3;j++){

        
        if(board[0][j]=='#' && board[1][j]=='#' && board[2][j]==' '){
            *k = 2;
            *l = j;
            return 1;
        }
        if(board[0][j]=='#' && board[2][j]=='#' && board[1][j]==' '){
            *k = 1;
            *l = j;
            return 1;
        }
        if(board[1][j]=='#' && board[2][j]=='#' && board[0][j]==' '){
            *k = 0;
            *l = j;
            return 1;
        }
    }
    

    
    if(board[0][0]=='#' && board[1][1]=='#' && board[2][2]==' '){
        *k = 2;
        *l = 2;
        return 2;
    }
    if(board[0][0]=='#' && board[2][2]=='#' && board[1][1]==' '){
        *k = 1;
        *l = 1;
        return 2;
    }
    if(board[1][1]=='#' && board[2][2]=='#' && board[0][0]==' '){
        *k = 0;
        *l = 0;
        return 2;
    }


    
    if(board[0][2]=='#' && board[1][1]=='#' && board[2][0]==' '){
        *k = 2;
        *l = 0;
        return 2;
    }
    if(board[0][2]=='#' && board[2][0]=='#' && board[1][1]==' '){
        *k = 1;
        *l = 1;
        return 2;
    }
    if(board[1][1]=='#' && board[2][0]=='#' && board[0][2]==' '){
        *k = 0;
        *l = 2;
        return 2;
    }
    
        for(i=0;i<3;i++){

        if(board[i][0]=='*' && board[i][1]=='*' && board[i][2]==' '){
            *k = i;
            *l = 2;
            return 0;
        }
        if(board[i][0]=='*' && board[i][2]=='*' && board[i][1]==' '){
            *k = i;
            *l = 1;
            return 0;
        }
        if(board[i][1]=='*' && board[i][2]=='*' && board[i][0]==' '){
            *k = i;
            *l = 0;
            return 0;
        }
    } 
        for(j=0;j<3;j++){

        if(board[0][j]=='*' && board[1][j]=='*' && board[2][j]==' '){
            *k = 2;
            *l = j;
            return 1;
        }
        if(board[0][j]=='*' && board[2][j]=='*' && board[1][j]==' '){
            *k = 1;
            *l = j;
            return 1;
        }
        if(board[1][j]=='*' && board[2][j]=='*' && board[0][j]==' '){
            *k = 0;
            *l = j;
            return 1;
        }
    }
    if(board[0][0]=='*' && board[1][1]=='*' && board[2][2]==' '){
        *k = 2;
        *l = 2;
        return 2;
    }
    if(board[0][0]=='*' && board[2][2]=='*' && board[1][1]==' '){
        *k = 1;
        *l = 1;
        return 2;
    }
    if(board[1][1]=='*' && board[2][2]=='*' && board[0][0]==' '){
        *k = 0;
        *l = 0;
        return 2;
    }
        if(board[0][2]=='*' && board[1][1]=='*' && board[2][0]==' '){
        *k = 2;
        *l = 0;
        return 2;
    }
    if(board[0][2]=='*' && board[2][0]=='*' && board[1][1]==' '){
        *k = 1;
        *l = 1;
        return 2;
    }
    if(board[1][1]=='*' && board[2][0]=='*' && board[0][2]==' '){
        *k = 0;
        *l = 2;
        return 2;
    }
}
char win(char board[ROW][COL],int row,int col){
    int i = 0;
    int j = 0;

    for(i=0;i<row;i++){
        
        if(board[i][0] == board[i][1]&&board[i][1]==board[i][2]&&board[i][2]=='*'){
            return '*';
        } 
        if(board[i][0] == board[i][1]&&board[i][1]==board[i][2]&&board[i][2]=='#'){
            return '#';
        }
        
    }
    for(j=0;j<col;j++){
        if(board[0][j] == board[1][j]&& board[1][j]==board[2][j]&&board[2][j]=='*'){
            return '*';
        } 
        if(board[0][j] == board[1][j] &&board[1][j]==board[2][j]&&board[2][j]=='#'){
            return '#';
        }
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' '){
        return board[1][1];
    }
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[1][1]!=' '){
        return board[1][1];
    }

    if(ful(board,ROW,COL)){
        return 'q';
    }
    return 'c';
}

int ful(char board[ROW][COL],int row,int col){
    int i = 0;
    int j = 0;
    int sum = 0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(board[i][j]==' '){
                return 0;
            }
        }
    }
    return 1;
}   


void game(){
    char ret = '.';
    char board[ROW][COL] = {0};
    initboard(board,ROW,COL);
    print(board,ROW,COL);
    
    
    while(1){
    player(board,ROW,COL);

    ret = win(board,ROW,COL);
    if(ret != 'c'){
        break;
    }
    print(board,ROW,COL);

    computer(board,ROW,COL);
    
    ret = win(board,ROW,COL);
    if(ret != 'c'){
        break;
    }
    print(board,ROW,COL);
}   
    print(board,ROW,COL);
    if(ret == '*'){
        printf("你赢了\n");
    }
    else if(ret == '#'){
        printf("电脑赢了\n");
    }
    else{
        printf("平局\n");
    }

}

int main(){

    int input = 0;
    srand((unsigned int)time(NULL));
    
    do{ 
        menu();
        scanf("%d",&input);       
        switch(input){
            case 1: game();
                    break;
            case 0: printf("退出游戏");
                    break;
            default:printf("输入错误，请重新输入");
                    break;
        }
    }
    while(input);

}