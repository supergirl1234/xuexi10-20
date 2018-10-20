//扫雷
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//菜单
int Menu(){
	 int choice=0;
      printf("1,开始游戏\n");
	  printf("0,退出游戏\n");
	  printf("请输入你的选择：");
	  scanf("%d",&choice);


}
//游戏玩法
#define MINE_COUNT 10
#define ROW 9
#define COL 9
//使用二维数组来表示扫雷的地图，此处需要使用两个二维数组
//第一个二维数组表示地雷的雷阵
//第二个二维数组表示用户看到的地图
//扫雷的地图大小为9*9，但是我们准备把这个二维数组定义成11*11
//此时，我们地图的有效范围[1][ROW]和[1][COL]
//对于mine_map，使用'0'表示不是地雷，使用'1'表示是地雷
char mine_map[ROW+2][COL+2];
//对于show_map，使用'*'来表示未打开的方块，使用具体的数字来表示打开的方块
char show_map[ROW+2][COL+2];

void Init(char mine_map[ROW+2][COL+2],char show_map[ROW+2][COL+2]){
	int mine_count=0;
     //1.把数组进行初始化
     //对于mine_map,先把里面的所有元素都设置成'0'
	
	//可以把数组名理解为一个指向数组第一个元素的指针
	//memset()函数可以把一段连续的存储内存设置成某一个特定的值
	memset(mine_map,'0',(ROW+2)*(COL+2));
	//对于show_map,先把所有的元素都设置成'*'
	memset(show_map,'*',(ROW+2)*(COL+2));
	
	 //2随机的布置雷阵
	srand(time(0));//随机种子，time(0)得到了当前一个毫秒级别的时间，不能放在while循环中，会导致每次得到的时间一样
	
	
	mine_count=MINE_COUNT;
	while(mine_count>0){
	   //在这个循环中随机设置地雷，每次设置完成一个，就--mine_count
		int row=0;
		int col=0;
		
		row=rand()%9+1;
		col=rand()%9+1;
		//有可能要放雷的地方已经有雷了
		if(mine_map[row][col]=='0'){
		      mine_map[row][col]='1';
			  --mine_count;
		
		}

	
	}

	

}
void DisplayMap(char map[ROW+2][COL+2]){
	 int row=0;
	 int col=0;
   printf("   ");
   //打印第一行的内容，即列的坐标
  
   for(col=1;col<=COL;col++){
        printf("%d ",col);
   
   }
   printf("\n");
   //打印具体的地图
   //打印第二行，地图的上边框
   for( col=1;col<=COL;col++){
   
	   printf("---");
   }
   printf("\n");
   //按行打印地图中的具体内容
   for(row=1;row<=ROW;row++){
        //先打印出行号
	   printf("%02d|",row);
	   for(col=1;col<=COL;col++){
	      printf("%c ",map[row][col]);
	   }
	   printf("\n");

   
   }

}
//需要统计row、col、位置的元素周围有几个雷，并且把结果更新到show_map中
void UpdateShowMap(char show_map[ROW+2][COL+2],
				  char mine_map[ROW+2][COL+2],int row,int col){
       int mine_count=0;
	   mine_count=(mine_map[row-1][col-1]-'0')
               +(mine_map[row-1][col]-'0')
			   +(mine_map[row-1][col+1]-'0')
			   +(mine_map[row][col-1]-'0')
			   +(mine_map[row][col+1]-'0')
			   +(mine_map[row+1][col-1]-'0')
			   +(mine_map[row+1][col]-'0')
		       +(mine_map[row+1][col+1]-'0');
	  //也可用这种方法
	  /* if(mine_map[row-1][col-1]='1'){
	         ++mine_count;
	   }
	    if(mine_map[row-1][col]='1'){
	         ++mine_count;
	   }
		if(mine_map[row-1][col+1]='1'){
	         ++mine_count;
	   }
	    if(mine_map[row][col-1]='1'){
	         ++mine_count;
	   }
		if(mine_map[row][col+1]='1'){
	         ++mine_count;

	   }
		if(mine_map[row+1][col-1]='1'){
	         ++mine_count;

	   }
	    if(mine_map[row+1][col]='1'){
	         ++mine_count;

	   }
       if(mine_map[row+1][col+1]='1'){
	         ++mine_count;

	   }*/
	   show_map[row][col]='0'+mine_count;

}

void Game(){
    //非地雷的个数
	int not_mine_count=0;
	//1.初始化地图（mine_map，show_map），布置雷阵
	Init(mine_map,show_map);

	//2.打印show_map
	DisplayMap(show_map);

	while(1){
	//3.提示用户输入坐标[1,ROW][1,COL]
		int row=0;
		int col=0;
		printf("请输入要翻开的方块的坐标row col:");
		scanf("%d %d",&row,&col);
	//4.对用户输入的合法性进行判断，如果不合理，提示用户重新输入
		if(row<=0||row>ROW||col<=0||col>COL){
		    printf("您的输入不合法，请重新输入\n");
			continue;
		}
	//5.判定玩家当前是否踩雷，如果踩雷，游戏结束，并且打印雷阵
		if(mine_map[row][col]=='1'){
			   printf("游戏结束\n");
			   DisplayMap(mine_map);
		       break;
		  
		}
	//6.如果没踩雷，判定一下玩家是否胜利（胜利条件是：已经翻开的方块数达到了地图总方块总数减去地雷数的个数，此时游戏胜利）
		++not_mine_count;
		if(not_mine_count==ROW*COL-MINE_COUNT){
		     printf("扫雷成功\n");
			 DisplayMap(mine_map);
			 break;
		}
	//7.如果游戏没有胜利，就需要统计当前位置有几个雷，打印show_map,回到3
	    UpdateShowMap(show_map,mine_map,row,col);
		DisplayMap(show_map);

	}


}
//游戏入口
void Start(){

	while(1){
		int choice=0;
		choice=Menu();
		if(choice==0){
		     printf("退出游戏\n");
			 //退出游戏
			 break;
		}
		Game();
	}

}
int main(){

   Start();
   system("pause");
   return 0;
}