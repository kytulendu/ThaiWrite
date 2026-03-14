#include "thai.h"
#include "global.h"

/*------------------------------------------------------------------------
Module name  : Syl_Sep  (Syllable Separation)
Parameters   : None
Function     : Find the location of the given text to be separated
Return       : Pointer to that location (Real Right Margin)

Author       :  Tanat Chirakarn
                Subun Yenjaichon

Date Written : Friday, 6 May, 1988 8:38:18 AM
Last Update  : Monday, 9 May, 1988 2:19:20 PM
------------------------------------------------------------------------*/

unsigned char *CheckOther(unsigned char *TempIndx);
unsigned char *Sara_IirEkRtn(unsigned char *TempIndx);
unsigned char *Sara_IirToeRtn(unsigned char *TempIndx);
unsigned char *Sara_IirRtn(unsigned char *TempIndx);
unsigned char *Sara_EeEkRtn(unsigned char *TempIndx);
unsigned char *Sara_EeToeRtn(unsigned char *TempIndx);
unsigned char *Sara_EeTriRtn(unsigned char *TempIndx);
unsigned char *Sara_EeJatRtn(unsigned char *TempIndx);
unsigned char *Sara_EeRtn(unsigned char *TempIndx);

unsigned char *MaiTaiKhuRtn(unsigned char *TempIndx)
{
    if (*(TempIndx + 1) == OANG)
    {
        if (TempIndx + 2 <= RightMargin)
        {
            return(TempIndx + 2);
        }
        else
        {
            return(FAIL);
        }
    }
    else
    {
        if (*(TempIndx - 1) == KOKAI)
        {
            if (*(TempIndx - 2) == SARA_E || *(TempIndx - 2) == SARA_AE)
            {
                if ((TempIndx + 2) <= RightMargin)
                {
                    return(TempIndx + 2);
                }
                else
                {
                    return(TempIndx - 3);
                }
            }
            else
            {
                return(TempIndx);
            }
        }
        else
        {
            if (*(TempIndx - 2) == SARA_E || *(TempIndx - 2) == SARA_AE
              || *(TempIndx - 3) == SARA_E || *(TempIndx - 3) == SARA_AE)
            {
                if (*(TempIndx + 3) == KARAN)
                {
                    if ((TempIndx + 3) <= RightMargin)
                    {
                        return(TempIndx + 3);
                    }
                    else
                    {
                        return(TempIndx - 3);
                    }
                }
                else
                {
                    if ((TempIndx + 1) <= RightMargin)
                    {
                        return(TempIndx + 1);
                    }
                    else
                    {
                        if (*(TempIndx - 2) == SARA_E || *(TempIndx - 2) == SARA_AE)
                        {
                            return(TempIndx - 3);
                        }
                        else
                        {
                            return(TempIndx - 4);
                        }
                    }
                }
            }
            else
            {
                return(FAIL);
            }
        }
    }
}

unsigned char *Sara_UuRtn(unsigned char *TempIndx)
{
    if ((TempIndx + 1) <= EndOfText)
    {
        switch (*(TempIndx + 1))
        {
            case TOTAO:
                if (!(*(TempIndx - 1) == PHOSAMPHAO ||
                    *(TempIndx - 1) == THOTHAHAN ||
                    *(TempIndx - 1) == SOSUA))
                {
                    return(TempIndx);
                }
                break;
            case POPLA:
                if (!(*(TempIndx - 1) == RORUA ||
                    *(TempIndx - 1) == THOTHONG ||
                    *(TempIndx - 1) == THOTHUNG))
                {
                    return(TempIndx);
                }
                break;
            case KHOKHAI:
            case KHOKHWAI:
            case CHOCHAN:
            case CHOCHANG:
            case SOSO:
            case THOTHONG:
            case PHOPHAN:
            case PHOSAMPHAO:
            case YOYAK:
            case WOWAEN:
            case FOFAN:
            case SOSALA:
            case SOSUA:
            case OANG:
            case CHOCHING:
            case PHOPHUNG:
            case FOFA:
            case HONOKHUK:
                return(TempIndx);
            case MAITHO:
                if ((TempIndx + 2) <= EndOfText)
                {
                    if (!(*(TempIndx + 2) == DODEK
                        || *(TempIndx + 2) == TOTAO
                        || *(TempIndx + 2) == FOFAN))
                    {
                        if ((TempIndx + 1) <= RightMargin)
                        {
                            return(TempIndx+1);
                        }
                    }
                }
                break;
            case MAITRI:
                if ((TempIndx + 2) <= EndOfText)
                {
                    if (!(*(TempIndx + 2) == DODEK
                        || *(TempIndx + 2) == TOTAO
                        || *(TempIndx + 2) == THOTHAHAN
                        || *(TempIndx + 2) == POPLA
                        || *(TempIndx + 2) == FOFA))
                    {
                        if ((TempIndx + 1) <= RightMargin)
                        {
                            return(TempIndx + 1);
                        }
                    }
                }
                break;
            case MAIEK:
            case MAICHATTAWA:
                if ((TempIndx + 1) <= RightMargin)
                {
                    return(TempIndx + 1);
                }
                else
                {
                    return(FAIL);
                }
        }
    }
    switch (*(TempIndx - 1))
    {
        case KHOKHAI:
        case KHOKHWAI:
        case KHORAKHANG:
        case NGONGU:
        case CHOCHAN:
        case CHOCHANG:
        case SOSO:
        case CHOCHOE:
        case YOYING:
        case DOCHADA:
        case TOPATAK:
        case THONANGMONTHO:
        case THOPHUTHAO:
        case THOTHAHAN:
        case THOTHONG:
        case POPLA:
        case PHOPHAN:
        case FOFAN:
        case PHOSAMPHAO:
        case SOSALA:
        case SORUSI:
        case LOCHULA:
        case OANG:
        case CHOCHING:
        case PHOPHUNG:
        case FOFA:
        case HONOKHUK:
            return(TempIndx - 2);
        case NONU:
            if (!(*(TempIndx - 2) == MOMA
                || *(TempIndx - 2) == HOHIP
                || *(TempIndx - 2) == THOTHONG))
            {
                return(TempIndx - 2);
            }
            break;
        case RORUA:
            if (!(*(TempIndx - 2) == POPLA
                || *(TempIndx - 2) == HOHIP
                || *(TempIndx - 2) == KHOKHWAI
                || *(TempIndx - 2) == KOKAI
                || *(TempIndx - 2) == CHOCHAN
                || *(TempIndx - 2) == TOTAO
                || *(TempIndx - 2) == PHOPHAN))
            {
                return(TempIndx - 2);
            }
            break;
        case MOMA:
            if (!(*(TempIndx - 2) == HOHIP || *(TempIndx - 2) == CHOCHAN))
            {
                return(TempIndx - 2);
            }
            break;
        case YOYAK:
            if (!(*(TempIndx - 2) == OANG || *(TempIndx - 2) == HOHIP))
            {
                return(TempIndx - 2);
            }
            break;
        case WOWAEN:
            if (*(TempIndx - 2) != HOHIP)
            {
                return(TempIndx - 2);
            }
            break;
        case LOLING:
            if (!(*(TempIndx - 2) == POPLA
                || *(TempIndx - 2) == HOHIP
                || *(TempIndx - 2) == OANG
                || *(TempIndx - 2) == FOFAN
                || *(TempIndx - 2) == PHOPHAN
                || *(TempIndx - 2) == CHOCHANG
                || *(TempIndx - 2) == KOKAI
                || *(TempIndx - 2) == PHOPHUNG
                || *(TempIndx - 2) == CHOCHING))
            {
                return(TempIndx - 2);
            }
            break;
        case TOTAO:
            if (*(TempIndx - 2) != SOSUA)
            {
                return(TempIndx - 2);
            }
            break;
        case HOHIP:
            if (*(TempIndx - 2) != PHOPHAN)
            {
                return(TempIndx - 2);
            }
            break;
        case BOBAIMAI:
            if (*(TempIndx - 2) != SOSUA)
            {
                return(TempIndx - 2);
            }
            break;
        case NONEN:
            if (*(TempIndx - 2) != OANG)
            {
                return(TempIndx - 2);
            }
            break;
        case KOKAI:
            if (*(TempIndx - 2) != SOSUA)
            {
                return(TempIndx - 2);
            }
            break;
        case DODEK:
            if (*(TempIndx - 2) == RU)
            {
                return(TempIndx - 3);
            }
            else
            {
                return(TempIndx - 2);
            }
        case SOSUA:
            if (!(*(TempIndx - 2) == OANG))
            {
                return(TempIndx - 2);
            }
            break;
        case THOTHUNG:
            if (*(TempIndx - 2) != SOSUA)
            {
                return(TempIndx - 2);
            }
            break;
    }
    return(FAIL);
}

unsigned char *Sara_IiRtn(unsigned char *TempIndx)
{
    unsigned char *charPtr;

    if ((TempIndx + 1) <= EndOfText)
    {
        switch (*(TempIndx + 1))
        {
            case SOSO:
                if (*(TempIndx - 1) != RORUA)
                {
                    return(TempIndx);
                }
                break;
            case FOFAN:
                if (*(TempIndx - 1) != OANG)
                {
                    return(TempIndx);
                }
                break;
            case HOHIP:
                if (*(TempIndx - 1) != SOSUA)
                {
                    return(TempIndx);
                }
                break;
            case KHOKHWAI:
                if (!(*(TempIndx - 1) == LOLING
                    || *(TempIndx - 1) == WOWAEN))
                {
                    return(TempIndx);
                }
                break;
            case SOSUA:
                if (!(*(TempIndx - 1) == YOYAK
                    || *(TempIndx - 1) == THOTHONG
                    || *(TempIndx - 1) == OANG))
                {
                    return(TempIndx);
                }
                break;
            case CHOCHANG:
                if (*(TempIndx - 1) != PHOPHAN)
                {
                    return(TempIndx);
                }
                break;
            case LOLING:
                if (!(*(TempIndx -1) == NONU
                    || *(TempIndx - 1) == FOFAN
                    || *(TempIndx - 1) == THOTHONG
                    || *(TempIndx - 1) == SOSALA))
                {
                    return(TempIndx);
                }
                break;
            case KHORAKHANG:
                if (*(TempIndx - 1) != THOTHAHAN)
                {
                    return(TempIndx);
                }
                break;
            case WOWAEN:
            case PHOPHAN:
                if (*(TempIndx - 1) != CHOCHANG)
                {
                    return(TempIndx);
                }
                break;
            case KOKAI:
                if (!(*(TempIndx - 1) == CHOCHING
                    || *(TempIndx - 1) == SOSO
                    || *(TempIndx - 1) == POPLA
                    || *(TempIndx - 1) == OANG))
                {
                    return(TempIndx);
                }
                break;
            case MOMA:
                if (!(*(TempIndx - 1) == KHOKHWAI
                    || *(TempIndx - 1) == THOTHAHAN
                    || *(TempIndx - 1) == RORUA))
                {
                    return(TempIndx);
                }
                break;
            case TOTAO:
                if (!(*(TempIndx - 1) == KHOKHWAI
                    || *(TempIndx - 1) == NONEN
                    || *(TempIndx - 1) == RORUA))
                {
                    return(TempIndx);
                }
                break;
            case POPLA:
                if (!(*(TempIndx - 1) == KHOKHAI
                    || *(TempIndx - 1) == THOTHAHAN
                    || *(TempIndx - 1) == WOWAEN))
                {
                    return(TempIndx);
                }
                break;
            case DODEK:
                switch (*(TempIndx - 1))
                {
                    case RORUA:
                        if (!(*(TempIndx - 2) == KOKAI || *(TempIndx - 2) == HOHIP))
                        {
                            return(TempIndx - 2);
                        }
                        break;
                    case WOWAEN:
                        if (*(TempIndx - 2) != HOHIP)
                        {
                            return(TempIndx - 2);
                        }
                        break;
                }
            case NONU:
                switch (*(TempIndx - 1))
                {
                    case RORUA:
                        if (*(TempIndx - 2) != KOKAI)
                        {
                            return(TempIndx - 2);
                        }
                        break;
                }
            case RORUA:
                break;
            case YOYAK:
                charPtr = CheckOther(TempIndx);
                if (charPtr!=NULL)
                {
                    return(charPtr);
                }
                else
                {
                    switch (*(TempIndx - 1))
                    {
                        case RORUA:
                            if (!(*(TempIndx - 2) == TOTAO
                                || *(TempIndx - 2) == POPLA
                                || *(TempIndx - 2) == HOHIP))
                            {
                                return(TempIndx - 2);
                            }
                            break;
                        case NONU:
                            if (!(*(TempIndx - 1) == SOSUA))
                            {
                                return(TempIndx - 2);
                            }
                            break;
                    }
                }
                break;
            case BOBAIMAI:
                switch (*(TempIndx - 1))
                {
                    case LOLING:
                        if (*(TempIndx - 2) != KOKAI)
                        {
                            return(TempIndx - 2);
                        }
                        break;
                    case RORUA:
                        if (*(TempIndx - 2) != KHOKHWAI)
                        {
                            return(TempIndx - 2);
                        }
                        break;
                }
            case MAITRI:
                if ((TempIndx + 2) <= RightMargin)
                {
                    if (*(TempIndx + 2) != YOYAK)
                    {
                        return(FAIL);
                    }
                    else
                    {
                        return(CheckOther(TempIndx));
                    }
                }
                break;
            case MAIEK:
            case MAITHO:
            case MAICHATTAWA:
                if ((TempIndx + 2) <= RightMargin)
                {
                    if (*(TempIndx + 2) != YOYAK)
                    {
                        return(TempIndx + 1);
                    }
                    else
                    {
                        return(CheckOther(TempIndx));
                    }
                }
                break;
            default:
                return(TempIndx);
        }
    }
    switch (*(TempIndx - 1))
    {
        case KHOKHAI:
        case KHOKHWAI:
        case KHORAKHANG:
        case NGONGU:
        case CHOCHANG:
        case SOSO:
        case CHOCHOE:
        case YOYING:
        case DOCHADA:
        case TOPATAK:
        case THOTHAN:
        case THOPHUTHAO:
        case TOTAO:
        case THOTHUNG:
        case THOTHAHAN:
        case THOTHONG:
        case POPLA:
        case FOFAN:
        case PHOSAMPHAO:
        case SOSALA:
        case SORUSI:
        case SOSUA:
        case LOCHULA:
        case OANG:
        case CHOCHING:
        case PHOPHUNG:
        case FOFA:
        case HONOKHUK:
            return(TempIndx - 2);
        case KOKAI:
            if (*(TempIndx - 2) != SOSUA)
            {
                return(TempIndx - 2);
            }
            break;
        case CHOCHAN:
            if (!(*(TempIndx - 2) == KHOKHAI || *(TempIndx - 2) == WOWAEN))
            {
                return(TempIndx - 2);
            }
            break;
        case YOYAK:
        case NONU:
            if (*(TempIndx - 2) != HOHIP)
            {
                return(TempIndx - 2);
            }
            break;
        case MOMA:
            if (!(*(TempIndx - 2) == HOHIP || *(TempIndx - 2) == SOSUA))
            {
                return(TempIndx - 2);
            }
            break;
        case PHOPHAN:
            if (*(TempIndx - 2) != RORUA)
            {
                return(TempIndx - 2);
            }
            break;
    }
    return(FAIL);
}

unsigned char *CheckOther(unsigned char *TempIndx)
{
    if (*(TempIndx - 3) == SARA_E)
    {
        switch (*(TempIndx + 1))
        {
            case MAIEK:
                return(Sara_IirEkRtn(TempIndx));
            case MAITHO:
                return(Sara_IirToeRtn(TempIndx));
            case YOYAK:
                return(Sara_IirRtn(TempIndx));
        }
    }
    else
    {
        if (*(TempIndx - 2) == SARA_E)
        {
            switch (*(TempIndx + 1))
            {
                case MAIEK:
                    return(Sara_EeEkRtn(TempIndx));
                case MAITHO:
                    return(Sara_EeToeRtn(TempIndx));
                case MAITRI:
                    return(Sara_EeTriRtn(TempIndx));
                case MAICHATTAWA:
                    return(Sara_EeJatRtn(TempIndx));
                case YOYAK:
                    return(Sara_EeRtn(TempIndx));
            }
        }
        else
        {
            switch (*(TempIndx + 1))
            {
                case MAIEK:
                case MAITHO:
                case MAICHATTAWA:
                    return(TempIndx + 1);
                default:
                    return(FAIL);
            }
        }
    }
    return(FAIL);
}

unsigned char *Sara_EeEkRtn(unsigned char *TempIndx)
{
    if ((TempIndx + 2) <= RightMargin)
    {
        if ((TempIndx + 3) <= RightMargin)
        {
            switch (*(TempIndx + 3))
            {
                case NGONGU:
                case WOWAEN:
                case NONU:
                case MOMA:
                    if (!(*(TempIndx - 1) == KHOKHAI
                        || *(TempIndx - 1) == TOTAO
                        || *(TempIndx - 1) == RORUA
                        || *(TempIndx - 1) == SOSUA
                        || *(TempIndx - 1) == HOHIP))
                    {
                        return(TempIndx + 3);
                    }
                    break;
                default:
                    return(TempIndx + 2);
            }
        }
    }
    return(TempIndx - 3);
}

unsigned char *Sara_EeToeRtn(unsigned char *TempIndx)
{
    if ((TempIndx + 2) <= RightMargin)
    {
        if (*(TempIndx + 3) == NGONGU
            || *(TempIndx + 3) == MOMA
            || *(TempIndx + 3) == NONU
            || *(TempIndx + 3) == WOWAEN
            || *(TempIndx + 3) == DODEK)
        {
            if ((TempIndx + 3) <= RightMargin)
            {
                if (*(TempIndx - 1) == TOTAO
                    || *(TempIndx - 1) == POPLA
                    || *(TempIndx - 1) == HOHIP)
                {
                    return(TempIndx - 3);
                }
                else
                {
                    return(TempIndx + 3);
                }
            }
            else
            {
                return(FAIL);
            }
        }
        else
        {
            return(TempIndx + 2);
        }
    }
    else
    {
        return(TempIndx - 3);
    }
}

unsigned char *Sara_EeTriRtn(unsigned char *TempIndx)
{
    if ((TempIndx + 3) <= RightMargin)
    {
        return(TempIndx + 3);
    }
    else
    {
        return(TempIndx - 3);
    }
}

unsigned char *Sara_EeJatRtn(unsigned char *TempIndx)
{
    if ((TempIndx + 3) <= RightMargin)
    {
        if (*(TempIndx - 1) != KOKAI)
        {
            return(TempIndx + 3);
        }
    }
    return(TempIndx - 3);
}

unsigned char *Sara_EeRtn(unsigned char *TempIndx)
{
    if (TempIndx + 1 <= RightMargin)
    {
        switch (*(TempIndx + 2))
        {
            case KOKAI:
                if (!(*(TempIndx - 1) == KOKAI
                    || *(TempIndx - 1) == POPLA
                    || *(TempIndx - 1) == RORUA))
                {
                    return(TempIndx + 1);
                }
                break;
            case CHOCHAN:
                if (*(TempIndx - 1) != KOKAI)
                {
                    return(TempIndx + 1);
                }
                break;
            case NGONGU:
            case BOBAIMAI:
            case DODEK:
            case NONU:
            case MOMA:
            case RORUA:
            case WOWAEN:
            case YOYING:
                break;
            default:
                return(TempIndx + 1);
        }
    }
    return(TempIndx - 3);
}

unsigned char *Sara_IirEkRtn(unsigned char *TempIndx)
{
    if ((TempIndx + 3) <= RightMargin)
    {
        if (*(TempIndx + 3) == NGONGU
            || *(TempIndx + 3) == NONU
            || *(TempIndx + 3) == MOMA
            || *(TempIndx + 3) == WOWAEN)
        {
            if (!((*(TempIndx - 1) == LOLING && *(TempIndx - 2) == CHOCHING)
                || (*(TempIndx - 1) == LOLING && *(TempIndx - 2) == KOKAI)))
            {
                return(TempIndx + 3);
            }
        }
    }
    return(FAIL);
}

unsigned char *Sara_IirToeRtn(unsigned char *TempIndx)
{
    if ((TempIndx + 2) <= RightMargin)
    {
        if (*(TempIndx + 3) == NGONGU || *(TempIndx + 3) == WOWAEN)
        {
            if (*(TempIndx - 1) == LOLING)
            {
                if (!(*(TempIndx - 2) == KOKAI
                    || *(TempIndx - 2) == POPLA
                    || *(TempIndx - 2) == PHOPHAN))
                {
                    return(TempIndx + 2);
                }
                else
                {
                    return(FAIL);
                }
            }
            else
            {
                return(TempIndx + 2);
            }
        }
    }
    return(FAIL);
}

unsigned char *Sara_IirRtn(unsigned char *TempIndx)
{
    if ((TempIndx + 2) <= RightMargin)
    {
        switch (*(TempIndx + 2))
        {
            case KARAN:
                return(TempIndx + 2);
            case KOKAI:
            case NGONGU:
            case NONU:
            case BOBAIMAI:
            case MOMA:
            case WOWAEN:
            case KHOKHWAI:
            case YOYING:
            case RORUA:
                if (!(*(TempIndx - 1) == LOLING && *(TempIndx - 2) == PHOPHAN))
                {
                    return(TempIndx + 2);
                }
                break;
        }
    }
    return(FAIL);
}
