//三子棋作业
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//先定义二维数组表示棋盘
#define ROW 3
#define COL 3
char g_chess_board[ROW][COL];

//判断棋盘是否都满了
int IsFull(){
	int row=0;
	int col=0;
    for(row=0;row<ROW;row++){
		for(col=0;col<COL;col++){
			if(g_chess_board[row][col]!=' '){
			
			         return 0;
			
			}
		}
	
	}
     return 1;
}

//对棋盘进行初始化,全部初始化为空格
void Init(){
	int col=0;
	int row=0;
	for(row=0;row<ROW;row++){
		for(col=0;col<COL;col++){
			g_chess_board[row][col]=' ';
		}
	}

}
//打印一下棋盘
void Printchess ( ){
	 int row=0;
	 int col=0;
	for(row=0;row<3;row++){
		  printf("|%c|%c|%c|\n",g_chess_board[row][0],g_chess_board[row][1],g_chess_board[row][2]);
		  if(row!=ROW-1){
			  //避免最后一行还输出一个便捷
		      printf("|-|-|-|\n");
		
		  }
	  }
}


//玩家落子,玩家落得子为x
void Player(){
	int row=-1;
    int col=-1;
	while(1){
		printf("请输入落子的坐标row col:");
		
		scanf("%d %d",&row,&col);
		//判断输入的坐标是否有误
		if(row<0||row>=ROW||col<0||col>=COL){
			  printf("坐标超出范围,请重新输入坐标\n");
			  //scanf("%d %d",&row,&col);
			  continue;

		}else if(g_chess_board[row][col]!=' '){
			printf("该坐标已经有子，请重新输入坐标\n");
			//scanf("%d %d",&row,&col);
			continue; 

		}else{
		//将该坐标处落入x
		 g_chess_board[row][col]='x';
		 break;
		}
    }
	
}

//电脑落子，电脑落得子为o
void Computer(){
        int row=0;
		int col=0;
		//电脑落子，靠随机数产生一个行，随机数产生一个列
		printf("请电脑落子!\n");
		while(1){
		
		     row=rand()%ROW;
			 col=rand()%COL;
			 if(g_chess_board[row][col]==' '){
			    
				 //将该坐标处落入x 
	             g_chess_board[row][col]='o';
				 break;

			 }
		
		}
		 

}

//检查函数，检测游戏是否结束，判断谁是赢家，如果返回x表示玩家胜利，
//如果返回o表示电脑胜利，返回q表示和棋，
//如果返回空格表示胜负未分,未下完
int Check(){
	int row=0;
	int col=0;
	for(row=0;row<ROW;row++){
		//竖行相同
		if(g_chess_board[row][0]==g_chess_board[row][1]
		&&g_chess_board[row][0]==g_chess_board[row][2]
		&&g_chess_board[row][0]!=' '){
		      return g_chess_board[row][0];
		}
	}
	for(col=0;col<COL;col++){
		//横行相同
		if(g_chess_board[0][col]==g_chess_board[1][col]
		&&g_chess_board[0][col]==g_chess_board[2][col]
		&&g_chess_board[0][col]!=' '){
		      return g_chess_board[0][col];
		}
	}
		//对角线相同
		if(g_chess_board[0][0]==g_chess_board[1][1]
		&&g_chess_board[0][0]==g_chess_board[2][2]
		&&g_chess_board[0][0]!=' '){
		      return g_chess_board[0][0];
		}
		if(g_chess_board[0][2]==g_chess_board[1][1]
		&&g_chess_board[0][0]==g_chess_board[2][0]
		&&g_chess_board[0][2]!=' '){
			return g_chess_board[0][2];
		      
		}
		//是否和棋
		if(IsFull()){
		   return 'q';
		}
		return ' ';
		 
	
   

}


int main(){
	
	
	char winner=' ';
	//对棋盘进行初始化  
	Init();
    while(1){
	  //打印棋盘
		 Printchess(g_chess_board);

		  //玩家落子
		   Player();
		  
		  winner=Check(); 
		  if(winner!=' '){ 
			  //游戏结束
			  break;
		  
		  }
		  //电脑落子
		 Computer();

		  winner=Check(); 
		  if(winner!=' '){
			  //游戏结束
			  break;
	  
	  }
   }
	  if(winner=='x'){
		  printf("玩家获胜!\n");
		  
	  
	  }else if(winner=='o'){
		   printf("电脑获胜!\n");
		  
	  }else if(winner=='q'){
		   printf("和棋!\n");
		  
	  
	  }

    system("pause");
	return 0;
}