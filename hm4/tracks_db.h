#ifndef _TRACKS_DB_H
#define _TRACKS_DB_H

#include"set.h"


typedef struct Track_DB* tracksDB;

typedef SetElement (*copyTrack)(SetElement);
typedef void       (*trackfree)(SetElement);
typedef int        (*compareTrackByName)(SetElement,SetElement);
typedef void       (*printTrack) (FILE*,SetElement);

RecordsResult recordsDbAddTrackToRecord (RecordsDB rdb, char *recordName, char *trackName, int trackLength);
void call_all_tracks(LinkedList);

#endif