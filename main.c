#include<stdio.h>
#include<conio.h>

int remGoat=20,kill=0;
int initialize(int board[5][5]);
int printBoard(int board[5][5]);
int checkValidity(int x,int y);
int goat(int board[5][5]);
int tiger(int board[5][5]);
int choice1;


void choicee(){
    int choice;
    char a, b, y, Y;
    first:
    system("cls");
    printf("\t\t  BAGH-CHAL\n");
    printf("\t\t-------------\n");
    printf("\n\t  Menu\n");
    printf("\t ------\n\n");
    printf("\t1.  Start game\n");
    printf("\t2.  Help\n");
    printf("\t3.  Exit\n");
    printf("\nChoose the option: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
        printf("\n1.  Press 1 for Bagh\n");
        printf("2.  Press 2 for Goat\n");
        scanf("%d", &choice1);


        break;



        case 2:
            system("cls");
            printf("\n\tHelp\n");
            printf("    -----------\n\n");
            printf("How to play?\n");
            printf("For Goat:\n");
            printf("Use following format for movement in the desired position:\n");
            printf("Enter row no. (space) Enter column no. Press enter.\n");
            printf("\nFor Bagh:\n");
            printf("Use following format for movement in the desired position:\n");
            printf("Enter row no. (space) column no. to identify the position of Bagh (space)\nEnter row no. (space) column no. for movement in desired position.\n\n");
             printf("Do you want to go back  (y/n)?  ");
            fflush(stdin);
            scanf("%c", &b);
            if(b=='y'){
                goto first;
            }else{
                exit(0);
            }
            break;

        case 3:
              system("cls");
              printf("\n\n\n\n\t\tYou have chosen to exit.");
              printf("\n\t\tAre you sure you want to exit (y/n)?  ");
              fflush(stdin);
                scanf("%c", &a);
                if(a=='y'){
                exit(0);
                }else{
                goto first;
                }

             break;



            default:
            goto first;
    }
}
    int main(){


        choicee();
      int board[5][5];
  initialize(board);
  printBoard(board);
  while(remGoat!=0){
    remGoat--;
    goat(board);
    tiger(board);
    if(kill==5){
        break;
    }
    }
   if(kill==5){
     printf("Tiger wins!!");
   }
   else{
     printf("\nGoat wins!!!");
     }
  return 0;


}

        int initialize(int board[5][5]){

  for(int x=0;x<5;x++){
    for(int y=0;y<5;y++){
        if((x==0 && y==0) || (x==0 && y==4) || (x==4 && y==0) || (x==4 && y==4)){
            board[x][y]=2;
        }
        else{
            board[x][y]=0;
        }
    }
  }
  return 0;
}

int printBoard(int board[5][5]){
    system("cls");
     int x=0,y=0;
     int a=0;

     if(choice1==1){
        printf("\n\nPlayer1 : Bagh\nPlayer2 : Goat\n");
     }else{
        printf("Player1 : Goat\nPlayer2 : Bagh\n");
     }
      printf("\t\t\t\t\t\t\t Remaining goat=%d",remGoat);
     printf("\n   0  1  2  3  4 \t\t\t\t\t Killed goats=%d\n",kill);
     for(x=0;x<=4;x++){
        printf("%d ",a);
        a++;
        for(y=0;y<=4;y++){
            printf("|");
          switch(board[x][y]){
            case 0:
                printf(" ");
                break;

            case 1:
                printf("G");
                break;

            case 2:
                printf("T");
                break;

            default:
                printf("Invalid");
                break;

          }
        printf(" ");
        }
        printf("|");
        printf("\n");
     }

}

int checkValidity(int x,int y){
   if((x>=0 && x<=4) && (y>=0 && y<=4)){
      return 1;
   }
   else{
      return 0;
   }
}
int goat(int board[5][5]){
    int  x,y, rp=0,val;
   while(rp==0){
     printf("\nGoat's turn=> ");
     fflush(stdin);
     scanf("%d%d",&x,&y);
     fflush(stdin);
     val=checkValidity(x,y); /*checking validity of position*/
     if(val==1){
       if(board[x][y]!=2 && board[x][y]!=1){ /*checking validity of position*/
       board[x][y]=1;
       system("cls");
       printBoard(board);
       break;
    }
          // break;
   }
   printf("Invalid move.\n");
}
return 0;
}

int tiger(int board[5][5]){
     int ox,oy,x,y,rp=0,val;
     int chgx,chgy;
     while(rp==0){
     printf("\nTiger's turn=> ");
     fflush(stdin);
     scanf("%d%d%d%d",&ox,&oy,&x,&y);
     val=checkValidity(x,y);
     if(board[ox][oy]==2 && val==1 && board[x][y]!=1){
         chgx=(ox+x)/2;
         chgy=(oy+y)/2;
       if(x==ox-1 || x==ox+1 || y==oy-1 || y==oy+1 || board[chgx][chgy]==1){
        if(board[chgx][chgy]==1){
          board[x][y]=2;
          board[ox][oy]=0;
          board[chgx][chgy]=0;
          system("cls");
          kill++;
          printBoard(board);

          break;
        }
          board[x][y]=2;
          board[ox][oy]=0;
          system("cls");
          printBoard(board);
          break;
     }
    }
     printf("Invalid move.\n");
     }
     return 0;
}
