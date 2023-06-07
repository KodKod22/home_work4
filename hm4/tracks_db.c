#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linked_list.h"
#include"set.h"
#include"records_db.h"
#include"erro_print.h"
#include"tracks_db.h"
#include"tracks.h"



typedef struct tracks
{
    char *name_track;
    int legth;
    int position;
}tracks,*tracks_ptr;


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
    tracks* track_copy = (tracks*)malloc(sizeof(tracks));

    if(track_copy ==NULL)
    {
        return NULL;
        exit(1);
    }
    tracks* old_track = (tracks*)new_track;

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
static int compareTrackByName(SetElement track_name1,SetElement track_name2)
{
    tracks_ptr first_track = (tracks_ptr)track_name1;
    tracks_ptr second_track = (tracks_ptr)track_name2;

    if(first_track == NULL || second_track == NULL)
    {
        return 0;
    }
    return strcmp(first_track->name_track,second_track->name_track);
}

////free a tracksDB by name
static void trackfree(SetElement track_free)
{
    if(track_free == NULL)
    {
        return 0;
    }
    tracks_ptr *elm = (tracks_ptr *)track_free;
    free(elm->name_track);
    free(elm);
}

///print the tracks
static void printTrack(FILE *out,SetElement track_print)
{
    tracksDB track_t = (tracksDB)track_print;
    if(track_t == NULL)
    {
        return;
    }
    fprintf(out,"%s,%d,%d",track_t->name_track,track_t->legth,track_t->position);
}
void call_all_tracks(LinkedList track_list)
{
    LinkedList temp = track_list;
    tracks_db *curr_track=(tracks_db*)malloc(sizeof(tracks_db));
    temp = (LinkedList)malloc(sizeof(LinkedList));
    if(temp == NULL|| curr_track == NULL)
    {
        prog_erro_list(LIST_OUT_OF_MEMORY);
        exit(1);
    }
    linkedListGoToHead(temp);
    while(temp != NULL)
    {
        linkedListGetCurrent(track_list,curr_track);
        prog2_report_track(stdout, curr_track->name_track,curr_track->legth);
    }
    free(temp);
    free(curr_track);
}


RecordsResult recordsDbAddTrackToRecord (RecordsDB rdb, char *recordName, char *trackName, int trackLength)
{
    RecordsDB t = rdb;
    
    if(rdb == NULL)
    {
        prog3_report_error_message(RDB_RECORD_DOESNT_EXIST);
        exit(1);
    }
    if(setIsIn(t,recordName) == SET_ELEMENT_DOES_NOT_EXIST)
    {
        prog3_report_error_message(RDB_RECORD_DOESNT_EXIST);
        exit(1);
    }
    
    tracksDB track;
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
    if(linkedListInsertLast(track->position,track->name_track) != LIST_SUCCESS)
    {
        return LIST_FAIL;
    }
    return RDB_SUCCESS;
}


/*RecordsResult recordsDbRemoveTrackFromRecord (RecordsDB rdb, char *recordName, char *trackName)
{
    RecordsDB t = rdb;
    if(setFind(t,recordName,))
    tracksDB track = trackName;
    if(setFind())
    
}

RecordsResult recordsDbReportTracksOfRecord (RecordsDB rdb, char *recordName)
{

}*/
