/*
 * ImageBuffer.h
 *
 *  Created on: 20.06.2014
 *      Author: Jonas
 */

#ifndef IMAGEBUFFER_H_
#define IMAGEBUFFER_H_

#include <string>
#include <GLFW/glfw3.h>

class ImageBuffer {
public:
	ImageBuffer();
	virtual ~ImageBuffer();

	bool loadFromPPM(const std::string& filename);

	unsigned int getWidth() const;
	unsigned int getHeight() const;
	const std::string& getPath() const;
	GLuint getTexHandle() const;

private:
	float* buffer_;
	unsigned int width_;
	unsigned int height_;
	GLuint tex_handle_;
	std::string path_;
};

#endif /* IMAGEBUFFER_H_ */
