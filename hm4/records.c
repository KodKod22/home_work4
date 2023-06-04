#include "linked_list.h"
#include"set.h"
#include"records_db.h"
#include"records.h"
#include"tracks_db.h"
#include"tracks.h"

typedef struct records
{
    char *name;
    int year;
    int num_of_traks;
    enum record_category_e ct;
    LinkedList *own_track;
}records;