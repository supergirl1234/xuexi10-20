//ɨ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�˵�
int Menu(){
	 int choice=0;
      printf("1,��ʼ��Ϸ\n");
	  printf("0,�˳���Ϸ\n");
	  printf("���������ѡ��");
	  scanf("%d",&choice);


}
//��Ϸ�淨
#define MINE_COUNT 10
#define ROW 9
#define COL 9
//ʹ�ö�ά��������ʾɨ�׵ĵ�ͼ���˴���Ҫʹ��������ά����
//��һ����ά�����ʾ���׵�����
//�ڶ�����ά�����ʾ�û������ĵ�ͼ
//ɨ�׵ĵ�ͼ��СΪ9*9����������׼���������ά���鶨���11*11
//��ʱ�����ǵ�ͼ����Ч��Χ[1][ROW]��[1][COL]
//����mine_map��ʹ��'0'��ʾ���ǵ��ף�ʹ��'1'��ʾ�ǵ���
char mine_map[ROW+2][COL+2];
//����show_map��ʹ��'*'����ʾδ�򿪵ķ��飬ʹ�þ������������ʾ�򿪵ķ���
char show_map[ROW+2][COL+2];

void Init(char mine_map[ROW+2][COL+2],char show_map[ROW+2][COL+2]){
	int mine_count=0;
     //1.��������г�ʼ��
     //����mine_map,�Ȱ����������Ԫ�ض����ó�'0'
	
	//���԰����������Ϊһ��ָ�������һ��Ԫ�ص�ָ��
	//memset()�������԰�һ�������Ĵ洢�ڴ����ó�ĳһ���ض���ֵ
	memset(mine_map,'0',(ROW+2)*(COL+2));
	//����show_map,�Ȱ����е�Ԫ�ض����ó�'*'
	memset(show_map,'*',(ROW+2)*(COL+2));
	
	 //2����Ĳ�������
	srand(time(0));//������ӣ�time(0)�õ��˵�ǰһ�����뼶���ʱ�䣬���ܷ���whileѭ���У��ᵼ��ÿ�εõ���ʱ��һ��
	
	
	mine_count=MINE_COUNT;
	while(mine_count>0){
	   //�����ѭ����������õ��ף�ÿ���������һ������--mine_count
		int row=0;
		int col=0;
		
		row=rand()%9+1;
		col=rand()%9+1;
		//�п���Ҫ���׵ĵط��Ѿ�������
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
   //��ӡ��һ�е����ݣ����е�����
  
   for(col=1;col<=COL;col++){
        printf("%d ",col);
   
   }
   printf("\n");
   //��ӡ����ĵ�ͼ
   //��ӡ�ڶ��У���ͼ���ϱ߿�
   for( col=1;col<=COL;col++){
   
	   printf("---");
   }
   printf("\n");
   //���д�ӡ��ͼ�еľ�������
   for(row=1;row<=ROW;row++){
        //�ȴ�ӡ���к�
	   printf("%02d|",row);
	   for(col=1;col<=COL;col++){
	      printf("%c ",map[row][col]);
	   }
	   printf("\n");

   
   }

}
//��Ҫͳ��row��col��λ�õ�Ԫ����Χ�м����ף����Ұѽ�����µ�show_map��
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
	  //Ҳ�������ַ���
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
    //�ǵ��׵ĸ���
	int not_mine_count=0;
	//1.��ʼ����ͼ��mine_map��show_map������������
	Init(mine_map,show_map);

	//2.��ӡshow_map
	DisplayMap(show_map);

	while(1){
	//3.��ʾ�û���������[1,ROW][1,COL]
		int row=0;
		int col=0;
		printf("������Ҫ�����ķ��������row col:");
		scanf("%d %d",&row,&col);
	//4.���û�����ĺϷ��Խ����жϣ������������ʾ�û���������
		if(row<=0||row>ROW||col<=0||col>COL){
		    printf("�������벻�Ϸ�������������\n");
			continue;
		}
	//5.�ж���ҵ�ǰ�Ƿ���ף�������ף���Ϸ���������Ҵ�ӡ����
		if(mine_map[row][col]=='1'){
			   printf("��Ϸ����\n");
			   DisplayMap(mine_map);
		       break;
		  
		}
	//6.���û���ף��ж�һ������Ƿ�ʤ����ʤ�������ǣ��Ѿ������ķ������ﵽ�˵�ͼ�ܷ���������ȥ�������ĸ�������ʱ��Ϸʤ����
		++not_mine_count;
		if(not_mine_count==ROW*COL-MINE_COUNT){
		     printf("ɨ�׳ɹ�\n");
			 DisplayMap(mine_map);
			 break;
		}
	//7.�����Ϸû��ʤ��������Ҫͳ�Ƶ�ǰλ���м����ף���ӡshow_map,�ص�3
	    UpdateShowMap(show_map,mine_map,row,col);
		DisplayMap(show_map);

	}


}
//��Ϸ���
void Start(){

	while(1){
		int choice=0;
		choice=Menu();
		if(choice==0){
		     printf("�˳���Ϸ\n");
			 //�˳���Ϸ
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