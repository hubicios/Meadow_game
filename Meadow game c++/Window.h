#pragma once
#ifndef WINDOW_H
#define WINDOW_H

class Window //: public Point
{
public:
	Window();
	~Window();
	void ClearConsole();
	void gotoXY(int x, int y);
	void setCursor(bool visible);
	void drawEmptyWindow(int height, int width);
};
#endif /*WINDOW_H */
