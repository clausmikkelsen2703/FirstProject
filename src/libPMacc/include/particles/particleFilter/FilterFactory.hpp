/**
 * Copyright 2013 René Widera
 *
 * This file is part of libPMacc. 
 * 
 * libPMacc is free software: you can redistribute it and/or modify 
 * it under the terms of of either the GNU General Public License or 
 * the GNU Lesser General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, or 
 * (at your option) any later version. 
 * libPMacc is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU General Public License and the GNU Lesser General Public License 
 * for more details. 
 * 
 * You should have received a copy of the GNU General Public License 
 * and the GNU Lesser General Public License along with libPMacc. 
 * If not, see <http://www.gnu.org/licenses/>. 
 */ 
 
/* 
 * File:   FilterFactory.hpp
 * Author: widera
 *
 * Created on 19. Oktober 2011, 09:34
 */

#pragma once

#include "particles/boostExtension/InheritGenerators.hpp"
#include "particles/boostExtension/JoinVectors.hpp"
#include "particles/particleFilter/system/TrueFilter.hpp"
#include "particles/particleFilter/system/DefaultFilter.hpp"

#include "particles/memory/frames/NullFrame.hpp"

#include <boost/mpl/list.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/front_inserter.hpp>

namespace PMacc
{

namespace bmpl = boost::mpl;

template<typename UserTypeList = bmpl::vector<NullFrame> >
    class FilterFactory
{
public:

    typedef
    typename LinearInherit
    <
        typename JoinVectors<
           bmpl::vector<DefaultFilter<> >,
           UserTypeList,
           bmpl::vector<TrueFilter>
        >::type
    >::type FilterType;

};

}//namespace PMacc


