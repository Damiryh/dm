#pragma once

#define OP_HLT  0xff

#define OP_LD   0x10
#define OP_ST   0x20
#define OP_SWP  0x30

#define OP_ADD  0x40
#define OP_ADC  0x41
#define OP_SUB  0x42
#define OP_SBB  0x43

#define OP_AND  0x50
#define OP_OR   0x51
#define OP_XOR  0x52
#define OP_NOT  0x53

#define OP_TST  0x58
#define OP_CMP  0x59

#define OP_JMP  0x60
#define OP_JZ   0x61
#define OP_JC   0x62
#define OP_JNZ  0x63
#define OP_JNC  0x64

#define OP_CALL 0x70
#define OP_RET  0xf0

#define OP_LDI  0xe0

#define IMM 0x00
#define DIR 0x01
#define IDX 0x02
