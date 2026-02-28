;                   Font macro definition module for TURBO C
;                             AT&T Adaptor
;
;                           Kraisorn Liansee
;               Date    :     12/01/88
;               Updated :     12/01/88

shift_down  MACRO reg
            LOCAL br1
    add     &reg&,2000h
    jns     br1
    add     &reg&,8050h
br1:
            ENDM

shift_up    MACRO reg
            LOCAL br1
    sub     &reg&,2000h
    jns     br1
    add     &reg&,8000h - 050h
br1:
            ENDM
