//
//  LineGridModel.cpp
//  ogl4
//
//  Created by Philipp Lensing on 19.09.16.
//  Copyright © 2016 Philipp Lensing. All rights reserved.
//

#include "LinePlaneModel.h"

LinePlaneModel::LinePlaneModel( float DimX, float DimZ, int NumSegX, int NumSegZ )
{
    VB.begin();
    
    float StepX = DimX / (float)NumSegX;
    float StepZ = DimZ / (float)NumSegZ;
    
    float BeginX = -DimZ/2.0f;
    float BeginZ = -DimX/2.0f;
    
    for( int i=0; i<=NumSegX; ++i )
    {
        VB.addVertex( BeginZ + i*StepX, 0, BeginX );
        VB.addVertex( BeginZ + i*StepX, 0, -BeginX );
    }
    for( int i=0; i<=NumSegZ; ++i )
    {
        VB.addVertex( BeginZ, 0, BeginX + i*StepZ );
        VB.addVertex( -BeginZ, 0, BeginX + i*StepZ );
    }
    
    VB.end();
    
}

void LinePlaneModel::draw(const BaseCamera& Cam)
{
    BaseModel::draw(Cam);

    VB.activate();
    
    glDrawArrays(GL_LINES, 0, VB.vertexCount());
    
    VB.deactivate();
}

void LinePlaneModel::calculateBoundingBox() 
{
 
}

AABB& LinePlaneModel::getBoundingBox()
{
    return BoundingBox;
}
