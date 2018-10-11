#pragma once
#include "../../includes/KeemoDefines.h"

namespace KeemoLib
{
	namespace cpu
	{
		namespace op
		{
			// ADD A, r
			void add_a_n();
			void add_a_a();
			void add_a_b();
			void add_a_c();
			void add_a_d();
			void add_a_e();
			void add_a_h();
			void add_a_l();
			void add_a_hl();

			// ADC A, r
			void adc_a_n();
			void adc_a_a();
			void adc_a_b();
			void adc_a_c();
			void adc_a_d();
			void adc_a_e();
			void adc_a_h();
			void adc_a_l();
			void adc_a_hl();

			// SUB n
			void sub_a();
			void sub_b();
			void sub_c();
			void sub_d();
			void sub_e();
			void sub_h();
			void sub_l();
			void sub_hl();
			void sub_n();

			// SBC n
			void sbc_a();
			void sbc_b();
			void sbc_c();
			void sbc_d();
			void sbc_e();
			void sbc_h();
			void sbc_l();
			void sbc_hl();
			void sbc_n();
		}
	}
}