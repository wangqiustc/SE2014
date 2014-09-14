/**************************************************************************************************/
/* Copyright (C) WangQi, SSE@USTC, 2014-2015                                                      */
/*                                                                                                */
/*  FILE NAME             :  linklish.c                                                           */
/*  PRINCIPAL AUTHOR      :  WangQi                                                               */
/*  SUBSYSTEM NAME        :  menu2                                                                */
/*  MODULE NAME           :  linklist                                                             */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/14                                                           */
/*  DESCRIPTION           :  This is a linklist for menu2 program                                 */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by WangQi, 2014/09/014
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

tDataNode * FindCmd(tDataNode * head,char * cmd)
{
    if(head == NULL || cmd == NULL)
    {
        return NULL;
     }
    tDataNode *p=head;
    while(p != NULL)
    {
        if(strcmp(p->cmd, cmd)==0)
            {
                return p;
                break;
            }
            p = p->next;
	}
	return NULL;
}

int FindAllCmd(tDataNode *head)
{
    printf("All commands:\n");
    tDataNode *p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0; 
}
