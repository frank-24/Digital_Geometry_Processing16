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

    FILE* fp = fopen(filename,"w");
    if(	fp!=(FILE*)0) {
      if(wrl->getName() != NULL ) {
        filename = wrl->getName();
      }
      
      // if set, use ifs->getName()
      // otherwise use filename,
      // but first remove directory and extension

      fprintf(fp,"solid %s\n",filename);

      // TODO ...
      // for each face {
      //   ...
      // }
      int numberOfFaces = getNumberOfFaces();

      // for each face
      for(int idxOfFace = 0; idxOfFace < numberOfFaces; idxOfFace++ ) {
        fprintf(fp, "%s", "facet norml ");
        fprintf(fp, "%f, %f, %f\n", _normal[idxOfFace * 3], _normal[idxOfFace * 3 + 1], _normal[idxOfFace * 3 + 2] );
        // outer loop
        fprintf(fp, "%s\n", "outer loop");
        // for each vertex
        for(int idxOfVertex = 0; idxOfVertex < getFaceSize(idxOfFace); idxOfVertex++ ) {
          fprintf(fp, "%s, %f, %f, %f ", "vertex", getFaceVertex(idxOfFace, 0), getFaceVertex(idxOfFace, 1), getFaceVertex(idxOfFace, 2) );   
        }
        // end loop
        fprintf(fp, "%s\n", "endloop" );
        // end facet
        fprintf(fp, "%s\n", "endfacet");
      }


      fclose(fp);
      success = true;
    }

    // } endif (all the conditions are satisfied)

  }
  return success;
}
