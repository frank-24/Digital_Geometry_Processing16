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
  // cout << "in Faces()" << endl;
  _numberOfVertices = nV;
  _coordIndex = coordIndex;

  _firstCornerOfFace.clear();
  _firstCornerOfFace.push_back(0);
  //getNumberOfFaces
  int numberOfFaces = 0;
  // cout << "coordIndex.size() " << coordIndex.size() << endl;
  for(int i = 0; i < coordIndex.size(); i++) {
    // cout << "coordIndex[i] " << coordIndex[i] << endl; 
    if(coordIndex[i] == -1) {
      // cout << "find -1" << endl;
      numberOfFaces++;
      _firstCornerOfFace.push_back(i + 1);
    }
  }
  _numberOfFaces = numberOfFaces;
  // cout << "_numberOfFaces ___" << _numberOfFaces << endl;
  // getNumberOfCorners
  _numberOfCorners = coordIndex.size() - numberOfFaces;
}

int Faces::getNumberOfVertices() const {
  // TODO
  // return 0;
  // cout << "in getNumberOfVertices()" << endl;
  return _numberOfVertices;
}

int Faces::getNumberOfFaces() const {
  // TODO
  // return 0;
  // cout << "in getNumberOfFaces()" << endl;

  return _numberOfFaces;
}

int Faces::getNumberOfCorners() const {
  // TODO
  // return 0;
  // cout << "in getNumberOfCorners()" << endl;

  return _numberOfCorners;
}

int Faces::getFaceSize(const int iF) const {
  // TODO
  // return 0;

  // is an error
  // cout << "getFaceSize()" << endl;
  // if(iF < 0 || iF >= getNumberOfFaces() ) {
  //   return -1;
  // }

  // int numberOfFaces = 0;
  // // vector<int>::iterator vit = _coordIndex.begin();
  // int i = 0;
  // for(; i < _coordIndex.size(); i++){
  //     if(numberOfFaces == iF) {
  //       break;
  //     }
  //     if(_coordIndex[i] == -1) {
  //         numberOfFaces++;
  //     }
  // }
  // int count = 0;
  // while(_coordIndex[i] != -1 ) {
  //   count++;
  //   i++;
  // }
  return _firstCornerOfFace[iF + 1] - _firstCornerOfFace[iF] - 1;
}

int Faces::getFaceFirstCorner(const int iF) const {
  // TODO
  // return -1;

  // is an error
  // cout << "in getFaceFirstCorner()" << endl;
  if(iF < 0 || iF >= getNumberOfFaces() ) {
    return -1;
  }

  int numberOfFaces = 0;
  int i = 0;
  for(; i < _coordIndex.size(); i++){
      if(numberOfFaces == iF) {
        return _coordIndex[i];
      }
      if(_coordIndex[i] == -1) {
          numberOfFaces++;
      }
  }
}

int Faces::getFaceVertex(const int iF, const int j) const {
  // TODO
  // return -1;

  // is an error
  // cout << "in getFaceVertex()" << endl;
  if(iF < 0 || iF >= getNumberOfFaces() || j < 0 || j > getNumberOfCorners()  ) {
    return -1;
  }

  // int numberOfFaces = 0;
  // int i = 0;
  // for(; i < _coordIndex.size(); i++){
  //     if(numberOfFaces == iF) {
  //       break;
  //     }
  //     if(_coordIndex[i] == -1) {
  //         numberOfFaces++;
  //     }
  // }

  // for(int idx = 0; idx < j; idx++ ) {
  //   if(idx == j) {
  //     return _coordIndex[i];
  //   }
  //   i++;
  // }
  // cout << "Faces::getFaceVertex" << _firstCornerOfFace[iF] << endl;
  // cout << "coordIndex " << _coordIndex[_firstCornerOfFace[iF] + j] << endl;
  return _coordIndex[_firstCornerOfFace[iF] + j];

}

int Faces::getCornerFace(const int iC) const {
  // TODO
  // return -1;
  
  // is an error input
  // cout << "in getCornerFace()" << endl;
  if(iC < 0 || iC >= getNumberOfCorners() ) {
    return -1;
  }

  int faceIndex = 0;
  int cornerIndex = 0;

  for(int i = 0; i < _coordIndex.size(); i++ ) {  
      if(cornerIndex == iC) {
        return faceIndex;
      }

      if(_coordIndex[i] == -1) {
        faceIndex++;
      }
      else {
        cornerIndex++;        
      }
  }

}

int Faces::getNextCorner(const int iC) const {
  // TODO
  return -1;
  // if(iC < 0 || iC >= getNumberOfCorners() ) {
  //   return -1;
  // }

  // int faceIndex = 0;
  // int cornerIndex = 0;
  // int firstCornerIndex = 0;

  // for(int i = 0; i < _coordIndex.size(); i++ ) {  
  //     if(cornerIndex == iC) {
  //       return faceIndex;
  //     }

  //     if(_coordIndex[i] == -1) {
  //       faceIndex++;
  //     }
  //     else {
  //       cornerIndex++;        
  //     }
  // }

}

vector<int> Faces::getFirstCornerOfFace() const {
  return _firstCornerOfFace;
}

vector<int> Faces::getCoordIndex() const {
  return _coordIndex;
}

