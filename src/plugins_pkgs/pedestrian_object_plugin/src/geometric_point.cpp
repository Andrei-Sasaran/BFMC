/**
 * Copyright (c) 2019, Bosch Engineering Center Cluj and BFMC organizers
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:

 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.

 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.

 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE
*/

#include "geometric_point.h"

namespace gazebo
{
    namespace pedestrian
    {   
        ::std::ostream& operator<<(::std::ostream& o, GeometricPoint gp)
        {
            o << "(" << gp.x << ", " << gp.y << ")";
            return o; 
        }

        GeometricPoint::GeometricPoint(){}

        GeometricPoint::GeometricPoint(const double &x, const double &y)
        {
            this->setPoint(x, y);
        } 

        void GeometricPoint::setPoint(GeometricPoint geometric_point)
        {
            this->x = geometric_point.x;
            this->y = geometric_point.y;
        }

        void GeometricPoint::setPoint(const double &x, const double &y)
        {
            this->x = x;
            this->y = y;
        }

        double GeometricPoint::operator[](unsigned int index)
        {
            if(index == 0)
            {
                return this->x;
            }
            else if (index == 1)
            {
                return this->y;
            }
            else
            {
                throw std::out_of_range("for operator[] in geometric point only allowed indexes : {0, 1}");
            }
        }
        
        void GeometricPoint::print()
        {
            std::cerr << this->x << " " << this->y;
        }
    }; // namespace pedestrian
}; // namespace gazebo