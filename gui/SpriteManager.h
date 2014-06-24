#ifndef SPRITEMANAGER_H_
#define SPRITEMANAGER_H_

#include <vector>
#include <string>
#include "Sprite.h"
#include "ImageBuffer.h"


/**
 * @author Jonas Gerdes
 *
 * Verwaltet Spites und ImageBuffer
 */
class SpriteManager {
public:

	SpriteManager();
	virtual ~SpriteManager();

	/**
	 * Läd ein eine neue PPM datei als ImageBuffer,
	 * wenn sie vorher noch nicht geladen wurde.
	 *
	 * @param path Der Pfad zu dem zu landenden Sprite
	 * @return Ein neues Sprite Objekt
	 */
	Sprite* getSprite(std::string path);

private:
	std::vector<ImageBuffer*> image_buffers_;
	std::vector<Sprite*> sprites_;
};

#endif /* SPRITEMANAGER_H_ */
