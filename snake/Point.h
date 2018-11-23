#pragma once


class Point {
public:
    int xPos, yPos;
    int dir;
    int l;
    bool flagged = false;

    Point(int x, int y, int direction, int life) {
        xPos = x;
        yPos = y;
        dir = direction;
        l = life;
    }
    void decrementLife() {
        --l;
        if (l < 1) {
            flagged = true;
            xPos = -1;
            yPos = -1;
        }
    }
private:
};

