#pragma once
#include <cstdint>

namespace Quest
{
	// Signed integers
	using int8 = std::int8_t;
	using int16 = std::int16_t;
	using int32 = std::int32_t;
	using int64 = std::int64_t;

	// Fast signed integers
	using int8f = std::int_fast8_t;
	using int16f = std::int_fast16_t;
	using int32f = std::int_fast32_t;
	using int64f = std::int_fast64_t;

	// Unsigned integers
	using uint8 = std::uint8_t;
	using uint16 = std::uint16_t;
	using uint32 = std::uint32_t;
	using uint64 = std::uint64_t;

	// Fast unsigned integers
	using uint8f = std::uint_fast8_t;
	using uint16f = std::uint_fast16_t;
	using uint32f = std::uint_fast32_t;
	using uint64f = std::uint_fast64_t;

	// Floats
	using f32 = float;
	using f64 = double;
}