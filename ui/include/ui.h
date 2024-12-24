
#ifndef UI_USERINTERFACE
#define UI_USERINTERFACE

#include <iostream>
namespace ui {

	constexpr size_t MEMORYARENA_DEFAULT_CAPACITY = 512;

	class MemoryArena {
	public:
		MemoryArena(size_t capacity);
		MemoryArena(MemoryArena&) = delete;
		MemoryArena(MemoryArena&&) = delete;

		~MemoryArena();

		template<typename T>
		T* RequestMemory(size_t ammount) {
			size_t size = ammount * sizeof(T);
			if (m_capacity - (m_pointer - m_memory) < size)
				return nullptr;

			T* address = (T*)m_pointer;
			m_pointer += size;
			return address;
		}
	private:
		char* m_memory = nullptr;
		char* m_pointer = nullptr;
		size_t m_capacity = 0;
	public:		
		friend std::ostream& operator<<(std::ostream& os, const MemoryArena& arena) {
			os	<< '[' << (void*)arena.m_memory
				<< ',' << (void*)arena.m_pointer
				<< ',' << (int)(arena.m_pointer - arena.m_memory)
				<< ',' << arena.m_capacity << ']';
			return os;
		}
	};

	class UserInterface
	{
	public:
		UserInterface();
		UserInterface(MemoryArena memory);

	private:

	};
}

#endif