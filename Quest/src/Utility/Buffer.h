#pragma once
#include <cstdint>
#include <cstdlib>
#include <cstring>

namespace Quest
{
	class Buffer
	{
	public:
		Buffer() = default;

		Buffer(uint64_t size)
		{
		}

		Buffer(const void* data, uint64_t size)
			: Data((uint8_t*)data), Size(size)
		{
		}

		Buffer(const Buffer&) = default;

		void Allocate(uint64_t size)
		{
			// Clear buffer before allocation
			Release();

			Data = (uint8_t*)malloc(size);
			Size = size;
		}

		void Release()
		{
			free(Data);

			Data = nullptr;
			Size = 0;
		}

		static Buffer Copy(Buffer buff)
		{
			Buffer newBuff(buff.Size);
			memcpy(newBuff.Data, buff.Data, buff.Size);
			return newBuff;
		}

		template<typename T>
		T* Cast()
		{
			return (T*)Data;
		}

		operator bool() const
		{
			return (bool)Data;
		}
	public:
		// uint8_t* = char*
		uint8_t* Data = nullptr;
		// Size (in bytes) of the buffer
		uint64_t Size = 0;
	};
}