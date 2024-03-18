#include <iostream>
#include <cstdint>

struct Data
{
	int i;
	std::string src;
};

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	{
		Data *data = new Data;

		data->src = "la plus belle chose au monde";
		data->i = 96;
		uintptr_t no = serialize(data);
		Data *ptr = deserialize(no);
		std::cout << ptr->src << std::endl;
		std::cout << ptr->i << std::endl;
		delete data;
	}
	{
		Data data;

		std::cout << &data << std::endl;
		deserialize(serialize(&data));
		std::cout << &data << std::endl;
	}
	return 0;
}
