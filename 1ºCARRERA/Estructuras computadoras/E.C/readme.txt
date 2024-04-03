Quartus Prime Design Suite Release 17.0 README.TXT
==================================================
Note: Intel FPGA(R) Quartus Prime includes Quartus Prime Standard and 
Quartus Prime Pro editions. 

This readme.txt file accompanies the Pro, Standard, and Lite editions
of the Quartus Prime Design Suite version 17.0.

Although we have made every effort to ensure that this version
of the Intel FPGA(R) software operates correctly, you can encounter
problems that we have not discovered. If you have a question or
problem that is not answered by the information provided in
this readme.txt file, please go to www.altera.com and click Support, 
or submit a service request at mysupport.altera.com.

This readme.txt file contains the following information:
*  Quartus Prime Design Suite Contents--lists the set of Intel FPGA design tools.
*  Technical Documentation--directs you where to find documentation for 
   Intel FPGA design tools.
*  System Requirements--lists the system requirements.

Quartus Prime Design Suite Contents
===================================
*  Intel(R) Quartus Prime Design Software (which includes the 
   Intel(R) FPGA IP Library and Intel(R) Nios(R) II Embedded Design Suite)
*  ModelSim (*)- Intel(R) FPGA Edition Simulation Tool
*  ModelSim (*)- Intel(R) FPGA Starter Edition Simulation Tool
*  Intel(R) FPGA SoC Embedded Design Suite (Pro and Standard Editions)
*  DSP Builder for Intel(R) FPGAs
*  Intel(R) FPGA SDK for OpenCL
                 
You can download the Quartus Prime software, as well as tools such as the
JNEye Link Analysis Tool or Stand-Alone Programmer, from the 
Intel FPGA Download Center on the Intel FPGA website: 
https://www.altera.com/downloads/download-center.html

Technical Documentation
=======================
*  Intel Quartus Prime Software and Device Support Release Notes version 17.0
   Provides information about new features and enhancements, known issues, 
   workarounds, device support information, memory requirements for design 
   processing, and timing and power model status. 
   This document is available on the Intel FPGA website:
   https://www.altera.com/en_US/pdfs/literature/rn/rn_qts_dev_support.pdf

*  Intel FPGA SDK for OpenCL Release Notes version 17.0
   Provides information about new features and enhancements, errata, and 
   workarounds. This document is available on the Intel FPGA website:
   https://www.altera.com/en_US/pdfs/literature/rn/rn_aocl.pdf

*  Intel SoC Embedded Design Suite Release Notes
   Provides information about new features and enhancements and bug fixes
   for both Pro and Standard Editions.
   This document is available on the Intel FPGA website:
   https://www.altera.com/en_US/pdfs/literature/rn/rn_soc_eds.pdf
   
*  Intel SoC HPS Device Errata in the Knowledge Base
   You can find information, errata, and workarounds by searching the 
   Intel FPGA Knowledge Base:
   https://www.altera.com/kdb   
   
*  Intel Nios II Embedded Design Suite Release Notes
   Provides information about new features and enhancements, errata, and 
   workarounds. This document is available on the Intel FPGA website:
   https://www.altera.com/en_US/pdfs/literature/rn/rn_nios2eds.pdf
      
*  Intel FPGA IP Release Notes
   Provides information about new features and enhancements, errata, and 
   workarounds. This document is available on the Intel FPGA website:
   https://www.altera.com/en_US/pdfs/literature/rn/rn_ip.pdf
   
*  DSP Builder for Intel FPGAs Release Notes
   Provides information about new features and enhancements, errata, and 
   workarounds. This document is available on the Intel FPGA website:
   https://www.altera.com/en_US/pdfs/literature/rn/rn_dsp_builder.pdf
   
*  Intel FPGA Software Installation and Licensing Manual 17.0
   Provides information about installing and licensing your Intel FPGA design
   software. This document is available on the Intel FPGA website:
   https://www.altera.com/en_US/pdfs/literature/manual/quartus_install.pdf 
   
*  Intel FPGA Quartus Prime Software Download and Installation Quick Start Guide
   Provides directions on how to download and install both Windows and Linux 
   versions of the ACDS software. This document is available on the Intel FPGA website:
   http://dl.altera.com/static/quick_start_guide/quick_start_guide_17.0_en.pdf

*  Introduction to the Intel FPGA Quartus Prime Software
   Provides an introduction to using the Quartus Prime software. 
   This document is available on the Intel FPGA website:   
   https://www.altera.com/en_US/pdfs/literature/manual/quartus2_introduction.pdf
   
*  Intel FPGA Quartus Prime Handbook
   Provides detailed information about all aspects of
   the Quartus Prime software. This document is available on the Intel FPGA website:
   https://www.altera.com/products/design-software/fpga-design/quartus-prime/support.html

*  AN 320: OpenCore Plus Evaluation of Megafunctions
   https://www.altera.com/en_US/pdfs/literature/an/an320.pdf
   
*  AN 343: OpenCore Evaluation of AMPP Megafunctions
   https://www.altera.com/en_US/pdfs/literature/an/an343.pdf
   
System Requirements
===================
Operating system support
------------------------
*  Windows 7 SP1(64 bit)
*  Windows 8.1 (64 bit)
*  Windows 10 (64 bit)
*  Windows Server 2008 R2 SP1 (64 bit)
*  Red Hat Enterprise Linux 5.10 (64 bit)
*  Red Hat Enterprise Linux 6.5 (64 bit)
*  Red Hat Enterprise Linux 7.3 (64 bit)


Notes:
    * Quartus Prime Pro is not supported under Red Hat Linux 5.10
    * Nios II EDS Standard is not supported under Windows 10. 
      Nios II EDS(Standard and Pro) are not supported under 
      Red Hat Enterprise Linux 7.3. 
    * Red Hat Enterprise Linux 7.3 only supports KDE Desktop Manager	  
    * OpenCL is supported only under Windows 7 SP1, Windows 8.1,
      Windows 10, RedHat Enterprise Linux 6.8 and 7.3  
    * SoC Embedded Design Suites (Standard and Pro) are only supported 
	  under Windows 7 SP1, Windows 10, Windows Server 2008 R2 SP1, 
	  Red Hat Enterprise Linux 5.10 and 6.8 and require 32-bit library files.
    * ModelSim-Intel FPGA is supported only under  Windows 7 SP1, Windows 8,
      Windows 10, Windows Server 2008 R2 SP1, Red Hat Enterprise Linux 5.10, 6.8,
	  and 7.3. All require 32-bit library files.

Support information including an updated list of limitations for all
editions of the Quartus Prime software can be found on the Intel FPGA website:
https://www.altera.com/support/support-resources/download/os-support.html

DSP Builder 
Supports MathWorks releases R2015a, R2014b.

    
FLEXlm
   For more information on the FLEXlm license server software, refer 
   to the Intel FPGA Software Installation and Licensing manual:
   https://www.altera.com/en_US/pdfs/literature/manual/quartus_install.pdf 
   
KDE or GNOME Display Manager
   *  Version included with your Linux operating system installation.
   
Useful Links
============
*  You can create a MyAltera account where you can file a service request, 
   register for a class, download software, and more on the Intel FPGA website.
   http://www.altera.com/getmylicense
   
*  You can view video demonstrations for Quartus Prime and Nios II software on 
   the Intel FPGA website:
   https://www.altera.com/support/training/demonstrations/dem-index.html
   
*  You can download reference designs that show efficient solutions for 
   common system design problems from Intel FPGA and our partners on the 
   Intel FPGA website:
   https://www.altera.com/products/reference-designs/all-reference-designs.html
   
*  You can compare the features of the Pro, Standard and Lite Editions of
   the Quartus Prime Software on the Intel FPGA website:
   https://www.altera.com/en_US/pdfs/literature/po/ss_quartussevswe.pdf 
 
