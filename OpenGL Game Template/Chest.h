#pragma once

#include "State.h"
#include "Model.h"
#include "Variables.h" 

#include <iostream>


class Chest {
	public:
		Chest(GLWindow& window, std::string const& filePath);
		
		void update();
		void render(const glm::mat4& viewMatrix, const glm::mat4 projection);

		void setPosition(glm::vec3 position) { this->position = position; }
		void setScale(glm::vec3 scaleValue = SCALE_VALUE) { this->scaleValue = scaleValue; }

	private:
		Model model;

		GLWindow& window;
		Program program;

		glm::vec3 position;
		glm::vec3 scaleValue = SCALE_VALUE;
};
