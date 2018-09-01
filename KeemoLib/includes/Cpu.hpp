#pragma once
#include <cstdint>

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
						uint8_t f;
						uint8_t a;
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
						uint8_t c;
						uint8_t b;
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
						uint8_t e;
						uint8_t d;
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
						uint8_t l;
						uint8_t h;
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
		extern uint16_t ram_size;

		bool raise_pc = true;
		

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

			void NOP();
		}

		inline void CLEAR_FLAGS(uint8_t flags)
		{
			registers.f &= ~(flags);
		}

		inline void SET_FLAGS(uint8_t flags)
		{
			registers.f |= (flags);
		}
	}
}