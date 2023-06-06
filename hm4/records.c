#include "linked_list.h"
#include"set.h"
#include"records_db.h"
#include"records.h"
#include"tracks_db.h"
#include"tracks.h"
#include"erro_print.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct record_curr
{
    char *name;
    int year;
    int num_of_traks;
    enum record_category_e ct;
    LinkedList *own_track;
}record_curr,*record;

static SetElement copyRecord(SetElement d){
    if (!d)
    {
        return NULL;
    }
    record_curr* new=(record_curr*)malloc(sizeof(record_curr));

    if (new == NULL)
    {
        return NULL;
        exit(1);
    }
    record_curr* old= (record_curr*)d;

    new->name=(char*)malloc(strlen(old->name)+1);
    if (new->name == NULL)
    {
        free(new);
        return NULL;       
    }
    strcpy(new->name,old->name);
    new->year=old->year;
    new->num_of_traks=old->num_of_traks;
    new->ct=old->ct;
    new->own_track=old->own_track;
    return new;
}