#ifndef _TRACKS_DB_H
#define _TRACKS_DB_H


#include"set.h"
#include"records.h"
#include"erro_print.h"
#include"linked_list.h"
#include"records_db.h"

typedef struct Track* track;
typedef struct trackDB* trackDB_ptr;

typedef ListElement(*copyTrack)(ListElement);

typedef void(*trackfree)(ListElement);

typedef int(*compareTrackByName)(ListElement,ListElement);

typedef void (*printTrack)(FILE *,ListElement);

RecordsResult recordsDbAddTrackToRecord(RecordsDB, char *, char *, int);
void call_all_tracks(LinkedList);

#endif