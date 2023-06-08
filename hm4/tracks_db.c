#include"linked_list.h"
#include"records_db.h"
#include"records.h"
#include"erro_print.h"
#include"tracks_db.h"
#include"tracks.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>




typedef struct Track
{
    char *name_track;
    int legth;
    int position;
}Track;


typedef struct trackDB
{
    LinkedList tracks;
}trackDB;



// add a new truck to the record by coping from track_copy
static ListElement copyTrack(ListElement new_track)
{
    if(new_track == NULL)
    {
        return NULL;
    }
    Track* track_copy = (Track*)malloc(sizeof(Track));

    if(track_copy ==NULL)
    {
        return NULL;
        exit(1);
    }
    Track* old_track = (Track*)new_track;

    track_copy->name_track = (char*)malloc(strlen(old_track->name_track)+1);
    if(track_copy->name_track == NULL)
    {
        free(track_copy);
        return NULL;
    }
    strcpy(track_copy->name_track,old_track->name_track);
    track_copy->legth = old_track->legth;
    track_copy->position = old_track->position;
    return track_copy;
}


//copmare two tracks by name
static int compareTrackByName(ListElement track_name1,ListElement track_name2)
{
    track first_track = (track)track_name1;
    track second_track = (track)track_name2;

    if(first_track == NULL || second_track == NULL)
    {
        return 0;
    }
    return strcmp(first_track->name_track,second_track->name_track);
}

////free a tracksDB by name
static void trackfree(ListElement track_free)
{
    if(track_free == NULL)
    {
        return ;
    }
    Track *elm = (Track *)track_free;
    free(elm->name_track);
    free(elm);
}

///print the tracks
static void printTrack(FILE *out,ListElement track_print)
{
    track track_t = (track)track_print;
    if(track_t == NULL)
    {
        return;
    }
    fprintf(out,"%s,%d,%d",track_t->name_track,track_t->legth,track_t->position);
}
void call_all_tracks(LinkedList track_list)
{
    ListElement key;
    LinkedList temp;
    track curr_track=(track)malloc(sizeof(Track));
    temp = (LinkedList)malloc(sizeof(LinkedList));
    if(temp == NULL|| curr_track == NULL)
    {
        prog_erro_list(LIST_OUT_OF_MEMORY);
        exit(1);
    }
    temp= track_list;
    linkedListGoToHead(temp);
    while(temp != NULL)
    {
        linkedListGetCurrent(track_list,key);
        prog2_report_track(stdout, curr_track->name_track,curr_track->legth);
    }
    curr_track=(track)key;
    free(temp);
    free(curr_track);
}


RecordsResult recordsDbAddTrackToRecord(RecordsDB rdb, char *recordName, char *trackName, int trackLength)
{
    
    Set record;
    LinkedList track3;
    if(rdb == NULL)
    {
        prog3_report_error_message(RDB_RECORD_DOESNT_EXIST);
        exit(1);
    }
    if(setIsIn(record,recordName) == SET_ELEMENT_DOES_NOT_EXIST)
    {
        prog3_report_error_message(RDB_RECORD_DOESNT_EXIST);
        exit(1);
    }
    track track;
    if(trackLength <= 0)
    {
        prog3_report_error_message(RDB_INVALID_TRACK_LENGTH);
        exit(1);
    }
    track->legth = trackLength;
    

    if(compareTrackByName(trackName,track->name_track) != 0)
    {
        prog3_report_error_message(RDB_TRACK_ALREADY_EXISTS);
        exit(1);
    }
    track->name_track = (char*)malloc(strlen(trackName)+1);
    if(track->name_track == NULL)
    {
        prog3_report_error_message(RDB_OUT_OF_MEMORY);
        free(track);
        exit(1);
    }
    strcpy(track->name_track,trackName);
    track3=(LinkedList)copyTrack(track3);
    if(linkedListInsertLast(track3,track->name_track) != LIST_SUCCESS)
    {
        return LIST_FAIL;
    }
    return RDB_SUCCESS;
}


RecordsResult recordsDbRemoveTrackFromRecord (RecordsDB rdb, char *recordName, char *trackName)
{
    RecordsDB temp = (RecordsDB)malloc(sizeof(RecordsDB));
    if(temp == NULL)
    {
        prog3_report_error_message(RDB_OUT_OF_MEMORY);
        exit(1);
    }
    Set record;
    if(setIsIn(record,recordName) != SET_ELEMENT_EXISTS)
    {
        prog3_report_error_message(RDB_RECORD_DOESNT_EXIST);
        exit(1);
    }


    RecordsDB rec_name =(RecordsDB)malloc(sizeof(RecordsDB));
    if(rec_name == NULL)
    {
        prog3_report_error_message(RDB_OUT_OF_MEMORY);
        exit(1);
    }
    
    LinkedList Tracks_DB;
    track trc_name = (track)malloc(sizeof(track));
        if(trc_name == NULL)
        {
            prog3_report_error_message(RDB_OUT_OF_MEMORY);
            exit(1);
        }
        trc_name->name_track = trackName;
    linkedListGoToHead(Tracks_DB);
    while(linkedListGoToNext(Tracks_DB) != LIST_BAD_ARGUMENTS)
    {
        if(setIsIn(record,trc_name) != SET_ELEMENT_EXISTS)
        {
    
            prog3_report_error_message(RDB_TRACK_DOESNT_EXIST);
            exit(1);
        }
        linkedListRemoveCurrent(Tracks_DB);
    }
    return RDB_SUCCESS;
}

/*RecordsResult recordsDbReportTracksOfRecord (RecordsDB rdb, char *recordName)
{

}*/
