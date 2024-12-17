#include <vector>
#include <thread>

#include "raylib.h"

static float progress;
static bool done;
static bool loaded;
static std::vector<Image> images;
static std::vector<Texture2D> textures;

const float progressInc = 1.0f / 54.0f;

static void loadImage(const char* filename)
{
    auto image = LoadImage(filename);
    images.push_back(image);
    progress += progressInc;
}

static void loadImages()
{
    // CLUBS
    loadImage("assets/clubs/a_clubs.png");
    loadImage("assets/clubs/2_clubs.png");
    loadImage("assets/clubs/3_clubs.png");
    loadImage("assets/clubs/4_clubs.png");
    loadImage("assets/clubs/5_clubs.png");
    loadImage("assets/clubs/6_clubs.png");
    loadImage("assets/clubs/7_clubs.png");
    loadImage("assets/clubs/8_clubs.png");
    loadImage("assets/clubs/9_clubs.png");
    loadImage("assets/clubs/10_clubs.png");
    loadImage("assets/clubs/j_clubs.png");
    loadImage("assets/clubs/q_clubs.png");
    loadImage("assets/clubs/k_clubs.png");

    // DIAMONDS
    loadImage("assets/diamonds/a_diamonds.png");
    loadImage("assets/diamonds/2_diamonds.png");
    loadImage("assets/diamonds/3_diamonds.png");
    loadImage("assets/diamonds/4_diamonds.png");
    loadImage("assets/diamonds/5_diamonds.png");
    loadImage("assets/diamonds/6_diamonds.png");
    loadImage("assets/diamonds/7_diamonds.png");
    loadImage("assets/diamonds/8_diamonds.png");
    loadImage("assets/diamonds/9_diamonds.png");
    loadImage("assets/diamonds/10_diamonds.png");
    loadImage("assets/diamonds/j_diamonds.png");
    loadImage("assets/diamonds/q_diamonds.png");
    loadImage("assets/diamonds/k_diamonds.png");

    // HEARTS
    loadImage("assets/hearts/A_hearts.png");
    loadImage("assets/hearts/2_hearts.png");
    loadImage("assets/hearts/3_hearts.png");
    loadImage("assets/hearts/4_hearts.png");
    loadImage("assets/hearts/5_hearts.png");
    loadImage("assets/hearts/6_hearts.png");
    loadImage("assets/hearts/7_hearts.png");
    loadImage("assets/hearts/8_hearts.png");
    loadImage("assets/hearts/9_hearts.png");
    loadImage("assets/hearts/10_hearts.png");
    loadImage("assets/hearts/J_hearts.png");
    loadImage("assets/hearts/Q_hearts.png");
    loadImage("assets/hearts/K_hearts.png");

    // SPADES
    loadImage("assets/spades/a_spades.png");
    loadImage("assets/spades/2_spades.png");
    loadImage("assets/spades/3_spades.png");
    loadImage("assets/spades/4_spades.png");
    loadImage("assets/spades/5_spades.png");
    loadImage("assets/spades/6_spades.png");
    loadImage("assets/spades/7_spades.png");
    loadImage("assets/spades/8_spades.png");
    loadImage("assets/spades/9_spades.png");
    loadImage("assets/spades/10_spades.png");
    loadImage("assets/spades/j_spades.png");
    loadImage("assets/spades/q_spades.png");
    loadImage("assets/spades/k_spades.png");

    loaded = true;
}

static void loadTexture(Image image)
{
    auto texture = LoadTextureFromImage(image);
    textures.push_back(texture);
}

static void loadTextures()
{
    for (auto image : images)
    {
        loadTexture(image);
    }

    done = true;
}

int main(void)
{
    progress = 0.0f;
    loaded = false;
    done = false;

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib multithreaded");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    std::thread loading(loadImages);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if (loaded && !done)
        {
            loadTextures();
            done = true;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Progress loading textures", 190, 200, 20, LIGHTGRAY);

        float barSize = progress * 300;

        DrawRectangle(190, 300, (int)barSize , 20, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    loading.join();

	return 0;
}