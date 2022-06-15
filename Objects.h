#pragma once

struct Objects
{
    float startX;
    float startY;
    float endX;
    float endY;
    char type;
};

static Objects mapObjects[] = {
    200.f, 200.f, 500.f, 300.f, 'P',
    0.f, 300.f, 1000.f, 350.f, 'P',
    100.f, 100.f, 300.f, 120.f, 'P',
};

static int objectsQuantity = sizeof(mapObjects)/sizeof(Objects);
