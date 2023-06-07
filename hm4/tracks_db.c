#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linked_list.h"
#include"set.h"
#include"records_db.h"
#include"erro_print.h"



typedef struct tracks_db
{
    char *name_track;
    int legth;
    int position;
}tracks_db,*tracksDB;


typedef struct trackDB
{
    Set tracks;
}trackDB;



// add a new truck to the record by coping from track_copy
static ListElement copyTrack(ListElement new_track)
{
    if(new_track == NULL)
    {
        return NULL;
    }
    tracks_db* track_copy = (tracks_db*)malloc(sizeof(tracks_db));

    if(track_copy ==NULL)
    {
        return NULL;
        exit(1);
    }
    tracks_db* old_track = (tracks_db*)new_track;

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
    tracksDB first_track = (tracksDB)track_name1;
    tracksDB second_track = (tracksDB)track_name2;

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
    tracks_db *elm = (tracks_db *)track_free;
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


RecordsResult recordsDbAddTrackToRecord (RecordsDB rdb, char *recordName, char *trackName, int trackLength)
{
    RecordsDB record;
    
    if(rdb == NULL)
    {
        prog3_report_error_message(RDB_RECORD_DOESNT_EXIST);
        exit(1);
    }
    if(compareRecordByName(recordName,))



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
    strcpy(track->name_track,trackName);
    
    

    
    
}

