/**************************************************************************************************/
/* Copyright (C) WangQi, SSE@USTC, 2014-2015                                                      */
/*                                                                                                */
/*  FILE NAME             :  menu2.c                                                              */
/*  PRINCIPAL AUTHOR      :  Mengning,WangQi                                                      */
/*  SUBSYSTEM NAME        :  menu2                                                                */
/*  MODULE NAME           :  menu2                                                                */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/14                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by WangQi, 2014/09/14
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

#define CMD_MAX_LEN 128
#define DESC_LEN    1024

int Help();

static tDataNode head[] = 
{
        {"help", "this is help command", Help,&head[1]},
	{"dir", "this is dir command", Help,&head[2]},
	{"mdelete", "this is mdelete command", Help, &head[3]},
	{"qc", "this is qc command", Help, &head[4]},
	{"site", "this is site command", Help, &head[5]},
	{"disconnect", "this is disconnect command", Help, &head[6]},
	{"mdir", "this is mdir command", Help, &head[7]},
	{"sendport", "this is sendport command", Help, &head[8]},
	{"size", "this is size command", Help, &head[9]},
	{"account", "this is account command", Help, &head[10]},
	{"exit", "this is exit command", Help, &head[11]},
	{"mget", "this is mget command", Help, &head[12]},
	{"glob", "this is glob command", Help, &head[13]},
        {"get", "this is get command", NULL, NULL}
};

void main()
{
   /* cmd line begins */
    const char *help = "help";
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Please input a command > ");
        scanf("%s", cmd);
	if(strcmp(cmd,help)==0)
	{
	    Help();
	    continue;
	}
        tDataNode *p = FindCmd(head,cmd);
	while(p != NULL)
        {
	    if(strcmp(p->cmd, cmd)==0)
            {
                printf("%s - %s\n", p->cmd, p->desc);
                break;
            }
            p = p->next;
         }
	 if(p == NULL) 
         {
            printf("This is a wrong command!\n ");
	    continue;
         }
    }
}

int Help()
{
    FindAllCmd(head);
    return 0; 	
}