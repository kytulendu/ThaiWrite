/* Update: Suttipong Kanakakorn
Sun  07-30-1989  17:56:53
Sun  08-06-1989  11:20:06
*/

/***SCRN.C*******************************************************************/
void cls(void);

/***EDIT.C*******************************************************************/
void findstrcode(char fontcode[], font_attr attr);
unsigned int findlineno(struct line_node *line);
struct line_node *linepointer(unsigned int linenum);
void displine(struct line_node *line, unsigned int y, unsigned int linenum);
void disppagebreak(unsigned int y);
void showpage(void);
void showpageall(void);
unsigned int findrow(void);
void adjustcol(unsigned int *x);
void loadtoline(char *text);
void storeline(struct line_node *line);
void refreshline(unsigned int x, unsigned int y);

/***INS.C********************************************************************/
void insertblank(unsigned int j, char code);
void insert_line(struct line_node *currentline,struct line_node *newline);
void shiftscrn(unsigned int count, unsigned int *x);
void linetoolong(void);
void inscntrl(char cntrl, unsigned int x, unsigned int y);
void printcntrl(unsigned int x, unsigned int y);
int insert_char(char c, unsigned int *x, unsigned int *y);
int ovrwrite_char(char c, unsigned int *x,unsigned int *y);
void insertreturn(struct line_node *line, unsigned int thaicol);
void insert_ret(unsigned int *x);
void returnkey(unsigned int *x, unsigned int y);
void ret_with_ins(unsigned *x, unsigned int y);
void insertmacro(char *macro, unsigned int *x, unsigned int *y);
void blankmaro(int y);
void dispmacro(int i);
void editmacro(void);

/***DEL.C********************************************************************/
void delete_char(unsigned int x);
void deletereturn(struct line_node *line);
void del_return(void);
void backspace(unsigned int *x);
void delete_word(unsigned int x);
void deltoendline(unsigned int x, unsigned int y);
void deleteline(struct line_node *line);
void delete_line(void);

/***STATUS.C*****************************************************************/
void relmarstatus(void);
void arabictothai(char *st);
void writepage(void);
void writeline(void);
void writelineno(void);
void writepageline(void);
void writecolno(unsigned int x);
void writeinsmode(void);
void writelanguage(void);
void writeattr(void);
void writefilename(void);
void writedriveno(void);
void writestatus(unsigned int x);

/***KBD.C********************************************************************/
void waitkbd(unsigned int x, unsigned int y);
int changekey(int key);
int readkbd(void);
int alt_char_map (int c);

/***MOVE.C*******************************************************************/
void goline(unsigned int linetogo);
void gocol(unsigned int coltogo, unsigned int *x);
void home(unsigned int *x);
void endline(unsigned int *x);
void topfile(unsigned int *x);
void endfile(unsigned int *x);
void backword(unsigned int *x);
void nextword(unsigned int *x, unsigned int y);
void gotopage(void);
void gotoline(void);
void gobeginblk(unsigned int *x);
void goendblk(unsigned int *x);
void quick(unsigned int *x, unsigned int *y);

/***MOVEMENT.C***************************************************************/
void cursor_up(void);
void cursor_down(unsigned int y);
void cursor_left(unsigned int *x);
void cursor_right(unsigned int *x, unsigned int y);
void page_up(void);
void page_down(void);
void scroll_up(void);
void scroll_down(void);
void top_of_page(void);
void bottom_of_page(void);

/***WRAP.C*******************************************************************/
void justify_right(void);
unsigned int genrule1(unsigned int nominal);
unsigned int genrule3(unsigned int nominal);
unsigned int genrule4(unsigned int nominal);
unsigned int genrule5(unsigned int nominal);
unsigned int genrule7(unsigned int nominal);
unsigned int breakpoint(void);
void manualwrap(unsigned int *x, unsigned int *y);
void autowrap(unsigned int *x, unsigned int *y);
void reform(void);
void compress_blank(unsigned char *);

/***ONSCRN.C*****************************************************************/
void writetab(void);
void centerline(unsigned int y);
void doonscrn(unsigned int key, unsigned int x, unsigned int y);
void movetotab(unsigned int *x, unsigned int y);
void onscreen(unsigned int x, unsigned int y);
void readconfig(void);

/***FILE.C*******************************************************************/
int handler(int errval, int ax, int bp, int si);
int havewild(char filname[]);
int read_file(char *file_name);
void abandonfile(void);
boolean file_exist(char *filename);

/***SEARCH.C*****************************************************************/
int searchonlyinfo(void);
int searchreplaceinfo(void);
int optionglobal(void);
int optionupper(void);
int optionword(void);
int optionnoask(void);
char *searchline(char *textline, int startpos);
void wordnotfound(void);
int searchfwd(unsigned int *x, unsigned int *y);
void addblank(void);
void searching(unsigned int *x, unsigned int *y);
void replaceword(unsigned int *x, unsigned int *y);
int searchreplace(unsigned int *x, unsigned int *y);
void replacing(unsigned int *x, unsigned int *y);

/***BLOCK.C******************************************************************/
void toggleblk(void);
void markbegin(unsigned int x);
void markend(unsigned int x);
int haveblock(void);
int inblock(unsigned int linenum, unsigned int colnum);
struct line_node *copytospace(struct line_node *fline, struct line_node *lline, unsigned int fcol, unsigned int lcol);
void insertlinklist(struct line_node *sourceline, struct line_node *destline, unsigned int destcol);
void deletelinklist(struct line_node *fline, struct line_node *lline, unsigned int fcol, unsigned int lcol);
unsigned int spacesize(struct line_node *space);
struct line_node *rdfiletospace(char file_name[]);
void copyblk(unsigned int *x);
void deleteblk(void);
void moveblk(unsigned int *x);
void readblk(unsigned int *x);
unsigned long getfilesize(void);
unsigned long diskfree(int driveno);
void writeblk(char file_name[], struct line_node *linebegin, unsigned int colbegin,
              struct line_node *lineend, unsigned int colend);
void writeblock(void);
void blkcmd(unsigned int key, unsigned int *x);
void blockcommand(unsigned int *x);
int chkspace(char *);

/***CW.C*********************************************************************/
void dispkey(unsigned int key);
void setupnode(void);
char *chulaname(void);
void initscrn(void);
unsigned int menu_to_key(unsigned int curmenu);
void main(int argc, char *argv[]);


/***THAICUT.C****************************************************************/
unsigned char *FINDCUT(char *lm, char *eot, char *rm);

/***GRPH.C*******************************************************************/
char *readgraph(char *filename);
paintlinegraph(char *graph, unsigned int linewant);
paintgraph(char *graph, unsigned int linewant);

/* cwsetup.c */
void cwsetup(int argc, char *argv[]);
void usage(void);
void set_directory(void);
int  readoption(search_file_mode mode);
void saveoption(search_file_mode mode);
void blankoption(int y);
void dispoption(int i);
void setoption(void);
void initvalue(unsigned int *x, unsigned int *y);
void edit_font(void);
void offbreak(void);

/***MENU.C*******************************************************************/
char *savescrn(int x1, int y1, int x2, int y2);
void resscrn(char *scrnindex, int x1, int y1, int x2, int y2);
int selectmenu(unsigned int x, unsigned int y, unsigned int number,
               char *message[], unsigned int *curmenu);
void headmenu(unsigned int topmenu, char attr);
unsigned int findcurmenu(unsigned int lev1, unsigned int lev2, unsigned int lev3,
                         unsigned int lev4);
void findcurlevel(unsigned int curmenu, unsigned int *lev1, unsigned *lev2,
                  unsigned int *lev3, unsigned int *lev4);
unsigned int pulled_down_menu(unsigned int *curmenu, unsigned int *x, unsigned int *y);
void print_file(void);
void showerrno(void);

/* TUTIL1.c */
unsigned int thaistrlen(register unsigned char *thaist);
unsigned int linearcolumn(char *textstream, unsigned int thaicol, font_attr *font);

/***GETSTR.C*****************************************************************/
int getstring(char textst[], unsigned int x, unsigned int y, unsigned int maxlen, char attr, strtype mode);
int getname(char textst[], unsigned int x, unsigned int y, unsigned int maxlen, char attr);
