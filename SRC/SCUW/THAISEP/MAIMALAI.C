#include "Thai.h"
#include "Global.h"
#include "Routine.h"
#include "TCtype.h"

/* ------------ MaiMalai Rtn ------------ */
/*  Programmer  : Subun Yenjaichon
    Date Written    : Thursday, 12 May, 1988 8:54:52 AM
    Last Updated    : Saturday, 14 May, 1988 12:08:05 PM
*/

unsigned char *MaiMalaiFC(unsigned char *TempIndx);

unsigned char *MaiMalaiRtn(register unsigned char *TempIndx)
{
    register short i;
/*  short MaiMalaiExNum = 2;  */  /* 3-1 */
    short MaiMalaiEx2Num = 6; /* 7-1 */
    register unsigned char *TempIndxp1 = TempIndx + 1;
/*  static unsigned char *MaiMalaiExWord[] = {"‰ª√…≥’¬", "‰ø≈∑Ï", "‰ª√∑Ï"};*/
    static unsigned char *MaiMalaiExWord2[] = {"‰À¡", "‰À¡È", "‰Àπ", "‰∂ß", "‰º∑", "‰Õ»", "‰©π"};

    /* TAIL CUT RTN. by rule  ‰c/c  */
    if (TempIndxp1 <= RightMargin && istcon(*(TempIndx + 2)))
    {
        if (*(TempIndx + 3) == KARAN)
        {
            if(TempIndx + 3 <= RightMargin)
            {
                return(TempIndx + 3);
            }
            else
            {
                return(MaiMalaiFC(TempIndx));
            }
        }
/*
        for (i = 0; i <= MaiMalaiExNum ;++i)
        {
            if (!(nstrcmp(MaiMalaiExWord[i], TempIndx)))
            {
                return(MaiMalaiFC(TempIndx));
            }
        }
*/
        if (findchar(*(TempIndx + 2), "¬√≈«"))
        {
            return(MaiMalaiFC(TempIndx));
        }
        else
        {
            for (i = 0; i <= MaiMalaiEx2Num; ++i)
            {
                if(!(nstrcmp(MaiMalaiExWord2[i], TempIndx)))
                {
                    /* cut before MaiMalai */
                    return(TempIndx - 1);
                }
            }
            return(TempIndxp1); /* cut after following-consonant */
        }
    }
    else
    {
        if (isttnl(*(TempIndx + 2)) && TempIndx + 2 <= RightMargin)
        {
            return(TempIndx + 2);     /* cut after tonal */
        }
    }

    return(MaiMalaiFC(TempIndx));
}

unsigned char *MaiMalaiFC(unsigned char *TempIndx)
{
    register short i;
    register unsigned char *TempIndxm1 = TempIndx - 1;
    short SoSuaMMLExNum = 5;  /* 6-1 */
    static unsigned char ChoChangEx[]= "™‰¡æ√";
    static unsigned char *SoSuaMMLExTable[] = {" ‰µ√Í§Ï", " ‰ª√∑Ï", " ‰≈´Ï",
        " ‰∫", " ‰≈¥Ï", " ‰µ≈Ï"};

    switch (*(TempIndxm1))
    {
        case SOSUA:
            for (i = 0; i <= SoSuaMMLExNum; ++i)
            {
                /* if same cut before consonant */
                if (!(nstrcmp(SoSuaMMLExTable[i], TempIndxm1)))
                {
                    return(TempIndx - 2);
                }
            }
            /* cut before MaiMalai */
            return(TempIndxm1);
        case CHOCHANG:
            if (nstrcmp(ChoChangEx, TempIndxm1))
            {
                /* cut before MaiMalai */
                return(TempIndxm1);
            }
            else
            {
                /* cut before leading-consonant */
                return(TempIndx - 2);
            }
        /* case MoMa is Optional: ¡‰À»«√√…Ï ¡‰À»Ÿ√¬Ï */
        default:
            /* cut before MaiMalai */
            return(TempIndxm1);
    }
}
