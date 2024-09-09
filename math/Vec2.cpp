#include "Vec2.h"
#include<cmath>  //sprt

Vec2::Vec2() :x(0), y(0)
{
}

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

void Vec2::Init()
{
	x = 0.0f;
	y = 0.0f;
}

void Vec2::Init(float num)
{
	x = num;
	y = num;
}

float Vec2::length()const {
	return std::sqrt(x * x + y * y);
}

Vec2& Vec2::normalize() {
	float len = length();
	if (len != 0) {
		return *this /= len;
	}
	return *this;
}

float Vec2::dot(const Vec2& v) const
{
	return x * v.x + y * v.y;
}

float Vec2::cross(const Vec2& v) const
{
	return x * v.y - y * v.x;
}

Vec2 Vec2::operator+() const
{
	return *this;
}

Vec2 Vec2::operator-() const
{
	return Vec2(-x, -y);
}

Vec2& Vec2::operator+=(const Vec2& v)
{
	this->x += v.x;
	this->y += v.y;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& v)
{
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

Vec2& Vec2::operator*=(float s)
{
	this->x *= s;
	this->y *= s;
	return *this;
}

Vec2& Vec2::operator/=(float s)
{
	x /= s;
	y /= s;
	return *this;
}

const Vec2 operator+(const Vec2& v1, const Vec2& v2)
{
	Vec2 temp(v1);
	temp.x += v2.x;
	temp.y += v2.y;
	return temp;
}

const Vec2 operator-(const Vec2& v1, const Vec2& v2)
{
	Vec2 temp(v1);
	temp.x -= v2.x;
	temp.y -= v2.y;
	return temp;
}

const Vec2 operator*(const Vec2& v, float s)
{
	Vec2 temp(v);
	temp.x *= s;
	temp.y *= s;
	return temp;
}

const Vec2 operator*(float s, const Vec2& v)
{
	Vec2 temp;
	temp.x = s * v.x;
	temp.y = s * v.y;
	return temp;
}

const Vec2 operator/(const Vec2& v, float s)
{
	Vec2 temp(v);
	temp.x /= s;
	temp.y /= s;
	return temp;
}

float lerpFloat(const float start, const float end, const float t) {
	return start * (1.0f - t) + end * t;
}

float  RandomFloat(float offset, float min, float max)
{
	//乱数生成装置(メルセンヌ・ツイスタ)
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());

	//乱数
	std::uniform_real_distribution<float>dist(offset + min, offset + max);
	float result;
	result = dist(engine);

	return result;
}