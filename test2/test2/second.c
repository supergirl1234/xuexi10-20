//��������ҵ
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//�ȶ����ά�����ʾ����
#define ROW 3
#define COL 3
char g_chess_board[ROW][COL];

//�ж������Ƿ�����
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

//�����̽��г�ʼ��,ȫ����ʼ��Ϊ�ո�
void Init(){
	int col=0;
	int row=0;
	for(row=0;row<ROW;row++){
		for(col=0;col<COL;col++){
			g_chess_board[row][col]=' ';
		}
	}

}
//��ӡһ������
void Printchess ( ){
	 int row=0;
	 int col=0;
	for(row=0;row<3;row++){
		  printf("|%c|%c|%c|\n",g_chess_board[row][0],g_chess_board[row][1],g_chess_board[row][2]);
		  if(row!=ROW-1){
			  //�������һ�л����һ�����
		      printf("|-|-|-|\n");
		
		  }
	  }
}


//�������,��������Ϊx
void Player(){
	int row=-1;
    int col=-1;
	while(1){
		printf("���������ӵ�����row col:");
		
		scanf("%d %d",&row,&col);
		//�ж�����������Ƿ�����
		if(row<0||row>=ROW||col<0||col>=COL){
			  printf("���곬����Χ,��������������\n");
			  //scanf("%d %d",&row,&col);
			  continue;

		}else if(g_chess_board[row][col]!=' '){
			printf("�������Ѿ����ӣ���������������\n");
			//scanf("%d %d",&row,&col);
			continue; 

		}else{
		//�������괦����x
		 g_chess_board[row][col]='x';
		 break;
		}
    }
	
}

//�������ӣ����������Ϊo
void Computer(){
        int row=0;
		int col=0;
		//�������ӣ������������һ���У����������һ����
		printf("���������!\n");
		while(1){
		
		     row=rand()%ROW;
			 col=rand()%COL;
			 if(g_chess_board[row][col]==' '){
			    
				 //�������괦����x 
	             g_chess_board[row][col]='o';
				 break;

			 }
		
		}
		 

}

//��麯���������Ϸ�Ƿ�������ж�˭��Ӯ�ң��������x��ʾ���ʤ����
//�������o��ʾ����ʤ��������q��ʾ���壬
//������ؿո��ʾʤ��δ��
int Check(){
	int row=0;
	int col=0;
	for(row=0;row<ROW;row++){
		//������ͬ
		if(g_chess_board[row][0]==g_chess_board[row][1]
		&&g_chess_board[row][0]==g_chess_board[row][2]
		&&g_chess_board[row][0]!=' '){
		      return g_chess_board[row][0];
		}
	}
	for(col=0;col<COL;col++){
		//������ͬ
		if(g_chess_board[0][col]==g_chess_board[1][col]
		&&g_chess_board[0][col]==g_chess_board[2][col]
		&&g_chess_board[0][col]!=' '){
		      return g_chess_board[0][col];
		}
	}
		//�Խ�����ͬ
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
		//�Ƿ����
		if(IsFull()){
		   return 'q';
		}
		return ' ';
		 
	
   

}


int main(){
	
	
	char winner=' ';
	//�����̽��г�ʼ��  
	Init();
 while(1 ){
	  //��ӡ����
	 Printchess(g_chess_board);

	  //�������
	   Player();
	  
	  winner=Check(); 
	  if(winner!=' '){ 
		  //��Ϸ����
		  break;
	  
	  }
	  //��������
     Computer();

	  winner=Check(); 
	  if(winner!=' '){
		  //��Ϸ����
		  break;
	  
	  }
   }
	  if(winner=='x'){
		  printf("��һ�ʤ!\n");
		  
	  
	  }else if(winner=='o'){
		   printf("���Ի�ʤ!\n");
		  
	  }else if(winner=='q'){
		   printf("����!\n");
		  
	  
	  }

    system("pause");
	return 0;
}