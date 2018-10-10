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
		}
	}
}