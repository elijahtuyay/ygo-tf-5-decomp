/*
 * rel_duel_draw.prx — reconstructed code (matching decompilation)
 *
 * Compiler:     Metrowerks CodeWarrior for PSP — MWCC 1.3 SP7 (mwccpsp_3.0.1_219)
 * Flags:        -O4,s -sdatathreshold 0
 * Verification: scripts/mwcc_build.sh src/rel_duel_draw.c
 *               scripts/mwcc_diff.py asm/rel_duel_draw/text.s build/mwcc/rel_duel_draw.o
 *
 * Every function below is byte-identical to the shipped module — each was
 * accepted only on a MATCH verdict from scripts/mwcc_diff.py, and the whole
 * file is re-verified after assembly (scripts/assemble_module.py).
 * Functions are in ADDRESS ORDER, which is what the linker needs.
 *
 * Import names are resolved from the module's NID tables and are identical
 * across all 28 modules — see docs/nids/README.md.
 *
 * STATUS: 457 functions matched here (of 1546 total). The rest of the
 * module is not yet decompiled; build/auto/<module>.json has the status
 * of every attempt.
 *
 * NOTE: assembled by scripts/assemble_module.py from drafts produced by
 * scripts/auto_decomp.py (m2c + source reshapes + verification). Local names
 * are therefore still m2c's (temp_v0, var_s1); renaming them and adding
 * per-function commentary is safe as long as every edit is re-verified.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
#define NULL 0

/* ---- imports and globals ---- */
extern char D_0007EB50;
extern char D_0007EB54;
extern char D_00080090;
extern char D_00090CF4;
extern char D_00090D20;
extern int D_00090D70;
extern int D_000910CC;
extern char D_00091654;
extern char D_000916B0;
extern char D_00093AF8;
extern char D_3958D8;
extern char D_395A20;
extern char D_395D7C;
extern char D_3964D4;
extern char D_396854;
extern char D_396978;
extern char D_39847C;
extern char D_398528;
extern char D_398538;
extern char D_398748;
extern char D_398754;
extern char D_398958;
extern int ehsys_3BB2BAC6();
extern int ehsys_97BB99A5();
extern int ehsys_B89D38DC();
extern int ehsys_BC8E65D7();
extern int func_00031EC8();
extern int func_00032FDC();
extern int func_000586B0();
extern int func_00066700();
extern char D_00094020;
extern char D_3956E0;
extern int duel_eng_09BD4A2A();
extern int duel_eng_0F848AB5();
extern int duel_eng_1256A810();
extern int duel_eng_2174D9E0();
extern int duel_eng_3865EBDA();
extern int duel_eng_4A030E8B();
extern int duel_eng_4F664B71();
extern int duel_eng_66155499();
extern int duel_eng_746BFD48();
extern int duel_eng_9081141C();
extern int duel_eng_A5CC5331();
extern int duel_eng_BAF46839();
extern int duel_eng_F2783CB1();
extern int ehsys_39ADDA9F();
extern int ehsys_4AA58320();
extern int ehsys_4BF558F1();
extern int ehsys_5DF04F49();
extern int ehsys_60B55A50();
extern int ehsys_65DA0419();
extern int ehsys_82B715FD();
extern int ehsys_93EACD81();
extern int ehsys_942B03D0();
extern int ehsys_9EA6989A();
extern int ehsys_B0F320E6();
extern int ehsys_C792FA38();
extern int ehsys_C9D9E989();
extern int ehsys_D470D0B2();
extern int ehsys_D853F15C();
extern int ehsys_E1139F1A();
extern int ehsys_EBD1986B();
extern int ehsys_EF9B5D06();
extern int ehsys_F292E199();
extern int ehsys_F5E3080C();
extern int ehsys_memset();
extern int func_00001DB8();
extern int func_00001EBC();
extern int func_00002320();
extern int func_00002354();
extern int func_0000364C();
extern int func_000036C0();
extern int func_00004364();
extern int func_00004410();
extern int func_00004FB8();
extern int func_00005098();
extern int func_00005460();
extern int func_000054B4();
extern int func_000066E4();
extern int func_00007494();
extern int func_0000864C();
extern int func_00008734();
extern int func_00008E04();
extern int func_00009F80();
extern int func_0000B288();
extern int func_0000B4D4();
extern int func_0000B668();
extern int func_0000B9E8();
extern int func_0000BD14();
extern int func_0001095C();
extern int func_00010970();
extern int func_00011060();
extern int func_00011B24();
extern int func_00013A2C();
extern int func_00013AA8();
extern int func_00013F94();
extern int func_00014140();
extern int func_000142D8();
extern int func_0001557C();
extern int func_00019500();
extern int func_0001A7CC();
extern int func_0001AFFC();
extern int func_0001B3D4();
extern int func_0001C424();
extern int func_0001C508();
extern int func_0001C8D0();
extern int func_0001C9D8();
extern int func_0001CBD8();
extern int func_0001CD08();
extern int func_0001D620();
extern int func_000232A4();
extern int func_0002EEDC();
extern int func_0003199C();
extern int func_00031A10();
extern int func_00031FA0();
extern int func_00032744();
extern int func_00038D50();
extern int func_00050304();
extern int func_00050E34();
extern int func_00051184();
extern int func_00051210();
extern int func_00051678();
extern int func_00051958();
extern int func_000527C8();
extern int func_000536B8();
extern int func_00055390();
extern int func_00055E34();
extern int func_00055F0C();
extern int func_00056310();
extern int func_000573E8();
extern int func_0005846C();
extern int func_000587E8();
extern int func_00058E3C();
extern int func_00058E9C();
extern int func_000592CC();
extern int func_000593B4();
extern int func_000596A4();
extern int func_000599A8();
extern int func_00059C94();
extern int func_0005AED8();
extern int func_0005AEEC();
extern int func_0005BE44();
extern int func_0005BE84();
extern int func_0005FB34();
extern int func_000600B4();
extern int func_00063580();
extern int func_00063700();
extern int func_00064658();
extern int func_000687BC();
extern int func_000687D8();
extern int func_000687E0();
extern int func_00069304();
extern int func_00069F28();
extern int func_0006A3C0();
extern int func_0006E0DC();
extern char D_39881C;
extern char D_398834;
extern char D_398868;
extern char D_398940;
extern char D_39898C;
extern int duel_eng_0534CBA5();
extern int duel_eng_0796FC63();
extern int duel_eng_0EB5F782();
extern int duel_eng_12943036();
extern int duel_eng_1837FC74();
extern int duel_eng_1A4C5817();
extern int duel_eng_1DE65CD9();
extern int duel_eng_20FA1976();
extern int duel_eng_302F0BDC();
extern int duel_eng_3B0C99E7();
extern int duel_eng_3EF59AD0();
extern int duel_eng_4BC82DF2();
extern int duel_eng_4E22C77E();
extern int duel_eng_50FDA3A6();
extern int duel_eng_564492D2();
extern int duel_eng_575C7FF3();
extern int duel_eng_5A2E1D22();
extern int duel_eng_65CABB3B();
extern int duel_eng_6C7BDC7D();
extern int duel_eng_6E78EB9B();
extern int duel_eng_70D96DE6();
extern int duel_eng_70F7713B();
extern int duel_eng_7214A584();
extern int duel_eng_77689943();
extern int duel_eng_780289AD();
extern int duel_eng_878654F9();
extern int duel_eng_8ACE7469();
extern int duel_eng_8B100126();
extern int duel_eng_8CE718D2();
extern int duel_eng_8FEC3AF9();
extern int duel_eng_94B1D599();
extern int duel_eng_95531E08();
extern int duel_eng_962F6809();
extern int duel_eng_9ADAC01D();
extern int duel_eng_A47EF27C();
extern int duel_eng_A7D6360C();
extern int duel_eng_A99B16A1();
extern int duel_eng_AEDF1F0D();
extern int duel_eng_B1CA7A57();
extern int duel_eng_B5DAA640();
extern int duel_eng_B774881F();
extern int duel_eng_B8A3FF78();
extern int duel_eng_C4B3FEFE();
extern int duel_eng_CD086A4E();
extern int duel_eng_CFCDD509();
extern int duel_eng_DE8F840C();
extern int duel_eng_E8754761();
extern int duel_eng_ED3B1B4B();
extern int duel_eng_EDED5379();
extern int duel_eng_EE219051();
extern int ehsys_2AE3C0AD();
extern int func_0000568C();
extern int func_000119B0();
extern int func_00011A00();
extern int func_00011A2C();
extern int func_0001B2E8();
extern int func_0001BD44();
extern int func_0001BF28();
extern int func_0001C1DC();
extern int func_00051770();
extern int func_00053B3C();
extern int func_000564C8();
extern int func_00058A68();
extern int func_00058B0C();
extern int func_000590DC();
extern int func_000592B4();
extern int func_0005B77C();
extern int func_0005D078();
extern int func_0005D0B8();
extern int func_000633C8();
extern int func_000696A0();
extern int func_000696A8();
extern int func_000696B0();
extern int func_000696B8();
extern int func_0006DD28();
extern int func_0006DD70();
extern int func_0006DE64();
extern int func_0006DE7C();
extern int func_0006DE84();
extern int func_0006DE9C();
extern int func_0006DF74();
extern void * D_00077BE0;
extern void * D_00078210;
extern void * D_00078220;
extern void * D_000909E0;
extern void * D_00090CB0;
extern void * D_00090CE4;
extern void * D_00093B0C;
extern void * D_0009410C;
extern void * D_00094124;
extern void * D_395A6C;
extern void * D_3A13A8;
extern void * D_3A13B0;
extern char D_0007EB30;
extern char D_0007EB38;
extern char D_0007EB3C;
extern char D_0007EB40;
extern char D_0007F2D0;
extern char D_0007F30C;
extern char D_0007F318;
extern char D_0007F31C;
extern char D_0007F320;
extern char D_0007F340;
extern char D_000800C8;
extern char D_000909D0;
extern char D_000909DC;
extern char D_00090C58;
extern char D_00090ED4;
extern char D_00090F40;
extern char D_00091114;
extern char D_00091648;
extern char D_0009164C;
extern char D_00091650;
extern char D_000937A0;
extern char D_000937A4;
extern char D_000937A8;
extern char D_000938C4;
extern char D_000938C8;
extern char D_00093AFC;
extern char D_000940E0;
extern char D_000940F4;
extern char D_000940F8;
extern char D_000940FC;
extern char D_0009412C;
extern char D_00095538;
extern int func_00000000();
extern int func_0000246C();
extern int func_00002478();
extern int func_00002548();
extern int func_0000258C();
extern int func_00002D78();
extern int func_00004CA0();
extern int func_00004F88();
extern int func_0000B3E8();
extern int func_00015880();
extern int func_00015914();
extern int func_000194EC();
extern int func_00019C38();
extern int func_0001CC98();
extern int func_0001D428();
extern int func_0003066C();
extern int func_00030694();
extern int func_0004FC94();
extern int func_0005062C();
extern int func_0005086C();
extern int func_00051630();
extern int func_0005163C();
extern int func_00051648();
extern int func_000539AC();
extern int func_000560BC();
extern char D_0007F2E0;
extern char D_0007F2E4;
extern char D_0007F310;
extern char D_0007F314;
extern char D_0007F330;
extern char D_0007F334;
extern char D_00093B04;
extern char D_000940E4;
extern int ehsys_1EC5342B();
extern int ehsys_399AC68A();
extern int ehsys_C62F9EAC();
extern int ehsys_D767C29F();
extern int ehsys_DFCA450B();
extern int func_00004EFC();
extern int func_000068A8();
extern int func_00009054();
extern int func_0000B00C();
extern int func_00015BF0();
extern int func_0001A8E4();
extern int func_0001CC70();
extern int func_000204A0();
extern int func_00031A08();
extern int func_00033420();
extern int func_0004F34C();
extern int func_0004F3F0();
extern int func_00050600();
extern int func_00069448();
extern int ehsys_B56890DA();
extern int ehsys_get_language();
void *func_00002838(void *arg0, void *arg1);
extern int func_0005577C();
extern int func_0006DE5C();
extern int ehsys_20E340D9();
extern int ehsys_41AABF28();
extern int ehsys_AD0E1E03();
extern int func_00002CFC();
extern int func_000031B4();
extern int func_000031F8();
extern int func_000034A0();
extern int func_0005369C();
extern int ehsys_82DEC529();
void func_00004EF0(s32 arg0);
extern int func_00038E10();
extern int func_00039158();

/* ---- structs (local, for pointer-arg thunks) ---- */
struct S1B70C { int pad0; int pad1; int pad2; int f0C; };
struct S1BD3C { int f00; };

/* ---- forward declarations ---- */
f32 func_00032EB4(s32 arg0, s32 arg1);
s32 * func_000633B0(s32 *arg0, s32 *arg1);
s32 func_00001CEC(s32 arg0);
s32 func_000040F0(void);
s32 func_0000465C(void);
s32 func_00004664(void);
s32 func_00008758(void);
s32 func_00011C50(void);
s32 func_00033258(s32 arg0, s32 arg1, s32 arg2);
s32 func_0004C798(s32 *arg0, s32 *arg1);
s32 func_0004CF98(void);
s32 func_0004D000(void);
s32 func_0004D040(void);
s32 func_0004D43C(void);
s32 func_0004D480(void);
s32 func_0004D56C(void);
s32 func_0004DC3C(void);
s32 func_0004DD14(void);
s32 func_0004DF50(void);
s32 func_0004E04C(void);
s32 func_0004E168(void);
s32 func_0004E54C(void);
s32 func_0004F410(s32 arg0);
s32 func_0004F4B8(void);
s32 func_00050F98(void);
s32 func_00051760(void);
s32 func_00051768(void);
s32 func_000536AC(void);
s32 func_00053B48(s32 *arg0, s32 *arg1);
s32 func_00054F64(s32 arg0);
s32 func_00054FCC(void);
s32 func_00055374(void);
s32 func_00055728(void);
s32 func_00055804(s32 arg0);
s32 func_000559A8(void);
s32 func_00055C18(s32 arg0);
s32 func_00055D20(void);
s32 func_00055E28(void);
s32 func_000564F0(void);
s32 func_000564FC(void);
s32 func_000573E0(void);
s32 func_0005784C(s32 *arg0, s32 *arg1);
s32 func_00058FDC(void);
s32 func_00059018(void);
s32 func_00059078(void);
s32 func_00059960(void);
s32 func_000599C4(void);
s32 func_00059D20(void);
s32 func_0005B7E4(void);
s32 func_0005BBA0(s32 arg0);
s32 func_0005E144(s32 arg0);
s32 func_0005FBB8(void);
s32 func_0006051C(void);
s32 func_00060558(void);
s32 func_000619F8(s32 arg0);
s32 func_00062534(s32 arg0);
s32 func_00062B34(s32 arg0);
s32 func_00063B48(s32 arg0);
s32 func_000681F8(s32 arg0);
s32 func_00068208(s32 arg0);
s32 func_0006A3A8(s32 arg0);
s32 func_0006A490(s32 arg0, int arg1, int arg2);
s32 func_0006A6B8(void);
s32 func_0006C8AC(void);
s32 func_0006CC2C(void);
s32 func_0006DD1C(void);
u16 * func_000066D4(u16 *arg0, u16 *arg1);
u16 * func_00008DF4(u16 *arg0, u16 *arg1);
void * func_0005034C(s32 arg0);
void func_000000B8(void);
void func_000024BC(void);
void func_00002CBC(s32 arg0, int arg1);
void func_00005F9C(void);
void func_000069CC(void);
void func_00008494(void);
void func_00011074(void);
void func_0001388C(void);
void func_000138D0(void);
void func_000154DC(void);
void func_00017C40(s32 arg0);
void func_00019628(void);
void func_00019630(void);
void func_00019CF8(void);
void func_0001A1F4(void);
void func_0001A8A8(void);
void func_0001C500(void);
void func_0001D2E8(void);
void func_0003159C(void);
void func_00031BD0(void);
void func_000320B0(s32 arg0, int arg1);
void func_000327C8(s32 arg0);
void func_00039140(void);
void func_00039148(void);
void func_00039150(void);
void func_0003DAF8(void);
void func_0003DB00(void);
void func_0004C4D8(void);
void func_0004F61C(void);
void func_0004FC68(void);
void func_0004FC8C(void);
void func_0004FCC0(void);
void func_0004FF90(void);
void func_0004FFDC(void);
void func_0004FFE4(void);
void func_00050018(void);
void func_000502CC(void);
void func_000502D4(void);
void func_000502DC(void);
void func_000502E4(void);
void func_000502EC(void);
void func_000502F4(void);
void func_0005054C(void);
void func_00050578(void);
void func_000505F8(void);
void func_00050BB8(void);
void func_00050C58(void);
void func_00050C60(void);
void func_00050C70(void);
void func_00050D60(void);
void func_00053674(s32 arg0);
void func_00053680(void);
void func_00053930(void);
void func_0005399C(void);
void func_00053B10(void);
void func_00053B58(void);
void func_00053BE4(void);
void func_00054F54(void);
void func_00054F5C(void);
void func_00055388(void);
void func_00055488(void);
void func_00055598(void);
void func_0005574C(void);
void func_000557F8(void);
void func_00055BAC(void);
void func_00055BE0(void);
void func_00055C10(void);
void func_0005666C(void);
void func_00056C4C(s32 arg0);
void func_00056C58(void);
void func_00056C60(void);
void func_00056D18(void);
void func_00056D20(void);
void func_00056D84(void);
void func_00056D8C(void);
void func_00056DB0(void);
void func_00056E54(void);
void func_00056E78(s32 arg0);
void func_00057128(void);
void func_00057B34(void);
void func_00058E34(void);
void func_0005906C(void);
void func_00059290(void);
void func_0005929C(s32 arg0);
void func_000592A8(s32 arg0);
void func_000592C0(s32 arg0);
void func_00059328(s32 arg0);
void func_00059434(s32 arg0);
void func_0005999C(s32 arg0);
void func_000599D0(void);
void func_0005B770(void);
void func_0005C8D4(void);
void func_0005D964(void);
void func_0005D970(void);
void func_0005DB6C(void);
void func_0005F8DC(void);
void func_0005FBA0(void);
void func_0005FBB0(void);
void func_0005FBC4(void);
void func_0005FBE8(void);
void func_0005FC14(void);
void func_0005FC1C(void);
void func_0005FC48(void);
void func_000605BC(void);
void func_000618AC(void);
void func_00062428(void);
void func_00063020(void);
void func_00063050(void);
void func_000633C0(void);
void func_00066B3C(void);
void func_00066CCC(void);
void func_00066E7C(void);
void func_000680DC(void);
void func_000685C0(void);
void func_000685F4(void);
void func_000687B4(void);
void func_00068D3C(void);
void func_00069244(void);
void func_00069278(void);
void func_000692A8(void);
void func_000698C8(void);
void func_00069E6C(void);
void func_00069EF4(void);
void func_0006A6A8(void);
void func_0006A6B0(void);
void func_0006CD0C(void);
void func_0006CD14(void);
void func_0006E174(void);
void func_0006E204(void);
void func_0006E3E0(void);
void func_0006E3E8(void);

s32 func_00004CB4(s32 arg0, s32 arg1, s32 arg2);
s32 func_00010C20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_000117D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_000117F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_000154E4(s32 arg0, s32 arg1, s32 arg2);
s32 func_00017D68(s32 arg0, s32 arg1, s32 arg2);
s32 func_0001D318(s32 arg0, s32 arg1, s32 arg2);
s32 func_00033094(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0003DAEC(s32 arg0, s32 arg1, s32 arg2);
s32 func_00050A48(s32 arg0, s32 arg1, s32 arg2);
s32 func_00050B68(s32 arg0, s32 arg1);
s32 func_00050C4C(s32 arg0, s32 arg1);
s32 func_000542B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_00055D44(s32 arg0, s32 arg1, s32 arg2);
s32 func_00055D58(s32 arg0, s32 arg1, s32 arg2);
s32 func_00056C40(s32 arg0, s32 arg1);
s32 func_0005711C(s32 arg0, s32 arg1);
s32 func_00057640(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_00057D00(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_00058690(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0005ACCC(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0005B750(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0005C574(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0005C68C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_0005CE20(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0005D288(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0005E108(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0005E128(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_0005E554(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0005ECC0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0005F310(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0005F700(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_0005FB18(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_00060CF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_00060D08(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_000615D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_00063C48(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_000650E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_00066B30(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_00066CB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_0006753C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_00067550(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_000680C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_000685AC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_00068CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_00068F24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_00069238(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_00069AF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_00069B14(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_00069E60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0006A388(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0006ABF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

/* func_000000B8 — 2 words. MATCH 100% (shape: m2c). */
void func_000000B8(void) {

}

/* func_00000300 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00000300(s32 *arg0) {
    return arg0[0x3F] != 0;
}

/* func_00000244 — 7 words. MATCH 100% (verified). */
void func_00000244(void *arg0) {
    *(s32 *)((char *)arg0 + 0xFC) = 0;
    *(s32 *)((char *)arg0 + 0xF8) = -1;
    ehsys_memset((char *)arg0 + 0x78, 0xFF, 0x40);
}

/* func_0000030C — 14 words. MATCH 100% (shape: m2c). */
int func_0000030C(s32 *arg0) {
    if (func_00000300(arg0) != 0) {
        ehsys_82DEC529((*(int *)((char *)arg0 + 0x40)));
        (*(int *)((char *)arg0 + 0xFC)) = 0;
    }
}

/* func_00001CEC — 14 words. MATCH 100% (shape: m2c). */
s32 func_00001CEC(s32 arg0) {
    s32 temp_s0;

    temp_s0 = ehsys_82B715FD(arg0 + 1);
    return temp_s0 - ehsys_82B715FD(arg0);
}

/* func_00001E54 — 10 words. MATCH 100% (shape: hand). */
s32 func_00001E54(s32 arg0, s32 arg1) {
    return arg1 + func_00001DB8();
}

/* func_00001E7C — 16 words. MATCH 100% (shape: m2c). */
void func_00001E7C(void) {
    ehsys_memset(&D_0007EB30, 0, 0x7B0);
    *(s32 *)&D_0007EB3C = -1;
    func_00004CA0();
    func_00000000();
}

/* func_00002098 — 3 words. MATCH 100% (shape: m2c). */
int func_00002098(void) {
    return func_00002CFC((*(s32 *)&D_0007EB38));
}

/* func_000020A4 — 9 words. MATCH 100% (shape: m2c). */
s32 func_000020A4(void) {
    func_00002D78((*(s32 *)&D_0007EB38));
    return 0;
}

/* func_00002250 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00002250(void) {
    return (*(s32 *)&D_0007EB38);
}

/* func_0000225C — 7 words. MATCH 100% (verified). */
int func_0000225C(s32 arg0) {
    char *base = &D_0007EB30;
    if (arg0 == 0) {
        arg0 = -1;
    }
    *(s32 *)(*(s32 *)(base + 8) + 0x1B0) = arg0;
}

/* func_00002278 — 10 words. MATCH 100% (shape: m2c). */
void func_00002278(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_a0;

    temp_a0 = &D_0007EB30 + (arg0 * 0x1E0);
    (*(int *)((char *)temp_a0 + 0x1DC)) = arg1;
    (*(int *)((char *)temp_a0 + 0x1E0)) = (s32) (arg1 + arg2);
}

/* func_0000246C — 3 words. MATCH 100% (shape: m2c). */
int func_0000246C(arg0) s32 arg0;
{
    (*(s32 *)&D_0007F2D0) = arg0;
}

/* func_00002478 — 3 words. MATCH 100% (shape: m2c). */
int func_00002478() {
    return (s32)((*(s32 *)&D_0007F2D0));
}

/* func_000024BC — 2 words. MATCH 100% (shape: m2c). */
void func_000024BC(void) {
    func_0000258C();
}

/* func_00002510 — 5 words. MATCH 100% (shape: m2c). */
int func_00002510(s32 arg0, int arg1) {
    return func_000031B4((*(s32 *)&D_0007EB38), arg0, arg1);
}

/* func_00002524 — 5 words. MATCH 100% (shape: m2c). */
int func_00002524(s32 arg0, int arg1) {
    return func_000031F8((*(s32 *)&D_0007EB38), arg0, arg1);
}

/* func_00002538 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00002538(void) {
    return (*(s32 *)&D_0007EB38) + 0x120;
}

/* func_00002548 — 4 words. MATCH 100% (shape: m2c). */
int func_00002548() {
    return (s32)((*(s32 *)&D_0007EB38) + 0x160);
}

/* func_00002558 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00002558(void) {
    return (*(s32 *)&D_0007EB38) + 0x1A0;
}

/* func_00002568 — 6 words. MATCH 100% (shape: m2c). */
int func_00002568(void) {
    *(s32 *)&D_0007EB40 = 1;
    return func_0000030C((s32 *)(*(s32 *)&D_0007EB38));
}

/* func_00002580 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00002580(void) {
    return (*(s32 *)&D_0007EB40);
}

/* func_0000258C — 3 words. MATCH 100% (shape: m2c). */
int func_0000258C() {
    (*(s32 *)&D_0007EB40) = 0;
}

/* func_00002598 — 4 words. MATCH 100% (shape: m2c). */
int func_00002598(s32 arg0) {
    return func_000034A0((*(s32 *)&D_0007EB38), arg0);
}

/* func_00002600 — 8 words. MATCH 100% (shape: hand). */
s32 func_00002600(s32 arg0) {
    return *(int *)(&D_0007EB50 + (arg0 * 0x1E0));
}

/* func_00002620 — 8 words. MATCH 100% (shape: hand). */
s32 func_00002620(s32 arg0) {
    return *(int *)(&D_0007EB54 + (arg0 * 0x1E0));
}

/* func_00002640 — 3 words. MATCH 100% (shape: m2c). */
s32 (*func_00002640(void))() {
    return func_0006A3C0;
}

/* func_000027AC — 5 words. MATCH 100% (shape: m2c). */
void func_000027AC(s32 arg0, s32 arg1) {
    (*(s32 *)&D_0007F2E0) = arg0;
    (*(s32 *)&D_0007F2E4) = arg1;
}

/* func_000027F4 — 17 words. MATCH 100% (shape: m2c). */
void func_000027F4(s32 arg0, int arg1) {
    ehsys_memset(arg0, 0, 0x1E0);
    func_00002838((void *)arg0, (void *)arg1);
}

/* func_00002838 — 34 words. MATCH 100% (shape: m2c). */
void *func_00002838(void *arg0, void *arg1) {
    (*(int *)((char *)arg0 + 0x0)) = (s32) (*(int *)((char *)arg1 + 0x0));
    (*(int *)((char *)arg0 + 0x4)) = (s32) (*(int *)((char *)arg1 + 0x4));
    (*(int *)((char *)arg0 + 0x8)) = (s32) (*(int *)((char *)arg1 + 0x8));
    (*(int *)((char *)arg0 + 0xC)) = (s32) (*(int *)((char *)arg1 + 0xC));
    (*(int *)((char *)arg0 + 0x10)) = (s32) (*(int *)((char *)arg1 + 0x10));
    (*(int *)((char *)arg0 + 0x14)) = (s32) (*(int *)((char *)arg1 + 0x14));
    (*(int *)((char *)arg0 + 0x18)) = (s32) (*(int *)((char *)arg1 + 0x18));
    (*(int *)((char *)arg0 + 0x1C)) = (s32) (*(int *)((char *)arg1 + 0x1C));
    (*(int *)((char *)arg0 + 0x20)) = (s32) (*(int *)((char *)arg1 + 0x20));
    (*(int *)((char *)arg0 + 0x24)) = (s32) (*(int *)((char *)arg1 + 0x24));
    (*(int *)((char *)arg0 + 0x28)) = (s32) (*(int *)((char *)arg1 + 0x28));
    (*(int *)((char *)arg0 + 0x2C)) = (s32) (*(int *)((char *)arg1 + 0x2C));
    (*(int *)((char *)arg0 + 0x30)) = (s32) (*(int *)((char *)arg1 + 0x30));
    (*(int *)((char *)arg0 + 0x34)) = (s32) (*(int *)((char *)arg1 + 0x34));
    (*(int *)((char *)arg0 + 0x38)) = (s32) (*(int *)((char *)arg1 + 0x38));
    (*(int *)((char *)arg0 + 0x3C)) = (s32) (*(int *)((char *)arg1 + 0x3C));
    return arg0;
}

/* func_00002CBC — 16 words. MATCH 100% (shape: m2c). */
void func_00002CBC(s32 arg0, int arg1) {
    func_0000364C(arg1);
    func_000036C0(arg0, arg1);
}

/* func_000034DC — 8 words. MATCH 100% (shape: m2c). */
s32 func_000034DC(s32 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (arg0[116] & (1 << arg1)) != 0;
    return (temp_v0 ^ 1) & 0xFF;
}
/* func_00003634 — 0 words. MATCH 100% (shape: twin of func_00002EB0). */
void func_00003634(void *arg0) {

    void (*fn)(void *);
    fn = *(void (**)(void *))((char *)arg0 + 0x24);
    fn(arg0);
}
/* func_00003640 — 0 words. MATCH 100% (shape: twin of func_00002EBC). */
void func_00003640(void *arg0) {

    void (*fn)(void *);
    fn = *(void (**)(void *))((char *)arg0 + 0x28);
    fn(arg0);
}

/* func_000040D0 — 8 words. MATCH 100% (verified). */
extern void *ehsys_B2B9FEFA(void);
s32 func_000040D0(void) {
    void *v0 = ehsys_B2B9FEFA();
    return *(s32 *)((char *)v0 + 4);
}

/* func_000040F0 — 2 words. MATCH 100% (shape: m2c). */
s32 func_000040F0(void) {
    return 1;
}

/* func_000041B8 — 22 words. MATCH 100% (shape: m2c). */
s32 func_000041B8(s32 arg0, int arg1, int arg2) {
    func_00039158();
    func_00038E10(arg0, arg1, arg2);
    func_00004EF0(0);
    return 0;
}

/* func_0000465C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0000465C(void) {
    return 0;
}

/* func_00004664 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00004664(void) {
    return 0;
}
/* func_000048B8 — 10 words. MATCH 100% (verified). */
typedef struct { f32 a, b, c, d; } V4_58A0_48B8;
void *func_000048B8(V4_58A0_48B8 *arg0, V4_58A0_48B8 *arg1) {
    arg0->a = arg1->a;
    arg0->b = arg1->b;
    arg0->c = arg1->c;
    arg0->d = arg1->d;
    return arg0;
}

/* func_000048E0 — 10 words. MATCH 100% (verified). */
void *func_000048E0(V4_58A0_48B8 *arg0, V4_58A0_48B8 *arg1) {
    arg0->a = arg1->a;
    arg0->b = arg1->b;
    arg0->c = arg1->c;
    arg0->d = arg1->d;
    return arg0;
}

/* func_00004CA0 — 0 words. MATCH 100% (shape: twin of func_00004CB4). */
s32 func_00004CA0(s32 arg0, s32 arg1, s32 arg2) {

    return ehsys_memset(&D_0007F30C, 0, 0xC);
}

/* func_00004CB4 — 5 words. MATCH 100% (shape: thunk). */
s32 func_00004CB4(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_memset(&D_0007F30C, 0, 0xC);
}

/* func_00004EDC — 5 words. MATCH 100% (shape: m2c). */
void func_00004EDC(s32 arg0, s32 arg1) {
    (*(s32 *)&D_0007F314) = arg1;
    (*(s32 *)&D_0007F310) = arg0;
}

/* func_00004EF0 — 3 words. MATCH 100% (shape: m2c). */
void func_00004EF0(s32 arg0) {
    (*(s32 *)&D_0007F30C) = arg0;
}

/* func_00004EFC — 19 words. MATCH 100% (shape: m2c). */
int func_00004EFC(arg0) s32 arg0;
{
    ehsys_memset(&D_0007F318, 0, 0x2C);
    (*(s32 *)&D_0007F330) = arg0;
    (*(s32 *)&D_0007F334) = 1 - arg0;
}

/* func_00004F48 — 16 words. MATCH 100% (shape: m2c). */
void func_00004F48(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a0;

    temp_a0 = (arg0 * 3) << 2;
    *(s32 *)(&D_0007F318 + temp_a0) = arg1;
    *(s32 *)(&D_0007F31C + temp_a0) = arg2;
    *(s32 *)(&D_0007F320 + temp_a0) = arg3;
}

/* func_00004F88 — 12 words. MATCH 100% (shape: m2c). */
int func_00004F88(arg0) s32 arg0;
{
    (*(s32 *)&D_0007F340) = arg0;
    func_00050304(0x10, 1);
    ehsys_4BF558F1(0xD);
}

/* func_00005F9C — 15 words. MATCH 100% (shape: m2c). */
void func_00005F9C(void) {
    ehsys_memset(&D_00080090, 0, 0x90);
    func_000066E4(0, 7, 0, 0);
}

/* func_000066D4 — 4 words. MATCH 100% (shape: m2c). */
u16 *func_000066D4(u16 *arg0, u16 *arg1) {
    *arg0 = *arg1;
    return arg0;
}

/* func_000069C0 — 3 words. MATCH 100% (shape: m2c). */
void func_000069C0(s32 arg0) {
    (*(s32 *)&D_000800C8) = arg0;
}

/* func_000069CC — 2 words. MATCH 100% (shape: m2c). */
void func_000069CC(void) {

}

/* func_00008494 — 9 words. MATCH 100% (shape: m2c). */
void func_00008494(void) {
    func_00005F9C();
    func_0000BD14();
}

/* func_00008184 — 8 words. MATCH 100% (verified). */
typedef struct { f32 a, b, c; } V3_3B00_8184;
void *func_00008184(V3_3B00_8184 *arg0, V3_3B00_8184 *arg1) {
    arg0->a = arg1->a;
    arg0->b = arg1->b;
    arg0->c = arg1->c;
    return arg0;
}

/* func_0000864C — 6 words. MATCH 100% (verified). */
int func_0000864C(void) {
    extern s32 D_00080120;
    ehsys_memset(&D_00080120, 0, 0x10AE0);
}

/* func_00008758 — 14 words. MATCH 100% (shape: single-switch). */
s32 func_00008758(void) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_00008734();
    var_v1 = temp_v0 >> 1;
    if (temp_v0 < 0) {
        var_v1 = (s32) (temp_v0 + 1) >> 1;
    }

    switch (var_v1) {
    case 0:
        return temp_v0 + 2;
        break;
    }
    return temp_v0 - 2;
}

/* func_00008DF4 — 4 words. MATCH 100% (shape: m2c). */
u16 *func_00008DF4(u16 *arg0, u16 *arg1) {
    *arg0 = *arg1;
    return arg0;
}

/* func_0000ADB0 — 4 words. MATCH 100% (verified). */
void func_0000ADB0(void *arg0, u16 arg1, s32 arg2) {
    *(s32 *)((char *)arg0 + 0x88) = arg2 & 0xFFFF;
    *(u16 *)((char *)arg0 + 0x80) = arg1;
}

/* func_0000B224 — 4 words. MATCH 100% (shape: m2c). */
void func_0000B224(void) {
    (*(s32 *)&D_000909D0) = 1;
}

/* func_0000B3E8 — 3 words. MATCH 100% (shape: m2c). */
int func_0000B3E8(arg0) s32 arg0;
{
    (*(s32 *)&D_000909DC) = arg0;
}

/* func_0000B464 — 6 words. MATCH 100% (shape: m2c). */
void func_0000B464(s32 arg0, void *arg1) {
    (&D_000909E0)[arg0] = arg1;
}

/* func_0000EBC8 — 9 words. MATCH 100% (verified). */
typedef struct Node0EBC8 { struct Node0EBC8 *next; struct Node0EBC8 *prev; } Node0EBC8;
s32 func_0000EBC8(Node0EBC8 *arg0, Node0EBC8 *arg1) {
    arg0->next = arg1->next;
    arg0->prev = arg1;
    arg0->next->prev = arg0;
    arg0->prev->next = arg0;
    return 1;
}

/* func_0000EBEC — 8 words. MATCH 100% (verified). */
typedef struct Node0EBEC { struct Node0EBEC *next; struct Node0EBEC *prev; } Node0EBEC;
s32 func_0000EBEC(Node0EBEC *arg0, Node0EBEC *arg1) {
    arg0->prev = arg1->prev;
    arg0->next = arg1;
    arg1->prev = arg0;
    arg0->prev->next = arg0;
    return 1;
}

/* func_0001095C — 5 words. MATCH 100% (verified). */
s32 func_0001095C(void) {
    extern s32 D_00090C08;
    return ehsys_memset(&D_00090C08, 0, 0x9C);
}

/* func_00010970 — 5 words. MATCH 100% (verified). */
s32 func_00010970(void) {
    extern s32 D_00090C08;
    return ehsys_memset(&D_00090C08, 0, 0x9C);
}

/* func_00010C20 — 7 words. MATCH 100% (shape: thunk). */
s32 func_00010C20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return ehsys_3BB2BAC6((arg0 << 6), (arg1 << 6), (arg2 << 6), (arg3 << 6), arg4, -0x1, 0);
}

/* func_00010FB4 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00010FB4(void) {
    return (*(s32 *)&D_00090C58);
}

/* func_00010FC0 — 12 words. MATCH 100% (shape: m2c). */
void *func_00010FC0(void) {
    return (&D_00077BE0)[func_00051770()];
}

/* func_00011060 — 5 words. MATCH 100% (verified). */
s32 func_00011060(void) {
    extern s32 D_00090CA4;
    return ehsys_memset(&D_00090CA4, 0, 0x74);
}

/* func_00011074 — 2 words. MATCH 100% (shape: m2c). */
void func_00011074(void) {

}

/* func_000117D0 — 8 words. MATCH 100% (shape: thunk). */
s32 func_000117D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_000117F0 — 5 words. MATCH 100% (shape: thunk). */
s32 func_000117F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_BC8E65D7((arg0 << 6), (arg1 << 6), (arg2 << 6), arg3, -0x1);
}

/* func_000119B0 — 6 words. MATCH 100% (shape: m2c). */
int func_000119B0(arg0) s32 arg0;
{
    return (s32)((&D_00090CB0)[arg0]);
}

/* func_00011C20 — 12 words. MATCH 100% (shape: m2c). */
void func_00011C20(s32 arg0, void **arg1, void **arg2) {
    *arg1 = (&D_00090CE4)[arg0];
    *arg2 = *(void **)(&D_00090CF4 + arg0 * 4);
}

/* func_00011C50 — 15 words. MATCH 100% (shape: m2c). */
s32 func_00011C50(void) {
    return ((*(s32 *)(&D_00090CF4 + func_00051210() * 4)) >= 0xF) & 0xFF;
}

/* func_0001388C — 17 words. MATCH 100% (shape: m2c). */
void func_0001388C(void) {
    func_00013A2C();
    func_00004FB8();
    func_00005F9C();
    func_00008494();
    func_0001095C();
    func_00011060();
}

/* func_000138D0 — 15 words. MATCH 100% (shape: m2c). */
void func_000138D0(void) {
    func_00013AA8();
    func_00005098();
    func_0000864C();
    func_00010970();
    func_00011074();
}
/* func_0001390C — 50 words. MATCH 100% (shape: m2c). */
void func_0001390C(void) {
    extern int ehsys_1D98951B();
    extern int ehsys_1EC5342B();
    extern int ehsys_399AC68A();
    extern int ehsys_42110BF9();
    extern int ehsys_C62F9EAC();
    extern int ehsys_DFCA450B();
    extern int func_000050DC();
    extern int func_00008790();
    extern int func_0001107C();
    extern int func_0001390C();
    extern int func_00013B30();
    extern int func_00050304();
    ehsys_1EC5342B(ehsys_C62F9EAC(ehsys_399AC68A(ehsys_42110BF9(ehsys_1D98951B(ehsys_DFCA450B(0, 0), 0), 0), 0), 0x17));
    if (func_00050304(1, -1) != 0) {
        func_00013B30();
    }
    if (func_00050304(2, -1) != 0) {
        func_00008790();
    }
    if (func_00050304(4, -1) != 0) {
        func_0001107C();
    }
    if (func_00050304(4, -1) != 0) {
        func_000050DC();
    }
}

/* func_00014038 — 10 words. MATCH 100% (shape: hand). */
s32 func_00014038(void) {
    return *(int *)(&D_00090D20 + (D_00090D70 * 0x28));
}

/* func_00014140 — 2 words. MATCH 100% (shape: hand). */
s32 func_00014140(arg0, arg1)
s32 arg0, arg1;
{
    return func_000142D8(arg0, arg1, 0);
}

/* func_00015304 — 4 words. MATCH 100% (shape: m2c). */
void func_00015304(void) {
    (*(s32 *)&D_00090ED4) = 1;
}

/* func_000154DC — 2 words. MATCH 100% (shape: m2c). */
void func_000154DC(void) {

}

/* func_000154E4 — 5 words. MATCH 100% (shape: thunk). */
s32 func_000154E4(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_memset(&D_00090F40, 0, 0xC);
}

/* func_00015540 — 15 words. MATCH 100% (shape: m2c). */
void func_00015540(void) {
    if ((*(s32 *)&D_00090F40) == 0) {
        func_00015880();
        return;
    }
    func_00015914();
}

/* func_00015B54 — 8 words. MATCH 100% (shape: m2c). */
void func_00015B54(s32 unused0, s32 arg1) {
    if (arg1 != 0) {
        func_0005369C(arg1);
    }
}

/* func_00015B74 — 10 words. MATCH 100% (shape: m2c). */
void func_00015B74(void) {
    s32 sp1C;

    func_000068A8(&sp1C);
    func_00015BF0((s16)sp1C, 0);
}

/* func_00016034 — 7 words. MATCH 100% (verified). */
void func_00016034(void) {
    extern s32 D_00090F44;
    s32 *p = *(s32 **)&D_00090F44;
    s32 *p2 = *(s32 **)((char *)p + 0x18);
    *(s32 *)((char *)p2 + 0x4C) = 0;
    D_00090F44 = 0;
}

/* func_00016050 — 2 words. MATCH 100% (shape: hand). */
void func_00016050(s32 arg0, s32 arg1) {
    func_0005369C(arg1);
}

/* func_000167CC — 12 words. MATCH 100% (shape: m2c). */
void *func_000167CC(void) {
    return (&D_00078210)[func_00051770()];
}

/* func_000167FC — 12 words. MATCH 100% (shape: m2c). */
void *func_000167FC(void) {
    return (&D_00078220)[func_00051770()];
}

/* func_00017C40 — 9 words. MATCH 100% (shape: m2c). */
void func_00017C40(s32 arg0) {
    if (arg0 != -1) {
        func_00031A08();
    }
}

/* func_00017D68 — 5 words. MATCH 100% (shape: thunk). */
s32 func_00017D68(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_memset(&D_000910CC, 0, 0x2C);
}

/* func_0001839C — 4 words. MATCH 100% (shape: m2c). */
s32 func_0001839C(void) {
    return (*(s32 *)&D_000910CC) != 0;
}

/* func_00018E3C — 15 words. MATCH 100% (shape: hand). */
void func_00018E3C(s32 arg0, s32 arg1) {
    ehsys_F292E199();
    ehsys_65DA0419(0x94D5);
    func_0005369C(arg1);
    D_000910CC = 0;
}
/* func_00019168 — 17 words. MATCH 100% (shape: lead-dummy1). */
void func_00019168(s32 unused0, void *arg1) {
    extern int func_00019168();
    extern int func_000194EC();
    u32 temp_v1;

    temp_v1 = (*(int *)((char *)arg1 + 0x1C)) + 1;
    (*(int *)((char *)arg1 + 0x1C)) = temp_v1;
    if (temp_v1 >= 0x2DU) {
        (*(int *)((char *)arg1 + 0x18)) = 0;
    }
    if ((*(int *)((char *)arg1 + 0x18)) == 0) {
        func_000194EC();
    }
}

/* func_000191AC — 9 words. MATCH 100% (shape: hand). */
void func_000191AC(s32 arg0, s32 arg1) {
    func_0005369C(arg1);
    D_000910CC = 0;
}

/* func_000194EC — 5 words. MATCH 100% (shape: m2c). */
int func_000194EC() {
    (*(s32 *)&D_00091114) = 1;
    return (s32)(0);
}

/* func_00019628 — 2 words. MATCH 100% (shape: m2c). */
void func_00019628(void) {

}

/* func_00019630 — 2 words. MATCH 100% (shape: m2c). */
void func_00019630(void) {
    func_0001CD08();
}

/* func_00019C38 — 3 words. MATCH 100% (shape: m2c). */
int func_00019C38(arg0) s32 arg0;
{
    (*(s32 *)&D_00091650) = arg0;
}

/* func_00019CF8 — 2 words. MATCH 100% (shape: m2c). */
void func_00019CF8(void) {
    func_0001CD08();
}

/* func_0001A1F4 — 2 words. MATCH 100% (shape: m2c). */
void func_0001A1F4(void) {
    func_0001CD08();
}
/* func_0001A864 — 17 words. MATCH 100% (shape: lead-dummy1). */
void func_0001A864(s32 unused0, s32 *arg1) {
    extern int func_0001A864();
    extern int func_000318A0();
    extern int func_0005369C();
    s32 temp_a0;

    temp_a0 = *arg1;
    if (temp_a0 != -1) {
        func_000318A0(temp_a0);
        *arg1 = -1;
    }
    func_0005369C(arg1);
}

/* func_0001A8A8 — 11 words. MATCH 100% (shape: m2c). */
void func_0001A8A8(void) {
    ehsys_4BF558F1(0x2C);
    ehsys_4BF558F1(0x2F);
    ehsys_4BF558F1(0x32);
}

/* func_0001ACE0 — 3 words. MATCH 100% (shape: m2c). */
void func_0001ACE0(s32 unused0) {
    func_0001A8E4(unused0, func_000204A0);
}
/* func_0001B220 — 26 words. MATCH 100% (shape: m2c). */
void func_0001B220(void) {
    extern int func_0001B094();
    extern int func_0001B1D8();
    extern int func_0001B220();
    extern int func_0006DE9C();
    extern int func_0006E1BC();
    if (func_0006DE9C() == 0) {
        if (func_0006E1BC(0, 0xC, 0) & 4) {
            func_0001B094();
            return;
        }
        func_0001B1D8();
        return;
    }
    func_0001B1D8();
}

/* func_0001B70C — 2 words. MATCH 100% (shape: hand). */
void func_0001B70C(s32 arg0, struct S1B70C *arg1) {
    ehsys_4BF558F1(arg1->f0C);
}
/* func_0001B714 — 27 words. MATCH 100% (shape: m2c). */
void func_0001B714(void *arg0) {
    extern int duel_eng_EEFFFE1B();
    extern int func_00019500();
    extern int func_0001B714();
    extern int func_0001BD44();
    extern int func_0001BD4C();
    extern int func_0002EF34();
    if ((duel_eng_EEFFFE1B((*(int *)((char *)arg0 + 0x4))) == 0x169C) && ((*(int *)((char *)arg0 + 0x0)) < 0x14)) {
        func_0002EF34((*(int *)((char *)arg0 + 0x0)), func_0001BD44, func_0001BD4C(0x25));
    }
    func_00019500((*(int *)((char *)arg0 + 0x8)));
}
/* func_0001BA0C — 22 words. MATCH 100% (shape: m2c). */
void func_0001BA0C(void) {
    extern int ehsys_4BF558F1();
    extern int func_000194EC();
    extern int func_0001BA0C();
    extern int func_00050304();
    extern int func_00050B68();
    extern int func_00050C70();
    ehsys_4BF558F1(0x27);
    if ((func_00050B68() == 0) && (func_00050C70() == 0) && (func_00050304(0x100, -1) == 0)) {
        func_000194EC();
    }
}

/* func_0001BD3C — 2 words. MATCH 100% (shape: hand). */
void func_0001BD3C(s32 arg0, struct S1BD3C *arg1) {
    ehsys_4BF558F1(arg1->f00);
}

/* func_0001BD44 — 2 words. MATCH 100% (shape: m2c). */
int func_0001BD44() {
    func_00019500();
}
/* func_0001BFC4 — 15 words. MATCH 100% (shape: m2c). */
void func_0001BFC4(void *arg0) {
    extern int func_000119C8();
    extern int func_00019500();
    extern int func_0001BFC4();
    extern int func_0005369C();
    func_00019500((*(int *)((char *)arg0 + 0x0)));
    func_000119C8((*(int *)((char *)arg0 + 0x4)), (*(int *)((char *)arg0 + 0x8)));
    func_0005369C(arg0);
}
/* func_0001C138 — 17 words. MATCH 100% (shape: m2c). */
void func_0001C138(void *arg0) {
    extern int func_0000B464();
    extern int func_00019500();
    extern int func_0001C138();
    extern int func_0001D1F0();
    extern int func_0005369C();
    func_0000B464((*(int *)((char *)arg0 + 0x4)), 1);
    func_00019500((*(int *)((char *)arg0 + 0x0)));
    func_0005369C(arg0);
    func_0001D1F0(0);
}

/* func_0001C2C8 — 12 words. MATCH 100% (shape: m2c). */
void func_0001C2C8(s32 arg0) {
    func_00051648(-1);
    func_0001BD44(arg0);
}

/* func_0001C500 — 2 words. MATCH 100% (shape: m2c). */
void func_0001C500(void) {
    func_0001CD08();
}
/* func_0001C820 — 30 words. MATCH 100% (shape: m2c). */
void func_0001C820(s32 arg0, s32 arg1) {
    extern int func_0001BD44();
    extern int func_0001BD4C();
    extern int func_0001C820();
    extern int func_0002E07C();
    extern int func_00051184();
    extern int func_00055E34();
    extern int func_00056E78();
    if (arg1 != 0) {
        if ((func_00051184() != 0) && (arg0 == 4)) {
            func_00056E78(0x1468);
            func_00055E34(0xB);
        }
    } else {
        func_0002E07C(arg0 + 1, 0, func_0001BD44, func_0001BD4C(0x40));
    }
}

/* func_0001C898 — 14 words. MATCH 100% (shape: hand). */
void func_0001C898(s32 arg0, s32 arg1) {
    if (func_0002EEDC(arg1) != 0) {
        func_000194EC();
    }
    ehsys_4BF558F1(0x3F);
}

/* func_0001C930 — 14 words. MATCH 100% (shape: hand). */
void func_0001C930(s32 arg0, s32 arg1) {
    if (func_000232A4(arg1) != 0) {
        func_000194EC();
    }
    ehsys_4BF558F1(0x3E);
}

/* func_0001CA54 — 3 words. MATCH 100% (shape: m2c). */
s32 func_0001CA54(void) {
    return (*(s32 *)&D_00091648);
}

/* func_0001CAB8 — 4 words. MATCH 100% (shape: m2c). */
void func_0001CAB8(s32 *arg0) {
    ((s32 *)arg0[6])[3] = 1;
}

/* func_0001CC70 — 10 words. MATCH 100% (shape: m2c). */
int func_0001CC70() {
    func_00031A08((*(s32 *)&D_0009164C));
    (*(s32 *)&D_0009164C) = 0;
}

/* func_0001CC98 — 4 words. MATCH 100% (shape: m2c). */
int func_0001CC98() {
    return (s32)((*(s32 *)&D_0009164C) != 0);
}

/* func_0001CCA8 — 12 words. MATCH 100% (shape: m2c). */
void func_0001CCA8(s32 arg0) {
    if ((*(s32 *)&D_0009164C) != 0) {
        func_0003066C((*(s32 *)&D_0009164C), arg0);
    }
}

/* func_0001CCD8 — 12 words. MATCH 100% (shape: m2c). */
void func_0001CCD8(s32 arg0) {
    if ((*(s32 *)&D_0009164C) != 0) {
        func_00030694((*(s32 *)&D_0009164C), arg0);
    }
}

/* func_0001CD50 — 3 words. MATCH 100% (shape: m2c). */
void func_0001CD50(s32 *arg0) {
    arg0[0x26] = -1;
}
/* func_0001D1F0 — 9 words. MATCH 100% (verified). */
void func_0001D1F0(s32 arg0) {
    extern s32 D_000910F8;
    char *a1 = (char *)&D_000910F8;
    if (arg0 != 0) {
        *(s32 *)(a1 + 0x550) = 1;
    } else {
        *(s32 *)(a1 + 0x550) = 0;
    }
}

/* func_0001D214 — 21 words. MATCH 100% (shape: m2c). */
void func_0001D214(void) {
    extern int func_00005720();
    extern int func_0001D214();
    extern int func_000536B8();
    extern int func_00058A68();
    extern int func_0005909C();
    extern int func_000590D0();
    extern int func_00059440();
    func_00058A68(func_000536B8(5), 2, 1, 0);
    func_00059440(0);
    func_0005909C(0, 0x64);
    func_000590D0();
    func_00005720(1);
}

/* func_0001D2E8 — 12 words. MATCH 100% (shape: m2c). */
void func_0001D2E8(void) {
    ehsys_memset(&D_00091654, 0, 4);
    func_0001D428(1);
}

/* func_0001D318 — 5 words. MATCH 100% (shape: thunk). */
s32 func_0001D318(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_memset(&D_00091654, 0, 0x4);
}

/* func_0001D428 — 3 words. MATCH 100% (shape: m2c). */
int func_0001D428(arg0) s32 arg0;
{
    (*(s32 *)&D_00091654) = arg0;
}
/* func_00021ACC — 8 words. MATCH 100% (shape: m2c). */
void *func_00021ACC(void *arg0, void *arg1) {
    extern int func_00021ACC();
    (*(int *)((char *)arg0 + 0x0)) = (s32) (*(int *)((char *)arg1 + 0x0));
    (*(int *)((char *)arg0 + 0x4)) = (s32) (*(int *)((char *)arg1 + 0x4));
    (*(int *)((char *)arg0 + 0x8)) = (s32) (*(int *)((char *)arg1 + 0x8));
    return arg0;
}

/* func_0002EEC4 — 6 words. MATCH 100% (verified). */
typedef struct { f32 a, b; } V2_EEC4;
void *func_0002EEC4(V2_EEC4 *arg0, V2_EEC4 *arg1) {
    arg0->a = arg1->a;
    arg0->b = arg1->b;
    return arg0;
}

/* func_0003159C — 14 words. MATCH 100% (shape: m2c). */
void func_0003159C(void) {
    ehsys_memset(&D_000916B0, 0, 0x20F0);
    func_0001D620();
    func_00038D50();
}

/* func_00031A08 — 2 words. MATCH 100% (shape: hand). */
s32 func_00031A08(arg0)
s32 arg0;
{
    func_0003199C(arg0, 1);
}

/* func_00031BD0 — 17 words. MATCH 100% (shape: m2c). */
void func_00031BD0(void) {
    func_00031A10(1);
    func_00031A10(2);
    func_00031A10(3);
    func_00031A10(5);
    func_00031A10(7);
    func_00031A10(8);
}

/* func_000320B0 — 13 words. MATCH 100% (shape: m2c). */
void func_000320B0(s32 arg0, int arg1) {
    ehsys_9EA6989A(arg0, func_00031FA0(arg1));
}

/* func_000325FC — 18 words. MATCH 100% (shape: m2c). */
void func_000325FC(int unused0, int arg1) {
    ehsys_1EC5342B(ehsys_C62F9EAC(ehsys_399AC68A(ehsys_DFCA450B(unused0, 0), arg1), 0x14));
}

/* func_00032644 — 19 words. MATCH 100% (shape: m2c). */
void func_00032644(int unused0, int arg1, int arg2) {
    ehsys_1EC5342B(ehsys_B56890DA(ehsys_DFCA450B(unused0, 0), arg1, arg2));
}

/* func_0003271C — 10 words. MATCH 100% (verified). */
s32 func_0003271C(s32 arg0) {
    extern int ehsys_E47E40E4();
    s32 temp_v0;

    temp_v0 = ehsys_E47E40E4();
    return temp_v0 + arg0;
}

/* func_000327C8 — 12 words. MATCH 100% (shape: m2c). */
void func_000327C8(s32 arg0) {
    func_00032744(arg0, func_00002548());
}
/* func_00032B64 — 29 words. MATCH 100% (shape: m2c). */
void func_00032B64(void) {
    extern int ehsys_4F22C9AA();
    extern int ehsys_9EFDC9B9();
    extern int ehsys_F2BD0694();
    extern int func_00032B64();
    ehsys_4F22C9AA(0);
    ehsys_F2BD0694();
    ehsys_9EFDC9B9();
    ehsys_4F22C9AA(1);
    ehsys_F2BD0694();
    ehsys_9EFDC9B9();
    ehsys_4F22C9AA(3);
    ehsys_F2BD0694();
    ehsys_9EFDC9B9();
    ehsys_4F22C9AA(2);
    ehsys_F2BD0694();
    ehsys_9EFDC9B9();
}
/* func_00032BD8 — 21 words. MATCH 100% (shape: m2c). */
void func_00032BD8(void) {
    extern int ehsys_4F22C9AA();
    extern int ehsys_F8CDBCAB();
    extern int func_00032BD8();
    ehsys_4F22C9AA(0);
    ehsys_F8CDBCAB();
    ehsys_4F22C9AA(1);
    ehsys_F8CDBCAB();
    ehsys_4F22C9AA(3);
    ehsys_F8CDBCAB();
    ehsys_4F22C9AA(2);
    ehsys_F8CDBCAB();
}
/* func_00032CA8 — 33 words. MATCH 100% (shape: m2c). */
void func_00032CA8(void) {
    extern char D_00093690;
    extern char D_000936D0;
    extern char D_00093710;
    extern char D_00093750;
    extern int ehsys_4F22C9AA();
    extern int ehsys_EF9740B0();
    extern int ehsys_F2BD0694();
    extern int func_00032CA8();
    ehsys_4F22C9AA(0);
    ehsys_F2BD0694();
    ehsys_EF9740B0(&D_00093690);
    ehsys_4F22C9AA(1);
    ehsys_F2BD0694();
    ehsys_EF9740B0(&D_000936D0);
    ehsys_4F22C9AA(3);
    ehsys_F2BD0694();
    ehsys_EF9740B0(&D_00093710);
    ehsys_4F22C9AA(2);
    ehsys_F2BD0694();
    ehsys_EF9740B0(&D_00093750);
}
/* func_00032D2C — 33 words. MATCH 100% (shape: m2c). */
void func_00032D2C(void) {
    extern int ehsys_4F22C9AA();
    extern int ehsys_9EFDC9B9();
    extern int ehsys_EF9740B0();
    extern int ehsys_F2BD0694();
    extern int func_00002538();
    extern int func_00002548();
    extern int func_00032D2C();
    ehsys_4F22C9AA(0);
    ehsys_F2BD0694();
    ehsys_EF9740B0(func_00002538());
    ehsys_4F22C9AA(1);
    ehsys_F2BD0694();
    ehsys_EF9740B0(func_00002548());
    ehsys_4F22C9AA(3);
    ehsys_F2BD0694();
    ehsys_9EFDC9B9();
    ehsys_4F22C9AA(2);
    ehsys_F2BD0694();
    ehsys_9EFDC9B9();
}

/* func_00032EB4 — 13 words. MATCH 100% (shape: m2c). */
f32 func_00032EB4(s32 arg0, s32 arg1) {
    s32 var_a0;

    var_a0 = arg0;
    if (var_a0 < 0) {
        var_a0 = 0;
    }
    if (arg1 < var_a0) {
        var_a0 = arg1;
    }
    return (f32) var_a0 / (f32) arg1;
}

/* func_00032F10 — 11 words. MATCH 100% (verified). */
f32 func_00032F10(s32 arg0, s32 arg1, s32 arg2) {
    s32 diff = arg2 - arg1;
    f32 v0 = func_00032EB4(arg0 - diff, arg1);
    return 1.0f - v0;
}

/* func_00033094 — 4 words. MATCH 100% (shape: thunk). */
s32 func_00033094(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_00032FDC((arg0 - (arg2 - arg1)), arg1, arg3, arg3);
}

/* func_00033258 — 13 words. MATCH 100% (shape: m2c). */
s32 func_00033258(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_v0;

    var_v0 = arg0 + arg1;
    if (arg1 >= 0) {
        if (arg2 < var_v0) {
            goto block_4;
        }
    } else if (var_v0 < arg2) {
block_4:
        var_v0 = arg2;
    }
    return var_v0;
}
/* func_00033420 — 5 words. MATCH 100% (verified). */
int func_00033420(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 *p = (s32 *)arg0;
    *arg1 = p[0];
    *arg2 = p[1];
}

/* func_00039128 — 0 words. MATCH 100% (shape: twin of func_00007BB4). */
void func_00039128(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {

    s32 *p = *(s32 **)((char *)arg0 + 0x108);
    if (p != 0) {
        *(s32 *)((char *)p + 4) = arg4;
    }
}

/* func_00039140 — 2 words. MATCH 100% (shape: m2c). */
void func_00039140(void) {

}

/* func_00039148 — 2 words. MATCH 100% (shape: m2c). */
void func_00039148(void) {

}

/* func_00039150 — 2 words. MATCH 100% (shape: m2c). */
void func_00039150(void) {

}
/* func_00039284 — 0 words. MATCH 100% (shape: twin of func_00007D10). */
void func_00039284(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {

    s32 *p = *(s32 **)((char *)arg0 + 0x110);
    if (p != 0) {
        *(s32 *)((char *)p + 4) = arg4;
    }
}

/* func_0003D878 — 3 words. MATCH 100% (shape: m2c). */
void func_0003D878(s32 arg0) {
    (*(s32 *)&D_000937A0) = arg0;
}

/* func_0003DAEC — 3 words. MATCH 100% (shape: thunk). */
s32 func_0003DAEC(s32 arg0, s32 arg1, s32 arg2) {
    return func_00031EC8(arg0, 0, 0x1);
}

/* func_0003DAF8 — 2 words. MATCH 100% (shape: m2c). */
void func_0003DAF8(void) {

}

/* func_0003DB00 — 2 words. MATCH 100% (shape: m2c). */
void func_0003DB00(void) {

}

/* func_00045180 — 9 words. MATCH 100% (shape: m2c). */
s32 func_00045180(s32 unused0) {
    int sp1C;
    int sp18;

    func_00033420(unused0, &sp1C, &sp18);
    return 0;
}

/* func_000451A4 — 18 words. MATCH 100% (verified). */
extern s32 func_000452B8(s32, s32, s32);
extern s32 func_00045F9C(s32, s32, s32);
s32 func_000451A4(int arg0, s32 arg1, int arg2, int arg3) {
    switch (arg1) {
    case 0:
        return func_000452B8(arg0, arg2, arg3);
    case 1:
        return func_00045F9C(arg0, arg2, arg3);
    default:
        return -1;
    }
}

/* func_00047030 — 3 words. MATCH 100% (shape: m2c). */
void func_00047030(s32 arg0) {
    (*(s32 *)&D_000937A4) = arg0;
}

/* func_000483E4 — 3 words. MATCH 100% (shape: m2c). */
void func_000483E4(s32 arg0) {
    (*(s32 *)&D_000937A8) = arg0;
}

/* func_0004C4A4 — 13 words. MATCH 100% (shape: m2c). */
void func_0004C4A4(void) {
    ehsys_memset(&D_000938C4, 0, 0x208);
    (*(s32 *)&D_000938C8) = 1;
}

/* func_0004C4D8 — 2 words. MATCH 100% (shape: m2c). */
void func_0004C4D8(void) {

}

/* func_0004C798 — 4 words. MATCH 100% (shape: m2c). */
s32 func_0004C798(s32 *arg0, s32 *arg1) {
    return *arg0 - *arg1;
}

/* func_0004CF98 — 8 words. MATCH 100% (shape: m2c). */
s32 func_0004CF98(void) {
    func_00013F94();
    return 1;
}

/* func_0004CFB8 — 18 words. MATCH 100% (shape: m2c). */
s32 func_0004CFB8(int unused0, int arg1, int arg2) {
    func_000066E4(func_0006DE5C(), arg1, arg2, 0);
    return 1;
}

/* func_0004D000 — 2 words. MATCH 100% (shape: m2c). */
s32 func_0004D000(void) {
    return 1;
}

/* func_0004D008 — 14 words. MATCH 100% (shape: m2c). */
s32 func_0004D008(void) {
    func_00004EFC(func_0006DE5C());
    func_0001557C();
    func_0000568C(0);
    return 1;
}

/* func_0004D040 — 2 words. MATCH 100% (shape: m2c). */
s32 func_0004D040(void) {
    return 1;
}

/* func_0004D43C — 17 words. MATCH 100% (shape: m2c). */
s32 func_0004D43C(void) {
    func_0000B4D4(1);
    func_0001C508(0xD, func_0000B668, 0);
    func_00004F88(0x46);
    func_0001557C();
    return 1;
}

/* func_0004D480 — 8 words. MATCH 100% (shape: m2c). */
s32 func_0004D480(void) {
    func_0001D428(0);
    return 1;
}
/* func_0004D530 — 15 words. MATCH 100% (shape: lead-dummy1). */
s32 func_0004D530(s32 unused0, int arg1, s32 arg2) {
    extern int func_0001C000();
    extern int func_0004D530();
    extern int func_0006DE5C();
    if (arg2 == 0) {
        func_0001C000(func_0006DE5C(), arg1);
    }
    return 1;
}

/* func_0004D56C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0004D56C(void) {
    return 1;
}

/* func_0004D574 — 10 words. MATCH 100% (shape: m2c). */
s32 func_0004D574(void) {
    func_0001B2E8(func_0006DE5C());
    return 1;
}

/* func_0004D62C — 17 words. MATCH 100% (shape: m2c). */
s32 func_0004D62C(int unused0, int arg1, int arg2) {
    func_0000B00C(func_0006DE5C(), arg1, arg2);
    return 1;
}

/* func_0004D670 — 10 words. MATCH 100% (shape: m2c). */
s32 func_0004D670(void) {
    func_0001C1DC(func_0006DE5C());
    return 1;
}

/* func_0004D698 — 13 words. MATCH 100% (shape: hand). */
s32 func_0004D698(s32 arg0, s32 arg1) {
    func_00009F80(func_0006DE5C(), arg1);
    return 1;
}

/* func_0004D6CC — 13 words. MATCH 100% (shape: hand). */
s32 func_0004D6CC(s32 arg0, s32 arg1) {
    func_00008E04(func_0006DE5C(), arg1);
    return 1;
}

/* func_0004D700 — 17 words. MATCH 100% (shape: m2c). */
s32 func_0004D700(int unused0, int arg1, int arg2) {
    func_00009054(func_0006DE5C(), arg1, arg2);
    return 1;
}

/* func_0004DC3C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0004DC3C(void) {
    return 1;
}

/* func_0004DD14 — 2 words. MATCH 100% (shape: m2c). */
s32 func_0004DD14(void) {
    return 1;
}
/* func_0004DD1C — 29 words. MATCH 100% (shape: lead-dummy1). */
s32 func_0004DD1C(s32 unused0, s32 arg1, int arg2, int arg3) {
    extern int func_00009E9C();
    extern int func_0001B90C();
    extern int func_0004DD1C();
    extern int func_0006DE5C();
    s32 var_v0;

    if (arg1 == 0x10) {
        var_v0 = 0;
    } else {
        var_v0 = func_00009E9C(func_0006DE5C(), arg1, 0);
    }
    func_0001B90C(var_v0, arg2, arg3);
    return 1;
}

/* func_0004DEC0 — 13 words. MATCH 100% (shape: hand). */
s32 func_0004DEC0(s32 arg0, s32 arg1) {
    func_0001B3D4(func_0006DE5C(), arg1);
    return 1;
}

/* func_0004DF50 — 8 words. MATCH 100% (shape: m2c). */
s32 func_0004DF50(void) {
    func_0001A7CC();
    return 1;
}

/* func_0004E04C — 8 words. MATCH 100% (shape: m2c). */
s32 func_0004E04C(void) {
    func_0001AFFC();
    return 1;
}

/* func_0004E168 — 8 words. MATCH 100% (shape: m2c). */
s32 func_0004E168(void) {
    func_0001AFFC();
    return 1;
}

/* func_0004E54C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0004E54C(void) {
    return 1;
}

/* func_0004F260 — 8 words. MATCH 100% (shape: hand). */
s32 func_0004F260(s32 arg0) {
    func_00005460(arg0, 0);
    return 1;
}

/* func_0004F2F4 — 13 words. MATCH 100% (shape: hand). */
s32 func_0004F2F4(s32 arg0, s32 arg1, s32 arg2) {
    func_0001C424(func_0006DE5C(), arg2);
    return 1;
}

/* func_0004F328 — 9 words. MATCH 100% (shape: hand). */
s32 func_0004F328(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_0001C9D8();
    }
    return 1;
}

/* func_0004F34C — 14 words. MATCH 100% (shape: m2c). */
int func_0004F34C() {
    if (func_00051184() != 0) {
        func_00056E78(0xFBB);
        func_00055E34(0xB);
    }
    return (s32)(1);
}

/* func_0004F384 — 18 words. MATCH 100% (shape: m2c). */
s32 func_0004F384(s32 unused0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 7:
        return func_0004F3F0();
    case 3:
        return func_0004F34C();
    default:
        return 1;
    }
}
/* func_0004F3CC — 9 words. MATCH 100% (shape: lead-dummy2). */
s32 func_0004F3CC(s32 unused0, s32 unused1, int arg2, int arg3) {
    extern int func_0001C820();
    extern int func_0004F3CC();
    func_0001C820(arg2, arg3);
    return 1;
}

/* func_0004F3F0 — 8 words. MATCH 100% (shape: m2c). */
int func_0004F3F0() {
    func_0001C8D0();
    return (s32)(1);
}

/* func_0004F410 — 18 words. MATCH 100% (shape: single-switch). */
s32 func_0004F410(s32 arg0) {
    if ((arg0 != 2) && (arg0 != 1)) {

        switch (arg0) {
        case 0:
            func_0001C508(0x41, func_00056310, 1);
            break;
        }
    }
    return 1;
}

/* func_0004F4B8 — 16 words. MATCH 100% (shape: m2c). */
s32 func_0004F4B8(void) {
    if (func_0001CC98() != 0) {
        duel_eng_9081141C();
        duel_eng_1256A810();
        func_0001CC70();
    }
    return 1;
}

/* func_0004F534 — 10 words. MATCH 100% (shape: m2c). */
s32 func_0004F534(void) {
    func_0001BF28(func_0006DE5C());
    return 1;
}

/* func_0004F61C — 16 words. MATCH 100% (shape: m2c). */
void func_0004F61C(void) {
    func_0005FBE8();
    func_00001EBC();
    func_00051958();
    ehsys_EBD1986B(0, 0);
    func_00053680();
}
/* func_0004F930 — 23 words. MATCH 100% (shape: m2c). */
void func_0004F930(void) {
    extern int func_00001EBC();
    extern int func_000138D0();
    extern int func_0001927C();
    extern int func_0004C4D8();
    extern int func_0004F930();
    extern int func_00050A48();
    extern int func_00050D60();
    extern int func_000519AC();
    extern int func_00055D58();
    extern int func_0005FC1C();
    func_00050A48();
    func_00055D58();
    func_0001927C();
    func_0004C4D8();
    func_00001EBC();
    func_0005FC1C();
    func_00050D60();
    func_000138D0();
    func_000519AC();
}

/* func_0004FAD8 — 9 words. MATCH 100% (verified). */
void func_0004FAD8(s32 *arg0, s32 arg1) {
    extern s32 D_00093B8C;
    extern s32 D_00093B90;
    extern s32 D_00093B94;
    D_00093B8C = arg0[0];
    D_00093B90 = arg0[1];
    D_00093B94 = arg1;
}

/* func_0004FC58 — 4 words. MATCH 100% (shape: m2c). */
s32 func_0004FC58(void) {
    (*(s32 *)&D_00093AF8) = 0;
    return 1;
}

/* func_0004FC68 — 9 words. MATCH 100% (shape: m2c). */
void func_0004FC68(void) {
    func_00001EBC();
    func_000527C8();
}

/* func_0004FC8C — 2 words. MATCH 100% (shape: m2c). */
void func_0004FC8C(void) {

}

/* func_0004FC94 — 11 words. MATCH 100% (shape: m2c). */
int func_0004FC94() {
    if ((*(s32 *)&D_00093AF8) != 0) {
        func_0005062C();
    }
}

/* func_0004FCC0 — 2 words. MATCH 100% (shape: m2c). */
void func_0004FCC0(void) {
    func_00051678();
}

/* func_0004FCC8 — 13 words. MATCH 100% (shape: m2c). */
s32 func_0004FCC8(void) {
    func_000539AC();
    func_0005086C();
    func_000560BC();
    return (*(s32 *)&D_00093AFC);
}

/* func_0004FCFC — 20 words. MATCH 100% (shape: m2c). */
void func_0004FCFC(int unused0, int arg1, int arg2, int arg3) {
    func_0005577C(func_0006DE5C(), arg1, arg2, arg3);
}

/* func_0004FD5C — 2 words. MATCH 100% (shape: m2c). */
void func_0004FD5C(void) {
    func_00053B3C();
}

/* func_0004FDB4 — 2 words. MATCH 100% (shape: m2c). */
void func_0004FDB4(void) {
    func_000633C8();
}

/* func_0004FDBC — 2 words. MATCH 100% (shape: m2c). */
void func_0004FDBC(void) {
    func_00058B0C();
}

/* func_0004FDFC — 17 words. MATCH 100% (shape: m2c). */
void func_0004FDFC(int unused0, int arg1, int arg2) {
    func_000066E4(func_0006DE5C(), arg1, arg2, 0);
}

/* func_0004FF90 — 2 words. MATCH 100% (shape: m2c). */
void func_0004FF90(void) {
    func_000054B4();
}

/* func_0004FF98 — 2 words. MATCH 100% (shape: hand). */
void func_0004FF98(s32 arg0) {
    func_00005460(arg0, 0);
}

/* func_0004FFA0 — 15 words. MATCH 100% (shape: m2c). */
void func_0004FFA0(void) {
    func_00011A00(func_0006DE9C(), 1);
    func_00011A2C(duel_eng_3B0C99E7(), 1);
}

/* func_0004FFDC — 2 words. MATCH 100% (shape: m2c). */
void func_0004FFDC(void) {
    func_0006E0DC();
}

/* func_0004FFE4 — 2 words. MATCH 100% (shape: m2c). */
void func_0004FFE4(void) {
    func_0006DF74();
}

/* func_0004FFEC — 11 words. MATCH 100% (verified). */
extern s32 func_00009E9C(s32, s32, s32);
s32 func_0004FFEC(s32 arg0, s32 arg1) {
    s32 *v0 = (s32 *)func_00009E9C(arg0, 0xB, arg1);
    if (v0 == 0) {
        return -1;
    }
    return *(u16 *)((char *)v0 + 0x80);
}

/* func_00050018 — 2 words. MATCH 100% (shape: m2c). */
void func_00050018(void) {
    func_00058FDC();
}

/* func_00050020 — 3 words. MATCH 100% (verified). */
extern s32 func_00051EE4(s32);
s32 func_00050020(void) {
    return func_00051EE4(0x80001);
}

/* func_000502C4 — 2 words. MATCH 100% (shape: m2c). */
void func_000502C4(void) {
    func_0000B3E8();
}

/* func_000502CC — 2 words. MATCH 100% (shape: m2c). */
void func_000502CC(void) {
    func_00011B24();
}

/* func_000502D4 — 2 words. MATCH 100% (shape: m2c). */
void func_000502D4(void) {
    func_0001CBD8();
}

/* func_000502DC — 2 words. MATCH 100% (shape: m2c). */
void func_000502DC(void) {
    func_0006DD1C();
}

/* func_000502E4 — 2 words. MATCH 100% (shape: m2c). */
void func_000502E4(void) {
    func_0006DD28();
}

/* func_000502EC — 2 words. MATCH 100% (shape: m2c). */
void func_000502EC(void) {
    func_0005163C();
}

/* func_000502F4 — 2 words. MATCH 100% (shape: m2c). */
void func_000502F4(void) {
    func_00050E34();
}

/* func_000502FC — 2 words. MATCH 100% (shape: m2c). */
void func_000502FC(void) {
    func_00019C38();
}

/* func_0005034C — 8 words. MATCH 100% (shape: m2c). */
void *func_0005034C(s32 arg0) {
    return &D_00093AF8 + (arg0 * 0x60) + 0x3A0;
}

/* func_0005054C — 11 words. MATCH 100% (shape: m2c). */
void func_0005054C(void) {
    func_00051958();
    func_00053680();
    func_00050600();
}

/* func_00050578 — 9 words. MATCH 100% (shape: m2c). */
void func_00050578(void) {
    func_0004FC8C();
    func_0004FC94();
}

/* func_000505F8 — 2 words. MATCH 100% (shape: m2c). */
void func_000505F8(void) {

}

/* func_00050600 — 11 words. MATCH 100% (shape: m2c). */
int func_00050600() {
    ehsys_D767C29F((*(s32 *)&D_00093B04));
    (*(s32 *)&D_00093B04) = -1;
}

/* func_0005086C — 2 words. MATCH 100% (shape: m2c). */
int func_0005086C() {
    ehsys_F5E3080C();
}

/* func_00050918 — 6 words. MATCH 100% (shape: m2c). */
void *func_00050918(s32 arg0) {
    return (&D_00093B0C)[arg0];
}
/* func_00050988 — 25 words. MATCH 100% (shape: m2c). */
s32 func_00050988(s32 arg0) {
    extern int func_00050918();
    extern int func_00050930();
    extern int func_00050988();
    extern int func_00050D68();
    s32 temp_s0;
    s32 var_s1;

    var_s1 = 0;
    if (func_00050D68() != 0) {
        temp_s0 = arg0 * 2;
        var_s1 = func_00050918(temp_s0);
        if (var_s1 == 1) {
            var_s1 = func_00050930(temp_s0 + 1);
        }
    }
    return var_s1;
}

/* func_00050A48 — 5 words. MATCH 100% (shape: thunk). */
s32 func_00050A48(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_memset(&D_00094020, 0, 0xC0);
}
/* func_00050A5C — 21 words. MATCH 100% (shape: m2c). */
void func_00050A5C(s32 arg0) {
    extern char D_00094020;
    extern int ehsys_4F22C9AA();
    extern int ehsys_5739D1F8();
    extern int ehsys_7ABC8184();
    extern int func_00050A5C();
    s32 temp_s0;

    temp_s0 = ehsys_7ABC8184();
    ehsys_4F22C9AA(1);
    ehsys_5739D1F8(&D_00094020 + (arg0 << 6));
    ehsys_4F22C9AA(temp_s0);
}

/* func_00050B68 — 3 words. MATCH 100% (shape: thunk). */
s32 func_00050B68(s32 arg0, s32 arg1) {
    return func_00050304(0x8, -0x1);
}

/* func_00050BB8 — 2 words. MATCH 100% (shape: m2c). */
void func_00050BB8(void) {

}
/* func_00050BC0 — 23 words. MATCH 100% (shape: m2c). */
void func_00050BC0(s32 arg0, int arg1, int arg2) {
    extern int func_000021D0();
    extern int func_0000225C();
    extern int func_000022A0();
    extern int func_00050BC0();
    extern int func_00051184();
    if (func_00051184() != 0) {
        func_000021D0(arg0);
        func_0000225C(arg2);
        func_000022A0(arg1);
    }
}

/* func_00050C4C — 3 words. MATCH 100% (shape: thunk). */
s32 func_00050C4C(s32 arg0, s32 arg1) {
    return func_00050304(0x100, arg0);
}

/* func_00050C58 — 2 words. MATCH 100% (shape: m2c). */
void func_00050C58(void) {
    func_00002320();
}

/* func_00050C60 — 2 words. MATCH 100% (shape: m2c). */
void func_00050C60(void) {
    func_00002354();
}

/* func_00050C68 — 2 words. MATCH 100% (shape: m2c). */
void func_00050C68(void) {
    func_0000246C();
}

/* func_00050C70 — 2 words. MATCH 100% (shape: m2c). */
void func_00050C70(void) {
    func_00002478();
}

/* func_00050D18 — 18 words. MATCH 100% (shape: m2c). */
void func_00050D18(s32 arg0) {
    ehsys_memset(&D_000940E0, 0, 0x50);
    (*(s32 *)&D_000940E4) = arg0;
    (*(s32 *)&D_000940F8) = -1;
}

/* func_00050D60 — 2 words. MATCH 100% (shape: m2c). */
void func_00050D60(void) {

}

/* func_00050D68 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00050D68(void) {
    return (*(s32 *)&D_000940E0);
}

/* func_00050D74 — 3 words. MATCH 100% (shape: m2c). */
void func_00050D74(s32 arg0) {
    (*(s32 *)&D_000940E0) = arg0;
}

/* func_00050D80 — 10 words. MATCH 100% (verified). */
extern void *ehsys_88B6C7F0(void);
u8 func_00050D80(void) {
    void *v0 = ehsys_88B6C7F0();
    u8 b = *(u8 *)((char *)v0 + 0xD5);
    return (b ^ 2) != 0;
}

/* func_00050F20 — 14 words. MATCH 100% (shape: m2c). */
s32 func_00050F20(void) {
    if (func_00050E34() != 0) {
        return 0;
    }
    return func_0006DE9C() != 0;
}

/* func_00050F58 — 2 words. MATCH 100% (shape: m2c). */
void func_00050F58(void) {
    func_000119B0();
}

/* func_00050F98 — 8 words. MATCH 100% (shape: m2c). */
s32 func_00050F98(void) {
    return duel_eng_0F848AB5() + 1;
}

/* func_00051064 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00051064(void) {
    return (*(s32 *)&D_000940FC);
}

/* func_00051070 — 3 words. MATCH 100% (shape: m2c). */
void func_00051070(s32 arg0) {
    (*(s32 *)&D_000940FC) = arg0;
}

/* func_00051150 — 3 words. MATCH 100% (shape: m2c). */
void func_00051150(s32 arg0) {
    (*(s32 *)&D_0009412C) = arg0;
}

/* func_00051630 — 3 words. MATCH 100% (shape: m2c). */
int func_00051630(arg0) s32 arg0;
{
    (*(s32 *)&D_000940F4) = arg0;
}

/* func_0005115C — 10 words. MATCH 100% (verified). */
u8 func_0005115C(void) {
    void *v0 = ehsys_88B6C7F0();
    u8 b = *(u8 *)((char *)v0 + 0xD4);
    return b == 2;
}

/* func_00051600 — 6 words. MATCH 100% (verified). */
u8 func_00051600(void) {
    extern s32 D_00094108;
    return !D_00094108;
}

/* func_0005163C — 3 words. MATCH 100% (shape: m2c). */
int func_0005163C() {
    return (s32)((*(s32 *)&D_000940F4));
}

/* func_00051648 — 3 words. MATCH 100% (shape: m2c). */
int func_00051648(arg0) s32 arg0;
{
    (*(s32 *)&D_000940F8) = arg0;
}

/* func_00051654 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00051654(void) {
    return (*(s32 *)&D_000940F8);
}

/* func_00051660 — 6 words. MATCH 100% (shape: m2c). */
void *func_00051660(s32 arg0) {
    return (&D_0009410C)[arg0];
}

/* func_00051760 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00051760(void) {
    return -1;
}

/* func_00051768 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00051768(void) {
    return 0;
}

/* func_000517F4 — 12 words. MATCH 100% (shape: m2c). */
void *func_000517F4(void) {
    return (&D_00094124)[func_0006DE7C()];
}

/* func_0005185C — 9 words. MATCH 100% (shape: m2c). */
void func_0005185C(void) {
    duel_eng_70F7713B(func_0006DE7C());
}

/* func_00051880 — 9 words. MATCH 100% (shape: m2c). */
void func_00051880(void) {
    duel_eng_E8754761(func_0006DE7C());
}

/* func_000518A4 — 12 words. MATCH 100% (shape: hand). */
void func_000518A4(s32 arg0, s32 arg1) {
    duel_eng_A5CC5331(func_0006DE7C(), arg1);
}
/* func_000518D4 — 33 words. MATCH 100% (shape: m2c). */
void func_000518D4(void) {
    extern int D_00079408;
    extern int D_00079804;
    extern int D_00079B60;
    extern int D_00079ED0;
    extern int ehsys_qsort();
    extern int func_000518D4();
    extern int func_00052CAC();
    ehsys_qsort(&D_00079408, 0x25, 0x18, func_00052CAC);
    ehsys_qsort(&D_00079804, 1, 0xCC, func_00052CAC);
    ehsys_qsort(&D_00079B60, 0x24, 0x10, func_00052CAC);
    ehsys_qsort(&D_00079ED0, 0xC, 0x14, func_00052CAC);
}

/* func_00051958 — 21 words. MATCH 100% (verified). */
int func_00051958(void) {
    extern void func_00051A6C(void);
    extern void func_0005303C(void);
    extern int ehsys_2630B590();
    extern int ehsys_frame_sync();
    extern int func_000519AC();
    func_00051A6C();
    func_0005303C();
    func_000527C8();
    func_000519AC();
    while (ehsys_2630B590() != 0) {
        ehsys_frame_sync();
    }
}

/* func_00051FF0 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00051FF0(void) {
    return (*(s32 *)&D_00095538);
}
/* func_00052CAC — 8 words. MATCH 100% (verified). */
s32 func_00052CAC(u32 *arg0, u32 *arg1) {
    u32 b = *arg1;
    u32 a = *arg0;
    if (a < b) {
        return -1;
    }
    return b < a;
}

/* func_00052CCC — 8 words. MATCH 100% (verified). */
s32 func_00052CCC(u16 *arg0, u16 *arg1) {
    u16 a = *arg0;
    u16 b = *arg1;
    if (a < b) {
        return -1;
    }
    return b < a;
}

/* func_0005310C — 16 words. MATCH 100% (shape: m2c). */
s32 func_0005310C(void *arg0, s32 arg1) {
    extern int ehsys_4B0DABFA();
    extern int func_0005310C();
    if (arg1 < 0) {
        return 0;
    }
    ehsys_4B0DABFA(0, (*(int *)((char *)arg0 + 0xC4)));
    (*(int *)((char *)arg0 + 0xC8)) = 0;
    return 1;
}
/* func_000532C8 — 17 words. MATCH 100% (shape: m2c). */
s32 func_000532C8(void *arg0, s32 arg1) {
    extern int ehsys_4B0DABFA();
    extern int func_000532C8();
    if (arg1 <= 0) {
        return 0;
    }
    ehsys_4B0DABFA(0, (*(int *)((char *)arg0 + 0xC)));
    (*(int *)((char *)arg0 + 0x1C)) = 1;
    (*(int *)((char *)arg0 + 0x14)) = 0;
    return 1;
}
/* func_0005330C — 17 words. MATCH 100% (shape: m2c). */
s32 func_0005330C(void *arg0, s32 arg1) {
    extern int ehsys_4B0DABFA();
    extern int func_0005330C();
    if (arg1 <= 0) {
        return 0;
    }
    ehsys_4B0DABFA(0, (*(int *)((char *)arg0 + 0x8)));
    (*(int *)((char *)arg0 + 0x18)) = 1;
    (*(int *)((char *)arg0 + 0x10)) = 0;
    return 1;
}
/* func_000535A4 — 7 words. MATCH 100% (verified). */
s32 func_000535A4(void *arg0, s32 arg1) {
    if (arg1 <= 0) {
        return 0;
    }
    *(s32 *)((char *)arg0 + 0x24) = 0;
    return 1;
}

/* func_000535C0 — 21 words. MATCH 100% (shape: m2c). */
s32 func_000535C0(void *arg0, s32 arg1) {
    extern int D_0007A638;
    extern int ehsys_4B0DABFA();
    extern int ehsys_C6C15111();
    extern int func_000535C0();
    if (arg1 <= 0) {
        return 0;
    }
    ehsys_4B0DABFA(0, ehsys_C6C15111((*(int *)((char *)arg0 + 0x8)), &D_0007A638, 0));
    (*(int *)((char *)arg0 + 0x28)) = 0;
    return 1;
}
/* func_00053614 — 24 words. MATCH 100% (shape: lead-dummy2). */
s32 func_00053614(s32 unused0, s32 unused1, int arg2) {
    extern int D_0007A528;
    extern int D_0007A65C;
    extern int ehsys_53D7C1EE();
    extern int ehsys_strcat();
    extern int ehsys_strcpy();
    extern int func_00053614();
    s32 temp_s0;

    temp_s0 = ehsys_53D7C1EE();
    ehsys_strcpy(arg2, &D_0007A65C);
    ehsys_strcat(arg2, temp_s0);
    ehsys_strcat(arg2, (s32) &D_0007A528);
    return 1;
}

/* func_00053674 — 3 words. MATCH 100% (shape: m2c). */
void func_00053674(s32 arg0) {
    *(s32 *)0x395638 = arg0;
}

/* func_00053680 — 3 words. MATCH 100% (shape: m2c). */
void func_00053680(void) {
    *(s32 *)0x395638 = 0;
}

/* func_0005368C — 4 words. MATCH 100% (shape: m2c). */
int func_0005368C(s32 arg0) {
    return ehsys_41AABF28(*(s32 *)0x395638, arg0);
}

/* func_0005369C — 4 words. MATCH 100% (shape: m2c). */
int func_0005369C(arg0) s32 arg0;
{
    return (s32)(ehsys_20E340D9(*(s32 *)0x395638, arg0));
}

/* func_000536AC — 3 words. MATCH 100% (shape: m2c). */
s32 func_000536AC(void) {
    return *(s32 *)0x395638;
}

/* func_00053930 — 2 words. MATCH 100% (shape: m2c). */
void func_00053930(void) {
    func_00014140();
}

/* func_0005399C — 4 words. MATCH 100% (shape: m2c). */
void func_0005399C(void) {
    *(s32 *)0x395644 = 1;
}

/* func_000539AC — 3 words. MATCH 100% (shape: m2c). */
int func_000539AC() {
    *(s32 *)0x395644 = 0;
}

/* func_00053B10 — 11 words. MATCH 100% (shape: m2c). */
void func_00053B10(void) {
    if (duel_eng_2174D9E0() != 0) {
        func_00051630(0);
    }
}

/* func_00053B3C — 3 words. MATCH 100% (shape: m2c). */
int func_00053B3C(arg0) s32 arg0;
{
    *(s32 *)0x395648 = arg0;
}

/* func_00053B48 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00053B48(s32 *arg0, s32 *arg1) {
    return *arg0 - *arg1;
}

/* func_00053B58 — 11 words. MATCH 100% (shape: m2c). */
void func_00053B58(void) {
    duel_eng_1256A810();
    func_0000B9E8();
    func_0001CC70();
}

/* func_00053BE4 — 2 words. MATCH 100% (shape: m2c). */
void func_00053BE4(void) {
    duel_eng_4A030E8B();
}

/* func_000542B0 — 8 words. MATCH 100% (shape: thunk). */
s32 func_000542B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_00054F54 — 2 words. MATCH 100% (shape: m2c). */
void func_00054F54(void) {

}

/* func_00054F5C — 2 words. MATCH 100% (shape: m2c). */
void func_00054F5C(void) {

}

/* func_00054F64 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00054F64(s32 arg0) {
    return arg0;
}
/* func_00054F6C — 24 words. MATCH 100% (shape: m2c). */
void func_00054F6C(void) {
    extern int ehsys_get_button_code();
    extern int func_00002568();
    extern int func_00053938();
    extern int func_00054F6C();
    s32 temp_a0;
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = func_00053938();
    temp_s0 = ehsys_get_button_code(0) & 0xFFFF;
    temp_a0 = temp_s0 | (ehsys_get_button_code(1) & 0xFFFF);
    if ((*(int *)((char *)temp_s1 + 0x4)) & temp_a0) {
        func_00002568(temp_a0);
    }
}

/* func_00054FCC — 20 words. MATCH 100% (shape: m2c). */
s32 func_00054FCC(void) {
    if (func_00055390() == 0) {
        return 0;
    }
    *(s32 *)0x3956B0 = func_00055E28();
    func_00055E34(8);
    func_000564C8(0);
    return 1;
}

/* func_00055374 — 5 words. MATCH 100% (shape: m2c). */
s32 func_00055374(void) {
    return *(s32 *)0x3956AC == 1;
}

/* func_00055388 — 2 words. MATCH 100% (shape: m2c). */
void func_00055388(void) {
    func_00055488();
}

/* func_00055488 — 15 words. MATCH 100% (shape: m2c). */
void func_00055488(void) {
    *(s32 *)0x3956AC = 2;
    func_00050304(0x87, 1);
    ehsys_D470D0B2(1, 0xFF000000, 1);
}
/* func_0005553C — 23 words. MATCH 100% (shape: m2c). */
void func_0005553C(void) {
    extern int ehsys_5998BFD7();
    extern int func_00051EE4();
    extern int func_000536AC();
    extern int func_0005553C();
    extern int func_00064254();
    s32 temp_s0;

    *(s32 *)0x3956B4 = 1;
    ehsys_5998BFD7(1, 0xFF000000, 0x10);
    temp_s0 = func_000536AC();
    func_00064254(temp_s0, func_00051EE4(0x80001), 1);
}

/* func_00055598 — 2 words. MATCH 100% (shape: m2c). */
void func_00055598(void) {
    func_00064658();
}

/* func_00055728 — 9 words. MATCH 100% (shape: m2c). */
s32 func_00055728(void) {
    return func_00055E28() == 9;
}

/* func_0005574C — 12 words. MATCH 100% (shape: m2c). */
void func_0005574C(void) {
    if (func_00055E28() == 9) {
        func_00055F0C();
    }
}

/* func_000557F8 — 3 words. MATCH 100% (shape: m2c). */
void func_000557F8(void) {
    *(s32 *)0x3956BC = 0;
}

/* func_00055804 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00055804(s32 arg0) {
    return arg0;
}

/* func_000559A8 — 4 words. MATCH 100% (shape: m2c). */
s32 func_000559A8(void) {
    return *(s32 *)0x3956BC != 0;
}

/* func_00055BAC — 13 words. MATCH 100% (shape: m2c). */
void func_00055BAC(void) {
    s32 temp_s0;

    temp_s0 = func_000564F0();
    func_00055E34(7);
    func_000564C8(temp_s0);
}

/* func_00055BE0 — 12 words. MATCH 100% (shape: m2c). */
void func_00055BE0(void) {
    func_0005FB34(func_000536B8(3));
    *(s32 *)0x3956DC = 1;
}

/* func_00055C10 — 2 words. MATCH 100% (shape: m2c). */
void func_00055C10(void) {

}

/* func_00055C18 — 2 words. MATCH 100% (shape: m2c). */
s32 func_00055C18(s32 arg0) {
    return arg0;
}

/* func_00055D20 — 5 words. MATCH 100% (shape: m2c). */
s32 func_00055D20(void) {
    return *(s32 *)0x3956DC == 1;
}

/* func_00055D44 — 5 words. MATCH 100% (shape: thunk). */
s32 func_00055D44(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_memset(&D_3956E0, 0, 0x4C);
}

/* func_00055D58 — 5 words. MATCH 100% (shape: thunk). */
s32 func_00055D58(s32 arg0, s32 arg1, s32 arg2) {
    return ehsys_memset(&D_3956E0, 0, 0x4C);
}

/* func_00055E28 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00055E28(void) {
    return *(s32 *)0x3956E0;
}

/* func_000564C8 — 10 words. MATCH 100% (shape: m2c). */
int func_000564C8(arg0) s32 arg0;
{
    *(s32 *)0x3956E4 = arg0;
    if (arg0 >= 0) {
        ehsys_4BF558F1();
    }
}
/* func_00055EF4 — 6 words. MATCH 100% (shape: m2c). */
void *func_00055EF4(void *arg0, void *arg1) {
    extern int func_00055EF4();
    (*(int *)((char *)arg0 + 0x0)) = (s32) (*(int *)((char *)arg1 + 0x0));
    (*(int *)((char *)arg0 + 0x4)) = (s32) (*(int *)((char *)arg1 + 0x4));
    return arg0;
}

/* func_000564F0 — 3 words. MATCH 100% (shape: m2c). */
s32 func_000564F0(void) {
    return *(s32 *)0x3956E4;
}

/* func_000564FC — 8 words. MATCH 100% (shape: m2c). */
s32 func_000564FC(void) {
    return func_0000B288() != 0;
}

/* func_0005651C — 11 words. MATCH 100% (verified). */
u8 func_0005651C(s32 *arg0, s32 arg1) {
    u8 v0;
    if ((*arg0 & 0x300) != 0x100) {
        v0 = 0;
    } else {
        v0 = (u32)((arg1 & 0x300) ^ 0x100) < 1;
    }
    return v0;
}

/* func_00056548 — 11 words. MATCH 100% (verified). */
u8 func_00056548(s32 *arg0, s32 arg1) {
    u8 v0;
    if ((*arg0 & 0x300) != 0x200) {
        v0 = 0;
    } else {
        v0 = (u32)((arg1 & 0x300) ^ 0x200) < 1;
    }
    return v0;
}

/* func_00056574 — 11 words. MATCH 100% (verified). */
u8 func_00056574(s32 *arg0, s32 arg1) {
    u8 v0;
    if ((*arg0 & 0x300) != 0x300) {
        v0 = 0;
    } else {
        v0 = (u32)((arg1 & 0x300) ^ 0x300) < 1;
    }
    return v0;
}

/* func_0005666C — 10 words. MATCH 100% (shape: m2c). */
void func_0005666C(void) {
    func_00050304(7, 1);
    *(s32 *)0x395710 = 0;
}

/* func_00056C40 — 3 words. MATCH 100% (shape: thunk). */
s32 func_00056C40(s32 arg0, s32 arg1) {
    return func_00050304(0x7, 0);
}

/* func_00056C4C — 3 words. MATCH 100% (shape: m2c). */
void func_00056C4C(s32 arg0) {
    *(s32 *)0x395718 = arg0;
}

/* func_00056C58 — 2 words. MATCH 100% (shape: m2c). */
void func_00056C58(void) {

}

/* func_00056C60 — 2 words. MATCH 100% (shape: m2c). */
void func_00056C60(void) {
    func_000600B4();
}

/* func_00056D18 — 2 words. MATCH 100% (shape: m2c). */
void func_00056D18(void) {
    func_0005FC48();
}

/* func_00056D20 — 2 words. MATCH 100% (shape: m2c). */
void func_00056D20(void) {

}

/* func_00056D28 — 2 words. MATCH 100% (shape: m2c). */
void func_00056D28(void) {
    func_0005B77C();
}

/* func_00056D84 — 2 words. MATCH 100% (shape: m2c). */
void func_00056D84(void) {
    func_0005B770();
}

/* func_00056D8C — 9 words. MATCH 100% (shape: m2c). */
void func_00056D8C(void) {
    func_0005BE44();
    func_00058E34();
}

/* func_00056DB0 — 2 words. MATCH 100% (shape: m2c). */
void func_00056DB0(void) {
    func_00058E9C();
}
/* func_00056DB8 — 39 words. MATCH 100% (shape: m2c). */
void func_00056DB8(void) {
    extern int func_00053938();
    extern int func_00055BAC();
    extern int func_00055F0C();
    extern int func_00056DB8();
    extern int func_00058F28();
    extern int func_00059018();
    extern int func_0005902C();
    extern int func_00059078();
    extern int func_00059084();
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = func_00053938();
    temp_s0 = func_00058F28();
    if ((func_00059018() != 0) && (func_00059084() != 0) && (func_00059078() != 1) && ((*(int *)((char *)temp_s1 + 0x4)) & 0x8000)) {
        func_00055BAC();
        return;
    }
    if (temp_s0 != 0) {
        func_00055F0C();
        func_0005902C();
    }
}

/* func_00056E54 — 9 words. MATCH 100% (shape: m2c). */
void func_00056E54(void) {
    func_00058E3C();
    func_0005BE84();
}

/* func_00056E78 — 3 words. MATCH 100% (shape: m2c). */
void func_00056E78(s32 arg0) {
    *(s32 *)0x39571C = arg0;
}

/* func_0005711C — 3 words. MATCH 100% (shape: thunk). */
s32 func_0005711C(s32 arg0, s32 arg1) {
    return func_00050304(0x7, 0x1);
}

/* func_00057128 — 15 words. MATCH 100% (shape: m2c). */
void func_00057128(void) {
    func_00050304(7, 1);
    *(s32 *)0x395720 = 2;
    ehsys_D470D0B2(1, 0xFF000000, 1);
}
/* func_000573B4 — 11 words. MATCH 100% (shape: bool-fold). */
s32 func_000573B4(void *arg0, void *arg1) {
    extern int func_000573B4();
    s32 temp_v0;

    temp_v0 = (*(int *)((char *)arg0 + 0x0)) - (*(int *)((char *)arg1 + 0x0));
    if (!temp_v0) {
        return (*(int *)((char *)arg0 + 0x4)) - (*(int *)((char *)arg1 + 0x4));
    }
    return temp_v0;
}

/* func_000573E0 — 2 words. MATCH 100% (shape: m2c). */
s32 func_000573E0(void) {
    return 1;
}
/* func_0005741C — 37 words. MATCH 100% (shape: m2c). */
void func_0005741C(s32 arg0) {
    extern int ehsys_2AE3C0AD();
    extern int func_0005368C();
    extern int func_000536B8();
    extern int func_00055E34();
    extern int func_000564C8();
    extern int func_0005741C();
    extern int func_000574B0();
    extern int func_0005751C();
    extern int func_00057650();
    extern int func_00057884();
    extern int func_000590DC();
    extern int func_000592B4();
    extern int func_000592C0();
    s32 temp_s0;

    temp_s0 = func_000536B8(0x2E);
    *(s32 *)0x395774 = func_0005368C(0x4B0C);
    func_00057650(arg0);
    func_000590DC(temp_s0, 0, 0x20, func_000574B0);
    func_00055E34(4);
    func_000564C8(0x36);
    func_000592B4(func_0005751C);
    func_000592C0(func_00057884);
    ehsys_2AE3C0AD(0x94CB);
}

/* func_00057564 — 6 words. MATCH 100% (shape: m2c). */
int func_00057564(s32 arg0) {
    return ehsys_AD0E1E03((*(s32 **)0x395774)[arg0]);
}
/* func_0005757C — 49 words. MATCH 100% (shape: m2c). */
void func_0005757C(s32 arg0, s32 arg1, int arg2, s32 arg3) {
    extern int ehsys_2FD4863E();
    extern int ehsys_60B55A50();
    extern int ehsys_66F8E113();
    extern int ehsys_942B03D0();
    extern int ehsys_A4AFF8E6();
    extern int ehsys_B8AD96EA();
    extern int func_00057564();
    extern int func_0005757C();
    extern int func_00057640();
    extern int func_00057B0C();
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v1;

    ehsys_942B03D0(0xC, 0xC);
    ehsys_60B55A50(0xFF000000);
    temp_v0 = func_00057564(arg1 & 0xFFFF);
    ehsys_66F8E113(temp_v0);
    temp_s1 = ehsys_2FD4863E() >> 6;
    ehsys_B8AD96EA(arg0);
    temp_v0_2 = func_00057B0C();
    var_v1 = temp_s1 >> 1;
    if (temp_s1 < 0) {
        var_v1 = (s32) (temp_s1 + 1) >> 1;
    }
    func_00057640(arg2, arg3 + (9 - var_v1), temp_v0_2, temp_v0);
    ehsys_A4AFF8E6();
}

/* func_00057640 — 4 words. MATCH 100% (shape: thunk). */
s32 func_00057640(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), (arg2 << 6), arg3);
}

/* func_0005784C — 14 words. MATCH 100% (shape: m2c). */
s32 func_0005784C(s32 *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 temp_s0_2;

    temp_s0_2 = *arg1;
    temp_s0 = ehsys_93EACD81(*arg0);
    return temp_s0 - ehsys_93EACD81(temp_s0_2);
}

/* func_00057B0C — 10 words. MATCH 100% (shape: m2c). */
s32 func_00057B0C(void) {
    if (ehsys_get_language() == 0) {
        return 0xC8;
    }
    return 0x12C;
}

/* func_00057B34 — 2 words. MATCH 100% (shape: m2c). */
void func_00057B34(void) {
    func_000587E8();
}
/* func_00057BAC — 24 words. MATCH 100% (shape: m2c). */
void *func_00057BAC(void *arg0, void *arg1) {
    extern int func_00057BAC();
    (*(int *)((char *)arg0 + 0x0)) = (s32) (*(int *)((char *)arg1 + 0x0));
    (*(int *)((char *)arg0 + 0x4)) = (s32) (*(int *)((char *)arg1 + 0x4));
    (*(int *)((char *)arg0 + 0x8)) = (s32) (*(int *)((char *)arg1 + 0x8));
    (*(int *)((char *)arg0 + 0xC)) = (s32) (*(int *)((char *)arg1 + 0xC));
    (*(int *)((char *)arg0 + 0x10)) = (s32) (*(int *)((char *)arg1 + 0x10));
    (*(int *)((char *)arg0 + 0x14)) = (s32) (*(int *)((char *)arg1 + 0x14));
    (*(int *)((char *)arg0 + 0x18)) = (s32) (*(int *)((char *)arg1 + 0x18));
    (*(int *)((char *)arg0 + 0x1C)) = (s32) (*(int *)((char *)arg1 + 0x1C));
    (*(int *)((char *)arg0 + 0x20)) = (s32) (*(int *)((char *)arg1 + 0x20));
    (*(int *)((char *)arg0 + 0x24)) = (s32) (*(int *)((char *)arg1 + 0x24));
    (*(int *)((char *)arg0 + 0x28)) = (s32) (*(int *)((char *)arg1 + 0x28));
    return arg0;
}

/* func_00057D00 — 5 words. MATCH 100% (shape: thunk). */
s32 func_00057D00(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_000586B0(0, 0, 0x64, 0x15);
}

/* func_00058690 — 8 words. MATCH 100% (shape: thunk). */
s32 func_00058690(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_00058B0C — 3 words. MATCH 100% (shape: m2c). */
int func_00058B0C(arg0) s32 arg0;
{
    *(s32 *)0x3958D4 = arg0;
}

/* func_00058E34 — 2 words. MATCH 100% (shape: m2c). */
void func_00058E34(void) {

}

/* func_00058FDC — 15 words. MATCH 100% (shape: m2c). */
s32 func_00058FDC(void) {
    u8 temp_v1;

    temp_v1 = *(u8 *)0x3959C5;
    if ((temp_v1 != 6) && (temp_v1 != 1) && (temp_v1 != 0)) {
        return 1;
    }
    return 0;
}

/* func_00059018 — 5 words. MATCH 100% (shape: m2c). */
s32 func_00059018(void) {
    return *(u8 *)0x3959C5 == 3;
}

/* func_0005906C — 3 words. MATCH 100% (shape: m2c). */
void func_0005906C(void) {
    ehsys_B0F320E6(&D_3958D8);
}

/* func_00059078 — 3 words. MATCH 100% (shape: m2c). */
s32 func_00059078(void) {
    return *(s32 *)0x395A18;
}

/* func_00059084 — 6 words. MATCH 100% (verified). */
u8 func_00059084(void) {
    return !(*(int *)0x395A1C);
}

/* func_000590D0 — 3 words. MATCH 100% (shape: m2c). */
void **func_000590D0(void) {
    return (void **)&D_3958D8;
}

/* func_00059290 — 3 words. MATCH 100% (shape: m2c). */
void func_00059290(void) {
    ehsys_E1139F1A(&D_3958D8);
}

/* func_0005929C — 3 words. MATCH 100% (shape: m2c). */
void func_0005929C(s32 arg0) {
    *(s32 *)0x395A00 = arg0;
}

/* func_000592A8 — 3 words. MATCH 100% (shape: m2c). */
void func_000592A8(s32 arg0) {
    *(s32 *)0x395A04 = arg0;
}

/* func_000592B4 — 3 words. MATCH 100% (shape: m2c). */
int func_000592B4(arg0) s32 arg0;
{
    *(s32 *)0x3959FC = arg0;
}

/* func_000592C0 — 3 words. MATCH 100% (shape: m2c). */
void func_000592C0(s32 arg0) {
    *(s32 *)0x395A08 = arg0;
}

/* func_00059328 — 3 words. MATCH 100% (shape: m2c). */
void func_00059328(s32 arg0) {
    *(s32 *)0x395A0C = arg0;
}

/* func_00059434 — 3 words. MATCH 100% (shape: m2c). */
void func_00059434(s32 arg0) {
    *(s32 *)0x395A18 = arg0;
}

/* func_00059960 — 12 words. MATCH 100% (shape: m2c). */
s32 func_00059960(void) {
    s32 temp_v1;

    temp_v1 = *(s32 *)0x395CE8;
    if ((temp_v1 != 6) && (temp_v1 != 0)) {
        return 0;
    }
    return 1;
}

/* func_00059990 — 3 words. MATCH 100% (shape: m2c). */
void **func_00059990(void) {
    return &D_395A6C;
}

/* func_0005999C — 3 words. MATCH 100% (shape: m2c). */
void func_0005999C(s32 arg0) {
    *(s32 *)0x395CF8 = arg0;
}

/* func_000599A8 — 7 words. MATCH 100% (verified). */
int func_000599A8(void *arg0) {
    char *v1 = &D_395A20;
    if (arg0 == 0) {
        arg0 = (void *)func_00059D20;
    }
    *(void **)(v1 + 0x2D4) = arg0;
}

/* func_000599C4 — 3 words. MATCH 100% (shape: m2c). */
s32 func_000599C4(void) {
    return *(s32 *)0x395D04;
}

/* func_000599D0 — 16 words. MATCH 100% (shape: m2c). */
void func_000599D0(void) {
    ehsys_5DF04F49(&D_395A20);
    func_00007494(func_00059C94);
    ehsys_memset(&D_395A20, 0, 0x2E8);
}

/* func_00059D20 — 9 words. MATCH 100% (shape: m2c). */
s32 func_00059D20(void) {
    return duel_eng_746BFD48() == 0;
}
/* func_0005A90C — 33 words. MATCH 100% (shape: m2c). */
void func_0005A90C(s32 arg0) {
    extern int D_395D0C;
    extern int ehsys_2AE3C0AD();
    extern int ehsys_memset();
    extern int func_00055E34();
    extern int func_000564C8();
    extern int func_00058C1C();
    extern int func_000590DC();
    extern int func_000592B4();
    extern int func_000592C0();
    extern int func_0005A90C();
    extern int func_0005A990();
    extern int func_0005AA0C();
    extern int func_0005ACEC();
    ehsys_memset(&D_395D0C, 0, 0x4C);
    func_0005ACEC();
    func_000590DC(0, arg0, 3, func_0005A990);
    func_00055E34(4);
    func_000564C8(0x36);
    func_000592B4(func_0005AA0C);
    func_000592C0(func_00058C1C);
    ehsys_2AE3C0AD(0x94CB);
}

/* func_0005ACCC — 8 words. MATCH 100% (shape: thunk). */
s32 func_0005ACCC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}
/* func_0005AED8 — 5 words. MATCH 100% (verified). */
s32 func_0005AED8(void) {
    extern s32 D_395D58;
    return ehsys_memset(&D_395D58, 0, 0x24);
}

/* func_0005AEEC — 5 words. MATCH 100% (verified). */
s32 func_0005AEEC(void) {
    extern s32 D_395D58;
    return ehsys_memset(&D_395D58, 0, 0x24);
}

/* func_0005AF00 — 35 words. MATCH 100% (shape: m2c). */
void func_0005AF00(s32 arg0) {
    extern int D_395D58;
    extern int ehsys_2AE3C0AD();
    extern int func_00055E34();
    extern int func_000564C8();
    extern int func_000590DC();
    extern int func_0005929C();
    extern int func_000592B4();
    extern int func_00059434();
    extern int func_0005AF00();
    extern int func_0005AF8C();
    extern int func_0005AFA4();
    extern int func_0005B0DC();
    extern int func_0005B1DC();
    extern int func_0005B5D0();
    func_0005AF8C(&D_395D58, arg0);
    func_0005AFA4();
    if (*(s32 *)0x395D74 != 0) {
        func_000590DC(0, 0, 0x20, func_0005B0DC);
        func_00055E34(4);
        func_000564C8(0x36);
        func_000592B4(func_0005B1DC);
        func_0005929C(func_0005B5D0);
        func_00059434(1);
        ehsys_2AE3C0AD(0x94C7);
    }
}
/* func_0005AF8C — 6 words. MATCH 100% (shape: m2c). */
void *func_0005AF8C(void *arg0, void *arg1) {
    extern int func_0005AF8C();
    (*(int *)((char *)arg0 + 0x0)) = (s32) (*(int *)((char *)arg1 + 0x0));
    (*(int *)((char *)arg0 + 0x4)) = (s32) (*(int *)((char *)arg1 + 0x4));
    return arg0;
}

/* func_0005B750 — 8 words. MATCH 100% (shape: thunk). */
s32 func_0005B750(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_0005B770 — 3 words. MATCH 100% (shape: m2c). */
void func_0005B770(void) {
    ehsys_E1139F1A(&D_395D7C);
}

/* func_0005B77C — 11 words. MATCH 100% (shape: m2c). */
int func_0005B77C(arg0) s32 arg0;
{
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_395D7C);
    return (s32)(sp1C);
}

/* func_0005B7E4 — 15 words. MATCH 100% (shape: m2c). */
s32 func_0005B7E4(void) {
    u8 temp_v1;

    temp_v1 = *(u8 *)0x395E69;
    if ((temp_v1 != 6) && (temp_v1 != 1) && (temp_v1 != 0)) {
        return 1;
    }
    return 0;
}
/* func_0005B820 — 0 words. MATCH 100% (shape: harvested). */
void func_0005B820(s32 arg0, s32 arg1) {
    extern int D_3962AC;
    extern int ehsys_2AE3C0AD();
    extern int ehsys_memset();
    extern int func_00055E34();
    extern int func_000564C8();
    extern int func_000590DC();
    extern int func_0005929C();
    extern int func_000592A8();
    extern int func_000592B4();
    extern int func_0005B820();
    extern int func_0005B8BC();
    extern int func_0005BA7C();
    extern int func_0005BAB4();
    extern int func_0005BBA0();
    ehsys_memset(&D_3962AC, 0, 0xC);
    *(s32 *)0x3962AC = arg1;
    func_000590DC(arg0, arg0, 0x30, func_0005B8BC);
    func_00055E34(4);
    func_000564C8(0x36);
    func_000592B4(func_0005BAB4);
    func_0005929C(func_0005BBA0);
    func_000592A8(func_0005BA7C);
    ehsys_2AE3C0AD(0x94C7);
}

/* func_0005BA7C — 14 words. MATCH 100% (shape: hand). */
void func_0005BA7C(s32 arg0, s32 arg1, s32 arg2) {
    func_000593B4(func_000536B8(arg2 + 0x17));
    *(s32 *)0x3962B0 = arg2;
}

/* func_0005BBA0 — 2 words. MATCH 100% (shape: m2c). */
s32 func_0005BBA0(s32 arg0) {
    return arg0;
}

/* func_0005C574 — 8 words. MATCH 100% (shape: thunk). */
s32 func_0005C574(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_0005C68C — 7 words. MATCH 100% (shape: thunk). */
s32 func_0005C68C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return ehsys_3BB2BAC6((arg0 << 6), (arg1 << 6), (arg2 << 6), (arg3 << 6), arg4, -0x1, 0);
}

/* func_0005C8D4 — 10 words. MATCH 100% (shape: m2c). */
void func_0005C8D4(void) {
    duel_eng_3865EBDA(func_0005846C(*(s32 *)0x3964C4));
}
/* func_0005C8FC — 0 words. MATCH 100% (shape: harvested). */
s32 func_0005C8FC(void) {
    extern int func_00057F84();
    extern int func_00058FDC();
    extern int func_0005C8FC();
    func_00057F84(*(s32 *)0x3964C4);
    return (!func_00058FDC()) & 0xFF;
}

/* func_0005CE20 — 8 words. MATCH 100% (shape: thunk). */
s32 func_0005CE20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_0005D028 — 20 words. MATCH 100% (shape: m2c). */
void func_0005D028(s32 arg0) {
    func_000590DC(0, arg0, 0x30, func_0005D078);
    func_00055E34(4);
    func_000564C8(0x36);
    func_000592B4(func_0005D0B8);
    ehsys_2AE3C0AD(0x94CB);
}

/* func_0005D0B8 — 9 words. MATCH 100% (shape: m2c). */
int func_0005D0B8() {
    duel_eng_3865EBDA(func_000592CC());
}

/* func_0005D288 — 8 words. MATCH 100% (shape: thunk). */
s32 func_0005D288(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_0005D964 — 3 words. MATCH 100% (shape: m2c). */
void func_0005D964(void) {
    ehsys_E1139F1A(&D_3964D4);
}

/* func_0005D970 — 3 words. MATCH 100% (shape: m2c). */
void func_0005D970(void) {
    ehsys_39ADDA9F(&D_3964D4);
}

/* func_0005DB6C — 9 words. MATCH 100% (shape: m2c). */
void func_0005DB6C(void) {
    duel_eng_3865EBDA(func_000592CC());
}

/* func_0005E108 — 8 words. MATCH 100% (shape: thunk). */
s32 func_0005E108(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_0005E128 — 7 words. MATCH 100% (shape: thunk). */
s32 func_0005E128(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return ehsys_3BB2BAC6((arg0 << 6), (arg1 << 6), (arg2 << 6), (arg3 << 6), arg4, -0x1, 0);
}

/* func_0005E144 — 2 words. MATCH 100% (shape: m2c). */
s32 func_0005E144(s32 arg0) {
    return arg0;
}

/* func_0005E554 — 8 words. MATCH 100% (shape: thunk). */
s32 func_0005E554(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}
/* func_0005E79C — 0 words. MATCH 100% (shape: harvested). */
s32 func_0005E79C(void) {
    extern int func_00057F84();
    extern int func_00058FDC();
    extern int func_0005E79C();
    func_00057F84(*(s32 *)0x396840);
    return (!func_00058FDC()) & 0xFF;
}

/* func_0005ECC0 — 8 words. MATCH 100% (shape: thunk). */
s32 func_0005ECC0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_0005F310 — 8 words. MATCH 100% (shape: thunk). */
s32 func_0005F310(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_0005F700 — 7 words. MATCH 100% (shape: thunk). */
s32 func_0005F700(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return ehsys_3BB2BAC6((arg0 << 6), (arg1 << 6), (arg2 << 6), (arg3 << 6), arg4, -0x1, 0);
}

/* func_0005F8DC — 9 words. MATCH 100% (shape: m2c). */
void func_0005F8DC(void) {
    duel_eng_3865EBDA(func_000592CC() != 0);
}

/* func_0005FB18 — 7 words. MATCH 100% (shape: thunk). */
s32 func_0005FB18(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return ehsys_3BB2BAC6((arg0 << 6), (arg1 << 6), (arg2 << 6), (arg3 << 6), arg4, -0x1, 0);
}

/* func_0005FBA0 — 4 words. MATCH 100% (shape: m2c). */
void func_0005FBA0(void) {
    *(s32 *)0x396850 = 1;
}

/* func_0005FBB0 — 2 words. MATCH 100% (shape: m2c). */
void func_0005FBB0(void) {
    func_00059960();
}

/* func_0005FBB8 — 3 words. MATCH 100% (shape: m2c). */
s32 func_0005FBB8(void) {
    return *(s32 *)0x396850;
}

/* func_0005FBC4 — 9 words. MATCH 100% (shape: m2c). */
void func_0005FBC4(void) {
    func_00063020();
    func_0005AED8();
}

/* func_0005FBE8 — 11 words. MATCH 100% (shape: m2c). */
void func_0005FBE8(void) {
    func_00063050();
    func_000573E8();
    func_0005AEEC();
}

/* func_0005FC14 — 2 words. MATCH 100% (shape: m2c). */
void func_0005FC14(void) {

}

/* func_0005FC1C — 11 words. MATCH 100% (shape: m2c). */
void func_0005FC1C(void) {
    func_0005FC48();
    func_00058E3C();
    func_00057B34();
}

/* func_0005FC48 — 11 words. MATCH 100% (shape: m2c). */
void func_0005FC48(void) {
    ehsys_E1139F1A(&D_396854);
    ehsys_E1139F1A(&D_396978);
}

/* func_0006051C — 15 words. MATCH 100% (shape: m2c). */
s32 func_0006051C(void) {
    u8 temp_v1;

    temp_v1 = *(u8 *)0x396941;
    if ((temp_v1 != 6) && (temp_v1 != 1) && (temp_v1 != 0)) {
        return 1;
    }
    return 0;
}

/* func_00060558 — 5 words. MATCH 100% (shape: m2c). */
s32 func_00060558(void) {
    return *(u8 *)0x396941 == 3;
}

/* func_000605BC — 3 words. MATCH 100% (shape: m2c). */
void func_000605BC(void) {
    ehsys_B0F320E6(&D_396854);
}

/* func_00060CF8 — 4 words. MATCH 100% (shape: thunk). */
s32 func_00060CF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), (arg2 << 6), arg3);
}

/* func_00060D08 — 5 words. MATCH 100% (shape: thunk). */
s32 func_00060D08(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_BC8E65D7((arg0 << 6), (arg1 << 6), (arg2 << 6), arg3, -0x1);
}

/* func_00061124 — 8 words. MATCH 100% (verified). */
s32 func_00061124(void) {
    void *v0 = ehsys_B2B9FEFA();
    return *(s32 *)((char *)v0 + 4);
}

/* func_000615D4 — 8 words. MATCH 100% (shape: thunk). */
s32 func_000615D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_000618AC — 3 words. MATCH 100% (shape: m2c). */
void func_000618AC(void) {
    ehsys_E1139F1A(&D_396978);
}

/* func_000619F8 — 11 words. MATCH 100% (shape: m2c). */
s32 func_000619F8(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_396978);
    return sp1C;
}

/* func_00062428 — 3 words. MATCH 100% (shape: m2c). */
void func_00062428(void) {
    ehsys_E1139F1A(&D_396978);
}

/* func_00062534 — 11 words. MATCH 100% (shape: m2c). */
s32 func_00062534(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_396978);
    return sp1C;
}

/* func_00062B34 — 11 words. MATCH 100% (shape: m2c). */
s32 func_00062B34(s32 arg0) {
    s32 sp1C;

    sp1C = arg0;
    ehsys_EF9B5D06(&sp1C, &D_396978);
    return sp1C;
}

/* func_00063020 — 12 words. MATCH 100% (shape: m2c). */
void func_00063020(void) {
    ehsys_memset(&D_39847C, 0, 0xA0);
    *(s32 *)0x39851C = 0;
}

/* func_00063050 — 12 words. MATCH 100% (shape: m2c). */
void func_00063050(void) {
    ehsys_memset(&D_39847C, 0, 0xA0);
    *(s32 *)0x39851C = 0;
}

/* func_000633B0 — 4 words. MATCH 100% (shape: m2c). */
s32 *func_000633B0(s32 *arg0, s32 *arg1) {
    *arg0 = *arg1;
    return arg0;
}

/* func_000633C0 — 2 words. MATCH 100% (shape: m2c). */
void func_000633C0(void) {
    func_00063580();
}

/* func_000633C8 — 3 words. MATCH 100% (shape: m2c). */
int func_000633C8(arg0) s32 arg0;
{
    *(s32 *)0x39851C = arg0;
}

/* func_00063B48 — 10 words. MATCH 100% (shape: m2c). */
s32 func_00063B48(s32 arg0) {
    func_00063700();
    return arg0;
}

/* func_00063C48 — 8 words. MATCH 100% (shape: thunk). */
s32 func_00063C48(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_000650E8 — 5 words. MATCH 100% (shape: thunk). */
s32 func_000650E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_BC8E65D7((arg0 << 6), (arg1 << 6), (arg2 << 6), arg3, -0x1);
}

/* func_00066660 — 24 words. MATCH 100% (verified). */
int func_00066660(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    extern int ehsys_4175E3DB();
    extern int ehsys_23E69878();
    extern int ehsys_8EA6B1E7();
    extern int ehsys_FDD168CA();
    s32 temp_v0;

    temp_v0 = ehsys_4175E3DB(arg0, 9);
    temp_v0 = ehsys_23E69878(temp_v0, arg5);
    temp_v0 = ehsys_8EA6B1E7(temp_v0, 1, 1, arg3, arg4);
    return ehsys_FDD168CA(temp_v0, arg1, arg2, 0, 0, 0, 0, 0);
}

/* func_00066700 — 8 words. MATCH 100% (verified). */
extern void func_00066720(s32, s32, s32, s32, s32, s32, s32, s32, s32);
int func_00066700(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_00066720(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg5, arg6);
}

/* func_00066720 — 31 words. MATCH 100% (verified). */
void func_00066720(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    extern int ehsys_8EA6B1E7();
    extern int ehsys_FDD168CA();
    s32 v0 = ehsys_8EA6B1E7(arg0, arg5, arg6, arg7, arg8);
    ehsys_FDD168CA(v0, arg1, arg2, 0, arg3, arg4, 0, 0);
}

/* func_00066B30 — 3 words. MATCH 100% (shape: thunk). */
s32 func_00066B30(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_00066B3C — 2 words. MATCH 100% (shape: m2c). */
void func_00066B3C(void) {

}

/* func_00066CB0 — 7 words. MATCH 100% (shape: thunk). */
s32 func_00066CB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return ehsys_3BB2BAC6((arg0 << 6), (arg1 << 6), (arg2 << 6), (arg3 << 6), arg4, -0x1, 0);
}

/* func_00066CCC — 13 words. MATCH 100% (shape: m2c). */
void func_00066CCC(void) {
    ehsys_5DF04F49(&D_398538);
    ehsys_memset(&D_398528, 0, 0xF0);
}

/* func_00066E7C — 18 words. MATCH 100% (shape: m2c). */
void func_00066E7C(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

/* func_0006753C — 5 words. MATCH 100% (shape: thunk). */
s32 func_0006753C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_00066700(arg0, arg1, arg2, 0, 0, 0x7, 0x6);
}

/* func_00067550 — 5 words. MATCH 100% (shape: thunk). */
s32 func_00067550(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return func_00066700(arg0, arg1, arg2, 0, 0x6, 0x7, 0x6);
}

/* func_000680C8 — 5 words. MATCH 100% (shape: thunk). */
s32 func_000680C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_BC8E65D7((arg0 << 6), (arg1 << 6), (arg2 << 6), arg3, -0x1);
}

/* func_000680DC — 16 words. MATCH 100% (shape: m2c). */
void func_000680DC(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_942B03D0(0xF, 0xF);
    ehsys_60B55A50(0xFF000000);
}

/* func_0006811C — 2 words. MATCH 100% (shape: hand). */
void func_0006811C(void) {
    ehsys_C792FA38(0);
}

/* func_000681F8 — 4 words. MATCH 100% (shape: m2c). */
s32 func_000681F8(s32 arg0) {
    return *(s32 *)0x398670 + arg0;
}

/* func_00068208 — 4 words. MATCH 100% (shape: m2c). */
s32 func_00068208(s32 arg0) {
    return arg0 - *(s32 *)0x398670;
}

/* func_000685AC — 5 words. MATCH 100% (shape: thunk). */
s32 func_000685AC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_BC8E65D7((arg0 << 6), (arg1 << 6), (arg2 << 6), arg3, -0x1);
}

/* func_000685C0 — 13 words. MATCH 100% (shape: m2c). */
void func_000685C0(void) {
    ehsys_5DF04F49(&D_398754);
    ehsys_memset(&D_398748, 0, 0xD4);
}

/* func_000685F4 — 18 words. MATCH 100% (shape: m2c). */
void func_000685F4(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}
/* func_0006863C — 0 words. MATCH 100% (shape: twin of func_0002F470). */
void func_0006863C(s32 *arg0) {

    arg0[2] = 0;
}

/* func_000687B4 — 2 words. MATCH 100% (shape: m2c). */
void func_000687B4(void) {

}

/* func_00068CC4 — 5 words. MATCH 100% (shape: thunk). */
s32 func_00068CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return ehsys_BC8E65D7((arg0 << 6), (arg1 << 6), (arg2 << 6), arg3, -0x1);
}

/* func_000687E0 — 2 words. MATCH 100% (verified). */
int func_000687E0(arg0, arg1)
void *arg0;
u16 arg1;
{
    *(u16 *)((char *)arg0 + 2) = arg1;
}

/* func_000687D8 — 2 words. MATCH 100% (verified). */
int func_000687D8(arg0)
void *arg0;
{
    return *(u16 *)((char *)arg0 + 2);
}

/* func_00068CD8 — 16 words. MATCH 100% (shape: m2c). */
void func_00068CD8(void) {
    func_000696A0(&D_398834);
    ehsys_5DF04F49(&D_398868);
    ehsys_memset(&D_39881C, 0, 0x124);
}

/* func_00068D3C — 4 words. MATCH 100% (shape: m2c). */
void func_00068D3C(void) {
    *(s32 *)0x39881C = 1;
}

/* func_00068D4C — 3 words. MATCH 100% (shape: m2c). */
void func_00068D4C(void) {
    func_000696B0(&D_398834);
}

/* func_00068F24 — 7 words. MATCH 100% (shape: thunk). */
s32 func_00068F24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return ehsys_3BB2BAC6((arg0 << 6), (arg1 << 6), (arg2 << 6), (arg3 << 6), arg4, -0x1, 0);
}

/* func_00069238 — 3 words. MATCH 100% (shape: thunk). */
s32 func_00069238(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_00069244 — 13 words. MATCH 100% (shape: m2c). */
void func_00069244(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
}

/* func_00069278 — 12 words. MATCH 100% (shape: m2c). */
void func_00069278(void) {
    func_00069244();
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(-1);
}

/* func_000692A8 — 12 words. MATCH 100% (shape: m2c). */
void func_000692A8(void) {
    func_00069244();
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

/* func_000692D8 — 11 words. MATCH 100% (verified). */
void func_000692D8(s32 *arg0) {
    func_0006863C(arg0);
    *(s16 *)((char *)arg0 + 0x30) = 0;
    *(s16 *)((char *)arg0 + 0x32) = 0;
}

/* func_000696A0 — 2 words. MATCH 100% (shape: m2c). */
int func_000696A0() {
    func_000687B4();
}

/* func_000696A8 — 2 words. MATCH 100% (shape: m2c). */
int func_000696A8() {
    func_000687BC();
}

/* func_000696B0 — 2 words. MATCH 100% (shape: m2c). */
int func_000696B0() {
    func_000687D8();
}

/* func_000696B8 — 2 words. MATCH 100% (shape: m2c). */
int func_000696B8() {
    func_000687E0();
}

/* func_000698C8 — 3 words. MATCH 100% (shape: m2c). */
void func_000698C8(void) {
    func_00069304(&D_398958);
}

/* func_000698D4 — 3 words. MATCH 100% (shape: m2c). */
void func_000698D4(s32 unused0) {
    func_00069448(unused0, &D_398958);
}

/* func_000698E0 — 16 words. MATCH 100% (shape: m2c). */
void func_000698E0(void) {
    func_000696A0(&D_398958);
    ehsys_5DF04F49(&D_39898C);
    ehsys_memset(&D_398940, 0, 0x11C);
}

/* func_00069920 — 4 words. MATCH 100% (shape: m2c). */
void func_00069920(s32 arg0) {
    func_000696A8(&D_398958, arg0);
}

/* func_00069930 — 3 words. MATCH 100% (shape: m2c). */
void func_00069930(void) {
    func_000696B0(&D_398958);
}

/* func_0006993C — 4 words. MATCH 100% (shape: m2c). */
void func_0006993C(s32 arg0) {
    func_000696B8(&D_398958, arg0);
}

/* func_00069AF8 — 7 words. MATCH 100% (shape: thunk). */
s32 func_00069AF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return ehsys_3BB2BAC6((arg0 << 6), (arg1 << 6), (arg2 << 6), (arg3 << 6), arg4, -0x1, 0);
}

/* func_00069B14 — 8 words. MATCH 100% (shape: thunk). */
s32 func_00069B14(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_00069E60 — 3 words. MATCH 100% (shape: thunk). */
s32 func_00069E60(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_97BB99A5(arg0, arg1, 0, 0);
}

/* func_00069E6C — 18 words. MATCH 100% (shape: m2c). */
void func_00069E6C(void) {
    ehsys_D853F15C(1);
    ehsys_C792FA38(0);
    ehsys_C9D9E989(1);
    ehsys_4AA58320(1);
    ehsys_942B03D0(0xE, 0xE);
    ehsys_60B55A50(0xFF000000);
}

/* func_00069EF4 — 13 words. MATCH 100% (shape: m2c). */
void func_00069EF4(void) {
    func_000596A4();
    func_000599A8(func_00069F28);
    *(s32 *)0x398A60 = 0xA;
}

/* func_00069F28 — 10 words. MATCH 100% (verified). */
extern s32 func_0005163C(void);
int func_00069F28(void) {
    u8 b = !func_0005163C();
    return b;
}

/* func_0006A388 — 8 words. MATCH 100% (shape: thunk). */
s32 func_0006A388(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_0006A3A8 — 6 words. MATCH 100% (shape: single-switch). */
s32 func_0006A3A8(s32 arg0) {

    switch (arg0) {
    case 0x239F:
        return 2;
        break;
    }
    return 1;
}

/* func_0006A490 — 20 words. MATCH 100% (shape: m2c). */
s32 func_0006A490(s32 arg0, int arg1, int arg2) {
    func_00039140();
    func_000041B8(arg0, arg1, arg2);
    return 0;
}

/* func_0006A4E0 — 24 words. MATCH 100% (verified). */
s32 func_0006A4E0(s32 arg0, int arg1, int arg2, int arg3) {
    extern void func_00004210(s32, int, int, int);
    func_00039148();
    func_00004210(arg0, arg1, arg2, arg3);
    return 0;
}

/* func_0006A6A8 — 2 words. MATCH 100% (shape: m2c). */
void func_0006A6A8(void) {
    func_00004364();
}

/* func_0006A6B0 — 2 words. MATCH 100% (shape: m2c). */
void func_0006A6B0(void) {
    func_00004410();
}

/* func_0006A6B8 — 2 words. MATCH 100% (shape: m2c). */
s32 func_0006A6B8(void) {
    return 0;
}

/* func_0006ABF0 — 8 words. MATCH 100% (shape: thunk). */
s32 func_0006ABF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ehsys_B89D38DC((arg0 << 6), (arg1 << 6), ((0x1E0 - arg0) << 6), arg2);
}

/* func_0006C8AC — 3 words. MATCH 100% (shape: m2c). */
s32 func_0006C8AC(void) {
    return *(s32 *)0x3A1170;
}

/* func_0006CC2C — 2 words. MATCH 100% (shape: m2c). */
s32 func_0006CC2C(void) {
    return 0;
}

/* func_0006CD0C — 2 words. MATCH 100% (shape: m2c). */
void func_0006CD0C(void) {
    func_00055F0C();
}

/* func_0006CD14 — 3 words. MATCH 100% (shape: m2c). */
void func_0006CD14(void) {
    *(s32 *)0x398A68 = 0;
}

/* func_0006CDB8 — 11 words. MATCH 100% (verified). */
extern void func_0006CC34(void *, s32, s32);
extern void func_0006CD70(void *);
void func_0006CDB8(s32 arg0) {
    char buf[0x200];
    func_0006CC34(buf, 0x100, arg0);
    func_0006CD70(buf);
}

/* func_0006DD1C — 3 words. MATCH 100% (shape: m2c). */
s32 func_0006DD1C(void) {
    return *(s32 *)0x3A13A4;
}

/* func_0006DD28 — 18 words. MATCH 100% (shape: m2c). */
int func_0006DD28() {
    func_00058A68(func_000536B8(4), 2, 1, 0);
    func_000592B4(func_0006DD70);
    *(s32 *)0x3A13A4 = 1;
}

/* func_0006DE5C — 2 words. MATCH 100% (shape: m2c). */
int func_0006DE5C() {
    func_0006DE64();
}

/* func_0006DE64 — 6 words. MATCH 100% (shape: m2c). */
int func_0006DE64(arg0) s32 arg0;
{
    return (s32)((&D_3A13A8)[arg0]);
}

/* func_0006DE7C — 2 words. MATCH 100% (shape: m2c). */
int func_0006DE7C() {
    func_0006DE84();
}

/* func_0006DE84 — 6 words. MATCH 100% (shape: m2c). */
int func_0006DE84(arg0) s32 arg0;
{
    return (s32)((&D_3A13B0)[arg0]);
}

/* func_0006DE9C — 9 words. MATCH 100% (shape: m2c). */
int func_0006DE9C() {
    func_0006DE64(duel_eng_4F664B71());
}

/* func_0006DEC0 — 9 words. MATCH 100% (shape: m2c). */
void func_0006DEC0(void) {
    duel_eng_EDED5379(func_0006DE84());
}

/* func_0006DEE4 — 9 words. MATCH 100% (shape: m2c). */
void func_0006DEE4(void) {
    duel_eng_9ADAC01D(func_0006DE84());
}

/* func_0006DF08 — 9 words. MATCH 100% (shape: m2c). */
void func_0006DF08(void) {
    duel_eng_8ACE7469(func_0006DE84());
}

/* func_0006DF2C — 9 words. MATCH 100% (shape: m2c). */
void func_0006DF2C(void) {
    duel_eng_962F6809(func_0006DE84());
}

/* func_0006DF50 — 9 words. MATCH 100% (shape: m2c). */
void func_0006DF50(void) {
    duel_eng_3EF59AD0(func_0006DE84());
}

/* func_0006DF74 — 9 words. MATCH 100% (shape: m2c). */
int func_0006DF74() {
    duel_eng_95531E08(func_0006DE84());
}

/* func_0006DF98 — 9 words. MATCH 100% (shape: m2c). */
void func_0006DF98(void) {
    duel_eng_0EB5F782(func_0006DE84());
}

/* func_0006DFBC — 9 words. MATCH 100% (shape: m2c). */
void func_0006DFBC(void) {
    duel_eng_302F0BDC(func_0006DE84());
}

/* func_0006DFE0 — 9 words. MATCH 100% (shape: m2c). */
void func_0006DFE0(void) {
    duel_eng_ED3B1B4B(func_0006DE84());
}

/* func_0006E004 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E004(void) {
    duel_eng_1A4C5817(func_0006DE84());
}

/* func_0006E028 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E028(void) {
    duel_eng_4E22C77E(func_0006DE84());
}

/* func_0006E04C — 9 words. MATCH 100% (shape: m2c). */
void func_0006E04C(void) {
    duel_eng_8FEC3AF9(func_0006DE84());
}

/* func_0006E070 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E070(void) {
    duel_eng_780289AD(func_0006DE84());
}

/* func_0006E094 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E094(void) {
    duel_eng_878654F9(func_0006DE84());
}

/* func_0006E0B8 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E0B8(void) {
    duel_eng_CD086A4E(func_0006DE84());
}

/* func_0006E108 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E108(void) {
    duel_eng_A7D6360C(func_0006DE84());
}

/* func_0006E12C — 9 words. MATCH 100% (shape: m2c). */
void func_0006E12C(void) {
    duel_eng_1DE65CD9(func_0006DE84());
}

/* func_0006E150 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E150(void) {
    duel_eng_8CE718D2(func_0006DE84());
}

/* func_0006E174 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E174(void) {
    func_0006DE64(duel_eng_F2783CB1());
}

/* func_0006E198 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E198(void) {
    duel_eng_575C7FF3(func_0006DE84());
}

/* func_0006E1BC — 9 words. MATCH 100% (shape: m2c). */
void func_0006E1BC(void) {
    duel_eng_5A2E1D22(func_0006DE84());
}

/* func_0006E1E0 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E1E0(void) {
    duel_eng_8B100126(func_0006DE84());
}

/* func_0006E204 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E204(void) {
    func_0006DE64(duel_eng_BAF46839());
}

/* func_0006E228 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E228(void) {
    duel_eng_6C7BDC7D(func_0006DE84());
}

/* func_0006E29C — 9 words. MATCH 100% (shape: m2c). */
void func_0006E29C(void) {
    duel_eng_6E78EB9B(func_0006DE84());
}

/* func_0006E2C0 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E2C0(void) {
    duel_eng_94B1D599(func_0006DE84());
}

/* func_0006E2E4 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E2E4(void) {
    duel_eng_A47EF27C(func_0006DE84());
}

/* func_0006E308 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E308(void) {
    duel_eng_C4B3FEFE(func_0006DE84());
}

/* func_0006E32C — 9 words. MATCH 100% (shape: m2c). */
void func_0006E32C(void) {
    duel_eng_B8A3FF78(func_0006DE84());
}

/* func_0006E350 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E350(void) {
    duel_eng_B5DAA640(func_0006DE84());
}

/* func_0006E374 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E374(void) {
    duel_eng_AEDF1F0D(func_0006DE84());
}

/* func_0006E398 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E398(void) {
    duel_eng_1837FC74(func_0006DE84());
}

/* func_0006E3BC — 9 words. MATCH 100% (shape: m2c). */
void func_0006E3BC(void) {
    duel_eng_0534CBA5(func_0006DE84());
}

/* func_0006E3E0 — 2 words. MATCH 100% (shape: m2c). */
void func_0006E3E0(void) {
    duel_eng_09BD4A2A();
}

/* func_0006E3E8 — 2 words. MATCH 100% (shape: m2c). */
void func_0006E3E8(void) {
    duel_eng_66155499();
}

/* func_0006E3F0 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E3F0(void) {
    duel_eng_0796FC63(func_0006DE84());
}

/* func_0006E414 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E414(void) {
    duel_eng_70D96DE6(func_0006DE84());
}

/* func_0006E438 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E438(void) {
    duel_eng_20FA1976(func_0006DE84());
}

/* func_0006E45C — 9 words. MATCH 100% (shape: m2c). */
void func_0006E45C(void) {
    duel_eng_564492D2(func_0006DE84());
}

/* func_0006E480 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E480(void) {
    duel_eng_CFCDD509(func_0006DE84());
}

/* func_0006E4A4 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E4A4(void) {
    duel_eng_12943036(func_0006DE84());
}

/* func_0006E4C8 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E4C8(void) {
    duel_eng_B1CA7A57(func_0006DE84());
}

/* func_0006E4EC — 9 words. MATCH 100% (shape: m2c). */
void func_0006E4EC(void) {
    duel_eng_DE8F840C(func_0006DE84());
}

/* func_0006E510 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E510(void) {
    duel_eng_7214A584(func_0006DE84());
}

/* func_0006E5D4 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E5D4(void) {
    duel_eng_65CABB3B(func_0006DE84());
}

/* func_0006E5F8 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E5F8(void) {
    duel_eng_4BC82DF2(func_0006DE84());
}

/* func_0006E61C — 9 words. MATCH 100% (shape: m2c). */
void func_0006E61C(void) {
    duel_eng_EE219051(func_0006DE84());
}

/* func_0006E674 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E674(void) {
    duel_eng_B774881F(func_0006DE84());
}

/* func_0006E698 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E698(void) {
    duel_eng_A99B16A1(func_0006DE84());
}

/* func_0006E6BC — 9 words. MATCH 100% (shape: m2c). */
void func_0006E6BC(void) {
    duel_eng_50FDA3A6(func_0006DE84());
}

/* func_0006E6E0 — 9 words. MATCH 100% (shape: m2c). */
void func_0006E6E0(void) {
    duel_eng_77689943(func_0006DE84());
}

