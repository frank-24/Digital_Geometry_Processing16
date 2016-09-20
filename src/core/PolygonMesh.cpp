//------------------------------------------------------------------------
//  Copyright (C) Gabriel Taubin
//  Time-stamp: <2016-09-11 13:22:06 taubin>
//------------------------------------------------------------------------
//
// PolygonMesh.cpp
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

#include "PolygonMesh.hpp"

PolygonMesh::PolygonMesh(vector<float>& coord, vector<int>& coordIndex):
  Faces(coord.size(),coordIndex) {
  // TODO
}

float PolygonMesh::getVertexCoord(const int iV, const int j) const {
  // TODO
  return 0.0f;
}

float PolygonMesh::getCornerCoord(const int iC, const int j) const {
  // TODO
  return 0.0f;
}

int PolygonMesh::getEdge(const int iC) const {
  // TODO
  return -1;
}

int PolygonMesh::getEdge(const int iV0, const int iV1) const {
  // TODO
  return -1;
}

int PolygonMesh::getVertex0(const int iE) const {
  // TODO
  return -1;
}

int PolygonMesh::getVertex1(const int iE) const {
  // TODO
  return -1;
}

int PolygonMesh::getNumberOfEdgeFaces(const int iE) const {
  // TODO
  return 0;
}

int PolygonMesh::getEdgeFace(const int iE, const int j) const {
  // TODO
  return -1;
}

bool PolygonMesh::isBoundaryEdge(const int iE) const {
  // TODO
  return false;
}

bool PolygonMesh::isRegularEdge(const int iE) const {
  // TODO
  return false;
}

bool PolygonMesh::isSingularEdge(const int iE) const {
  // TODO
  return false;
}

bool PolygonMesh::isBoundaryVertex(const int iV) const {
  // TODO
  return false;
}

bool PolygonMesh::isRegularVertex(const int iV) const {
  // TODO
  return false;
}

bool PolygonMesh::isSingularVertex(const int iV) const {
  // TODO
  return false;
}

bool PolygonMesh::isRegular() const {
  // TODO
  return false;
}

bool PolygonMesh::hasBoundary() const {
  // TODO
  return false;
}

Graph* PolygonMesh::makeDualGraph() {
  // TODO
  return (Graph*)0;
}

