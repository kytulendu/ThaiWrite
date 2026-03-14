#ifndef _POPUP_H
#define _POPUP_H

#define CENTER 1

#define OLD    1
#define DIRECT 2
#define HIGH_LIGHT 3

void popup_message(char *item[]);
int popup_menu(char *item[], char** buff);

#endif /* _POPUP_H */
