#ifndef MEMORY_MAP
#define MEMORY_MAP

#define DEVICE_ENUM_BASE	0x0880	// EALLOW
#define FLASH_BASE			0x0A80	// EALLOW
#define CODE_SECURITY_BASE	0x0AE0	// EALLOW
#define ADC_BASE			0x0B00
#define XINTF_BASE			0x0B20	// EALLOW

#define F28335_CPU_TIMER_0_BASE	0x0C00
#define F28335_CPU_TIMER_1_BASE	0x0C08
#define F28335_CPU_TIMER_2_BASE	0x0C10

#define F28335_PIE_BASE			0x0CE0
#define F28335_PIE_VECTOR_BASE			0x0D00	// EALLOW
#define DMA_BASE				0x1000	// EALLOW

#define ECAN_A_BASE			0x6000
#define ECAN_B_BASE			0x6200
#define EPWM_1_BASE			0x6800
#define EPWM_2_BASE			0x6840
#define EPWM_3_BASE			0x6880
#define EPWM_4_BASE			0x68C0
#define EPWM_5_BASE			0x6900
#define EPWM_6_BASE			0x6940
#define ECAP_1_BASE			0x6A00
#define ECAP_2_BASE			0x6A20
#define ECAP_3_BASE			0x6A40
#define ECAP_4_BASE			0x6A60
#define ECAP_5_BASE			0x6A80
#define ECAP_6_BASE			0x6AA0
#define EQEP_1_BASE			0x6B00
#define EQEP_2_BASE			0x6B40
#define F28335_GPIO_BASE			0x6F80

#define SYSCTL_BASE			0x7010
#define SPI_A_BASE			0x7040
#define SCI_A_BASE			0x7050
#define EXTI_BASE			0x7070
#define ADC_SHADOW_BASE		0x7100	// TODO
#define SCI_B_BASE			0x7750
#define SCI_C_BASE			0x7770
#define I2C_A_BASE			0x7900

#define MCBSP_A_BASE		0x5000
#define MCBSP_B_BASE		0x5040
#define DMA_EPWM_1_BASE		0x5800
#define DMA_EPWM_2_BASE		0x5840
#define DMA_EPWM_3_BASE		0x5880
#define DMA_EPWM_4_BASE		0x58C0
#define DMA_EPWM_5_BASE		0x5900
#define DMA_EPWM_6_BASE		0x5940

//>>>>>>>>>>>>>>>>>> SYSCTL >>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define F28335_WATCHDOG_BASE		(SYSCTL_BASE + 0x12)
#define F28335_PLL_BASE				(SYSCTL_BASE)

#define OSCCLK				(150)
#define CLKIN				(OSCCLK)
#define CLKIN_MAX			(150)

#endif
