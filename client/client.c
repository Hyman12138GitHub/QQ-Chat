#include "head.h"
#include "pack.h"

int row = 9;
int nsee = 9;

int main(int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_in server_addr;
	struct hostent *host;
	struct chat temp;
	char cmd[MAX];
	int login = 0;
	int admin;
	pthread_t tid;
	time_t timep;
	char tm[MAX];

	if (argc != 2)
	{
		printf("Error! The Correct Format is\n./client 127.0.0.1\n");
		exit(1);
	}
	if (NULL == (host = gethostbyname(argv[1])))
	{
		printf("Error! gethostbyname failure!\n");
		exit(1);
	}
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Error! socket failure!\n");
		exit(1);
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr = *((struct in_addr *)host->h_addr);
	if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0)
	{
		printf("Error! connect failure!\n");
		exit(1);
	}
	Start();
	memset(&temp, 0, sizeof(struct chat));
	while (!login)
	{
		admin = 0;
		printf("\033[13;42H\033[38X");
		printf("\033[13;50H 请输入相应的命令：");
		My_Fgets(cmd, MAX, stdin);
		temp.cmd = Analy_Start_Cmd(cmd);
		switch (temp.cmd)
		{
			case REG:
				{
					Reg(sockfd, &temp);
					sleep(3);
					printf("\033[12;42H\033[38X");
					break;
				}
			case LOG:
				{
					Log(sockfd, &temp);
					if (0 == strcmp(temp.name, "admin"))
					{
						admin++;
					}
					memset(&temp, 0, sizeof(struct chat));
					temp.revert = -999;
					read(sockfd, &temp, sizeof(struct chat));
					printf("\033[11;42H\033[38X");
					if (PASSWORDOK == temp.revert)
					{
						admin++;
						printf("\033[11;47H 您已经登录成功，欢迎您的使用！\n");
						login = 1;
					}
					else if (PASSWORDNO == temp.revert)
					{
						printf("\033[11;50H\033[41m 密码错误或用户名不存在！\033[0m\n");
					}
					else if (ONLINEIN == temp.revert)
					{
						printf("\033[11;52H\033[41m 该用户已经登录！\033[0m\n");
					}
					else
					{
						printf("\033[11;50H\033[41m 接受到错误的服务器消息！\033[0m\n");
					}
					break;
				}

			case USERHELP:
				{
					printf("\033[13;42H\033[38X");
					printf("\033[13;48H\033[43mCopyright @ 2015-2016, Shen \033[0m\n");
					printf("\033[14;53H\033[43mAll Rights Reserve\033[0m\n");
					sleep(3);
					printf("\033[14;42H\033[38X");
					break;
				}

			case USEREXIT:
				{
					system("reset");
					exit(0);
				}

			default:
				{
					printf("\033[13;42H\033[38X");
					printf("\033[13;53H\033[41m您输入的命令有误！\033[0m\n");
					sleep(2);
				}
		}
	}

	if (2 == admin)
	{
		Admin_Start(temp.name);
	}
	else
	{
		Client_Start(temp.name);
	}

	pthread_create(&tid, NULL, Thread_Read,(void *)&sockfd);
	while (1)
	{
		Check_Screen();
		time(&timep);
		strcpy(tm, ctime(&timep));
		tm[strlen(tm) - 1] = '\0';
		printf("\033[27;2H\033[100X\033[1A\033[100X\033[1A\033[100X\033[1A\033[100X");
		fflush(stdout);
		My_Fgets(cmd, MAX, stdin);
		printf("\033[24;2H\033[100X");
		fflush(stdout);
		if (2 == admin)
		{
			temp.cmd = Analy_Admin_Cmd(cmd);
		}
		else
		{
			temp.cmd = Analy_Client_Cmd(cmd);
		}
		strcpy(temp.time, tm);
		switch (temp.cmd)
		{
			case CHAT:
				{
					Chat_One(sockfd, &temp);
					sleep(1);
					break;
				}

			case ALL:
				{
					Chat_All(sockfd, &temp);
					sleep(1);
					break;
				}

			case SEE:
				{
					Handle_See_Board();
					See(sockfd, &temp);
					sleep(3);
					break;
				}

			case DATA:
				{
					char ch[MAX] = "no";
					printf("\033[1;1H\033[J");
					fflush(stdout);
					Data(sockfd, &temp);
					sleep(3);
					printf("Please input yes\n");
					while (0 != strcmp(ch, "yes"))
					{
						My_Fgets(ch, MAX, stdin);
					}
					if (2 == admin)
					{
						Admin_Start(temp.name);
					}
					else
					{
						Client_Start(temp.name);
					}
					sleep(2);
					break;
				}

			case FACE:
				{
					Face(sockfd, &temp);
					sleep(1);
					break;
				}

			case HI:
				{
					Hi(sockfd, &temp);
					sleep(1);
					break;
				}
			case PASSWORD:
				{
					Password(sockfd, &temp);
					sleep(3);
					break;
				}

			case TRANS:
				{
					Trans(sockfd, &temp);
					sleep(5);
					break;
				}

			case CHANGE:
				{
					Change(sockfd, &temp);
					sleep(1);
					break;
				}
				
			case KICK:
				{
					Kick(sockfd, &temp);
					sleep(1);
					break;
				}

			case SHUT:
				{
					Shut(sockfd, &temp);
					sleep(1);
					break;
				}

			case REMOVE:
				{
					Remove(sockfd, &temp);
					sleep(1);
					break;
				}

			case CANCEL:
				{
					Cancel(sockfd, &temp);
					sleep(1);
					break;
				}

			case HELP:
				{
					if (2 == admin)
					{
						Admin_Start(temp.name);
					}
					else
					{
						Client_Start(temp.name);
					}
					sleep(1);
					break;
				}

			case EXIT:
				{
					Exit_Tell(sockfd, &temp);
					sleep(1);
					system("reset");
					exit(0);
				}

			default:
				{
					printf(" 您输入的命令有误！\n");
					sleep(1);
					break;
				}
		}
	}
	close(sockfd);
	return 0;
}
