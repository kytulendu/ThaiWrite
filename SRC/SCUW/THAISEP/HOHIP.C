#include "thai.h"
#include "tctype.h"
#include "global.h"

/*  -----------------------------------
    Module Name : HoHipRtn
    Programmer  : Subun yenjaichon
    Date Written    : Friday, 20 May, 1988 2:04:06 PM
    Last Updated    : date
    parameter   : TempIndx (pointer to unsigned char)
    return value    : pointer that pointer to cut pointer.
    ------------------------------------    */

unsigned char *HoHipRtn(unsigned char *TempIndx)
{
    unsigned char *TempIndxm1 = TempIndx - 1;
    unsigned char *TempIndxp1 = TempIndx + 1;

    if (istcon(*TempIndxm1))
    {
        switch (*TempIndxm1)
        {
            case KHOKHWAI:
            case MOMA:
            case SOSUA:
                return(FAIL);
            case THOTHAHAN:
                if (*TempIndxp1 != SARA_AA)
                {
                    /* cut before HoHip */
                    return(TempIndxm1);
                }
                break;
            case RORUA:
            case OANG:
                if (*TempIndxp1 != MAIHUNAKAT)
                {
                    /* cut before HoHip */
                    return(TempIndxm1);
                }
                break;
            case PHOPHAN:
                if (*TempIndxp1 != SARA_U && *TempIndxp1 != SARA_UU)
                {
                    /* cut before HoHip */
                    return(TempIndxm1);
                }
                break;
            default:
                return(TempIndxm1);
        }
    }
    return(FAIL);
}
