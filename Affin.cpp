#include "Affin.h"
#include"input/input.h"
#include"cmath"



Affin::Affin()
{
	matScale = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};


	matTrans = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};

	matRotateZ = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};
}

void Affin::init()
{

}



void Affin::UpdateTrans(WorldTransform &worldTransform_)
{
	matTrans = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		worldTransform_.translation_.x,worldTransform_.translation_.y,worldTransform_.translation_.z,1.0f
	};

	worldTransform_.matWorld_ *= matTrans;



}

void Affin::UpdateScale(WorldTransform& worldTransform_)
{
	matScale = {
			worldTransform_.scale_.x,0.0f,0.0f,0.0f,
			0.0f,worldTransform_.scale_.y,0.0f,0.0f,
			0.0f,0.0f,worldTransform_.scale_.z,0.0f,
			0.0f,0.0f,0.0f,1.0f
	};

	worldTransform_.matWorld_ *= matScale;



}

void Affin::UpdateRotate(WorldTransform& worldTransform_)
{
	matRotateZ = {
		cos(worldTransform_.rotation_.z),sin(worldTransform_.rotation_.z),0.0f,0.0f,
		-sin(worldTransform_.rotation_.z),cos(worldTransform_.rotation_.z),0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};

	worldTransform_.matWorld_ *= matRotateZ;



}
