#include "ParticleManager.h"

void ParticleManager::Init() {
}

void ParticleManager::Update() {
	Particles_.remove_if(
		[](std::unique_ptr<Particle>& objParticle) { return objParticle->GetIsDead(); });

	for (std::unique_ptr<Particle>& Particle : Particles_) {
		Particle->Update();
	}
}

void ParticleManager::Draw() {
	for (std::unique_ptr<Particle>& Particle : Particles_) {
		Particle->Draw();
	}
}

void ParticleManager::SetAnyExp(const Vec2& pos, Vec2 velocityMinMax, size_t volume, int lifetime, float scale, unsigned int color) {
	std::unique_ptr<Particle> newParticle;
	float min, max;
	min = velocityMinMax.x;
	max = velocityMinMax.y;
	for (size_t i = 0; i < volume; i++) {
		// 生成
		newParticle.reset(Particle::Create(
			pos, {
				RandomFloat(0,min, max),
				RandomFloat(0,min, max) },
				lifetime, scale, color
				));
		// 出力
		Particles_.push_back(std::move(newParticle));
	}
}

void ParticleManager::SetAnyExp(ParticlePreset preset)
{
	std::unique_ptr<Particle> newParticle;
	float min, max;
	min = preset.velocityMinMax.x;
	max = preset.velocityMinMax.y;
	for (size_t i = 0; i < preset.volume; i++) {
		// 生成
		newParticle.reset(Particle::Create(
			preset.pos_, {
				RandomFloat(0,min, max),
				RandomFloat(0,min, max) },
				preset.lifeTime,
				preset.scale,
				preset.color
				));
		// 出力
		Particles_.push_back(std::move(newParticle));
	}
}

ParticleManager* ParticleManager::GetInstance() {
	static ParticleManager instance;
	return &instance;
}

//////////////////////////////


Particle* Particle::Create(
	const Vec2& pos_, const Vec2& velocity_, int lifetime, float scale, unsigned int color) {
	// インスタンス
	Particle* instance = new Particle();
	if (instance == nullptr) {
		return nullptr;
	}

	// 初期化
	instance->Init(pos_, velocity_,lifetime, scale, color);

	return instance;
}

void Particle::Init(
	const Vec2& pos, const Vec2& velocity, int lifetime, float scale, unsigned int color) {
	pos_ = pos;
	velocity_ = velocity;
	MAXLIFETIME = lifetime;
	scale_ = scale;
	color_ = color;

	lifeTimer = 0;

}

void Particle::Update() {
	if (lifeTimer < MAXLIFETIME) {
		lifeTimer++;

		pos_ += velocity_;

		if (lifeTimer > MAXLIFETIME - MAXEASETIME) {
			if (easeTimer < MAXEASETIME) {
				easeTimer++;
				scale_ = lerpFloat({ 0.5f }, { 0.0f }, easeTimer / MAXEASETIME);
			}
		}
	}
	else {
		isDead = true;
	}
}

void Particle::Draw() {
	DrawBoxAA(pos_.x - scale_, pos_.y - scale_, pos_.x + scale_, pos_.y + scale_, color_, true);
}