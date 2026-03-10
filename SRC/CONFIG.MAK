# Compiler configuration

# Assembler
#======================================

# Watcom Assembler
#ASM = WASMR
#AFLAGS = -zq -wx -ml

# Borland Turbo Assembler
ASM = TASM
AFLAGS = /w2/z/zi/ml

# C Compiler
#======================================

# Borland C++
#CC = BCC
#CCFLAGS = -c -w -ml -d -f- -K
#INCPATH = C:\BC\INCLUDE;..\COMMON

# Borland Turbo C or C++
CC = TCC
CCFLAGS = -c -w -ml -C -d -f- -K -O -Z
INCPATH = C:\TC\INCLUDE;..\COMMON

#======================================

LINKER = TLINK
LFLAGS = /x/n/d/c

# Unused yet
#LIBPATH = C:\BC\LIB
