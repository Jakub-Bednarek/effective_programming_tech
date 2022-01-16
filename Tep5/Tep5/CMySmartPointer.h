#pragma once

template<typename T>
class CMySmartPointer
{
private:
	class CRefCounter
	{
	public:
		CRefCounter()
		{
			i_count = 0;
		}

		int i_get() const
		{
			return i_count;
		}

		int i_dec()
		{
			return --i_count;
		}

		int i_add()
		{
			return ++i_count;
		}
	private:
		int i_count;
	};
public:
	CMySmartPointer() = delete;

	CMySmartPointer(T* pcPointer)
	{
		pc_pointer = pcPointer;
		pc_counter = new CRefCounter();
		pc_counter->i_add();
	}

	CMySmartPointer(const CMySmartPointer& pcOther)
	{
		*this = pcOther;
	}

	CMySmartPointer& operator=(const CMySmartPointer& pcOther)
	{
		if (*this == pcOther)
			return *this;

		if (pc_counter != nullptr && pc_counter->i_dec() == 0)
		{

			delete pc_pointer;
			delete pc_counter;
		}

		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;
		pc_counter->i_add();

		return *this;
	}

	bool operator==(const CMySmartPointer& pcOther)
	{
		if (&pc_pointer != &pcOther.pc_pointer || &pc_counter != &pcOther.pc_counter)
		{
			return false;
		}

		return true;
	}

	bool operator!=(const CMySmartPointer& pcOther)
	{
		return !(*this == pcOther);
	}

	~CMySmartPointer()
	{
		if (pc_counter->i_dec() == 0)
		{
			delete pc_pointer;
			delete pc_counter;
		}
	}

	T& operator*()
	{
		return (*pc_pointer);
	}

	T* operator->()
	{
		return pc_pointer;
	}
private:
	CRefCounter* pc_counter;
	T* pc_pointer;
};