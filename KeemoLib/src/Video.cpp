#include "../includes/Video.hpp"

namespace KeemoLib
{
	namespace video
	{
		uint8_t decode_pixel_with_shift(uint8_t first_byte, uint8_t second_byte, uint8_t shift);
		void create_row_color_data(uint8_t row_first_byte, uint8_t row_second_byte, uint8_t* result);

		uint8_t decode_pixel_with_shift(uint8_t first_byte, uint8_t second_byte, uint8_t shift)
		{
			uint8_t leftmost = (second_byte >> (shift - 1));
			leftmost = leftmost & (1 << 1);

			uint8_t rightmost = (first_byte >> shift);
			rightmost = rightmost & (1);

			uint8_t result = leftmost | rightmost;

			return result;
		}


		void create_row_color_data(uint8_t row_first_byte, uint8_t row_second_byte, uint8_t* result)
		{
			for (int i = 0; i < 8; i++)
			{
				result[i] = decode_pixel_with_shift(row_first_byte, row_second_byte, 7 - i);
			}
		}

		void create_tile_color_data(const uint8_t* tile_start, uint8_t** result)
		{
			for (int i = 0; i < 8; i++)
			{
				create_row_color_data(tile_start[i * 2], tile_start[(i * 2) + 1], result[i]);
			}
		}
	}
}
