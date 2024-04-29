#pragma once

template<typename K, typename V>
class Map
{
private:

	struct pair
	{
		K key;
		V value;
		int index;
	};
	pair* elements;
	int elem_count;

public:

	Map() {
		this->elements = nullptr;
		this->elem_count = 0;
	}

	~Map() {
		delete[] elements;
	}


	pair* begin() { return &elements[0]; }
	pair* end() { return &elements[elem_count]; }


	V& operator[](K key) {

		for (int i = 0; i < elem_count; i++)
		{
			if (elements[i].key == key)
			{
				return elements[i].value;
				
			}
		}

		Set(key, "");
		return elements[elem_count - 1].value;

	}

	
	void Set(K key, V value) {
		
		for (int i = 0; i < elem_count; i++)
		{
			if (elements[i].key == key)
			{
				elements[i].value = value;
				return;
			}
		}

		pair* temp = new pair[elem_count + 1];
		for (int i = 0; i < elem_count; i++)
		{
			temp[i] = elements[i];
		}

		temp[elem_count].key = key;
		temp[elem_count].value = value;
		temp[elem_count].index = elem_count;

		elem_count++;

		delete elements;
		elements = temp;

	}


	bool Get(const K& Key, V& Value) 
	{
		for (int i = 0; i < elem_count; i++)
		{
			if (elements[i].key == Key)
			{
				Value = elements[i].value;
				return true;
			}
		}
		return false;
	}
	
	int Count()
	{
				return elem_count;
	}

	void Clear() {
		elem_count = 0;	
	}

	bool Delete(const K& Key) {
		for (int i = 0; i < elem_count; i++) {
			if (elements[i].key == Key)
			{
				pair* temp = new pair[elem_count - 1];
				for (int j = 0; j < i; j++)
				{
					temp[j] = elements[j];
				}
				for (int j = i; j < elem_count - 1; j++)
				{
					elements[j+1].index--;
					temp[j] = elements[j + 1];
				}
				elem_count--;
				delete[] elements;
				elements = temp;
				return true;
			}
		}
		return false;
	}
	bool Includes(const Map<K, V>& map) {
		for (int i = 0; i < elem_count; i++) {
			if (elements[i].key != map.elements[i].key)
			{
				return false;
			}
		}
		return true;
	}

	
};

