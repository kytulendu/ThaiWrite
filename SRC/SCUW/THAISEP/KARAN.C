#include "Thai.h"
#include "TCtype.h"
#include "Global.h"
#include "Routine.h"

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
/* RoreReo */
    static unsigned char *MoreMarRoreReoTable5[] = {"ฟอร์ม", "ฟาร์ม",
        "วอร์ม", "อาร์ม"};
    static unsigned char *ToreTaoRoreReoTable5[] = {"มาร์ต", "ชอร์ต", "ปอร์ต",
        "อาร์ต"};
    static unsigned char *DoreDekRoreReoTable5[] = {"บอร์ด", "ฮาร์ด", "ตาร์ด",
        "การ์ด","ลอร์ด", "ฟอร์ด"};
    static unsigned char *KoreKwaiRoreReoTable5[] = {"ยอร์ค", "ปาร์ค", "มาร์ค"};
    static unsigned char *KoreGaiRoreReoTable5[] = {"ตาร์ก"};
    static unsigned char *LoreLingRoreReoTable5[] = {"มาร์ล"};
    static unsigned char *PorePlaRoreReoTable5[] = {"ชาร์ป"};
    static unsigned char *JoreJarnRoreReoTable5[] = {"ชาร์จ"};
    static unsigned char *PoreParnRoreReoTable5[] = {"ชาร์พ"};
    static unsigned char *ShoreChangRoreReoTable5[] = {"มาร์ช"};
    static unsigned char *SoreSeoRoreReoTable5[] = {"มอร์ส"};
    static unsigned char *ToreTaharnRoreReoTable5[] = {"มาร์ท"};

    static unsigned char *ToreTaharnRoreReoTable6[] = {"สมาร์ท", "สตาร์ท", "อพาร์ท"};
    static unsigned char *ToreTaoRoreReoTable6[] = {"สปอร์ต", "สตาร์ต", "อพาร์ต"};
    static unsigned char *DoreDekRoreReoTable6[] = {"เบิร์ด", "เวิร์ด"};
    static unsigned char *KoreKwaiRoreReoTable6[] = {"เบอร์ค", "เวิร์ค"};
    static unsigned char *MoreMarRoreReoTable6[] = {"เทอร์ม", "เยิร์ม"}; /* 2*/
    static unsigned char *NoreNooRoreReoTable6[] = {"เดิร์น", "เฟิร์น"};
    static unsigned char *KoreGaiRoreReoTable6[] = {"เตอร์ก", "เบอร์ก"};
    static unsigned char *ForeFunRoreReoTable6[] = {"เสิร์ฟ"};
    static unsigned char *LoreLingRoreReoTable6[] = {"เอิร์ล"};

    static unsigned char *MoreMarRoreReoTable7[] = {"สเปอร์ม", "สเปิร์ม"};/* 2 */

    /* LoreLing */
    static unsigned char *MoreMarLoreLingTable5[] = {"ปาล์ม", "โฮล์ม", "บาล์ม",
                        "ฟิล์ม"};
    static unsigned char *KoreKwaiLoreLingTable5[] = {"ชอร์ค", "ทอล์ค", "วอล์ค", "โฟล์ค"};
    static unsigned char *KoreGaiLoreLingTable5[] = {"ชอล์ก"};
    static unsigned char *ForeFunLoreLingTable5[] = {"กอล์ฟ", "ฮาล์ฟ"};
    static unsigned char *WoreWaanLoreLingTable5[] = {"วาล์ว"};

    if(istrvwl(*(TempIndx + 2)))
    {
        /* cut after karan */
        return(TempIndx);
    }
    switch (*TempIndxm1)
    {
        case RoreReo:
            switch (*TempIndxp1)
            {
                case MoreMar:
                    for (i = 0; i <= 1; ++i)
                    {
                        if (!(nstrcmp(MoreMarRoreReoTable7[i], (TempIndx - 5))))
                        {
                            /* cut after following-consonant */
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : (TempIndx - 6));
                        }
                    }
                    for (i = 0; i <= 1; ++i)
                    {
                        if (!(nstrcmp(MoreMarRoreReoTable6[i], TempIndxm4)))
                        {
                            /* cut after following-consonant */
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for (i = 0; i <= 3; ++i)
                    {
                        if (!(nstrcmp(MoreMarRoreReoTable5[i], TempIndxm3)))
                        {
                            /* cut after following-consonant */
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case ToreTao:
                    for (i = 0; i <= 2; ++i)
                    {
                        if (!(nstrcmp(ToreTaoRoreReoTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for (i = 0;i <= 3; ++i)
                    {
                        if (!(nstrcmp(ToreTaoRoreReoTable5[i], TempIndxm3)))
                        {
                            /* cut after following-consonant */
                            return((TempIndxp1 <= RightMargin ) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;

                case DoreDek:
                    for (i = 0;i <= 1; ++i)
                    {
                        if (!(nstrcmp(DoreDekRoreReoTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin)? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for(i = 0; i <= 5;++i)
                    {
                        if (!(nstrcmp(DoreDekRoreReoTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin )? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case KoreKwai:
                    for (i = 0; i <= 1; ++i)
                    {
                        if(!(nstrcmp(KoreKwaiRoreReoTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for (i = 0; i <= 2; ++i)
                    {
                        if (!(nstrcmp(KoreKwaiRoreReoTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case KoreGai:
                    for (i = 0; i <= 1; ++i)
                    {
                        if(!(nstrcmp(KoreGaiRoreReoTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for (i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(KoreGaiRoreReoTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case ToreTaharn:
                    for (i = 0;i <= 2; ++i)
                    {
                        if(!(nstrcmp(ToreTaharnRoreReoTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for (i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(ToreTaharnRoreReoTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case LoreLing:
                    for (i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(LoreLingRoreReoTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    for (i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(LoreLingRoreReoTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case PorePla:
                    for (i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(LoreLingRoreReoTable5[i],TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case ShoreChang:
                    for (i = 0; i <= 0; ++i)
                    {
                        if (!(nstrcmp(ShoreChangRoreReoTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case JoreJarn:
                    for (i = 0; i <= 0; ++i)
                    {
                        if (!(nstrcmp(JoreJarnRoreReoTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case PoreParn:
                    for (i = 0; i <= 0; ++i)
                    {
                        if (!(nstrcmp(PoreParnRoreReoTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
                        }
                    }
                    break;
                case SoreSeo:
                    for (i = 0; i <= 0; ++i)
                    {
                        if (!(nstrcmp(SoreSeoRoreReoTable5[i], TempIndxm3)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1: TempIndxm4);
                        }
                    }
                    break;
                case ForeFun:
                    for (i = 0; i <= 0; ++i)
                    {
                        if (!(nstrcmp(ForeFunRoreReoTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                case NoreNoo:
                    for (i = 0; i <= 1; ++i)
                    {
                        if (!(nstrcmp(NoreNooRoreReoTable6[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                default:
                    return(TempIndx);
            }

        case LoreLing:
            switch (*TempIndxp1)
            {
                case MoreMar:
                    for(i = 0; i <= 3; ++i)
                    {
                        if(!(nstrcmp(MoreMarLoreLingTable5[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                case KoreKwai:
                    for (i = 0;i <= 3; ++i)
                    {
                        if(!(nstrcmp(KoreKwaiLoreLingTable5[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                case KoreGai:
                    for(i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(KoreGaiLoreLingTable5[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                case ForeFun:
                    for(i = 0; i <= 1; ++i)
                    {
                        if(!(nstrcmp(ForeFunLoreLingTable5[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                case WoreWaan:
                    for(i = 0; i <= 0; ++i)
                    {
                        if(!(nstrcmp(WoreWaanLoreLingTable5[i], TempIndxm4)))
                        {
                            return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm5);
                        }
                    }
                    break;
                default:
                    return(TempIndx);
            }

        case SoreSeo:
            if (!(nstrcmp("สาส์น", TempIndxm3)) || !(nstrcmp("ศาส์น", TempIndxm3)))
            {
                /* cut after following-consonant or before SoreSeo or SoreSara */
                return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
            }
            break;

        case WoreWaan:
            if (!(nstrcmp("โบว์ล", TempIndxm3)))
            {
                /* cut after following-consonant or before SaraO */
                return((TempIndxp1 <= RightMargin) ? TempIndxp1 : TempIndxm4);
            }
            break;

        case HorHeeb:
            if (!(nstrcmp("โอห์ม", TempIndxm3)))
            {
                /* cut after following-consonant or before SaraO */
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
