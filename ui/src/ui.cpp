#include "ui.h"

namespace ui {

	MemoryArena::MemoryArena(size_t capacity):
		m_capacity(capacity)
	{
		m_memory = new char[m_capacity];
		m_pointer = m_memory;
	}
	
	MemoryArena::~MemoryArena()
	{
		delete[] m_memory;
	}


	UserInterface::UserInterface() {

	}

}