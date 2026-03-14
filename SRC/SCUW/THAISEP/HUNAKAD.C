#include "Thai.h"
#include "Global.h"
#include "TCtype.h"
#include "Routine.h"

unsigned char *MaiHunAKatRtn(register unsigned char *TempIndx)
{
    register unsigned char *plus1 = TempIndx + 1;
    register unsigned char *minus2 = TempIndx - 2;
    if (plus1 <= RightMargin)
    {
        switch(*(plus1))
        {
            case KOKAI:
                if (findchar(*(TempIndx - 1), "¡§ª«´µ¶º»¿ÁÇË"))
                {
                    return(plus1);
                }
                break;
            case NGONGU:
                switch(*(TempIndx - 1))
                {
                    case SOSUA:
                        if (*(TempIndx + 2) != KHOKHAI && *(TempIndx + 2) != KHORAKHANG)
                        {
                            return(plus1);
                        }
                        break;
                    case RORUA:
                        if (!nstrcmp("¡ÃÑ§´ì", minus2))
                        {
                            return(TempIndx - 3);
                        }
                        else
                        {
                            return(plus1);
                        }
                    default:
                        return(plus1);
                }
                break;
            case DODEK:
                return(plus1);
            case NONU:
                if (*(TempIndx + 3) != KARAN)
                {
                    return(plus1);
                }
                break;
            case YOYAK:
                if (!nstrcmp("¹ÑÂ¹ì", TempIndx - 1))
                {
                    return(minus2);
                }
                else
                {
                    return(plus1);
                }
            case SOSUA:
                if (*(TempIndx + 4) != KARAN)
                {
                    return(plus1);
                }
                break;
            case WOWAEN:
                switch(*(TempIndx + 2))
                {
                    case SARA_A:
                        if (TempIndx + 2 <= RightMargin)
                        {
                            return(TempIndx + 2);
                        }
                        break;
                     case RORUA:
                        if (*(TempIndx + 3) == KARAN)
                        {
                            return(minus2);
                        }
                        break;
                    default:
                        return(plus1);
                }
                break;
            default:
                if (isttnl(*(plus1)))
                {
                    if (*(TempIndx + 4) == KARAN)
                    {
                        return(minus2);
                    }
                    else
                    {
                        if (TempIndx + 2 <= RightMargin)
                            return(TempIndx + 2);
                    }
                }
        }

        switch(*(TempIndx - 1))
        {
            case NGONGU:
                return(plus1);
            case NONU:
                if (!findchar(*(plus1), "µ¹Â"))
                {
                    return(plus1);
                }
                break;
            case MOMA:
                if (!findchar(*(plus1), "¤¹Ç"))
                {
                    return(plus1);
                }
                break;
            case RORUA:
                if (!findchar(*(plus1), "¡µ¾È"))
                {
                    return(plus1);
                }
                break;
            case HOHIP:
                if (*(plus1) != TOTAO && *(plus1) != NONU)
                {
                    return(plus1);
                }
                break;
            case HONOKHUK:
                return(plus1);
        }
    }

    if (findchar(*(TempIndx - 1), "¢¤¦ª«­±³¶¸»¼½¾¿ÈÊÍÎ"))
    {
        return(minus2);
    }
    else
    {
        switch(*(TempIndx - 1))
        {
            case KOKAI:
                return(*minus2 == SOSUA ? FAIL : minus2);
            case NGONGU:
                switch(*minus2)
                {
                    case HOHIP:
                        return(TempIndx - 3);
                    case SOSUA:
                        return(FAIL);
                    default:
                        return(minus2);
                }
            case CHOCHAN:
                return((*minus2 == KHOKHAI) ? FAIL : minus2);
            case DODEK:
                return((*minus2 == SOSUA) ? FAIL : minus2);
            case TOTAO:
                return((*minus2 == KOKAI) ? FAIL : minus2);
            case THOTHAHAN:
                switch(*minus2)
                {
                    case HOHIP:
                        return(TempIndx - 3);
                    case WOWAEN:
                        return(FAIL);
                    default:
                        return(minus2);
                }
            case BOBAIMAI:
                return((*minus2 == CHOCHING) ? TempIndx - 3 : minus2);
            case PHOSAMPHAO:
                return((*minus2 == OANG) ? FAIL : minus2);
            case WOWAEN:
                return(findchar(*minus2, "¡¢¤¨©µ¶¸ÊË") ? FAIL : minus2);
            case HOHIP:
                return(findchar(*minus2 ,"ÁÃÍ")? FAIL :minus2);
        }
    }
    return(FAIL);
}
