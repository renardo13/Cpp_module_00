#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:
			int		_nb;
			static const int  _fracBits = 8;

	public:
			Fixed(void);
			Fixed(int nb);
			~Fixed(void);
			Fixed(Fixed const &Fixed);
			Fixed& operator=(Fixed const &Fixed);
			int getRawBits( void ) const;
			void setRawBits( int const raw );
};

#endif
