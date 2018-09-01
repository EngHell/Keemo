#include "../includes/Cpu.hpp"
#include "../includes/Memory.hpp"
#include "op/Op.hpp"

namespace KeemoLib
{
	namespace cpu
	{
		uint8_t opcode;
		Registers registers;
		uint16_t ram_size;
		bool raise_pc = true;
	}
}

using namespace KeemoLib;


void cpu::step()
{
	opcode = KeemoLib::memory::readUInt8(registers.pc);

	switch (opcode)
	{
		/***********************************************************************
		 * JMP calls
		 ***********************************************************************/
	case 0xc3:
		op::jp_nn();
		break;
	case 0xc2:
		op::jp_nz_nn();
		break;
	case 0xca:
		op::jp_z_nn();
		break;
	case 0xd2:
		op::jp_nc_nn();
		break;
	case 0xda:
		op::jp_c_nn();
		break;
	case 0xe9:
		op::jp_hl();
		break;
	case 0x18:
		op::jr_n();
		break;
	case 0x20:
		op::jr_nz_n();
		break;
	case 0x28:
		op::jr_z_n();
		break;
	case 0x30:
		op::jr_nc_n();
		break;
	case 0x38:
		op::jr_c_n();
		break;

		/**
		 * 8 bit loads.
		 */

		/**
		 * LD nn,n
		 */
	case 0x06:
		op::ld_b_n();
		break;
	case 0x0e:
		op::ld_c_n();
		break;
	case 0x16:
		op::ld_d_n();
		break;
	case 0x1e:
		op::ld_e_n();
		break;
	case 0x26:
		op::ld_h_n();
		break;
	case 0x2e:
		op::ld_l_n();
		break;

		/***********************************************************************
		 * LD r1,r2
		 ***********************************************************************/

		/*
		 * LD A,r2
		 */
	case 0x7f:
		op::ld_a_a();
		break;
	case 0x78:
		op::ld_a_b();
		break;
	case 0x79:
		op::ld_a_c();
		break;
	case 0x7a:
		op::ld_a_d();
		break;
	case 0x7b:
		op::ld_a_e();
		break;
	case 0x7c:
		op::ld_a_h();
		break;
	case 0x7d:
		op::ld_a_l();
		break;
	case 0x0a:
		op::ld_a_bc();
		break;
	case 0x1a:
		op::ld_a_de();
		break;
	case 0x3e:
		op::ld_a_n();
		break;
	case 0xfa:
		op::ld_a_nn();
		break;
	case 0x7e:
		op::ld_a_hl();
		break;
	case 0xf2:
		op::ld_a_ff_c();
		break;

		/*
		 * LD B,r2
		 */
	case 0x47:
		op::ld_b_a();
		break;
	case 0x40:
		op::ld_b_b();
		break;
	case 0x41:
		op::ld_b_c();
		break;
	case 0x42:
		op::ld_b_d();
		break;
	case 0x43:
		op::ld_b_e();
		break;
	case 0x44:
		op::ld_b_h();
		break;
	case 0x45:
		op::ld_b_l();
		break;
	case 0x46:
		op::ld_b_hl();
		break;
		/*
		 * LD C,r2
		 */
	case 0x4f:
		op::ld_c_a();
		break;
	case 0x48:
		op::ld_c_b();
		break;
	case 0x49:
		op::ld_c_c();
		break;
	case 0x4a:
		op::ld_c_d();
		break;
	case 0x4b:
		op::ld_c_e();
		break;
	case 0x4c:
		op::ld_c_h();
		break;
	case 0x4d:
		op::ld_c_l();
		break;
	case 0x4e:
		op::ld_c_hl();
		break;
		/**
		 * LD D,r2
		 */
	case 0x57:
		op::ld_d_a();
		break;
	case 0x50:
		op::ld_d_b();
		break;
	case 0x51:
		op::ld_d_c();
		break;
	case 0x52:
		op::ld_d_d();
		break;
	case 0x53:
		op::ld_d_e();
		break;
	case 0x54:
		op::ld_d_h();
		break;
	case 0x55:
		op::ld_d_l();
		break;
	case 0x56:
		op::ld_d_hl();
		break;

		/**
		* LD E,r2
		*/
	case 0x5f:
		op::ld_e_a();
		break;
	case 0x58:
		op::ld_e_b();
		break;
	case 0x59:
		op::ld_e_c();
		break;
	case 0x5a:
		op::ld_e_d();
		break;
	case 0x5b:
		op::ld_e_e();
		break;
	case 0x5c:
		op::ld_e_h();
		break;
	case 0x5d:
		op::ld_e_l();
		break;
	case 0x5e:
		op::ld_e_hl();
		break;

		/*
		* LD H,r2
		*/
	case 0x67:
		op::ld_h_a();
		break;
	case 0x60:
		op::ld_h_b();
		break;
	case 0x61:
		op::ld_h_c();
		break;
	case 0x62:
		op::ld_h_d();
		break;
	case 0x63:
		op::ld_h_e();
		break;
	case 0x64:
		op::ld_h_h();
		break;
	case 0x65:
		op::ld_h_l();
		break;
	case 0x66:
		op::ld_h_hl();
		break;

		/*
		* LD L,r2
		*/
	case 0x6f:
		op::ld_l_a();
		break;
	case 0x68:
		op::ld_l_b();
		break;
	case 0x69:
		op::ld_l_c();
		break;
	case 0x6a:
		op::ld_l_d();
		break;
	case 0x6b:
		op::ld_l_e();
		break;
	case 0x6c:
		op::ld_l_h();
		break;
	case 0x6d:
		op::ld_l_l();
		break;
	case 0x6e:
		op::ld_l_hl();
		break;

		/*
		* LD (HL),r2
		*/
	case 0x77:
		op::ld_hl_a();
		break;
	case 0x70:
		op::ld_hl_b();
		break;
	case 0x71:
		op::ld_hl_c();
		break;
	case 0x72:
		op::ld_hl_d();
		break;
	case 0x73:
		op::ld_hl_e();
		break;
	case 0x74:
		op::ld_hl_h();
		break;
	case 0x75:
		op::ld_hl_l();
		break;
	case 0x36:
		op::ld_hl_n();
		break;
	case 0xf8:
		op::ld_hl_sp_n();
		break;

	/*
	* LD (BC),r2
	*/
	case 0x02:
		op::ld_bc_a();
		break;

	/*
	* LD (DE),r2
	*/
	case 0x12:
		op::ld_de_a();
		break;

	/*
	* LD (nn),r2
	*/
	case 0xea:
		op::ld_nn_a();
		break;
	case 0x08:
		op::ld_nn_sp();
		break;

	/*
	* LD (c),r2
	*/
	case 0xe2:
		op::ld_ff_c_a();
		break;

		/*
		* LDX r1,r2
		*/
	case 0x3a:
		op::ldd_a_hl();
		break;
	case 0x32:
		op::ldd_hl_a();
		break;
	case 0x2a:
		op::ldi_a_hl();
		break;
	case 0x22:
		op::ldi_hl_a();
		break;
	case 0xe0:
		op::ld_ff_n_a();
		break;
	case 0xf0:
		op::ld_a_ff_n();
		break;

	/*
	* LD n,nn
	*/
	case 0x01:
		op::ld_bc_nn();
		break;
	case 0x11:
		op::ld_de_nn();
		break;
	case 0x21:
		op::ld_hl_nn();
		break;

	/*
	* LD SP, r2
	*/
	case 0x31:
		op::ld_sp_nn();
		break;
	case 0xf9:
		op::ld_sp_hl();
		break;

	/*
	 * PUSH nn
	 */
	case 0xf5:
		op::push_af();
		break;
	case 0xc5:
		op::push_bc();
		break;
	case 0xd5:
		op::push_de();
		break;
	case 0xe5:
		op::push_hl();
		break;

	/*
	 * POP nn
	 */
	case 0xf1:
		op::pop_af();
		break;
	case 0xc1:
		op::pop_bc();
		break;
	case 0xd1:
		op::pop_de();
		break;
	case 0xe1:
		op::pop_hl();
		break;

	default:
		op::NOP();
		break;
	}

	// I'm going to assume that each function increments the register
	// only when they relly on continuous bits to the pc
	// this means, i just need to increace one more time here, and
	// avoid a shitton of ++registers.pc at the end of each opcode function
	if(raise_pc)
	{
		++registers.pc;
	} else
	{
		raise_pc = true;
	}
}


/*
 * NOP
 */
void cpu::op::NOP()
{
	//lol there shall be nothing.
}