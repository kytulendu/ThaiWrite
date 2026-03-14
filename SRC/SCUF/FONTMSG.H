#ifndef _FONTMSG_H
#define _FONTMSG_H

void put_box(int x1, int y1, int x2, int y2);
int fontnamebox(char* pname, int creat);
void error_message(char *prompt);
int immediatebox(int x, int y, char *str, char *ans);

#endif /* _FONTMSG_H */
