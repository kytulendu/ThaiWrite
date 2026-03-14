#include "thai.h"
#include "global.h"
#include "tctype.h"

/*------------------------------------------------------------------------
Module name  : Syl_Sep  (Syllable Separation)
Parameters   : None
Function     : Find the location of the given text to be separated
Return       : Pointer to that location (Real Right Margin)

Author       :  Tanat Chirakarn
                Subun Yenjaichon

Date Written : Friday, 6 May, 1988 8:38:18 AM
Last Update  : Wednesday, 18 May, 1988
------------------------------------------------------------------------*/

unsigned char *OAngRtn(unsigned char *TempIndx)
{
    unsigned char *TempIndxp1 = TempIndx + 1;
    unsigned char *TempIndxm1 = TempIndx - 1;
    unsigned char *TempIndxm2 = TempIndx - 2;
    unsigned char *TempIndxm3 = TempIndx - 3;
    unsigned char *TempIndxm4 = TempIndx - 4;

    switch (*(TempIndxm1))
    {
        case MAIEK:
            if (findchar(*(TempIndxm2), "¢¤§©¹»¼ÇÍ"))
            {
                if ((TempIndxp1) <= RightMargin)
                    return(TempIndxp1);
            }
            else
            {
                switch (*(TempIndxm2))              /* Check to cut behind */
                {
                    case PHOPHAN:
                    case FOFA:
                        return(TempIndx);
                    case KOKAI:
                    case HOHIP:
                        if (*(TempIndxp1) != NONU)
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case CHOCHAN:
                        if (*(TempIndxp1) != MOMA)
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case CHOCHANG:
                        if (!findchar(*(TempIndxp1), "§¹"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case FOFAN:
                        if (!findchar(*(TempIndxp1), "§¹"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case SOSUA:
                        if (!findchar(*(TempIndxp1), "§¹"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case SOSO:
                        if (!findchar(*(TempIndxp1), "§¹Á"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case THOTHAHAN:
                        if (!findchar(*(TempIndxp1), "§¹Á"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case TOTAO:
                        if (!findchar(*(TempIndxp1), "§ÁÂ"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case THOTHUNG:
                        if (!findchar(*(TempIndxp1), "§ÁÂ"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case YOYAK:
                        if (!findchar(*(TempIndxp1), "§¹ÁÂ"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case BOBAIMAI:
                        if (!findchar(*(TempIndxp1), "¹Â"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case MOMA:
                        if (!findchar(*(TempIndxp1), "§ÁÂ"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case RORUA:
                        if (!findchar(*(TempIndxp1), "§¹ÁÂ"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case LOLING:
                        if (!findchar(*(TempIndxp1), "¡§¹ÁÂ"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case HONOKHUK:
                        if (*(TempIndxp1) != NGONGU)
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    default:
                        return(FAIL);
                }

                /* Check vowel routine here */
                if (istrvwl(*(TempIndx + 2)) || isttnl(*(TempIndx + 2)))
                {
                    return(TempIndx);
                }
            }

            switch (*(TempIndxm2))                  /* Check to cut in front */
            {
                case RORUA:
                    if (findchar(*(TempIndxm3), "¡¤¾Í"))
                    {
                        return(FAIL);
                    }
                    break;                          /* Check vowel */
                case LOLING:
                    if (*(TempIndxm3) == HOHIP)
                    {
                        return(TempIndxm4);         /* cut before HoHip */
                    }
                    if (findchar(*(TempIndxm3), "¡¤»¾Í"))
                    {
                        return(FAIL);
                    }
                    break;                          /* Check vowel */
                case NONU:
                    if (*(TempIndxm3) == HOHIP)
                    {
                        return(TempIndxm4);
                    }
                    break;                          /* Check vowel */
                case YOYAK:
                    if (*(TempIndxm3) == HOHIP)
                    {
                        return(FAIL);
                    }
                    break;                          /* Check vowel */
                case MOMA:
                    if (findchar(*(TempIndxm3), "¢Ë"))
                    {
                        return(TempIndxm4);
                    }
                    break;                          /* Check vowel */
                case NGONGU:
                    if (*(TempIndxm3) == HOHIP)
                    {
                        return(TempIndxm4);
                    }
                    break;                          /* Check vowel */
            }
            return(TempIndxm3);

        case MAITHO:
            if (findchar(*(TempIndxm2), "ª´¹ÂÊ"))
            {
                if ((TempIndxp1) <= RightMargin)
                {
                    return(TempIndxp1);
                }
            }
            else
            {
                switch (*(TempIndxm2))              /* Check to cut behind */
                {
                    case RORUA:
                        if (*(TempIndxm3) != KOKAI && TempIndxp1 <= RightMargin)
                        {
                            return(TempIndxp1);
                        }
                        break;
                    case NGONGU:
                    case CHOCHING:
                    case HONOKHUK:
                        return(TempIndx);
                    case KOKAI:
                    case CHOCHAN:
                        if (!findchar(*(TempIndxp1), "§¹Â"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case KHOKHAI:
                        if (!findchar(*(TempIndxp1), "§Â"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case KHOKHWAI:
                        if (*(TempIndxp1) != NONU)
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case SOSO:
                    case POPLA:
                        if (!findchar(*(TempIndxp1), "§¹Á"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case TOTAO:
                        if (!findchar(*(TempIndxp1), "§¹ÁÂ"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case THOTHAHAN:
                    case FOFAN:
                        if (!findchar(*(TempIndxp1), "§¹"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case BOBAIMAI:
                        if (!findchar(*(TempIndxp1), "§Á"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case PHOPHAN:
                        if (*(TempIndxp1) != NGONGU)
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case LOLING:
                        if (!(findchar(*(TempIndxp1), "§Â¹Á")))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case HOHIP:
                        if (!findchar(*(TempIndxp1), "§ÁÂ"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                    case OANG:
                        if (!findchar(*(TempIndxp1), "¹ÁÂ"))
                        {
                            return(TempIndx);
                        }
                        break;                      /* Check vowel */
                }
                /* Check vowel routine here */
                if (istrvwl(*(TempIndx + 2)) || isttnl(*(TempIndx + 2)))
                {
                    return(TempIndx);
                }
            }
            switch (*(TempIndxm2))                  /* Check to cut in front */
            {
                case RORUA:
                    if (findchar(*(TempIndxm3), "¡¾Ê"))
                    {
                        return(FAIL);
                    }
                    break;                          /* Check vowel */
                case LOLING:
                    if (*(TempIndxm3) == KOKAI)
                    {
                        return(FAIL);
                    }
                    if (findchar(*(TempIndxm3), "¤»Ê"))
                    {
                        if (TempIndxp1 <= RightMargin)
                        {
                            return(TempIndxp1);
                        }
                    }
                    break;                          /* Check vowel */
                case YOYAK:
                    if (*(TempIndxm3) == KHOKHAI)
                    {
                        return(TempIndxm4);
                    }
                    break;                          /* Check vowel */
                case MOMA:
                    if (findchar(*(TempIndxm3), "ªË"))
                    {
                        return(TempIndxm4);
                    }
                    break;                          /* Check vowel */
            }
            return(TempIndxm3);

        case MAITAIKHU:
        {
            if ((TempIndxp1) <= RightMargin)
            {
                return(TempIndxp1);
            }
        }

        default:
        {
            if(!istcon(*(TempIndxm1)))
            {
                return(FAIL);
            }
            else
            {
                switch(*(TempIndxm2))
                {
                    case SARA_AE:
                    case SARA_O:
                    case MAIMUAN:
                    case MAIMALAI:
                        return(TempIndxm1);
                    case SARA_E:
                        Indx = TempIndxm2;
                        return((*FuncPtr[*Indx])(Indx));
                }

                if (istcon(*TempIndxm2))
                {
                    switch(*TempIndxm1)
                    {
                        case KHOKHAI:
                        case SOSO:
                        case FOFAN:
                            return((*TempIndxm2 != OANG) ? TempIndxm2 : FAIL);
                        case OANG:
                            if (findchar(*TempIndxp1, "¡¹¿ÁÊ"))
                            {
                                return(FAIL);
                            }
                            else
                            {
                                return((*TempIndxm2 == LOLING) ? FAIL: TempIndxm1);
                            }
                        default:
                            return(FAIL);
                    }
                }
            }
        }
    }
    return(FAIL);
}
