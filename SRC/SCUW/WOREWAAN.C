#include "Thai.h"
#include "Global.h"
#include "TCtype.h"

unsigned char *WoreWaanRtn(register unsigned char *TempIndx)
{
    register unsigned char *plus1 = TempIndx + 1, *minus3 = TempIndx - 3;

    if (istcon(*(TempIndx - 1)))
    {
        if (istlvwl(*(TempIndx - 2)))
        {
            return(minus3);
        }
        else
        {
            if (istcon(*(TempIndx - 2)) && istcon(*plus1))
            {
                switch(*(TempIndx +1))
                {
                    case OrAng:
                        return(FAIL);
                    case RoreReo:
                        if (*(TempIndx + 2) == RoreReo)
                        {
                            return(FAIL);
                        }
                    default:
                        if (plus1 <= RightMargin)
                        {
                            if (*(TempIndx + 3) == Karan)
                            {
                                return(FAIL);
                            }
                            else
                            {
                                return(!istrvwl(*(TempIndx + 2)) ? plus1 : FAIL);
                            }
                        }
                        else
                        {
                            return(FAIL);
                        }
                }
            }
        }
    }
    else
    {
        if (isttnl(*(TempIndx - 1)) && istcon(*(TempIndx - 2)) && istcon(*minus3))
        {
            if (plus1 <= RightMargin)
            {
                return(plus1);
            }
            else if (!nstrcmp("กร", minus3) || !nstrcmp("กล", minus3) ||
                    !nstrcmp("หน", minus3) || !nstrcmp("หย", minus3))
            {
                return(TempIndx - 4);
            }
            else
            {
                return(minus3);
            }
        }
    }
    return(FAIL);
}
