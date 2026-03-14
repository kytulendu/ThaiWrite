#include "Thai.h"
#include "Global.h"
#include "Routine.h"

/* ------------ Ru  Rtn ------------ */
/*  Programmer  : Subun Yenjaichon
    Date Written    : Monday, 16 May, 1988 10:55:24 AM
    Last Updated    : Monday, 16 May, 1988 10:55:48 AM
*/

unsigned char *RuRtn(unsigned char *TempIndx)
{
    unsigned char *TempIndxm1 = TempIndx - 1;
    short i;
    short RuWdCnt = 7; /* 8-1 */
    static unsigned char *RuWd[] = {"Ä¡Éì", "Ä´Ù", "Ä´Õ", "ÄªÒ", "Ä¤àÇ·",
        "Ä·ÑÂ", "ÄÉÕ", "Ä·¸Ôì", "Ä·¸Õ"};

    if(!(findchar(*TempIndxm1, "¡¤µ·¹»¾ÁÈÊ")))
    {
        /* cut before RU */
        return(TempIndxm1);
    }
    else
    {   /*  possible leading consonants is found  do */
        if (*TempIndxm1 == PHOPHAN && !(nstrcmp("¾Ä¡Éì", TempIndxm1)))
        {
            /* cut before ¾Ä¡Éì */
            return(TempIndx - 2);
        }

        for (i = 0; i <= RuWdCnt; ++i)
        {
            if(!(nstrcmp(RuWd[i], TempIndx)))
            {
                /* if found, cut before Ru */
                return(TempIndxm1);
            }
        }
        /* cut before possible leading consonants */
        return(TempIndx - 2);
    }
}
