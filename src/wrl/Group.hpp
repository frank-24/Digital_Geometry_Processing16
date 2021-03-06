//------------------------------------------------------------------------
//  Copyright (C) Gabriel Taubin
//  Time-stamp: <2016-09-10 21:47:29 taubin>
//------------------------------------------------------------------------
//
// Group.hpp
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

#ifndef _Group_h_
#define _Group_h_

// Group {
//   eventIn      MFNode  addChildren
//   eventIn      MFNode  removeChildren
//   exposedField MFNode  children       []
//   field        SFVec3f bboxCenter      0  0  0
//   field        SFVec3f bboxSize       -1 -1 -1
// }

#include <vector>
#include "Node.hpp"

using namespace std;

class Group : public Node {

protected:

  vector<pNode> _children;
  Vec3f         _bboxCenter;
  Vec3f         _bboxSize;

public:
  
  Group();
  virtual ~Group();

  vector<pNode>&        getChildren();
  Node*                 getChild(const string& name) const;
  int                   getNumberOfChildren() const;
  pNode                 operator[](const int i);
  void                  addChild(pNode child);
  void                  removeChild(pNode child);

  Vec3f&                getBBoxCenter();
  Vec3f&                getBBoxSize();
  float                 getBBoxDiameter();
  void                  setBBoxCenter(Vec3f& value);
  void                  setBBoxSize(Vec3f& value);
  void                  clearBBox();
  bool                  hasEmptyBBox() const;
  void                  appendBBoxCoord(vector<float>& coord);
  void                  updateBBox(vector<float>& coord);
  virtual void          updateBBox();

  virtual bool          isGroup() const { return    true; };
  virtual string        getType() const { return "Group"; };
  typedef bool          (*Property)(Group& group);
  typedef void          (*Operator)(Group& group);

  virtual void    printInfo(string indent);
};

#endif /* _Group_h_ */
