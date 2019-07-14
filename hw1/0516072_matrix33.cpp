#include "0516072_matrix33.h"

#include<iostream>

using namespace std;

matrix33::matrix33(vector3 inV1, vector3 inV2, vector3 inV3){
    set( inV1, inV2, inV3);
}

matrix33::matrix33(const matrix33 &m){
    v1=m.v1;
    v2=m.v2;
    v3=m.v3;
}

 vector3                 &matrix33::operator [] (unsigned int index){
    switch(index){
        case 0: return this->v1;break;
        case 1: return this->v2;break;
        case 2: return this->v3;break;
        default: break;
    }
}
const vector3           &matrix33::operator [] (unsigned int index) const{
    switch(index){
        case 0: return this->v1;break;
        case 1: return this->v2;break;
        case 2: return this->v3;break;
        default: break;
    }
}

matrix33               &matrix33::operator =  (const matrix33 &m){
    this->v1 = m.v1;
    this->v2 = m.v2;
    this->v3 = m.v3;
    return *this;
}
matrix33               &matrix33::operator += (const matrix33 &m){
    this->v1 += m.v1;
    this->v2 += m.v2;
    this->v3 += m.v3;
    return *this;
}
matrix33               &matrix33::operator -= (const matrix33 &m){
    this->v1 -= m.v1;
    this->v2 -= m.v2;
    this->v3 -= m.v3;
    return *this;
}

matrix33               &matrix33::operator *= (float f){
    this->v1 *= f;
    this->v2 *= f;
    this->v3 *= f;
    return *this;
}

matrix33               &matrix33::operator /= (float f){
    this->v1 /= f;
    this->v2 /= f;
    this->v3 /= f;
    return *this;
}

bool           operator == (const matrix33 &a, const matrix33 &b){
    if(a.v1==b.v1 && a.v2==b.v2 && a.v3 == b.v3)
        return 1;
    else
        return 0;
}

bool           operator != (const matrix33 &a, const matrix33 &b){
    if(a.v1==b.v1 && a.v2==b.v2 && a.v3 == b.v3)
        return 0;
    else
        return 1;
}

matrix33        operator - (const matrix33 &a){
    matrix33 tmp;
    tmp.v1=a.v1*(-1);
    tmp.v2=a.v2*(-1);
    tmp.v3=a.v3*(-1);
    return tmp;
}
matrix33        operator + (const matrix33 &a, const matrix33 &b){
    matrix33 tmp;
    tmp.v1=a.v1+b.v1;
    tmp.v2=a.v2+b.v2;
    tmp.v3=a.v3+b.v3;
    return tmp;
}
matrix33        operator - (const matrix33 &a, const matrix33 &b){
    matrix33 tmp;
    tmp.v1=a.v1 - b.v1;
    tmp.v2=a.v2 - b.v2;
    tmp.v3=a.v3 - b.v3;
    return tmp;
}
matrix33        operator * (const matrix33 &v, float f){
    matrix33 tmp;
    tmp.v1=v.v1*f;
    tmp.v2=v.v2*f;
    tmp.v3=v.v3*f;
    return tmp;
}

matrix33        operator * (const matrix33 &a, const matrix33 &b){
    matrix33 tmp;
    int i;
    for(i=0;i<3;i++){
        tmp.v1[i]=a.v1[i]*b.v1[0] + a.v2[i]*b.v1[1] +a.v3[i]*b.v1[2];
        tmp.v2[i]=a.v1[i]*b.v2[0] + a.v2[i]*b.v2[1] +a.v3[i]*b.v2[2];
        tmp.v3[i]=a.v1[i]*b.v3[0] + a.v2[i]*b.v3[1] +a.v3[i]*b.v3[2];
    }
    return tmp;
}
matrix33        operator / (const matrix33 &v, float f){
    matrix33 tmp;
    tmp.v1 = v.v1/f;
    tmp.v2 = v.v2/f;
    tmp.v3 = v.v3/f;
    return tmp;
}

void matrix33::set(vector3 v1In, vector3 v2In, vector3 v3In){
    v1= v1In;
    v2= v2In;
    v3= v3In;
}

matrix33 matrix33::invert(){
    float det=this->determinant();
    matrix33 tmp;
    tmp.v1[0]=v2[1]*v3[2]-v3[1]*v2[2];
    tmp.v2[0]=-(v2[0]*v3[2]-v3[0]*v2[2]);
    tmp.v3[0]=v2[0]*v3[1]-v3[0]*v2[1];
    tmp.v1[1]=-(v1[1]*v3[2]-v3[1]*v1[2]);
    tmp.v2[1]=v1[0]*v3[2]-v3[0]*v1[2];
    tmp.v3[1]=-(v1[0]*v3[1]-v3[0]*v1[1]);
    tmp.v1[2]=v1[1]*v2[2]-v2[1]*v1[2];
    tmp.v2[2]=-(v1[0]*v2[2]-v2[0]*v1[2]);
    tmp.v3[2]=v2[1]*v1[0]-v1[1]*v2[0];

    return tmp/det;
}

matrix33 matrix33::identity(){
    v1=vector3(1,0,0);
    v2=vector3(0,1,0);
    v3=vector3(0,0,1);
}
float  matrix33::determinant() const{
    return (v1[0]*(v2[1]*v3[2]-v3[1]*v2[2])-v2[0]*(v1[1]*v3[2]-v3[1]*v1[2])+v3[0]*(v1[1]*v2[2]-v2[1]*v1[2]));
}

void matrix33::printMatrix() const{
    int i;
    for(i=0;i<3;i++){
        cout << v1[i] << " " ;
        cout << v2[i] << " " ;
        cout << v3[i] << endl;
    }
}
