///
/// RenderUtils.h
/// Seed of Andromeda
///
/// Created by Benjamin Arnold on 3 Dec 2014
/// Copyright 2014 Regrowth Studios
/// All Rights Reserved
///
/// Summary:
/// Some simple utils for rendering
///

#pragma once

#ifndef RenderUtils_h__
#define RenderUtils_h__

#include "stdafx.h"

/// Sets translation for a matrix relative to relativePos. Will overwrite existing translation
inline void setMatrixTranslation(f32m4& matrix, const f64v3 &position, const f64v3& relativePos) {
    matrix[3][0] = (float)(position.x - relativePos.x);
    matrix[3][1] = (float)(position.y - relativePos.y);
    matrix[3][2] = (float)(position.z - relativePos.z);
}

/// Sets translation for a matrix relative to relativePos. Will overwrite existing translation
inline void setMatrixTranslation(f32m4& matrix, const f32v3 &position, const f32v3& relativePos) {
    matrix[3][0] = (position.x - relativePos.x);
    matrix[3][1] = (position.y - relativePos.y);
    matrix[3][2] = (position.z - relativePos.z);
}

/// Sets translation for a matrix relative to relativePos. Will overwrite existing translation
inline void setMatrixTranslation(f32m4& matrix, const f32v3 &position, const f64v3& relativePos) {
    matrix[3][0] = (float)((double)position.x - relativePos.x);
    matrix[3][1] = (float)((double)position.y - relativePos.y);
    matrix[3][2] = (float)((double)position.z - relativePos.z);
}

/// Sets translation for a matrix. Will overwrite existing translation
inline void setMatrixTranslation(f32m4& matrix, const float x, const float y, const float z) {
    matrix[3][0] = x;
    matrix[3][1] = y;
    matrix[3][2] = z;
}

/// Sets translation for a matrix. Will overwrite existing translation
inline void setMatrixTranslation(f32m4& matrix, const double x, const double y, const double z) {
    matrix[3][0] = (float)x;
    matrix[3][1] = (float)y;
    matrix[3][2] = (float)z;
}

/// Sets translation for a matrix. Will overwrite existing translation
inline void setMatrixTranslation(f32m4& matrix, const f64v3& trans) {
    matrix[3][0] = (float)trans.x;
    matrix[3][1] = (float)trans.y;
    matrix[3][2] = (float)trans.z;
}

/// Sets scale for a matrix. Will overwrite existing scale
inline void setMatrixScale(f32m4& matrix, const f32v3 &scale) {
    matrix[0][0] = scale.x;
    matrix[1][1] = scale.y;
    matrix[2][2] = scale.z;
}

/// Sets scale for a matrix. Will overwrite existing scale
inline void setMatrixScale(f32m4& matrix, const float scaleX, const float scaleY, const float scaleZ) {
    matrix[0][0] = scaleX;
    matrix[1][1] = scaleY;
    matrix[2][2] = scaleZ;
}

/// Gets the closest point on the AABB to the position
/// @param pos: Position to query nearest point in relation to
/// @param aabbPos: Position of the -x,-y,-z corner of the aabb
/// @param aabbDims: Dimensions of the aabb
inline void getClosestPointOnAABB(const f32v3& pos, const f32v3& aabbPos,
                                  const f32v3& aabbDims, OUT f32v3& point) {
    point.x = (pos.x <= aabbPos.x) ? aabbPos.x : ((pos.x > aabbPos.x + aabbDims.x) ?
                                                  (aabbPos.x + aabbDims.x) : pos.x);
    point.y = (pos.y <= aabbPos.y) ? aabbPos.y : ((pos.y > aabbPos.y + aabbDims.y) ?
                                                  (aabbPos.y + aabbDims.y) : pos.y);
    point.z = (pos.z <= aabbPos.z) ? aabbPos.z : ((pos.z > aabbPos.z + aabbDims.z) ?
                                                  (aabbPos.z + aabbDims.z) : pos.z);
}
inline void getClosestPointOnAABB(const f64v3& pos, const f64v3& aabbPos,
                                  const f64v3& aabbDims, OUT f64v3& point) {
    point.x = (pos.x <= aabbPos.x) ? aabbPos.x : ((pos.x > aabbPos.x + aabbDims.x) ?
                                                  (aabbPos.x + aabbDims.x) : pos.x);
    point.y = (pos.y <= aabbPos.y) ? aabbPos.y : ((pos.y > aabbPos.y + aabbDims.y) ?
                                                  (aabbPos.y + aabbDims.y) : pos.y);
    point.z = (pos.z <= aabbPos.z) ? aabbPos.z : ((pos.z > aabbPos.z + aabbDims.z) ?
                                                  (aabbPos.z + aabbDims.z) : pos.z);
}

#endif // RenderUtils_h__