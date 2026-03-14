#include "thai.h"
#include "tctype.h"
#include "global.h"
#include "routine.h"

/* ------------ Sara Ae Rtn ------------ */
/*  Programmer  : Subun Yenjaichon
    Date Written    : Wednesday, 11 May, 1988 4:02:08 PM
    Last Updated    : Saturday, 14 May, 1988 9:39:42 AM
*/

unsigned char *Sara_AeRtn(register unsigned char *TempIndx)
{
    register short i;
    unsigned char *TempIndxp1 = TempIndx + 1;
    unsigned char *TempIndxm1 = TempIndx - 1;
    unsigned char *TempIndxp2 = TempIndx + 2;
    unsigned char *TempIndxm2 = TempIndx - 2;

    short SoSuaTableLen = 6;    /* 7-1 */
    static char ThoThaHanWd[] = "∑·¬ß";
    static char ChoChangWd[] = "™·«ß";
    static char *SoSuaTable[] =  {" ·≈Á§ Ï", " ·§«√Ï", " ·µπ¥", " ·°π‡πÕ√Ï",
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
        case CHOCHANG:
            if (!(nstrcmp(ChoChangWd, TempIndxm1))) /* if same return zero */
            {
                /* cut before consonant */
                return(TempIndxm2);
            }
            /* cut before Sara Ae */
            return(TempIndxm1);
        case THOTHAHAN:
            if (!(nstrcmp(ThoThaHanWd,TempIndxm1)))
            {
                /* cut before consonant */
                return(TempIndxm2);
            }
            return(TempIndxm1);
        case SOSUA:
            for (i = 0; i <= SoSuaTableLen; ++i)
            {
                if (!(nstrcmp(SoSuaTable[i], TempIndxm1)))
                {
                    /* cut before consonant */
                    return(TempIndxm2);
                }
            }
            /* cut before Sara Ae */
            return(TempIndxm1);
    }
    /* cut before Sara Ae */
    return(TempIndxm1);
}
