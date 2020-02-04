#include "Chest.h"

Chest::Chest(GLWindow& window, std::string const& filePath)
	: Model(filePath, window) {
}

void Chest::update() {
	// ?
}

void Chest::render(const glm::mat4& viewMatrix, const glm::mat4 projection) {
	program->useProgram();

	// Model matrix
	glm::mat4 model(1.f);
	model = glm::translate(model, position);
	model = glm::scale(model, scaleValue);

	// Uniforms
	program->setMat4("model", model);
	program->setMat4("view", viewMatrix);
	program->setMat4("projection", projection);

	// Model rendering
	renderModel(program);
}
