#pragma once
#include "Core/Base.h"

namespace Quest
{
	class IBuffer
	{
	public:
		virtual ~IBuffer() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetData(void* buffer, uint64_t size) = 0;
		virtual uint64_t GetSize() = 0;

		// Create functions
	};
}