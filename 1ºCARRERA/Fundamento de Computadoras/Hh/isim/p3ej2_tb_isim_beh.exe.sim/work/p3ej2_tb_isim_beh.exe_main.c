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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *STD_STANDARD;
char *UNISIM_P_0947159679;
char *IEEE_P_2592010699;
char *IEEE_P_1242562249;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    ieee_p_1242562249_init();
    unisim_p_0947159679_init();
    unisim_a_1801614988_1818890047_init();
    unisim_a_3762448000_2971575191_init();
    unisim_a_2661327437_0605893366_init();
    work_a_1955912572_3212880686_init();
    unisim_a_3828308815_1222000726_init();
    unisim_a_2211589156_2274105955_init();
    work_a_1541266661_3212880686_init();
    unisim_a_1391413833_1848422758_init();
    work_a_1589229043_3212880686_init();
    unisim_a_2562466605_1496654361_init();
    unisim_a_3988446151_0546328132_init();
    unisim_a_3376478592_3856742516_init();
    unisim_a_2312877582_0635394241_init();
    unisim_a_2216329674_1385100001_init();
    work_a_2281161299_3212880686_init();
    unisim_a_1717296735_4086321779_init();
    work_a_2346352722_3212880686_init();
    work_a_3098026446_3212880686_init();


    xsi_register_tops("work_a_3098026446_3212880686");

    STD_STANDARD = xsi_get_engine_memory("std_standard");
    UNISIM_P_0947159679 = xsi_get_engine_memory("unisim_p_0947159679");
    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");

    return xsi_run_simulation(argc, argv);

}
