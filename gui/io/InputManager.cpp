/*
 * InputManager.cpp
 *
 *  Created on: 08.06.2014
 *      Author: Jonas
 */


#include <GLFW/glfw3.h>
#include <iostream>
#include "InputManager.h"
#include "../../Vec2.h"
#include <stdexcept>
#include "../../Game.h"

using namespace std;

InputManager& InputManager::getInstance(){
	static InputManager instance;
	return instance;
}

void InputManager::onMouseMove(GLFWwindow *window, double x, double y){
	InputManager::getInstance().onMouseMoveImpl(x, y);
}

void InputManager::onKey(GLFWwindow *window, int key, int scancode, int action, int mods){
	InputManager::getInstance().onKeyImpl(key, action);
}
void InputManager::onButton(GLFWwindow *window, int button, int action, int mods){
	InputManager::getInstance().onButtonImpl(button, action);
}
void InputManager::onScroll(GLFWwindow *window, double x_offset, double y_offset){
	InputManager::getInstance().onScrollImpl(x_offset, y_offset);
}
void InputManager::onResize(GLFWwindow * window, int width, int height){
	InputManager::getInstance().onResizeImpl(width, height);
}


InputManager::InputManager():
		last_x(0),
		last_y(0){

}

void InputManager::onMouseMoveImpl(double x, double y){
	y = Game::window_height-y;
	for(MouseListener* listener : mouse_listeners_){
		listener->onMouseMove(Vec2(x, y), Vec2(last_x, last_y));
	}
	last_x = x;
	last_y = y;
}

void InputManager::onKeyImpl(int key, int action){
	if(action == GLFW_PRESS || action == GLFW_REPEAT){
		keys_[key] = true;
	}else{
		keys_[key] = false;
	}
	for(KeyListener* listener : key_listeners_){
		if(action == GLFW_PRESS){
			listener->onKeyDown(key);
		}
		if(action == GLFW_RELEASE){
			listener->onKeyUp(key);
		}
	}
}

void InputManager::onButtonImpl(int button, int action){
	if(action == GLFW_PRESS || action == GLFW_REPEAT){
		mouse_buttons_[button] = true;
	}else{
		mouse_buttons_[button] = false;
	}
	size_t i = 0;
	for(MouseListener* listener : mouse_listeners_){
		if(action == GLFW_PRESS){
			if(listener->onButtonDown(button, Vec2(last_x, last_y))){
				cout<< "listener: " << i <<endl;
				return;
			}
		}
		if(action == GLFW_RELEASE){
			//TODO: genauso wie bei buttton down
			listener->onButtonUp(button, Vec2(last_x, last_y));
		}
		++i;
	}

}

void InputManager::onScrollImpl(double x_offset, double y_offset){
	for(MouseListener* listener : mouse_listeners_){
		listener->onScroll(Vec2(x_offset, y_offset));
	}
}

void InputManager::onResizeImpl(int width, int height){
	Game::window_width = width;
	Game::window_height = height;
	cout << "new width:" << Game::window_width << endl;
}

bool InputManager::isKeyDown(int key){
	try {
		bool result = keys_[key];
	    return result;
	}catch (const std::out_of_range& oor) {
		return false;
	}
}

bool InputManager::isButtonDown(int button){
	try {
		bool result = mouse_buttons_[button];
		return result;
	}catch (const std::out_of_range& oor) {
		return false;
	}
}

void InputManager::addMouseListener(MouseListener* listener){
	mouse_listeners_.push_back(listener);
}

void InputManager::addKeyListener(KeyListener* listener){
	key_listeners_.push_back(listener);
}
