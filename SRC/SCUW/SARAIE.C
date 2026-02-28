#include "TCtype.h"
#include "Thai.h"
#include "Global.h"

/*  -------------SARA Ie Rtn ------------
    Programmer : Subun Yenjaichon
    Date written : Tuesday, 17 May, 1988 2:53:20 PM
    Last Updated :  Monday, 23 May, 1988
    ----------------------------------  */

unsigned char *SaraIeRtn(unsigned char *TempIndx)
{
    short i;
    unsigned char *TempIndxm1 = TempIndx - 1;
    unsigned char *TempIndxm2 = TempIndx - 2;
    unsigned char *TempIndxm3 = TempIndx - 3;
    unsigned char *TempIndxm4 = TempIndx - 4;
    unsigned char *TempIndxp1 = TempIndx + 1;
    unsigned char *TempIndxp2 = TempIndx + 2;
    static unsigned char *DoreDekSaraIeEx[] = {"¾ÃÃ´Ô","ÇÃÃ´Ô"};
    static unsigned char *ToreTaoSaraIeEx[] = {"ÇÑµÔ","ºÑµÔ","­ÑµÔ","¹ÔµÔ",
                    "ÂØµÔ","ÊÙµÔ","ªÒµÔ","­ÒµÔ","âªµÔ"};
    static unsigned char *JoreJarnSaraIeEx[] = {"ÊÙ¨Ô","ÊØ¨Ô"};

    /* start  check SaraA before */
    if (*TempIndxm3 == SaraA)
    {
        if (isttnl(*TempIndxp1) && TempIndxp2 <= RightMargin)
        {
            /* cut after speller */
            return(TempIndxp2);
        }
        else
        {   Indx = TempIndxm3;
            /* Jmp to SaraARtn */
            return((*FuncPtr[*Indx])(Indx));
        }
    }
    else
    {
        if (*TempIndxm2 == SaraA)
        {
            if(isttnl(*TempIndxp1))
            {
                return((TempIndxp2 <=  RightMargin)?  TempIndxp2 : TempIndxm3);
            }
            return((TempIndxp1<= RightMargin)? TempIndxp1 : TempIndxm3);
        }
    }

    /* begin SaraIeRtn with out SaraA before */
    if (isttnl(*TempIndxp1) &&  TempIndxp2 <= RightMargin)
    {
        return(TempIndxp2);
    }

    if (findchar(*TempIndxp1,"¦¬®¯±²¶ÀÂÄËÍ"))
    {
        return(TempIndx);
    }

    switch (*TempIndxp1)
    {
        case KorKai:
            if (*TempIndxm1 != LoreLing)
            {
                return(TempIndx);
            }
            break;
        case KoreKwai:
            if (!(findchar(*TempIndxm1,"¹»¿ÃÅÊ")))
            {
                return(TempIndx);
            }
            break;
        case JoreJarn:
            if (!(findchar(*TempIndxm1,"¡¹ÁÍ")))
            {
                return(TempIndx);
            }
            break;
        case SoreSoe:
            if (*TempIndxm1 != MoreMar)
            {
                return(TempIndx);
            }
            break;
        case YoreYing:
            if (!(findchar(*TempIndxm1,"¯ÀÃÇÊ")))
            {
                return(TempIndx);
            }
            break;
        case ThorSantan:
            if (*TempIndxm1 != OrAng)
            {
                return(TempIndx);
            }
            break;
        case NoreNane:
            if (!(findchar(*TempIndxm1,"µ¾É")))
            {
                return(TempIndx);
            }
            break;
        case ToreTaharn:
            if (!(findchar(*TempIndxm1,"¹¾ÅÇÊÍ")))
            {
                return(TempIndx);
            }
            break;
        case ToreTong:
            if(*TempIndxm1 != PoreParn)
            {
                return(TempIndx);
            }
            break;
        case PoreParn:
            if(!(findchar(*TempIndxm1,"ª·¹Å")))
            {
                return(TempIndx);
            }
            break;
        case ForeFun:
            if(!(findchar(*TempIndxm1,"¡Å")))
            {
                return(TempIndx);
            }
            break;
        case LoreLing:
            if(!(findchar(*TempIndxm1,"«¹º¿ÁÃÇÈ")))
            {
                return(TempIndx);
            }
            break;
        case SoreSala:
            if (!(findchar(*TempIndxm1,"·¾ÃÅÇÍ")))
            {
                return(TempIndx);
            }
        case SoreRusi:
            if(!(findchar(*TempIndxm1,"¸¹¾ÃÇÈ")))
            {
                return(TempIndx);
            }
            break;
        case SoreSeo:
            if(!(findchar(*TempIndxm1,"«¹¾¿ÁÃÇÍÎ")))
            {
                return(TempIndx);
            }
            break;
    }

    /*  Front Cut */
    if (findchar(*TempIndxm1, "¡¢¤¦«¬±·»¿ÉÌÍ") || istlcon(*TempIndxm1))
    {
        /* cut before consonant */
        return(TempIndxm2);
    }
    switch (*TempIndxm1)
    {
        case JoreJarn:
            for(i = 0; i <= 1; ++i)
            {
                if (!(nstrcmp(JoreJarnSaraIeEx[i], TempIndxm3)))
                {
                    return(TempIndx);
                }
            }
            /* cut before JoreJarn */
            return(TempIndxm2);
        case DoreDek:
            for (i = 0; i <= 1; ++i)
            {
                if (!(nstrcmp(DoreDekSaraIeEx[i], TempIndxm4)))
                {
                    return(TempIndx-5);
                }
            }
            if (!(nstrcmp("ÊÇÑÊ´", (TempIndx - 5))))
            {
                return(TempIndx - 6);
            }
            /* cut before DoreDeck */
            return(TempIndxm2);
        case ToreTao:
            for (i = 0; i <= 8; ++i)
            {
                if (!(nstrcmp(ToreTaoSaraIeEx[i], TempIndxm3)))
                {
                    return(TempIndx);
                }
            }
            if (!(findchar(*TempIndxm2, "¡¤¹ÃÄÊ")))
            {
                /* cut before ToreTao */
                return(TempIndxm2);
            }
            break;
        case TorePootao:
            /* can't cut before TorePootao */
            break;
        case NoreNoo:
            if (!(findchar(*TempIndxm2, "¢ª¶ÃÇÊËÍ")))
            {
                /* cut before norenoo */
                return(TempIndxm2);
            }
            break;
        case RoreReo:
            if(!(findchar(*TempIndxm2, "¡¢¤¨µ¹º»¼¾ÀËÍ")))
            {
                /* cut before RoreReo */
                return(TempIndxm2);
            }
            break;
        case NgorNgoo:
            if (*TempIndxm2 != HorHeeb)
            {
                /* cut before NgorNgoo */
                return(TempIndxm2);
            }
            else
            {
                /* cut before HorHeeb */
                return(TempIndxm3);
            }
        case MoreMar:
            if (!(nstrcmp("ÀÙÁÔ", TempIndxm3)))
            {
                /* cut after SaraIe */
                return(TempIndx);
            }
            if (!(findchar(*TempIndxm2, "¢·ÊËÍ")))
            {
                /* cut before MoreMar */
                return(TempIndxm2);
            }
            break;
        case YoreYak:
            if (!(findchar(*TempIndxm2, "¢ÊË")))
            {
                /* cut before YoreYak */
                return(TempIndxm2);
            }
            break;
        case WoreWaan:
            if(!(findchar(*TempIndxm2, "¢¤¶·ÃÊËÍ")))
            {
                /* cut before WoreWaan */
                return(TempIndxm2);
            }
            break;
        case LoreLing:
            if (!(findchar(*TempIndxm2, "¡¢ªµ»¼¾ÅÇÊËÍ")))
            {
                /* cut before LoreLing */
                return(TempIndxm2);
            }
            break;
        case HorHeeb:
            if (*TempIndxm2 != OrAng )
            {
                /* cut before HorHeeb */
                return(TempIndxm2);
            }
            break;
        case ShoreChang:
            if (*TempIndxm2 != WoreWaan && *TempIndxm2 != KoreKwai)
            {
                /* cut before ShoreChang */
                return(TempIndxm2);
            }
            break;
        case ThorToong:
            if(*TempIndxm2 != SoreSeo)
            {
                /* cut before ThorToong */
                return(TempIndxm2);
            }
            break;
        case NoreNane:
            /* uncut before norenane */
            break;
        case ToreTong:
            if(!(nstrcmp("ÊØ·¸Ô", TempIndxm4)))
            {
                /* if found cut after saraIe */
                return(TempIndx);
            }
            if(*TempIndxm2 != OrAng)
            {
                /* cut before ToreTong */
                return(TempIndxm2);
            }
            /* uncut before ToreTong */
            break;
        case PoreSumpao:
            if (*TempIndxm2 != OrAng)
            {
                /* cut before PoreSumpao */
                return(TempIndxm2);
            }
            break;
        case SoreSeo:
            if (!(nstrcmp("¡ÊÔ¡Ã", TempIndxm2)))
            {
                /* cut before KoreGai */
                return(TempIndxm3);
            }
            else
            {
                /* cut before SoreSeo */
                return(TempIndxm2);
            }
        case SoreSala:
            if (*TempIndxm2 != SoreSala)
            {
                /* cut before SoreSala */
                return(TempIndxm2);
            }
            break;
        case PoreParn:
            if (*TempIndxm2 != BoreBaimai)
            {
                /* cut before PoreParn */
                return(TempIndxm2);
            }
            break;
    }

    return(FAIL);
}
