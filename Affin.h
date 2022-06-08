#pragma once
#include "WorldTransform.h"
#include "Model.h"
#include "DirectXCommon.h"
#include "Math.h"

class Affin
{
public:
	Affin();

	void init();

	void UpdateTrans(WorldTransform &worldTransform_);

	void UpdateScale(WorldTransform& worldTransform_);

	void UpdateRotate(WorldTransform& worldTransform_);

	Matrix4 matScale;


	Matrix4 matTrans;

	Matrix4 matRotateZ;

};

