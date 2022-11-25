/// Класс описывающий цвет в формате RGB
/// @author Пилипейко А.А.


#pragma once


class ColorRGB {
  public:
	unsigned char red;
	unsigned char green;
	unsigned char blue;


	ColorRGB() {
		red   = 255;
		green = 255;
		blue  = 255;
	}

	/// задать цвет в формате RGB
	void setСolor(unsigned char red, unsigned char green, unsigned char blue) {
		this->red   = red;
		this->green = green;
		this->blue  = blue;
	}
};

