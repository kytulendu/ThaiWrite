#include "Thai.h"
#include "Global.h"
#include "Routine.h"

/* ------------ SaraA Rtn ------------ */
/*  Programmer  : Subun Yenjaichon
    Date Written    : Monday, 16 May, 1988 9:40:59 AM
    Last Updated    : Monday, 16 May, 1988 9:41:26 AM
*/

unsigned char *SaraARtn(unsigned char *TempIndx)
{
    register short i;
    unsigned char *TempIndxm1 = TempIndx -1;
    unsigned char *TempIndxm2 = TempIndx -2 ;
    short SoreSeoAlen = 17; /* 18-1 */
    short OrAngAlen = 7;    /* 8-1 */
    short MoreMarAlen = 2;  /* 3-1 */
    static unsigned char *SoreSeoTableA[] = {" ‡°‘Í√Ïµ", " ‡ªÕ√Ï¡", " ‡ª‘√Ï¡",
        " ‡µ√‘‚Õ", " ‡°Áµ", " ‡ª‚µ", " ‡µ™—Ëπ", " ‡µÁª", " ‡µ¬Ï", " ‡µÁ§",
        " ‡µÁ–", " ‡°≈", " ‡ª°", " ‡ªπ", " ‡µµ", " ‡µ∑", " ‡µπ", " ‡≈π"};
    static unsigned char *OrAngTableA[] = {"Õ‡π®", "Õ‡π°—µ∂", "Õ‡¡√‘°—π",
        "Õ‡¡√‘°“", "Õ‡¡‡®Õ√Ï", "Õ‡«®’", "Õ‡ªÀ‘", "Õ‡π∂"};
    static unsigned char *MoreMarTableA[] = {"¡‡À»—°¥‘Ï", "¡‡À —°¢Ï", "¡‡À ’"};
    static unsigned char ToreTongAEx[] = "∏‡π»";
    static unsigned char JoreJarnAEx[] = "®‡√";
    static unsigned char PoreParnAEx[] = "æ‡π®√";

    switch (*TempIndxm1)
    {
        case SoreSeo:
            for (i = 0; i <= SoreSeoAlen; ++i)
            {
                if (!(nstrcmp(SoreSeoTableA[i], TempIndxm1)))
                {
                    /* found cut before leading-consonant */
                    return(TempIndxm2);
                }
            }
            break;

        case OrAng:
            for (i = 0; i <= OrAngAlen; ++i)
            {
                if (!(nstrcmp(OrAngTableA[i], TempIndxm1)))
                {
                    /* found cut before leading-consonant */
                    return(TempIndxm2);
                }
            }
            break;

        case MoreMar:
            for (i = 0; i <= MoreMarAlen; ++i)
            {
                if(!(nstrcmp(MoreMarTableA[i], TempIndxm1)))
                {
                    /* found cut before leading-consonant */
                    return(TempIndxm2);
                }
            }
            break;

        case PoreParn:
            if (!(nstrcmp(PoreParnAEx, TempIndxm1)))
            {
                /* found cut before leading-consonant */
                return(TempIndxm2);
            }
            /* cut before SaraA */
            return(TempIndxm1);
            break;

        case ToreTong:
            if (!(nstrcmp(ToreTongAEx, TempIndxm1)))
            {
                /* found cut before leading-consonant */
                return(TempIndxm2);
            }
            break;

        case JoreJarn:
            if (!(nstrcmp(JoreJarnAEx, TempIndxm1)))
            {
                /* found cut before leading-consonant */
                return(TempIndxm2);
            }
            break;

        default:
            /* cut before SaraA */
            return(TempIndxm1);
    }
    /* cut before SaraA */
    return(TempIndxm1);
}
