//------------------------------------------------------------------------
//  Copyright (C) Gabriel Taubin
//  Time-stamp: <2016-09-14 11:59:06 taubin>
//------------------------------------------------------------------------
//
// LoaderStl.cpp
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

#include <stdio.h>
#include "Tokenizer.hpp"
#include "LoaderStl.hpp"
#include "StrException.hpp"

#include "wrl/Shape.hpp"
#include "wrl/Appearance.hpp"
#include "wrl/Material.hpp"
#include "wrl/IndexedFaceSet.hpp"

#include "iostream"
// reference
// https://en.wikipedia.org/wiki/STL_(file_format)

const char* LoaderStl::_ext = "stl";

bool LoaderStl::load(const char* filename, SceneGraph& wrl) {
  bool success = false;

  // clear the scene graph
  wrl.clear();
  wrl.setUrl("");

  FILE* fp = (FILE*)0;
  try {

    // open the file
    if(filename==(char*)0) throw new StrException("filename==null");
    fp = fopen(filename,"r");
    if(fp==(FILE*)0) throw new StrException("fp==(FILE*)0");

    // use the io/Tokenizer class to parse the input ascii file

    Tokenizer tkn(fp);
    // first token should be "solid"
    if(tkn.expecting("solid") && tkn.get()) {
      string stlName = tkn; // second token should be the solid name
      wrl.setName(stlName);
      // TODO ...

      // create the scene graph structure :
      // 1) the SceneGraph should have a single Shape node a child
      // 2) the Shape node should have an Appearance node in its appearance field
      // 3) the Appearance node should have a Material node in its material field
      // 4) the Shape node should have an IndexedFaceSet node in its geometry node

      // from the IndexedFaceSet
      // 5) get references to the coordIndex, coord, and normal arrays
      // 6) set the normalPerVertex variable to false (i.e., normals per face)  

      // the file should contain a list of triangles in the following format

      // facet normal ni nj nk
      //   outer loop
      //     vertex v1x v1y v1z
      //     vertex v2x v2y v2z
      //     vertex v3x v3y v3z
      //   endloop
      // endfacet

      // - run an infinite loop to parse all the faces
      // - write a private method to parse each face within the loop
      // - the method should return true if successful, and false if not
      // - if your method returns tru
      //     update the normal, coord, and coordIndex variables
      // - if your method returns false
      //     throw an StrException explaining why the method failed

      // **************** implemented from here *****************
      cout << "create Shape" << endl;
      // add shape
      Shape* shape = new Shape();
      shape->setName(stlName);
      wrl.addChild(shape);
          // add appearance
      Appearance* appearance = new Appearance();
      Material* material = new Material();
      // set for appearance first
      appearance->setMaterial((Node*)material);
      shape->setAppearance((Node*)appearance);
              // add material

          // add geomotry
      IndexedFaceSet* indexedFaceSet = new IndexedFaceSet();

      // get references

      // vector<float>& coord = indexedFaceSet->getCoord();
      // vector<int>& coordIndex = indexedFaceSet->getCoordIndex();
      // vector<float>& normal = indexedFaceSet->getNormal();
      // vector<int>& normalIndex = indexedFaceSet->getNormalIndex();

      indexedFaceSet->setNormalPerVertex(false);
      // start indexedFaceSet
      cout << "start indexedFaceSet" << endl;
      int indexCount = 0;
      int normalCount = 0;
      // while(true) {
      //   loadIndexedFaceSet(tkn, *indexedFaceSet, indexCount, normalCount);
      //   // end of stl file
      //   if(tkn.equals("endsolid")) {
      //     success = true;
      //     break;
      //   }
      // }
      tkn.get();
      while(!tkn.equals("endsolid") ) {
        if(!loadIndexedFaceSet(tkn, *indexedFaceSet, indexCount, normalCount)) {
          cout << "loadIndexedFaceSet false" << endl;
        }
      }

      shape->setGeometry((Node*)indexedFaceSet);
      wrl.addChild((pNode)shape);
      // ******************* implemented end here **********************
    }

    // close the file (this statement may not be reached)
    fclose(fp);
    success = true;
    
  } catch(StrException* e) { 
    
    if(fp!=(FILE*)0) fclose(fp);
    fprintf(stderr,"ERROR | %s\n",e->what());
    delete e;

  }
  cout << "load success" << endl;
  return success;
}

// ****************** implemented private method *******************
// to parse one face
bool LoaderStl::loadIndexedFaceSet(Tokenizer& tkn, IndexedFaceSet& ifs, int& indexCount, int& normalCount ) {
  // bool success = false;
  // std::cout << "in loadIndexedFaceSet" << std::endl;
  // while(success == false) {
  try {
    if(!tkn.equals("facet")) {
      // cout << "facet" << endl;
      throw new StrException("No facet");
    }

    if(!tkn.expecting("normal")) {
      // cout << "normal" << endl;
      throw new StrException("No normal");
    }

    // get normal
    // int count = 0;
    // while(tkn.get() && count < 3) {
    //   cout << "tkn is " << tkn << endl;
    //   float ds = atof(tkn.c_str());
    //   ifs.getNormal().push_back(ds);
    //   count++;
    // }

    // ************ Vec3f ***************
    Vec3f normal;
    tkn.getVec3f(normal);
    // for(int i = 0; i < 3; i++) {

    ifs.getNormal().push_back(normal.x);    
    ifs.getNormal().push_back(normal.y);    
    ifs.getNormal().push_back(normal.z);    
    // ************ Vec3f ***************
   
    // tkn.get();
    // ifs.getNormal().push_back(tkn);
    // tkn.get();
    // ifs.getNormal().push_back(tkn);
    // tkn.get();
    // ifs.getNormal().push_back(tkn);    
    // }
    // cout << "tkn is " << normal.x << endl;
    // cout << "tkn is " << normal.y << endl;
    // cout << "tkn is " << normal.z << endl;
    ifs.getNormalIndex().push_back(normalCount++);
    
    if(!tkn.expecting("outer")) {
      // cout << "outer" << endl;
      throw new StrException("No outer");
    }
    if(!tkn.expecting("loop")) {
      // cout << "loop" << endl;
      throw new StrException("No loop");
    }
    // get vertex

    for(int i = 0; i < 3; i++) {
      if(!tkn.expecting("vertex")) throw new StrException("No vertex");
      // int count = 0;
      // while(tkn.get() && count < 3) {
      //   float ds = atof(tkn.c_str());
      //   ifs.getCoord().push_back(ds);
      //   count++;
      // }
      // ************ Vec3f ***************
      Vec3f vertex;
      tkn.getVec3f(vertex);
      ifs.getCoord().push_back(vertex.x);
      ifs.getCoord().push_back(vertex.y);
      ifs.getCoord().push_back(vertex.z);
      // ************ Vec3f ***************
      // tkn.get();
      // ifs.getNormal().push_back(tkn);
      // tkn.get();
      // ifs.getNormal().push_back(tkn);
      // tkn.get();
      // ifs.getNormal().push_back(tkn);   

      ifs.getCoordIndex().push_back(indexCount++);
    }
    ifs.getCoordIndex().push_back(-1);

    if(!tkn.expecting("endloop")) throw new StrException("No endloop");
    if(!tkn.expecting("endfacet")) throw new StrException("No endfacet");
    //   // tkn.expecting("endfacet");
    tkn.get();
  } catch(StrException* e) {     
      fprintf(stderr,"ERROR | %s\n",e->what());
      delete e;
      return false;
  }

  //   success = true;
  //   // cout << "face success " << success << endl; 
  // // }

  // if(success == false) {
  //   throw new StrException("fail to load this face");
  //   // cout << "fail to load this face" << endl;
  // }
  return true;

}
