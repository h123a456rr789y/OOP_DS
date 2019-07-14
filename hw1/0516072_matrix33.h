#ifndef _MATRIX33_H_
#define _MATRIX33_H_

#include "0516072_vector3.h"


class matrix33
{
public:
    //3 vectors
    vector3 v1,v2,v3;
public:
    // constructors
    matrix33() {};

    matrix33(vector3 inV1,vector3 inV2,vector3 inV3);

    matrix33(const matrix33 &m);

public:
    //operators
    vector3                 &operator [] (unsigned int index);
	const vector3           &operator [] (unsigned int index) const;

	matrix33               &operator =  (const matrix33 &m);
	matrix33               &operator += (const matrix33 &m);
	matrix33               &operator -= (const matrix33 &m);
	matrix33               &operator *= (float f);
	matrix33               &operator /= (float f);
	friend bool            operator == (const matrix33 &a, const matrix33 &b);
	friend bool            operator != (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator - (const matrix33 &a);
	friend matrix33        operator + (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator - (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator * (const matrix33 &v, float f);
	friend matrix33        operator * (float f, const matrix33 &v);
	friend matrix33        operator / (const matrix33 &v, float f);
	friend matrix33        operator * (const matrix33 &a, const matrix33 &b);

public:
    //mathods
	void set(vector3 v1In, vector3 v2In, vector3 v3In);

	matrix33 invert();
	matrix33 identity();

    float determinant() const ;
	void printMatrix() const;
};

#endif
