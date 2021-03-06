#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include <Trackable.h>

#include <string>
#include "Color.h"

class GraphicsSystem;

class GraphicsBuffer : public Trackable
{
	friend class GraphicsSystem;
public:
	GraphicsBuffer(const std::string& filename);
	GraphicsBuffer(unsigned int width, unsigned int height, Color color = Color() );
	~GraphicsBuffer();

	GraphicsBuffer* clone() const;

	unsigned int getWidth() const { return al_get_bitmap_width(mpBitmap); };
	unsigned int getHeight() const { return al_get_bitmap_height(mpBitmap); };

private:
	ALLEGRO_BITMAP* mpBitmap = NULL;
	bool mOwnsBitmap = true;

	GraphicsBuffer(ALLEGRO_DISPLAY* pDisplay);//to be called by GraphicsSystem only
	ALLEGRO_BITMAP* getBitmap() const { return mpBitmap; };//to be called by GraphicsSystem only

	//invalidate copy constructor and assignment operator
	GraphicsBuffer(GraphicsBuffer&);
	GraphicsBuffer operator=(GraphicsBuffer&);
};
