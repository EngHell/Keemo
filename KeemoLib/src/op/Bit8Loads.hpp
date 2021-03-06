﻿#pragma once
#include "../../includes/KeemoDefines.h"

namespace KeemoLib
{
	namespace cpu
	{
		namespace op
		{
			void ld_b_n();
			void ld_c_n();
			void ld_d_n();
			void ld_e_n();
			void ld_h_n();
			void ld_l_n();
			// LD r1,r2
			void ld_a_a();
			void ld_a_b();
			void ld_a_c();
			void ld_a_d();
			void ld_a_e();
			void ld_a_h();
			void ld_a_l();
			void ld_a_hl();
			void ld_a_n();
			void ld_a_nn();
			void ld_a_bc();
			void ld_a_de();
			void ld_a_ff_c();

			void ld_b_a();
			void ld_b_b();
			void ld_b_c();
			void ld_b_d();
			void ld_b_e();
			void ld_b_h();
			void ld_b_l();
			void ld_b_hl();

			void ld_c_a();
			void ld_c_b();
			void ld_c_c();
			void ld_c_d();
			void ld_c_e();
			void ld_c_h();
			void ld_c_l();
			void ld_c_hl();

			void ld_d_a();
			void ld_d_b();
			void ld_d_c();
			void ld_d_d();
			void ld_d_e();
			void ld_d_h();
			void ld_d_l();
			void ld_d_hl();

			void ld_e_a();
			void ld_e_b();
			void ld_e_c();
			void ld_e_d();
			void ld_e_e();
			void ld_e_h();
			void ld_e_l();
			void ld_e_hl();

			void ld_h_a();
			void ld_h_b();
			void ld_h_c();
			void ld_h_d();
			void ld_h_e();
			void ld_h_h();
			void ld_h_l();
			void ld_h_hl();

			void ld_l_a();
			void ld_l_b();
			void ld_l_c();
			void ld_l_d();
			void ld_l_e();
			void ld_l_h();
			void ld_l_l();
			void ld_l_hl();

			void ld_hl_a();
			void ld_hl_b();
			void ld_hl_c();
			void ld_hl_d();
			void ld_hl_e();
			void ld_hl_h();
			void ld_hl_l();
			void ld_hl_n();

			void ld_bc_a();

			void ld_de_a();

			void ld_nn_a();

			void ld_ff_c_a();

			/*
			* LDX r1,r2
			*/
			void ldd_a_hl();
			void ldd_hl_a();
			void ldi_a_hl();
			void ldi_hl_a();
			void ld_ff_n_a();
			void ld_a_ff_n();
		}
	}
}