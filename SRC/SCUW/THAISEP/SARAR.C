#include "TCtype.h"
#include "Thai.h"
#include "Global.h"
#include "Routine.h"

/*  -------------SARA AR Rtn ------------
    Programmer : Subun Yenjaichon
    Date written : Monday, 9 May, 1988 3:09:08 PM
    Last Updated : Friday, 20 May, 1988 12:01:14 PM
    ----------------------------------  */

unsigned char *SaraRRtn(register unsigned char *TempIndx)
 {
    register unsigned char *TempIndxm3 = TempIndx -3; /* for return point before A-2 */
    register unsigned char *charPtr;
    unsigned char chbufm1 = *(TempIndx - 1);
    unsigned char chbufm3 = *TempIndxm3;

    if (istcon(chbufm1))
    {
        if (*(TempIndx - 2) == SaraA)
        {
            /* After this comment is   à_Ò */
            switch (*(TempIndx +1))
            {
                case SaraAh: /* à_ÒÐ */
                    if ((TempIndx + 1) <=  RightMargin)
                    {
                        if (*(TempIndx -1)  ==  ToreMontoe) /* à±ÒÐ */
                        {
                            /* cut before a-2 */
                            return(TempIndxm3);
                        }
                        else
                        {
                            /*cut after a+1*/
                            return (TempIndx + 1);
                        }
                    }
                    else
                    {
                        /* cut before a-2*/
                        return(TempIndxm3);
                    }
                case RoreReo:
                    if (chbufm1== SoreSeo || chbufm1 == KoreKwai)  /* àÊÒÃì, à¤ÒÃ¾*/
                    {
                        /* cut before a-2  (/à_Ò) */
                        return(TempIndxm3);
                    }
                    else
                    {
                        /* cut after a */
                        return(TempIndx);
                    }
                case NoreNoo:
                    if (chbufm1 == KoreKwai || chbufm1 == PorePla)   /* à¤Ò¹ì,à»Ò¹ì*/
                    {
                        /* cut before a-2 */
                        return(TempIndxm3);
                    }
                    else
                    {
                        /* cut after a */
                        return(TempIndx);
                    }
                case WoreWaan:
                    if (chbufm1 == SoreSeo || chbufm1 == ShoreChang || chbufm1 == YoreYak)
                    {
                        /* cut before a-2 */
                        return(TempIndxm3);
                    }
                    else
                    {
                        /* cut after a */
                        return(TempIndx);
                    }
                default:
                    /* cut after a (à_Ò/) */
                    return(TempIndx);
            }
        }
        else /* isn't SaraA */
        {
            if (chbufm3 == SaraA)
            {
                Indx = TempIndxm3;
                /* Jmp to SaraARtn */
                return((*FuncPtr[*Indx])(Indx));
            }
            else
            {
                return(SaraRWithoutTnl(TempIndx));
            }
        }
    }
    /* Sara ArRtn without tonal mark section */
    else
    {
        switch (chbufm1)
        {
            case MaiTri:
                if (*(TempIndx - 3)== SaraA)
                {
                    if(*(TempIndx + 1) == SaraAh && TempIndx + 1 <= RightMargin)
                    {
                        /*cut after a+1*/
                        return(TempIndx + 1);
                    }
                    else
                    {
                        return(TempIndx - 4);
                    }
                }
                else
                {
                    return(SaraRWithMaiTri(TempIndx));
                }
            case MaiEk :
            case MaiToe :
            case MaiJattawa :
                if (*(TempIndx - 3) == SaraA)
                {
                    /* cut after a */
                    return(TempIndx);
                }
                else if (*(TempIndx - 4) == SaraA)
                {
                    Indx = TempIndx - 4;
                    /* Jmp to Sara A Rtn */
                    return((*FuncPtr[*Indx])(Indx));
                }
                else
                {
                    return(SaraRWithTonal(TempIndx));
                }
            default:
                return(NULL);
        }
    }
}

/* SARA AR Without Tonal mark Rtn
    Date Written : Monday, 9 May, 1988 3:16:47 PM */

unsigned char *SaraRWithoutTnl(register unsigned char *TempIndx)
{
    register unsigned char *TempIndxm2 = TempIndx - 2;  /* for return point before A-1 */
    register unsigned char *TempIndxm3 = TempIndx - 3;  /* for return point before A-2 */
    unsigned char chbufp1 = *(TempIndx + 1);
    unsigned char chbufm1 = *(TempIndx - 1);
    unsigned char chbufm2 = *TempIndxm2;

    if (findchar(chbufp1, "¢«¬®°±²Í" ) || istlcon(chbufp1))
    {
        return(TempIndx);
    }
    else
    {
        switch (chbufp1)
        {
            case PoreParn:
                if (findchar(chbufm1, "¡ÀÃ") == 0)  /* ÀÒ¾ */
                {
                    /* cut after a */
                    return(TempIndx);
                }
                break;
            case KoreKwai:
                if (findchar(chbufm1, "¹ÀÃÍ")== 0)  /* ÀÒ¤ */
                {
                    return(TempIndx);
                }
                break;
            case PorePla:
                if (findchar(chbufm1, "¤¬´ºÉÊ") == 0) /* ¤Ò» */
                {
                    return(TempIndx);
                }
                break;
            case SoreSeo:
                if (findchar(chbufm1, "¡¤¾ÁÅÇÈÊÍ") == 0) /* ÇÒÊ */
                {
                    return(TempIndx);
                }
                break;
            case KoreRakung:
                if (chbufm1 != MoreMar)             /* ÁÒ¦ */
                {
                    return(TempIndx);
                }
                break;
            case JoreJarn:
                if (findchar(chbufm1, "¡¹Í") == 0)  /* ¡Ò¨ */
                {
                    return(TempIndx);
                }
                break;
            case ShoreChang:
                if (chbufm1 != RoreReo && chbufm1 != OrAng) /* ÍÒª­Ò */
                {
                    return(TempIndx);
                }
                break;
            case YoreYing:
                /* this mean if not found do (same as 'if (findchar(chbufm1, "¡ÃÅÇË") == 0) */
                if (!(findchar(chbufm1, "¡ÃÅÇË")))  /* ¡Ò­¨¹ */
                {
                    return(TempIndx);
                }
                break;
            case NoreNane:
                if (chbufm1 != YoreYing && chbufm1 != MoreMar) /* ­Ò³*/
                    return(TempIndx);
                break;
            case ThorToong:
                if (chbufm1 != NoreNoo)             /* ¹Ò¶ */
                {
                    return(TempIndx);
                }
                break;
            case ToreTong:
                if (chbufm1 != YoreYak && chbufm1 != PoreParn) /* ¾Ò¸ */
                {
                    return(TempIndx);
                }
                break;
            case ToreTaharn:
                if (!(findchar(chbufm1, "¹º¾ÁÇÊ"))) /* ÇÒ· */
                {
                    return(TempIndx);
                }
                break;
            case ForeFun:
                if (chbufm1 != RoreReo && chbufm1 != LoreLing) /* ¡ÃÒ¿ */
                {
                    return(TempIndx);
                }
                break;
            case PoreSumpao:
                if (chbufm1 != LoreLing)            /* ÅÒÀ */
                {
                    return(TempIndx);
                }
                break;
            case SoreSala:
                if (!(findchar(chbufm1, "¡Ã¹ºÈ")))  /* ÍÒ¡ÒÈ */
                {
                    return(TempIndx);
                }
                break;
            case SoreRusi:
                if (chbufm1 != DoreDek && chbufm1 != PoreSumpao) /* ´ÒÉ´Ò */
                {
                    return(TempIndx);
                }
                break;
        }
    }

    /* Front Cut Section */
    if (findchar(chbufm1, "¢¤¦­ª«¯°±²³´¸¿ÈÌÍ") || istlcon(chbufm1))
    {
        /* cut before A-1 */
        return(TempIndxm2);
    }
    else
    {
        if (*TempIndxm2 == HorHeeb && findchar(chbufm1, "¹ÁÂÃÅÇ"))
        {
            /* cut before HorHeeb */
            return(TempIndxm3);
        }
        switch (chbufm1)
        {
            case KoreGai:
                if (chbufm2 != PorPeng && chbufm2 != SoreSeo) /* ¼¡Ò */
                {
                    /* cut before a-1 */
                    return(TempIndxm2);
                }
                break;
            case NgorNgoo:
                if (findchar(chbufp1, "´¹ºÁÂ"))
                {
                    if (chbufm2 != PorPeng && chbufm1 != HorHeeb)
                    {
                        /* cut before a-1 */
                        return(TempIndxm2);
                    }
                }
                else
                {
                    /* cut after a */
                    return(TempIndx);
                }
                break;
            case JoreJarn:
                if (!(chbufm2 == KorKai && chbufp1 == YoreYak)) /*  ¢¨ÒÂ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                else
                {
                    /* cut before KorKai */
                    return(TempIndx - 3);
                }
            case PorePla:
                if (chbufm2  != SoreSeo)            /* Ê»ÒÂ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case NoreNane:
                if (chbufm2 != PorePla)             /* »³ÒÁ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                else if (chbufp1 != MoreMar)
                {
                    return(TempIndx);
                }
                break;
            case NoreNoo:
                if (!(findchar(chbufm2, "¢©·¸¾ÇÊËÍ"))) /* ¢¹Ò¹ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case SoreSeo:
                if (chbufm2 != SoreSeo || chbufp1 !=  RoreReo ) /* ÊÊÒÃ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case RoreReo:
                if (!(findchar(chbufm2, "¡¢¤¦¨ªµ·¹º»¾¿ÈÊË"))) /* ¡ÃÒÂ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case MoreMar:
                if (!(findchar(chbufm2, "¢ªÉÊË")))  /* ÊÁÒ¤Á */
                {
                    /* cut before a-1 */
                    return(TempIndxm2);
                }
                break;
            case YoreYak:
                if (!(findchar(chbufm2, "¢ª¾ÊËÍ"))) /* ¢ÂÒÂ */
                {
                    /* cut before a-1 */
                    return(TempIndxm2);
                }
                break;
            case WoreWaan:
                if (!(findchar(chbufm2, "¡¢¤¨ªµ¶·¼ÀÊË"))) /* ¡ÇÒ§ */
                {
                    /* cut before a-1 */
                    return(TempIndxm2);
                }
                break;
            case LoreLing:
                if (!(findchar(chbufm2, "¡¢¨©ª´µ¶·»¼¾¿ÁÊËÍ"))) /* ¡ÅÒ§ */
                {
                    /* cut before a-1 */
                    return(TempIndxm2);
                }
                break;
            case ToreTaharn:
                if (chbufm2 != PorePla && chbufm2 !=  KoreGai && chbufm2 != KoreKwai) /* ¡·Ò */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case ToreTao:
                if (chbufm2 != SoreSeo && chbufm2 != KoreGai) /* ÊµÒ§¤ì */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case HorHeeb:
                if (chbufm2 != MoreMar && chbufm2 != SoreSeo && chbufm2 != ToreTaharn) /* ËÁÒÂ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case BoreBaimai:
                if (chbufm2 != SoreSeo && chbufm2 != ShoreChang) /* ÊºÒÂ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case PoreParn:
                if (chbufm2 != SoreSeo)             /* Ê¾Ò¹ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case ThorToong:
                if (chbufm2 != SoreSeo && chbufm2 != ToreTao) /*  µ¶Ò */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case PoreSumpao:
                if (chbufm2 != SoreSeo && chbufm2 != NoreNoo) /* ¹ÀÒ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case DoreChada:
                if (chbufm2 != ShoreChang)          /* ª®Ò */
                {
                    /* cut before a-1 */
                    return(TempIndxm2);
                }
                break;
        }
    }

    return (NULL);
}

unsigned char *SaraRWithMaiTri(register unsigned char *TempIndx)
{
    unsigned char chbufm2 = *(TempIndx - 2);
    register unsigned char *TempIndxm3 = TempIndx - 3;
    /* _êÒ Rtn */
    if (chbufm2 != RoreReo && chbufm2 != WoreWaan)  /* ¡ÃêÒ¿ ¡ÇêÒ¹ */
    {
        return(TempIndxm3);
    }
    return(NULL);
}

unsigned char *SaraRWithTonal(register unsigned char *TempIndx)
{
    register unsigned char *TempIndxm2 = TempIndx - 2; /* for return point before A-1 */
    register unsigned char *TempIndxm4 = TempIndx - 4;
    unsigned char chbufm1 = *(TempIndx - 1);
    unsigned char chbufp1 = *(TempIndx + 1);
    /* _èÒ  _éÒ  _ëÒ Rtn */

    switch (*(TempIndx - 1))
    {
        case MaiEk: /* _èÒ */
            switch (*(TempIndx - 2))
            {
                case HorNokHook:
                case KoreRakung:
                        return(TempIndx);
                case KorKai:
                case NgorNgoo:
                    if (!(findchar(chbufp1, "§¹ÁÂÇ")))  /* §èÒ§ ¢èÒ§*/
                    {
                        return (TempIndx);
                    }
                    break;
                case PoreParn:
                case ToreTao:
                case ThorToong:
                    if (findchar(chbufp1, "§¹Â"))       /* µèÒ ¶èÒ ¾èÒ */
                    {
                        return((TempIndx+1) <= RightMargin) ? TempIndx + 1 : TempIndx - 3;
                    }
                    /* cut after a+1 or before a-2 */
                    break;
                case KoreKwai:
                case ChorChing:
                    if (chbufp1 != NgorNgoo && chbufp1 != YoreYak)
                    {
                        return(TempIndx);
                    }
                    break;
                case HorHeeb:
                case YoreYak:
                    if (chbufp1 != NgorNgoo &&
                        chbufp1 != NoreNoo && chbufp1 != MoreMar) /*  ËèÒ§ */
                    {
                        return(TempIndx);
                    }
                    break;
                case KoreGai:
                case ForFa:
                    if (chbufp1 !=  YoreYak)            /* ½èÒÂ */
                    {
                        return(TempIndx);
                    }
                    break;
                case JoreJarn:
                case BoreBaimai:
                    if (chbufp1 != NgorNgoo &&
                        chbufp1 != YoreYak && chbufp1 != WoreWaan)  /* ºèÒÇ */
                    {
                        return (TempIndx);
                    }
                    break;
                case ShoreChang:
                    if (chbufp1 != NgorNgoo)
                    {
                        return(TempIndx);
                    }
                    return;
                case SoreSoe:
                    if (chbufp1 != NoreNoo)             /* «èÒ¹ */
                    {
                        return(TempIndx);
                    }
                    break;
                case DoreDek:
                case PorPeng:
                case OrAng:
                    if (chbufp1 != NgorNgoo &&
                        chbufp1 != NoreNoo && chbufp1 != WoreWaan) /* ÍèÒÇ */
                    {
                        return(TempIndx);
                    }
                    break;
                case ToreTaharn:
                    if (chbufp1 != NoreNoo && chbufp1 != MoreMar) /* ·èÒÁ ·èÒ¹ */
                    {
                        return (TempIndx);
                    }
                    break;
                case NoreNoo:
                case MoreMar:
                    if (chbufp1 != NoreNoo && chbufp1 != YoreYak) /* ¹èÒ¹ ÁèÒÂ */
                    {
                        return(TempIndx);
                    }
                    break;
                case PorePla:
                case WoreWaan:
                    if (!(findchar(chbufp1, "§¹ÂÇ")))   /*  »èÒÇ ÇèÒ¹*/
                    {
                        return(TempIndx);
                    }
                    break;
                case RoreReo:
                    if (!(findchar(chbufp1, "§¹ÁÂ")))   /* ÃèÒ¹ */
                    {
                        return(TempIndx);
                    }
                    break;
                case LoreLing:
                    if (chbufp1 != NgorNgoo &&
                        chbufp1 != MoreMar && chbufp1 !=WoreWaan) /* ËÅèÒÇ ÅèÒÁ */
                    {
                        return(TempIndx);
                    }
                    break;
                case SoreSeo:
                    if (chbufp1 != NgorNgoo &&
                        chbufp1 != NoreNoo && chbufp1 != YoreYak) /* ÊèÒ¹ */
                    {
                        break;
                    }
            }
            if (findchar(*TempIndxm2, "¢¤¦­ª«´¸¿ÈËÍ") || istlcon(*TempIndxm2))
            {
                /* cut before A-2 */
                return(TempIndx - 3);
            }
            break;
        case MaiToe:   /*  _éÒ */
        {
            switch (*(TempIndx - 2))
            {
                case YoreYing:
                case ThorToong:
                case ForeFun:
                caseHorNokHook:
                    return(TempIndx);
                case DoreDek:
                case RoreReo:
                    if (!(findchar(chbufp1, "§¹ÁÂÇ")))
                    {
                        return(TempIndx);
                    }
                    break;
                case KoreGai:
                    if (!(findchar(chbufp1, "§¹ÁÇ")))   /* ¡éÒÇ */
                    {
                        return (TempIndx);
                    }
                    break;
                case MoreMar:
                case LoreLing:
                    if (!(findchar(chbufp1, "§¹ÁÂ")))   /* ËÁéÒÂ */
                    {
                        return(TempIndx);
                    }
                    break;
                case KorKai:
                    if (!(findchar(chbufp1, "§¹¾ÁÇ")))
                    {
                        return(TempIndx);
                    }
                    break;
                case HorHeeb:
                    if (chbufp1 != NgorNgoo &&
                        chbufp1 != MoreMar && chbufp1 != WoreWaan) /* ËéÒÁ */
                    {
                        return(TempIndx);
                    }
                    break;
                case KoreKwai:
                    if (chbufp1 != NoreNoo && chbufp1 != NgorNgoo) /* ¤éÒ§ */
                    {
                        return(TempIndx);
                    }
                    break;
                case NgorNgoo:
                    if (chbufp1 != NgorNgoo && chbufp1 != WoreWaan) /* §éÒÇ */
                    {
                        return(TempIndx);
                    }
                    break;
                case JoreJarn:
                    if (chbufp1 != NgorNgoo &&
                        chbufp1 != WoreWaan && chbufp1 != NoreNoo) /* ¨éÒ§ */
                    {
                        return(TempIndx);
                    }
                    break;
                case ShoreChang:
                    if (chbufp1 != NgorNgoo)            /* ªéÒ§ */
                    {
                        return (TempIndx);
                    }
                    break;
                case SoreSoe:
                case PorPeng:
                case ForFa:
                case YoreYak:
                    if (chbufp1 != YoreYak)             /* ÂéÒÂ */
                    {
                        return(TempIndx);
                    }
                    break;
                case ToreTao:
                    if (chbufp1 != YoreYak && chbufp1 != NoreNoo) /* µéÒ¹ */
                    {
                        return(TempIndx);
                    }
                    break;
                case ToreTaharn:
                    if (chbufp1 !=  YoreYak &&
                        chbufp1 != NgorNgoo && chbufp1 != WoreWaan) /* ·éÒÇ */
                    {
                        return(TempIndx);
                    }
                    break;
                case NoreNoo:
                    if (chbufp1 !=  WoreWaan)           /* ¹éÒÇ */
                    {
                        return(TempIndx);
                    }
                    break;
                case BoreBaimai:
                case PorePla:
                case WoreWaan:
                    if (chbufp1 !=  YoreYak && chbufp1 != NgorNgoo &&
                        chbufp1 != NoreNoo )            /* ÇéÒÂ */
                    {
                        return(TempIndx);
                    }
                    break;
                case OrAng:
                    if (chbufp1 !=  YoreYak && chbufp1 != NgorNgoo) /* ÍéÒ§ */
                    {
                        return(TempIndx);
                    }
                    break;
            }
            if (findchar(*TempIndxm2, "¢¤¦­ª«´¸¿ÈËÍ") || istlcon(*TempIndxm2))
            {
                /* cut before A-2 */
                return(TempIndx - 3);
            }
            break;
        }
        case MaiJattawa:    /*  _ëÒ */
            return(TempIndx);
    }
    if (*(TempIndx - 3) == HorHeeb && findchar(*TempIndxm2, "¹ÁÂÃÅÇ"))
    {
        /* cut before HorHeeb */
        return(TempIndxm4);
    }
    return(NULL);
}
