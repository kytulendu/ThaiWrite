#include "Thai.h"
#include "Global.h"
#include "Routine.h"

/* ------------ Sara E Rtn ------------ */
/*  Programmer  : Subun Yenjaichon
    Date Written    : Monday, 16 May, 1988 9:40:59 AM
    Last Updated    : Monday, 16 May, 1988 9:41:26 AM
*/

unsigned char *Sara_ERtn(unsigned char *TempIndx)
{
    register short i;
    unsigned char *TempIndxm1 = TempIndx -1;
    unsigned char *TempIndxm2 = TempIndx -2 ;
    short SoSuaAlen = 17; /* 18-1 */
    short OAngAlen = 7;    /* 8-1 */
    short MoMaAlen = 2;  /* 3-1 */
    static unsigned char *SoSuaTableA[] = {" ‡°‘Í√Ïµ", " ‡ªÕ√Ï¡", " ‡ª‘√Ï¡",
        " ‡µ√‘‚Õ", " ‡°Áµ", " ‡ª‚µ", " ‡µ™—Ëπ", " ‡µÁª", " ‡µ¬Ï", " ‡µÁ§",
        " ‡µÁ–", " ‡°≈", " ‡ª°", " ‡ªπ", " ‡µµ", " ‡µ∑", " ‡µπ", " ‡≈π"};
    static unsigned char *OAngTableA[] = {"Õ‡π®", "Õ‡π°—µ∂", "Õ‡¡√‘°—π",
        "Õ‡¡√‘°“", "Õ‡¡‡®Õ√Ï", "Õ‡«®’", "Õ‡ªÀ‘", "Õ‡π∂"};
    static unsigned char *MoMaTableA[] = {"¡‡À»—°¥‘Ï", "¡‡À —°¢Ï", "¡‡À ’"};
    static unsigned char ThoThongAEx[] = "∏‡π»";
    static unsigned char ChoChanAEx[] = "®‡√";
    static unsigned char PhoPhanAEx[] = "æ‡π®√";

    switch (*TempIndxm1)
    {
        case SOSUA:
            for (i = 0; i <= SoSuaAlen; ++i)
            {
                if (!(nstrcmp(SoSuaTableA[i], TempIndxm1)))
                {
                    /* found cut before leading-consonant */
                    return(TempIndxm2);
                }
            }
            break;

        case OANG:
            for (i = 0; i <= OAngAlen; ++i)
            {
                if (!(nstrcmp(OAngTableA[i], TempIndxm1)))
                {
                    /* found cut before leading-consonant */
                    return(TempIndxm2);
                }
            }
            break;

        case MOMA:
            for (i = 0; i <= MoMaAlen; ++i)
            {
                if(!(nstrcmp(MoMaTableA[i], TempIndxm1)))
                {
                    /* found cut before leading-consonant */
                    return(TempIndxm2);
                }
            }
            break;

        case PHOPHAN:
            if (!(nstrcmp(PhoPhanAEx, TempIndxm1)))
            {
                /* found cut before leading-consonant */
                return(TempIndxm2);
            }
            /* cut before Sara E */
            return(TempIndxm1);
            break;

        case THOTHONG:
            if (!(nstrcmp(ThoThongAEx, TempIndxm1)))
            {
                /* found cut before leading-consonant */
                return(TempIndxm2);
            }
            break;

        case CHOCHAN:
            if (!(nstrcmp(ChoChanAEx, TempIndxm1)))
            {
                /* found cut before leading-consonant */
                return(TempIndxm2);
            }
            break;

        default:
            /* cut before Sara E */
            return(TempIndxm1);
    }
    /* cut before Sara E */
    return(TempIndxm1);
}
