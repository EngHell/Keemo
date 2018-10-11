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

			inline void add_carry_uint8(uint8_t& destination, uint8_t value)
			{
				add_uint8(destination, value + (CHECK_FLAG(C)? 1: 0));
			}

			inline void sub_uint8(uint8_t& dest, uint8_t value)
			{
				if(value > dest)
					SET_FLAGS(C);
				else
					CLEAR_FLAGS(C);

				if( (value & 0xf) > (dest & 0xf ))
					SET_FLAGS(H);
				else
					CLEAR_FLAGS(H);

				SET_FLAGS(N);

				dest -= value;

				if(dest)
					CLEAR_FLAGS(Z);
				else
					SET_FLAGS(Z);

			}

			inline void sub_carry_uint8(uint8_t& dest, uint8_t value)
			{
				sub_uint8(dest, value + (CHECK_FLAG(C)? 1 : 0));
			}
		}
	}
}
