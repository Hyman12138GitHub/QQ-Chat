#include "head.h"
#include "cmd.h"

int Analy_Start_Cmd(char *cmd)
{
	if (0 == strcmp(cmd, "reg"))
	{
		return REG;
	}
	else if (0 == strcmp(cmd, "log"))
	{
		return LOG;
	}
	else if (0 == strcmp(cmd, "help"))
	{
		return USERHELP;
	}
	else if (0 == strcmp(cmd, "exit"))
	{
		return USEREXIT;
	}
	else
	{
		return ERROR;
	}
}

int Analy_Admin_Cmd(char *cmd)
{
	if (0 == strcmp(cmd, "chat"))
	{
		return CHAT;
	}
	else if (0 == strcmp(cmd, "all"))
	{
		return ALL;
	}
	else if (0 == strcmp(cmd, "see"))
	{
		return SEE;
	}
	else if (0 == strcmp(cmd, "data"))
	{
		return DATA;
	}
	else if (0 == strcmp(cmd, "face"))
	{
		return FACE;
	}
	else if (0 == strcmp(cmd, "hi"))
	{
		return HI;
	}
	else if (0 == strcmp(cmd, "trans"))
	{
		return TRANS;
	}
	else if (0 == strcmp(cmd, "password"))
	{
		return PASSWORD;
	}
	else if (0 == strcmp(cmd, "kick"))
	{
		return KICK;
	}
	else if (0 == strcmp(cmd, "shut"))
	{
		return SHUT;
	}
	else if (0 == strcmp(cmd, "remove"))
	{
		return REMOVE;
	}
	else if (0 == strcmp(cmd, "cancel"))
	{
		return CANCEL;
	}
	else if (0 == strcmp(cmd, "help"))
	{
		return HELP;
	}
	else if (0 == strcmp(cmd, "exit"))
	{
		return EXIT;
	}
	else
	{
		return ERROR;
	}
}

int Analy_Client_Cmd(char *cmd)
{
	if (0 == strcmp(cmd, "chat"))
	{
		return CHAT;
	}
	else if (0 == strcmp(cmd, "all"))
	{
		return ALL;
	}
	else if (0 == strcmp(cmd, "see"))
	{
		return SEE;
	}
	else if (0 == strcmp(cmd, "data"))
	{
		return DATA;
	}
	else if (0 == strcmp(cmd, "face"))
	{
		return FACE;
	}
	else if (0 == strcmp(cmd, "hi"))
	{
		return HI;
	}
	else if (0 == strcmp(cmd, "trans"))
	{
		return TRANS;
	}
	else if (0 == strcmp(cmd, "password"))
	{
		return PASSWORD;
	}
	else if (0 == strcmp(cmd, "change"))
	{
		return CHANGE;
	}
	else if (0 == strcmp(cmd, "help"))
	{
		return HELP;
	}
	else if (0 == strcmp(cmd, "exit"))
	{
		return EXIT;
	}
	else
	{
		return ERROR;
	}
}
