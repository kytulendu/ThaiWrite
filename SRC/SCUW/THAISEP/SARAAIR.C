#include "Thai.h"
#include "TCtype.h"
#include "Global.h"
#include "Routine.h"

/* ------------ SaraAir Rtn ------------ */
/*  Programmer  : Subun Yenjaichon
    Date Written    : Wednesday, 11 May, 1988 4:02:08 PM
    Last Updated    : Saturday, 14 May, 1988 9:39:42 AM
*/

unsigned char *SaraAirRtn(register unsigned char *TempIndx)
{
    register short i;
    unsigned char *TempIndxp1 = TempIndx + 1;
    unsigned char *TempIndxm1 = TempIndx - 1;
    unsigned char *TempIndxp2 = TempIndx + 2;
    unsigned char *TempIndxm2 = TempIndx - 2;

    short SoreSeoTableLen = 6;    /* 7-1 */
    static char ToreTaharnWd[] = "∑·¬ß";
    static char ShoreChangWd[] = "™·«ß";
    static char *SoreSeoTable[] =  {" ·≈Á§ Ï", " ·§«√Ï", " ·µπ¥", " ·°π‡πÕ√Ï",
        " ·°π¥‘", " ·πÁ§", " ·≈ß"};

    if (TempIndxp1 <= RightMargin && findchar(*(TempIndxp2), "¢®≠∞∂¿Õ"))
    {
        /* cut after following consonant */
        return(TempIndxp1);
    }

    if (TempIndxp2 <= RightMargin && isttnl(*TempIndxp2) &&
        findchar(*(TempIndx + 3), "¢®≠∞∂¿Õ"))
    {
        /* cut after tonal mark */
        return(TempIndxp2);
    }

    /* check exception words */
    switch (*TempIndxm1)
    {
        case ShoreChang:
            if (!(nstrcmp(ShoreChangWd, TempIndxm1))) /* if same return zero */
            {
                /* cut before consonant */
                return(TempIndxm2);
            }
            /* cut before SaraAir */
            return(TempIndxm1);
        case ToreTaharn:
            if (!(nstrcmp(ToreTaharnWd,TempIndxm1)))
            {
                /* cut before consonant */
                return(TempIndxm2);
            }
            return(TempIndxm1);
        case SoreSeo:
            for (i = 0; i <= SoreSeoTableLen; ++i)
            {
                if (!(nstrcmp(SoreSeoTable[i], TempIndxm1)))
                {
                    /* cut before consonant */
                    return(TempIndxm2);
                }
            }
            /* cut before SaraAir */
            return(TempIndxm1);
    }
    /* cut before SaraAir */
    return(TempIndxm1);
}
