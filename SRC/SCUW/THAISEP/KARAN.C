#include "thai.h"
#include "tctype.h"
#include "global.h"
#include "routine.h"

/* ------------ Karan Rtn ------------ */
/*  Programmer  : Subun Yenjaichon
    Written Date    : Monday, 16 May, 1988 1:04:44 PM
    Last Updated    : Tuesday, 17 May, 1988 11:15:14 AM
*/

unsigned char *KaranRtn(unsigned char *TempIndx)
{
    short i;
    unsigned char *TempIndxp1 = TempIndx + 1;
    unsigned char *TempIndxm1 = TempIndx - 1;
    unsigned char *TempIndxm3 = TempIndx - 3;
    unsigned char *TempIndxm4 = TempIndx - 4;
    unsigned char *TempIndxm5 = TempIndx - 5;

    /* RORUA */
    static unsigned char *MoMaRoRuaTable5[] = {"ฟอร์ม", "ฟาร์ม",
        "วอร์ม", "อาร์ม"};
    static unsigned char *ToTaoRoRuaTable5[] = {"มาร์ต", "ชอร์ต", "ปอร์ต",
        "อาร์ต"};
    static unsigned char *DoDekRoRuaTable5[] = {"บอร์ด", "ฮาร์ด", "ตาร์ด",
        "การ์ด","ลอร์ด", "ฟอร์ด"};
    static unsigned char *KhoKhwaiRoRuaTable5[] = {"ยอร์ค", "ปาร์ค", "มาร์ค"};
    static unsigned char *KoKaiRoRuaTable5[] = {"ตาร์ก"};
    static unsigned char *LoLingRoRuaTable5[] = {"มาร์ล"};
    static unsigned char *PoPlaRoRuaTable5[] = {"ชาร์ป"};
    static unsigned char *ChoChanRoRuaTable5[] = {"ชาร์จ"};
    static unsigned char *PhoPhanRoRuaTable5[] = {"ชาร์พ"};
    static unsigned char *ChoChangRoRuaTable5[] = {"มาร์ช"};
    static unsigned char *SoSuaRoRuaTable5[] = {"มอร์ส"};
    static unsigned char *ThoThaHanRoRuaTable5[] = {"มาร์ท"};

    static unsigned char *ThoThaHanRoRuaTable6[] = {"สมาร์ท", "สตาร์ท", "อพาร์ท"};
    static unsigned char *ToTaoRoRuaTable6[] = {"สปอร์ต", "สตาร์ต", "อพาร์ต"};
    static unsigned char *DoDekRoRuaTable6[] = {"เบิร์ด", "เวิร์ด"};
    static unsigned char *KhoKhwaiRoRuaTable6[] = {"เบอร์ค", "เวิร์ค"};
    static unsigned char *MoMaRoRuaTable6[] = {"เทอร์ม", "เยิร์ม"}; /* 2*/
    static unsigned char *NoNuRoRuaTable6[] = {"เดิร์น", "เฟิร์น"};
    static unsigned char *KoKaiRoRuaTable6[] = {"เตอร์ก", "เบอร์ก"};
    static unsigned char *FoFanRoRuaTable6[] = {"เสิร์ฟ"};
    static unsigned char *LoLingRoRuaTable6[] = {"เอิร์ล"};

    static unsigned char *MoMaRoRuaTable7[] = {"สเปอร์ม", "สเปิร์ม"};/* 2 */

    /* LoLing */
    static unsigned char *MoMaLoLingTable5[] = {"ปาล์ม", "โฮล์ม", "บาล์ม",
                        "ฟิล์ม"};
    static unsigned char *KhoKhwaiLoLingTable5[] = {"ชอร์ค", "ทอล์ค", "วอล์ค", "โฟล์ค"};
    static unsigned char *KoKaiLoLingTable5[] = {"ชอล์ก"};
    static unsigned char *FoFanLoLingTable5[] = {"กอล์ฟ", "ฮาล์ฟ"};
    static unsigned char *WoWaenLoLingTable5[] = {"วาล์ว"};

    if(istrvwl(*(TempIndx + 2)))
    {
        /* cut after Karan */
        return(TempIndx);
    }
    switch (*TempIndxm1)
    {
        case RORUA:
            switch (*TempIndxp1)
            {
                case MOMA:
                    for (i = 0; i <= 1; ++i)
                    {
                        if (!(nstrcmp(MoMaRoRuaTable7[i], (TempIndx - 5))))
                        {
                            /* cut after following-consonant */
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : (TempIndx - 6));
                        }
                    }
                    for (i = 0; i <= 1; ++i)
                    {
                        if (!(nstrcmp(MoMaRoRuaTable6[i], TempIndxm4)))
                        {
                            /* cut after following-consonant */
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for (i = 0; i <= 3; ++i)
                    {
                        if (!(nstrcmp(MoMaRoRuaTable5[i], TempIndxm3)))
                        {
                            /* cut after following-consonant */
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case TOTAO:
                    for (i = 0; i <= 2; ++i)
                    {
                        if (!(nstrcmp(ToTaoRoRuaTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for (i = 0;i <= 3; ++i)
                    {
                        if (!(nstrcmp(ToTaoRoRuaTable5[i], TempIndxm3)))
                        {
                            /* cut after following-consonant */
                            return((TempIndxp1 <= RightMargin ) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;

                case DODEK:
                    for (i = 0;i <= 1; ++i)
                    {
                        if (!(nstrcmp(DoDekRoRuaTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin)? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for(i = 0; i <= 5;++i)
                    {
                        if (!(nstrcmp(DoDekRoRuaTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin )? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case KHOKHWAI:
                    for (i = 0; i <= 1; ++i)
                    {
                        if(!(nstrcmp(KhoKhwaiRoRuaTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for (i = 0; i <= 2; ++i)
                    {
                        if (!(nstrcmp(KhoKhwaiRoRuaTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case KOKAI:
                    for (i = 0; i <= 1; ++i)
                    {
                        if(!(nstrcmp(KoKaiRoRuaTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for (i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(KoKaiRoRuaTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case THOTHAHAN:
                    for (i = 0;i <= 2; ++i)
                    {
                        if(!(nstrcmp(ThoThaHanRoRuaTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for (i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(ThoThaHanRoRuaTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case LOLING:
                    for (i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(LoLingRoRuaTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for (i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(LoLingRoRuaTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case POPLA:
                    for (i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(LoLingRoRuaTable5[i],TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case CHOCHANG:
                    for (i = 0; i <= 0; ++i)
                    {
                        if (!(nstrcmp(ChoChangRoRuaTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case CHOCHAN:
                    for (i = 0; i <= 0; ++i)
                    {
                        if (!(nstrcmp(ChoChanRoRuaTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case PHOPHAN:
                    for (i = 0; i <= 0; ++i)
                    {
                        if (!(nstrcmp(PhoPhanRoRuaTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case SOSUA:
                    for (i = 0; i <= 0; ++i)
                    {
                        if (!(nstrcmp(SoSuaRoRuaTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1: TempIndxm4);
                        }
                    }
                    break;
                case FOFAN:
                    for (i = 0; i <= 0; ++i)
                    {
                        if (!(nstrcmp(FoFanRoRuaTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                case NONU:
                    for (i = 0; i <= 1; ++i)
                    {
                        if (!(nstrcmp(NoNuRoRuaTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                default:
                    return(TempIndx);
            }

        case LOLING:
            switch (*TempIndxp1)
            {
                case MOMA:
                    for(i = 0; i <= 3; ++i)
                    {
                        if(!(nstrcmp(MoMaLoLingTable5[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                case KHOKHWAI:
                    for (i = 0;i <= 3; ++i)
                    {
                        if(!(nstrcmp(KhoKhwaiLoLingTable5[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                case KOKAI:
                    for(i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(KoKaiLoLingTable5[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                case FOFAN:
                    for(i = 0; i <= 1; ++i)
                    {
                        if(!(nstrcmp(FoFanLoLingTable5[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                case WOWAEN:
                    for(i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(WoWaenLoLingTable5[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                default:
                    return(TempIndx);
            }

        case SOSUA:
            if (!(nstrcmp("สาส์น", TempIndxm3)) || !(nstrcmp("ศาส์น", TempIndxm3)))
            {
                /* cut after following-consonant or before SoSua or SoreSara */
                return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
            }
            break;

        case WOWAEN:
            if (!(nstrcmp("โบว์ล", TempIndxm3)))
            {
                /* cut after following-consonant or before Sara O */
                return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
            }
            break;

        case HOHIP:
            if (!(nstrcmp("โอห์ม", TempIndxm3)))
            {
                /* cut after following-consonant or before Sara O */
                return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
            }
            break;

        default:
            /* cut after garant */
            return(TempIndx);
    }
    /* cut after garant */
    return(TempIndx);
}
