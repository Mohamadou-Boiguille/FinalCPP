#include "../inc/Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *ptr)
{
	try
	{
		if (!ptr)
			throw std::invalid_argument("Le pointeur fourni est nul.");

		uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
		return raw;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Erreur lors de la sérialisation : " << e.what() << std::endl;
		return 0;
	}
}

Data *Serializer::deserialize(uintptr_t raw)
{
	try
	{
		Data *deserialized = reinterpret_cast<Data *>(raw);
		return deserialized;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Erreur lors de la désérialisation : " << e.what() << std::endl;
		return NULL;
	}
}
