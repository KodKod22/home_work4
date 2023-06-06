#include "linked_list.h"
#include"set.h"
#include"records_db.h"
#include"records.h"
#include"tracks_db.h"
#include"tracks.h"
#include"erro_print.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct record_curr
{
    char *name;
    int year;
    int num_of_traks;
    enum record_category_e ct;
    LinkedList *own_track;
}record_curr,*record;

typedef struct RecordsDB_s
{
    Set records;
}RecordsDB_s;

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
static int compareRecordByName(SetElement element1,SetElement element2){
    record record1=(record)element1;
    record record2=(record)element2;

    if (record1 == NULL || record2 == NULL)
    {
        return 0;
    }
    return strcmp(record1->name,record2->name);
}

static void recordFree(SetElement d){
    if (d != NULL)
    {
        record_curr *t=(record_curr *)d;
        free(t->name);
        free(t);
    }
    
}

static void printRecord(FILE *out,SetElement element){
    record record_t=(record)element;
    if (record_t == NULL)
    {
        return;
    }
    fprintf(out,"%s %d %d",record_t->name,record_t->year,record_t->num_of_traks);
    LinkedList *curr=record_t->own_track;
    for (int i = 0; i < linkedListGetNumElements(record_t->own_track); i++)
    {
        linkedListPrint(curr,out,compareTrackByName);
        if(linkedListGoToHead(curr)== LIST_BAD_ARGUMENTS){
            
        }

    }
    
     
}

RecordsDB recordsDbCreate(){
    RecordsDB t=(RecordsDB)malloc(sizeof(RecordsDB_s));
    if (t == NULL)
    {
        prog_erro_set(SET_OUT_OF_MEMORY);
        exit(1);
    }
    setCreate(t->records,compareRecordByName,copyRecord,recordFree,printRecord);
}

