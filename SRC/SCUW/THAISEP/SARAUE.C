#include "thai.h"
#include "global.h"
#include "tctype.h"


/*------------------------------------------------------------------------
Module name  : Sara_UeRtn


Date Written : 17 May, 1988 8:38:18 AM
Last Update  : 18 May, 1988 2:19:20 PM
------------------------------------------------------------------------*/

unsigned char *Sara_UeRtn(unsigned char *TempIndx)
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
            case RORUA:
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
            case HONOKHUK:
                switch (*(TempIndx + 1))
                {
                case KOKAI:
                case DODEK:
                case MOMA:
                    return(TempIndx - 2);
                default:
                    return(TempIndx);
                }
            case HOHIP:
                if (*(TempIndx + 1) == NGONGU)
                {
                    return(TempIndx - 2);
                }
                else
                {
                    return(TempIndx);
                }
            case OANG:
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
        case NONU:
            if (!findchar(*(TempIndx - 2), "¤¼ËÍ"))
            {
                return(TempIndx - 2);
            }
            break;
        case MOMA:
            if (*(TempIndx - 2) != HOHIP)
            {
                return(TempIndx-2);
            }
            else
            {
                /* cut before HorHeep */
                return(TempIndx - 3);
            }
        case RORUA:
            if(!findchar(*(TempIndx - 2), "¤µ»¾"))
            {
                return(TempIndx - 2);
            }
            break;
        case LOLING:
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
