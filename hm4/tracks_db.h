#ifndef _TRACKS_DB_H
#define _TRACKS_DB_H

#include"set.h"


typedef struct Track* track;

/*typedef ListElement (*copyTrack)(ListElement);
typedef void       (*trackfree)(ListElement);
typedef int        (*compareTrackByName)(ListElement,ListElement);
typedef void       (*printTrack) (FILE*,ListElement);*/

RecordsResult recordsDbAddTrackToRecord (RecordsDB, char *, char *, int);
void call_all_tracks(LinkedList);

#endif