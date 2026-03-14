#include "Thai.h"
#include "TCtype.h"
#include "Global.h"
#include "Routine.h"

/* ------------ Sara O Rtn ------------ */
/*  Programmer  : Subun Yenjaichon
    Date Written    : Wednesday, 11 May, 1988 10:08:10 AM
    Last Updated    : Monday, 16 May, 1988 4:26:17 PM
*/

unsigned char *Sara_ORtn(register unsigned char *TempIndx)
{
    register short i;
    unsigned char *TempIndxm1 = TempIndx -1;
    short SoSuaTbLen    = 6;      /*7-1*/
    short OAngTbLen      = 8;      /*9-1*/
    short MoMaTbLen    = 6;      /*7-1*/
    short NoNuTbLen    = 1;      /*2-1*/
    short ChoChangTbLen = 3;      /*4-1*/
    static char *SoSuaTable[] = {" ‚≈«Ï", " ‚π«Ï", " ‚µ√Ï", " ‚¡ √",
        " ‚µπ", " ‚§ª", " ‚≈·°π"};
    static char *OAngTable[] = {"Õ‚≥∑—¬", "Õ‚√§¬“", "Õ‚À ‘", "Õ‚π™“",
        "Õ‚∑ –", "Õ‚¡À–", "Õ‚≈¿–", "Õ‚≈À–", "Õ‚»°"};
    static char *MoMaTable[] = {"¡‚À√–∑÷°", "¡‚À√ æ", "¡‚ÀÃ“√", "¡‚À√’",
        "¡‚À ∂", "¡‚π¿“æ", "¡‚π∏√√¡"};
    static char *NoNuTable[] = {"π‚¬∫“¬", "π‚√¥¡"};
    static char *ChoChangTable[] = {"™‚≈∫≈", "™‚≈∏√", "™‚≈¡", "™‚¬"};
    static char ThoThaHanWord[] = "∑‚¡π";
    static char RoRuaWord[] = "√‚À∞“π";
    static char YoYakWord[] = "¬‚ ";
    static char KhoKhaiWord[] = "¢‚¡¬";

    switch (*(TempIndxm1))
    {
        case SOSUA:           /*  ‚≈«Ï  ‚π«Ï  ‚µ√Ï  ‚¡ √  ‚µπ  ‚§ª  ‚≈·°π*/
            for (i = 0; i <= SoSuaTbLen; ++i)
            {
                if (!(nstrcmp(SoSuaTable[i], TempIndxm1)))
                {
                    /* cut before consonant that before Sara O */
                    return(TempIndx - 2);
                }
            }
            /* cut before sara O */
            return(TempIndxm1);
            break;

        case OANG:         /* Õ‚≥∑—¬ Õ‚√§¬“ Õ‚À ‘ Õ‚π™“ Õ‚∑ – Õ‚¡À– Õ‚≈¿– Õ‚≈À– Õ‚»°*/
            for (i = 0; i <= OAngTbLen; ++i)
            {
                if (!(nstrcmp(OAngTable[i], TempIndxm1)))
                {
                    /* cut before consonant that before Sara O */
                    return(TempIndx - 2);
                }
            }
            /* cut before sara O */
            return(TempIndxm1);
            break;

        case MOMA:       /* ¡‚À√–∑÷°, ¡‚À√ æ,¡‚ÀÃ“√,¡‚À√,¡‚À ∂ */
            for (i = 0; i <= MoMaTbLen; ++i)
            {
                if (!(nstrcmp(MoMaTable[i], TempIndxm1)))
                {
                    /* cut before consonant that before Sara O */
                    return(TempIndx - 2);
                }
            }
            /* cut before sara O */
            return(TempIndxm1);
            break;

        case NONU:       /* π‚¬∫“¬ π‚√¥¡ */
            if (!(nstrcmp("π‚¡", TempIndxm1)) && !(istlvwl(*(TempIndx - 2))))
            {
                if(!(isttnl(*(TempIndx + 2))))
                {
                    /* cut before NoNu */
                    return(TempIndx - 2);
                }
            }
            for (i = 0; i <= NoNuTbLen; ++i)
            {
                if (!(nstrcmp(NoNuTable[i], TempIndxm1)))
                {
                    /* cut before consonant that before Sara O */
                    return(TempIndx - 2);
                }
            }
            /* cut before sara O */
            return(TempIndxm1);
            break;

        case CHOCHANG:        /* ™‚≈∫≈ ™‚≈∏√ ™‚≈¡ ™‚¬ */
            for (i = 0; i <= ChoChangTbLen; ++i)
            {
                if (!(nstrcmp(ChoChangTable[i], TempIndxm1)))
                {
                    /* cut before consonant that before Sara O */
                    return(TempIndx - 2);
                }
            }
            /* cut before sara O */
            return(TempIndxm1);
            break;

        case THOTHAHAN:        /* ∑‚¡π */
            if (nstrcmp(ThoThaHanWord, TempIndxm1))
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

        case RORUA:           /* √‚À∞“π */
            if (nstrcmp(RoRuaWord, TempIndxm1))
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

        case YOYAK:       /* ¬‚  */
            if (nstrcmp(YoYakWord, TempIndxm1))
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

        case KHOKHAI:        /* ¢‚¡¬ */
            if (nstrcmp(KhoKhaiWord, TempIndxm1))
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
