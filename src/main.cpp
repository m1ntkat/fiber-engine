#include "raylib.h"
#include <iostream>

using namespace std;

constexpr auto SCREEN_WIDTH  = 800;
constexpr auto SCREEN_HEIGHT = 450;

void helloWorld()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(60);

    //Texture2D texture = LoadTexture(ASSETS_PATH"test.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        //const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
        //DrawTexture(texture, texture_x, texture_y, WHITE);

        const char* text = "Hello World!";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, SCREEN_HEIGHT / 2 - text_size.y / 2, 20, BLACK);


        EndDrawing();
    }

    //UnloadTexture(texture);

    CloseWindow();
}

void helloRaylib()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(60);

    Texture2D texture = LoadTexture(ASSETS_PATH"test.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
        DrawTexture(texture, texture_x, texture_y, WHITE);

        const char* text = "OMG! IT WORKS!";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + texture.height + text_size.y + 10, 20, BLACK);

        EndDrawing();
    }

    UnloadTexture(texture);

    CloseWindow();
}

int main()
{
    cout << "Fiber Engine" << endl;
    cout << "(C) 2023 m1ntkat" << endl;
    cout << endl;

    string command;
    cin >> command;

    if (command == "helloRaylib")
    {
        helloRaylib();
    }
    else if (command == "helloWorld")
    {
        helloWorld();
    }

    return 0;
}
