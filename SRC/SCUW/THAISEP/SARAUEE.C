#include "thai.h"
#include "global.h"
#include "tctype.h"
#include "routine.h"

/*  ----------------------------
        Written by      Tanat Chirakarn
        Modified by     Subun Yenjaichon
        Date Written          7 May, 1988
        Date Modified       23 May, 1988
        ---------------------------- */

unsigned char *Ueer1(unsigned char *TempIndx);
unsigned char *Ueer2(unsigned char *TempIndx);
unsigned char *Ueer3(unsigned char *TempIndx);
unsigned char *Ueer4(unsigned char *TempIndx);
unsigned char *Ueer5(unsigned char *TempIndx);
unsigned char *Ueer6(unsigned char *TempIndx);
unsigned char *Sara_UeeFC(unsigned char *TempIndx);

unsigned char *Sara_UeeRtn(register unsigned char *TempIndx)
{
/*
    if (findchar(*(TempIndx + 1), "¨±¿À"))
    {
        return(FAIL);
    }
*/

    if (isttnl(*(TempIndx + 1)))
    {
        if (*(TempIndx + 2) != OANG)
        {
            if (TempIndx + 2 <= RightMargin)
            {
                return(TempIndx + 2);
/*              return((TempIndx + 2 <= RightMargin) ? (TempIndx + 2) : FAIL); */
            }
        }
        else if (*(TempIndx - 3) == SARA_E)  /* *(TempIndx+2) == OANG */
        {
            switch(*(TempIndx + 1))
            {
                case MAIEK:     return(Ueer1(TempIndx)); /* ‡--◊ËÕ */
                case MAITHO:    return(Ueer2(TempIndx)); /* ‡--◊ÈÕ */
                default:        return(TempIndx - 4);
            }
        }
        else if (*(TempIndx - 2) == SARA_E)
        {
            switch(*(TempIndx + 1))
            {
                case MAIEK:     return(Ueer3(TempIndx)); /* ‡-◊ËÕ */
                case MAITHO:    return(Ueer4(TempIndx)); /* ‡-◊ÈÕ */
                default:        return(TempIndx - 3);
            }
        }
        if(TempIndx + 2 <= RightMargin)
        {
            return(TempIndx + 2);
        }
        else
        {
            return(Sara_UeeFC(TempIndx));
/*            return((TempIndx + 2 <= RightMargin) ? TempIndx + 2 : FAIL); */
        }
    }
    else
    {
        if (*(TempIndx + 1) == OANG)
        {
            if (*(TempIndx - 3) == SARA_E)
            {
                return (Ueer5(TempIndx));   /* ‡--◊Õ */
            }
            else if (*(TempIndx - 2) == SARA_E)
            {
                return (Ueer6(TempIndx));   /* ‡-◊Õ */
            }
            else
            {
                if (TempIndx + 1 <= RightMargin)
                {
                    return(TempIndx + 1);
                }
/*                return((TempIndx + 1 <= RightMargin) ? (TempIndx + 1) : FAIL);  */
            }
        }
    }
    if (TempIndx + 1 <= RightMargin)
    {
        return(TempIndx + 1);
    }
    else
    {
        return(Sara_UeeFC(TempIndx));
    }

/*      return((TempIndx + 1 <= RightMargin) ? (TempIndx + 1) : FAIL);  */
}

unsigned char *Sara_UeeFC(unsigned char *TempIndx)
{
    unsigned char *TempIndxm2 = TempIndx - 2;

    switch (*(TempIndx - 1))
    {
        case NONU:
        case MOMA:
        case WOWAEN:
            if (*TempIndxm2 != HOHIP)
            {
                /* cut before NoNu */
                return(TempIndxm2);
            }
            else
            {
                /* cut before HoHip */
                return(TempIndx - 3);
            }
            /*
            break;
            */
        case RORUA:
            if (!findchar(*TempIndxm2, "§ªÀ"))
            {
                return(TempIndxm2);
            }
            break;
        case LOLING:
            if (!findchar(*TempIndxm2, "°§ªÀ"))
            {
                return(TempIndxm2);
            }
            break;
        default:
            return(TempIndxm2);
    }
    return(FAIL);
}

unsigned char *Ueer1(unsigned char *TempIndx) /* ‡--◊ËÕ */
{
    if (TempIndx + 2 <= RightMargin &&
        (!findchar(*(TempIndx + 3), "ßπ¡¬") ||
        !nstrcmp("æ√", TempIndx - 2) ||
        !nstrcmp("Àß", TempIndx - 2) ||
        !nstrcmp("À¬", TempIndx - 2)))
    {
        return(TempIndx + 2);
    }
    else if (TempIndx + 3 <= RightMargin)
    {
        return(TempIndx + 3);
    }
    return(TempIndx - 4);
}

unsigned char *Ueer2(unsigned char *TempIndx) /* ‡--◊ÈÕ */
{
    if (TempIndx + 2 <= RightMargin)
    {
        if (!nstrcmp("°≈", TempIndx - 2))
        {
            if (*(TempIndx + 3) != NONU)
            {
                return(TempIndx + 2);
            }
        }
        else
        {
            if (TempIndx + 3 <= RightMargin)
            {
                return(TempIndx + 3);
            }
        }
    }
    return(TempIndx - 4);
}

unsigned char *Ueer3(unsigned char *TempIndx) /* ‡-◊ËÕ */
{
    if (findchar(*(TempIndx - 1), "™¥∫ºæø¡¬√ "))
    {
        if (findchar(*(TempIndx + 3), "ßπ¡¬"))
        {
            return(TempIndx - 3);
        }
        else
        {
            return((TempIndx + 2 <= RightMargin) ? TempIndx + 2 : TempIndx - 3);
        }
    }
    else
    {
        return((TempIndx + 3 <= RightMargin) ? TempIndx + 3 : TempIndx - 3);
    }
}

unsigned char *Ueer4(unsigned char *TempIndx) /* ‡-◊ÈÕ */
{
    if (TempIndx + 2 <= RightMargin)
    {
        if (findchar(*(TempIndx + 3), "ßπ¡¬"))
        {
            return(TempIndx - 3);
        }
        else
        {
            return(TempIndx + 2);
        }
    }
    return(TempIndx - 3);
}

unsigned char *Ueer5(unsigned char *TempIndx) /* ‡--◊Õ */
{
    if (TempIndx + 2 <= RightMargin &&
        findchar(*(TempIndx + 2), "°ßπ∫¡¬") &&
        nstrcmp("°≈", TempIndx - 2) &&
        nstrcmp("§√", TempIndx - 2) &&
        nstrcmp("Àπ", TempIndx - 2) &&
        nstrcmp("À≈", TempIndx - 2))
    {
        return(TempIndx + 2);
    }
    return(TempIndx - 4);
}

unsigned char *Ueer6(unsigned char *TempIndx) /* ‡-◊Õ */
{
    if (TempIndx + 2 <= RightMargin &&
        !findchar(*(TempIndx - 1), "¢®∂∫ø¬√ ") &&
        findchar(*(TempIndx + 2), "°ß¥π∫¡¬"))
    {
        return(TempIndx + 2);
    }
    return(TempIndx - 3);
}
