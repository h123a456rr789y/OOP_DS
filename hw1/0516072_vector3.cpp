#include "0516072_vector3.h"
#include<iostream>
#include<cmath>

using namespace std;

vector3::vector3(float inX,float inY, float inZ){
    set(inX, inY, inZ);
}

vector3::vector3(const vector3 &v){
    x=v.x;
    y=v.y;
    z=v.z;
}

float        &vector3::operator [] (unsigned int index){

    switch(index){
        case 0:return this->x;break;
        case 1:return this->y;break;
        case 2:return this->z;break;
        default:break;
    }
}

const float      &vector3::operator [] (unsigned int index) const{
    switch(index){
        case 0:return this->x;break;
        case 1:return this->y;break;
        case 2:return this->z;break;
        default:break;
    }
}

vector3              &vector3::operator =  (const vector3 &v){
    this->x=v.x;
    this->y=v.y;
    this->z=v.z;
    return *this;
}

vector3             &vector3::operator += (const vector3 &v){
    this->x+=v.x;
    this->y+=v.y;
    this->z+=v.z;
    return *this;
}

vector3              &vector3::operator -= (const vector3 &v){
    this->x-=v.x;
    this->y-=v.y;
    this->z-=v.z;
    return *this;
}

vector3          &vector3::operator *= (float f){
    this->x*=f;
    this->y*=f;
    this->z*=f;
    return *this;
}

vector3           &vector3::operator /= (float f){
    this->x/=f;
    this->y/=f;
    this->z/=f;
    return *this;
}

bool           operator == (const vector3 &a, const vector3 &b){
    if(a.x==b.x && a.y==b.y && a.z == b.z)
        return 1;
    else
        return 0;
}

bool           operator != (const vector3 &a, const vector3 &b){
    if(a.x==b.x && a.y==b.y && a.z == b.z)
        return 0;
    else
        return 1;
}

vector3        operator - (const vector3 &a){
    vector3 tmp;
    tmp.x=a.x*(-1);
    tmp.y=a.y*(-1);
    tmp.z=a.z*(-1);
    return tmp;
}

vector3        operator + (const vector3 &a, const vector3 &b){
    vector3 tmp;
    tmp.x=a.x+b.x;
    tmp.y=a.y+b.y;
    tmp.z=a.z+b.z;
    return tmp;
}

vector3        operator - (const vector3 &a, const vector3 &b){
    vector3 tmp;
    tmp.x=a.x-b.x;
    tmp.y=a.y-b.y;
    tmp.z=a.z-b.z;
    return tmp;
}

vector3        operator * (const vector3 &v, float f ){
    vector3 tmp;
    tmp.x=v.x*f;
    tmp.y=v.y*f;
    tmp.z=v.z*f;
    return tmp;
}

vector3        operator * (float f, const vector3 &v){
    vector3 tmp;
    tmp.x=f*v.x;
    tmp.y=f*v.y;
    tmp.z=f*v.z;
    return tmp;
}

vector3        operator / (const vector3 &v, float f){
    vector3 tmp;
    tmp.x=v.x/f;
    tmp.y=v.y/f;
    tmp.z=v.z/f;
    return tmp;
}


void vector3::set(float xIn, float yIn, float zIn){
    x=xIn;
    y=yIn;
    z=zIn;
}

float vector3::length() const{

   return sqrt(x*x+y*y+z*z);
}

void vector3::printVector3() const{
    cout << "(" << x << ", " << y << ", " << z << ")" <<endl;
}
