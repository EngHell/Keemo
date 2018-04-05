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
			void NOP();
		}
	}
}