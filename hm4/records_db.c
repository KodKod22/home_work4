#include "linked_list.h"
#include"set.h"
#include"records_db.h"
#include"tracks_db.h"
#include"records.h"
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
    RecordsCategory ct;
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
    switch (record_t->ct)
    {
    case ROCK:
        fprintf(out,"ROCK");
        break;
    case POP:
        fprintf(out,"POP");
        break;
    case JAZZ:
        fprintf(out,JAZZ);
        break;
    case BLUES:
        fprintf(out,"BLUES");
        break;
    case HIP_HOP:
        fprintf(out,"HIP_HOP");
        break;
    case COUNTRY:
        fprintf(out,"COUNTRY");
        break;
    case CLASSIC:
        fprintf(out,"CLASSIC");
        break;
    }
    LinkedList *curr=record_t->own_track;
    for (int i = 0; i < linkedListGetNumElements(record_t->own_track); i++)
    {
        linkedListPrint(curr,out,record_t->num_of_traks);
        if(linkedListGoToHead(curr)== LIST_BAD_ARGUMENTS){
            break;
        }else{
            record_t->num_of_traks--;
            continue;
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

    setCreate(&(t->records),compareRecordByName,copyRecord,recordFree,printRecord);

    if(setCreate(&(t->records),compareRecordByName,copyRecord,recordFree,printRecord)==SET_BAD_ARGUMENTS){
        prog_erro_set(SET_BAD_ARGUMENTS);
        free(t);
        exit(1);
    }else
    {
        prog_erro_set(SET_OUT_OF_MEMORY);
        free(t);
        exit(1);
    }
    return t;
}
void recordsDbDestroy(RecordsDB d)
{
    if (d == NULL)
    {
        prog3_report_error_message(RDB_NO_RECORDS);
    }
    if (setDestroy(d->records) != SET_SUCCESS)
    {
        prog_erro_set(SET_BAD_ARGUMENTS);
    }
    free(d);
}

RecordsResult recordsDbAddRecord(RecordsDB rdb, const char *name, int year, RecordsCategory category){
    RecordsDB t=rdb;
    if (rdb == NULL || name == NULL)
    {
        prog3_report_error_message(RDB_NULL_ARGUMENT);
        exit(1);
    }
    if (year<1900)
    {
        prog3_report_error_message(RDB_INVALID_YEAR);
        exit(1);
    }
    if(setFind(rdb->records,t,name,compareRecordByName)==SET_SUCCESS){
        prog3_report_error_message(RDB_RECORD_ALREADY_EXISTS);
        exit(1);
    }
    
    record new=(record)malloc(sizeof(record_curr));
    if (new == NULL)
    {
        prog3_report_error_message(RDB_OUT_OF_MEMORY);
        exit(1);
    }

    new->name=(char *)malloc(strlen(name)+1);
    if (new->name == NULL)
    {
        prog3_report_error_message(RDB_OUT_OF_MEMORY);
        free(new);
        exit(1);
    }
    
    strcpy(new->name,name);
    new->year=year;

    switch (category)
    {
        case ROCK:
            new->ct=ROCK;
        break;
        case POP:
            new->ct=POP;
        break;
        case JAZZ:
            new->ct=JAZZ;
        break;
        case BLUES:
            new->ct=BLUES;
        break;
        case HIP_HOP:
            new->ct=HIP_HOP;
        break;
        case COUNTRY:
            new->ct=COUNTRY;
            break;
        case CLASSIC:
            new->ct=CLASSIC;
            break;         
    }
    if(setAdd(rdb->records, new)== SET_SUCCESS){
        return RDB_SUCCESS;
    }
}
RecordsResult recordsDbRemoveRecord (RecordsDB rdb, char *name){
    RecordsDB temp=(RecordsDB)malloc(sizeof(RecordsDB_s));
    if (temp == NULL)
    {
        prog3_report_error_message(RDB_OUT_OF_MEMORY);
    }
    
    if (rdb == NULL)
    {
        return SET_BAD_ARGUMENTS;
    }
    setGetFirst(rdb->records,temp);

    if (setFind(rdb->records,temp->records,name,compareRecordByName) == SET_SUCCESS)
    {
        if (setRemove(rdb,temp) != SET_SUCCESS)
        {
            return NULL;
        }
        
    }else{
        return RDB_RECORD_DOESNT_EXIST;
    }

    return SET_SUCCESS;
}

RecordsResult recordsDbReportRecords (RecordsDB rdb, RecordsCategory category){
    
}