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
     * Defaults to a naive density estimate based on the minimal bounding box of the quadrilateral.
     * 
     * \return the approximate required density of a quadrilateral
     */
    virtual float operator()(const Point& a, const Point& b, const Point& c, const Point& d) const
    {
        AABB aabb_here;
        aabb_here.include(a);
        aabb_here.include(b);
        aabb_here.include(c);
        aabb_here.include(d);
        return operator()(aabb_here);
    }
    virtual float operator()(const AABB& aabb) const = 0;
    virtual ~DensityProvider()
    {
    };
};

} // namespace cura


#endif // INFILL_DENSITY_PROVIDER_H
