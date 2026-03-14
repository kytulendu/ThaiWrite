/* --------------------------------- */
/* Program PMENU.C                   */
/* Written Oct -87                   */
/* Update  10-6-88                   */
/* Update  24-9-88                   */
/* Update  25-12-88                  */
/* Update  09-04-89                  */
/* Update  27-04-89                  */
/* Add print configuration feature.  */
/* Function : user menu interactions */
/* Update  Suttipong Kanakakorn      */
/* Mon  08-07-1989 00:00:55          */
/* break the program smaller         */
/* and add function prototype, clear */
/* all warning message               */
/* Fri  08-11-1989  02:25:09         */
/* call cwsetup.c                    */
/* Sun  09-03-1989  01:29:31         */
/* call line per page routine        */
/* --------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <dir.h>

#include "inc.h"
#include "..\common\cwgrphc.h"
#include "..\common\kbdcode.h"
#include "global.h"

#define  DIRCOLMAX 5
#define  DIRROWMAX 5
#define  MAXNUM 20


void main(int argc, char *argv[])
{
    cupsetup(argc, argv);
    setgraph();
    writeallmenu();
    menuselect();
    settext();
}

void writefilename(void)
{
    dispstrhgc("แฟ้มข้อมูล : ", 44, 0, 0);
    dispstrhgc("                         ", 54, 0, 0);
    dispstrhgc(filename, 54, 0, 0);
}

void writemenu(int row, int col, font_attr attr)
{
    char st[5];
    switch(col)
    {
        case 0 :
            switch(row)
            {
                case 0 :
                    dispstrhgc(" ใส่ชื่อแฟ้มข้อมูลที่ต้องการพิมพ์  ", mcol[col], 3, attr);
                    writefilename();
                    break;
                case 1 :
                    dispstrhgc(" เริ่มพิมพ์แฟ้มข้อมูล          ", mcol[col], 4, attr);
                    break;
                case 2 :
                    dispstrhgc(" ช่องเก็บ(Disk Drive)     ", mcol[col], 5, attr);
                    prchar('A' + getdisk(), attr, smcol[0] - 1, 5);
                    break;
                case 3 :
                    dispstrhgc(" เปลี่ยนราก(Directory)    ", mcol[col], 6, attr);
                    break;
                case 4 :
                    dispstrhgc(" ไประบบปฏิบัติการชั่วคราว    ", mcol[col], 7, attr);
                    break;
                case 5 :
                    dispstrhgc(" เครื่องพิมพ์               ", mcol[col], 8, attr);
                    break;
                case 6 :
                    if (stdcode == YES)
                    {
                        dispstrhgc(" รหัสข้อมูลภาษาไทย    สมอ. ", mcol[col], 9, attr);
                    }
                    else
                    {
                        dispstrhgc(" รหัสข้อมูลภาษาไทย   เกษตร ", mcol[col], 9, attr);
                    }
                    break;
                case 7 :
                    dispstrhgc(" เลิกการทำงาน      ALT-X ", mcol[col], 10, attr);
                    break;
            }
            break;
        case 1 :
            switch(row)
            {
                case 0 :
                    dispstrhgc(" จำนวนบรรทัดต่อหน้า        ", mcol[col], 3, attr);
                    itoa(userlineperpage, st, 10);
                    dispstrhgc(st, smcol[col] - strlen(st), 3, attr);
                    break;
                case 1 :
                    dispstrhgc(" ขนาดตัวอักษร (ตัวต่อนิ้ว)    ", mcol[col], 4, attr);
                    itoa(cpi, st, 10);
                    dispstrhgc(st, smcol[col] - strlen(st), 4, attr);
                    break;
                case 2 :
                    dispstrhgc(" ขอบซ้าย                 ", mcol[col], 5, attr);
                    itoa(leftmargin, st, 10);
                    dispstrhgc(st, smcol[col] - strlen(st), 5, attr);
                    break;
                case 3 :
                    dispstrhgc(" ขอบขวา                 ", mcol[col], 6, attr);
                    /*
                    rightmargin = ((rightmargin > leftmargin) && (rightmargin < maxcol))
                                        ? rightmargin : maxcol;
                    */
                    itoa(rightmargin, st, 10);
                    dispstrhgc(st, smcol[col] - strlen(st), 6, attr);
                    break;
                case 4 :
                    dispstrhgc(" เริ่มพิมพ์ที่หน้า             ", mcol[col], 7, attr);
                    itoa(pagebegin, st, 10);
                    dispstrhgc(st, smcol[col] - strlen(st), 7, attr);
                    break;
                case 5 :
                    dispstrhgc(" หยุดพิมพ์ที่หน้า             ", mcol[col], 8, attr);
                    itoa(pageend, st, 10);
                    dispstrhgc(st, smcol[col] - strlen(st), 8, attr);
                    break;
                case 6 :
                    dispstrhgc(" หมายเลขหน้าเริ่มต้น        ",mcol[col],9,attr);
                    itoa(pagenumberoffset, st, 10);
                    dispstrhgc(st, smcol[col] - strlen(st), 9, attr);
                    break;
                case 7 :
                    dispstrhgc(" จำนวนชุดที่พิมพ์ (COPY)     ", mcol[col], 10, attr);
                    itoa(copytoprint, st, 10);
                    dispstrhgc(st, smcol[col] - strlen(st), 10, attr);
                    break;
            }
            break;
        case 2 :
            switch(row)
            {
                case 0 :
                    dispstrhgc(" หัวกระดาษ (Header)      ", mcol[col], 3, attr);
                    break;
                case 1 :
                    dispstrhgc(" ท้ายกระดาษ (Footer)     ", mcol[col], 4, attr);
                    break;
                case 2 :
                    dispstrhgc(" หน้ากระดาษ (PageTitle)  ", mcol[col], 5, attr);
                    break;
                case 3 :
                    dispstrhgc(" ตำแหน่งหัวข้อเรื่อง (Title) ", mcol[col], 6, attr);
                    break;
                case 4 :
                    dispstrhgc(" เก็บค่าตัวแปร (Parameters)", mcol[col], 7, attr);
                    break;
                case 5 :
                    dispstrhgc(" อ่านค่าตัวแปร (Parameters)", mcol[col], 8, attr);
                    break;
                case 6 :
                    dispstrhgc(" โหมดพิมพ์                ", mcol[col], 9, attr);
                    break;
                case 7 :
                    if (pagebreak == YES)
                    {
                        dispstrhgc(" หยุดเปลี่ยนกระดาษ    หยุด  ", mcol[col], 10, attr);
                    }
                    else
                    {
                        dispstrhgc(" หยุดเปลี่ยนกระดาษ   ไม่หยุด ", mcol[col], 10, attr);
                    }
                    break;
            }
            break;
    }
}

void docommand(int row, int col)
{
    char *setpageformat();
    int key;
    char *fileptr;
    char st[5];
    char cwd[38];

    key = 0;
    fileptr=filename;
    switch(col)
    {
        case 0 :
            switch(row)
            {
                case 0 :
                    savepic();
                    dispstrhgc("ใส่ชื่อแฟ้มข้อมูลที่ต้องการพิมพ์ : ", 25, 12, 0);
                    fileptr = (filename[0] == '\0') ? "*.*" : filename;
                    strcpy(filename,fileptr);
                    if ((getname(filename, 49, 12, 25, 2) == YES) &&
                        (filename[0] != '\0'))
                    {
                        if (havewild(filename))
                        {
                            selectfile(filename);
                            retpic();
                        }
                    }
                    if ((fileready == YES) && (filename == oldfilename))
                        ;
                    else
                    {
                        fclose(fp);     /* close old file */
                        if  ((fp = fopen(filename, "r")) == NULL)
                        {
                            fileready = NO;
                            filename[0] ='\0';  /* clear filename */
                            strcpy(oldfilename, filename);
                            writefilename();
                            dispstrhgc("                                                     ", 25, 12, 0);
                            dispstrhgc("•••••••••••••••••••••••••••••••••••••", 20, 12, 2);
                            dispstrhgc("–   *** ไม่พบแฟ้มข้อมูล *** กดปุ่มใด ๆ ...  –", 20, 13, 2);
                            dispstrhgc("•••••••••••••••••••••••••••••••••••••", 20, 14, 2);
                            ebioskey(0);  /* clear KBD buffer */
                        }
                        else
                        {
                            strcpy(oldfilename, filename);
                            fileready = YES;
                        }
                    }
                    retpic();
                    writefilename();
                    break;
                case 1 :
                    if (fileready == YES)
                    {
                        savepic();
                        /* Suttipong Kanakakorn Fri  10-27-1989  19:09:59 */
                        /* check every error of printer before print */
                        if (PrinterReadstatus() & 0x80 &&
                            (PrinterReadstatus() & 0x29) == 0)
                        {
                            printing();
                        }
                        else
                        {
                            dispstrhgc("                                                     ", 25, 12, 0);
                            dispstrhgc("•••••••••••••••••••••••••••••••••••••", 20, 12, 2);
                            dispstrhgc("– *** เครื่องพิมพ์ไม่พร้อม ***  กดปุ่มใด ๆ ...–", 20, 13, 2);
                            dispstrhgc("•••••••••••••••••••••••••••••••••••••", 20, 14, 2);
                            ebioskey(0);  /* clear KBD buffer */
                        }
                        retpic();
                    }
                    else
                    {
                        savepic();
                        dispstrhgc("                                                     ", 25, 12, 0);
                        dispstrhgc("•••••••••••••••••••••••••••••••••••••••••", 20, 12, 2);
                        dispstrhgc("–  *** กรุณาเปิดแฟ้มข้อมูลก่อน ***  กดปุ่มใด ๆ ...–", 20, 13, 2);
                        dispstrhgc("•••••••••••••••••••••••••••••••••••••••••", 20, 14, 2);
                        ebioskey(0);  /* clear KBD buffer */
                        retpic();
                    }
                    break;
                case 2 :
                    savepic();
                    dispstrhgc(" เปลี่ยนช่องเก็บ (Logged Drive) เป็น   ", 28, 12, 0);
                    waitkbd(60, 12);
                    key = ebioskey(0) & 0xff;
                    if ((key >= 'a') || (key <= 'p'))
                    {
                        setdisk(key - 'a');
                    }
                    else if ((key >= 'A') || (key <= 'P'))
                    {
                        setdisk(key - 'A');
                    }
                    retpic();
                    writemenu(row, col, 2);
                    break;
                case 3 :
                    savepic();
                    dispstrhgc("เปลี่ยนราก (Directory) เป็น :", 10, 12, 0);
                    getstring(getcwd(cwd, 37), 37, 12, 37, 2);
                    chdir(cwd);
                    retpic();
                    writemenu(row, col, 2);
                    break;
                case 4 :
                    settext();
                    puts("Type EXIT to return to CUPRINT");
                    system("");
                    setgraph();
                    writeallmenu();
                    writemenu(row, col, 2);
                    break;
                case 5 :
                    savepic();
                    prtwriteallmenu();
                    prtmenuselect();
                    retpic();
                    /* add by Suttipong Kanakakorn Sun  09-03-1989  01:29:17 */
                    set_all_lineperpage(INTERACTIVE); /* set (user)lineperpage */
                    writemenu(row, col, 2);
                    writemenu(3, 1, 0);   /* show new right margin */
                    break;
                case 6 :
                    if (stdcode == YES)
                    {
                        stdcode = NO;
                    }
                    else
                    {
                        stdcode = YES;
                    }
                    writemenu(row, col, 2);
                    break;
                case 7 :
                    quitprog = YES;
                    break;
            }
            break;
        case 1 :
            switch(row)
            {
                case 0 :
                    savepic();
                    dispstrhgc("ต้องการจำนวนบรรทัดต่อหน้าเท่าไร : ", 30, 12, 0);
                    if (getnumber(itoa(userlineperpage, st, 10), 59, 12, 3, 2) == YES)
                    {
                        if (atoi(st) > 0)
                        {
                            userlineperpage = atoi(st);
                        }
                    }
                    dispstrhgc("     ความยาวกระดาษเท่าไร (นิ้ว) : ", 30, 12, 0);
                    if (getnumber(itoa(pagelength, st, 10), 59, 12, 3, 2) == YES)
                    {
                        if (atoi(st) > 0)
                        {
                            pagelength = atoi(st);
                        }
                    }
                    retpic();
                    /* add by Suttipong Kanakakorn Sun  09-03-1989  01:29:17 */
                    set_all_lineperpage(INTERACTIVE); /* set (user)lineperpage */
                    writemenu(row, col, 2);
                    break;
                case 1 :
                    savepic();
                    dispstrhgc("ต้องการ จำนวนตัวอักษรต่อนิ้ว เท่าไร     : ", 28, 12, 0);
                    if (getnumber(itoa(cpi, st, 10), 62, 12, 3, 2) == YES)
                    {
                        cpi = atoi(st);
                        cpi = (cpi<20) ? cpi : 20;
                        cpi = (cpi>0)  ? cpi : 1;
                        if ((printer == LQ) || (printer == N7) || (printer == N5))
                        {
                            maxcol = 136 * cpi / 10;
                            maxdot = 3264;
                            maxbuffer = (cpi < 10) ? 3264 : 3264 * (long)(cpi) / 10 + 50;
                            /* Strange to Suttipong Kanakakorn */
                        }
                        else
                        {
                            maxcol = 80  * cpi / 10;
                            maxdot = 1920;
                            maxbuffer = (cpi < 10) ? 1920 : 192 * cpi;
                        }
                    }
                    retpic();
                    writemenu(3, 1, 0);
                    writemenu(row, col, 2);
                    break;
                case 2 :
                    savepic();
                    dispstrhgc("ต้องการตั้งขอบซ้าย(Left Margin)เท่าไร : ", 27, 12, 0);
                    if (getnumber(itoa(leftmargin, st, 10), 62, 12, 3, 2) == YES)
                    {
                        leftmargin = (atoi(st) > 0) ? atoi(st) : 1;
                        leftmargin = (leftmargin < rightmargin) ? leftmargin : 1;
                    }
                    retpic();
                    writemenu(row, col, 2);
                    break;
                case 3 :
                    savepic();
                    dispstrhgc("ต้องการตั้งขอบขวา(Right Margin)เท่าไร: ", 27, 12, 0);
                    if (getnumber(itoa(rightmargin, st, 10), 62, 12, 3, 2) == YES)
                    {
                        rightmargin = atoi(st);
                    }
                    retpic();
                    writemenu(row, col, 2);
                    break;
                case 4 :
                    savepic();
                    dispstrhgc("ต้องการเริ่มพิมพ์ที่หน้าเท่าไร : ", 33, 12, 0);
                    if (getnumber(itoa(pagebegin, st, 10), 57, 12, 3, 2) == YES)
                    {
                        pagebegin = (atoi(st) > 0) ? atoi(st) : 1;
                        pagebegin = (pageend < pagebegin) ? pageend : pagebegin;
                    }
                    retpic();
                    writemenu(row, col, 2);
                    break;
                case 5 :
                    savepic();
                    dispstrhgc("ต้องการหยุดพิมพ์ที่หน้า (PageEnd) เท่าไร  :   ", 26, 12, 0);
                    if (getnumber(itoa(pageend, st, 10), 64, 12, 3, 2) == YES)
                    {
                        pageend = atoi(st);
                        pageend = (pageend < pagebegin) ? pagebegin : pageend;
                    }
                    retpic();
                    writemenu(row, col, 2);
                    break;
                case 6 :
                    savepic();
                    dispstrhgc("ต้องการให้พิมพ์หมายเลขหน้าเริ่มต้น เท่าไร ?  : ", 26, 12, 0);
                    if (getnumber(itoa(pagenumberoffset, st, 10), 64, 12, 3, 2) == YES)
                    {
                        pagenumberoffset = atoi(st);
                    }
                    retpic();
                    writemenu(row, col, 2);
                    break;
                case 7 :
                    savepic();
                    dispstrhgc("ต้องการพิมพ์กี่ชุด : ", 37, 12, 0);
                    if (getnumber(itoa(copytoprint, st, 10), 52, 12, 3, 2) == YES)
                    {
                        copytoprint = (atoi(st) > 0) ? atoi(st) : 1;
                    }
                    retpic();
                    writemenu(row, col, 2);
                    break;
            }
            break;
        case 2 :
            switch(row)
            {
                case 0 :
                    savepic();
                    dispstrhgc("ใส่ข้อความหัวกระดาษ (Heading) ที่ต้องการ : ", 1, 12, 0);
                    getstring(heading, 38, 12, 40, 2);
                    retpic();
                    break;
                case 1 :
                    savepic();
                    dispstrhgc("ใส่ข้อความท้ายกระดาษ (Footing) ที่ต้องการ : ", 1, 12, 0);
                    getstring(footing, 39, 12, 39, 2);
                    retpic();
                    break;
                case 2 :
                    savepic();
                    dispstrhgc("ใส่ข้อความหน้ากระดาษ(PageTitle)ที่ต้องการ : ", 1, 12, 0);
                    getstring(pagetitle, 39, 12, 39, 2);
                    strcpy(pageformat, setpageformat(pagetitle, maxcol));
                    dispstrhgc(pageformat, 2, 13, 0);
                    retpic();
                    break;
                case 3 :
                    savepic();
                    titlewriteallmenu();
                    titlemenuselect();
                    retpic();
                    writemenu(row, col, 2);
                    /* add by Suttipong Kanakakorn Sun  09-03-1989  01:29:17 */
                    set_all_lineperpage(INTERACTIVE); /* set (user)lineperpage */
                    /* writemenu(0, 1, 0); */  /* show new lines per page */
                    break;
                case 4 :
                case 5 :
                {
                    char *option_menu[2];
                    char *scrndx2;
                    char cur_dir[MAXDRIVE + MAXDIR], buf0[65], buf1[65];
                    int i, me = 1;
                    search_file_mode smode;

                    getcwd(cur_dir, sizeof(cur_dir));
                    sprintf(buf0, " ที่ Current  directory (%.30s) ", cur_dir);
                    sprintf(buf1, " ที่ Cuwriter directory (%.30s) ", cup_dir);
                    option_menu[0] = buf0;
                    option_menu[1] = buf1;
                    scrndx2 = savescrn(20, 8, 20 + 1 + find_menu_len(2, option_menu), 8 + 2 + 1);
                    i = smenu(20 + 1, 8 + 1, 2, option_menu, &me);
                    if (i == RETKEY)
                    {
                        smode = (me == 1) ? CUR_DIR : CW_DIR;
                        savepic();
                        dispstrhgc("•••••••••••••••", 30, 11, 2);
                        dispstrhgc("–กรุณารอสักครู่.....–", 30, 12, 2);
                        dispstrhgc("•••••••••••••••", 30, 13, 2);
                        (row == 4) ? saveoption(smode) : readoption(smode);
                        retpic();
                    }
                    resscrn(scrndx2, 20, 8, 20 + 1 + find_menu_len(2, option_menu), 8 + 2 + 1);
                    break;
                }
                case 6 :
                    savepic();
                    modewriteallmenu();
                    modemenuselect();
                    retpic();
                    /* add by Suttipong Kanakakorn Sun  09-03-1989  01:29:17 */
                    set_all_lineperpage(INTERACTIVE); /* set (user)lineperpage */
                    writemenu(row, col, 2);
                    break;
                case 7 :
                    if (pagebreak == YES)
                    {
                        pagebreak = NO;
                    }
                    else
                    {
                        pagebreak = YES;
                    }
                    writemenu(row, col, 2);
                    break;
            }
            break;
    }
}

void writeallmenu(void)
{
    int i;
    clsall();
    _rectangle(0, 0, 639, 347);
    prakeaw();
    /*
    dispstrhgc("จุฬาลงกรณ์มหาวิทยาลัย", 6, 0, BOLDATTR);
    */
    dispstrhgc("จุฬาลงกรณ์มหาวิทยาลัย", 6, 0, ITALICATTR);
    dispstrhgc("CU-PRINT", 31, 1, ENLARGEATTR | BOLDATTR | ONELINEATTR);
    dispprintf(22, 2, NORMALATTR,
                "Version 1.41  %s %s",
                prog_date, prog_time);
    _line(0, 24, 639, 24);
    dispstrhgc("โปรแกรมจัดพิมพ์เอกสารภาษาไทย/อังกฤษ", 25, 15, ONELINEATTR | BOLDATTR);
    mcol[0] = 3;
    mcol[1] = mcol[0] + mlenght + 1;
    mcol[2] = mcol[1] + mlenght + 1;
    smcol[0] = mcol[0] + mlenght - 1;
    smcol[1] = mcol[1] + mlenght - 1;
    smcol[2] = mcol[2] + mlenght - 1;
    _rectangle(mcol[0] * 8 - 2, 62, (mcol[0] + mlenght) * 8 + 2, 225);
    i = 0;
    while (i <= rowmax[0])
    {
        writemenu(i++, 0, 0);
    }
    _rectangle(mcol[1] * 8 - 2, 62, (mcol[1] + mlenght) * 8 + 2, 225);
    i = 0;
    while (i <= rowmax[1])
    {
        writemenu(i++, 1, 0);
    }
    _rectangle(mcol[2] * 8 - 2, 62, (mcol[2] + mlenght) * 8 + 2, 225);
    i = 0;
    while (i <= rowmax[2])
    {
        writemenu(i++, 2, 0);
    }
}

void menuselect(void)
{
    int c;
    int row=0,col=0;
    writemenu(row,col,REVERSEATTR);
    do{
        c = ebioskey(0);
        switch (c)
        {
            case UPKEY  :
                writemenu(row, col, 0);
                if (row == 0)
                {
                    row = rowmax[col];
                }
                else
                {
                    row--;
                }
                writemenu(row, col, REVERSEATTR);
                break;
            case DNKEY  :
                writemenu(row, col, 0);
                if (row == rowmax[col])
                {
                    row = 0;
                }
                else
                {
                    row++;
                }
                writemenu(row, col, REVERSEATTR);
                break;
            case RIKEY  :
                writemenu(row, col, 0);
                if (col == 2)
                {
                    col = 0;
                }
                else
                {
                    col++;
                }
                if (row > rowmax[col])
                {
                    row = rowmax[col];
                }
                writemenu(row, col, REVERSEATTR);
                break;
            case LEKEY  :
                writemenu(row, col, 0);
                if (col == 0)
                {
                    col = 2;
                }
                else
                {
                    col--;
                }
                if (row > rowmax[col])
                {
                    row = rowmax[col];
                }
                writemenu(row, col, REVERSEATTR);
                break;
            case RETKEY :
                docommand(row, col);
                break;
            case ALTX   :
                quitprog = YES;
                break;
        }
    } while (quitprog == NO);
}

void prtwriteallmenu(void)
{
    int i;
    dispstrhgc("••••••••••••••••••••••••••••••", 4, 9, 0);
    dispstrhgc("–                              –", 4, 10, 0);
    dispstrhgc("–                              –", 4, 11, 0);
    dispstrhgc("–                              –", 4, 12, 0);
    dispstrhgc("••••••••••••••••••••••••••••••", 4, 13, 0);
    i = 0;
    while (i <= prtrowmax)
    {
        prtwritemenu(i++, 0);
    }
}

void prtwritemenu(int row, font_attr attr)
{
   switch (row)
   {
        case 0 :
            switch (printer)
            {
                case EPSON9PIN80COLTYPE1 :
                    dispstrhgc(" เครื่องพิมพ์  FX 80,800 : EX800  ", 5, 10, attr);
                    break;
                case EPSON9PIN136COLTYPE1 :
                    dispstrhgc(" เครื่องพิมพ์  FX 100,850,1050    ", 5, 10, attr);
                    break;
                case EPSON9PIN80COLTYPE2 :
                    dispstrhgc(" เครื่องพิมพ์  LX 80,800          ", 5, 10, attr);
                    break;
                case EPSON24PIN80COL :
                    dispstrhgc(" เครื่องพิมพ์  LQ 500,800         ", 5, 10, attr);
                    break;
                case EPSON24PIN136COL :
                    dispstrhgc(" เครื่องพิมพ์  LQ 1050,1500,2500  ", 5, 10, attr);
                    break;
                case NEC24PIN80COL :
                    dispstrhgc(" เครื่องพิมพ์  NEC P2200          ", 5, 10, attr);
                    break;
                case NEC24PIN136COL :
                    dispstrhgc(" เครื่องพิมพ์  NEC P5,P7,P9 XL    ", 5, 10, attr);
                    break;
            }
            break;
        case 1 :
            if(smallpaper == NO)
            {
                dispstrhgc(" ขนาดหน้ากระดาษ      136 คอลัมน์ ", 5, 11, attr);
            }
            else
            {
                dispstrhgc(" ขนาดหน้ากระดาษ       80 คอลัมน์ ", 5, 11, attr);
            }
            break;
        case 2 :
            if(prtcodestd == YES)
            {
                dispstrhgc(" รหัสเครื่องพิมพ์             สมอ. ", 5, 12, attr);
            }
            else
            {
                dispstrhgc(" รหัสเครื่องพิมพ์            เกษตร ", 5, 12, attr);
            }
            break;
   }
}

void prtmenuselect(void)
{
    int quitprt = NO;
    int c;
    int row = 0;
    prtwritemenu(row, 2);
    do
    {
        c = ebioskey(0);
        switch (c)
        {
            case UPKEY :
                prtwritemenu(row, 0);
                if (row == 0)
                {
                    row = prtrowmax;
                }
                else
                {
                    row--;
                }
                prtwritemenu(row, 2);
                break;
            case DNKEY :
                prtwritemenu(row, 0);
                if (row == prtrowmax)
                {
                    row = 0;
                }
                else
                {
                    row++;
                }
                prtwritemenu(row, 2);
                break;
            case RETKEY :
                prtdocommand(row);
                break;
            case ESCKEY :
                quitprt = YES;
                break;
        }
    } while (quitprt == NO);
}

void setprinter(int smallpaper, int printer24pin)
{
    int col;
    if (smallpaper == YES)
    {
        col = 80;
    }
    else
    {
        col = 136;
    }
    if (printer24pin==YES)
    {
        maxcol = col * cpi / 10;
        maxdot = col * 18;
        maxbuffer= col * 18 * 2;
    }
    else
    {
        maxcol = col * cpi / 10;
        maxdot = col * 24;
        maxbuffer = col * 24 * 2;
    }
}

void prtdocommand(int row)
{
   switch (row)
   {
        case 0 :
            switch (printer)
            {
                case EPSON9PIN80COLTYPE1:
                    printer = EPSON9PIN136COLTYPE1;
                    linespace = 15;
                    smallpaper = NO;
                    printer24pin = NO;
                    break;
                case EPSON9PIN136COLTYPE1:
                    printer = EPSON9PIN80COLTYPE2;
                    linespace = 4;
                    smallpaper = YES;
                    printer24pin = NO;
                    break;
                case EPSON9PIN80COLTYPE2:
                    printer = EPSON24PIN80COL;
                    linespace = 4;
                    smallpaper = YES;
                    printer24pin = YES;
                    break;
                case EPSON24PIN80COL:
                    printer = EPSON24PIN136COL;
                    linespace = 4;
                    smallpaper = NO;
                    printer24pin = YES;
                    break;
                case EPSON24PIN136COL:
                    printer = NEC24PIN80COL;
                    linespace = 4;
                    smallpaper = YES;
                    printer24pin = YES;
                    break;
                case NEC24PIN80COL:
                    printer = NEC24PIN136COL;
                    linespace = 4;
                    smallpaper = NO;
                    printer24pin = YES;
                    break;
                case NEC24PIN136COL:
                    printer = EPSON9PIN80COLTYPE1;
                    linespace = 15;
                    smallpaper = YES;
                    printer24pin = NO;
                    break;
            }
            prtwritemenu(row, 2);
            prtwritemenu(1, 0);  /* show new paper width */
            break;
        case 1:
            if (smallpaper == NO)
            {
                smallpaper = YES;
            }
            else
            {
                if ((printer==FX) || (printer==LX))
                    ;       /*no chg*/
                else
                {
                    smallpaper = NO;
                }
            }
            prtwritemenu(row, 2);
            break;
        case 2:
            if (prtcodestd == NO)
            {
                prtcodestd  = YES;
            }
            else
            {
                prtcodestd = NO;
            }
            prtwritemenu(row, 2);
            break;
   }
   setprinter(smallpaper, printer24pin);
}

void modewriteallmenu(void)
{
   int i;
   char smcol;
   smcol=mcol[2]-4;
   dispstrhgc("••••••••••••••••••••••••••••",smcol,10,0);
   dispstrhgc("–                            –",smcol,11,0);
   dispstrhgc("–                            –",smcol,12,0);
   dispstrhgc("••••••••••••••••••••••••••••",smcol,13,0);
   i = 0;
   while(i <= moderowmax)
         modewritemenu(i++,0);
}

void modewritemenu(int row, int attr)
{
    char smcol;
    smcol = mcol[2] - 3;
    switch (row)
    {
        case 0 :
            if (graphicprint == YES)
            {
                dispstrhgc(" Print Mode         GRAPHIC ", smcol, 11, attr);
            }
            else
            {
                dispstrhgc(" Print Mode           TEXT  ", smcol, 11, attr);
            }
            break;
        case 1 :
            if (nlqmode==YES)
            {
                dispstrhgc(" Precision             NLQ  ", smcol, 12, attr);
            }
            else
            {
                dispstrhgc(" Precision            Draft ", smcol, 12, attr);
            }
            break;
    }
}

void modemenuselect(void)
{
    int quit = NO;
    int c;
    int row = 0;
    modewritemenu(row, 2);
    do
    {
        c = ebioskey(0);
        switch (c)
        {
            case UPKEY  :
                modewritemenu(row, 0);
                if (row == 0)
                {
                    row = moderowmax;
                }
                else
                {
                    row--;
                }
                modewritemenu(row, 2);
                break;
            case DNKEY  :
                modewritemenu(row, 0);
                if (row == moderowmax)
                {
                    row = 0;
                }
                else
                {
                    row++;
                }
                modewritemenu(row, 2);
                break;
            case RETKEY :
                modedocommand(row);
                break;
            case ESCKEY :
                quit = YES;
                break;
        }
    } while (quit == NO);
}

void modedocommand(int row)
{
   switch (row)
   {
        case 0 :
            if (graphicprint == YES)
            {
                graphicprint = NO;
            }
            else
            {
                graphicprint = YES;
            }
            modewritemenu(row, 2);
            break;
        case 1 :
            if (nlqmode == YES)
            {
                nlqmode = NO;
            }
            else
            {
                nlqmode = YES;
            }
            modewritemenu(row, 2);
            break;
   }
}

void titlewriteallmenu(void)
{
    int i;
    char smcol;
    smcol = mcol[2] - 4;
    dispstrhgc("••••••••••••••••••••••••••••", smcol, 7, 0);
    dispstrhgc("–                            –", smcol, 8, 0);
    dispstrhgc("–                            –", smcol, 9, 0);
    dispstrhgc("–                            –", smcol, 10, 0);
    dispstrhgc("••••••••••••••••••••••••••••", smcol, 11, 0);
    i = 0;
    while (i <= titlerowmax)
    {
        titlewritemenu(i++, 0);
    }
}

void titlewritemenu(int row, int attr)
{
    char smcol;
    smcol = mcol[2] - 3;
    switch (row)
    {
        case 0 :
            switch (locheading)
            {
                case 0 :
                    dispstrhgc(" ตำแหน่งหัวกระดาษ       ไม่พิมพ์ ", smcol, 8, attr);
                    break;
                case 1 :
                    dispstrhgc(" ตำแหน่งหัวกระดาษ        ซ้าย  ", smcol, 8, attr);
                    break;
                case 2 :
                    dispstrhgc(" ตำแหน่งหัวกระดาษ        กลาง ", smcol, 8, attr);
                    break;
                case 3 :
                    dispstrhgc(" ตำแหน่งหัวกระดาษ        ขวา  ", smcol, 8, attr);
                    break;
                case 4 :
                    dispstrhgc(" ตำแหน่งหัวกระดาษ      ขวา,ซ้าย", smcol, 8, attr);
                    break;
                case 5 :
                    dispstrhgc(" ตำแหน่งหัวกระดาษ      ซ้าย,ขวา", smcol, 8, attr);
                    break;
            }
            break;
        case 1 :
            switch (locfooting)
            {
                case 0 :
                    dispstrhgc(" ตำแหน่งท้ายกระดาษ      ไม่พิมพ์ ", smcol, 9, attr);
                    break;
                case 1 :
                    dispstrhgc(" ตำแหน่งท้ายกระดาษ       ซ้าย  ", smcol, 9, attr);
                    break;
                case 2 :
                    dispstrhgc(" ตำแหน่งท้ายกระดาษ       กลาง ", smcol, 9, attr);
                    break;
                case 3 :
                    dispstrhgc(" ตำแหน่งท้ายกระดาษ       ขวา  ", smcol, 9, attr);
                    break;
                case 4 :
                    dispstrhgc(" ตำแหน่งท้ายกระดาษ     ขวา,ซ้าย", smcol, 9, attr);
                    break;
                case 5 :
                    dispstrhgc(" ตำแหน่งท้ายกระดาษ     ซ้าย,ขวา", smcol, 9, attr);
                    break;
            }
            break;
        case 2 :
            switch (locpagetitle)
            {
                case 0 :
                    dispstrhgc(" ตำแหน่งหน้ากระดาษ      ไม่พิมพ์ ", smcol, 10, attr);
                    break;
                case 1 :
                    dispstrhgc(" ตำแหน่งหน้ากระดาษ       ซ้าย  ", smcol, 10, attr);
                    break;
                case 2 :
                    dispstrhgc(" ตำแหน่งหน้ากระดาษ       กลาง ", smcol, 10, attr);
                    break;
                case 3 :
                    dispstrhgc(" ตำแหน่งหน้ากระดาษ       ขวา  ", smcol, 10, attr);
                    break;
                case 4 :
                    dispstrhgc(" ตำแหน่งหน้ากระดาษ     ขวา,ซ้าย", smcol, 10, attr);
                    break;
                case 5 :
                    dispstrhgc(" ตำแหน่งหน้ากระดาษ     ซ้าย,ขวา", smcol, 10, attr);
                    break;
            }
            break;
    }
}

void titlemenuselect(void)
{
    int quit = NO;
    int c;
    int row = 0;
    titlewritemenu(row, 2);
    do
    {
        c = ebioskey(0);
        switch (c)
        {
            case UPKEY  :
                titlewritemenu(row, 0);
                if (row == 0)
                {
                    row = titlerowmax;
                }
                else
                {
                    row--;
                }
                titlewritemenu(row, 2);
                break;
            case DNKEY  :
                titlewritemenu(row, 0);
                if (row == titlerowmax)
                {
                    row = 0;
                }
                else
                {
                    row++;
                }
                titlewritemenu(row, 2);
                break;
            case RETKEY :
                titledocommand(row);
                break;
            case ESCKEY :
                quit = YES;
                break;
        }
    } while (quit == NO);
}

void titledocommand(int row)
{
    switch (row)
    {
        case 0 :
            if (locheading != 5)
            {
                locheading++;
            }
            else
            {
                locheading = 0;
            }
            break;
        case 1 :
            if (locfooting != 5)
            {
                locfooting++;
            }
            else
            {
                locfooting = 0;
            }
            break;
        case 2 :
            if (locpagetitle != 5)
            {
                locpagetitle++;
            }
            else
            {
                locpagetitle = 0;
            }
            break;
    }
    /*writemenu(0, 1, 0);*/
    titlewritemenu(row, 2);
}
