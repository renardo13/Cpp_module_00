#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_nb = 0;
}

Fixed::Fixed(int nb) : _nb(nb)
{
	std::cout << "Fixed constructor called" << std::endl;
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
	this->_nb = raw * (1 << Fixed::_fracBits);
	std::cout << this->_nb << std::endl;
}
