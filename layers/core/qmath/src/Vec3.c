#include "AVIDLib_QMath/Vec3.h"
#include "AVIDLib_QMath/Math.h"
#include "AVIDLib_Plat/Ptr.h"
#include "AVIDLib_Plat/Check.h"
#include "AVIDLib_Plat/Util.h"

const ALQM_Vec3 ALQM_Vec3_Origin = {{ 0, 0, 0 }};

float* ALQM_Vec3_Data(ALQM_Vec3* v)
{
	return ALP_TSANITY_VALID(v, &v->v[0], ALP_NULL);
}

const float* ALQM_Vec3_CData(const ALQM_Vec3* v)
{
	return ALP_TSANITY_VALID(v, &v->v[0], ALP_NULL);
}

ALQM_Vec3* ALQM_Vec3_Zero(ALQM_Vec3* vOut)
{
	if ( ALP_SANITY_VALID(vOut) )
	{
		vOut->v[ALQM_VECX] = 0;
		vOut->v[ALQM_VECY] = 0;
		vOut->v[ALQM_VECZ] = 0;
	}

	return vOut;
}

ALQM_Vec3* ALQM_Vec3_Copy(const ALQM_Vec3* vIn, ALQM_Vec3* vOut)
{
	if ( ALP_SANITY_VALID(vIn && vOut) && vIn != vOut )
	{
		vOut->v[ALQM_VECX] = vIn->v[ALQM_VECX];
		vOut->v[ALQM_VECY] = vIn->v[ALQM_VECY];
		vOut->v[ALQM_VECZ] = vIn->v[ALQM_VECZ];
	}

	return vOut;
}

ALQM_Vec3* ALQM_Vec3_Set(const float* values, ALP_Size count, ALQM_Vec3* vOut)
{
	if ( ALP_SANITY_VALID(values && count >= 3 && vOut) )
	{
		vOut->v[ALQM_VECX] = values[0];
		vOut->v[ALQM_VECY] = values[1];
		vOut->v[ALQM_VECZ] = values[2];
	}

	return vOut;
}

ALQM_Vec3* ALQM_Vec3_Add(const ALQM_Vec3* vLHS, const ALQM_Vec3* vRHS, ALQM_Vec3* vOut)
{
	if ( ALP_SANITY_VALID(vLHS && vRHS && vOut) )
	{
		vOut->v[ALQM_VECX] = vLHS->v[ALQM_VECX] + vRHS->v[ALQM_VECX];
		vOut->v[ALQM_VECY] = vLHS->v[ALQM_VECY] + vRHS->v[ALQM_VECY];
		vOut->v[ALQM_VECZ] = vLHS->v[ALQM_VECZ] + vRHS->v[ALQM_VECZ];
	}

	return vOut;
}

ALQM_Vec3* ALQM_Vec3_Subtract(const ALQM_Vec3* vLHS, const ALQM_Vec3* vRHS, ALQM_Vec3* vOut)
{
	if ( ALP_SANITY_VALID(vLHS && vRHS && vOut) )
	{
		vOut->v[ALQM_VECX] = vLHS->v[ALQM_VECX] - vRHS->v[ALQM_VECX];
		vOut->v[ALQM_VECY] = vLHS->v[ALQM_VECY] - vRHS->v[ALQM_VECY];
		vOut->v[ALQM_VECZ] = vLHS->v[ALQM_VECZ] - vRHS->v[ALQM_VECZ];
	}

	return vOut;
}

ALQM_Vec3* ALQM_Vec3_CrossProduct(const ALQM_Vec3* vLHS, const ALQM_Vec3* vRHS, ALQM_Vec3* vOut)
{
	if ( ALP_SANITY_VALID(vLHS && vRHS && vOut) )
	{
		vOut->v[ALQM_VECX] = (vLHS->v[ALQM_VECY] * vRHS->v[ALQM_VECZ]) - (vLHS->v[ALQM_VECZ] * vRHS->v[ALQM_VECY]);
		vOut->v[ALQM_VECY] = (vLHS->v[ALQM_VECZ] * vRHS->v[ALQM_VECX]) - (vLHS->v[ALQM_VECX] * vRHS->v[ALQM_VECZ]);
		vOut->v[ALQM_VECZ] = (vLHS->v[ALQM_VECX] * vRHS->v[ALQM_VECY]) - (vLHS->v[ALQM_VECY] * vRHS->v[ALQM_VECX]);
	}

	return vOut;
}

ALQM_Vec3* ALQM_Vec3_MultiplyAdd(const ALQM_Vec3* vIn, ALQM_Scalar scale, const ALQM_Vec3* vScaledAdd, ALQM_Vec3* vOut)
{
	if ( ALP_SANITY_VALID(vIn && vScaledAdd && vOut) )
	{
		vOut->v[ALQM_VECX] = vIn->v[ALQM_VECX] + (scale * vScaledAdd->v[ALQM_VECX]);
		vOut->v[ALQM_VECY] = vIn->v[ALQM_VECY] + (scale * vScaledAdd->v[ALQM_VECY]);
		vOut->v[ALQM_VECZ] = vIn->v[ALQM_VECZ] + (scale * vScaledAdd->v[ALQM_VECZ]);
	}

	return vOut;
}

ALQM_Vec3* ALQM_Vec3_Normalise(const ALQM_Vec3* vIn, ALQM_Vec3* vOut)
{
	if ( ALP_SANITY_VALID(vIn && vOut) )
	{
		ALQM_Vec3_NormaliseAndGetLength(vIn, vOut);
	}

	return vOut;
}

ALQM_Vec3* ALQM_Vec3_Negate(const ALQM_Vec3* vIn, ALQM_Vec3* vOut)
{
	if ( ALP_SANITY_VALID(vIn && vOut) )
	{
		ALQM_Vec3_Scale(vIn, -1, vOut);
	}

	return vOut;
}

ALQM_Vec3* ALQM_Vec3_Scale(const ALQM_Vec3* vIn, ALQM_Scalar scale, ALQM_Vec3* vOut)
{
	if ( ALP_SANITY_VALID(vIn && vOut) )
	{
		vOut->v[ALQM_VECX] = vIn->v[ALQM_VECX] * scale;
		vOut->v[ALQM_VECY] = vIn->v[ALQM_VECY] * scale;
		vOut->v[ALQM_VECZ] = vIn->v[ALQM_VECZ] * scale;
	}

	return vOut;
}

ALQM_Scalar ALQM_Vec3_DotProduct(const ALQM_Vec3* v0, const ALQM_Vec3* v1)
{
	return ALP_TSANITY_VALID(v0 && v1,
							 (v0->v[ALQM_VECX] * v1->v[ALQM_VECX]) + (v0->v[ALQM_VECY] * v1->v[ALQM_VECY]) + (v0->v[ALQM_VECZ] * v1->v[ALQM_VECZ]),
							 0);
}

ALP_Bool ALQM_Vec3_ExactlyEqual(const ALQM_Vec3* vLHS, const ALQM_Vec3* vRHS)
{
	return ALP_TSANITY_VALID(vLHS && vRHS,
							 ALQM_ScalarsExactlyEqual(vLHS->v[ALQM_VECX], vRHS->v[ALQM_VECX]) &&
							 ALQM_ScalarsExactlyEqual(vLHS->v[ALQM_VECY], vRHS->v[ALQM_VECY]) &&
							 ALQM_ScalarsExactlyEqual(vLHS->v[ALQM_VECZ], vRHS->v[ALQM_VECZ]),
							 ALP_FALSE);
}

ALP_Bool ALQM_Vec3_ApproximatelyEqual(const ALQM_Vec3* vLHS, const ALQM_Vec3* vRHS)
{
	return ALP_TSANITY_VALID(vLHS && vRHS,
							 ALQM_ScalarsApproximatelyEqual(vLHS->v[ALQM_VECX], vRHS->v[ALQM_VECX]) &&
							 ALQM_ScalarsApproximatelyEqual(vLHS->v[ALQM_VECY], vRHS->v[ALQM_VECY]) &&
							 ALQM_ScalarsApproximatelyEqual(vLHS->v[ALQM_VECZ], vRHS->v[ALQM_VECZ]),
							 ALP_FALSE);
}

ALP_Bool ALQM_Vec3_ExactlyZero(const ALQM_Vec3* v)
{
	return ALP_TSANITY_VALID(v,
							 ALQM_Vec3_ExactlyEqual(v, &ALQM_Vec3_Origin),
							 ALP_FALSE);
}

ALP_Bool ALQM_Vec3_ApproximatelyZero(const ALQM_Vec3* v)
{
	return ALP_TSANITY_VALID(v,
							 ALQM_Vec3_ApproximatelyEqual(v, &ALQM_Vec3_Origin),
							 ALP_FALSE);
}

ALQM_Scalar ALQM_Vec3_Length(const ALQM_Vec3* v)
{
	return ALP_TSANITY_VALID(v,
							 ALQM_Sqrt(ALQM_Vec3_DotProduct(v, v)),
							 0.0f);
}

ALQM_Scalar ALQM_Vec3_NormaliseAndGetLength(const ALQM_Vec3* vIn, ALQM_Vec3* vOut)
{
	ALQM_Scalar length = 0.0f;

	if ( ALP_SANITY_VALID(vIn && vOut) )
	{
		length = ALQM_Vec3_Length(vIn);

		if ( !ALQM_ScalarApproximatelyZero(length) )
		{
			const ALQM_Scalar invLength = 1.0f / length;

			vOut->v[ALQM_VECX] = vIn->v[ALQM_VECX] * invLength;
			vOut->v[ALQM_VECY] = vIn->v[ALQM_VECY] * invLength;
			vOut->v[ALQM_VECZ] = vIn->v[ALQM_VECZ] * invLength;
		}
	}

	return length;
}
