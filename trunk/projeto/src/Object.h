/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#ifndef _OBJECT_H
#define _OBJECT_H

#include <iostream>


namespace GBF {

class Object
{
    public:
        Object();

        virtual ~Object();

        template<class T>
        inline bool isInstance() {
            if (dynamic_cast<T*>(this)){
                return true;
            } else {
                return false;
            }
        };

        template<class T>
        inline bool isInstance(T) {
            if (dynamic_cast<T*>(this)){
                return true;
            } else {
                return false;
            }
        };

        template<class T>
        inline bool isInstance(T * t) {
            if (dynamic_cast<T*>(this)){
                return true;
            } else {
                return false;
            }
        };

};

} // namespace GBF
#endif
