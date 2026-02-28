/*
proto.h for cufont.exe
By Suttipong Kanakakorn Fri  08-25-1989  22:34:30
*/

/***GETSTR.C*****************************************************************/
int getstring(char textst[], unsigned int x, unsigned int y,
    unsigned maxlen, char attr, strtype mode);
int getname(char textst[], unsigned int x, unsigned int y, unsigned int maxlen, char attr);

/* TUTIL1.c */
unsigned int thaistrlen(register unsigned char *thaist);

/* cufsetup.c */
void cufsetup(int argc, char *argv[]);
void readfont(void *font_buffer, char *fontname);

/***KBD.C********************************************************************/
void waitkbd(unsigned int x, unsigned int y);
int readkbd(void);

/***FILE.C*******************************************************************/
search_file_mode find_file(char *filename, char *search_path);
