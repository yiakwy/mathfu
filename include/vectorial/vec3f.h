#ifndef VECTORIAL_VEC3F_H

#ifndef VECTORIAL_SIMD4F_H
  #include "vectorial/simd4f.h"
#endif



namespace vectorial {
    

    class vec3f {
    public:

        simd4f value;
    
        inline vec3f() {}
        inline vec3f(const simd4f& v) : value(v) {}
        inline vec3f(float x, float y, float z) : value( simd4f_create(x,y,z,0) ) {}
        inline vec3f(const float *ary) : value( simd4f_uload3(ary) ) { }
            
        inline float x() const { return simd4f_get_x(value); }
        inline float y() const { return simd4f_get_y(value); }
        inline float z() const { return simd4f_get_z(value); }

        inline void load(const float *ary) { value = simd4f_uload3(ary); }
        inline void store(float *ary) const { simd4f_ustore3(value, ary); }
    
        enum { elements = 3 };

        static vec3f zero() { return vec3f(simd4f_zero()); }
        static vec3f one() { return vec3f(1.0f, 1.0f, 1.0f); }
        static vec3f xaxis() { return vec3f(1.0f, 0.0f, 0.0f); }
        static vec3f yaxis() { return vec3f(0.0f, 1.0f, 0.0f); }
        static vec3f zaxis() { return vec3f(0.0f, 0.0f, 1.0f); }

    };


    vectorial_inline vec3f operator+(const vec3f& lhs, const vec3f& rhs) {
        return vec3f( simd4f_add(lhs.value, rhs.value) );
    }

    vectorial_inline vec3f operator-(const vec3f& lhs, const vec3f& rhs) {
        return vec3f( simd4f_sub(lhs.value, rhs.value) );
    }

    vectorial_inline vec3f operator*(const vec3f& lhs, const vec3f& rhs) {
        return vec3f( simd4f_mul(lhs.value, rhs.value) );
    }

    vectorial_inline vec3f operator/(const vec3f& lhs, const vec3f& rhs) {
        return vec3f( simd4f_div(lhs.value, rhs.value) );
    }



    vectorial_inline vec3f operator+(const vec3f& lhs, float rhs) {
        return vec3f( simd4f_add(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec3f operator-(const vec3f& lhs, float rhs) {
        return vec3f( simd4f_sub(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec3f operator*(const vec3f& lhs, float rhs) {
        return vec3f( simd4f_mul(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec3f operator/(const vec3f& lhs, float rhs) {
        return vec3f( simd4f_div(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec3f operator+(float lhs, const vec3f& rhs) {
        return vec3f( simd4f_add(simd4f_splat(lhs), rhs.value) );
    }

    vectorial_inline vec3f operator-(float lhs, const vec3f& rhs) {
        return vec3f( simd4f_sub(simd4f_splat(lhs), rhs.value) );
    }

    vectorial_inline vec3f operator*(float lhs, const vec3f& rhs) {
        return vec3f( simd4f_mul(simd4f_splat(lhs), rhs.value) );
    }

    vectorial_inline vec3f operator/(float lhs, const vec3f& rhs) {
        return vec3f( simd4f_div(simd4f_splat(lhs), rhs.value) );
    }



    vectorial_inline float dot(const vec3f& lhs, const vec3f& rhs) {
        return simd4f_get_x( simd4f_dot3(lhs.value, rhs.value) );
    }

    vectorial_inline vec3f cross(const vec3f& lhs, const vec3f& rhs) {
        return simd4f_cross3(lhs.value, rhs.value);
    }
    
    
    vectorial_inline float length(const vec3f& v) {
        return simd4f_get_x( simd4f_length3(v.value) );
    }

    vectorial_inline float length_squared(const vec3f& v) {
        return simd4f_get_x( simd4f_length3_squared(v.value) );
    }

    vectorial_inline vec3f normalize(const vec3f& v) {
        return vec3f( simd4f_normalize3(v.value) );
    }


}



#ifdef VECTORIAL_OSTREAM
#include <ostream>

static std::ostream& operator<<(std::ostream& os, const vectorial::vec3f& v) {
    os << "[ " << v.x() << ", "
               << v.y() << ", "
               << v.z() << " ]";
    return os;
}
#endif




#endif
