#include "KeemoDefines.h"
#include <cstdint>
#include <string>

namespace KeemoLib
{
	namespace cpu
	{
		enum Flags
		{
			Z = 1 << 7,
			N = 1 << 6,
			H = 1 << 5,
			C = 1 << 4
		};

		struct Registers
		{
			struct
			{
				union
				{
					struct
					{
						uint8_t a;
						uint8_t f;
					};
					uint16_t af;
				};
			};

			struct
			{
				union
				{
					struct
					{
						uint8_t b;
						uint8_t c;
					};
					uint16_t bc;
				};
			};

			struct
			{
				union
				{
					struct
					{
						uint8_t d;
						uint8_t e;
					};
					uint16_t de;
				};
			};

			struct
			{
				union
				{
					struct
					{
						uint8_t h;
						uint8_t l;
					};

					uint16_t hl;
				};
			};

			uint16_t sp;
			uint16_t pc;

		};

		struct Instruction
		{
			uint8_t length;
			wchar_t *disassembly;
		};

		extern uint8_t opcode;
		extern Registers registers;
		//Instruction currentInstruction;
		//Instruction instructionDictionary[256];

		void initInstructionDictionary();
		void step();
		void fetchInstruction();
		void decodeInstruction();
		void executeCommand();
		void storeResults();

		namespace op
		{
			void LD_B_n();
			void LD_C_n();
			void LD_D_n();
			void LD_E_n();
			void LD_H_n();
			void LD_L_n();
			// LD r1,r2
			void ld_a_a();
			void ld_a_b();
			void ld_a_c();
			void ld_a_d();
			void ld_a_e();
			void ld_a_h();
			void ld_a_l();
			void ld_a_hl();
			void ld_b_b();
			void ld_b_c();
			void ld_b_d();
			void ld_b_e();
			void ld_b_h();
			void ld_b_l();
			void ld_b_hl();
			void ld_c_b();
			void ld_c_c();
			void ld_c_d();
			void ld_c_e();
			void ld_c_h();
			void ld_c_l();
			void ld_c_hl();
			void ld_d_b();
			void ld_d_c();
			void ld_d_d();
			void ld_d_e();
			void ld_d_h();
			void ld_d_l();
			void ld_d_hl();
			void ld_e_b();
			void ld_e_c();
			void ld_e_d();
			void ld_e_e();
			void ld_e_h();
			void ld_e_l();
			void ld_e_hl();
			void ld_h_b();
			void ld_h_c();
			void ld_h_d();
			void ld_h_e();
			void ld_h_h();
			void ld_h_l();
			void ld_h_hl();
			void NOP();
		}
	}
}