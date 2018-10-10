#pragma once
#include "../../includes/KeemoDefines.h"

namespace KeemoLib
{
	namespace cpu
	{
		namespace math
		{
			inline void add_uint8(uint8_t& destination, uint8_t value)
			{
				const uint16_t result = destination + value;
				
				if(result)
				{
					// we check carry at bit 7
					if(result & 0xff00)
						SET_FLAGS(C);
					else
						CLEAR_FLAGS(C);

					// we check carry at bit 3
					if(result & (1<<4))
						SET_FLAGS(H);
					else
						CLEAR_FLAGS(H);

					CLEAR_FLAGS(Z);
				} 
				else
				{
					CLEAR_FLAGS(H | C);
					SET_FLAGS(Flags::Z);
				}

				CLEAR_FLAGS(Flags::N);

				destination = result;
			}
		}
	}
}
