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
			
			inline uint8_t cp_uint8(const uint8_t a, const uint8_t b)
			{
				uint8_t result = 0;

				if(b > a)
					SET_FLAGS(C);
				else
					CLEAR_FLAGS(C);

				if( (b&0xf) > (a&0xf) )
					SET_FLAGS(H);
				else
					CLEAR_FLAGS(H);

				SET_FLAGS(N);

				result = a - b;

				if(result)
					CLEAR_FLAGS(Z);
				else
					SET_FLAGS(Z);

				return result;
				
			}

			inline void sub_uint8(uint8_t& dest, uint8_t value)
			{
				dest = cp_uint8(dest, value);
			}

			inline void sub_carry_uint8(uint8_t& dest, uint8_t value)
			{
				sub_uint8(dest, value + (CHECK_FLAG(C)? 1 : 0));
			}

			inline void and_uint8(uint8_t& dest, const uint8_t value)
			{
				dest &= value;

				if(dest)
					CLEAR_FLAGS(Z);
				else
					SET_FLAGS(Z);

				SET_FLAGS(H);
				CLEAR_FLAGS(N);
				CLEAR_FLAGS(C);
			}

			inline void or_uint8(uint8_t& dest, const uint8_t value)
			{
				dest |= value;

				if(dest)
					CLEAR_FLAGS(Z);
				else
					SET_FLAGS(Z);

				CLEAR_FLAGS(N);
				CLEAR_FLAGS(H);
				CLEAR_FLAGS(C);
			}

			inline void xor_uint8(const uint8_t value)
			{
				registers.a ^= value;

				if(registers.a)
					CLEAR_FLAGS(Z);
				else
					SET_FLAGS(Z);

				CLEAR_FLAGS(N);
				CLEAR_FLAGS(H);
				CLEAR_FLAGS(C);
			}

			inline void inc_uint8(uint8_t& reg)
			{
				if( (reg & 0xf) == 0xf)
					SET_FLAGS(H);
				else
					CLEAR_FLAGS(H);

				CLEAR_FLAGS(N);

				reg++;

				if(reg)
					CLEAR_FLAGS(Z);
				else
					SET_FLAGS(Z);
			}

			inline void dec_uint8(uint8_t& reg)
			{
				if(reg & 0xf)
					SET_FLAGS(H);
				else
					CLEAR_FLAGS(H);

				SET_FLAGS(N);
				--reg;

				if(reg)
					CLEAR_FLAGS(Z);
				else
					SET_FLAGS(Z);
			}
		}
	}
}
