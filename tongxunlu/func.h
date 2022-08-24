#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>

#define MAX 1000
#define MAX_ID 20
#define MAX_NAME 20
#define MAX_IPHONE 20
#define MAX_SEX 20
#define DataType int

typedef struct{
	char id[MAX_ID];
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char iphone[MAX_IPHONE];
}User;//每个人的用户信息

typedef struct{
	User data[MAX]; 
	int count;
}Num;//信息与人数

typedef struct list{
	User person;
	struct list *next;
}linklist;

/*typedef struct list{
	char id[MAX_ID];
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char iphone[MAX_IPHONE];
	struct list *next;
}linklist;*/

//数组
size_t Mystrlen(const char *s);
int Mystrcmp(char *dest,const char *src);
void menu();
void Inituser(Num *p);
void Add_user(Num *p);
void View_user(Num *p);
void Search_user(Num *p);
void Delete_user(Num *p);
void Update_user(Num *p);
//单链表
linklist* LinklistCreate();
bool LinklistIsEmpty(linklist *head);
void LinklistInsertHead(linklist *head);
void LinklistPrint(linklist *head);
void LinklistSearch(linklist *head);
void LinklistDelete(linklist *head);
void LinklistUpdate(linklist *head);
void LinklistInsertTail(linklist *head,User value);
void ReadData(linklist *head);
void WriteData(linklist *head);