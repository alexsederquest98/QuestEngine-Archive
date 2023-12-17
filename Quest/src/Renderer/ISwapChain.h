#pragma once

namespace Quest
{
	class ISwapChain
	{
	public:
		virtual ~ISwapChain() = 0;

		virtual void Present() = 0;
		virtual void Resize() = 0;
	};
}