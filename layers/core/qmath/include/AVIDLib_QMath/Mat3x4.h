#ifndef AVIDLIB_QMATH_MAT3X4_H
#define AVIDLIB_QMATH_MAT3X4_H

#include "AVIDLib_QMath/LibExport.h"
#include "AVIDLib_QMath/Types.h"
#include "AVIDLib_Core/Int.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ALQM_MAT3X4_ROWS 4
#define ALQM_MAT3X4_COLS 3
#define ALQM_MAT3X4_CELLS (ALQM_MAT3X4_ROWS * ALQM_MAT3X4_COLS)

// In Quake, matrices are specified like this.
// The data layout in memory means that when you iterate
// sequentially over an [A][B] array, B varies first, then
// A. This means that the data layout is "A-major" (each
// A entry contains a whole B entry).
// If we treat a Vec3 as being a column, where is it
// transformed by pre-multiplication by a matrix, then
// matrices are 4 rows by 3 columns, in column-major order.
typedef struct _ALQM_Mat3x4
{
	ALQM_Scalar v[ALQM_MAT3X4_COLS][ALQM_MAT3X4_ROWS];
} ALQM_Mat3x4;

// Constants:
API_AVIDLIB_QMATH extern const ALQM_Mat3x4 ALQM_Mat3x4_Identity;

// All functions below assume that their inputs are valid vectors.
// If this is not the case, undefined behaviour will result.
// Checking can be turned on using AVIDLIB_VALIDITY_CHECKS.

// Returns the raw float values of the matrix.
// There are ALQM_MAT3X4_CELLS values, in column-major order.
API_AVIDLIB_QMATH float* ALQM_Mat3x4_Data(ALQM_Mat3x4* m);
API_AVIDLIB_QMATH const float* ALQM_Mat3x4_CData(const ALQM_Mat3x4* m);

// Returns data for the given column. There are ALQM_MAT3X4_ROWS values.
API_AVIDLIB_QMATH float* ALQM_Mat3x4_Column(ALQM_Mat3x4* m, ALC_Size column);
API_AVIDLIB_QMATH const float* ALQM_Mat3x4_CColumn(const ALQM_Mat3x4* m, ALC_Size column);

// Chainable functions, where vOut is returned:
API_AVIDLIB_QMATH ALQM_Mat3x4* ALQM_Mat3x4_SetIdentity(ALQM_Mat3x4* mOut);
API_AVIDLIB_QMATH ALQM_Mat3x4* ALQM_Mat3x4_Copy(const ALQM_Mat3x4* mIn, ALQM_Mat3x4* mOut);
API_AVIDLIB_QMATH ALQM_Mat3x4* ALQM_Mat3x4_Set(const float* values, ALC_Size count, ALQM_Mat3x4* mOut);
API_AVIDLIB_QMATH ALQM_Mat3x4* ALQM_Mat3x4_Concat(const ALQM_Mat3x4* m0, const ALQM_Mat3x4* m1, ALQM_Mat3x4* mOut);
API_AVIDLIB_QMATH ALQM_Mat3x4* ALQM_Mat3x4_ConcatRot(const ALQM_Mat3x4* m0, const ALQM_Mat3x4* m1, ALQM_Mat3x4* mOut);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // AVIDLIB_QMATH_MAT3X4_H
