#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 1024

int main(void){
	FILE* fp = fopen("C:\\Users\\Administrator\\Desktop\\test.txt","r");
	char arr1[LEN];
	char arr2[LEN];
	char arr3[LEN];
	char arr4[LEN];
	char arr5[LEN];
	int num;
	
	if(fp == NULL){
		fprintf(stderr,"Can not open file");
		return -1;
	}
	
	fscanf(fp,"%s%d %[^\n]%*c",arr1,&num,arr2);//%*c to read a character right where the pointer is
						   // * to tell that dont store the character
 						   //after this statement the pointer points to '\n' character
						   //if dont skip it, the next statement can not use [^\n] because
						   //the string is started with '\n' which stop this function from reading
						   //so there is nothing to read now, result is an error.
	fscanf(fp,"%[^\n]",arr3);		   //[^list of character that stop this function from reading, ;,abv...]
	fseek(fp,0,SEEK_SET);			   //set the pointer points to the begin of the file
	fscanf(fp,"string1 1234 string2%[^\n]",arr4);//type exactly what data you wanna skip to move the pointer through it
						   //'\n' charracter can be write as a white space character
	printf("%s\n%d\n%s\n%s\n",arr1,num,arr2,arr3);
	puts("=============================");
	printf("arr4: %s\n",arr4);
	


	puts("=============================");
	fseek(fp,0,SEEK_SET);
	while(feof(fp) == 0){//check whether the pointer reach to the end of file, it it does, feof(fp) returns 1, else 0
		fscanf(fp,"%[^\n]%*c",arr5);//Rember that if you use [^\n], you have to make the pointer move through it, else, next
		printf("feof test: %s\n",arr5);	    //statement will see the '\n' first and it will stop and this loop will be forever.
	}
	fseek(fp,0,SEEK_SET);
	
	
	
	puts("=============================");
	while((fscanf(fp,"%[^\n]%*c",arr5)) != EOF){//fscanf will read all data until seeing '\n', pointer will skip this character
						   //because of %*c, then while-loop will check if the return of scanf is EOF or not
						   //if it is not EOF, continue reading data. When pointer points to the end of file
						   //There is nothing to read so fscanf will return EOF
						   //Note that EOF will only be returned when there is nothing to read, as when the pointer
						   //points to the end of file. If there is data but fscanf is fail to read it or read
						   //nothing from it then frscanf will return NULL or zero. 
						   //So if you use while((fscanf(fp,"%[^\n]%*c",arr5)) != NULL) the loop will run
						   //forever because the last fscanf returns EOF has value = -1 (!= NULL).
					//-If you just use %[^\n] instead of %[^\n]%*c, this loop will stop right when seeing the 
					// first '\n' because you tell fread to stop reading data when seeing '\n' so he will read 
					// so he will read nothing in the second time and he will return 0 = NULL and make the loop stop
		printf("fscanf test: %s\n",arr5);
	}
	puts("=============================");
	int b = ftell(fp);
	fseek(fp,0,SEEK_SET);
	int a = ftell(fp); //ftell will return the current position of the pointer
	printf("position before fseek = %d\nposition after fseek: %d\n",b,a);
	puts("=============================");
	a = fread(arr5,1,1000,fp);
	printf("number of read characters: %d\n",a);
	printf("test fread: %s",arr5);
	
}
