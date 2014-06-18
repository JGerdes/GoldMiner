/*
 * InputManager.cpp
 *
 *  Created on: 08.06.2014
 *      Author: Jonas
 */


#include <GLFW/glfw3.h>
#include <iostream>
#include "InputManager.h"
#include <stdexcept>

using namespace std;

InputManager& InputManager::getInstance(){
	static InputManager instance;
	return instance;
}

void InputManager::onMouseMove(GLFWwindow *window, double x, double y){
	InputManager::getInstance().onMouseMoveImpl(window, x, y);
}

void InputManager::onKey(GLFWwindow *window, int key, int scancode, int action, int mods){
	InputManager::getInstance().onKeyImpl(window, key, scancode, action, mods);
}
void InputManager::onButton(GLFWwindow *window, int button, int action, int mods){
	InputManager::getInstance().onButtonImpl(window, button, action, mods);
}
void InputManager::onScroll(GLFWwindow *window, double x_offset, double y_offset){
	InputManager::getInstance().onScrollImpl(window, x_offset, y_offset);
}

void InputManager::onMouseMoveImpl(GLFWwindow *window, double x, double y){
	static double last_x = 0;
	static double last_y = 0;
	for(auto listener : mouse_listeners_){
		listener->onMouseMove(x, y, last_x, last_y);
	}
	last_x = x;
	last_y = y;
}

void InputManager::onKeyImpl(GLFWwindow *window, int key, int scancode, int action, int mods){
	if(action == GLFW_PRESS || action == GLFW_REPEAT){
		keys_[key] = true;
	}else{
		keys_[key] = false;
	}
	for(auto listener : key_listeners_){
		if(action == GLFW_PRESS){
			listener->onKeyDown(key);
		}
		if(action == GLFW_RELEASE){
			listener->onKeyUp(key);
		}
	}
}

void InputManager::onButtonImpl(GLFWwindow *window, int button, int action, int mods){
	if(action == GLFW_PRESS || action == GLFW_REPEAT){
		mouse_buttons_[button] = true;
	}else{
		mouse_buttons_[button] = false;
	}
	for(auto listener : mouse_listeners_){
		if(action == GLFW_PRESS){
			listener->onButtonDown(button);
		}
		if(action == GLFW_RELEASE){
			listener->onButtonUp(button);
		}
	}
}

void InputManager::onScrollImpl(GLFWwindow *window, double x_offset, double y_offset){
	for(auto listener : mouse_listeners_){
		listener->onScroll(x_offset, y_offset);
	}
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

