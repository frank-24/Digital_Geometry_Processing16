//------------------------------------------------------------------------
//  Copyright (C) Gabriel Taubin
//  Time-stamp: <2016-09-14 11:41:06 taubin>
//------------------------------------------------------------------------
//
// SaverStl.cpp
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

#include "SaverStl.hpp"

#include "wrl/Shape.hpp"
#include "wrl/Appearance.hpp"
#include "wrl/Material.hpp"
#include "wrl/IndexedFaceSet.hpp"

#include "core/Faces.hpp"
#include "iostream"
#include <string>
using namespace std;

const char* SaverStl::_ext = "stl";

//////////////////////////////////////////////////////////////////////
bool SaverStl::save(const char* filename, SceneGraph& wrl) const {
  bool success = false;
  if(filename!=(char*)0) {

    // Check these conditions

    // 1) the SceneGraph should have a single child
    // 2) the child should be a Shape node
    // 3) the geometry of the Shape node should be an IndexedFaceSet node

    // - construct an instance of the Faces class from the IndexedFaceSet
    // - remember to delete it when you are done with it (if necessary)
    //   before returning

    // 4) the IndexedFaceSet should be a triangle mesh
    // 5) the IndexedFaceSet should have normals per face

    // if (all the conditions are satisfied) {

    if(wrl.isSceneGraph() == false ) {
      cout << "not a SceneGraph node" << endl;
    }

    if(wrl.getNumberOfChildren() != 1) {
      cout << "SceneGraph has more than 1 child" << endl;
    }
    cout << "NumbOfChilder " << wrl.getNumberOfChildren() << endl; 
    vector<Node*> children = wrl.getChildren();
    Shape* shape = (Shape*)children[0];
    if(shape->isShape() == false) {
      cout << "child of SceneGraph not a Shape node" << endl;
    }

    if(shape->hasGeometryIndexedFaceSet() == false ) {
      cout << "shape has no Geometry" << endl;
    }
    IndexedFaceSet* ifs = (IndexedFaceSet*)shape->getGeometry();
    if(ifs->isIndexedFaceSet() == false ) {
      cout << "geometry of the Shape node not an IndexedFaceSet node" << endl;
    }

    if(ifs->isTriangleMesh() == false) {
      cout << "ifs not triangle mesh" << endl;
    }

    vector<float> coord = ifs->getCoord();
    vector<float> normal = ifs->getNormal();
    vector<int> coordIndex = ifs->getCoordIndex();
    // std::set<float> myset;
    // for(int i = 0; i < coordIndex.size(); i++) {
    //   myset.insert(coordIndex[i]);
    // }

    // int nV = myset.size() - 1; // remove the "-1", others are vertex
    int nV = coord.size() / 3;
    cout << "nV" << nV << endl;
    cout << "coordIndex.size() " << coordIndex.size() << endl;
    cout << "normal.size() " << normal.size() << endl; 
    cout << "numberOfFaces " << ifs->getNumberOfFaces() << endl;
    Faces* face = new Faces(nV, ifs->getCoordIndex());

    FILE* fp = fopen(filename,"w");
    if(	fp!=(FILE*)0) {
      string name;
      // // ********* get Name *******
      if(shape->getName() != "" ) {
        name = shape->getName();
      }
      else {
        name = string(filename);
        int lastSlash = name.find_last_of('/');
        int lastDot = name.find_last_of('.');
        name = name.substr(lastSlash + 1, lastDot - lastSlash - 1);
      }
      
      // if set, use ifs->getName()
      // otherwise use filename,
      // but first remove directory and extension

      fprintf(fp,"solid %s\n", name.c_str());

      // TODO ...
      // for each face {
      //   ...
      // }

      // *************** save each face ***************
      int numberOfFaces = face->getNumberOfFaces();
      // cout << "size of coordIndex " << (face->getCoordIndex()).size() << endl;
      // for(int i = 0; i < coordIndex.size(); i++) {
      //   cout << "coordIndex[i]" << coordIndex[i] << endl;
      // }
      // cout << "numberOfFaces" << numberOfFaces << endl;
      // cout << "_firstCornerOfFace.size()" << (face->getFirstCornerOfFace()).size() << endl;
      // for(int i = 0; i < (face->getFirstCornerOfFace()).size(); i++ ) {
      //   cout << (face->getFirstCornerOfFace())[i] << endl;
      // }
      // cout << ""
      // for each face
      for(int idxOfFace = 0; idxOfFace < numberOfFaces; idxOfFace++ ) {
        fprintf(fp, "  %s", "facet normal ");
        fprintf(fp, "%f %f %f\n", normal[idxOfFace * 3], normal[idxOfFace * 3 + 1], normal[idxOfFace * 3 + 2] );
        // outer loop
        fprintf(fp, "\t%s\n", "outer loop");
        // for each vertex
        for(int idxOfVertex = 0; idxOfVertex < face->getFaceSize(idxOfFace); idxOfVertex++ ) {
          fprintf(fp, "\t  %s %f %f %f\n", "vertex", coord[(face->getFaceVertex(idxOfFace, idxOfVertex))*3], 
                                                     coord[(face->getFaceVertex(idxOfFace, idxOfVertex))*3 + 1], 
                                                     coord[(face->getFaceVertex(idxOfFace, idxOfVertex))*3 + 2] );   
        // cout << "face->getFaceVertex(idxOfFace, idxOfVertex)" << face->getFaceVertex(idxOfFace, idxOfVertex) << endl;
        }
        // end loop
        fprintf(fp, "\t%s\n", "endloop" );
        // end facet
        fprintf(fp, "  %s\n", "endfacet");
      }
      // *************** save each face end here ***************
      fprintf(fp, "%s\n", "endsolid" );
      fclose(fp);
      success = true;
    }

    delete face;
    // } endif (all the conditions are satisfied)

  }
  return success;
}
