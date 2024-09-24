#include "../inc/Array.hpp"

Array::Array() {
}

Array::Array(size_t size) {
}

Array::Array(const Array& other) {
  *this = other;
}

Array& Array::operator=(const Array& other) {
  if (this != &other) {
  }
  return *this;
}

Array::~Array() {
}
