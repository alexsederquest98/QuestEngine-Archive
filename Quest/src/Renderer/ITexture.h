#pragma once
#include "Core/Base.h"

namespace Quest
{
	// will inherit from asset when that exists
	class ITexture
	{
	public:
		virtual ~ITexture() = default;

		virtual void Bind(uint32_t slot = 0) const = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		// create functions
	};
}