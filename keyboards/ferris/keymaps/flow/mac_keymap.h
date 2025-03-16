#pragma once
#include "keycodes.h"
// clang-format off

// Aliases
#define MC_CIRC KC_GRV  // ^ (dead)
#define MC_1    KC_1    // 1
#define MC_2    KC_2    // 2
#define MC_3    KC_3    // 3
#define MC_4    KC_4    // 4
#define MC_5    KC_5    // 5
#define MC_6    KC_6    // 6
#define MC_7    KC_7    // 7
#define MC_8    KC_8    // 8
#define MC_9    KC_9    // 9
#define MC_0    KC_0    // 0
#define MC_SS   KC_MINS // ß
#define MC_ACUT KC_EQL  // ´ (dead)
#define MC_Q    KC_Q    // Q
#define MC_W    KC_W    // W
#define MC_E    KC_E    // E
#define MC_R    KC_R    // R
#define MC_T    KC_T    // T
#define MC_Z    KC_Y    // Z
#define MC_U    KC_U    // U
#define MC_I    KC_I    // I
#define MC_O    KC_O    // O
#define MC_P    KC_P    // P
#define MC_UDIA KC_LBRC // Ü
#define MC_PLUS KC_RBRC // +
#define MC_A    KC_A    // A
#define MC_S    KC_S    // S
#define MC_D    KC_D    // D
#define MC_F    KC_F    // F
#define MC_G    KC_G    // G
#define MC_H    KC_H    // H
#define MC_J    KC_J    // J
#define MC_K    KC_K    // K
#define MC_L    KC_L    // L
#define MC_ODIA KC_SCLN // Ö
#define MC_ADIA KC_QUOT // Ä
#define MC_HASH KC_NUHS // #
#define MC_LABK KC_NUBS // <
#define MC_Y    KC_Z    // Y
#define MC_X    KC_X    // X
#define MC_C    KC_C    // C
#define MC_V    KC_V    // V
#define MC_B    KC_B    // B
#define MC_N    KC_N    // N
#define MC_M    KC_M    // M
#define MC_COMM KC_COMM // ,
#define MC_DOT  KC_DOT  // .
#define MC_MINS KC_SLSH // -
#define MC_DEG  S(DE_CIRC) // °
#define MC_EXLM S(DE_1)    // !
#define MC_DQUO S(DE_2)    // "
#define MC_SECT S(DE_3)    // §
#define MC_DLR  S(DE_4)    // $
#define MC_PERC S(DE_5)    // %
#define MC_AMPR S(DE_6)    // &
#define MC_SLSH S(DE_7)    // /
#define MC_LPRN S(DE_8)    // (
#define MC_RPRN S(DE_9)    // )
#define MC_EQL  S(DE_0)    // =
#define MC_QUES S(DE_SS)   // ?
#define MC_GRV  S(DE_ACUT) // ` (dead)
#define MC_ASTR S(DE_PLUS) // *
#define MC_QUOT S(DE_HASH) // '
#define MC_RABK S(DE_LABK) // >
#define MC_SCLN S(DE_COMM) // ;
#define MC_COLN S(DE_DOT)  // :
#define MC_UNDS S(DE_MINS) // _
#define MC_DLQU A(DE_CIRC) // „
#define MC_IEXL A(DE_1)    // ¡
#define MC_LDQU A(DE_2)    // “
#define MC_PILC A(DE_3)    // ¶
#define MC_CENT A(DE_4)    // ¢
#define MC_LBRC A(DE_5)    // [
#define MC_RBRC A(DE_6)    // ]
#define MC_PIPE A(DE_7)    // |
#define MC_LCBR A(DE_8)    // {
#define MC_RCBR A(DE_9)    // }
#define MC_NEQL A(DE_0)    // ≠
#define MC_IQUE A(DE_SS)   // ¿
#define MC_LDAQ A(DE_Q)    // «
#define MC_NARS A(DE_W)    // ∑
#define MC_EURO A(DE_E)    // €
#define MC_REGD A(DE_R)    // ®
#define MC_DAGG A(DE_T)    // †
#define MC_OMEG A(DE_Z)    // Ω
#define MC_DIAE A(DE_U)    // ¨ (dead)
#define MC_FRSL A(DE_I)    // ⁄
#define MC_OSTR A(DE_O)    // Ø
#define MC_PI   A(DE_P)    // π
#define MC_BULT A(DE_UDIA) // •
#define MC_PLMN A(DE_PLUS) // ±
#define MC_ARNG A(DE_A)    // Å
#define MC_SLQU A(DE_S)    // ‚
#define MC_PDIF A(DE_D)    // ∂
#define MC_FHK  A(DE_F)    // ƒ
#define MC_COPY A(DE_G)    // ©
#define MC_FORD A(DE_H)    // ª
#define MC_MORD A(DE_J)    // º
#define MC_INCR A(DE_K)    // ∆
#define MC_AT   A(DE_L)    // @
#define MC_OE   A(DE_ODIA) // Œ
#define MC_AE   A(DE_ADIA) // Æ
#define MC_LSQU A(DE_HASH) // ‘
#define MC_LTEQ A(DE_LABK) // ≤
#define MC_YEN  A(DE_Y)    // ¥
#define MC_AEQL A(DE_X)    // ≈
#define MC_CCCE A(DE_C)    // Ç
#define MC_SQRT A(DE_V)    // √
#define MC_INTG A(DE_B)    // ∫
#define MC_TILD A(DE_N)    // ~ (dead)
#define MC_MICR A(DE_M)    // µ
#define MC_INFN A(DE_COMM) // ∞
#define MC_ELLP A(DE_DOT)  // …
#define MC_NDSH A(DE_MINS) // –
#define MC_NOT  S(A(DE_1))    // ¬
#define MC_RDQU S(A(DE_2))    // ”
#define MC_PND  S(A(DE_4))    // £
#define MC_FI   S(A(DE_5))    // ﬁ
#define MC_BSLS S(A(DE_7))    // (backslash)
#define MC_STIL S(A(DE_8))    // ˜
#define MC_MDDT S(A(DE_9))    // ·
#define MC_MACR S(A(DE_0))    // ¯
#define MC_DOTA S(A(DE_SS))   // ˙
#define MC_RNGA S(A(DE_ACUT)) // ˚
#define MC_RDAQ S(A(DE_Q))    // »
#define MC_PERM S(A(DE_E))    // ‰
#define MC_CEDL S(A(DE_R))    // ¸
#define MC_DACU S(A(DE_T))    // ˝
#define MC_CARN S(A(DE_Z))    // ˇ
#define MC_AACU S(A(DE_U))    // Á
#define MC_UCIR S(A(DE_I))    // Û
#define MC_NARP S(A(DE_P))    // ∏
#define MC_APPL S(A(DE_PLUS)) //  (Apple logo)
#define MC_IACU S(A(DE_S))    // Í
#define MC_TM   S(A(DE_D))    // ™
#define MC_IDIA S(A(DE_F))    // Ï
#define MC_IGRV S(A(DE_G))    // Ì
#define MC_OACU S(A(DE_H))    // Ó
#define MC_DLSI S(A(DE_J))    // ı
#define MC_FL   S(A(DE_L))    // ﬂ
#define MC_GTEQ S(A(DE_LABK)) // ≥
#define MC_DDAG S(A(DE_Y))    // ‡
#define MC_UGRV S(A(DE_X))    // Ù
#define MC_LOZN S(A(DE_V))    // ◊
#define MC_LSAQ S(A(DE_B))    // ‹
#define MC_RSAQ S(A(DE_N))    // ›
#define MC_BREV S(A(DE_M))    // ˘
#define MC_OGON S(A(DE_COMM)) // ˛
#define MC_DIV  S(A(DE_DOT))  // ÷
#define MC_MDSH S(A(DE_MINS)) // —

