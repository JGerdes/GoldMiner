#ifndef IMAGEBUFFER_H_
#define IMAGEBUFFER_H_

#include <string>
#include <GLFW/glfw3.h>

/**
 * @author Jonas Gerdes, Jonathan Wiemers
 *
 * Hat ein Array von Floats in dem die Pixelfarbe der PPM Datei gespeichert wird.
 * Eine Höhe und eine Breite. den Pfad zur geladenden Datai.
 * Und ein tex_handle der von OpenGl vergeben wird. @see loadFromPPM Methode
 *
 */
class ImageBuffer {
public:
	ImageBuffer();
	virtual ~ImageBuffer();

	/**
	 * Läd eine PPM datei und speichert je drei Werte für jeden einzelnen Pixel in dem Floatarray buffer_.
	 * @see genauere beschreibung in der Methode
	 *
	 * @param filename Der Pfad zur einzulesenden Datei.
	 * @return bool true: wenn das einlesen ohne Fehler verlaufen ist, sonst false
	 */
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
