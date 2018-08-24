#pragma once
#include "../../includes/KeemoDefines.h"

namespace KeemoLib
{
	namespace cpu
	{
		namespace op
		{
			void ld_bc_nn();
			void ld_de_nn();
			void ld_hl_nn();
			void ld_sp_nn();
			void ld_sp_hl();
			void ld_hl_sp_n();
			void ld_nn_sp();
			void push_af();
			void push_bc();
			void push_de();
			void push_hl();
			void pop_af();
			void pop_bc();
			void pop_de();
			void pop_hl();
		}
	}
}