#if defined _inc_maths_
	#endinput
#endif 
#define _inc_maths_


//
//	DEFINES
//


#if !defined FLOAT_EPSILON
	#define FLOAT_EPSILON 							0.00001
#endif


#define DotProductAsNormal(%0,%1,%2,%3,%4,%5) 		((%0*%3) + (%1*%4) + (%2*%5))
#define FloatLength(%0,%1,%2)						floatsqroot((%0*%0) + (%1*%1) + (%2*%2)	



//
//	FORWARDS
//


forward CrossProductAsArray(Float:a[3], Float:b[3], Float:result[3]);
forward CrossProductAsNormal(Float:a1, Float:a2, Float:a3, Float:b1, Float:b2, Float:b3, &Float:r1, &Float:r2, &Float:r3);
forward Float:DotProductAsArray(Float:a[3], Float:b[3]);
forward NormalizeAsArray(Float:value[3], Float:result[3]);


//
//	FUNCTIONS
//


stock CrossProductAsArray(Float:a[3], Float:b[3], Float:result[3])
{
	result[0] = a[1] * b[2] - a[2] * b[1]; 
	result[1] = a[0] * b[2] - a[2] * b[0];
	result[2] = a[0] * b[1] - a[1] * b[0];	
}


stock CrossProductAsNormal(Float:a1, Float:a2, Float:a3, Float:b1, Float:b2, Float:b3, &Float:r1, &Float:r2, &Float:r3)
{
	r1 = a2 * b3 - a3 * b2;
	r2 = a1 * b3 - a3 * b1;	
	r3 = a1 * b2 - a2 * b1;
}


stock Float:DotProductAsArray(Float:a[3], Float:b[3])
{
	return ((a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]));
}


stock NormalizeAsArray(Float:value[3], Float:result[3])
{
	new Float:L = FloatLength(value[0], value[1], value[2]);
	result[0] = value[0] / L;
	result[1] = value[1] / L;
	result[2] = value[2] / L;
}	
