#ifndef STRING1_H
#define STRING1_H

struct String;

int BF(String s, String t, int pos);

void get_next(String t, int *next);
void get_nextval(String t, int *nextval);
int Index_KMP(String s, String t, int pos);

#endif
