#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef unsigned long uintptr_t;

typedef struct s_Data 
{
	std::string name;
	std::string login;
	int level;
} Data;

class Serializer {
public:
  Serializer();
  Serializer(const Serializer& other);
  Serializer& operator=(const Serializer& other);
  ~Serializer();
  uintptr_t serialize(Data* ptr);
  Data* deserialize(uintptr_t raw);

private:
};

#endif // !SERIALIZER_HPP
#define SERIALIZER_HPP
