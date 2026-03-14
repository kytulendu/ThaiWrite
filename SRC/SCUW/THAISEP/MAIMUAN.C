#include "Thai.h"
#include "TCtype.h"
#include "Global.h"

/*  --------------------------------------------
    Programmer  :   Mr. Subun Yenjaichon
    Date Written    :   Tuesday, 17 May, 1988 11:20:44 AM
    Last Updated    :   Tuesday, 17 May, 1988 11:21:07 AM
    --------------------------------------------    */

unsigned char *MaiMuanRtn(unsigned char *TempIndx)
{
    unsigned char *TempIndxp3 = TempIndx + 3;
    unsigned char *TempIndxp2 = TempIndx + 2;
    unsigned char *TempIndxp1 = TempIndx + 1;
    unsigned char *TempIndxm1 = TempIndx - 1;

    /* check if after following-consonant is tonal ? */
    if (isttnl(*TempIndxp2))
    {
        /* cut after tonal mark or cut before MaiMuan */
        return((TempIndxp2 <= RightMargin) ? TempIndxp2 : TempIndxm1);
    }

    /* else, if it is not tonal, it must be consonant */
    switch (*(TempIndxp1))
    {
        case HorHeeb:
            if  (findchar(*TempIndxp2,"­ÁÅ"))
            {
                if (isttnl(*TempIndxp3))
                {
                    /* cut after tonal mark or cut before MaiMuan */
                    return((TempIndxp3 <= RightMargin) ? TempIndxp3 : TempIndxm1);
                }
                else
                {
                    /* cut after second following consonant or before MaiMuan */
                    return((TempIndxp2 <= RightMargin) ? TempIndxp2 : TempIndxm1);
                }
            }
            break;
        case KoreGai:
            if (*TempIndxp2 == LoreLing)
            {
                if(isttnl(*TempIndxp3))
                {
                    /* cut after tonal mark or cut before MaiMuan */
                    return((TempIndxp3 <= RightMargin) ? TempIndxp3 : TempIndxm1);
                }
                else
                {
                    /* cut after second following consonant or before MaiMuan */
                    return((TempIndxp2 <= RightMargin) ? TempIndxp2 : TempIndxm1);
                }
            }
            break;
        case KoreKwai:
            if (*TempIndxp2 == RoreReo)
            {
                if(isttnl(*TempIndxp3))
                {
                    /* cut after tonal mark or cut before MaiMuan */
                    return((TempIndxp3 <= RightMargin) ? TempIndxp3 : TempIndxm1);
                }
                else
                {
                    /* cut after second following consonant or before MaiMuan */
                    return((TempIndxp2 <= RightMargin) ? TempIndxp2 : TempIndxm1);
                }
            }
            break;
        default:
            return((TempIndxp1 <= RightMargin)? TempIndxp1 : TempIndxm1);
    }

    return(TempIndxm1);
}
