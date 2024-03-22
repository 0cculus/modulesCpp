template <typename T>
Array<T>::Array() : sz(0), array(NULL)
{
}

template <typename T>
Array<T>::Array(size_t n) : sz(n), array(new T[n]) 
{
}

template <typename T>
Array<T>::Array(const Array<T>& copy) : sz(0), array(NULL)
{
	(*this) = copy;
}

template <typename T>
Array<T>::~Array()
{
	if (this->array)
		delete[] this->array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& copy)
{
	if (this->array)
		delete[] this->array;
	this->array = new T[copy.size()];
	this->sz = copy.size();
	for (size_t i = 0; i < copy.size(); i++)
		this->array[i] = copy.array[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t index) const
{
	if (index >= this->sz)
		throw std::invalid_argument("Error: out of range");
	return (this->array[index]);
}

template <typename T>
size_t Array<T>::size() const
{
	return (this->sz);
}
