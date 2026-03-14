#include "TCtype.h"
#include "Thai.h"
#include "Global.h"

/*  -------------SARA Ie Rtn ------------
    Programmer : Subun Yenjaichon
    Date written : Tuesday, 17 May, 1988 2:53:20 PM
    Last Updated :  Monday, 23 May, 1988
    ----------------------------------  */

unsigned char *Sara_IRtn(unsigned char *TempIndx)
{
    short i;
    unsigned char *TempIndxm1 = TempIndx - 1;
    unsigned char *TempIndxm2 = TempIndx - 2;
    unsigned char *TempIndxm3 = TempIndx - 3;
    unsigned char *TempIndxm4 = TempIndx - 4;
    unsigned char *TempIndxp1 = TempIndx + 1;
    unsigned char *TempIndxp2 = TempIndx + 2;
    static unsigned char *DoDekSara_IEx[] = {"¾ÃÃ´Ô","ÇÃÃ´Ô"};
    static unsigned char *ToTaoSara_IEx[] = {"ÇÑµÔ","ºÑµÔ","­ÑµÔ","¹ÔµÔ",
                    "ÂØµÔ","ÊÙµÔ","ªÒµÔ","­ÒµÔ","âªµÔ"};
    static unsigned char *ChoChanSara_IEx[] = {"ÊÙ¨Ô","ÊØ¨Ô"};

    /* start  check Sara E before */
    if (*TempIndxm3 == SARA_E)
    {
        if (isttnl(*TempIndxp1) && TempIndxp2 <= RightMargin)
        {
            /* cut after speller */
            return(TempIndxp2);
        }
        else
        {   Indx = TempIndxm3;
            /* Jmp to Sara_ERtn */
            return((*FuncPtr[*Indx])(Indx));
        }
    }
    else
    {
        if (*TempIndxm2 == SARA_E)
        {
            if(isttnl(*TempIndxp1))
            {
                return((TempIndxp2 <=  RightMargin)?  TempIndxp2 : TempIndxm3);
            }
            return((TempIndxp1<= RightMargin)? TempIndxp1 : TempIndxm3);
        }
    }

    /* begin Sara_IRtn without Sara E before */
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
        case KHOKHAI:
            if (*TempIndxm1 != LOLING)
            {
                return(TempIndx);
            }
            break;
        case KHOKHWAI:
            if (!(findchar(*TempIndxm1,"¹»¿ÃÅÊ")))
            {
                return(TempIndx);
            }
            break;
        case CHOCHAN:
            if (!(findchar(*TempIndxm1,"¡¹ÁÍ")))
            {
                return(TempIndx);
            }
            break;
        case SOSO:
            if (*TempIndxm1 != MOMA)
            {
                return(TempIndx);
            }
            break;
        case YOYING:
            if (!(findchar(*TempIndxm1,"¯ÀÃÇÊ")))
            {
                return(TempIndx);
            }
            break;
        case THOTHAN:
            if (*TempIndxm1 != OANG)
            {
                return(TempIndx);
            }
            break;
        case NONEN:
            if (!(findchar(*TempIndxm1,"µ¾É")))
            {
                return(TempIndx);
            }
            break;
        case THOTHAHAN:
            if (!(findchar(*TempIndxm1,"¹¾ÅÇÊÍ")))
            {
                return(TempIndx);
            }
            break;
        case THOTHONG:
            if(*TempIndxm1 != PHOPHAN)
            {
                return(TempIndx);
            }
            break;
        case PHOPHAN:
            if(!(findchar(*TempIndxm1,"ª·¹Å")))
            {
                return(TempIndx);
            }
            break;
        case FOFAN:
            if(!(findchar(*TempIndxm1,"¡Å")))
            {
                return(TempIndx);
            }
            break;
        case LOLING:
            if(!(findchar(*TempIndxm1,"«¹º¿ÁÃÇÈ")))
            {
                return(TempIndx);
            }
            break;
        case SOSALA:
            if (!(findchar(*TempIndxm1,"·¾ÃÅÇÍ")))
            {
                return(TempIndx);
            }
        case SORUSI:
            if(!(findchar(*TempIndxm1,"¸¹¾ÃÇÈ")))
            {
                return(TempIndx);
            }
            break;
        case SOSUA:
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
        case CHOCHAN:
            for(i = 0; i <= 1; ++i)
            {
                if (!(nstrcmp(ChoChanSara_IEx[i], TempIndxm3)))
                {
                    return(TempIndx);
                }
            }
            /* cut before ChoChan */
            return(TempIndxm2);
        case DODEK:
            for (i = 0; i <= 1; ++i)
            {
                if (!(nstrcmp(DoDekSara_IEx[i], TempIndxm4)))
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
        case TOTAO:
            for (i = 0; i <= 8; ++i)
            {
                if (!(nstrcmp(ToTaoSara_IEx[i], TempIndxm3)))
                {
                    return(TempIndx);
                }
            }
            if (!(findchar(*TempIndxm2, "¡¤¹ÃÄÊ")))
            {
                /* cut before ToTao */
                return(TempIndxm2);
            }
            break;
        case THOPHUTHAO:
            /* can't cut before ThoPhuThao */
            break;
        case NONU:
            if (!(findchar(*TempIndxm2, "¢ª¶ÃÇÊËÍ")))
            {
                /* cut before NoNu */
                return(TempIndxm2);
            }
            break;
        case RORUA:
            if(!(findchar(*TempIndxm2, "¡¢¤¨µ¹º»¼¾ÀËÍ")))
            {
                /* cut before RoRua */
                return(TempIndxm2);
            }
            break;
        case NGONGU:
            if (*TempIndxm2 != HOHIP)
            {
                /* cut before NgoNgu */
                return(TempIndxm2);
            }
            else
            {
                /* cut before HoHip */
                return(TempIndxm3);
            }
        case MOMA:
            if (!(nstrcmp("ÀÙÁÔ", TempIndxm3)))
            {
                /* cut after Sara I */
                return(TempIndx);
            }
            if (!(findchar(*TempIndxm2, "¢·ÊËÍ")))
            {
                /* cut before MoMa */
                return(TempIndxm2);
            }
            break;
        case YOYAK:
            if (!(findchar(*TempIndxm2, "¢ÊË")))
            {
                /* cut before YOYAK */
                return(TempIndxm2);
            }
            break;
        case WOWAEN:
            if(!(findchar(*TempIndxm2, "¢¤¶·ÃÊËÍ")))
            {
                /* cut before WoWaen */
                return(TempIndxm2);
            }
            break;
        case LOLING:
            if (!(findchar(*TempIndxm2, "¡¢ªµ»¼¾ÅÇÊËÍ")))
            {
                /* cut before LoLing */
                return(TempIndxm2);
            }
            break;
        case HOHIP:
            if (*TempIndxm2 != OANG )
            {
                /* cut before HoHip */
                return(TempIndxm2);
            }
            break;
        case CHOCHANG:
            if (*TempIndxm2 != WOWAEN && *TempIndxm2 != KHOKHWAI)
            {
                /* cut before ChoChang */
                return(TempIndxm2);
            }
            break;
        case THOTHUNG:
            if(*TempIndxm2 != SOSUA)
            {
                /* cut before ThoThung */
                return(TempIndxm2);
            }
            break;
        case NONEN:
            /* uncut before NoNen */
            break;
        case THOTHONG:
            if(!(nstrcmp("ÊØ·¸Ô", TempIndxm4)))
            {
                /* if found cut after Sara I */
                return(TempIndx);
            }
            if(*TempIndxm2 != OANG)
            {
                /* cut before ThoThong */
                return(TempIndxm2);
            }
            /* uncut before ThoThong */
            break;
        case PHOSAMPHAO:
            if (*TempIndxm2 != OANG)
            {
                /* cut before PhoSamPhao */
                return(TempIndxm2);
            }
            break;
        case SOSUA:
            if (!(nstrcmp("¡ÊÔ¡Ã", TempIndxm2)))
            {
                /* cut before KoKai */
                return(TempIndxm3);
            }
            else
            {
                /* cut before SOSUA */
                return(TempIndxm2);
            }
        case SOSALA:
            if (*TempIndxm2 != SOSALA)
            {
                /* cut before SoSaLa */
                return(TempIndxm2);
            }
            break;
        case PHOPHAN:
            if (*TempIndxm2 != BOBAIMAI)
            {
                /* cut before PhoPhan */
                return(TempIndxm2);
            }
            break;
    }

    return(FAIL);
}
