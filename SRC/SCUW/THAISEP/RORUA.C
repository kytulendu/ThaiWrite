#include "thai.h"
#include "tctype.h"
#include "global.h"

unsigned char *RoRuaRtn(register unsigned char *TempIndx)
{
    if (*(TempIndx - 1) != RORUA)
    {
        return(FAIL);
    }
    if (istrvwl(*(TempIndx - 2)))
    {
        return(TempIndx - 1);
    }
    return(FAIL);
}
