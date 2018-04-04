#include "KeemoDefines.h"
#include <cstdint>
#include <string>

namespace KeemoLib
{
	namespace cpu
	{
		struct registers
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


		} extern registers;

		void machineCycle();
		void fetchInstruction();
		void decodeInstruction();
		void executeCommand();
		void storeResults();
	}
}