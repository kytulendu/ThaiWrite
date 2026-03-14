#include "TCtype.h"
#include "Thai.h"
#include "Global.h"
#include "Routine.h"

/*  -------------SARA AR Rtn ------------
    Programmer : Subun Yenjaichon
    Date written : Monday, 9 May, 1988 3:09:08 PM
    Last Updated : Friday, 20 May, 1988 12:01:14 PM
    ----------------------------------  */

unsigned char *Sara_AaWithoutTnl(register unsigned char *TempIndx);
unsigned char *Sara_AaWithMaiTri(register unsigned char *TempIndx);
unsigned char *Sara_AaWithTonal(register unsigned char *TempIndx);

unsigned char *Sara_AaRtn(register unsigned char *TempIndx)
 {
    register unsigned char *TempIndxm3 = TempIndx -3; /* for return point before A-2 */
    register unsigned char *charPtr;
    unsigned char chbufm1 = *(TempIndx - 1);
    unsigned char chbufm3 = *TempIndxm3;

    if (istcon(chbufm1))
    {
        if (*(TempIndx - 2) == SARA_E)
        {
            /* After this comment is   à_Ò */
            switch (*(TempIndx +1))
            {
                case SARA_A: /* à_ÒÐ */
                    if ((TempIndx + 1) <=  RightMargin)
                    {
                        if (*(TempIndx -1)  ==  THONANGMONTHO) /* à±ÒÐ */
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
                case RORUA:
                    if (chbufm1== SOSUA || chbufm1 == KHOKHWAI)  /* àÊÒÃì, à¤ÒÃ¾*/
                    {
                        /* cut before a-2  (/à_Ò) */
                        return(TempIndxm3);
                    }
                    else
                    {
                        /* cut after a */
                        return(TempIndx);
                    }
                case NONU:
                    if (chbufm1 == KHOKHWAI || chbufm1 == POPLA)   /* à¤Ò¹ì,à»Ò¹ì*/
                    {
                        /* cut before a-2 */
                        return(TempIndxm3);
                    }
                    else
                    {
                        /* cut after a */
                        return(TempIndx);
                    }
                case WOWAEN:
                    if (chbufm1 == SOSUA || chbufm1 == CHOCHANG || chbufm1 == YOYAK)
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
        else /* isn't Sara E */
        {
            if (chbufm3 == SARA_E)
            {
                Indx = TempIndxm3;
                /* Jmp to Sara_ERtn */
                return((*FuncPtr[*Indx])(Indx));
            }
            else
            {
                return(Sara_AaWithoutTnl(TempIndx));
            }
        }
    }
    /* Sara ArRtn without tonal mark section */
    else
    {
        switch (chbufm1)
        {
            case MAITRI:
                if (*(TempIndx - 3)== SARA_E)
                {
                    if(*(TempIndx + 1) == SARA_A && TempIndx + 1 <= RightMargin)
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
                    return(Sara_AaWithMaiTri(TempIndx));
                }
            case MAIEK :
            case MAITHO :
            case MAICHATTAWA :
                if (*(TempIndx - 3) == SARA_E)
                {
                    /* cut after a */
                    return(TempIndx);
                }
                else if (*(TempIndx - 4) == SARA_E)
                {
                    Indx = TempIndx - 4;
                    /* Jmp to Sara A Rtn */
                    return((*FuncPtr[*Indx])(Indx));
                }
                else
                {
                    return(Sara_AaWithTonal(TempIndx));
                }
            default:
                return(NULL);
        }
    }
}

/* SARA AR Without Tonal mark Rtn
    Date Written : Monday, 9 May, 1988 3:16:47 PM */

unsigned char *Sara_AaWithoutTnl(register unsigned char *TempIndx)
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
            case PHOPHAN:
                if (findchar(chbufm1, "¡ÀÃ") == 0)  /* ÀÒ¾ */
                {
                    /* cut after a */
                    return(TempIndx);
                }
                break;
            case KHOKHWAI:
                if (findchar(chbufm1, "¹ÀÃÍ")== 0)  /* ÀÒ¤ */
                {
                    return(TempIndx);
                }
                break;
            case POPLA:
                if (findchar(chbufm1, "¤¬´ºÉÊ") == 0) /* ¤Ò» */
                {
                    return(TempIndx);
                }
                break;
            case SOSUA:
                if (findchar(chbufm1, "¡¤¾ÁÅÇÈÊÍ") == 0) /* ÇÒÊ */
                {
                    return(TempIndx);
                }
                break;
            case KHORAKHANG:
                if (chbufm1 != MOMA)             /* ÁÒ¦ */
                {
                    return(TempIndx);
                }
                break;
            case CHOCHAN:
                if (findchar(chbufm1, "¡¹Í") == 0)  /* ¡Ò¨ */
                {
                    return(TempIndx);
                }
                break;
            case CHOCHANG:
                if (chbufm1 != RORUA && chbufm1 != OANG) /* ÍÒª­Ò */
                {
                    return(TempIndx);
                }
                break;
            case YOYING:
                /* this mean if not found do (same as 'if (findchar(chbufm1, "¡ÃÅÇË") == 0) */
                if (!(findchar(chbufm1, "¡ÃÅÇË")))  /* ¡Ò­¨¹ */
                {
                    return(TempIndx);
                }
                break;
            case NONEN:
                if (chbufm1 != YOYING && chbufm1 != MOMA) /* ­Ò³*/
                    return(TempIndx);
                break;
            case THOTHUNG:
                if (chbufm1 != NONU)             /* ¹Ò¶ */
                {
                    return(TempIndx);
                }
                break;
            case THOTHONG:
                if (chbufm1 != YOYAK && chbufm1 != PHOPHAN) /* ¾Ò¸ */
                {
                    return(TempIndx);
                }
                break;
            case THOTHAHAN:
                if (!(findchar(chbufm1, "¹º¾ÁÇÊ"))) /* ÇÒ· */
                {
                    return(TempIndx);
                }
                break;
            case FOFAN:
                if (chbufm1 != RORUA && chbufm1 != LOLING) /* ¡ÃÒ¿ */
                {
                    return(TempIndx);
                }
                break;
            case PHOSAMPHAO:
                if (chbufm1 != LOLING)            /* ÅÒÀ */
                {
                    return(TempIndx);
                }
                break;
            case SOSALA:
                if (!(findchar(chbufm1, "¡Ã¹ºÈ")))  /* ÍÒ¡ÒÈ */
                {
                    return(TempIndx);
                }
                break;
            case SORUSI:
                if (chbufm1 != DODEK && chbufm1 != PHOSAMPHAO) /* ´ÒÉ´Ò */
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
        if (*TempIndxm2 == HOHIP && findchar(chbufm1, "¹ÁÂÃÅÇ"))
        {
            /* cut before HoHip */
            return(TempIndxm3);
        }
        switch (chbufm1)
        {
            case KOKAI:
                if (chbufm2 != PHOPHUNG && chbufm2 != SOSUA) /* ¼¡Ò */
                {
                    /* cut before a-1 */
                    return(TempIndxm2);
                }
                break;
            case NGONGU:
                if (findchar(chbufp1, "´¹ºÁÂ"))
                {
                    if (chbufm2 != PHOPHUNG && chbufm1 != HOHIP)
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
            case CHOCHAN:
                if (!(chbufm2 == KHOKHAI && chbufp1 == YOYAK)) /*  ¢¨ÒÂ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                else
                {
                    /* cut before KhoKhai */
                    return(TempIndx - 3);
                }
            case POPLA:
                if (chbufm2  != SOSUA)            /* Ê»ÒÂ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case NONEN:
                if (chbufm2 != POPLA)             /* »³ÒÁ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                else if (chbufp1 != MOMA)
                {
                    return(TempIndx);
                }
                break;
            case NONU:
                if (!(findchar(chbufm2, "¢©·¸¾ÇÊËÍ"))) /* ¢¹Ò¹ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case SOSUA:
                if (chbufm2 != SOSUA || chbufp1 !=  RORUA ) /* ÊÊÒÃ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case RORUA:
                if (!(findchar(chbufm2, "¡¢¤¦¨ªµ·¹º»¾¿ÈÊË"))) /* ¡ÃÒÂ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case MOMA:
                if (!(findchar(chbufm2, "¢ªÉÊË")))  /* ÊÁÒ¤Á */
                {
                    /* cut before a-1 */
                    return(TempIndxm2);
                }
                break;
            case YOYAK:
                if (!(findchar(chbufm2, "¢ª¾ÊËÍ"))) /* ¢ÂÒÂ */
                {
                    /* cut before a-1 */
                    return(TempIndxm2);
                }
                break;
            case WOWAEN:
                if (!(findchar(chbufm2, "¡¢¤¨ªµ¶·¼ÀÊË"))) /* ¡ÇÒ§ */
                {
                    /* cut before a-1 */
                    return(TempIndxm2);
                }
                break;
            case LOLING:
                if (!(findchar(chbufm2, "¡¢¨©ª´µ¶·»¼¾¿ÁÊËÍ"))) /* ¡ÅÒ§ */
                {
                    /* cut before a-1 */
                    return(TempIndxm2);
                }
                break;
            case THOTHAHAN:
                if (chbufm2 != POPLA && chbufm2 !=  KOKAI && chbufm2 != KHOKHWAI) /* ¡·Ò */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case TOTAO:
                if (chbufm2 != SOSUA && chbufm2 != KOKAI) /* ÊµÒ§¤ì */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case HOHIP:
                if (chbufm2 != MOMA && chbufm2 != SOSUA && chbufm2 != THOTHAHAN) /* ËÁÒÂ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case BOBAIMAI:
                if (chbufm2 != SOSUA && chbufm2 != CHOCHANG) /* ÊºÒÂ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case PHOPHAN:
                if (chbufm2 != SOSUA)             /* Ê¾Ò¹ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case THOTHUNG:
                if (chbufm2 != SOSUA && chbufm2 != TOTAO) /*  µ¶Ò */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case PHOSAMPHAO:
                if (chbufm2 != SOSUA && chbufm2 != NONU) /* ¹ÀÒ */
                {
                    /* cut before a-1 */
                    return (TempIndxm2);
                }
                break;
            case DOCHADA:
                if (chbufm2 != CHOCHANG)          /* ª®Ò */
                {
                    /* cut before a-1 */
                    return(TempIndxm2);
                }
                break;
        }
    }

    return (NULL);
}

unsigned char *Sara_AaWithMaiTri(register unsigned char *TempIndx)
{
    unsigned char chbufm2 = *(TempIndx - 2);
    register unsigned char *TempIndxm3 = TempIndx - 3;
    /* _êÒ Rtn */
    if (chbufm2 != RORUA && chbufm2 != WOWAEN)  /* ¡ÃêÒ¿ ¡ÇêÒ¹ */
    {
        return(TempIndxm3);
    }
    return(NULL);
}

unsigned char *Sara_AaWithTonal(register unsigned char *TempIndx)
{
    register unsigned char *TempIndxm2 = TempIndx - 2; /* for return point before A-1 */
    register unsigned char *TempIndxm4 = TempIndx - 4;
    unsigned char chbufm1 = *(TempIndx - 1);
    unsigned char chbufp1 = *(TempIndx + 1);
    /* _èÒ  _éÒ  _ëÒ Rtn */

    switch (*(TempIndx - 1))
    {
        case MAIEK: /* _èÒ */
            switch (*(TempIndx - 2))
            {
                case HONOKHUK:
                case KHORAKHANG:
                        return(TempIndx);
                case KHOKHAI:
                case NGONGU:
                    if (!(findchar(chbufp1, "§¹ÁÂÇ")))  /* §èÒ§ ¢èÒ§*/
                    {
                        return (TempIndx);
                    }
                    break;
                case PHOPHAN:
                case TOTAO:
                case THOTHUNG:
                    if (findchar(chbufp1, "§¹Â"))       /* µèÒ ¶èÒ ¾èÒ */
                    {
                        return((TempIndx+1) <= RightMargin) ? TempIndx + 1 : TempIndx - 3;
                    }
                    /* cut after a+1 or before a-2 */
                    break;
                case KHOKHWAI:
                case CHOCHING:
                    if (chbufp1 != NGONGU && chbufp1 != YOYAK)
                    {
                        return(TempIndx);
                    }
                    break;
                case HOHIP:
                case YOYAK:
                    if (chbufp1 != NGONGU &&
                        chbufp1 != NONU && chbufp1 != MOMA) /*  ËèÒ§ */
                    {
                        return(TempIndx);
                    }
                    break;
                case KOKAI:
                case FOFA:
                    if (chbufp1 !=  YOYAK)            /* ½èÒÂ */
                    {
                        return(TempIndx);
                    }
                    break;
                case CHOCHAN:
                case BOBAIMAI:
                    if (chbufp1 != NGONGU &&
                        chbufp1 != YOYAK && chbufp1 != WOWAEN)  /* ºèÒÇ */
                    {
                        return (TempIndx);
                    }
                    break;
                case CHOCHANG:
                    if (chbufp1 != NGONGU)
                    {
                        return(TempIndx);
                    }
                    return;
                case SOSO:
                    if (chbufp1 != NONU)             /* «èÒ¹ */
                    {
                        return(TempIndx);
                    }
                    break;
                case DODEK:
                case PHOPHUNG:
                case OANG:
                    if (chbufp1 != NGONGU &&
                        chbufp1 != NONU && chbufp1 != WOWAEN) /* ÍèÒÇ */
                    {
                        return(TempIndx);
                    }
                    break;
                case THOTHAHAN:
                    if (chbufp1 != NONU && chbufp1 != MOMA) /* ·èÒÁ ·èÒ¹ */
                    {
                        return (TempIndx);
                    }
                    break;
                case NONU:
                case MOMA:
                    if (chbufp1 != NONU && chbufp1 != YOYAK) /* ¹èÒ¹ ÁèÒÂ */
                    {
                        return(TempIndx);
                    }
                    break;
                case POPLA:
                case WOWAEN:
                    if (!(findchar(chbufp1, "§¹ÂÇ")))   /*  »èÒÇ ÇèÒ¹*/
                    {
                        return(TempIndx);
                    }
                    break;
                case RORUA:
                    if (!(findchar(chbufp1, "§¹ÁÂ")))   /* ÃèÒ¹ */
                    {
                        return(TempIndx);
                    }
                    break;
                case LOLING:
                    if (chbufp1 != NGONGU &&
                        chbufp1 != MOMA && chbufp1 !=WOWAEN) /* ËÅèÒÇ ÅèÒÁ */
                    {
                        return(TempIndx);
                    }
                    break;
                case SOSUA:
                    if (chbufp1 != NGONGU &&
                        chbufp1 != NONU && chbufp1 != YOYAK) /* ÊèÒ¹ */
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
        case MAITHO:   /*  _éÒ */
        {
            switch (*(TempIndx - 2))
            {
                case YOYING:
                case THOTHUNG:
                case FOFAN:
                caseHONOKHUK:
                    return(TempIndx);
                case DODEK:
                case RORUA:
                    if (!(findchar(chbufp1, "§¹ÁÂÇ")))
                    {
                        return(TempIndx);
                    }
                    break;
                case KOKAI:
                    if (!(findchar(chbufp1, "§¹ÁÇ")))   /* ¡éÒÇ */
                    {
                        return (TempIndx);
                    }
                    break;
                case MOMA:
                case LOLING:
                    if (!(findchar(chbufp1, "§¹ÁÂ")))   /* ËÁéÒÂ */
                    {
                        return(TempIndx);
                    }
                    break;
                case KHOKHAI:
                    if (!(findchar(chbufp1, "§¹¾ÁÇ")))
                    {
                        return(TempIndx);
                    }
                    break;
                case HOHIP:
                    if (chbufp1 != NGONGU &&
                        chbufp1 != MOMA && chbufp1 != WOWAEN) /* ËéÒÁ */
                    {
                        return(TempIndx);
                    }
                    break;
                case KHOKHWAI:
                    if (chbufp1 != NONU && chbufp1 != NGONGU) /* ¤éÒ§ */
                    {
                        return(TempIndx);
                    }
                    break;
                case NGONGU:
                    if (chbufp1 != NGONGU && chbufp1 != WOWAEN) /* §éÒÇ */
                    {
                        return(TempIndx);
                    }
                    break;
                case CHOCHAN:
                    if (chbufp1 != NGONGU &&
                        chbufp1 != WOWAEN && chbufp1 != NONU) /* ¨éÒ§ */
                    {
                        return(TempIndx);
                    }
                    break;
                case CHOCHANG:
                    if (chbufp1 != NGONGU)            /* ªéÒ§ */
                    {
                        return (TempIndx);
                    }
                    break;
                case SOSO:
                case PHOPHUNG:
                case FOFA:
                case YOYAK:
                    if (chbufp1 != YOYAK)             /* ÂéÒÂ */
                    {
                        return(TempIndx);
                    }
                    break;
                case TOTAO:
                    if (chbufp1 != YOYAK && chbufp1 != NONU) /* µéÒ¹ */
                    {
                        return(TempIndx);
                    }
                    break;
                case THOTHAHAN:
                    if (chbufp1 !=  YOYAK &&
                        chbufp1 != NGONGU && chbufp1 != WOWAEN) /* ·éÒÇ */
                    {
                        return(TempIndx);
                    }
                    break;
                case NONU:
                    if (chbufp1 !=  WOWAEN)           /* ¹éÒÇ */
                    {
                        return(TempIndx);
                    }
                    break;
                case BOBAIMAI:
                case POPLA:
                case WOWAEN:
                    if (chbufp1 !=  YOYAK && chbufp1 != NGONGU &&
                        chbufp1 != NONU )            /* ÇéÒÂ */
                    {
                        return(TempIndx);
                    }
                    break;
                case OANG:
                    if (chbufp1 !=  YOYAK && chbufp1 != NGONGU) /* ÍéÒ§ */
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
        case MAICHATTAWA:    /*  _ëÒ */
            return(TempIndx);
    }
    if (*(TempIndx - 3) == HOHIP && findchar(*TempIndxm2, "¹ÁÂÃÅÇ"))
    {
        /* cut before HoHip */
        return(TempIndxm4);
    }
    return(NULL);
}
