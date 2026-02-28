;                   Font macro definition module for TURBO C
;                             EGA/VGA  Adaptor
;
;                           Kraisorn Liansee
;               Date    :     12/01/88
;               Updated :     12/01/88

shift_down  MACRO reg
    add     &reg&,80
            ENDM

shift_up    MACRO reg
    sub     &reg&,80
            ENDM
