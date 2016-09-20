//------------------------------------------------------------------------
//  Copyright (C) Gabriel Taubin
//  Time-stamp: <2016-09-11 13:18:08 taubin>
//------------------------------------------------------------------------
//
// PolygonMesh.hpp
//
// Software developed for the Fall 2016 Brown University course
// ENGN 2501 Digital Geometry Processing
// Copyright (c) 2016, Gabriel Taubin
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the Brown University nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL GABRIEL TAUBIN BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef _POLYGONMESH_HPP_
#define _POLYGONMESH_HPP_

#include <vector>
#include "Faces.hpp"
#include "Graph.hpp"

using namespace std;

class PolygonMesh : public Faces {
  
public:

             PolygonMesh(vector<float>& coord, vector<int>& coordIndex);
     float   getVertexCoord(const int iV, const int j) const;
     float   getCornerCoord(const int iC, const int j) const;
     int     getEdge(const int iC)                     const;
     int     getEdge(const int iV0, const int iV1)     const;
     int     getVertex0(const int iE)                  const;
     int     getVertex1(const int iE)                  const;
     int     getNumberOfEdgeFaces(const int iE)        const;
     int     getEdgeFace(const int iE, const int j)    const;
     bool    isBoundaryEdge(const int iE)              const;
     bool    isRegularEdge(const int iE)               const;
     bool    isSingularEdge(const int iE)              const;
     bool    isBoundaryVertex(const int iV)            const;
     bool    isRegularVertex(const int iV)             const;
     bool    isSingularVertex(const int iV)            const;
     bool    isRegular()                               const;
     bool    hasBoundary()                             const;
     Graph*  makeDualGraph();
  
private:

  // TODO

};

#endif /* _POLYGONMESH_HPP_ */
