#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:

		MateriaSource();
		MateriaSource(const MateriaSource& other);
		virtual ~MateriaSource();

		MateriaSource&	operator=(const MateriaSource& other);

		void			learnMateria(AMateria*) override;
		AMateria*		createMateria(std::string const & type) override;

	private:

		AMateria*		_materia[4];

};

#endif