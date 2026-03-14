#include "thai.h"
#include "global.h"
#include "tctype.h"
#include "routine.h"

unsigned char *Sara_URtn(register unsigned char *TempIndx)
{
    register unsigned char *plus1 = TempIndx + 1, *minus2 = TempIndx - 2;

    if (findchar(*(plus1), "¦©«¬±¶¼½ÄÇÍÎ") ||
        *plus1 == PHOSAMPHAO && nstrcmp("ÍÊ", minus2) ||
        *plus1 == RORUA && *(TempIndx - 1) != THOTHONG &&
        nstrcmp("ÍÊ", minus2) ||
        *plus1 == HOHIP && nstrcmp("¾Â", minus2))
    {
        return(TempIndx);
    }
    else if (plus1 <= RightMargin)
    {
        if (isttnl(*(plus1)))
        {
            if (*(plus1) == MAITRI)
            {
                switch (*(TempIndx - 1))
                {
                    case CHOCHAN:
                        if (*(TempIndx + 2) != KOKAI && *(TempIndx + 2) != YOYAK)
                        {
                            return(plus1);
                        }
                        break;
                    case TOTAO:
                        if (!findchar(*(TempIndx + 2), "¡§´"))
                        {
                            return(plus1);
                        }
                        break;
                    case POPLA:
                        if (!findchar(*(TempIndx + 2), "¡´º"))
                        {
                            return(plus1);
                        }
                        break;
                }
            }
            else if (TempIndx + 2 <= RightMargin)
            {
                return(TempIndx + 2);
            }
        }
    }
    if (findchar(*(TempIndx - 1), "¢¤¦¨©ª«¬­®¯°±²³º»¼½¾¿ÀÈÉÌÎ"))
    {
        return(minus2);
    }
    else
    {
        switch(*(TempIndx - 1))
        {
            case KOKAI:
                return((findchar(*minus2, "ÁÈÊÍ")) ? FAIL : minus2);
            case NGONGU:
                return((*minus2 == HOHIP || *minus2 == OANG) ? FAIL : minus2);
            case DODEK:
                return((findchar(*minus2, "¼ÊÍ")) ? FAIL : minus2);
            case TOTAO:
                if (!nstrcmp("àË", TempIndx - 3) || !nstrcmp("¸Ò", TempIndx - 3))
                {
                    return(TempIndx);
                }
                else
                {
                    return((*minus2 == CHOCHAN) ? FAIL : minus2);
                }
            case THOTHUNG:
                return((*minus2 == SOSUA || *plus1 == KARAN) ? FAIL : minus2);
            case THOTHAHAN:
                return((*minus2 == POPLA) ? FAIL : minus2);
            case THOTHONG:
                return((*minus2 == MOMA) ? FAIL : minus2);
            case NONU:
                return((findchar(*minus2, "¢µ¸ÁÊËÍ")) ? FAIL : minus2);
            case MOMA:
                return((findchar(*minus2, "¢ÊË")) ? FAIL : minus2);
            case YOYAK:
                return((findchar(*minus2, "¾ÊËÍ")) ? FAIL : minus2);
            case RORUA:
                if (*(TempIndx - 3) == SARA_E && *(TempIndx - 2) == MOMA)
                {
                    return(TempIndx);
                }
                else
                {
                    return((findchar(*minus2, "¡¤¨´µ·»¼¾ÇÊËÍ")) ? FAIL : minus2);
                }
            case LOLING:
                return((findchar(*minus2, "¡¢¤©¶»¼¾¿ÊË")) ? FAIL : minus2);
            case WOWAEN:
                return((*minus2 == HOHIP) ?   FAIL : minus2);
            case SOSUA:
                return((*minus2 == PHOPHAN || *minus2 == OANG) ? FAIL : minus2);
            case HOHIP:
                return((*minus2 == PHOPHAN || *minus2 == LOLING) ? FAIL : minus2);
            case OANG:
                return((*minus2 == CHOCHANG) ? FAIL : minus2);
        }
    }
    return(FAIL);
}
