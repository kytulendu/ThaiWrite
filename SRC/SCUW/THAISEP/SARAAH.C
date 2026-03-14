#include "Thai.h"
#include "Global.h"
#include "TCtype.h"

unsigned char *Sara_ARtn(register unsigned char *TempIndx)
{
    unsigned char *TempIndxm2 = TempIndx - 2;

    if (*(TempIndx + 1) == HOHIP &&
        *(TempIndx + 2) == KARAN) /* กรณีนี้เป็น ห์ เช่น เคราะห์ */
    {
        return((TempIndx + 2 <= RightMargin) ? (TempIndx + 2) : FAIL);
    }
    else
    {
        if (TempIndx <= RightMargin)
        {
            return(TempIndx);   /* กรณีทั่ว ๆ ไป เช่น จะ, พระ   */
        }
        else if (istcon(*TempIndxm2))
        {
            switch (*(TempIndx - 1))
            {
                case NONU:
                    if (*TempIndxm2 != CHOCHANG)
                    {
                        /* cut before NoreNue */
                        return(TempIndxm2);
                    }
                    break;
                case RORUA:
                    if (!findchar(*TempIndxm2, "กขตทปพสห"))
                    {
                        return(TempIndxm2);
                    }
                    break;
                case WOWAEN:
                    if (!findchar(*TempIndxm2, "สห"))
                    {
                        return(TempIndxm2);
                    }
                    break;
                case LOLING:
                    if (!findchar(*TempIndxm2, "คผสห"))
                    {
                        return(TempIndxm2);
                    }
                    break;
                case NONEN:
                    if (!findchar(*TempIndxm2, "ขคษ"))
                    {
                        return(TempIndxm2);
                    }
                    break;
                default:
                    return(TempIndxm2);
            }
        }
        return(FAIL);
    }
}
