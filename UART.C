/*
 * UART.C
 *
 *  Created on: 8 nov 2019
 *      Author: Miguel Gil
 */

#include "UART.h"


void UART_init(uart_channel_t uart_channel, uint32_t system_clk, uart_baud_rate_t baud_rate){


	switch(uart_channel)
	{
		case UART_0:
			SIM->SCGC4 |= SIM_SCGC4_UART3_MASK;
			UART3->C2 |= UART_C2_RE(0) | UART_C2_TE(0);
			UART3->BDH |= 0x1f00 & baud_rate;
			UART3->BDL |=0xff & baud_rate;

				switch(baud_rate)
				{
				case BD_4800:
					UART3->C4 |= 0xE;
				break;
				case BD_9600:
					UART3->C4 |= 0x17;
				break;
				case BD_5600:
					UART3->C4 |= 0x0C;
				break;
				case BD_115200:
					UART3->C4 |= 0xD;
				break;
				}

			UART3->C2 |= UART_C2_RE(1) | UART_C2_TE(1);
		break;

		case UART_1:
			SIM->SCGC4 |= SIM_SCGC4_UART1_MASK;
			UART1->C2 |= UART_C2_RE(0) | UART_C2_TE(0);
			UART1->BDH |= 0x1f00 & baud_rate;
			UART1->BDL |=0xff & baud_rate;

				switch(baud_rate)
				{
				case BD_4800:
					UART1->C4 |= 0xE;
				break;
				case BD_9600:
					UART1->C4 |= 0x17;
				break;
				case BD_5600:
					UART1->C4 |= 0x0C;
				break;
				case BD_115200:
					UART1->C4 |= 0xD;
				break;
				}

			UART1->C2 |= UART_C2_RE(1) | UART_C2_TE(1);

		break;

		case UART_2:
			SIM->SCGC4 |= SIM_SCGC4_UART2_MASK;
			UART2->C2 |= UART_C2_RE(0) | UART_C2_TE(0);
			UART2->BDH |= 0x1f00 & baud_rate;
			UART2->BDL |=0xff & baud_rate;

				switch(baud_rate)
				{
				case BD_4800:
					UART2->C4 |= 0xE;
				break;
				case BD_9600:
					UART2->C4 |= 0x17;
				break;
				case BD_5600:
					UART2->C4 |= 0x0C;
				break;
				case BD_115200:
					UART2->C4 |= 0xD;
				break;
				}

			UART2->C2 |= UART_C2_RE(1) | UART_C2_TE(1);
		break;

		case UART_3:
			SIM->SCGC4 |= SIM_SCGC4_UART3_MASK;
			UART3->C2 |= UART_C2_RE(0) | UART_C2_TE(0);
			UART3->BDH |= 0x1f00 & baud_rate;
			UART3->BDL |=0xff & baud_rate;

				switch(baud_rate)
				{
				case BD_4800:
					UART3->C4 |= 0xE;
				break;
				case BD_9600:
					UART3->C4 |= 0x17;
				break;
				case BD_5600:
					UART3->C4 |= 0x0C;
				break;
				case BD_115200:
					UART3->C4 |= 0xD;
				break;
				}

			UART3->C2 |= UART_C2_RE(1) | UART_C2_TE(1);
		break;

		case UART_4:
			SIM->SCGC4 |= SIM_SCGC4_UART4_MASK;
			UART4->C2 |= UART_C2_RE(0) | UART_C2_TE(0);
			UART4->BDH |= 0x1f00 & baud_rate;
			UART4->BDL |=0xff & baud_rate;

				switch(baud_rate)
				{
				case BD_4800:
					UART4->C4 |= 0xE;
				break;
				case BD_9600:
					UART4->C4 |= 0x17;
				break;
				case BD_5600:
					UART4->C4 |= 0x0C;
				break;
				case BD_115200:
					UART4->C4 |= 0xD;
				break;
				}

			UART4->C2 |= UART_C2_RE(1) | UART_C2_TE(1);
		break;

		case UART_5:
			SIM->SCGC4 |= SIM_SCGC4_UART5_MASK;
			UART5->C2 |= UART_C2_RE(0) | UART_C2_TE(0);
			UART5->BDH |= 0x1f00 & baud_rate;
			UART5->BDL |=0xff & baud_rate;

				switch(baud_rate)
				{
				case BD_4800:
					UART5->C4 |= 0xE;
				break;
				case BD_9600:
					UART5->C4 |= 0x17;
				break;
				case BD_5600:
					UART5->C4 |= 0x0C;
				break;
				case BD_115200:
					UART5->C4 |= 0xD;
				break;
				}

			UART5->C2 |= UART_C2_RE(1) | UART_C2_TE(1);
		break;

	}

}

void UART_interrupt_enable(uart_channel_t uart_channel)
{
	switch (uart_channel)
	{
		case UART_0:
			while (!(UART0_S1 & UART_S1_RDRF_MASK))
				{
					UART0->C2 |= UART_C2_TCIE(1) | UART_C2_RIE(1) | UART_C2_RE(1);
				}
		break;

		case UART_1:
			while (!(UART1_S1 & UART_S1_RDRF_MASK))
				{
					UART1->C2 |= UART_C2_TCIE(1) | UART_C2_RIE(1) | UART_C2_RE(1);
				}
		break;

		case UART_2:
			while (!(UART2_S1 & UART_S1_RDRF_MASK))
				{
					UART2->C2 |= UART_C2_TCIE(1) | UART_C2_RIE(1) | UART_C2_RE(1);
				}
		break;

		case UART_3:
			while (!(UART3_S1 & UART_S1_RDRF_MASK))
				{
					UART3->C2 |= UART_C2_TCIE(1) | UART_C2_RIE(1) | UART_C2_RE(1);
				}
		break;

		case UART_4:
			while (!(UART4_S1 & UART_S1_RDRF_MASK))
				{
					UART4->C2 |= UART_C2_TCIE(1) | UART_C2_RIE(1) | UART_C2_RE(1);
				}
		break;

		case UART_5:
			while (!(UART5_S1 & UART_S1_RDRF_MASK))
				{
					UART5->C2 |= UART_C2_TCIE(1) | UART_C2_RIE(1) | UART_C2_RE(1);
				}
		break;
	}
}

void UART_put_char (uart_channel_t uart_channel, uint8_t character)
{

	switch (uart_channel)
		{
			case UART_0:
				while(!(UART0_S1 & UART_S1_TC_MASK))
					{
						UART0->D = character ;
					}
			break;

			case UART_1:
				while(!(UART1_S1 & UART_S1_TC_MASK))
					{
						UART1->D = character;
					}
			break;

			case UART_2:
				while(!(UART2_S1 & UART_S1_TC_MASK))
					{
						UART2->D = character;
					}
			break;

			case UART_3:
				while(!(UART3_S1 & UART_S1_TC_MASK))
					{
						UART3->D = character;
					}
			break;

			case UART_4:
				while(!(UART4_S1 & UART_S1_TC_MASK))
					{
						UART4->D = character;
					}
			break;

			case UART_5:
				while(!(UART5_S1 & UART_S1_TC_MASK))
					{
						UART5->D = character;
					}
			break;
	}
}

void UART_put_string(uart_channel_t uart_channel, int8_t* string)
{
	switch (uart_channel)
			{
				case UART_0:

				break;

				case UART_1:

				break;

				case UART_2:

				break;

				case UART_3:

				break;

				case UART_4:

				break;

				case UART_5:

				break;
		}
}
