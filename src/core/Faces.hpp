//------------------------------------------------------------------------
//  Copyright (C) Gabriel Taubin
//  Time-stamp: <2016-09-14 11:39:40 taubin>
//------------------------------------------------------------------------
//
// Faces.hpp
//
// Written by: <Your Name>
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

#ifndef _FACES_HPP_
#define _FACES_HPP_

#include <vector>
#include "iostream"
#include <iterator>
#include <algorithm>
using namespace std;

class Faces {
  
public:
  
          Faces(const int nV, const vector<int>& coordIndex);
  int     getNumberOfVertices()                    const;
  int     getNumberOfFaces()                       const;
  int     getNumberOfCorners()                     const;
  int     getFaceSize(const int iF)                const;
  int     getFaceFirstCorner(const int iF)         const;
  int     getFaceVertex(const int iF, const int j) const;
  int     getCornerFace(const int iC)              const;
  int     getNextCorner(const int iC)              const;

  //
  vector<int> getFirstCornerOfFace()               const;
  vector<int> getCoordIndex()                      const;

private:

  // TODO
  int _numberOfFaces;
  int _numberOfVertices;
  int _numberOfCorners;
  vector<int> _coordIndex;
  vector<int> _firstCornerOfFace; // index of firstCornerOfFace in coordIndex

};

#endif /* _FACES_HPP_ */
