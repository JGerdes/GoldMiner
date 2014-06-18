/*
 * InputManager.h
 *
 *  Created on: 08.06.2014
 *      Author: Jonas
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include <tr1/unordered_map>
#include <vector>
#include "MouseListener.h"

class KeyListener{
public:
	virtual ~KeyListener(){};
	virtual void onKeyUp(int key)=0;
	virtual void onKeyDown(int key)=0;
};

class InputManager {
public:

    static InputManager& getInstance();
	static void onMouseMove(GLFWwindow *window, double x, double y);
	static void onKey(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void onButton(GLFWwindow *window, int button, int action, int mods);
	static void onScroll(GLFWwindow *window, double x_offset, double y_offset);


    void onMouseMoveImpl(GLFWwindow *window, double x, double y);
	void onKeyImpl(GLFWwindow *window, int key, int scancode, int action, int mods);
	void onButtonImpl(GLFWwindow *window, int button, int action, int mods);
	void onScrollImpl(GLFWwindow *window, double x_offset, double y_offset);

	void addMouseMoveListener(const KeyListener& listener);
	void addKeyListener(const KeyListener& listener);
	bool isKeyDown(int key);
	bool isButtonDown(int button);

	InputManager(InputManager const&);
	void operator=(InputManager const&);

private:
	InputManager();
    std::tr1::unordered_map<int, bool> keys_;
    std::tr1::unordered_map<int, bool> mouse_buttons_;

    std::vector<MouseListener*> mouse_listeners_;
    std::vector<KeyListener*> key_listeners_;

    double last_x = 0;
	double last_y = 0;


};

#endif /* INPUTMANAGER_H_ */
