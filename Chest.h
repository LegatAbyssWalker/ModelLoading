#pragma once

#include "State.h"
#include "Model.h"
#include "Variables.h" 

#include <iostream>


class Chest : public Model {
	public:
		Chest(GLWindow& window, std::string const& filePath);
		
		void update();
		void render(const glm::mat4& viewMatrix, const glm::mat4 projection);

	private:


};
