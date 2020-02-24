#include "PlayingState.h"

PlayingState::PlayingState(StateMachine& machine, GLWindow& window, bool replace)
	: State(machine, window, replace), window(window) {

	// Player
	player = std::make_unique<Player>(window, glm::vec3(0, 2, 0), getProjectionMatrix());

	// Terrain
	terrain = std::make_unique<Terrain>(window, TERRAIN_MODEL_LOCATION);
	terrain->setPosition(glm::vec3(0, 0, 0));
	terrain->setScale(glm::vec3(5, 5, 5));
}

void PlayingState::keyboardInputs(sf::Keyboard::Key& key, bool isPressed) {
	if (key == sf::Keyboard::Escape) { machine.quit(); }
}

void PlayingState::updateEvents() {
	while (window.getWindow().pollEvent(sfEvent)) {
		auto keyCode = sfEvent.key.code;

		switch (sfEvent.type) { 
			case sf::Event::Closed:
				machine.quit();
				break;  

			case sf::Event::KeyPressed:
				keyboardInputs(keyCode, true);
				player->keyboardUpdate(keyCode, true, deltaTime);
				break;

			case sf::Event::KeyReleased:
				keyboardInputs(keyCode, false);
				player->keyboardUpdate(keyCode, false, deltaTime);
				break;
			}
	}
}

void PlayingState::update() {
	GLfloat now = clock.getElapsedTime().asSeconds();
	deltaTime = now - lastFrame;
	lastFrame = now;

	// Player
	player->update((GLfloat)deltaTime);

}

void PlayingState::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5f, 1.f, 1.f, 1.f);

	terrain->render(player->getViewMatrix(), getProjectionMatrix());

	window.swapBuffers();
}
