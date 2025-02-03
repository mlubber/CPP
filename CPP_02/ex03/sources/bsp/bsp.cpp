#include "../../headers/Point.hpp"

static Fixed	triangle_area(Point const &a, Point const &b, Point const &c)
{
	Fixed result = 

	(a.get_y() * b.get_x() +
	b.get_y() * c.get_x() +
	c.get_y() * a.get_x()) -

	(a.get_x() * b.get_y() +
	b.get_x() * c.get_y() +
	c.get_x() * a.get_y());

	if (result < 0)
		result = result * -1;

	return (result / 2);
}

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
	Fixed total_area = triangle_area(a, b, c);
	Fixed pab_area = triangle_area(point, a, b);
	Fixed pbc_area = triangle_area(point, b, c);
	Fixed pac_area = triangle_area(point, a, c);

	if (pab_area > 0 && pbc_area > 0 && pac_area > 0 &&
		(total_area == (pab_area + pbc_area + pac_area)))
		return (true);
	return (false);
}



