#include "Thai.h"
#include "Global.h"
#include "Routine.h"

/* ------------ RoreRu  Rtn ------------ */
/*  Programmer  : Subun Yenjaichon
    Date Written    : Monday, 16 May, 1988 10:55:24 AM
    Last Updated    : Monday, 16 May, 1988 10:55:48 AM
*/

unsigned char *RoreRuRtn(unsigned char *TempIndx)
{
    unsigned char *TempIndxm1 = TempIndx - 1;
    short i;
    short RoreRuWdCnt = 7; /* 8-1 */
    static unsigned char *RoreRuWd[] = {"Ä¡Éì", "Ä´Ù", "Ä´Õ", "ÄªÒ", "Ä¤àÇ·",
        "Ä·ÑÂ", "ÄÉÕ", "Ä·¸Ôì", "Ä·¸Õ"};

    if(!(findchar(*TempIndxm1, "¡¤µ·¹»¾ÁÈÊ")))
    {
        /* cut before RoreRu */
        return(TempIndxm1);
    }
    else
    {   /*  possible leading consonants is found  do */
        if (*TempIndxm1 == PoreParn && !(nstrcmp("¾Ä¡Éì", TempIndxm1)))
        {
            /* cut before ¾Ä¡Éì */
            return(TempIndx - 2);
        }

        for (i = 0; i <= RoreRuWdCnt; ++i)
        {
            if(!(nstrcmp(RoreRuWd[i], TempIndx)))
            {
                /* if found, cut before RoreRu */
                return(TempIndxm1);
            }
        }
        /* cut before possible leading consonants */
        return(TempIndx - 2);
    }
}
