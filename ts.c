




#include<stdio.h>
int read(int ,char *,int); 
int main(){
	char b1[1024];
	char b2[1024]; 
	//char src[]={'F','F','m','p','e','g'}; 
char src[]={0x47,0x40,0x11,0x14,0x00,0x42,0xf0,0x25,0x00,0x01 ,0xc1,0x00 ,0x00,0xff ,0x01,0xff}; 
	char *re=0;
	char *re1=0; 
	int ret=0;
	int ok=0;
	int oksize=sizeof(src); 
	re=b1; 
	int size=1; 
	while(size){
		size=read(0,re,1024);
		for(int i=0; i<size; i++){
			if(*re==src[ok]){
				ok++;
				if(ok==oksize){
					printf("ok\n");
				}
			}
			else{
				if(re1)re1=0;
				ok=0;
			}
			re++; 
		}
		if(ok>1){
			re1=re; 
			re=b2;
		}
		else{
			if(re1) 
				re1=0; 
			re=b1;
		}
	}
}
