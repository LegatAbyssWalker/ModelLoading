#pragma once

#include "glm/glm.hpp"
#include "GLWindow.h"

#include "State.h"
#include "Model.h"
#include "Variables.h"
#include "Object.h"

#include <iostream>
#include <vector>
#include <array>

class Terrain : public Object {
	public:
		Terrain(GLWindow& window, std::string const& filePath);

		void update();
		void render(const glm::mat4 viewMatrix, const glm::mat4& projection);

	private:
		Model model;
};

