/** Copyright (C) 2017 Tim Kuipers - Released under terms of the AGPLv3 License */
#ifndef INFILL_DENSITY_PROVIDER_H
#define INFILL_DENSITY_PROVIDER_H

#include "../utils/intpoint.h"
#include "../utils/AABB.h"

namespace cura
{

class DensityProvider
{
public:
    /*!
     * \return the approximate required density of a quadrilateral
     */
    virtual float operator()(const Point& a, const Point& b, const Point& c, const Point& d) const = 0;
    virtual float operator()(const AABB& aabb) const = 0;
    virtual ~DensityProvider()
    {
    };
};

} // namespace cura


#endif // INFILL_DENSITY_PROVIDER_H
