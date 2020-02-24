#pragma once

#include "Mesh.h"
#include "Program.h"
#include "Variables.h"
#include "State.h"
#include "Model.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

struct Object {
	public:
		Object() = default;
		Object(GLWindow& window) : window(window) { program = std::make_unique<Program>(BASIC_VERTEX_SHADER, BASIC_FRAGMENT_SHADER); }
		
		void setPosition(glm::vec3 position) { this->position = position; }
		void setScale(glm::vec3 scaleValue) { this->scaleValue = scaleValue; }

		glm::vec3 getPosition() const { return position; }
		glm::vec3 getScaleValue() const { return scaleValue; }

		glm::vec3 getHighPosition() const { return position * scaleValue; }

	protected:
		GLWindow& window;
		std::unique_ptr<Program> program = nullptr;

		glm::vec3 position = glm::vec3(0);
		glm::vec3 scaleValue = SCALE_VALUE;
};

