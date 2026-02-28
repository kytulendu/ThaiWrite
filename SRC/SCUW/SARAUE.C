#include "Thai.h"
#include "Global.h"
#include "TCtype.h"


/*------------------------------------------------------------------------
Module name  : SaraUeRtn


Date Written : 17 May, 1988 8:38:18 AM
Last Update  : 18 May, 1988 2:19:20 PM
------------------------------------------------------------------------*/

unsigned char *SaraUeRtn(unsigned char *TempIndx)
{
    /* Check vowel routine here */
    if (isttnl(*(TempIndx + 1)))
    {
        if ((TempIndx + 2) <= RightMargin)
        {
            return(TempIndx + 2);
        }
    }
    else
    {
        switch (*(TempIndx - 1))
        {
            case RoreReo:
                if (findchar(*(TempIndx + 1), "¡§´¹"))
                {
                    if(!istrvwl(*(TempIndx + 2)) && TempIndx + 2 <= RightMargin)
                    {
                        return(TempIndx + 1);
                    }
                }
                else
                {
                    return(TempIndx);
                }
                break;
            case HorNokHook:
                switch (*(TempIndx + 1))
                {
                case KoreGai:
                case DoreDek:
                case MoreMar:
                    return(TempIndx - 2);
                default:
                    return(TempIndx);
                }
            case HorHeeb:
                if (*(TempIndx + 1) == NgorNgoo)
                {
                    return(TempIndx - 2);
                }
                else
                {
                    return(TempIndx);
                }
            case OrAng:
                if (findchar(*(TempIndx+1), "¡§´¹"))
                {
                    if(TempIndx + 1 <= RightMargin)
                    {
                        return(TempIndx + 1);
                    }
                    else
                    {
                        return(TempIndx - 2);
                    }
                }
                else
                {
                    return(TempIndx);
                }
            default:
                if ((TempIndx + 1) <= RightMargin)
                {
                    return(TempIndx + 1);
                }
        }
    }
/* Check to cut in front */
/*
    if (!findchar(*(TempIndx - 1), "¹ÁÃÅ"))
    {
        return(TempIndx - 2);
    }
    else
    {
        return(FAIL);
    }
*/

    switch (*(TempIndx - 1))
    {
        case NoreNoo:
            if (!findchar(*(TempIndx - 2), "¤¼ËÍ"))
            {
                return(TempIndx - 2);
            }
            break;
        case MoreMar:
            if (*(TempIndx - 2) != HorHeeb)
            {
                return(TempIndx-2);
            }
            else
            {
                /* cut before HorHeep */
                return(TempIndx - 3);
            }
        case RoreReo:
            if(!findchar(*(TempIndx - 2), "¤µ»¾"))
            {
                return(TempIndx - 2);
            }
            break;
        case LoreLing:
            if(!findchar(*(TempIndx - 2), "¡¤¶¼ÊÍ"))
            {
                return(TempIndx - 2);
            }
            break;
        default:
            return(TempIndx - 2);
    }
    return(FAIL);
}
