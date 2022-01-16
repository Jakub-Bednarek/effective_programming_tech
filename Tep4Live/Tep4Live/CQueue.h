#pragma once

#define DEFAULT_QUEUE_SIZE 5

template<typename T>
class CQueue
{
public:
	CQueue()
	{
		m_queue = new T[DEFAULT_QUEUE_SIZE];
		m_items = 0;
		m_current_size = DEFAULT_QUEUE_SIZE;
	}

	~CQueue()
	{
		delete[] m_queue;
	}

	void add_elem(T value)
	{
		if (m_items + 1 == m_current_size)
		{
			resize();
		}

		for (int i = 0; i < m_items; i++)
		{
			if (value > m_queue[i])
			{
				shift_to_right(i);
				m_queue[i] = value;
				m_items++;

				return;
			}
		}

		m_queue[m_items] = value;
		m_items++;
	}
	
	bool get_elem(T& value)
	{
		if (m_items == 0)
		{
			return false;
		}

		value = m_queue[0];
		m_items--;
		shift_to_left();

		return true;
	}

	bool in_queue(T value)
	{
		for (int i = 0; i < m_items; i++)
		{
			if (m_queue[i] == value)
			{
				return true;
			}
		}

		return false;
	}

	void print_struct()
	{
		for (int i = 0; i < m_items; i++)
		{
			std::cout << m_queue[i] << ' ';
		}

		std::cout << '\n';
	}
private:
	void resize()
	{
		T* new_tab = new T[m_current_size * 2];

		for (int i = 0; i < m_current_size; i++)
		{
			new_tab[i] = m_queue[i];
		}

		delete m_queue;

		m_queue = new_tab;
		m_current_size *= 2;
	}

	void shift_to_left()
	{
		if (m_items == 0)
		{
			return;
		}

		for (int i = 0; i < m_items; i++)
		{
			m_queue[i] = m_queue[i + 1];
		}
	}

	void shift_to_right(int offset)
	{
		if (offset >= m_current_size - 1)
		{
			std::cout << "Fail \n";
			return;
		}

		for (int i = m_items; i >= offset; i--)
		{
			m_queue[i] = m_queue[i - 1];
		}
	}
private:
	T* m_queue;
	int m_items;
	int m_current_size;
};