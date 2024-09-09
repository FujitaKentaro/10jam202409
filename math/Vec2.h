
#pragma once
#include <random>
class Vec2
{
public:
	float x;	//x成分
	float y;	//y成分

public:
	//　コンストラクタ
	Vec2();					//零ベクトルとして生成
	Vec2(float x, float y);		//x成分、ｙ成分を指定しての生成
	void Init();
	void Init(float num);

	//　メンバ関数
	float length() const;				//ノルム（長さ）を求める
	Vec2& normalize();				//正規化する
	float dot(const Vec2& v) const;	//内積を求める
	float cross(const Vec2& v) const;//外積を求める

	//　単項演算子オーバーロード
	Vec2 operator+() const;
	Vec2 operator-() const;

	//　代入演算子オーバーロード
	Vec2& operator+=(const Vec2& v);
	Vec2& operator-=(const Vec2& v);
	Vec2& operator*=(float s);
	Vec2& operator/=(float s);
};

//二項演算子オーバーロード
//※いろんな引数（引数の方と順序）のパターンに対応するため、以下のように準備している
const Vec2 operator+(const Vec2& v1, const Vec2& v2);
const Vec2 operator-(const Vec2& v1, const Vec2& v2);
const Vec2 operator*(const Vec2& v, float s);
const Vec2 operator*(float s, const Vec2& v);
const Vec2 operator/(const Vec2& v, float s);
// 補間
float lerpFloat(const float start, const float end, const float t);
float RandomFloat(float offset = 0, float min = -10, float max = 10);