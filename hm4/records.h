#ifndef _RECORDS_H
#define _RECORDS_H
#include"set.h"
#include"tracks.h"

typedef struct record_curr* record;

typedef SetElement (*copyRecord)(SetElement);
typedef void       (*recordFree)(SetElement);
typedef int        (*compareRecordByName)(SetElement,SetElement);
typedef void       (*printRecord) (FILE*,SetElement);
int compareRecordByName(SetElement element1,SetElement element2);

#endif