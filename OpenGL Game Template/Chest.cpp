#include "Chest.h"

Chest::Chest(GLWindow& window, std::string const& filePath)
	: window(window), model(filePath) {
}

void Chest::update() {
	// ?
}

void Chest::render(const glm::mat4& viewMatrix, const glm::mat4 projection) {
	program.useProgram();

	// Model matrix
	glm::mat4 modelValues(1.f);
	modelValues = glm::translate(modelValues, position);
	modelValues = glm::scale(modelValues, scaleValue);

	// Uniforms
	program.setMat4("model", modelValues);
	program.setMat4("view", viewMatrix);
	program.setMat4("projection", projection);

	model.renderModel(program);
}
