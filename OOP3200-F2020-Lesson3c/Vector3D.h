#pragma once
#ifndef __VECTOR3D__
#define __VECTOR3D__
#include <string>
#include <iostream>
#include "Vector2D.h"
#include "assert.h"

template <class T>
class Vector3D
{
public:

	Vector3D(T x = static_cast<T>(0.0), T y = static_cast<T>(0.0), T z = static_cast<T>(0.0));
	Vector3D(std::string x, std::string y, std::string z);
	Vector3D(Vector2D& vector_2d);
	~Vector3D();

	//mutators

	void SetX(const T x);
	void SetY(const T y);
	void SetZ(const T z);
	void Set(const T x, const T y, const T z);
	
	//accessors
	T GetX() const;
	T GetY() const;
	T GetZ() const;
	friend std::ostream& operator<<(std::ostream& out, const Vector3D& rhs)
	{
		out << rhs.ToString();
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Vector3D& rhs)
	{
		in >> rhs.m_x;
		in.ignore();
		in >> rhs.m_y;
		in.ignore();
		in >> rhs.m_z;
		
		return in;
	}
	std::string ToString() const;
	

private:
	
	T m_x;
	T m_y;
	T m_z;
};

#endif /* defined (__VECTOR3D__) */
//Implementation
template <class T>
Vector3D<T>::Vector3D(const T x, const T y, const T z) : m_x(x), m_y(y), m_z(z)
{
}

template<class T>
inline Vector3D<T>::Vector3D(std::string x, std::string y, std::string z)
{
	if (typeid(T) == typeid(int))
	{
		m_x = std::stoi(x);
		m_y = std::stoi(y);
		m_z = std::stoi(z);
	}
	if (typeid(T) == typeid(float))
	{
		m_x = std::stoi(x);
		m_y = std::stoi(y);
		m_z = std::stoi(z);
	}
	if (typeid(T) == typeid(double))
	{
		m_x = std::stoi(x);
		m_y = std::stoi(y);
		m_z = std::stoi(z);
	}

	//if type is not one of these types, conversion not possible
	assert((typeid(T) != typeid(int) || typeid(T) != typeid(float) || typeid(T) != typeid(double)),
		"error no conversion possible");
}

template <class T>
Vector3D<T>::Vector3D(Vector2D& vector_2d)
{
	m_x = static_cast<T>(vector_2d.GetX());
	m_y = static_cast<T>(vector_2d.GetY());
	m_z = static_cast<T>(0.0);
}

template <class T>
Vector3D<T>::~Vector3D() {};

template <class T>
void Vector3D<T>::SetX(const T x)
{
	m_x = x;
}

template <class T>
void Vector3D<T>::SetY(const T y)
{
	m_y = y;
}

template <class T>
void Vector3D<T>::SetZ(const T z)
{
	m_z = z;
}

template <class T>
void Vector3D<T>::Set(const T x, const T y, const T z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

template <class T>
T Vector3D<T>::GetX() const
{
	return  m_x;
}

template <class T>
T Vector3D<T>::GetY() const
{
	return  m_y;
}

template <class T>
T Vector3D<T>::GetZ() const
{
	return  m_z;
}

template <class T>
std::string Vector3D<T>::ToString() const
{
	return "(" + std::to_string(m_x) + ", " + std::to_string(m_y) + ", " + std::to_string(m_z) + ")";
}
