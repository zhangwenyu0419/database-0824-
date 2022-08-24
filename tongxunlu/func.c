#include"func.h"


void menu()
{
	printf(" -------------------------\n");
	printf("|	1.添加用户        |\n");
	printf("|	2.查看用户        |\n");
	printf("|	3.搜索用户        |\n");
	printf("|	4.删除用户信息    |\n");
	printf("|	5.修改用户信息    |\n");
	printf("|	6.退出            |\n");
	printf(" -------------------------\n");
}
linklist* LinklistCreate()
{
	linklist *head = (linklist *)malloc(sizeof(linklist));
	head->next = NULL;
	return head;
}
void LinklistInsertHead(linklist *head)
{
	linklist *tmp = (linklist *)malloc(sizeof(linklist));
	tmp->next = NULL;
	printf("请输入ID：");
	scanf("%s",tmp->person.id);
	printf("请输入名字：");
	scanf("%s",tmp->person.name);
	printf("请输入性别：");
	scanf("%s",tmp->person.sex);
	printf("请输入手机号码：");
	scanf("%s",tmp->person.iphone);
	tmp->next = head->next;
	head->next = tmp;

	printf("输入结束，正在跳转菜单!\n");

}
void LinklistSearch(linklist *head)
{
	if(LinklistIsEmpty(head))
	{
		printf("ERROR:链表为空，查找失败！\n");
		return;
	}
	int choice;
	linklist *p = head->next;
	printf("请输入查找方式：1.通过id 2.通过姓名\n");
	printf("请输入>");
	scanf("%d",&choice);
	if(1 == choice)
	{
		printf("请输入需要查找的id：");
		char id[20] = {0};
		scanf("%s",id);
		while(p != NULL)
		{
			if(Mystrcmp(id,p->person.id) == 0)
			{
				printf("查找结果如下:\n");
				printf("ID:%-8s姓名:%-20s性别:%-8s手机号码:%-11s\n",p->person.id,p->person.name,p->person.sex,p->person.iphone);
				sleep(3);
				break;
			}
			p = p->next;
		}
	}
	else if(2 == choice)
	{
		printf("请输入需要查找的名字：");
		char name[20] = {0};
		scanf("%s",name);
		while(p != NULL)
		{
			if(Mystrcmp(name,p->person.name) == 0)
			{
				printf("查找结果如下:\n");
				printf("ID:%-8s姓名:%-20s性别:%-8s手机号码:%-11s\n",p->person.id,p->person.name,p->person.sex,p->person.iphone);
				sleep(3);
				break;
			}
			p = p->next;
		}
	}
}
void LinklistDelete(linklist *head)
{
	if(LinklistIsEmpty(head))
	{
		printf("ERROR:链表为空，删除失败！\n");
		return;
	}
	linklist *p,*q;
	p = head->next;
	char id[MAX_ID] = {0};
	printf("请输入需要删除的ID：");
	scanf("%s",id);
	while(p != NULL)
	{	
		if(Mystrcmp(id,p->person.id) == 0)//头结点后第一个元素就是
		{
			if(p->next != NULL)
			{
				head->next = p->next;
				printf("删除中.........\n");
				free(p);
				p = NULL;
				sleep(1);
				printf("删除成功！\n");
				break;
			}else if(p->next == NULL)
			{
				head->next = NULL;
				printf("删除中.........\n");
				free(p);
				p = NULL;
				sleep(1);
				printf("删除成功！\n");
				break;
			}
		}
		q = p;
		p = p->next;//两个结点以上
		if(Mystrcmp(id, p->person.id) == 0)
		{
			if(p->next == NULL)
			{
				printf("删除中.........\n");
				free(p);
				p = NULL;
				sleep(1);
				printf("删除成功！\n");
				break;
			}else if(p->next != NULL)
			{
				q->next = p->next;
				printf("删除中.........\n");
				free(p);
				p = NULL;
				sleep(1);
				printf("删除成功！\n");
				break;
			}
		}
	}
}
void LinklistUpdate(linklist *head)
{
	if(LinklistIsEmpty(head))
	{
		printf("ERROR:链表为空，修改失败！\n");
		return;
	}
	linklist *p = head->next;
	char id[20] = {0};
	printf("请输入需要修改的ID：");
	scanf("%s",id);
	while(p != NULL)
	{
		if(Mystrcmp(id,p->person.id) == 0)
		{
			int choice;
			printf("请输入需要修改的内容：1.姓名 2.性别 3.电话号码\n");
			printf(">");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					printf("请输入新姓名：");
					scanf("%s",p->person.name);
					break;
				case 2:
					printf("请输入新性别：");
					scanf("%s",p->person.sex);
					break;
				case 3:
					printf("请输入新手机号码：");
					scanf("%s",p->person.iphone);
					break;
				default: 
					printf("ERROR：输入错误！\n");
					break;
			}
		}
		p = p->next;
	}

}
bool LinklistIsEmpty(linklist *head)
{
	return head->next == NULL ? 1 : 0;
}
void  LinklistPrint(linklist *head)
{
	linklist *q = head->next;
	//p->person = data;
	if(LinklistIsEmpty(head))
	{
		printf("ERROR:链表为空，查看失败！\n");
		return;
	}
	while(q != NULL)
	{
		printf("ID:%-8s姓名:%-20s性别:%-8s手机号码:%-11s\n",q->person.id,q->person.name,q->person.sex,q->person.iphone);
		putchar(10);
		q = q->next;
	}
}
void ReadData(linklist *head)
{
	User p1;
	bzero(&p1, sizeof(p1));
	FILE *fp = fopen("./message.txt", "r");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}
	
	while(1)
	{
		if(0 == fread(&p1, sizeof(p1), 1, fp))
		{
			if(feof(fp))
			{
				perror("读取文件内容");
				break;
			}
			else
			{
				perror("fread");
				return;
			}
		}
		LinklistInsertTail(head,p1);
	}
	if(-1 == fclose(fp))
	{
		perror("fclose");
		return;
	}
	
}
void WriteData(linklist *head)
{
	FILE *fp = fopen("./message.txt", "w");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}
	linklist *tmp = head->next;
	while(tmp != NULL)
	{
		if(1 != fwrite(&tmp->person,sizeof(tmp->person),1,fp))
		{
			perror("fwrite");
			return -1;
		}
		tmp = tmp->next;
	}
	if(-1 == fclose(fp))
	{
		perror("fclose");
		return;
	}
}
void LinklistInsertTail(linklist *head,User value)
{
	linklist *tmp = (linklist *)malloc(sizeof(linklist));
	tmp->next = NULL;
	tmp->person = value;

	linklist *p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}

	tmp->next = p->next;
	p->next = tmp;
	return;
}

//数组指针 
void Inituser(Num *p)
{
	memset(p->data,0,sizeof(p->data));
	p->count = 0;
}

void Add_user(Num *p)
{	
	int i = 0;
	int ret;
	int cmp;
	char enter;
	while(1)
	{
sign_add:
		printf("请输入4位ID：");
		scanf("%s",p->data[p->count].id);
		for(i = 0;i < p->count ; i++)
		{
			cmp = Mystrcmp(p->data[p->count].id,p->data[i].id);
			if(cmp == 0)
			{
				printf("ERROR：ID重复，请重新输入！\n");
				goto sign_add;
			}
		}
		char *str = p->data[p->count].id;
		while(*str != '\0')
		{
			if(*str < '0' || *str > '9')
			{
				printf("ERROR：包含非数字内容，请重新输入！\n");
				goto sign_add;
			}
			str++;
		}			
		ret = Mystrlen(p->data[p->count].id);
		if(ret != 4)
		{
			printf("ERROR:ID不是四位，请重新输入！\n");
		}else
		{
			break;
		}
	}
	putchar(10);
	printf("请输入姓名：");
	scanf("%s",p->data[p->count].name);
	putchar(10);
	printf("请输入性别：");
	scanf("%s",p->data[p->count].sex);
	putchar(10);
	while(1)
	{
sign_add2:
		printf("请输入11位手机号码：");
		scanf("%s",p->data[p->count].iphone);
		for(i = 0;i < p->count ; i++)
		{
			cmp = Mystrcmp(p->data[p->count].iphone,p->data[i].iphone);
			if(cmp == 0)
			{
				printf("ERROR：电话号码重复，请重新输入！\n");
				goto sign_add2;
			}
		}
		char *str2 = p->data[p->count].iphone;
		while(*str2 != '\0')
		{
			if(*str2 < '0' || *str2 > '9')
			{
				printf("ERROR：包含非数字内容，请重新输入！\n");
				goto sign_add2;
			}
			str2++;
		}			
		ret = Mystrlen(p->data[p->count].iphone);
		if(ret != 11)
		{
			printf("ERROR:手机号码不足十一位，请重新输入！\n");
		}else
		{
			break;
		}
	}
	putchar(10);
	printf("添加通信人成功！\n");
	(p->count)++;
	printf("********************\n");
	printf("输入任意键退出\n");
	scanf(" %c",&enter);
	sleep(1);
	system("clear");
}

void View_user(Num *p)
{
	int i,j;
	for(i = 0 ; i < p->count-1; i++)
	{
		for(j = 0 ; j < p->count-1-i ; j++)
		{
			if(Mystrcmp(p->data[j].name,p->data[j+1].name) > 0)
			{
				User temp = p->data[j];
				p->data[j] = p->data[j+1];
				p->data[j+1] = temp;
			}
		}
	}
	printf("*********************************************************************************************************\n");
	for(i = 0 ; i < p->count ; i++)
	{
		printf("ID:%-8s姓名:%-20s性别:%-8s手机号码:%-11s\n",p->data[i].id,p->data[i].name,p->data[i].sex,p->data[i].iphone);
		putchar(10);
	}
	printf("*********************************************************************************************************\n");
	sleep(3);
	system("clear");
}
void Search_user(Num *p)
{
	printf("****************************************************\n");
	printf("请选择查找方式：1.通过id	2.通过姓名\n");
	printf("****************************************************\n");
	int input;
	int i;
	char id[20] = {0};
	char name[20] = {0};
	int ret;
	printf("请输入>");
	scanf("%d",&input);
	if(input == 1)
	{
		printf("请输入id： ");
		scanf("%s",id);
		for(i = 0 ; i < p->count ; i++)
		{
			ret = Mystrcmp(id,p->data[i].id);
			if(ret == 0)
			{	
				printf("*********************************************************************************************************\n");
				printf("查找结果如下！：");
				printf("ID:%-8s姓名:%-20s性别:%-8s手机号码:%-11s\n",p->data[i].id,p->data[i].name,p->data[i].sex,p->data[i].iphone);
				printf("*********************************************************************************************************\n");
				putchar(10);
				sleep(3);
				system("clear");
			}
		}
	}
	else if(input == 2)
	{
		printf("请输入姓名： ");
		scanf("%s",name);
		for(i = 0 ; i < p->count ; i++)
		{
			ret = Mystrcmp(name,p->data[i].name);
			if(ret == 0)
			{
				printf("*********************************************************************************************************\n");
				printf("查找结果如下！：");
				printf("ID:%-8s姓名:%-20s性别:%-8s手机号码:%-11s\n",p->data[i].id,p->data[i].name,p->data[i].sex,p->data[i].iphone);
				printf("*********************************************************************************************************\n");
				putchar(10);
				sleep(3);
				system("clear");
			}
		}
	}else
	{
		printf("********************\n");
		printf("ERROR：输入错误！\n");
		printf("********************\n");
		sleep(3);
		system("clear");
	}
}
void Delete_user(Num *p)
{
	char id[20] = {0};
	int i,j;
	int pos;
	int ret;
	printf("请输入需要删除信息的ID：  ");
	scanf("%s",id);
	for(i = 0 ; i < p->count ; i++)
	{
		ret = Mystrcmp(id,p->data[i].id);
		if(ret == 0)
		{
			pos = i;
			break;
		}else
		{
			pos = -1;
		}
	}
	if(pos == -1)
	{
		printf("查无此人！\n");
	}else
	{
		printf("正在删除中********\n");
		sleep(1);
		
		for(j = pos ; j < p->count-1 ; j++)
		{
			p->data[j] = p->data[j+1];
		}
		(p->count)--;
		printf("删除成功！\n");
		sleep(3);
		system("clear");
	}
}
void Update_user(Num *p)
{
	char id[20] = {0};
	int i;
	int pos;
	int ret;
	int input;
	printf("请输入需要修改信息的ID： ");
	scanf("%s",id);
	for(i = 0 ; i < p->count ; i++)
	{
		ret = Mystrcmp(id,p->data[i].id);
		if(ret == 0)
		{
			pos = i;
			break;
		}else
		{
			pos = -1;
		}
	}
	if(pos == -1)
	{
		printf("查无此人！\n");
	}else
	{
		printf("*************************************\n");
		printf("请问需要修改ID为%s的什么信息？\n",id);
		printf("*************************************\n");
		printf("1.姓名  2.性别  3.手机号码\n");
		printf("*************************************\n");
		printf("请输入>");
		scanf("%d",&input);
		if(input == 1)
		{
			printf("请输入新的姓名：");
			scanf("%s",p->data[pos].name);
			printf("*********************************************************************************************************\n");
			printf("更新后如下：");
			printf("ID:%-8s姓名:%-20s性别:%-8s手机号码:%-11s\n",p->data[i].id,p->data[i].name,p->data[i].sex,p->data[i].iphone);
			printf("*********************************************************************************************************\n");
			sleep(3);
			system("clear");
		}
		else if(input == 2)
		{
			printf("请输入新的性别：");
			scanf("%s",p->data[pos].sex);
			printf("*********************************************************************************************************\n");
			printf("更新后如下：");
			printf("ID:%-8s姓名:%-20s性别:%-8s手机号码:%-11s\n",p->data[i].id,p->data[i].name,p->data[i].sex,p->data[i].iphone);
			printf("*********************************************************************************************************\n");
			sleep(3);
			system("clear");
		}
		else if(input == 3)
		{
	//		printf("请输入新的手机号码：");
	//		scanf("%s",p->data[pos].iphone);
			while(1)
			{
				printf("请输入11位手机号码：");
				scanf("%s",p->data[pos].iphone);
				ret = Mystrlen(p->data[pos].iphone);
				if(ret != 11)
				{
					printf("ERROR:手机号码不足十一位，请重新输入！\n");
				}else
				{
					break;
				}
			}
			printf("*********************************************************************************************************\n");
			printf("更新后如下：");
			printf("ID:%-8s姓名:%-20s性别:%-8s手机号码:%-11s\n",p->data[i].id,p->data[i].name,p->data[i].sex,p->data[i].iphone);
			printf("*********************************************************************************************************\n");
			sleep(3);
			system("clear");
		}else
		{
			printf("**************\n");
			printf("输入错误！\n");
			printf("**************\n");
			sleep(3);
			system("clear");
		}

	}
}
int Mystrcmp(char *dest,const char *src)
{
	while(*dest == *src && *dest != '\0')
	{
		dest++;
		src++;
	}
	return *dest - *src;
}
size_t Mystrlen(const char *s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	return i;
}