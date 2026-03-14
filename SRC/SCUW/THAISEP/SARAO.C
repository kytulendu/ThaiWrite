#include "Thai.h"
#include "TCtype.h"
#include "Global.h"
#include "Routine.h"

/* ------------ SaraO Rtn ------------ */
/*  Programmer  : Subun Yenjaichon
    Date Written    : Wednesday, 11 May, 1988 10:08:10 AM
    Last Updated    : Monday, 16 May, 1988 4:26:17 PM
*/

unsigned char *SaraORtn(register unsigned char *TempIndx)
{
    register short i;
    unsigned char *TempIndxm1 = TempIndx -1;
    short SoreSeoTbLen    = 6;      /*7-1*/
    short OrAngTbLen      = 8;      /*9-1*/
    short MoreMarTbLen    = 6;      /*7-1*/
    short NoreNooTbLen    = 1;      /*2-1*/
    short ShoreChangTbLen = 3;      /*4-1*/
    static char *SoreSeoTable[] = {" ‚≈«Ï", " ‚π«Ï", " ‚µ√Ï", " ‚¡ √",
        " ‚µπ", " ‚§ª", " ‚≈·°π"};
    static char *OrAngTable[] = {"Õ‚≥∑—¬", "Õ‚√§¬“", "Õ‚À ‘", "Õ‚π™“",
        "Õ‚∑ –", "Õ‚¡À–", "Õ‚≈¿–", "Õ‚≈À–", "Õ‚»°"};
    static char *MoreMarTable[] = {"¡‚À√–∑÷°", "¡‚À√ æ", "¡‚ÀÃ“√", "¡‚À√’",
        "¡‚À ∂", "¡‚π¿“æ", "¡‚π∏√√¡"};
    static char *NoreNooTable[] = {"π‚¬∫“¬", "π‚√¥¡"};
    static char *ShoreChangTable[] = {"™‚≈∫≈", "™‚≈∏√", "™‚≈¡", "™‚¬"};
    static char ToreTaharnWord[] = "∑‚¡π";
    static char RoreReoWord[] = "√‚À∞“π";
    static char YoreYakWord[] = "¬‚ ";
    static char KorKaiWord[] = "¢‚¡¬";

    switch (*(TempIndxm1))
    {
        case SoreSeo:           /*  ‚≈«Ï  ‚π«Ï  ‚µ√Ï  ‚¡ √  ‚µπ  ‚§ª  ‚≈·°π*/
            for (i = 0; i <= SoreSeoTbLen; ++i)
            {
                if (!(nstrcmp(SoreSeoTable[i], TempIndxm1)))
                {
                    /* cut before consonant that before Sara O */
                    return(TempIndx - 2);
                }
            }
            /* cut before sara O */
            return(TempIndxm1);
            break;

        case OrAng:         /* Õ‚≥∑—¬ Õ‚√§¬“ Õ‚À ‘ Õ‚π™“ Õ‚∑ – Õ‚¡À– Õ‚≈¿– Õ‚≈À– Õ‚»°*/
            for (i = 0; i <= OrAngTbLen; ++i)
            {
                if (!(nstrcmp(OrAngTable[i], TempIndxm1)))
                {
                    /* cut before consonant that before Sara O */
                    return(TempIndx - 2);
                }
            }
            /* cut before sara O */
            return(TempIndxm1);
            break;

        case MoreMar:       /* ¡‚À√–∑÷°, ¡‚À√ æ,¡‚ÀÃ“√,¡‚À√,¡‚À ∂ */
            for (i = 0; i <= MoreMarTbLen; ++i)
            {
                if (!(nstrcmp(MoreMarTable[i], TempIndxm1)))
                {
                    /* cut before consonant that before Sara O */
                    return(TempIndx - 2);
                }
            }
            /* cut before sara O */
            return(TempIndxm1);
            break;

        case NoreNoo:       /* π‚¬∫“¬ π‚√¥¡ */
            if (!(nstrcmp("π‚¡", TempIndxm1)) && !(istlvwl(*(TempIndx - 2))))
            {
                if(!(isttnl(*(TempIndx + 2))))
                {
                    /* cut before NoreNoo */
                    return(TempIndx - 2);
                }
            }
            for (i = 0; i <= NoreNooTbLen; ++i)
            {
                if (!(nstrcmp(NoreNooTable[i], TempIndxm1)))
                {
                    /* cut before consonant that before Sara O */
                    return(TempIndx - 2);
                }
            }
            /* cut before sara O */
            return(TempIndxm1);
            break;

        case ShoreChang:        /* ™‚≈∫≈ ™‚≈∏√ ™‚≈¡ ™‚¬ */
            for (i = 0; i <= ShoreChangTbLen; ++i)
            {
                if (!(nstrcmp(ShoreChangTable[i], TempIndxm1)))
                {
                    /* cut before consonant that before Sara O */
                    return(TempIndx - 2);
                }
            }
            /* cut before sara O */
            return(TempIndxm1);
            break;

        case ToreTaharn:        /* ∑‚¡π */
            if (nstrcmp(ToreTaharnWord, TempIndxm1))
            {
                /* cut before sara O */
                return(TempIndxm1);
            }
            else
            {
                /* cut before consonant that before Sara O */
                return(TempIndx - 2);
            }
            break;

        case RoreReo:           /* √‚À∞“π */
            if (nstrcmp(RoreReoWord, TempIndxm1))
            {
                /* cut before sara O */
                return(TempIndxm1);
            }
            else
            {
                /* cut before consonant that before Sara O */
                return(TempIndx - 2);
            }
            break;

        case YoreYak:       /* ¬‚  */
            if (nstrcmp(YoreYakWord, TempIndxm1))
            {
                /* cut before sara O */
                return(TempIndxm1);
            }
            else
            {
                /* cut before consonant that before Sara O */
                return(TempIndx - 2);
            }
            break;

        case KorKai:        /* ¢‚¡¬ */
            if (nstrcmp(KorKaiWord, TempIndxm1))
            {
                /* cut before sara O */
                return(TempIndxm1);
            }
            else
            {
                /* cut before consonant that before Sara O */
                return(TempIndx - 2);
            }
            break;

        default:
            return(TempIndx - 1);
    }
}
