//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
//输入例子: 1999 2299 输出例子:7
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//先求出每一个数的二进制
void Bit(int *arr,int n){
	int i=0;
	for(i=31;i>=0,n>0;i--){
			if(n%2==0){
				arr[i]=0;
			}
			else{
				arr[i]=1;
			}
		n=n/2;
			 
	}
}

int main(){
  int num1=0;
  int num2=0;
  int arr1[32]={0};
  int arr2[32]={0};
  int i=0;
  int count=0;
  printf("请输入两个整数：");
  scanf("%d %d",&num1,&num2);
   Bit(arr1,num1);
   Bit(arr2,num2);
   for(i=0;i<32;i++){
	   if(arr1[i]!=arr2[i]){
	        count++;
	 }
   }
  printf("这两个数有%d个位不同",count);
  system("pause");
  return 0;

  }








