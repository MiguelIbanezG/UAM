/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/migue/OneDrive/Escritorio/e1_tb (1).vhd";
extern char *IEEE_P_3499444699;
extern char *IEEE_P_1242562249;
extern char *STD_STANDARD;

unsigned char ieee_p_1242562249_sub_319130236_1035706684(char *, unsigned char , unsigned char );
char *ieee_p_3499444699_sub_2213602152_3536714472(char *, char *, int , int );


static void work_a_1054008256_3212880686_p_0(char *t0)
{
    char t6[16];
    char t25[16];
    char t27[16];
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    int64 t17;
    int t18;
    int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned char t22;
    unsigned char t23;
    char *t24;
    char *t26;
    char *t28;
    char *t29;
    int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned char t33;
    int t34;

LAB0:    t1 = (t0 + 3432U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 7612);
    *((int *)t2) = 0;
    t3 = (t0 + 7616);
    *((int *)t3) = 15;
    t4 = 0;
    t5 = 15;

LAB4:    if (t4 <= t5)
        goto LAB5;

LAB7:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 2448U);
    t3 = *((char **)t2);
    t17 = *((int64 *)t3);
    t2 = (t0 + 3240);
    xsi_process_wait(t2, t17);

LAB22:    *((char **)t1) = &&LAB23;

LAB1:    return;
LAB5:    xsi_set_current_line(48, ng0);
    t7 = (t0 + 7612);
    t8 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t6, *((int *)t7), 4);
    t9 = (t6 + 12U);
    t10 = *((unsigned int *)t9);
    t10 = (t10 * 1U);
    t11 = (4U != t10);
    if (t11 == 1)
        goto LAB8;

LAB9:    t12 = (t0 + 4872);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t8, 4U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2448U);
    t3 = *((char **)t2);
    t17 = *((int64 *)t3);
    t2 = (t0 + 3240);
    xsi_process_wait(t2, t17);

LAB12:    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB6:    t2 = (t0 + 7612);
    t4 = *((int *)t2);
    t3 = (t0 + 7616);
    t5 = *((int *)t3);
    if (t4 == t5)
        goto LAB7;

LAB19:    t18 = (t4 + 1);
    t4 = t18;
    t7 = (t0 + 7612);
    *((int *)t7) = t4;
    goto LAB4;

LAB8:    xsi_size_not_matching(4U, t10, 0);
    goto LAB9;

LAB10:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t11 = *((unsigned char *)t3);
    t2 = (t0 + 2152U);
    t7 = *((char **)t2);
    t2 = (t0 + 7612);
    t18 = *((int *)t2);
    t19 = (t18 - 0);
    t10 = (t19 * 1);
    xsi_vhdl_check_range_of_index(0, 15, 1, *((int *)t2));
    t20 = (1U * t10);
    t21 = (0 + t20);
    t8 = (t7 + t21);
    t22 = *((unsigned char *)t8);
    t23 = ieee_p_1242562249_sub_319130236_1035706684(IEEE_P_1242562249, t11, t22);
    if (t23 == 0)
        goto LAB14;

LAB15:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t11 = *((unsigned char *)t3);
    t2 = (t0 + 2152U);
    t7 = *((char **)t2);
    t2 = (t0 + 7612);
    t18 = *((int *)t2);
    t19 = (t18 - 0);
    t10 = (t19 * 1);
    xsi_vhdl_check_range_of_index(0, 15, 1, *((int *)t2));
    t20 = (1U * t10);
    t21 = (0 + t20);
    t8 = (t7 + t21);
    t22 = *((unsigned char *)t8);
    t23 = ieee_p_1242562249_sub_319130236_1035706684(IEEE_P_1242562249, t11, t22);
    t33 = (!(t23));
    if (t33 != 0)
        goto LAB16;

LAB18:
LAB17:    goto LAB6;

LAB11:    goto LAB10;

LAB13:    goto LAB11;

LAB14:    t9 = (t0 + 7620);
    t13 = ((STD_STANDARD) + 384);
    t14 = (t0 + 7612);
    t15 = xsi_int_to_mem(*((int *)t14));
    t16 = xsi_string_variable_get_image(t6, t13, t15);
    t26 = ((STD_STANDARD) + 1008);
    t28 = (t27 + 0U);
    t29 = (t28 + 0U);
    *((int *)t29) = 1;
    t29 = (t28 + 4U);
    *((int *)t29) = 18;
    t29 = (t28 + 8U);
    *((int *)t29) = 1;
    t30 = (18 - 1);
    t31 = (t30 * 1);
    t31 = (t31 + 1);
    t29 = (t28 + 12U);
    *((unsigned int *)t29) = t31;
    t24 = xsi_base_array_concat(t24, t25, t26, (char)97, t9, t27, (char)97, t16, t6, (char)101);
    t29 = (t6 + 12U);
    t31 = *((unsigned int *)t29);
    t32 = (18U + t31);
    xsi_report(t24, t32, (unsigned char)1);
    goto LAB15;

LAB16:    xsi_set_current_line(55, ng0);
    t9 = (t0 + 1832U);
    t12 = *((char **)t9);
    t30 = *((int *)t12);
    t34 = (t30 + 1);
    t9 = (t0 + 4936);
    t13 = (t9 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    *((int *)t16) = t34;
    xsi_driver_first_trans_fast(t9);
    goto LAB17;

LAB20:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 7638);
    xsi_report(t2, 22U, 0);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 7660);
    t7 = ((STD_STANDARD) + 384);
    t8 = (t0 + 1832U);
    t9 = *((char **)t8);
    t4 = *((int *)t9);
    t8 = xsi_int_to_mem(t4);
    t12 = xsi_string_variable_get_image(t6, t7, t8);
    t14 = ((STD_STANDARD) + 1008);
    t15 = (t27 + 0U);
    t16 = (t15 + 0U);
    *((int *)t16) = 1;
    t16 = (t15 + 4U);
    *((int *)t16) = 18;
    t16 = (t15 + 8U);
    *((int *)t16) = 1;
    t5 = (18 - 1);
    t10 = (t5 * 1);
    t10 = (t10 + 1);
    t16 = (t15 + 12U);
    *((unsigned int *)t16) = t10;
    t13 = xsi_base_array_concat(t13, t25, t14, (char)97, t2, t27, (char)97, t12, t6, (char)101);
    t16 = (t6 + 12U);
    t10 = *((unsigned int *)t16);
    t20 = (18U + t10);
    xsi_report(t13, t20, (unsigned char)0);
    xsi_set_current_line(61, ng0);

LAB26:    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB21:    goto LAB20;

LAB23:    goto LAB21;

LAB24:    goto LAB2;

LAB25:    goto LAB24;

LAB27:    goto LAB25;

}

static void work_a_1054008256_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(64, ng0);

LAB3:    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t3 = (3 - 3);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 5000);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast(t8);

LAB2:    t13 = (t0 + 4744);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1054008256_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(65, ng0);

LAB3:    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t3 = (2 - 3);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 5064);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast(t8);

LAB2:    t13 = (t0 + 4760);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1054008256_3212880686_p_3(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(66, ng0);

LAB3:    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t3 = (1 - 3);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 5128);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast(t8);

LAB2:    t13 = (t0 + 4776);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1054008256_3212880686_p_4(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(67, ng0);

LAB3:    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t3 = (0 - 3);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t0 + 5192);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t7;
    xsi_driver_first_trans_fast(t8);

LAB2:    t13 = (t0 + 4792);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_1054008256_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1054008256_3212880686_p_0,(void *)work_a_1054008256_3212880686_p_1,(void *)work_a_1054008256_3212880686_p_2,(void *)work_a_1054008256_3212880686_p_3,(void *)work_a_1054008256_3212880686_p_4};
	xsi_register_didat("work_a_1054008256_3212880686", "isim/e1_tb_profesores_isim_beh.exe.sim/work/a_1054008256_3212880686.didat");
	xsi_register_executes(pe);
}
