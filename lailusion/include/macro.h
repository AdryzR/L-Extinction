/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** macro.h
*/


#ifndef MACRO_H
    #define MACRO_H

    // Defines for usage
    #define TRUE 1
    #define FALSE 0
    #define HELP 42
    #define ERROR 84
    #define WHITE 255
    #define SUCCESS 0
    #define TRANSPARENT 0

    // Window Specification
    #define WINDOW_WIDTH 711
    #define WINDOW_HEIGHT 400

    // Platforms
    #define PLATFORM_MIN_WIDTH 25
    #define PLATFORM_MAX_WIDTH 150

    // Player
    #define PLAYER_SPEED 10.f
    #define JUMP_STRENGTH 25.f
    #define PLAYER_GRAVITY 5.f

    // Defines for window
    #define CLEAR sfRenderWindow_clear
    #define CLOSE sfRenderWindow_close
    #define IS_OPEN sfRenderWindow_isOpen
    #define DISPLAY sfRenderWindow_display
    #define POLL_EVENT sfRenderWindow_pollEvent
    #define WINDOW_CREATE sfRenderWindow_create
    #define WINDOW_DESTROY sfRenderWindow_destroy
    #define WINDOW_FRAMELIMIT sfRenderWindow_setFramerateLimit

    // Defines for the clock
    #define CLOCK_CREATE sfClock_create
    #define CLOCK_RESTART sfClock_restart
    #define CLOCK_DESTROY sfClock_destroy
    #define CLOCK_TIME sfClock_getElapsedTime

    // Defines for rectangles shapes
    #define RECTANGLE_CREATE sfRectangleShape_create
    #define RECTANGLE_SETSIZE sfRectangleShape_setSize
    #define RECTANGLE_DESTROY sfRectangleShape_destroy
    #define RECTANGLE_SETSCALE sfRectangleShape_setScale
    #define RECTANGLE_GETPOS sfRectangleShape_getPosition
    #define RECTANGLE_SETPOS sfRectangleShape_setPosition
    #define RECTANGLE_SETORIGIN sfRectangleShape_setOrigin
    #define RECTANGLE_DRAW sfRenderWindow_drawRectangleShape
    #define RECTANGLE_FILLCOLOR sfRectangleShape_setFillColor
    #define RECTANGLE_GETGBOUNDS sfRectangleShape_getGlobalBounds
    #define RECTANGLE_SETOUTLINECOLOR sfRectangleShape_setOutlineColor
    #define RECTANGLE_SETOUTLINETHICK sfRectangleShape_setOutlineThickness

    // Defines for Circles
    #define CIRCLE_CREATE sfCircleShape_create
    #define CIRCLE_DESTROY sfCircleShape_destroy
    #define CIRCLE_SETRAD sfCircleShape_setRadius
    #define CIRCLE_SETPOS sfCircleShape_setPosition
    #define CIRCLE_DRAW sfRenderWindow_drawCircleShape
    #define CIRCLE_SETFILLCOLOR sfCircleShape_setFillColor
    #define CIRCLE_SETOUTLINECOLOR sfCircleShape_setOutlineColor
    #define CIRCLE_SETOUTILETHICK sfCircleShape_setOutlineThickness

    // Defines for rects
    #define RECT_CONTAINS sfFloatRect_contains
    #define RECT_POS sfRectangleShape_setPosition

    // Defines for Sprites
    #define SPRITE_CREATE sfSprite_create
    #define SPRITE_DESTROY sfSprite_destroy
    #define SPRITE_SETSCALE sfSprite_setScale
    #define SPRITE_SETPOS sfSprite_setPosition
    #define SPRITE_GETPOS sfSprite_getPosition
    #define SPRITE_SETORIGIN sfSprite_setOrigin
    #define SPRITE_SETTEXTURE sfSprite_setTexture
    #define SPRITE_DRAW sfRenderWindow_drawSprite
    #define SPRITE_SETRECT sfSprite_setTextureRect
    #define SPRITE_SETROTATION sfSprite_setRotation
    #define SPRITE_GETGBOUNDS sfSprite_getGlobalBounds

    // Defines for Texture
    #define TEXTURE_CREATE sfTexture_create
    #define TEXTURE_CREATE_FILE sfTexture_createFromFile
    #define TEXTURE_DESTROY sfTexture_destroy
    #define TEXTURE_UPDATE sfTexture_updateFromPixels
    #define TEXTURE_UPDATEIMAGE sfTexture_updateFromImage

    // Defines for text
    #define TEXT_DRAW sfRenderWindow_drawText
    #define TEXT_DESTROY sfText_destroy
    #define TEXT_CREATE sfText_create

    // Defines for font
    #define FONT_DESTROY sfFont_destroy

    // Defines for mouse
    #define MOUSE_GETPOS sfMouse_getPositionRenderWindow

    #define MUSIC sfMusic_getStatus

    // Defines for Image
    #define IMAGE_DESTROY sfImage_destroy

    // Defines for keyboard
    #define KEY_PRESSED sfKeyboard_isKeyPressed


#endif
