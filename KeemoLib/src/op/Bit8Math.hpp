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

			// AND n
			void and_a();
			void and_b();
			void and_c();
			void and_d();
			void and_e();
			void and_h();
			void and_l();
			void and_hl();
			void and_n();

			// OR n
			void or_a();
			void or_b();
			void or_c();
			void or_d();
			void or_e();
			void or_h();
			void or_l();
			void or_hl();
			void or_n();

			// XOR n
			void xor_a();
			void xor_b();
			void xor_c();
			void xor_d();
			void xor_e();
			void xor_h();
			void xor_l();
			void xor_hl();
			void xor_n();

			// CP n
			void cp_a();
			void cp_b();
			void cp_c();
			void cp_d();
			void cp_e();
			void cp_h();
			void cp_l();
			void cp_hl();
			void cp_n();
		}
	}
}