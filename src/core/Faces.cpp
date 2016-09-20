//------------------------------------------------------------------------
//  Copyright (C) Gabriel Taubin
//  Time-stamp: <2016-09-14 11:40:30 taubin>
//------------------------------------------------------------------------
//
// Faces.cpp
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

#include <math.h>
#include "Faces.hpp"
  
Faces::Faces(const int nV, const vector<int>& coordIndex) {
  // TODO
  _numberOfVertices = nV;
  _coordIndex = coordIndex;
}

int Faces::getNumberOfVertices() const {
  // TODO
  // return 0;
  return _numberOfVertices;
}

int Faces::getNumberOfFaces() const {
  // TODO
  // return 0;
  int numberOfFaces = 0;
  for(vector<int>::iterator vit = _coordIndex.begin(); vit != _coordIndex.end(); vit++){
      if(*vit == -1) {
          numberOfFaces++;
      }
  }
  return numberOfFaces;
}

int Faces::getNumberOfCorners() const {
  // TODO
  // return 0;
  int numberOfFaces = 0;
  int numberOfCorners = 0;
  for(vector<int>::iterator vit = _coordIndex.begin(); vit != _coordIndex.end(); vit++){
      if(*vit == -1) {
          numberOfFaces++;
      }
  }

  numberOfCorners = _coordIndex.size() - numberOfFaces;
  return numberOfCorners;
}

int Faces::getFaceSize(const int iF) const {
  // TODO
  // return 0;

  // is an error
  if(iF < 0 || iF >= getNumberOfFaces() ) {
    return -1;
  }

  int numberOfFaces = 0;
  vector<int>::iterator vit = _coordIndex.begin();
  for(; vit != _coordIndex.end(); vit++){
      if(numberOfFaces == iF) {
        break;
      }
      if(*vit == -1) {
          numberOfFaces++;
      }
  }
  int count = 0;
  while(*vit != -1 ) {
    count++;
    vit++;
  }
  return count;
}

int Faces::getFaceFirstCorner(const int iF) const {
  // TODO
  // return -1;

  // is an error
  if(iF < 0 || iF >= getNumberOfFaces() ) {
    return -1;
  }

  int numberOfFaces = 0;
  vector<int>::iterator vit = _coordIndex.begin();
  for(; vit != _coordIndex.end(); vit++){
      if(numberOfFaces == iF) {
        return *vit;
      }
      if(*vit == -1) {
          numberOfFaces++;
      }
  }
}

int Faces::getFaceVertex(const int iF, const int j) const {
  // TODO
  // return -1;

  // is an error
  if(iF < 0 || iF >= getNumberOfFaces() || j < 0 || j > getNumberOfCorners(iF)  ) {
    return -1;
  }

  int numberOfFaces = 0;
  vector<int>::iterator vit = _coordIndex.begin();
  for(; vit != _coordIndex.end(); vit++){
      if(numberOfFaces == iF) {
        break;
      }
      if(*vit == -1) {
          numberOfFaces++;
      }
  }

  for(int idx = 0; idx < j; idx++ ) {
    if(idx == j) {
      return *vit;
    }
    vit++;
  }

}

int Faces::getCornerFace(const int iC) const {
  // TODO
  // return -1;
  
  // is an error input
  if(iC < 0 || iC >= getNumberOfCorners() ) {
    return -1;
  }

  int faceIndex = 0;
  int cornerIndex = 0;

  for(vector<int>::iterator vit = _coordIndex.begin(); vit != _coordIndex.end(); vit++){
      if(cornerIndex == iC) {
        return faceIndex;
      }

      if(*vit == -1) {
        faceIndex++;
      }
      else {
        cornerIndex++;        
      }
  }

}

int Faces::getNextCorner(const int iC) const {
  // TODO
  // return -1;
  if(iF < 0 || iF >= getNumberOfFaces() ) {
    return -1;
  }
}

