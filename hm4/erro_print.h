#ifndef _ERRO_PRINT_H
#define _ERRO_PRINT_H

typedef enum ListResult ListResult;

typedef enum SetResult SetResult;

typedef enum RecordsResult RecordsResult;

void prog3_report_error_message(RecordsResult res);

void prog_erro_list(ListResult mess);

void prog_erro_set(SetResult t);
#endif