#include"func.h"
int main(int argc,const char *argv[])
{
	printf("	欢迎使用通讯录	\n");
	printf("****************************************\n");
	printf("请输入通讯录类型：1.数组指针型   2.单链表型\n");
	printf(">");
	int type;
	scanf("%d", &type);
	if(type == 1)
	{
		Num a;
		Inituser(&a);
		int choice;
		while(1)
		{
			menu();
			printf("请输入>");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					Add_user(&a);
					break;
				case 2:
					View_user(&a);
					break;
				case 3:
					Search_user(&a);
					break;
				case 4:
					Delete_user(&a);
					break;
				case 5:
					Update_user(&a);
					break;
				case 6:
					printf("期待您的下次使用\n");
					sleep(3);
					exit(0);
					break;
				default:
					printf("ERROR：输入有误！请重新输入\n");
					break;
			}
		}
	}
	else if(type == 2)
	{
		linklist *head = LinklistCreate();
		int choice;
		char judgment;
		ReadData(head);
		while(1)
		{
			menu();
			printf("请输入>");
			scanf("%d",&choice);

			switch(choice)
			{
				case 1:
				STAR:
					LinklistInsertHead(head);
					printf("是否需要继续输入?(Y or N)\n");
					char judgment;
					scanf(" %c",&judgment);
				
					if(judgment == 'Y'|| judgment == 'y')
					{
						goto STAR;
					}
					else
					{
						break;
					}
				case 2:
					LinklistPrint(head);
					break;
				case 3:
					LinklistSearch(head);
					break;
				case 4:
					LinklistDelete(head);
					break;
				case 5:
					LinklistUpdate(head);
					break;
				case 6:
					printf("期待您的下次使用\n");
					WriteData(head);
					exit(0);
					break;
				default:
					printf("ERROR：输入有误！请重新输入\n");
					break;
			}
		}
	}
	return 0;
}