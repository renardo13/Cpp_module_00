#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Fixed constructor called" << std::endl;
	this->_nb = 0;
}
Fixed::Fixed(const int nb)
{
	std::cout << "Default constructor called" << std::endl;
	this->_nb = nb << Fixed::_fracBits;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_nb = 0;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(other);
}

Fixed& Fixed::operator=(Fixed const& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_nb = src.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_nb);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nb = raw * roundf(1 << Fixed::_fracBits);
	std::cout << this->_nb << std::endl;
}
