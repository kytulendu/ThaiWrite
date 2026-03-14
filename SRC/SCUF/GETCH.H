#ifndef _GETCH_H
#define _GETCH_H

int cursorkey(char *key);
int get_pos(unsigned int *x, unsigned int *y,
    unsigned int block_x, unsigned int block_y,
    unsigned int width_x, unsigned int width_y);

#endif /* _GETCH_H */
