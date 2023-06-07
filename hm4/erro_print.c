#include "records_db.h"
#include "linked_list.h"
#include"erro_print.h"
#include"set.h"
#include<stdlib.h>
#include<string.h>
void prog3_report_error_message(RecordsResult res)
{
    if (res == 0)
    return;
    fprintf(stderr, "Error: ");
    switch (res)
    {
        case RDB_SUCCESS:
            printf("RDB_SUCCESS");
        break;
        case RDB_NULL_ARGUMENT:
            printf("RDB_NULL_ARGUMENT");
            break;
        case RDB_RECORD_DOESNT_EXIST:
            printf("RDB_RECORD_DOESNT_EXIST");
            break;
        case RDB_INVALID_YEAR:
            printf("RDB_INVALID_YEAR");
            break;
        case RDB_INVALID_CATEGORY:
            printf("RDB_INVALID_CATEGORY");
            break;  
        case RDB_RECORD_ALREADY_EXISTS:
            printf("RDB_RECORD_ALREADY_EXISTS");
            break;  
        case RDB_NO_RECORDS:
            printf("RDB_NO_RECORDS");
            break; 
        case RDB_INVALID_TRACK_LENGTH:
            printf("RDB_INVALID_TRACK_LENGTH");
            break;
        case RDB_TRACK_ALREADY_EXISTS:
            printf("RDB_TRACK_ALREADY_EXISTS");
            break;
        case RDB_NO_TRACKS:
            printf("RDB_NO_TRACKS");
            break;
        case RDB_TRACK_DOESNT_EXIST:
            printf("RDB_TRACK_DOESNT_EXIST");
            break;
        case RDB_OUT_OF_MEMORY:
            printf("RDB_OUT_OF_MEMORY");
            break;                  
    }
    printf("\n");
}
void prog_erro_list(ListResult mess){
    if (mess == NULL)
    {
        return;
    }
    fprintf(stderr,"erro: ");
    switch (mess)
    {
    case LIST_SUCCESS:
        printf("LIST_SUCCESS");
        break;
    case LIST_FAIL:
        printf("LIST_FAIL");
        break;
    case LIST_BAD_ARGUMENTS:
        printf("LIST_BAD_ARGUMENTS");
        break;
    case LIST_OUT_OF_MEMORY:
        printf("LIST_OUT_OF_MEMORY");
        break;
    }
    printf("\n");
}

void prog_erro_set(SetResult t){
    if (t == NULL)
    {
        return;
    }
    fprintf(stderr,"erro: ");
    switch (t)
    {
    case SET_SUCCESS:
        printf("SET_SUCCESS");
        break;
    
    case SET_BAD_ARGUMENTS:
        printf("SET_BAD_ARGUMENTS");
        break;

    case SET_OUT_OF_MEMORY:
        printf("SET_OUT_OF_MEMORY");
        break;

    case SET_ELEMENT_EXISTS:
        printf("SET_ELEMENT_EXISTS");
        break;

    case SET_ELEMENT_DOES_NOT_EXIST:
        break;
    }

}