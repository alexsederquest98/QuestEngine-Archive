#pragma once
#include "Core/Base.h"

namespace Quest
{
	class IBuffer
	{
	public:
		virtual ~IBuffer() = default;

		virtual void SetData(void* buffer, uint64_t size, uint64_t offset = 0) = 0;
		virtual void Bind() const = 0;

		virtual uint64_t GetSize() = 0;

		// Create functions
	};
}